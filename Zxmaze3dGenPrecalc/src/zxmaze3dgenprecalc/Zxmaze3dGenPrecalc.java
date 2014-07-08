/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package zxmaze3dgenprecalc;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Formatter;
import java.util.Locale;

/**
 *
 * @author Andrej
 */
public class Zxmaze3dGenPrecalc {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        System.setProperty("line.separator", "\r\n");
        FileOutputStream fos = new FileOutputStream("../tables.c");
        final Zxmaze3dGenPrecalc zxmaze3dGenPrecalc = new Zxmaze3dGenPrecalc(fos);
        zxmaze3dGenPrecalc.generate();
        fos.close();
    }
    private final PrintStream fos;
    public static int N_DIRECTIONS = 256;
    /**
     * IDEA (to test): Actually, max 308 is theoretically needed (max supported
     * distance by the engine is 16*sqrt(2)), but the algorithm currently relies
     * on 2^n values in the table.
     * <br>
     * If rounded up to 384 and last element has max value, it has the bit
     * pattern, that prevents bisection from searching past the last element.
     */
    public static int N_PRECALC_DRAW_DIST = 384;

    private Zxmaze3dGenPrecalc(FileOutputStream fos) {
        this.fos = new PrintStream(fos);
    }

    private void generate() {
        fos.print("// Precalculated Look-up tables\r\n");
        fos.print("// Generated by " + Zxmaze3dGenPrecalc.class.getName() + " \r\n");
        fos.print("\r\n");
        fos.print("#include <stdlib.h>\r\n");
        fos.print("\r\n");

        Formatter formatter = new Formatter(fos, Locale.US);
 
        new DirectionArrayGenerator("f_dir_sin") {
            @Override
            protected int geterateValue(int i, double phi, double sin_phi, double cos_phi) {
                return fixed_from_float(sin_phi);
            }
        }.generate(formatter);
        new DirectionArrayGenerator("f_dir_cos") {
            @Override
            protected int geterateValue(int i, double phi, double sin_phi, double cos_phi) {
                return fixed_from_float(cos_phi);
            }
        }.generate(formatter);

        // Conceptually, lim x->arg(ctan x), saturated
        new DirectionArrayGenerator("f_dir_ctan", "ctan of direction, saturated") {
            @Override
            protected int geterateValue(int i, double phi, double sin_phi, double cos_phi) {
                return fixed_from_float(sin_phi != 0.0 ? cos_phi / sin_phi : (cos_phi > 0 ? 127.0 : -128.0));
            }
        }.generate(formatter);

        // Conceptually, lim x->arg(ctan x), saturated
        new DirectionArrayGenerator("f_dir_tan", "tan of direction, saturated") {
            @Override
            protected int geterateValue(int i, double phi, double sin_phi, double cos_phi) {
                return fixed_from_float(cos_phi != 0.0 ? sin_phi / cos_phi : (sin_phi > 0 ? 127.0 : -128.0));
            }
        }.generate(formatter);


        new DistanceArrayGenerator("long", "f16_sqrs", "Squares of distance, in 16-shifted fixed point, for fast sqrt") {
            @Override
            protected int geterateValue(int distidx, int f_dist) {
                return (distidx < N_PRECALC_DRAW_DIST-1) ? (f_dist * f_dist) : 0x7FFFFFFF;
            }
        }.generate(formatter);
        new DistanceArrayGenerator("uchar", "draw_heigths", "Heights of given distance index") {
            @Override
            protected int geterateValue(int distidx, int f_dist) {
                int height = (int) Math.round(65.0 / float_from_fixed(f_dist));
                int result = 95-height;
                return result >= 0? result : 0;
            }
        }.generate(formatter);
        new DistanceArrayGenerator("uchar", "draw_heigths1", "Heights of given distance index") {
            @Override
            protected int geterateValue(int distidx, int f_dist) {
                int height = (int) Math.round(100.0 / float_from_fixed(f_dist));
                int result = 97 + height;
                return result <= 191? result : 191;
            }
        }.generate(formatter);
        new DistanceArrayGenerator("uchar", "draw_intens", "Color intensities of given distance index") {
            private final int N_INTENSITIES = 17;
            private final int INTENSITY_WHITE = 16;

            @Override
            protected int geterateValue(int distidx, int f_dist) {
                double distance = float_from_fixed(f_dist);
                int intensity = INTENSITY_WHITE - (int) Math.round((16.0 * (1.0 / ((distance + 2.0) * 0.34))));
                return intensity < N_INTENSITIES ? (intensity >= 0 ? intensity : 0) : INTENSITY_WHITE;
            }
        }.generate(formatter);
        formatter.flush();

    }

    static abstract class DirectionArrayGenerator extends ArrayGenerator {

        public DirectionArrayGenerator(String name) {
            super("int", name, name, N_DIRECTIONS);
        }

        public DirectionArrayGenerator(String name, String comment) {
            super("int", name, comment, N_DIRECTIONS);
        }

        @Override
        protected int geterateValue(int i) {
            double phi = phi_from_direction(i);
            double sin_phi = Math.sin(phi);
            double cos_phi = Math.cos(phi);

            return geterateValue(i, phi, sin_phi, cos_phi);
        }

        protected abstract int geterateValue(int i, double phi, double sin_phi, double cos_phi);
    }

    static abstract class DistanceArrayGenerator extends ArrayGenerator {

        public DistanceArrayGenerator(String type, String name, String comment) {
            super(type, name, comment, N_PRECALC_DRAW_DIST);
        }

        @Override
        protected int geterateValue(int distidx) {
            int f_dist = distidx * 16;

            return geterateValue(distidx, f_dist);
        }

        protected abstract int geterateValue(int distidx, int f_dist);
    }

    static abstract class ArrayGenerator {

        protected final String type, name, comment;
        protected final int nElements;

        public ArrayGenerator(String type, String name, String comment, int nElements) {
            this.type = type;
            this.name = name;
            this.comment = comment;
            this.nElements = nElements;
        }

        public void generate(Formatter formatter) {
            formatter.format("// %s\r\n", comment);
            formatter.format(type + " " + name + "[] = {");
            for (int i = 0; i < nElements; i++) {
                if (i > 0) {
                    formatter.format(",");
                }
                formatter.format("\r\n");
                formatter.format("%d", geterateValue(i));
            }

            formatter.format("};\r\n");
        }

        /**
         * Must generate value for i-th element of the array
         *
         * @param i
         * @return
         */
        protected abstract int geterateValue(int i);
    }

    private static short fixed_from_float(double d) {
        if (d >= 127.0) {
            return 0x7FFF;
        } else if (d <= -128.0) {
            return -0x8000;
        } else if (d >= 0.0) {
            return (short) Math.round(d * 256.0);
        } else {
            return (short) Math.round(-d * -256.0);
        }
    }

    private static double float_from_fixed(int fixed) {
        return fixed / 256.0;
    }

    private static double phi_from_direction(int i) {
        return i * 2.0 * Math.PI / N_DIRECTIONS;
    }
}

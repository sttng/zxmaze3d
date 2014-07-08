/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package zxmaze3dgenprecalc;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.text.MessageFormat;
import java.util.Formatter;
import java.util.Locale;

/**
 *
 * @author Andrej
 */
public class SpanDrawAsmGenPrecalc {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        System.setProperty("line.separator", "\r\n");
        FileOutputStream fos = new FileOutputStream("../ht_4x4_asm_routines.h");
        final SpanDrawAsmGenPrecalc zxmaze3dGenPrecalc = new SpanDrawAsmGenPrecalc(fos);
        zxmaze3dGenPrecalc.generate();
        fos.close();
    }
    private final PrintStream fos;

    private SpanDrawAsmGenPrecalc(FileOutputStream fos) {
        this.fos = new PrintStream(fos);
    }

    private void generate() throws IOException {
        fos.print("// Pregenerated span draw routines\r\n");
        fos.print("// Generated by " + SpanDrawAsmGenPrecalc.class.getName() + " \r\n");
        fos.print("\r\n");
        fos.print("// Offsets to span draw routines entry points\r\n");
        fos.print("extern int span_func_tbl[192];\r\n");
        fos.print("\r\n");

        Formatter formatter = new Formatter(fos, Locale.US);

        RoutineGenerator routineGenerator = new RoutineGenerator();
        routineGenerator.generate(formatter);

        formatter.flush();

    }

    static class RoutineGenerator {

        /**
         * <p>Params: </p>
         * <ul>
         * <li>0 - blocksToDraw</li>
         * <li>1 - endAlignment</li>
         * <ul>
         */
        private static final MessageFormat TEMPLATE_ROUTINE_NAME = new MessageFormat(
                "draw_{0}_cells_end{1}");
        /**
         * <p>Params: </p>
         * <ul>
         * <li>0 - blocksToDraw</li>
         * <li>1 - endAlignment</li>
         * <li>2 - routine name</li>
         * <ul>
         */
        private static final MessageFormat TEMPLATE_NON_8GROUP_ALIGNED = new MessageFormat(
                "_{2}:\n"
                + "	; hl points to screen\n"
                + "	ld (hl),c		; 7 T\n"
                + "	inc h			; 4 T\n"
                + "	ld (hl),e\n"
                + "	inc h\n"
                + "	ld (hl),d\n"
                + "	inc h\n"
                + "	ld (hl),b\n"
                + "	inc h\n"
                + "	ld (hl),c\n"
                + "	inc h\n"
                + "	ld (hl),e\n"
                + "	inc h\n"
                + "	ld (hl),d\n"
                + "	inc h\n"
                + "	ld (hl),b\n"
                + "	\n"
                + "	; advance HL appropriately for non-8 aligned row of blocks\n"
                + "	; next row of blocks\n"
                + "	ld a,32\n"
                + "	add	l\n"
                + "	ld l,a\n"
                + "	; back to first row of the block\n"
                + "	ld a,-7\n"
                + "	add	h\n"
                + "	ld h,a\n"
                + "\n");
        /**
         * <p>Params: </p>
         * <ul>
         * <li>0 - blocksToDraw</li>
         * <li>1 - endAlignment</li>
         * <li>2 - routine name</li>
         * <ul>
         */
        private static final MessageFormat TEMPLATE_8GROUP_ALIGNED = new MessageFormat(
                "_{2}:\n"
                + "	; hl points to screen\n"
                + "	ld (hl),c		; 7 T\n"
                + "	inc h			; 4 T\n"
                + "	ld (hl),e\n"
                + "	inc h\n"
                + "	ld (hl),d\n"
                + "	inc h\n"
                + "	ld (hl),b\n"
                + "	inc h\n"
                + "	ld (hl),c\n"
                + "	inc h\n"
                + "	ld (hl),e\n"
                + "	inc h\n"
                + "	ld (hl),d\n"
                + "	inc h\n"
                + "	ld (hl),b\n"
                + "\n"
                + "	; advance HL appropriately for 8-aligned row of blocks\n"
                + "	; first row of the 8-group of rows of blocks\n"
                + "	ld a,32\n"
                + "	add	l\n"
                + "	ld l,a\n"
                + "	; back to first row of the block (-7), but next 8-group of rows of blocks\n"
                + "	inc h\n"
                + "\n");
        private static final String TEMPLATE_RET =
                "	ret\n";
        private static final String TEMPLATE_ASM_START =
                "#asm\n";
        private static final String TEMPLATE_ASM_END =
                "#endasm\n";
        private static final String TEMPLATE_FUNC_TBL_START =
                "._span_func_tbl\n";
        private static final String TEMPLATE_FUNC_TBL_END =
                "\n";
        /**
         * <p>Params: </p>
         * <ul>
         * <li>0 - routineName</li>
         * <ul>
         */
        private static final MessageFormat TEMPLATE_FUNC_TBL_ELEMENT = new MessageFormat(
                "	defw _{0}\n");

        public RoutineGenerator() {
        }

        public String routineNameFromParams(int blocksToDraw, int endAlignment) {
            return TEMPLATE_ROUTINE_NAME.format(new Object[]{blocksToDraw, endAlignment});
        }

        public void generate(Formatter formatter) throws IOException {

            formatter.format(TEMPLATE_ASM_START);
            for (int endAlignment = 0; endAlignment < 8; endAlignment++) {
                for (int blocksToDraw = 24; blocksToDraw > 0; blocksToDraw--) {
                    String routineName = routineNameFromParams(blocksToDraw, endAlignment);

                    if (((blocksToDraw - 1) % 8) == (endAlignment % 8)) {
                        // If remaining blocks are the same as in last group or are 8-aligned with that number, 
                        // advancement to next group will be needed
                        formatter.out().append(TEMPLATE_8GROUP_ALIGNED.format(new Object[]{blocksToDraw, endAlignment, routineName}));
                    } else {
                        formatter.out().append(TEMPLATE_NON_8GROUP_ALIGNED.format(new Object[]{blocksToDraw, endAlignment, routineName}));
                    }
                }
                formatter.format(TEMPLATE_RET);
            }
            formatter.format(TEMPLATE_FUNC_TBL_START);
            for (int blocksToDraw = 1; blocksToDraw <= 24; blocksToDraw++) {
                for (int endAlignment = 0; endAlignment < 8; endAlignment++) {
                    String routineName = routineNameFromParams(blocksToDraw, endAlignment);

                    formatter.out().append(TEMPLATE_FUNC_TBL_ELEMENT.format(new Object[]{routineName}));
                }
            }
            formatter.format(TEMPLATE_FUNC_TBL_END);
            formatter.format(TEMPLATE_ASM_END);
        }

        /**
         * @param i
         * @return
         */
        void geterateRoutine(Formatter formatter, String routineName, int blocksToDraw, int endAlignment) {
        }
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
}

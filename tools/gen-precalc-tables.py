#! /usr/bin/env python3

import math
import decimal


N_DIRECTIONS = 256


# If rounded up to 384 and last element has max value, it has the bit
# pattern, that prevents bisection from searching past the last element.
N_PRECALC_DRAW_DIST = 384


# Python round() uses "banker's rounding", i.e. "round half even"
def round_half_up(d):
    return int(decimal.Decimal(d).to_integral_value(rounding=decimal.ROUND_HALF_UP))


def fixed_from_float(d):
    if d >= 127.0:
        return 0x7FFF
    elif d <= -128.0:
        return -0x8000
    elif d >= 0.0:
        return round_half_up(d * 256.0)
    else:
        return round_half_up(-d * -256.0)
    
    
def float_from_fixed(f):
    return f/256.0


def phi_from_direction(i):
    return i * 2.0 * math.pi / N_DIRECTIONS


def generate_array(f, el_type, name, comment, n_el, geterateValue):
    f.write(f"// {comment}\n")
    f.write(f"{el_type} {name}[] = {{")
    for i in range(n_el):
        if (i > 0):
            f.write(",")
        f.write("\n")
        f.write(str(geterateValue(i)))
    f.write("};\n")


def generate_direction_array(f, el_type, name, func, comment=None):
    generate_array(f, el_type, name, comment if comment else name, N_DIRECTIONS, lambda i : func(i, phi_from_direction(i), math.sin(phi_from_direction(i)), math.cos(phi_from_direction(i))))
    

def generate_distance_array(f, el_type, name, func, comment=None):
    generate_array(f, el_type, name, comment if comment else name, N_PRECALC_DRAW_DIST, lambda i : func(i, 16*i))


f = open("../tables.c", "w")
 
f.write("// Precalculated Look-up tables\n")
f.write("// Generated by " + __file__ + "\n")
f.write("\n")
f.write("#include <stdlib.h>\n")
f.write("\n")


generate_direction_array(f, "int", "f_dir_sin", \
    lambda i, phi, sin_phi, cos_phi : fixed_from_float(sin_phi))


generate_direction_array(f, "int", "f_dir_cos", \
    lambda i, phi, sin_phi, cos_phi : fixed_from_float(cos_phi))


generate_direction_array(f, "int", "f_dir_ctan", \
    lambda i, phi, sin_phi, cos_phi : fixed_from_float(cos_phi / sin_phi if sin_phi != 0.0 else (127.0 if cos_phi > 0 else -128.0)), comment="ctan of direction, saturated")


generate_direction_array(f, "int", "f_dir_tan", \
    lambda i, phi, sin_phi, cos_phi : fixed_from_float(sin_phi / cos_phi if cos_phi != 0.0 else (127.0 if sin_phi > 0 else -128.0)), comment="tan of direction, saturated")


generate_distance_array(f, "long", "f16_sqrs", \
    lambda distidx, f_dist: (f_dist * f_dist) if (distidx < N_PRECALC_DRAW_DIST-1) else 0x7FFFFFFF, comment="Squares of distance, in 16-shifted fixed point, for fast sqrt")


def gen_height(distidx, f_dist):
    if f_dist > 0:
        height = round_half_up(65.0 / float_from_fixed(f_dist))
        result = 95 - height;
        return max(result, 0);
    else:
        return 0
generate_distance_array(f, "uchar", "draw_heigths", gen_height, comment="Heights of given distance index")


def gen_height1(distidx, f_dist):
    if f_dist > 0:
        height = round_half_up(100.0 / float_from_fixed(f_dist))
        result = 97 + height;
        return min(result, 191);
    else:
        return 191
generate_distance_array(f, "uchar", "draw_heigths1", gen_height1, comment="Heights of given distance index")


def gen_height(distidx, f_dist):
    N_INTENSITIES = 17
    INTENSITY_WHITE = 16
    if f_dist > 0:
        distance = float_from_fixed(f_dist)
        intensity = INTENSITY_WHITE - round_half_up((16.0 * (1.0 / ((distance + 2.0) * 0.34))))
        return max(0, min(intensity, INTENSITY_WHITE));
    else:
        return 0
generate_distance_array(f, "uchar", "draw_intens", gen_height, comment="Color intensities of given distance index")

f.close()
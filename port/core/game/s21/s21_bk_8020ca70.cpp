#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bk_8020ca70.c"
// desc: Appears to round an unsigned value to a power of two: zero gives one, powers of two are kept, other values give the next lower bit found by a scan. Same bytes as its sibling.
unsigned w3d_s21_power_of_two_b_8020ca70(unsigned value)
{
    unsigned bit;
    if (value == 0)
        return 1;
    if ((value & -value) == value)
        return value;
    bit = 0x80000000;
    value <<= 1;
    if ((int)value >= 0) {
        do
            bit >>= 1;
        while ((bit & value) == 0);
    }
    return bit;
}

}

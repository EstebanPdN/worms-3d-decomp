#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_l_80212d4c.c"
// desc: Appears to forward a value with a sign flag for kind ten and return its second argument.
extern void fn_80212c74(int, Ptr32<void>, int, int);
int w3d_s21_forward_sign_80212d4c(int value, int result, int kind)
{
    int negative = 0;
    if (kind == 10)
        negative = (unsigned)value >> 31;
    fn_80212c74(value, w3d::G(result), kind, negative);
    return result;
}

}

#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_m_80212cf4.c"
// desc: Appears to forward a value with a sign flag set only for kind ten with a negative value, and return its second argument.
extern void fn_80212c74(int, Ptr32<void>, int, int);
int w3d_s21_forward_negative_80212cf4(int value, int result, int kind)
{
    if (kind == 10 && value < 0)
        fn_80212c74(value, w3d::G(result), 10, 1);
    else
        fn_80212c74(value, w3d::G(result), kind, 0);
    return result;
}

}

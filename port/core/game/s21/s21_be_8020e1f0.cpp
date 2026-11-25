#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_be_8020e1f0.c"
// desc: Appears to call virtual slot 7 of the object with its four arguments and a trailing one.
struct S21Object;
struct S21Methods { Ptr32<void (void)> reserved[7]; Ptr32<int (Ptr32<struct S21Object>, int, int, int, int, int)> convert; };
struct S21Object { Ptr32<struct S21Methods> methods; };
int w3d_s21_forward_flagged_8020e1f0(Ptr32<struct S21Object> self, int a, int b, int c, int d)
{
    return self->methods->convert(self, a, b, c, d, 1);
}

}

#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_c_8021bf14.c"
struct S21Inner { char pad[24]; int value; };
struct S21Outer { char pad[36]; Ptr32<struct S21Inner> inner; };
extern void fn_8021bffc(Ptr32<void>, Ptr32<void>);
void w3d_s21_forward_inner_8021bf14(Ptr32<struct S21Outer> self)
{
    fn_8021bffc(self, w3d::G(self->inner->value));
}

}

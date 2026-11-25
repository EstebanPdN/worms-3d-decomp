#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_c_8021bfd4.c"
struct S21Inner { char pad[24]; int value; };
struct S21Outer { char pad[36]; Ptr32<struct S21Inner> inner; };
extern int fn_8021e930(Ptr32<void>, int);
void w3d_s21_forward_inner_8021bfd4(Ptr32<struct S21Outer> self, int arg)
{
    fn_8021e930(w3d::G(self->inner->value), arg);
}

}

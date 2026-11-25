#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ab_802047ac.c"
// desc: Appears to forward its two arguments to a virtual slot of the inner stream object with a trailing zero.
struct S21Inner;
struct S21InnerMethods { Ptr32<void (void)> reserved[6]; Ptr32<int (Ptr32<struct S21Inner>, int, int, int)> write; };
struct S21Inner { Ptr32<struct S21InnerMethods> methods; };
struct S21Wrapper { char pad[20]; Ptr32<struct S21Inner> inner; };
int w3d_s21_forward_write_802047ac(Ptr32<struct S21Wrapper> self, int a, int b)
{
    return self->inner->methods->write(self->inner, a, b, 0);
}

}

#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_af_801df23c.c"
// desc: Appears to return a float from a virtual slot of the linked object, or a default constant when there is no link.
struct S21Link;
struct S21LinkMethods { Ptr32<void (void)> reserved[12]; Ptr32<float (Ptr32<struct S21Link>)> value; };
struct S21Link { Ptr32<struct S21LinkMethods> methods; };
struct S21Object { char pad[28]; Ptr32<struct S21Link> link; };
extern float lbl_803b0378[];
float w3d_s21_link_value_801df23c(Ptr32<struct S21Object> self){if (self->link != 0) return self->link->methods->value(self->link); return lbl_803b0378[0]; }
}

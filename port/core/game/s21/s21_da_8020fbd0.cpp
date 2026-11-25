#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_da_8020fbd0.c"
// desc: Appears to construct an object on a base constructor from five arguments, installing two vtable pointers, a 4-bit kind field and zeroed fields, then run a setup helper.
struct S21Flags { unsigned int rest:16; unsigned int kind:4; unsigned int top:12; };
struct S21Object { Ptr32<void> vtable; char pad[8]; Ptr32<void> vtable2; int a; int b; int c; int d; struct S21Flags flags; int zero1; int pad2; int zero2; };
extern Ptr32<void> fn_801ffecc(Ptr32<struct S21Object>);
extern void fn_8020fe54(Ptr32<struct S21Object>);
extern char lbl_80419598[];
extern char lbl_804195c0[];
Ptr32<struct S21Object> w3d_s21_construct_8020fbd0(Ptr32<struct S21Object> self, int a, int b, int c, unsigned kind, int d)
{
    fn_801ffecc(self);
    self->flags.top = 0;
    self->a = a;
    self->b = b;
    self->c = c;
    self->d = d;
    self->vtable2 = lbl_80419598;
    self->vtable = lbl_804195c0;
    self->flags.kind = kind;
    self->zero1 = 0;
    self->zero2 = 0;
    fn_8020fe54(self);
    return self;
}

}

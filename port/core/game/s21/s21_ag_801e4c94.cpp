#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ag_801e4c94.c"
// desc: Appears to call a virtual slot through the vtable field at offset 28 and then clear four words of the object.
struct S21Object { int a; int b; int c; int d; char pad[12]; Ptr32<Ptr32<void>> vtable; };
void w3d_s21_reset_801e4c94(Ptr32<struct S21Object> self)
{
    ((Ptr32<void (Ptr32<struct S21Object>)>)self->vtable[3])(self);
    self->d = 0;
    self->b = 0;
    self->c = 0;
    self->a = 0;
}

}

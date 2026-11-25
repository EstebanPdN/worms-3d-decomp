#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ei_801df11c.c"
// desc: Appears to copy state from another object: it retains the other's held interface, releases its own, then copies the interface pointer, a word and two bytes, returning one, or zero for a null source.
struct S21Ref;
struct S21RefMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<struct S21Ref>)> retain; Ptr32<void (Ptr32<struct S21Ref>)> release; };
struct S21Ref { Ptr32<struct S21RefMethods> methods; };
struct S21Object { char pad[28]; Ptr32<struct S21Ref> held; char pad1[12]; int value; char pad2[20]; unsigned char flag_a; unsigned char flag_b; };
int w3d_s21_copy_from_801df11c(Ptr32<struct S21Object> self, Ptr32<struct S21Object> other)
{
    if (!other)
        return 0;
    if (other->held)
        other->held->methods->retain(other->held);
    if (self->held)
        self->held->methods->release(self->held);
    self->held = other->held;
    self->value = other->value;
    self->flag_a = other->flag_a;
    self->flag_b = other->flag_b;
    return 1;
}

}

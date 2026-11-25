#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cj_802b4e8c.c"
// desc: Appears to forward the object's value to a held interface through virtual slot 22 and call a function pointer of the owner on the embedded part when a flag is set.
struct S21Interface;
struct S21InterfaceMethods { Ptr32<void (void)> reserved[22]; Ptr32<void (Ptr32<struct S21Interface>, int)> apply; };
struct S21Interface { Ptr32<struct S21InterfaceMethods> methods; };
struct S21Owner { char pad[56]; Ptr32<void (Ptr32<void>)> notify; };
struct S21Object { char pad[28]; char part[148]; int enabled; char pad1[28]; Ptr32<struct S21Owner> owner; char pad2[8]; int value; char pad3[16]; Ptr32<struct S21Interface> held; };
void w3d_s21_sync_802b4e8c(Ptr32<struct S21Object> self)
{
    if (self->held)
        self->held->methods->apply(self->held, self->value);
    if (self->enabled)
        self->owner->notify(self->part);
}

}

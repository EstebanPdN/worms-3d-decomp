#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s11_receiver_8026d9a0.c"
/* Inferred interface relationships; slot offsets come from original loads. */
typedef struct S11Interface S11Interface;
typedef struct S11VTable {
    char unknown00[0x10];
    Ptr32<void (Ptr32<S11Interface>)> release;
    char unknown14[4];
    Ptr32<Ptr32<S11Interface> (Ptr32<S11Interface>)> related;
    char unknown1c[0x40];
    Ptr32<void (Ptr32<S11Interface>, Ptr32<S11Interface>, int)> attach;
    Ptr32<void (Ptr32<S11Interface>, Ptr32<S11Interface>)> detach;
} S11VTable;
struct S11Interface { Ptr32<S11VTable> vtable; };
typedef struct S11Owner {
    char unknown00[0x48];
    int initialized;
    Ptr32<S11Interface> target;
} S11Owner;
extern void fn_8026DBE8(Ptr32<void>);
void s11_transfer_interface_8026d9a0(Ptr32<S11Owner> owner, Ptr32<Ptr32<S11Interface>> incoming) {
    Ptr32<S11Interface> related;
    if (!owner->initialized) fn_8026DBE8((Ptr32<void>)owner);
    if (owner->target->vtable->related(owner->target)) {
        related = owner->target->vtable->related(owner->target);
        related->vtable->detach(related, owner->target);
    }
    (*incoming)->vtable->attach(*incoming, owner->target, 0);
}

}

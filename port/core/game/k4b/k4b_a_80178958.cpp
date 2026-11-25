#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_80178958.c"
struct K4bIface { Ptr32<Ptr32<void>> vtable; };
struct K4bHolder {
    Ptr32<Ptr32<void>> vtable;
    Ptr32<struct K4bIface> held;
    unsigned char slot;
};
extern Ptr32<void> w3d_vtable_80412680[];
extern void w3d_actor_member_delete_backend(Ptr32<void> p);
void w3d_k4b_holder_delete_80178958(Ptr32<struct K4bHolder> self, int flags)
{
    Ptr32<struct K4bIface> held;
    Ptr32<struct K4bIface> none;
    self->vtable = w3d_vtable_80412680;
    held = self->held;
    none = 0;
    if (held != none)
        ((Ptr32<void (Ptr32<struct K4bIface>)>)held->vtable[4])(held);
    self->held = none;
    self->slot = 255;
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}
// desc: w3d_k4b_holder_delete_80178958: Appears to be a deleting destructor that releases a held interface through its fifth slot, clears it, marks the slot byte 255 and frees the object when flag bit one is set.

}

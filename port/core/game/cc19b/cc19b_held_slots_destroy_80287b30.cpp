#include "w3d_ptr.h"
#line 1 "cc19b_held_slots_destroy_80287b30.cpp"
// Observed object with a 64-element held-interface array starting at offset 28.
// New retry uses the exact admitted Cc19bHeld virtual-call expression/body.
#define CC19B_VCALL(p, T, o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o))))
struct Cc19bHeld
{
    Ptr32<void> held;
    ~Cc19bHeld() { if (held) CC19B_VCALL(held, void (*)(void *), 16)(held); }
};
extern Ptr32<const void> w3d_vtable_8041c010[];
extern "C" void w3d_base_destroy_8015ff2c(Ptr32<void> self, int flags);
struct Cc19bObject
{
    Ptr32<const void> vtable;      // +0
    char pad4[24];
    Cc19bHeld slots[64];        // +28
    ~Cc19bObject() {}
};
extern "C" void w3d_cc19b_held_slots_destroy_80287b30(Ptr32<void> self, int flags)
{
    Ptr32<Cc19bObject> o = (Ptr32<Cc19bObject>)self;
    o->vtable = w3d_vtable_8041c010;
    o->~Cc19bObject();
    w3d_base_destroy_8015ff2c(self, flags);
}



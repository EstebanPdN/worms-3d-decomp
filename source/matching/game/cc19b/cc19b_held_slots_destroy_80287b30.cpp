// Observed object with a 64-element held-interface array starting at offset 28.
// New retry uses the exact admitted Cc19bHeld virtual-call expression/body.
#define CC19B_VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
struct Cc19bHeld
{
    void *held;
    ~Cc19bHeld() { if (held) CC19B_VCALL(held, void (*)(void *), 16)(held); }
};
extern const void *w3d_vtable_8041c010[];
extern "C" void w3d_base_destroy_8015ff2c(void *self, int flags);
struct Cc19bObject
{
    const void *vtable;      // +0
    char pad4[24];
    Cc19bHeld slots[64];        // +28
    ~Cc19bObject() {}
};
extern "C" void w3d_cc19b_held_slots_destroy_80287b30(void *self, int flags)
{
    Cc19bObject *o = (Cc19bObject *)self;
    o->vtable = w3d_vtable_8041c010;
    o->~Cc19bObject();
    w3d_base_destroy_8015ff2c(self, flags);
}

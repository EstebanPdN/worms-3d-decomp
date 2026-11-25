// Appears to be the destructor of an object holding four interfaces in an array.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
struct K8aHeld
{
    void *held;
    ~K8aHeld() { if (held) VCALL(held, void (*)(void *), 16)(held); }
};
extern const void *w3d_vtable_8040eb20[];
extern "C" void w3d_base_destroy_8015ff2c(void *self, int flags);
struct K8aObject
{
    const void *vtable;      // +0
    char pad4[40];
    K8aHeld slots[4];        // +44
    ~K8aObject() {}
};
extern "C" void w3d_k8a_held_quad_destroy_80051564(void *self, int flags)
{
    K8aObject *o = (K8aObject *)self;
    o->vtable = w3d_vtable_8040eb20;
    o->~K8aObject();
    w3d_base_destroy_8015ff2c(self, flags);
}

// Appears to be the destructor of a service-derived object holding nine interfaces
// in an array followed by one more held interface.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
struct K8aHeld
{
    void *held;
    ~K8aHeld() { if (held) VCALL(held, void (*)(void *), 16)(held); }
};
extern const void *w3d_vtable_8040eaa0[];
extern "C" void w3d_service_destroy_801628ec(void *self, int flags);
struct K8aObject
{
    const void *vtable;      // +0
    char pad4[24];
    K8aHeld slots[9];        // +28
    K8aHeld top;             // +64
    ~K8aObject() {}
};
extern "C" void w3d_k8a_held_array_destroy_8004f118(void *self, int flags)
{
    K8aObject *o = (K8aObject *)self;
    o->vtable = w3d_vtable_8040eaa0;
    o->~K8aObject();
    w3d_service_destroy_801628ec(self, flags);
}

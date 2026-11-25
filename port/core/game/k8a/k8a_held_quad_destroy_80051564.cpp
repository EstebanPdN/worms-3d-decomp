#include "w3d_ptr.h"
#line 1 "k8a_held_quad_destroy_80051564.cpp"
// Appears to be the destructor of an object holding four interfaces in an array.
#define VCALL(p, T, o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o))))
struct K8aHeld
{
    Ptr32<void> held;
    ~K8aHeld() { if (held) VCALL(held, void (*)(void *), 16)(held); }
};
extern Ptr32<const void> w3d_vtable_8040eb20[];
extern "C" void w3d_base_destroy_8015ff2c(Ptr32<void> self, int flags);
struct K8aObject
{
    Ptr32<const void> vtable;      // +0
    char pad4[40];
    K8aHeld slots[4];        // +44
    ~K8aObject() {}
};
extern "C" void w3d_k8a_held_quad_destroy_80051564(Ptr32<void> self, int flags)
{
    Ptr32<K8aObject> o = (Ptr32<K8aObject>)self;
    o->vtable = w3d_vtable_8040eb20;
    o->~K8aObject();
    w3d_base_destroy_8015ff2c(self, flags);
}



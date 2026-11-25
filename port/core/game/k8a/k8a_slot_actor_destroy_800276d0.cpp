#include "w3d_ptr.h"
#line 1 "k8a_slot_actor_destroy_800276d0.cpp"
// Appears to be the destructor of a service-derived object that holds interfaces
// in a 20-slot array, a single slot and a top-level slot, plus two handle members.
// The member destructors are real inline destructors; the explicit destructor
// call reproduces the compiler's reverse-order member cleanup.
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
#define VCALL(p, T, o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o))))
extern Ptr32<const void> w3d_vtable_8040e1c8[];
extern "C" void w3d_actor_handle_member_destroy(Ptr32<void> member, int flags);
extern "C" void w3d_service_destroy_801628ec(Ptr32<void> self, int flags);
struct K8aHeld
{
    Ptr32<void> held;
    ~K8aHeld() { if (held) VCALL(held, void (*)(void *), 16)(held); }
};
struct K8aHandle
{
    Ptr32<void> word;
    ~K8aHandle() { w3d_actor_handle_member_destroy(this, 2); }
};
struct K8aObject
{
    Ptr32<const void> vtable;      // +0
    char pad4[24];
    K8aHeld slots[20];       // +28
    K8aHeld single;          // +108
    K8aHandle first;         // +112
    int pad;
    K8aHandle second;        // +120
    char pad124[88];
    K8aHeld top;             // +212
    ~K8aObject() {}
};
extern "C" void w3d_k8a_slot_actor_destroy_800276d0(Ptr32<void> self, int flags)
{
    Ptr32<K8aObject> o = (Ptr32<K8aObject>)self;
    o->vtable = w3d_vtable_8040e1c8;
    o->~K8aObject();
    w3d_service_destroy_801628ec(self, flags);
}



#include "w3d_ptr.h"
#line 1 "k8a_sinks_dispatch_8002daf0.cpp"
// Appears to forward the held sink interface and the five listener interfaces of an
// object to a dispatcher, then notifies the base with a message value.
struct K8aRef;
struct K8aRefVtable { Ptr32<void (void)> unknown_00[3]; Ptr32<void (Ptr32<K8aRef>)> retain; Ptr32<void (Ptr32<K8aRef>)> release; };
struct K8aRef { Ptr32<const K8aRefVtable> vtable; };
struct K8aHeldSlot { Ptr32<K8aRef> ref; };
struct K8aOwner
{
    char pad0[32];
    Ptr32<K8aRef> sink;            // +32
    char pad36[56];
    Ptr32<K8aRef> listeners[5];    // +92
};
extern "C" int w3d_fn_8004e384(Ptr32<K8aOwner> self, int a, int b);
extern "C" void w3d_fn_8004e2a4(Ptr32<K8aOwner> self, Ptr32<K8aHeldSlot> slot, int value);
extern "C" int w3d_constant_8015fb2c(Ptr32<K8aOwner> self, int message);
static inline void k8a_held_set(Ptr32<K8aHeldSlot> slot, Ptr32<K8aRef> ref)
{
    slot->ref = ref;
    if (ref)
        ref->vtable->retain(ref);
}
extern "C" int w3d_k8a_sinks_dispatch_8002daf0(Ptr32<K8aOwner> self, int message)
{
    K8aHeldSlot slot;
    int value = w3d_fn_8004e384(self, 0, 0);
    k8a_held_set(&slot, self->sink);
    unsigned int index = 0;
    w3d_fn_8004e2a4(self, &slot, value);
    Ptr32<Ptr32<K8aRef>> listener = self->listeners;
    do
    {
        k8a_held_set(&slot, *listener);
        w3d_fn_8004e2a4(self, &slot, value);
        index++;
        listener++;
    } while (index <= 4);
    w3d_constant_8015fb2c(self, message);
    return 0;
}



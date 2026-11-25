// Appears to forward the held sink interface and the five listener interfaces of an
// object to a dispatcher, then notifies the base with a message value.
struct K8aRef;
struct K8aRefVtable { void (*unknown_00[3])(void); void (*retain)(K8aRef *self); void (*release)(K8aRef *self); };
struct K8aRef { const K8aRefVtable *vtable; };
struct K8aHeldSlot { K8aRef *ref; };
struct K8aOwner
{
    char pad0[32];
    K8aRef *sink;            // +32
    char pad36[56];
    K8aRef *listeners[5];    // +92
};
extern "C" int w3d_fn_8004e384(K8aOwner *self, int a, int b);
extern "C" void w3d_fn_8004e2a4(K8aOwner *self, K8aHeldSlot *slot, int value);
extern "C" int w3d_constant_8015fb2c(K8aOwner *self, int message);
static inline void k8a_held_set(K8aHeldSlot *slot, K8aRef *ref)
{
    slot->ref = ref;
    if (ref)
        ref->vtable->retain(ref);
}
extern "C" int w3d_k8a_sinks_dispatch_8002daf0(K8aOwner *self, int message)
{
    K8aHeldSlot slot;
    int value = w3d_fn_8004e384(self, 0, 0);
    k8a_held_set(&slot, self->sink);
    unsigned int index = 0;
    w3d_fn_8004e2a4(self, &slot, value);
    K8aRef **listener = self->listeners;
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

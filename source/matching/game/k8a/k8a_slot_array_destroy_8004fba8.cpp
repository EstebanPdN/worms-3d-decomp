// Appears to be the destructor of a service that owns an array of held interfaces:
// it releases and clears every slot, clears a global pointer, destroys the array
// storage and calls the base destructor.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
struct K8aSlotArray
{
    unsigned int count;      // +44
    int pad;
    void **data;             // +52
};
struct K8aService
{
    const void *vtable;
    char pad4[40];
    K8aSlotArray slots;      // +44
};
extern const void *w3d_vtable_8040eae0[];
extern void *w3d_global_804aaa04;
extern "C" void w3d_auto_80210abc(void *array, int flags);
extern "C" void w3d_service_destroy_801628ec(void *self, int flags);
static inline void **k8a_begin(K8aSlotArray *a)
{
    return a->data;
}
static inline void **k8a_end(K8aSlotArray *a)
{
    return a->data + a->count;
}
extern "C" void w3d_k8a_slot_array_destroy_8004fba8(K8aService *self, int flags)
{
    self->vtable = w3d_vtable_8040eae0;
    for (void **p = k8a_begin(&self->slots); p != k8a_end(&self->slots); p++)
    {
        if (*p)
            VCALL(*p, void (*)(void *), 16)(*p);
        *p = 0;
    }
    w3d_global_804aaa04 = 0;
    w3d_auto_80210abc(&self->slots, 2);
    w3d_service_destroy_801628ec(self, flags);
}

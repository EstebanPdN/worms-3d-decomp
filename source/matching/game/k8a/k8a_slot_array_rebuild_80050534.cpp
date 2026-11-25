// Appears to rebuild a service's slot array: it releases and clears every held slot,
// refills the array from the service call, and sorts the entries.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
struct K8aSlotArray
{
    unsigned int count;      // +44
    int pad;
    void **data;             // +52
};
struct K8aService
{
    char pad0[44];
    K8aSlotArray slots;      // +44
};
extern "C" void w3d_task_deferred_clear(K8aSlotArray *array);
extern "C" void *w3d_s20_service_call_800fc668(void);
extern "C" void w3d_fn_80210b90(K8aSlotArray *array, void *service);
extern "C" int w3d_auto_800fc69c(void **out, void *slot);
extern "C" int w3d_compare_800504d0(const void *a, const void *b);
extern "C" void qsort(void *base, unsigned int count, unsigned int size, int (*compare)(const void *, const void *));
static inline void **k8a_begin(K8aSlotArray *a)
{
    return a->data;
}
static inline void **k8a_end(K8aSlotArray *a)
{
    return a->data + a->count;
}
extern "C" void w3d_k8a_slot_array_rebuild_80050534(K8aService *self)
{
    void *local;
    for (void **p = k8a_begin(&self->slots); p != k8a_end(&self->slots); p++)
    {
        if (*p)
            VCALL(*p, void (*)(void *), 16)(*p);
        *p = 0;
    }
    K8aSlotArray *array = &self->slots;
    int offset = -4;
    w3d_task_deferred_clear(array);
    w3d_fn_80210b90(array, w3d_s20_service_call_800fc668());
    do
    {
        local = 0;
        offset += 4;
    } while (w3d_auto_800fc69c(&local, (char *)array->data + offset));
    qsort(array->data, self->slots.count, 4, w3d_compare_800504d0);
}

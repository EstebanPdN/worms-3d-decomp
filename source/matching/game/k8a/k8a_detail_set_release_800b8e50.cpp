// Appears to release a detail set: it releases one held interface, destroys every
// detail object in its pointer vector, clearing each slot, then empties the vector.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
struct K8aPtrVector
{
    void **begin;
    void **end;
};
struct K8aDetailSet
{
    int pad0;
    void *held;              // +4
    char pad8[12];
    K8aPtrVector details;    // +20
};
extern "C" void w3d_fn_800600d4(void *detail, int flags);
extern "C" void w3d_memcpy_802eee50(void *dest, const void *source, unsigned int size, ...);
static inline unsigned int k8a_count(K8aPtrVector *v)
{
    return v->end - v->begin;
}
static inline void k8a_clear(K8aPtrVector *v)
{
    void **first = v->begin;
    void **last = v->end;
    int removed = (char *)last - (char *)first;
    w3d_memcpy_802eee50(first, last, (char *)v->end - (char *)last);
    v->end = (void **)((char *)v->end - removed);
}
extern "C" void w3d_k8a_detail_set_release_800b8e50(K8aDetailSet *self)
{
    int zero = 0;
    if (self->held)
        VCALL(self->held, void (*)(void *), 16)(self->held);
    self->held = 0;
    for (unsigned int i = zero; i < k8a_count(&self->details); i++)
    {
        if (*(void **)((char *)self->details.begin + (i << 2)))
            w3d_fn_800600d4(*(void **)((char *)self->details.begin + (i << 2)), 3);
        *(void **)((char *)self->details.begin + (i << 2)) = 0;
    }
    k8a_clear(&self->details);
}

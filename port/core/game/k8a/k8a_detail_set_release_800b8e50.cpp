#include "w3d_ptr.h"
#line 1 "k8a_detail_set_release_800b8e50.cpp"
// Appears to release a detail set: it releases one held interface, destroys every
// detail object in its pointer vector, clearing each slot, then empties the vector.
#define VCALL(p, T, o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o))))
struct K8aPtrVector
{
    Ptr32<Ptr32<void>> begin;
    Ptr32<Ptr32<void>> end;
};
struct K8aDetailSet
{
    int pad0;
    Ptr32<void> held;              // +4
    char pad8[12];
    K8aPtrVector details;    // +20
};
extern "C" void w3d_fn_800600d4(Ptr32<void> detail, int flags);
extern "C" void w3d_memcpy_802eee50(Ptr32<void> dest, Ptr32<const void> source, unsigned int size, ...);
static inline unsigned int k8a_count(Ptr32<K8aPtrVector> v)
{
    return v->end - v->begin;
}
static inline void k8a_clear(Ptr32<K8aPtrVector> v)
{
    Ptr32<Ptr32<void>> first = v->begin;
    Ptr32<Ptr32<void>> last = v->end;
    int removed = (Ptr32<char>)last - (Ptr32<char>)first;
    w3d_memcpy_802eee50(first, last, (Ptr32<char>)v->end - (Ptr32<char>)last);
    v->end = (Ptr32<Ptr32<void>>)((Ptr32<char>)v->end - removed);
}
extern "C" void w3d_k8a_detail_set_release_800b8e50(Ptr32<K8aDetailSet> self)
{
    int zero = 0;
    if (self->held)
        VCALL(self->held, void (*)(void *), 16)(self->held);
    self->held = 0;
    for (unsigned int i = zero; i < k8a_count(&self->details); i++)
    {
        if (*(Ptr32<Ptr32<void>>)((Ptr32<char>)self->details.begin + (i << 2)))
            w3d_fn_800600d4(*(Ptr32<Ptr32<void>>)((Ptr32<char>)self->details.begin + (i << 2)), 3);
        *(Ptr32<Ptr32<void>>)((Ptr32<char>)self->details.begin + (i << 2)) = 0;
    }
    k8a_clear(&self->details);
}



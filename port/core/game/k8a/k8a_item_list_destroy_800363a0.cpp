#include "w3d_ptr.h"
#line 1 "k8a_item_list_destroy_800363a0.cpp"
// Appears to be the deleting destructor of an item list: it destroys every item in its
// pointer vector, empties the vector, releases three held interfaces and frees the list.
#define VCALL(p, T, o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o))))
struct K8aHeld
{
    Ptr32<void> held;
    ~K8aHeld() { if (held) VCALL(held, void (*)(void *), 16)(held); }
};
extern "C" void w3d_handle_storage_release(Ptr32<void> storage);
extern "C" void w3d_auto_80036a94(Ptr32<void> item, int flags);
extern "C" void w3d_heap_release(Ptr32<void> heap, Ptr32<void> object);
extern "C" void w3d_memcpy_802eee50(Ptr32<void> dest, Ptr32<const void> source, unsigned int size, ...);
extern unsigned int w3d_heap_804b0044;
struct K8aPtrVector
{
    Ptr32<Ptr32<void>> begin;
    Ptr32<Ptr32<void>> end;
    int pad8;
    Ptr32<Ptr32<void>> capacity;
    ~K8aPtrVector() { if (begin) w3d_handle_storage_release(begin); }
};
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
struct K8aItemList
{
    int pad0;
    K8aPtrVector items;      // +4
    K8aHeld first;           // +20
    K8aHeld second;          // +24
    K8aHeld third;           // +28
    ~K8aItemList() {}
};
extern "C" void w3d_k8a_item_list_destroy_800363a0(Ptr32<K8aItemList> self, int flags)
{
    int zero = 0;
    for (unsigned int i = zero; i < k8a_count(&self->items); i++)
    {
        if (*(Ptr32<Ptr32<void>>)((Ptr32<char>)self->items.begin + (i << 2)))
            w3d_auto_80036a94(*(Ptr32<Ptr32<void>>)((Ptr32<char>)self->items.begin + (i << 2)), 3);
    }
    k8a_clear(&self->items);
    self->~K8aItemList();
    if (flags & 1)
        w3d_heap_release(&w3d_heap_804b0044, self);
}



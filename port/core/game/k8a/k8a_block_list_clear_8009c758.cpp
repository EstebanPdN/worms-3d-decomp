#include "w3d_ptr.h"
#line 1 "k8a_block_list_clear_8009c758.cpp"
// Appears to clear a block list: it frees every pooled block in its pointer vector,
// empties the vector, destroys an attached child, releases a held interface and
// clears a global flag.
#define VCALL(p, T, o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o))))
struct K8aPtrVector
{
    Ptr32<Ptr32<void>> begin;
    Ptr32<Ptr32<void>> end;
};
struct K8aBlockList
{
    char pad0[56];
    K8aPtrVector blocks;     // +56
    char pad64[32];
    Ptr32<void> held;              // +96
    char pad100[20];
    Ptr32<void> child;             // +120
};
extern unsigned int w3d_heap_804af5bc;
extern int w3d_global_804aabe8;
extern "C" void w3d_heap_release(Ptr32<void> heap, Ptr32<void> object);
extern "C" void w3d_auto_800e5bb8(Ptr32<void> child);
extern "C" void w3d_memcpy_802eee50(Ptr32<void> dest, Ptr32<const void> source, unsigned int size, ...);
static inline Ptr32<Ptr32<void>> k8a_end(Ptr32<K8aPtrVector> v)
{
    return v->end;
}
static inline void k8a_clear(Ptr32<K8aPtrVector> v)
{
    Ptr32<Ptr32<void>> first = v->begin;
    Ptr32<Ptr32<void>> last = v->end;
    int removed = (Ptr32<char>)last - (Ptr32<char>)first;
    w3d_memcpy_802eee50(first, last, (Ptr32<char>)v->end - (Ptr32<char>)last);
    v->end = (Ptr32<Ptr32<void>>)((Ptr32<char>)v->end - removed);
}
extern "C" void w3d_k8a_block_list_clear_8009c758(Ptr32<K8aBlockList> self)
{
    for (Ptr32<Ptr32<void>> p = self->blocks.begin; p != k8a_end(&self->blocks); p++)
        w3d_heap_release(&w3d_heap_804af5bc, *p);
    k8a_clear(&self->blocks);
    Ptr32<void> none = 0;
    if (self->child)
    {
        w3d_auto_800e5bb8(self->child);
        self->child = none;
    }
    if (self->held)
        VCALL(self->held, void (*)(void *), 16)(self->held);
    self->held = none;
    w3d_global_804aabe8 = (int)w3d::H(none);
}



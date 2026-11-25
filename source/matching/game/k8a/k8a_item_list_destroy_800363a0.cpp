// Appears to be the deleting destructor of an item list: it destroys every item in its
// pointer vector, empties the vector, releases three held interfaces and frees the list.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
struct K8aHeld
{
    void *held;
    ~K8aHeld() { if (held) VCALL(held, void (*)(void *), 16)(held); }
};
extern "C" void w3d_handle_storage_release(void *storage);
extern "C" void w3d_auto_80036a94(void *item, int flags);
extern "C" void w3d_heap_release(void *heap, void *object);
extern "C" void w3d_memcpy_802eee50(void *dest, const void *source, unsigned int size, ...);
extern unsigned int w3d_heap_804b0044;
struct K8aPtrVector
{
    void **begin;
    void **end;
    int pad8;
    void **capacity;
    ~K8aPtrVector() { if (begin) w3d_handle_storage_release(begin); }
};
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
struct K8aItemList
{
    int pad0;
    K8aPtrVector items;      // +4
    K8aHeld first;           // +20
    K8aHeld second;          // +24
    K8aHeld third;           // +28
    ~K8aItemList() {}
};
extern "C" void w3d_k8a_item_list_destroy_800363a0(K8aItemList *self, int flags)
{
    int zero = 0;
    for (unsigned int i = zero; i < k8a_count(&self->items); i++)
    {
        if (*(void **)((char *)self->items.begin + (i << 2)))
            w3d_auto_80036a94(*(void **)((char *)self->items.begin + (i << 2)), 3);
    }
    k8a_clear(&self->items);
    self->~K8aItemList();
    if (flags & 1)
        w3d_heap_release(&w3d_heap_804b0044, self);
}

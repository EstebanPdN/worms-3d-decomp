// Appears to clear a block list: it frees every pooled block in its pointer vector,
// empties the vector, destroys an attached child, releases a held interface and
// clears a global flag.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
struct K8aPtrVector
{
    void **begin;
    void **end;
};
struct K8aBlockList
{
    char pad0[56];
    K8aPtrVector blocks;     // +56
    char pad64[32];
    void *held;              // +96
    char pad100[20];
    void *child;             // +120
};
extern unsigned int w3d_heap_804af5bc;
extern int w3d_global_804aabe8;
extern "C" void w3d_heap_release(void *heap, void *object);
extern "C" void w3d_auto_800e5bb8(void *child);
extern "C" void w3d_memcpy_802eee50(void *dest, const void *source, unsigned int size, ...);
static inline void **k8a_end(K8aPtrVector *v)
{
    return v->end;
}
static inline void k8a_clear(K8aPtrVector *v)
{
    void **first = v->begin;
    void **last = v->end;
    int removed = (char *)last - (char *)first;
    w3d_memcpy_802eee50(first, last, (char *)v->end - (char *)last);
    v->end = (void **)((char *)v->end - removed);
}
extern "C" void w3d_k8a_block_list_clear_8009c758(K8aBlockList *self)
{
    for (void **p = self->blocks.begin; p != k8a_end(&self->blocks); p++)
        w3d_heap_release(&w3d_heap_804af5bc, *p);
    k8a_clear(&self->blocks);
    void *none = 0;
    if (self->child)
    {
        w3d_auto_800e5bb8(self->child);
        self->child = none;
    }
    if (self->held)
        VCALL(self->held, void (*)(void *), 16)(self->held);
    self->held = none;
    w3d_global_804aabe8 = (int)none;
}

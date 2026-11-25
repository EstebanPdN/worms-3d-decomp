/* Complete native storage adapters; signatures and service roles inferred. */
struct TemporaryOwner;
struct W3dHeap;
typedef unsigned int u32;
extern "C" {
extern W3dHeap *w3d_buffer_heap;
extern void *w3d_buffer_heap_dispatch_802098fc(W3dHeap *,u32,u32);
extern u32 w3d_buffer_heap_dispatch_80209a20(W3dHeap *);
extern void w3d_heap_release(W3dHeap *,void *);
extern void w3d_buffer_heap_dispatch_80209968(W3dHeap *);
void *w3d_buffer_storage_allocate(TemporaryOwner *unused,u32 size)
{
    return w3d_buffer_heap_dispatch_802098fc(w3d_buffer_heap,size,32);
}
u32 w3d_buffer_storage_available(TemporaryOwner *unused)
{
    return w3d_buffer_heap_dispatch_80209a20(w3d_buffer_heap);
}
void w3d_buffer_storage_release(TemporaryOwner *unused,void *data)
{
    w3d_heap_release(w3d_buffer_heap,data);
    w3d_buffer_heap_dispatch_80209968(w3d_buffer_heap);
}
}

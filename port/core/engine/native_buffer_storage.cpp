#include "w3d_ptr.h"
#line 1 "native_buffer_storage.cpp"
/* Complete native storage adapters; signatures and service roles inferred. */
struct TemporaryOwner;
struct W3dHeap;
typedef unsigned int u32;
extern "C" {
extern Ptr32<W3dHeap> w3d_buffer_heap;
extern Ptr32<void> w3d_buffer_heap_dispatch_802098fc(Ptr32<W3dHeap>,u32,u32);
extern u32 w3d_buffer_heap_dispatch_80209a20(Ptr32<W3dHeap>);
extern void w3d_heap_release(Ptr32<W3dHeap>,Ptr32<void>);
extern void w3d_buffer_heap_dispatch_80209968(Ptr32<W3dHeap>);
Ptr32<void> w3d_buffer_storage_allocate(Ptr32<TemporaryOwner> unused,u32 size)
{
    return w3d_buffer_heap_dispatch_802098fc(w3d_buffer_heap,size,32);
}
u32 w3d_buffer_storage_available(Ptr32<TemporaryOwner> unused)
{
    return w3d_buffer_heap_dispatch_80209a20(w3d_buffer_heap);
}
void w3d_buffer_storage_release(Ptr32<TemporaryOwner> unused,Ptr32<void> data)
{
    w3d_heap_release(w3d_buffer_heap,data);
    w3d_buffer_heap_dispatch_80209968(w3d_buffer_heap);
}
}



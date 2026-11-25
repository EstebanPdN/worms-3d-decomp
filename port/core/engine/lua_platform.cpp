#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "lua_platform.c"
/* Reconstructed Lua allocation and profiling interfaces, GWMP8P revision 0.
 * Heap-core and profiling service implementations are separate obligations.
 */
#include <stddef.h>

typedef unsigned int W3dSize;
typedef struct W3dHeapCallbacks W3dHeapCallbacks;
struct W3dHeapCallbacks {
    Ptr32<Ptr32<void> (Ptr32<W3dHeapCallbacks>, W3dSize)> allocate;
    Ptr32<Ptr32<void> (Ptr32<W3dHeapCallbacks>, Ptr32<void>, W3dSize, int)> resize;
    Ptr32<void (Ptr32<W3dHeapCallbacks>, Ptr32<void>)> release;
};
typedef struct W3dHeapCore {
    Ptr32<W3dHeapCallbacks> callbacks;
    unsigned char unknown_04[0x10];
    unsigned int flags;
} W3dHeapCore;
typedef struct W3dHeap {
    Ptr32<W3dHeapCore> core;
} W3dHeap;

extern W3dHeap w3d_lua_heap;
extern Ptr32<void> w3d_heap_core_allocate(Ptr32<W3dHeapCore>, W3dSize);
extern void w3d_heap_core_release(Ptr32<W3dHeapCore>, Ptr32<void>);
extern Ptr32<void> w3d_heap_core_resize(Ptr32<W3dHeapCore>, Ptr32<void>, W3dSize);
extern Ptr32<void> w3d_aligned_allocate(W3dSize, unsigned int);
extern void w3d_aligned_release(Ptr32<void>);
extern Ptr32<void> w3d_aligned_resize(Ptr32<void>, W3dSize, unsigned int);
extern Ptr32<void> w3d_system_allocate_aligned(unsigned int, W3dSize);
extern void w3d_system_release(Ptr32<void>);
extern void w3d_profile_refresh(void);
extern void w3d_profile_begin(Ptr32<const char>);
extern void w3d_profile_end(Ptr32<const char>);

Ptr32<void> w3d_aligned_allocate(W3dSize size, unsigned int alignment)
{
    return w3d_system_allocate_aligned(alignment, size);
}

void w3d_aligned_release(Ptr32<void> block)
{
    w3d_system_release(block);
}

Ptr32<void> w3d_heap_core_allocate(Ptr32<W3dHeapCore> heap, W3dSize size)
{
    Ptr32<void> result;
    if (heap->flags & 0x10)
        result = w3d_aligned_allocate(size, 16);
    else
        result = heap->callbacks->allocate(heap->callbacks, size);
    return result;
}

void w3d_heap_core_release(Ptr32<W3dHeapCore> heap, Ptr32<void> block)
{
    if (heap->flags & 0x10)
        w3d_aligned_release(block);
    else
        heap->callbacks->release(heap->callbacks, block);
}

Ptr32<void> w3d_heap_core_resize(Ptr32<W3dHeapCore> heap, Ptr32<void> block, W3dSize size)
{
    Ptr32<void> result;
    if (heap->flags & 0x10)
        result = w3d_aligned_resize(block, size, 16);
    else
        result = heap->callbacks->resize(heap->callbacks, block, size, 0);
    return result;
}

Ptr32<void> w3d_heap_allocate(Ptr32<W3dHeap> heap, W3dSize size)
{
    return w3d_heap_core_allocate(heap->core, size);
}

void w3d_heap_release(Ptr32<W3dHeap> heap, Ptr32<void> block)
{
    w3d_heap_core_release(heap->core, block);
}

Ptr32<void> w3d_heap_resize(Ptr32<W3dHeap> heap, Ptr32<void> block, W3dSize size)
{
    return w3d_heap_core_resize(heap->core, block, size);
}

void w3d_lua_release(Ptr32<void> block)
{
    w3d_heap_release(&w3d_lua_heap, block);
}

void w3d_lua_gc_boundary(Ptr32<void> state, int active)
{
    (void)state;
    if (active) {
        w3d_profile_refresh();
        w3d_profile_begin("XLua.GC");
    } else {
        w3d_profile_refresh();
        w3d_profile_end("XLua.GC");
    }
}

}

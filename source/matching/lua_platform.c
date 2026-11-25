/* Reconstructed Lua allocation and profiling interfaces, GWMP8P revision 0.
 * Heap-core and profiling service implementations are separate obligations.
 */
#include <stddef.h>

typedef unsigned long W3dSize;
typedef struct W3dHeapCallbacks W3dHeapCallbacks;
struct W3dHeapCallbacks {
    void *(*allocate)(W3dHeapCallbacks *, W3dSize);
    void *(*resize)(W3dHeapCallbacks *, void *, W3dSize, int);
    void (*release)(W3dHeapCallbacks *, void *);
};
typedef struct W3dHeapCore {
    W3dHeapCallbacks *callbacks;
    unsigned char unknown_04[0x10];
    unsigned int flags;
} W3dHeapCore;
typedef struct W3dHeap {
    W3dHeapCore *core;
} W3dHeap;

extern W3dHeap w3d_lua_heap;
extern void *w3d_heap_core_allocate(W3dHeapCore *, W3dSize);
extern void w3d_heap_core_release(W3dHeapCore *, void *);
extern void *w3d_heap_core_resize(W3dHeapCore *, void *, W3dSize);
extern void *w3d_aligned_allocate(W3dSize, unsigned int);
extern void w3d_aligned_release(void *);
extern void *w3d_aligned_resize(void *, W3dSize, unsigned int);
extern void *w3d_system_allocate_aligned(unsigned int, W3dSize);
extern void w3d_system_release(void *);
extern void w3d_profile_refresh(void);
extern void w3d_profile_begin(const char *);
extern void w3d_profile_end(const char *);

void *w3d_aligned_allocate(W3dSize size, unsigned int alignment)
{
    return w3d_system_allocate_aligned(alignment, size);
}

void w3d_aligned_release(void *block)
{
    w3d_system_release(block);
}

void *w3d_heap_core_allocate(W3dHeapCore *heap, W3dSize size)
{
    void *result;
    if (heap->flags & 0x10)
        result = w3d_aligned_allocate(size, 16);
    else
        result = heap->callbacks->allocate(heap->callbacks, size);
    return result;
}

void w3d_heap_core_release(W3dHeapCore *heap, void *block)
{
    if (heap->flags & 0x10)
        w3d_aligned_release(block);
    else
        heap->callbacks->release(heap->callbacks, block);
}

void *w3d_heap_core_resize(W3dHeapCore *heap, void *block, W3dSize size)
{
    void *result;
    if (heap->flags & 0x10)
        result = w3d_aligned_resize(block, size, 16);
    else
        result = heap->callbacks->resize(heap->callbacks, block, size, 0);
    return result;
}

void *w3d_heap_allocate(W3dHeap *heap, W3dSize size)
{
    return w3d_heap_core_allocate(heap->core, size);
}

void w3d_heap_release(W3dHeap *heap, void *block)
{
    w3d_heap_core_release(heap->core, block);
}

void *w3d_heap_resize(W3dHeap *heap, void *block, W3dSize size)
{
    return w3d_heap_core_resize(heap->core, block, size);
}

void w3d_lua_release(void *block)
{
    w3d_heap_release(&w3d_lua_heap, block);
}

void w3d_lua_gc_boundary(void *state, int active)
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

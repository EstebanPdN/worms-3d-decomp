/* Superseded reference probe: behavior is represented by tested portable C,
 * while lua_allocation_cpp.cpp reproduces the original instruction bytes.
 * This C reference probe is not admitted as an exact-byte source build. */
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
extern void *w3d_copy_memory(void *, const void *, W3dSize);
extern void w3d_profile_refresh(void);
extern void w3d_profile_begin(const char *);
extern void w3d_profile_end(const char *);

static inline const W3dSize *smaller_size(const W3dSize *first,
                                        const W3dSize *second)
{
    return *first <= *second ? first : second;
}

void *w3d_lua_reallocate(void *block, W3dSize old_size, W3dSize new_size)
{
    void *result = 0;
    if (block == 0) {
        result = w3d_heap_allocate(&w3d_lua_heap, new_size);
    } else if (new_size == 0) {
        w3d_heap_release(&w3d_lua_heap, block);
    } else {
        result = w3d_heap_resize(&w3d_lua_heap, block, new_size);
        if (result == 0) {
            result = w3d_heap_allocate(&w3d_lua_heap, new_size);
            if (result != 0) {
                const W3dSize *copy_size = smaller_size(&new_size, &old_size);
                w3d_copy_memory(result, block, *copy_size);
                w3d_heap_release(&w3d_lua_heap, block);
            }
        }
    }
    return result;
}


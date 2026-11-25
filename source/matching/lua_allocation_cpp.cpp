/* Natural reference-return minimum for comparison with the original compiler.
 * The portable C implementation is in source/portable/lua_memory.c.
 * Its complete 200-byte linked body matches original entry 0x8019e260.
 */
typedef unsigned long W3dSize;
struct W3dHeap { void *core; };
extern "C" {
extern W3dHeap w3d_lua_heap;
void *w3d_heap_allocate(W3dHeap *, W3dSize);
void *w3d_heap_resize(W3dHeap *, void *, W3dSize);
void w3d_heap_release(W3dHeap *, void *);
void *w3d_copy_memory(void *, const void *, W3dSize);
}

template<class T> inline const T &smaller_size(const T &first, const T &second)
{
    return second < first ? second : first;
}

extern "C" void *w3d_lua_reallocate(void *block, W3dSize old_size,
                                    W3dSize new_size)
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
                w3d_copy_memory(result, block, smaller_size(new_size, old_size));
                w3d_heap_release(&w3d_lua_heap, block);
            }
        }
    }
    return result;
}

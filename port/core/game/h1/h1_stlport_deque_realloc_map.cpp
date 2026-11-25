#include "w3d_ptr.h"
#line 1 "h1_stlport_deque_realloc_map.cpp"
/* STLport deque::_M_reallocate_map for deques of pointers (session
 * b169b320): recentres the node map when it is large enough, otherwise
 * grows it to size + max(size, nodes_to_add) + 2, then resets start and
 * finish. Node pointers move with the trivial copy/copy_backward
 * (memmove). Two translation units instantiate it. */

extern "C" Ptr32<void> w3d_handle_storage_allocate(unsigned int size);
extern "C" Ptr32<void> w3d_handle_storage_fallback(unsigned int size);
static inline Ptr32<void> w3d_malloc_alloc(unsigned int n)
{
    Ptr32<void> result = w3d_handle_storage_allocate(n);
    if (0 == result)
        result = w3d_handle_storage_fallback(n);
    return result;
}
template <class T> inline const T &w3d_max(const T &a, const T &b) { return a < b ? b : a; }
typedef Ptr32<void> W3dElem;
struct W3dDequeIter
{
    Ptr32<W3dElem> cur;
    Ptr32<W3dElem> first;
    Ptr32<W3dElem> last;
    Ptr32<Ptr32<W3dElem>> node;
    static unsigned int buffer_size() { return 32; }
    void set_node(Ptr32<Ptr32<W3dElem>> new_node)
    {
        node = new_node;
        first = *new_node;
        last = first + buffer_size();
    }
};
extern "C" void w3d_handle_storage_release(Ptr32<void> p);
extern "C" Ptr32<void> memmove(Ptr32<void>, Ptr32<const void>, unsigned int);
struct W3dMapProxy
{
    unsigned char allocator;
    Ptr32<Ptr32<W3dElem>> data;
    Ptr32<Ptr32<W3dElem>> allocate(unsigned int n) { return n != 0 ? w3d::R((Ptr32<Ptr32<W3dElem>>)w3d_malloc_alloc(n * sizeof(Ptr32<W3dElem>))) : 0; }
    void deallocate(Ptr32<Ptr32<W3dElem>> p, unsigned int) { if (p) w3d_handle_storage_release(p); }
};
static inline Ptr32<void> w3d_copy_trivial(Ptr32<const void> first, Ptr32<const void> last, Ptr32<void> result)
{
    return (last == first) ? w3d::R(result)
        : w3d::R((Ptr32<char>)memmove(result, first, (Ptr32<const char>)last - (Ptr32<const char>)first) + ((Ptr32<const char>)last - (Ptr32<const char>)first));
}
static inline Ptr32<void> w3d_copy_trivial_backward(Ptr32<const void> first, Ptr32<const void> last, Ptr32<void> result)
{
    const int num = (Ptr32<const char>)last - (Ptr32<const char>)first;
    return (num > 0) ? w3d::R(memmove((Ptr32<char>)result - num, first, num)) : w3d::R(result);
}
template <class T> inline Ptr32<Ptr32<T>> w3d_copy(Ptr32<Ptr32<T>> first, Ptr32<Ptr32<T>> last, Ptr32<Ptr32<T>> result) { return (Ptr32<Ptr32<T>>)w3d_copy_trivial(first, last, result); }
template <class T> inline Ptr32<Ptr32<T>> w3d_copy_backward(Ptr32<Ptr32<T>> first, Ptr32<Ptr32<T>> last, Ptr32<Ptr32<T>> result) { return (Ptr32<Ptr32<T>>)w3d_copy_trivial_backward(first, last, result); }
struct W3dSizeProxy
{
    unsigned char allocator;
    unsigned int data;
};
#define W3D_DEQUE_REALLOCATE_MAP(CLASS) \
struct CLASS \
{ \
    W3dDequeIter start; \
    W3dDequeIter finish; \
    W3dMapProxy map; \
    W3dSizeProxy map_size; \
    void reallocate_map(unsigned int nodes_to_add, bool add_at_front); \
}; \
void CLASS::reallocate_map(unsigned int nodes_to_add, bool add_at_front) \
{ \
    unsigned int old_num_nodes = finish.node - start.node + 1; \
    unsigned int new_num_nodes = old_num_nodes + nodes_to_add; \
    Ptr32<Ptr32<W3dElem>> new_nstart; \
    if (map_size.data > 2 * new_num_nodes) { \
        new_nstart = map.data + (map_size.data - new_num_nodes) / 2 + (add_at_front ? nodes_to_add : 0); \
        if (new_nstart < start.node) \
            w3d_copy(start.node, finish.node + 1, new_nstart); \
        else \
            w3d_copy_backward(start.node, finish.node + 1, new_nstart + old_num_nodes); \
    } \
    else { \
        unsigned int new_map_size = map_size.data + w3d_max((unsigned int)map_size.data, nodes_to_add) + 2; \
        Ptr32<W3dElem> *new_map = map.allocate(new_map_size); \
        new_nstart = new_map + (new_map_size - new_num_nodes) / 2 + (add_at_front ? nodes_to_add : 0); \
        w3d_copy(start.node, finish.node + 1, new_nstart); \
        map.deallocate(map.data, map_size.data); \
        map.data = new_map; \
        map_size.data = new_map_size; \
    } \
    start.set_node(new_nstart); \
    finish.set_node(new_nstart + old_num_nodes - 1); \
}

W3D_DEQUE_REALLOCATE_MAP(W3dPtrDequeA)
W3D_DEQUE_REALLOCATE_MAP(W3dPtrDequeB)



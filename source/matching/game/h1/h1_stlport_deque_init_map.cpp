/* STLport _Deque_base::_M_initialize_map for deques of pointers (session
 * b169b320): 128-byte buffers of 32 elements, a map of at least 8 node
 * slots centred on the used nodes, nodes created by the matching
 * _M_create_nodes (h1_8034883c), start/finish set to the first and last
 * node. Two translation units instantiate it. */

extern "C" void *w3d_handle_storage_allocate(unsigned int size);
extern "C" void *w3d_handle_storage_fallback(unsigned int size);
static inline void *w3d_malloc_alloc(unsigned int n)
{
    void *result = w3d_handle_storage_allocate(n);
    if (0 == result)
        result = w3d_handle_storage_fallback(n);
    return result;
}
template <class T> inline const T &w3d_max(const T &a, const T &b) { return a < b ? b : a; }
typedef void *W3dElem;
struct W3dDequeIter
{
    W3dElem *cur;
    W3dElem *first;
    W3dElem *last;
    W3dElem **node;
    static unsigned int buffer_size() { return 32; }
    void set_node(W3dElem **new_node)
    {
        node = new_node;
        first = *new_node;
        last = first + buffer_size();
    }
};
struct W3dMapProxy
{
    unsigned char allocator;
    W3dElem **data;
    W3dElem **allocate(unsigned int n) { return n != 0 ? (W3dElem **)w3d_malloc_alloc(n * sizeof(W3dElem *)) : 0; }
};
struct W3dSizeProxy
{
    unsigned char allocator;
    unsigned int data;
};
#define W3D_DEQUE_INITIALIZE_MAP(CLASS, FILL) \
struct CLASS \
{ \
    W3dDequeIter start;          /* 0x00 */ \
    W3dDequeIter finish;         /* 0x10 */ \
    W3dMapProxy map;             /* 0x20 */ \
    W3dSizeProxy map_size;       /* 0x28 */ \
    static unsigned int buffer_size() { return 32; } \
    void initialize_map(unsigned int num_elements); \
}; \
extern "C" void FILL(CLASS *self, W3dElem **nstart, W3dElem **nfinish); \
void CLASS::initialize_map(unsigned int num_elements) \
{ \
    unsigned int num_nodes = num_elements / buffer_size() + 1; \
    map_size.data = w3d_max((unsigned int)8, num_nodes + 2); \
    map.data = map.allocate(map_size.data); \
    W3dElem **nstart = map.data + (map_size.data - num_nodes) / 2; \
    W3dElem **nfinish = nstart + num_nodes; \
    FILL(this, nstart, nfinish); \
    start.set_node(nstart); \
    finish.set_node(nfinish - 1); \
    start.cur = start.first; \
    finish.cur = finish.first + num_elements % buffer_size(); \
}

W3D_DEQUE_INITIALIZE_MAP(W3dPtrDequeBaseA, w3d_h1_fill_allocated_blocks_80353454)
W3D_DEQUE_INITIALIZE_MAP(W3dPtrDequeBaseB, w3d_h1_fill_allocated_blocks_8035ec0c)

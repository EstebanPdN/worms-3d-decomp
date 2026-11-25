// Pool handle allocation (Worms 3D GameCube PAL, 0x800c53a0, 304 bytes).
//
// Allocates an object and a copy of the source's size-prefixed blob from the
// small-data arena 0x804af100, pops a free id, records the object and the new
// generation, updates statistics and returns the handle, id + generation * 128.
// The STLport-shaped vector is the model of d24j_register_node_8017d828.

extern "C" void *memmove(void *, const void *, unsigned);
extern "C" void *w3d_handle_storage_allocate(unsigned);
extern "C" void *w3d_handle_storage_fallback(unsigned);
extern "C" void w3d_handle_storage_release(void *);
inline void *operator new(unsigned int, void *place) throw() { return place; }
inline void *v_copy_trivial(const void *first, const void *last, void *result) {
    if (last != first) {
        unsigned n = (const char *)last - (const char *)first;
        return (char *)memmove(result, first, n) + n;
    }
    return result;
}
template<class T> inline const T &v_max(const T &a, const T &b) { return a < b ? b : a; }
template<class T> inline T *v_fill_n(T *out, unsigned n, const T &value) {
    for (; n > 0; --n, ++out) *out = value;
    return out;
}
struct VTrue {};
template<class T> struct VAlloc {
    static void *allocate_bytes(unsigned n) {
        void *p = w3d_handle_storage_allocate(n);
        if (p == 0) p = w3d_handle_storage_fallback(n);
        return p;
    }
    T *allocate(unsigned n) { return n ? (T *)allocate_bytes(n * sizeof(T)) : 0; }
    void deallocate(T *p, unsigned) { if (p) w3d_handle_storage_release(p); }
};
template<class T> struct VEnd : VAlloc<T> { T *data; };
template<class T> struct Vector {
    T *start;
    T *finish;
    VEnd<T> end_of_storage;
    unsigned size() const { return finish - start; }
    void set(T *s, T *f, T *e) { start = s; finish = f; end_of_storage.data = e; }
    void insert_overflow(T *pos, const T &x, const VTrue &, unsigned fill_len, bool atend) {
        const unsigned old_size = size();
        const unsigned len = old_size + v_max(old_size, fill_len);
        T *new_start = end_of_storage.allocate(len);
        T *new_finish = (T *)v_copy_trivial(start, pos, new_start);
        new_finish = v_fill_n(new_finish, fill_len, x);
        if (!atend) new_finish = (T *)v_copy_trivial(pos, finish, new_finish);
        end_of_storage.deallocate(start, end_of_storage.data - start);
        set(new_start, new_finish, new_start + len);
    }
    T *erase(T *pos) {
        if (pos + 1 != finish) v_copy_trivial(pos + 1, finish, pos);
        --finish;
        return pos;
    }
    void push_back(const T &x) {
        if (finish != end_of_storage.data) { new (finish) T(x); ++finish; }
        else insert_overflow(finish, x, VTrue(), 1, true);
    }
};
struct Arena { int word; };
extern Arena lbl_804af100;
extern "C" void *w3d_heap_allocate(Arena *, unsigned);
struct Texture;
extern "C" Texture *w3d_empty_800f74cc(void *);
struct Blob { unsigned size; char data[1]; };
extern "C" Blob *w3d_auto_803446e0(void *);
extern "C" void *fn_802eee50(void *, const void *, unsigned);
extern "C" void w3d_set_800f7510(Texture *, void *);
extern "C" int w3d_set_800f7500(Texture *, unsigned);
extern "C" void w3d_set_800f7520(Texture *, Blob *);
extern "C" void w3d_d24h_order_insert_800c54d0(int, unsigned);
extern Vector<int> lbl_8043e438;
extern Vector<int> lbl_8043e448;
struct PoolStats { unsigned freed, added, unknown08, peak; };
extern PoolStats lbl_803f5718[];
extern int lbl_804a87d8[];
extern Texture *lbl_804a85d8[];
extern "C" int w3d_d24h_pool_add_800c53a0(void *source, unsigned order) {
    Texture *texture = w3d_empty_800f74cc(w3d_heap_allocate(&lbl_804af100, 16));
    Blob *copy = (Blob *)w3d_heap_allocate(&lbl_804af100, w3d_auto_803446e0(source)->size);
    Blob *blob = w3d_auto_803446e0(source);
    fn_802eee50(copy, blob, blob->size);
    w3d_set_800f7510(texture, copy->data);
    w3d_set_800f7500(texture, order);
    w3d_set_800f7520(texture, copy);
    int *top = lbl_8043e438.finish - 1;
    int id = *top;
    lbl_8043e438.finish = top;
    w3d_d24h_order_insert_800c54d0(id, order);
    int generation = lbl_804a87d8[id] + 1;
    lbl_804a85d8[id] = texture;
    lbl_804a87d8[id] = generation;
    PoolStats *stats = lbl_803f5718;
    stats->added++;
    unsigned count = lbl_8043e448.size();
    int handle = id + (generation << 7);
    stats->peak = v_max(stats->peak, count);
    return handle;
}

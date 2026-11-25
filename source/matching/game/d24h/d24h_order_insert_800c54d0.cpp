// Sorted id insert (Worms 3D GameCube PAL, 0x800c54d0, 488 bytes).
//
// Scans the global id vector for the first entry ordered after the given
// value, then runs the STLport-shaped vector<int>::insert with the true-type
// overflow path (model: d24j_register_node_8017d828). Names are inferred.

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
inline void *v_copy_backward(const void *first, const void *last, void *result) {
    int n = (const char *)last - (const char *)first;
    if (n > 0) memmove((char *)result - n, first, n);
    return (char *)result - n;
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
    void insert_overflow(T *pos, const T &x, const VTrue &, unsigned fill_len) {
        const unsigned old_size = size();
        const unsigned len = old_size + v_max(old_size, fill_len);
        T *new_start = end_of_storage.allocate(len);
        T *new_finish = (T *)v_copy_trivial(pos, finish, v_fill_n((T *)v_copy_trivial(start, pos, new_start), fill_len, x));
        end_of_storage.deallocate(start, end_of_storage.data - start);
        set(new_start, new_finish, new_start + len);
    }
    void insert(T *pos, const T &x) {
        if (finish != end_of_storage.data) {
            if (pos == finish) { new (finish) T(x); ++finish; }
            else {
                new (finish) T(*(finish - 1));
                ++finish;
                T copy = x;
                v_copy_backward(pos, finish - 2, finish - 1);
                *pos = copy;
            }
        } else insert_overflow(pos, x, VTrue(), 1);
    }
};
extern "C" unsigned w3d_get_800f7508(void *);
extern Vector<int> lbl_8043e448;
extern void *lbl_804a85d8[];
extern "C" void w3d_d24h_order_insert_800c54d0(int id, unsigned order) {
    int *it = lbl_8043e448.start;
    for (; it != lbl_8043e448.finish; it++) {
        if (order < w3d_get_800f7508(lbl_804a85d8[*it])) break;
    }
    lbl_8043e448.insert(it, id);
}

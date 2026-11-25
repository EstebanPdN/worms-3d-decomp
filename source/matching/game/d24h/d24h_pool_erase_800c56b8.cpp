// Pool handle release (Worms 3D GameCube PAL, 0x800c56b8, 496 bytes).
//
// A handle is an id plus its generation times 128. On a match the id moves
// from the active vector to the free vector through STLport-shaped push_back
// and erase (model: d24j_register_node_8017d828). Names are inferred;
// 0x80004005 is the original's failure code.

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
extern "C" void w3d_pool_free_800c58a8(int);
extern Vector<int> lbl_8043e438;
extern Vector<int> lbl_8043e448;
extern int lbl_803f5718[];
extern int lbl_804a87d8[];
extern "C" int w3d_d24h_pool_erase_800c56b8(int handle) {
    for (int *it = lbl_8043e448.start; it != lbl_8043e448.finish; it++) {
        int id = *it;
        if (id + (lbl_804a87d8[id] << 7) == handle) {
            w3d_pool_free_800c58a8(id);
            lbl_8043e438.push_back(id);
            lbl_8043e448.erase(it);
            lbl_803f5718[0]++;
            return 0;
        }
    }
    return 0x80004005;
}

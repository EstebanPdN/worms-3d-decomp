// Pool expiry (Worms 3D GameCube PAL, 0x800c5164, 568 bytes).
//
// Removes expired pool objects and restarts the scan after each removal.
// The STLport-shaped vector follows d24j_register_node_8017d828. Names are
// inferred.

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
struct Texture;
struct Arena { int word; };
extern Arena lbl_804af100;
extern "C" unsigned w3d_get_800f7508(Texture *);
extern "C" void *w3d_get_800f7518(Texture *);
extern "C" void *w3d_get_800f7528(Texture *);
extern "C" void w3d_auto_800f74d0(Texture *, int);
extern "C" int fn_8016239c(void *);
extern "C" void w3d_heap_release(Arena *, void *);
extern Vector<int> lbl_8043e438;
extern Vector<int> lbl_8043e448;
struct PoolStats { unsigned freed, added, expired, peak; };
extern PoolStats lbl_803f5718[];
extern Texture *lbl_804a85d8[];
extern "C" int w3d_d24h_pool_expire_800c5164(void *self, unsigned now) {
    for (int *it = lbl_8043e448.start; it != lbl_8043e448.finish; ) {
        int id = *it;
        Texture *texture = lbl_804a85d8[id];
        if (now > w3d_get_800f7508(texture)) {
            void *message = w3d_get_800f7518(texture);
            void *blob = w3d_get_800f7528(texture);
            if (texture) w3d_auto_800f74d0(texture, 3);
            lbl_804a85d8[id] = 0;
            lbl_8043e438.push_back(id);
            lbl_8043e448.erase(it);
            fn_8016239c(message);
            lbl_803f5718[0].expired++;
            w3d_heap_release(&lbl_804af100, blob);
            it = lbl_8043e448.start;
        } else it++;
    }
    return 10;
}

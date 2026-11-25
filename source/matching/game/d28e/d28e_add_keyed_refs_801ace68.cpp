// (Worms 3D GameCube PAL, 0x801ace68).
//
// Append an empty reference array with the given key to the vector of
// 16-byte elements at +116: a temporary element is pushed (inlined STLport
// push_back with copy and destroy), destroyed, and the key is stored in the
// new last element.

extern "C" void *alloc_80212fd4(unsigned);
extern "C" void *w3d_handle_storage_fallback_803413d8(unsigned);
extern "C" void free_802134fc(void *);
inline void *operator new(unsigned int, void *place) throw() { return place; }
template<class T> inline const T &v_max(const T &a, const T &b) { return a < b ? b : a; }
struct VFalse {};
template<class T> inline void v_destroy(T *first, T *last) { for (; first != last; ++first) first->~T(); }
template<class T> inline T *v_ucopy(T *first, T *last, T *out) {
    for (; first != last; ++first, ++out) new (out) T(*first);
    return out;
}
template<class T> inline T *v_ufill(T *out, unsigned n, const T &x) {
    for (; n > 0; --n, ++out) new (out) T(x);
    return out;
}
template<class T> struct Vector {
    T *start; T *finish; int alloc; T *limit;
    static void *allocate_bytes(unsigned n) {
        void *p = alloc_80212fd4(n);
        if (p == 0) p = w3d_handle_storage_fallback_803413d8(n);
        return p;
    }
    T *allocate(unsigned n) { return n ? (T *)allocate_bytes(n * sizeof(T)) : 0; }
    unsigned size() const { return finish - start; }
    T &back() { return *(finish - 1); }
    void set(T *s, T *f, T *e) { start = s; finish = f; limit = e; }
    void insert_overflow(T *pos, const T &x, const VFalse &, unsigned fill_len, bool atend) {
        const unsigned old_size = size();
        const unsigned len = old_size + v_max(old_size, fill_len);
        T *new_start = allocate(len);
        T *new_finish = new_start;
        new_finish = v_ucopy(start, pos, new_finish);
        if (fill_len == 1) { new (new_finish) T(x); ++new_finish; }
        else new_finish = v_ufill(new_finish, fill_len, x);
        if (!atend) new_finish = v_ucopy(pos, finish, new_finish);
        { T *last = finish; v_destroy(start, last); }
        if (start) free_802134fc(start);
        set(new_start, new_finish, new_start + len);
    }
    void push_back(const T &x) {
        if (finish != limit) { new (finish) T(x); ++finish; }
        else insert_overflow(finish, x, VFalse(), 1, true);
    }
};
struct Refs;
extern "C" void w3d_construct_801f2678(Refs *);
extern "C" void * w3d_copy_refs_801f2698(Refs *, const Refs *);
extern "C" void w3d_auto_801f2758(Refs *, int);
struct Refs {
    int w[3];
    Refs() { w3d_construct_801f2678(this); }
    Refs(const Refs &o) { w3d_copy_refs_801f2698(this, &o); }
    ~Refs() { w3d_auto_801f2758(this, 2); }
};
struct Elem { Refs refs; int key; Elem() { } };
struct Self { char u[116]; Vector<Elem> elems; };
extern "C" void w3d_d28e_add_keyed_refs_801ace68(Self *self, int key)
{
    self->elems.push_back(Elem());
    self->elems.back().key = key;
}

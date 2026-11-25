// (Worms 3D GameCube PAL, 0x801b3e88).
//
// Under the owner's lock (table slot at +48) return the first item in the
// vector at +88 that the owner reports as the same, otherwise append the new
// item, retain it and return it. Unlocks by passing zero on both paths.

extern "C" void *alloc_80212fd4(unsigned);
extern "C" void free_802134fc(void *);
extern "C" void *memmove_802eeef4(void *, const void *, unsigned);
extern "C" void *w3d_handle_storage_fallback_803413d8(unsigned);
inline void *v_copy_trivial(const void *first, const void *last, void *result) {
    if (last != first) {
        unsigned n = (const char *)last - (const char *)first;
        return (char *)memmove_802eeef4(result, first, n) + n;
    }
    return result;
}
template<class T> inline const T &s_max(const T &a, const T &b) { return a < b ? b : a; }
template<class T> inline T *v_fill_n(T *out, unsigned n, const T &value) {
    for (; n > 0; --n, ++out) *out = value;
    return out;
}
struct VTrue {};
template<class T> struct SVec {
    T *start; T *finish; int alloc; T *limit;
    void set(T *s, T *f, T *e) { start = s; finish = f; limit = e; }
    static void *allocate_bytes(unsigned n) {
        void *p = alloc_80212fd4(n);
        if (p == 0) p = w3d_handle_storage_fallback_803413d8(n);
        return p;
    }
    void insert_overflow(T *pos, const T &x, const VTrue &, unsigned fill_len, bool atend) {
        const unsigned old_size = finish - start;
        const unsigned len = old_size + s_max(old_size, fill_len);
        T *new_start = len ? (T *)allocate_bytes(len * sizeof(T)) : 0;
        T *new_finish = (T *)v_copy_trivial(start, pos, new_start);
        new_finish = v_fill_n(new_finish, fill_len, x);
        if (start) free_802134fc(start);
        set(new_start, new_finish, new_start + len);
    }
    void push_back(const T &x) {
        if (finish != limit) { if (finish) *finish = x; ++finish; }
        else insert_overflow(finish, x, VTrue(), 1, true);
    }
};
struct Item { virtual void v0(); virtual void retain(); };
struct Owner {
    virtual void v8(); virtual void v12(); virtual void v16(); virtual void v20();
    virtual int same(Item *); virtual void v28(); virtual void v32(); virtual void v36(); virtual void v40(); virtual void v44();
    virtual void lock(Item *);
};
struct Self { char u[24]; Owner *owner; char u28[60]; SVec<Item *> items; };
extern "C" Item *w3d_d28e_add_unique_item_801b3e88(Self *self, Item *x)
{
    self->owner->lock(x);
    Item **last = self->items.finish;
    for (Item **it = self->items.start; it != last; ++it) {
        if (self->owner->same(*it) == 0) {
            self->owner->lock(0);
            return *it;
        }
    }
    self->items.push_back(x);
    x->retain();
    self->owner->lock(0);
    return x;
}

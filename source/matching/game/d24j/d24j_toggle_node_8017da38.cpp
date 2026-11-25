// Add or remove a node (Worms 3D GameCube PAL, 0x8017da38).
//
// With flag 0x40000000 appends the node to the vector at +9788. Otherwise
// removes it from the vector at +9756 or +9772 by moving the last element into
// its place. An unknown node makes a copy of its name string (0x80341884
// raises the shared count), destroys it, and returns 0x80004005.

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
    T *begin() { return start; }
    T *end() { return finish; }
    T &back() { return *(end() - 1); }
    void pop_back() { --finish; }
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
    void push_back(const T &x) {
        if (finish != end_of_storage.data) { new (finish) T(x); ++finish; }
        else insert_overflow(finish, x, VTrue(), 1, true);
    }
};
extern "C" void w3d_string_base_init(void *);
extern "C" void w3d_string_base_finish(void *);
extern "C" void w3d_string_release(void *);
extern "C" unsigned short *w3d_string_header(void *);
struct String {
    char *data;
    String(const String &x) { w3d_string_base_init(this); data = x.data; ++*w3d_string_header(this); }
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Named { void **vtable; const String &name() { return *((const String *(*)(Named *))vtable[17])(this); } };
struct Node { void **vtable; Named *named() { return ((Named *(*)(Node *))vtable[16])(this); } };
struct Owner { char u[20]; unsigned flags; char u2[9732]; Vector<Node *> b; Vector<Node *> a; Vector<Node *> c; };
extern "C" int d24j_toggle_node_8017da38(Owner *self, Node *x)
{
    if (self->flags & 0x40000000) { self->c.push_back(x); return 0; }
    for (Node **it = self->b.begin(); it != self->b.end(); ++it)
        if (*it == x) { *it = self->b.back(); self->b.pop_back(); return 0; }
    for (Node **it = self->a.begin(); it != self->a.end(); ++it)
        if (*it == x) { *it = self->a.back(); self->a.pop_back(); return 0; }

    String s(x->named()->name());
    return 0x80004005;
}

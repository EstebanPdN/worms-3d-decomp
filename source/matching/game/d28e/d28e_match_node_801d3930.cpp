// (Worms 3D GameCube PAL, 0x801d3930).
//
// Match a parsed node against the expected name. In sequence mode it
// compares with the name at the current index of the list at +48 and returns
// 1 until the last name; otherwise with the single name at +40. A full match
// records the node at +44, pushes it on the stack at +72 and returns
// 0x90000005. Otherwise 0. Reached through the secondary base at +4.

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
extern "C" int strcmp_802ef234(const char *, const char *);
struct Node { char u[36]; const char *name; };
struct NameList { const char **start; const char **finish; unsigned size() const { return finish - start; } const char *&operator[](unsigned i) { return start[i]; } };
struct Self { char u40[40]; const char *name; Node *last; NameList names; char u56[8]; int sequence; unsigned index; SVec<Node *> done; };
extern "C" int w3d_d28e_match_node_801d3930(char *sec, Node *x)
{
    Self *self = sec ? (Self *)(sec - 4) : 0;
    Node *y = x;
    if (self->sequence) {
        if (strcmp_802ef234(x->name, self->names[self->index]) == 0) {
            if (self->index == self->names.size() - 1) {
                self->last = y;
                self->done.push_back(y);
                return 0x90000005;
            }
            return 1;
        }
    } else if (strcmp_802ef234(x->name, self->name) == 0) {
        self->last = y;
        self->done.push_back(y);
        return 0x90000005;
    }
    return 0;
}

// (Worms 3D GameCube PAL, 0x801d3dd4).
//
// Start a node with a child: runs the match at 0x801d3930, then in sequence
// mode a partial match advances the index, pushes the node and dispatches
// the child through the handler table of the sub-object at +4, undoing both;
// outside sequence mode it dispatches the child and returns its error.
// Always ends through 0x801d3be0.

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
    void pop_back() { --finish; }

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
struct Node { char u[6]; unsigned short slot; char u8[28]; const char *name; char u40[8]; Node *child; };
struct NameList { const char **start; const char **finish; unsigned size() const { return finish - start; } const char *&operator[](unsigned i) { return start[i]; } };
struct Handlers;
struct Sub { char u[24]; int (**handlers)(Sub *, Node *); };
struct Self { char u4[4]; Sub sub; char u32[8]; const char *name; Node *last; NameList names; char u56[8]; int sequence; unsigned index; SVec<Node *> done; };
extern "C" int fn_801d3930(char *, Node *);
extern "C" int fn_801d3be0(char *, Node *);
extern "C" int w3d_d28e_open_node_801d3dd4(char *sec, Node *x)
{
    Self *self = sec ? (Self *)(sec - 4) : 0;
    Node *child = x->child;
    if (child) {
        int r = fn_801d3930(sec, x);
        if (r < 0) return r;
        if (self->sequence) {
            if (r == 1) {
                ++self->index;
                Node *y = x;
                self->done.push_back(y);
                Sub *sub = &self->sub;
                sub->handlers[child->slot](sub, child);
                self->done.pop_back();
                --self->index;
            }
        } else {
            Sub *sub = &self->sub;
            int s = sub->handlers[child->slot](sub, child);
            if (s < 0) return s;
        }
    }
    return fn_801d3be0(sec, x);
}

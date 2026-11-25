#include "w3d_ptr.h"
#line 1 "d28e_open_node_801d3dd4.cpp"
// (Worms 3D GameCube PAL, 0x801d3dd4).
//
// Start a node with a child: runs the match at 0x801d3930, then in sequence
// mode a partial match advances the index, pushes the node and dispatches
// the child through the handler table of the sub-object at +4, undoing both;
// outside sequence mode it dispatches the child and returns its error.
// Always ends through 0x801d3be0.

extern "C" Ptr32<void> alloc_80212fd4(unsigned);
extern "C" void free_802134fc(Ptr32<void>);
extern "C" Ptr32<void> memmove_802eeef4(Ptr32<void>, Ptr32<const void>, unsigned);
extern "C" Ptr32<void> w3d_handle_storage_fallback_803413d8(unsigned);
inline Ptr32<void> v_copy_trivial(Ptr32<const void> first, Ptr32<const void> last, Ptr32<void> result) {
    if (last != first) {
        unsigned n = (Ptr32<const char>)last - (Ptr32<const char>)first;
        return (Ptr32<char>)memmove_802eeef4(result, first, n) + n;
    }
    return result;
}
template<class T> inline const T &s_max(const T &a, const T &b) { return a < b ? b : a; }
template<class T> inline Ptr32<T> v_fill_n(T *out, unsigned n, const T &value) {
    for (; n > 0; --n, ++out) *out = value;
    return out;
}
struct VTrue { char w3d_empty; };
template<class T> struct SVec {
    void pop_back() { --finish; }

    Ptr32<T> start; Ptr32<T> finish; int alloc; Ptr32<T> limit;
    void set(Ptr32<T> s, Ptr32<T> f, Ptr32<T> e) { start = s; finish = f; limit = e; }
    static Ptr32<void> allocate_bytes(unsigned n) {
        Ptr32<void> p = alloc_80212fd4(n);
        if (p == 0) p = w3d_handle_storage_fallback_803413d8(n);
        return p;
    }
    void insert_overflow(Ptr32<T> pos, const T &x, const VTrue &, unsigned fill_len, bool atend) {
        const unsigned old_size = finish - start;
        const unsigned len = old_size + s_max(old_size, fill_len);
        Ptr32<T> new_start = len ? (Ptr32<T>)allocate_bytes(len * sizeof(T)) : 0;
        Ptr32<T> new_finish = (Ptr32<T>)v_copy_trivial(start, pos, new_start);
        new_finish = v_fill_n(w3d::R(new_finish), fill_len, x);
        if (start) free_802134fc(start);
        set(new_start, new_finish, new_start + len);
    }
    void push_back(const T &x) {
        if (finish != limit) { if (finish) *finish = x; ++finish; }
        else insert_overflow(finish, x, VTrue(), 1, true);
    }
};
extern "C" int strcmp_802ef234(Ptr32<const char>, Ptr32<const char>);
struct Node { char u[6]; unsigned short slot; char u8[28]; Ptr32<const char> name; char u40[8]; Ptr32<Node> child; };
struct NameList { Ptr32<Ptr32<const char>> start; Ptr32<Ptr32<const char>> finish; unsigned size() const { return finish - start; } Ptr32<const char> & operator[](unsigned i) { return start[i]; } };
struct Handlers;
struct Sub { char u[24]; Ptr32<Ptr32<int (Ptr32<Sub>, Ptr32<Node>)>> handlers; };
struct Self { char u4[4]; Sub sub; char u32[8]; Ptr32<const char> name; Ptr32<Node> last; NameList names; char u56[8]; int sequence; unsigned index; SVec <Ptr32<Node> > done; };
extern "C" int fn_801d3930(Ptr32<char>, Ptr32<Node>);
extern "C" int fn_801d3be0(Ptr32<char>, Ptr32<Node>);
extern "C" int w3d_d28e_open_node_801d3dd4(Ptr32<char> sec, Ptr32<Node> x)
{
    Ptr32<Self> self = sec ? w3d::R((Ptr32<Self>)(sec - 4)) : 0;
    Ptr32<Node> child = x->child;
    if (child) {
        int r = fn_801d3930(sec, x);
        if (r < 0) return r;
        if (self->sequence) {
            if (r == 1) {
                ++self->index;
                Ptr32<Node> y = x;
                self->done.push_back(y);
                Ptr32<Sub> sub = &self->sub;
                sub->handlers[child->slot](sub, child);
                self->done.pop_back();
                --self->index;
            }
        } else {
            Ptr32<Sub> sub = &self->sub;
            int s = sub->handlers[child->slot](sub, child);
            if (s < 0) return s;
        }
    }
    return fn_801d3be0(sec, x);
}



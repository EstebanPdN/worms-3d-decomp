#include "w3d_ptr.h"
#line 1 "d28e_match_node_801d3930.cpp"
// (Worms 3D GameCube PAL, 0x801d3930).
//
// Match a parsed node against the expected name. In sequence mode it
// compares with the name at the current index of the list at +48 and returns
// 1 until the last name; otherwise with the single name at +40. A full match
// records the node at +44, pushes it on the stack at +72 and returns
// 0x90000005. Otherwise 0. Reached through the secondary base at +4.

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
struct Node { char u[36]; Ptr32<const char> name; };
struct NameList { Ptr32<Ptr32<const char>> start; Ptr32<Ptr32<const char>> finish; unsigned size() const { return finish - start; } Ptr32<const char> & operator[](unsigned i) { return start[i]; } };
struct Self { char u40[40]; Ptr32<const char> name; Ptr32<Node> last; NameList names; char u56[8]; int sequence; unsigned index; SVec <Ptr32<Node> > done; };
extern "C" int w3d_d28e_match_node_801d3930(Ptr32<char> sec, Ptr32<Node> x)
{
    Ptr32<Self> self = sec ? w3d::R((Ptr32<Self>)(sec - 4)) : 0;
    Ptr32<Node> y = x;
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



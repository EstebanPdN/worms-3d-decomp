#include "w3d_ptr.h"
#line 1 "d28e_reset_stacks_801a74a8.cpp"
// (Worms 3D GameCube PAL, 0x801a74a8).
//
// Empty the two pointer deques at +48 and +96 (pop_back with the helper
// 0x8035366c at a node boundary), then push the given value on the second
// and the current value at +40 on the first (helper 0x80353880). Returns 0.

inline void *operator new(__SIZE_TYPE__, void *place) throw() { return place; }
template<class T> struct Deque;
extern "C" void w3d_auto_8035366c(Ptr32<Deque <Ptr32<void> >>);
extern "C" void w3d_auto_80353880(Ptr32<Deque <Ptr32<void> >>, Ptr32<Ptr32<void> const>);
template<class T> struct Deque {
    Ptr32<T> s_cur; Ptr32<T> s_first; Ptr32<T> s_last; Ptr32<Ptr32<T>> s_node;
    Ptr32<T> f_cur; Ptr32<T> f_first; Ptr32<T> f_last; Ptr32<Ptr32<T>> f_node;
    bool empty() const { return f_cur == s_cur; }
    void pop_back() {
        if (f_cur != f_first) --f_cur;
        else w3d_auto_8035366c(this);
    }
    void push_back(const T &x) {
        if (f_cur != f_last - 1) { new (f_cur) T(x); ++f_cur; }
        else w3d_auto_80353880(this, &x);
    }
};
struct Self { char u[40]; Ptr32<void> current; char u44[4]; Deque <Ptr32<void> > a; char u80[16]; Deque <Ptr32<void> > b; };
extern "C" int w3d_d28e_reset_stacks_801a74a8(Ptr32<Self> self, Ptr32<void> x)
{
    while (self->a.f_cur != self->a.s_cur) self->a.pop_back();
    while (self->b.f_cur != self->b.s_cur) self->b.pop_back();
    self->b.push_back(x);
    Ptr32<void> c = self->current;
    self->a.push_back(c);
    return 0;
}



// (Worms 3D GameCube PAL, 0x801a74a8).
//
// Empty the two pointer deques at +48 and +96 (pop_back with the helper
// 0x8035366c at a node boundary), then push the given value on the second
// and the current value at +40 on the first (helper 0x80353880). Returns 0.

inline void *operator new(unsigned int, void *place) throw() { return place; }
template<class T> struct Deque;
extern "C" void w3d_auto_8035366c(Deque<void *> *);
extern "C" void w3d_auto_80353880(Deque<void *> *, void *const *);
template<class T> struct Deque {
    T *s_cur, *s_first, *s_last; T **s_node;
    T *f_cur, *f_first, *f_last; T **f_node;
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
struct Self { char u[40]; void *current; char u44[4]; Deque<void *> a; char u80[16]; Deque<void *> b; };
extern "C" int w3d_d28e_reset_stacks_801a74a8(Self *self, void *x)
{
    while (self->a.f_cur != self->a.s_cur) self->a.pop_back();
    while (self->b.f_cur != self->b.s_cur) self->b.pop_back();
    self->b.push_back(x);
    void *c = self->current;
    self->a.push_back(c);
    return 0;
}

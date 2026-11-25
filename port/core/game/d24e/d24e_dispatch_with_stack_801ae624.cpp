#include "w3d_ptr.h"
#line 1 "d24e_dispatch_with_stack_801ae624.cpp"
// Pushes a node on the owner's stack at +48, dispatches through 0x801a3944, then pops it (Worms 3D GameCube PAL, 0x801ae624).
//
// STLport-shaped vector push_back with the inlined true-type overflow path
// (template from d24j_register_node_8017d828).

extern "C" Ptr32<void> memmove(Ptr32<void>, Ptr32<const void>, unsigned);
extern "C" Ptr32<void> w3d_handle_storage_allocate(unsigned);
extern "C" Ptr32<void> w3d_handle_storage_fallback(unsigned);
extern "C" void w3d_handle_storage_release(Ptr32<void>);
inline void *operator new(__SIZE_TYPE__, void *place) throw() { return place; }
inline Ptr32<void> v_copy_trivial(Ptr32<const void> first, Ptr32<const void> last, Ptr32<void> result) {
    if (last != first) {
        unsigned n = (Ptr32<const char>)last - (Ptr32<const char>)first;
        return (Ptr32<char>)memmove(result, first, n) + n;
    }
    return result;
}
template<class T> inline const T &v_max(const T &a, const T &b) { return a < b ? b : a; }
template<class T> inline Ptr32<T> v_fill_n(T *out, unsigned n, const T &value) {
    for (; n > 0; --n, ++out) *out = value;
    return out;
}
struct VTrue { char w3d_empty; };
template<class T> struct VAlloc {
    static Ptr32<void> allocate_bytes(unsigned n) {
        Ptr32<void> p = w3d_handle_storage_allocate(n);
        if (p == 0) p = w3d_handle_storage_fallback(n);
        return p;
    }
    Ptr32<T> allocate(unsigned n) { return n ? (Ptr32<T>)allocate_bytes(n * sizeof(T)) : 0; }
    void deallocate(Ptr32<T> p, unsigned) { if (p) w3d_handle_storage_release(p); }
 char w3d_empty; };
template<class T> struct VEnd : VAlloc<T> { Ptr32<T> data __attribute__((aligned(__alignof__(VAlloc<T>)))); };
template<class T> struct Vector {
    Ptr32<T> start;
    Ptr32<T> finish;
    VEnd<T> end_of_storage;
    unsigned size() const { return finish - start; }
    void set(Ptr32<T> s, Ptr32<T> f, Ptr32<T> e) { start = s; finish = f; end_of_storage.data = e; }
    void insert_overflow(Ptr32<T> pos, const T &x, const VTrue &, unsigned fill_len, bool atend) {
        const unsigned old_size = size();
        const unsigned len = old_size + v_max(old_size, fill_len);
        Ptr32<T> new_start = end_of_storage.allocate(len);
        Ptr32<T> new_finish = (Ptr32<T>)v_copy_trivial(start, pos, new_start);
        new_finish = v_fill_n(w3d::R(new_finish), fill_len, x);
        if (!atend) new_finish = (Ptr32<T>)v_copy_trivial(pos, finish, new_finish);
        end_of_storage.deallocate(start, end_of_storage.data - start);
        set(new_start, new_finish, new_start + len);
    }
    void pop_back() { --finish; }
    void push_back(const T &x) {
        if (finish != end_of_storage.data) { new (finish) T(x); ++finish; }
        else insert_overflow(finish, x, VTrue(), 1, true);
    }
};
struct Node;
struct Owner { char u[48]; Vector <Ptr32<const Node> > v; };
extern "C" int fn_801a3944(Ptr32<char>, Ptr32<Node>);
extern "C" void w3d_d24e_dispatch_with_stack_801ae624(Ptr32<char> self, Ptr32<Node> x) {
    Ptr32<Owner> o = self ? w3d::R((Ptr32<Owner>)(self - 4)) : 0;
    o->v.push_back(x);
    fn_801a3944(self, x);
    o->v.pop_back();
}



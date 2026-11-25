#include "w3d_ptr.h"
#line 1 "d24j_update_nodes_8017e49c.cpp"
// Update the registered nodes (Worms 3D GameCube PAL, 0x8017e49c).
//
// With flag 0x20000000 updates each node of the vector at +9772 (virtual slot
// 11) and returns the last negative status or 0. Otherwise moves every node
// of that vector to the vector at +9756, updates that vector and returns 0.
// Built with -mps-float (one saved FPR in a non-leaf function).

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
    Ptr32<T> begin() { return start; }
    Ptr32<T> end() { return finish; }
    Ptr32<T> erase(Ptr32<T> pos) { if (pos + 1 != end()) v_copy_trivial(pos + 1, finish, pos); --finish; return pos; }
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
    void push_back(const T &x) {
        if (finish != end_of_storage.data) { new (finish) T(x); ++finish; }
        else insert_overflow(finish, x, VTrue(), 1, true);
    }
};
struct Item { Ptr32<Ptr32<void>> vtable; int update(float dt) { return ((Ptr32<int (Ptr32<Item>, float)>)vtable[11])(this, dt); } };

struct Owner { char u[20]; unsigned flags; char u2[9732]; Vector <Ptr32<Item> > b; Vector <Ptr32<Item> > a; };
extern "C" int d24j_update_nodes_8017e49c(Ptr32<Owner> self, float dt)
{
    if (self->flags & 0x20000000) {
        int status = 0;
        for (Ptr32<Ptr32<Item>> it = self->a.begin(); it != self->a.end(); ++it) {
            int r = (*it)->update(dt);
            if (r < 0) status = r;
        }
        return status;
    }
    for (Ptr32<Ptr32<Item>> it = self->a.begin(); it != self->a.end(); ) {
        self->b.push_back(*it);
        it = self->a.erase(it);
    }
    for (Ptr32<Ptr32<Item>> it = self->b.begin(); it != self->b.end(); ++it)
        (*it)->update(dt);
    return 0;
}



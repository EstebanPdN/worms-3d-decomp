#include "w3d_ptr.h"
#line 1 "d24h_order_insert_800c54d0.cpp"
// Sorted id insert (Worms 3D GameCube PAL, 0x800c54d0, 488 bytes).
//
// Scans the global id vector for the first entry ordered after the given
// value, then runs the STLport-shaped vector<int>::insert with the true-type
// overflow path (model: d24j_register_node_8017d828). Names are inferred.

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
inline Ptr32<void> v_copy_backward(Ptr32<const void> first, Ptr32<const void> last, Ptr32<void> result) {
    int n = (Ptr32<const char>)last - (Ptr32<const char>)first;
    if (n > 0) memmove((Ptr32<char>)result - n, first, n);
    return (Ptr32<char>)result - n;
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
    void insert_overflow(Ptr32<T> pos, const T &x, const VTrue &, unsigned fill_len) {
        const unsigned old_size = size();
        const unsigned len = old_size + v_max(old_size, fill_len);
        Ptr32<T> new_start = end_of_storage.allocate(len);
        Ptr32<T> new_finish = (Ptr32<T>)v_copy_trivial(pos, finish, v_fill_n(w3d::R((Ptr32<T>)v_copy_trivial(start, pos, new_start)), fill_len, x));
        end_of_storage.deallocate(start, end_of_storage.data - start);
        set(new_start, new_finish, new_start + len);
    }
    void insert(Ptr32<T> pos, const T &x) {
        if (finish != end_of_storage.data) {
            if (pos == finish) { new (finish) T(x); ++finish; }
            else {
                new (finish) T(*(finish - 1));
                ++finish;
                T copy = x;
                v_copy_backward(pos, finish - 2, finish - 1);
                *pos = copy;
            }
        } else insert_overflow(pos, x, VTrue(), 1);
    }
};
extern "C" unsigned w3d_get_800f7508(Ptr32<void>);
extern Vector<int> lbl_8043e448;
extern Ptr32<void> lbl_804a85d8[];
extern "C" void w3d_d24h_order_insert_800c54d0(int id, unsigned order) {
    Ptr32<int> it = lbl_8043e448.start;
    for (; it != lbl_8043e448.finish; it++) {
        if (order < w3d_get_800f7508(lbl_804a85d8[*it])) break;
    }
    lbl_8043e448.insert(it, id);
}



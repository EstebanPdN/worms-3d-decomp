#include "w3d_ptr.h"
#line 1 "d24f_float_vector_fill_insert_80342bac.cpp"
// GWMP8P rev0 0x80342bac. Observed STLport-shaped vector of 4-byte trivially
// copied elements, repeated-value insert, over a heap-wrapper allocator.
// Copy helpers keep their returned result so the value numbering of the
// scaled count is lost across their guards, as in the original; the bounds
// are published through an inline setter.
extern "C" Ptr32<void> memmove(Ptr32<void>, Ptr32<const void>, unsigned);
extern "C" Ptr32<void> w3d_auto_8001528c(unsigned);
extern "C" void w3d_auto_800152ac(Ptr32<void>);
template<class T> inline Ptr32<T> d24f_copy_trivial(const T *first, const T *last, T *result) {
    if (last != first) {
        unsigned n = (Ptr32<const char>)last - (Ptr32<const char>)first;
        return (Ptr32<T>)((Ptr32<char>)memmove(result, first, n) + n);
    }
    return result;
}
template<class T> inline Ptr32<T> d24f_uninit_copy(const T *first, const T *last, T *result) { return d24f_copy_trivial(w3d::R(first), w3d::R(last), w3d::R(result)); }
template<class T> inline Ptr32<T> d24f_copy_backward_trivial(const T *first, const T *last, T *result) {
    int n = (Ptr32<const char>)last - (Ptr32<const char>)first;
    if (n > 0)
        return (Ptr32<T>)memmove((Ptr32<char>)result - n, first, n);
    return result;
}
template<class T> inline Ptr32<T> d24f_copy_backward(const T *first, const T *last, T *result) { return d24f_copy_backward_trivial(w3d::R(first), w3d::R(last), w3d::R(result)); }
template<class T> inline const T &d24f_max(const T &a, const T &b) { return a < b ? b : a; }
template<class T> inline void d24f_fill(T *first, T *last, const T &value) {
    for (; first != last; ++first) *first = value;
}
template<class T> inline Ptr32<T> d24f_fill_n(T *out, unsigned n, const T &value) {
    for (; n > 0; --n, ++out) *out = value;
    return out;
}
struct D24fAlloc { char w3d_empty; };
template<class T> struct D24fVector {
    Ptr32<T> start;
    Ptr32<T> finish;
    D24fAlloc alloc;
    Ptr32<T> storage_end;
    void insert_overflow(Ptr32<T> pos, const T &x, unsigned fill_len);
    void insert(Ptr32<T> pos, unsigned n, const T &x);
    void set(Ptr32<T> s, Ptr32<T> f, Ptr32<T> e) { start = s; finish = f; storage_end = e; }
};
template<class T> inline void D24fVector<T>::insert_overflow(Ptr32<T> pos, const T &x, unsigned fill_len) {
    const unsigned old_size = finish - start;
    const unsigned len = old_size + d24f_max(old_size, fill_len);
    Ptr32<T> new_start = (Ptr32<T>)w3d_auto_8001528c(len * sizeof(T));
    Ptr32<T> new_finish = d24f_copy_trivial(w3d::R(pos), w3d::R(finish), w3d::R(d24f_fill_n(w3d::R(d24f_copy_trivial(w3d::R(start), w3d::R(pos), w3d::R(new_start))), fill_len, x)));
    if (start) w3d_auto_800152ac(start);
    set(new_start, new_finish, new_start + len);
}
template<class T> inline void D24fVector<T>::insert(Ptr32<T> pos, unsigned n, const T &x) {
    if (n != 0) {
        if ((unsigned)(storage_end - finish) >= n) {
            T x_copy = x;
            const unsigned elems_after = finish - pos;
            Ptr32<T> old_finish = finish;
            if (elems_after > n) {
                d24f_uninit_copy(w3d::R(finish - n), w3d::R(finish), w3d::R(finish));
                finish += n;
                d24f_copy_backward(w3d::R(pos), w3d::R(old_finish - n), w3d::R(old_finish));
                d24f_fill(w3d::R(pos), w3d::R(pos + n), x_copy);
            } else {
                d24f_fill_n(w3d::R(finish), n - elems_after, x_copy);
                finish += n - elems_after;
                d24f_copy_trivial(w3d::R(pos), w3d::R(old_finish), w3d::R(finish));
                finish += elems_after;
                d24f_fill(w3d::R(pos), w3d::R(old_finish), x_copy);
            }
        } else
            insert_overflow(pos, x, n);
    }
}
extern "C" void d24f_float_vector_fill_insert_80342bac(Ptr32<D24fVector < float >> self, Ptr32<float> pos, unsigned n, const float &x) {
    self->insert(pos, n, x);
}



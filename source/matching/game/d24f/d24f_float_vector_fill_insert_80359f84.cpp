// GWMP8P rev0 0x80359f84. Observed STLport-shaped vector of 4-byte trivially
// copied elements, repeated-value insert. Copy helpers keep their returned
// result so the value numbering of the scaled count is lost across their
// guards, as in the original; the bounds are published through an inline
// setter.
extern "C" void *memmove(void *, const void *, unsigned);
extern "C" void *w3d_handle_storage_allocate(unsigned);
extern "C" void *w3d_handle_storage_fallback(unsigned);
extern "C" void w3d_handle_storage_release(void *);
template<class T> inline T *d24f_copy_trivial(const T *first, const T *last, T *result) {
    if (last != first) {
        unsigned n = (const char *)last - (const char *)first;
        return (T *)((char *)memmove(result, first, n) + n);
    }
    return result;
}
template<class T> inline T *d24f_uninit_copy(const T *first, const T *last, T *result) { return d24f_copy_trivial(first, last, result); }
template<class T> inline T *d24f_copy_backward_trivial(const T *first, const T *last, T *result) {
    int n = (const char *)last - (const char *)first;
    if (n > 0)
        return (T *)memmove((char *)result - n, first, n);
    return result;
}
template<class T> inline T *d24f_copy_backward(const T *first, const T *last, T *result) { return d24f_copy_backward_trivial(first, last, result); }
template<class T> inline const T &d24f_max(const T &a, const T &b) { return a < b ? b : a; }
template<class T> inline void d24f_fill(T *first, T *last, const T &value) {
    for (; first != last; ++first) *first = value;
}
template<class T> inline T *d24f_fill_n(T *out, unsigned n, const T &value) {
    for (; n > 0; --n, ++out) *out = value;
    return out;
}
inline void *d24f_storage(unsigned bytes) {
    void *p = w3d_handle_storage_allocate(bytes);
    if (0 == p) p = w3d_handle_storage_fallback(bytes);
    return p;
}
struct D24fAlloc {};
template<class T> struct D24fVector {
    T *start;
    T *finish;
    D24fAlloc alloc;
    T *storage_end;
    void insert_overflow(T *pos, const T &x, unsigned fill_len);
    void insert(T *pos, unsigned n, const T &x);
    void set(T *s, T *f, T *e) { start = s; finish = f; storage_end = e; }
};
template<class T> inline void D24fVector<T>::insert_overflow(T *pos, const T &x, unsigned fill_len) {
    const unsigned old_size = finish - start;
    const unsigned len = old_size + d24f_max(old_size, fill_len);
    T *new_start = len != 0 ? (T *)d24f_storage(len * sizeof(T)) : 0;
    T *new_finish = d24f_copy_trivial(pos, finish, d24f_fill_n(d24f_copy_trivial(start, pos, new_start), fill_len, x));
    if (start) w3d_handle_storage_release(start);
    set(new_start, new_finish, new_start + len);
}
template<class T> inline void D24fVector<T>::insert(T *pos, unsigned n, const T &x) {
    if (n != 0) {
        if ((unsigned)(storage_end - finish) >= n) {
            T x_copy = x;
            const unsigned elems_after = finish - pos;
            T *old_finish = finish;
            if (elems_after > n) {
                d24f_uninit_copy(finish - n, finish, finish);
                finish += n;
                d24f_copy_backward(pos, old_finish - n, old_finish);
                d24f_fill(pos, pos + n, x_copy);
            } else {
                d24f_fill_n(finish, n - elems_after, x_copy);
                finish += n - elems_after;
                d24f_copy_trivial(pos, old_finish, finish);
                finish += elems_after;
                d24f_fill(pos, old_finish, x_copy);
            }
        } else
            insert_overflow(pos, x, n);
    }
}
extern "C" void d24f_float_vector_fill_insert_80359f84(D24fVector<float> *self, float *pos, unsigned n, const float &x) {
    self->insert(pos, n, x);
}

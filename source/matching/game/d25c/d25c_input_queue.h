// STLport-form vector of the timed input records (d24f_timed_record.h), as used by the input
// service. clear() is erase(start, finish): the tail copy of a polymorphic element folds away
// because last == finish, and the compiler's assignment temporary stays in the frame.
#ifndef D25C_INPUT_QUEUE_H
#define D25C_INPUT_QUEUE_H
inline void *operator new(unsigned, void *place) throw() { return place; }
extern "C" void *w3d_handle_storage_allocate(unsigned);
extern "C" void *w3d_handle_storage_fallback(unsigned);
extern "C" void w3d_handle_storage_release(void *);
inline void *d24f_storage(unsigned bytes) {
    void *p = w3d_handle_storage_allocate(bytes);
    if (0 == p) p = w3d_handle_storage_fallback(bytes);
    return p;
}
#include "d24f_timed_record.h"
template<class T> inline void d24f_construct(T *p, const T &v) { new (p) T(v); }
template<class T> inline void d24f_destroy(T *p) { p->~T(); }
struct D24fNotPod {};
template<class T> inline void d24f_destroy_aux(T *first, T *last, const D24fNotPod &) { for (; first != last; ++first) d24f_destroy(first); }
template<class T> inline void d24f_destroy_typed(T *first, T *last, T *) { d24f_destroy_aux(first, last, D24fNotPod()); }
template<class T> inline void d24f_destroy_range(T *first, T *last) { d24f_destroy_typed(first, last, (T *)0); }
template<class T> inline T *d24f_uninit_copy(const T *first, const T *last, T *out, const D24fNotPod &) {
    for (; first != last; ++first, ++out) d24f_construct(out, *first);
    return out;
}
template<class T> inline T *d24f_uninit_fill_n(T *out, unsigned n, const T &v) {
    for (; n > 0; --n, ++out) d24f_construct(out, v);
    return out;
}
template<class T> inline T *d24f_copy_ptrs(const T *first, const T *last, T *out, const D24fNotPod &) { for (int n = last - first; n > 0; --n) { *out = *first; ++first; ++out; } return out; }
template<class T> inline const T &d24f_max(const T &a, const T &b) { return a < b ? b : a; }
template<class T> struct D24fAllocator {
    T *allocate(unsigned n) { return n != 0 ? (T *)d24f_storage(n * sizeof(T)) : 0; }
    void deallocate(T *p) { if (p) w3d_handle_storage_release(p); }
};
template<class T> struct D24fVector {
    T *start, *finish;
    D24fAllocator<T> allocator;
    T *storage_end;
    void set(T *s, T *f, T *e) { start = s; finish = f; storage_end = e; }
    void clear_storage() {
        d24f_destroy_range(start, finish);
        if (start) w3d_handle_storage_release(start);
    }
    void insert_overflow(T *pos, const T &x, const D24fNotPod &tag, unsigned fill_len) {
        const unsigned old_size = finish - start;
        const unsigned len = old_size + d24f_max(old_size, fill_len);
        T *new_start = allocator.allocate(len);
        T *new_finish = new_start;
        new_finish = d24f_uninit_copy(start, pos, new_start, tag);
        if (fill_len == 1) {
            d24f_construct(new_finish, x);
            ++new_finish;
        } else
            new_finish = d24f_uninit_fill_n(new_finish, fill_len, x);
        clear_storage();
        set(new_start, new_finish, new_start + len);
    }
    void push_back(const T &x) {
        if (finish != storage_end) {
            d24f_construct(finish, x);
            ++finish;
        } else
            insert_overflow(finish, x, D24fNotPod(), 1U);
    }
    T *erase(T *first, T *last) {
        T *kept = d24f_copy_ptrs((const T *)last, (const T *)finish, first, D24fNotPod());
        d24f_destroy_range(kept, finish);
        finish = kept;
        return first;
    }
    void clear() { erase(start, finish); }
    unsigned size() const { return finish - start; }
};
#endif

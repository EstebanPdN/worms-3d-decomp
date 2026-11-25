// STLport-form vector of the timed input records (d24f_timed_record.h), as used by the input
// service. clear() is erase(start, finish): the tail copy of a polymorphic element folds away
// because last == finish, and the compiler's assignment temporary stays in the frame.
#ifndef D25C_INPUT_QUEUE_H
#define D25C_INPUT_QUEUE_H
inline void *operator new(__SIZE_TYPE__, void *place) throw() { return place; }
extern "C" Ptr32<void> w3d_handle_storage_allocate(unsigned);
extern "C" Ptr32<void> w3d_handle_storage_fallback(unsigned);
extern "C" void w3d_handle_storage_release(Ptr32<void>);
inline Ptr32<void> d24f_storage(unsigned bytes) {
    Ptr32<void> p = w3d_handle_storage_allocate(bytes);
    if (0 == p) p = w3d_handle_storage_fallback(bytes);
    return p;
}
#include "d24f_timed_record.h"
template<class T> inline void d24f_construct(T *p, const T &v) { new (p) T(v); }
template<class T> inline void d24f_destroy(T *p) { p->~T(); }
struct D24fNotPod { char w3d_empty; };
template<class T> inline void d24f_destroy_aux(T *first, T *last, const D24fNotPod &) { for (; first != last; ++first) d24f_destroy(w3d::R(first)); }
template<class T> inline void d24f_destroy_typed(T *first, T *last, T *) { d24f_destroy_aux(w3d::R(first), w3d::R(last), D24fNotPod()); }
template<class T> inline void d24f_destroy_range(T *first, T *last) { d24f_destroy_typed(w3d::R(first), w3d::R(last), w3d::R((Ptr32<T>)0)); }
template<class T> inline Ptr32<T> d24f_uninit_copy(const T *first, const T *last, T *out, const D24fNotPod &) {
    for (; first != last; ++first, ++out) d24f_construct(w3d::R(out), *first);
    return out;
}
template<class T> inline Ptr32<T> d24f_uninit_fill_n(T *out, unsigned n, const T &v) {
    for (; n > 0; --n, ++out) d24f_construct(w3d::R(out), v);
    return out;
}
template<class T> inline Ptr32<T> d24f_copy_ptrs(const T *first, const T *last, T *out, const D24fNotPod &) { for (int n = last - first; n > 0; --n) { *out = *first; ++first; ++out; } return out; }
template<class T> inline const T &d24f_max(const T &a, const T &b) { return a < b ? b : a; }
template<class T> struct D24fAllocator {
    Ptr32<T> allocate(unsigned n) { return n != 0 ? (Ptr32<T>)d24f_storage(n * sizeof(T)) : 0; }
    void deallocate(Ptr32<T> p) { if (p) w3d_handle_storage_release(p); }
 char w3d_empty; };
template<class T> struct D24fVector {
    Ptr32<T> start; Ptr32<T> finish;
    D24fAllocator<T> allocator;
    Ptr32<T> storage_end;
    void set(Ptr32<T> s, Ptr32<T> f, Ptr32<T> e) { start = s; finish = f; storage_end = e; }
    void clear_storage() {
        d24f_destroy_range(w3d::R(start), w3d::R(finish));
        if (start) w3d_handle_storage_release(start);
    }
    void insert_overflow(Ptr32<T> pos, const T &x, const D24fNotPod &tag, unsigned fill_len) {
        const unsigned old_size = finish - start;
        const unsigned len = old_size + d24f_max(old_size, fill_len);
        Ptr32<T> new_start = allocator.allocate(len);
        Ptr32<T> new_finish = new_start;
        new_finish = d24f_uninit_copy(w3d::R(start), w3d::R(pos), w3d::R(new_start), tag);
        if (fill_len == 1) {
            d24f_construct(w3d::R(new_finish), x);
            ++new_finish;
        } else
            new_finish = d24f_uninit_fill_n(w3d::R(new_finish), fill_len, x);
        clear_storage();
        set(new_start, new_finish, new_start + len);
    }
    void push_back(const T &x) {
        if (finish != storage_end) {
            d24f_construct(w3d::R(finish), x);
            ++finish;
        } else
            insert_overflow(finish, x, D24fNotPod(), 1U);
    }
    Ptr32<T> erase(Ptr32<T> first, Ptr32<T> last) {
        Ptr32<T> kept = d24f_copy_ptrs(w3d::R((Ptr32<const T>)last), w3d::R((Ptr32<const T>)finish), w3d::R(first), D24fNotPod());
        d24f_destroy_range(w3d::R(kept), w3d::R(finish));
        finish = kept;
        return first;
    }
    void clear() { erase(start, finish); }
    unsigned size() const { return finish - start; }
};
#endif

// d24d: partial view of the engine's shared-string vector (STLport shape):
// start +0, finish +4, storage end +8, allocator-backed end +12. resize(n)
// takes a default element temporary; erase runs the three STLport layers (copy
// of the empty tail with a __false_type tag, destroy, finish update). The tail
// copy folds away, but it is why the finish pointer is reloaded before the
// destroy loop in the original. Each unit forward declares its element type and
// names the element's out-of-line fill routine through D24D_FILL_INSERT.
#ifndef D24D_STRING_VECTOR_H
#define D24D_STRING_VECTOR_H
struct d24d_String_803426b8 {
    char *text;
    d24d_String_803426b8();
    ~d24d_String_803426b8();
    d24d_String_803426b8 &operator=(const d24d_String_803426b8 &other);
};
extern "C" void d24d_string_finish_8020c5c4(d24d_String_803426b8 *);
extern "C" void d24d_string_release_80341588(d24d_String_803426b8 *);
extern "C" void d24d_string_release_header_8020bb2c(void *);
inline d24d_String_803426b8::~d24d_String_803426b8() {
    d24d_string_finish_8020c5c4(this);
    d24d_string_release_80341588(this);
}
inline d24d_String_803426b8 &d24d_String_803426b8::operator=(const d24d_String_803426b8 &other) {
    ++*(unsigned short *)(other.text - 6);
    unsigned short *header = (unsigned short *)(text - 6);
    if (--*header == 0) d24d_string_release_header_8020bb2c(header);
    text = other.text;
    return *this;
}
struct d24d_FalseType {};
template<class T> inline void d24d_destroy_one(T *p) { p->~T(); }
template<class T> inline void d24d_destroy_aux(T *first, T *last, const d24d_FalseType &) {
    for (; first != last; ++first) d24d_destroy_one(first);
}
template<class T> inline void d24d_destroy_typed(T *first, T *last, T *) {
    d24d_destroy_aux(first, last, d24d_FalseType());
}
template<class T> inline void d24d_destroy(T *first, T *last) { d24d_destroy_typed(first, last, (T *)0); }
template<class T> inline T *d24d_copy_ptrs(const T *first, const T *last, T *out, const d24d_FalseType &) {
    for (int n = last - first; n > 0; --n) { *out = *first; ++first; ++out; }
    return out;
}
template<class T> struct d24d_Vector {
    T *start, *finish, *end_of_storage, *allocator_end;
    unsigned size() const { return finish - start; }
    T *erase(T *first, T *last) {
        T *kept = d24d_copy_ptrs((const T *)last, (const T *)finish, first, d24d_FalseType());
        d24d_destroy(kept, finish);
        finish = kept;
        return first;
    }
    void resize(unsigned count, const T &value) {
        if (count < size()) erase(start + count, finish);
        else D24D_FILL_INSERT(this, finish, count - size(), value);
    }
    void resize(unsigned count) { resize(count, T()); }
};
#endif

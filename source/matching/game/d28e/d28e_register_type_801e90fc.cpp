// (Worms 3D GameCube PAL, 0x801e90fc).
//
// Register a type object in the global table at 0x8045e080: reuse a null
// slot or append, store the table index in the top 10 bits of the word at
// +32, rebuild through 0x801e925c, and return the index.

extern "C" void *w3d_d24k_heap_resize_80213750(void *, unsigned);
extern "C" void *alloc_80212fd4(unsigned);
extern "C" void free_802134fc(void *);
extern "C" void *memcpy_802eee50(void *, const void *, unsigned, ...);
extern "C" void *memmove_802eeef4(void *, const void *, unsigned);
inline const int &v_max(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &v_min(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
template<class T> struct Slots {
    char *begin, *end, *cap;
    unsigned size() const { return (T *)end - (T *)begin; }
    T &operator[](unsigned i) { return ((T *)begin)[i]; }
    Slots &operator=(const Slots &o) {
        unsigned n = o.end - o.begin;
        begin = (char *)w3d_d24k_heap_resize_80213750(begin, n);
        cap = end = begin + n;
        memcpy_802eee50(begin, o.begin, n);
        return *this;
    }
    T *first() { return (T *)begin; }
    T *last() { return (T *)end; }
    void push_back(const T &x) {
        if (end == cap) {
            unsigned used = end - begin;
            unsigned bytes = v_max((int)(used + 1), (int)(used + (used >> 1))) * sizeof(T);
            char *data = (char *)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
        }
        *(T *)end = x;
        end += sizeof(T);
    }
    void reserve(unsigned want) {
        unsigned c = cap - begin;
        unsigned have = (T *)cap - (T *)begin;
        if (want > have) {
            unsigned used = end - begin;
            unsigned bytes = v_max((int)(c + (want - have)), (int)(c + (c >> 1))) * sizeof(T);
            char *data = (char *)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
        }
    }
    void clear() { erase(begin, end); }
    void erase(char *first, char *last) {
        unsigned gone = last - first;
        memcpy_802eee50(first, last, end - last);
        end -= gone;
    }
    void insert(char *pos, unsigned n, const T &x) {
        unsigned at = (T *)pos - (T *)begin;
        if (pos + n * sizeof(T) > cap) {
            unsigned used = end - begin;
            unsigned left = (T *)cap - (T *)pos; unsigned c = cap - begin;
            unsigned bytes = v_max((int)(c + (n - left)), (int)(c + (c >> 1))) * sizeof(T);
            char *data = (char *)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
            pos = begin + at * sizeof(T);
        }
        if (pos == end) {
            for (unsigned i = 0; i < n; i++) *(T *)(end + i * sizeof(T)) = x;
            end += n * sizeof(T);
        } else {
            T y = x;
            memmove_802eeef4(pos + n * sizeof(T), pos, end - pos);
            end += n * sizeof(T);
            for (unsigned i = 0; i < n; i++) *(T *)pos = y;
        }
    }
    void resize(unsigned n, const T &x = T()) {
        if (n < size()) erase(begin + n * sizeof(T), end);
        else insert(end, n - size(), x);
    }
};
template<class T, class V> inline void v_fill(T *first, T *last, const V &value) {
    for (; first != last; ++first) *first = value;
}

struct Obj { char u[32]; unsigned index : 10; unsigned rest : 22; };
extern Slots<Obj *> lbl_8045e080;
extern "C" Obj **w3d_find_80356884(Obj **, Obj **, Obj *const *);
extern "C" void fn_801e925c();
extern "C" unsigned w3d_d28e_register_type_801e90fc(Obj *o)
{
    Obj *none = 0;
    Obj **slot = w3d_find_80356884((Obj **)lbl_8045e080.begin, (Obj **)lbl_8045e080.end, &none);
    int idx;
    if (slot != (Obj **)lbl_8045e080.end) {
        *slot = o;
        idx = slot - (Obj **)lbl_8045e080.begin;
    } else {
        idx = slot - (Obj **)lbl_8045e080.begin;
        lbl_8045e080.push_back(o);
    }
    o->index = idx;
    fn_801e925c();
    return o->index;
}

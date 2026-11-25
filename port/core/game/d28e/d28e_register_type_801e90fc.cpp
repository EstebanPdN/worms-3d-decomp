#include "w3d_ptr.h"
#line 1 "d28e_register_type_801e90fc.cpp"
// (Worms 3D GameCube PAL, 0x801e90fc).
//
// Register a type object in the global table at 0x8045e080: reuse a null
// slot or append, store the table index in the top 10 bits of the word at
// +32, rebuild through 0x801e925c, and return the index.

extern "C" Ptr32<void> w3d_d24k_heap_resize_80213750(Ptr32<void>, unsigned);
extern "C" Ptr32<void> alloc_80212fd4(unsigned);
extern "C" void free_802134fc(Ptr32<void>);
extern "C" Ptr32<void> memcpy_802eee50(Ptr32<void>, Ptr32<const void>, unsigned, ...);
extern "C" Ptr32<void> memmove_802eeef4(Ptr32<void>, Ptr32<const void>, unsigned);
inline const int &v_max(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &v_min(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
template<class T> struct Slots {
    Ptr32<char> begin; Ptr32<char> end; Ptr32<char> cap;
    unsigned size() const { return (Ptr32<T>)end - (Ptr32<T>)begin; }
    T &operator[](unsigned i) { return ((Ptr32<T>)begin)[i]; }
    Slots &operator=(const Slots &o) {
        unsigned n = o.end - o.begin;
        begin = (Ptr32<char>)w3d_d24k_heap_resize_80213750(begin, n);
        cap = end = begin + n;
        memcpy_802eee50(begin, o.begin, n);
        return *this;
    }
    Ptr32<T> first() { return (Ptr32<T>)begin; }
    Ptr32<T> last() { return (Ptr32<T>)end; }
    void push_back(const T &x) {
        if (end == cap) {
            unsigned used = end - begin;
            unsigned bytes = v_max((int)(used + 1), (int)(used + (used >> 1))) * sizeof(T);
            Ptr32<char> data = (Ptr32<char>)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
        }
        *(Ptr32<T>)end = x;
        end += sizeof(T);
    }
    void reserve(unsigned want) {
        unsigned c = cap - begin;
        unsigned have = (Ptr32<T>)cap - (Ptr32<T>)begin;
        if (want > have) {
            unsigned used = end - begin;
            unsigned bytes = v_max((int)(c + (want - have)), (int)(c + (c >> 1))) * sizeof(T);
            Ptr32<char> data = (Ptr32<char>)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
        }
    }
    void clear() { erase(begin, end); }
    void erase(Ptr32<char> first, Ptr32<char> last) {
        unsigned gone = last - first;
        memcpy_802eee50(first, last, end - last);
        end -= gone;
    }
    void insert(Ptr32<char> pos, unsigned n, const T &x) {
        unsigned at = (Ptr32<T>)pos - (Ptr32<T>)begin;
        if (pos + n * sizeof(T) > cap) {
            unsigned used = end - begin;
            unsigned left = (Ptr32<T>)cap - (Ptr32<T>)pos; unsigned c = cap - begin;
            unsigned bytes = v_max((int)(c + (n - left)), (int)(c + (c >> 1))) * sizeof(T);
            Ptr32<char> data = (Ptr32<char>)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
            pos = begin + at * sizeof(T);
        }
        if (pos == end) {
            for (unsigned i = 0; i < n; i++) *(Ptr32<T>)(end + i * sizeof(T)) = x;
            end += n * sizeof(T);
        } else {
            T y = x;
            memmove_802eeef4(pos + n * sizeof(T), pos, end - pos);
            end += n * sizeof(T);
            for (unsigned i = 0; i < n; i++) *(Ptr32<T>)pos = y;
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

struct Obj { char u[32]; unsigned int rest:22; unsigned int index:10; };
extern Slots <Ptr32<Obj> > lbl_8045e080;
extern "C" Ptr32<Ptr32<Obj>> w3d_find_80356884(Ptr32<Ptr32<Obj>>, Ptr32<Ptr32<Obj>>, Ptr32<Ptr32<Obj> const>);
extern "C" void fn_801e925c();
extern "C" unsigned w3d_d28e_register_type_801e90fc(Ptr32<Obj> o)
{
    Ptr32<Obj> none = 0;
    Ptr32<Ptr32<Obj>> slot = w3d_find_80356884((Ptr32<Ptr32<Obj>>)lbl_8045e080.begin, (Ptr32<Ptr32<Obj>>)lbl_8045e080.end, &none);
    int idx;
    if (slot != (Ptr32<Ptr32<Obj>>)lbl_8045e080.end) {
        *slot = o;
        idx = slot - (Ptr32<Ptr32<Obj>>)lbl_8045e080.begin;
    } else {
        idx = slot - (Ptr32<Ptr32<Obj>>)lbl_8045e080.begin;
        lbl_8045e080.push_back(o);
    }
    o->index = idx;
    fn_801e925c();
    return o->index;
}



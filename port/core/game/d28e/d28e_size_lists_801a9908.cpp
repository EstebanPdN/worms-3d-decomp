#include "w3d_ptr.h"
#line 1 "d28e_size_lists_801a9908.cpp"
// (Worms 3D GameCube PAL, 0x801a9908).
//
// Resize the list of word vectors at +288 to n default elements (erase
// destroys the tail, growth goes through the fill insert 0x80354f08) and
// reserve 16 words in each element. Returns 0.

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

struct List {
    Slots<int> items; int extra;

    List() { items.cap = 0; items.end = 0; items.begin = 0; extra = 0; }
    ~List() { if (items.begin) free_802134fc(items.begin); }
};
struct Lists;
template<class T> inline void v_dist(T *first, T *last, int &n) { n += last - first; }
template<class T> inline Ptr32<T> v_copy(T *first, T *last, T *out) {
    int n = 0;
    v_dist(w3d::R(first), w3d::R(last), n);
    for (; n > 0; --n) { *out = *first; ++first; ++out; }
    return out;
}
extern "C" void sol35f4r_nested_buffer_insert_80354f08(Ptr32<Lists>, Ptr32<List>, unsigned, Ptr32<const List>);
struct Lists {
    Ptr32<List> start; Ptr32<List> finish; Ptr32<List> limit;
    unsigned size() const { return finish - start; }
    List &operator[](unsigned i) { return start[i]; }
    void erase(Ptr32<List> first, Ptr32<List> last) {
        Ptr32<List> e = v_copy(w3d::R(last), w3d::R(finish), w3d::R(first));
        { Ptr32<List> l = finish; for (Ptr32<List> p = e; p != l; ++p) p->~List(); }
        finish = e;
    }
    void resize(unsigned n, const List &x = List()) {
        if (n < size()) erase(start + n, finish);
        else sol35f4r_nested_buffer_insert_80354f08(this, finish, n - size(), &x);
    }
};
struct Self { char u[288]; Lists lists; };
extern "C" int w3d_d28e_size_lists_801a9908(Ptr32<Self> self, unsigned n)
{
    self->lists.resize(n);
    for (unsigned i = 0; i < n; i++) self->lists[i].items.reserve(16);
    return 0;
}



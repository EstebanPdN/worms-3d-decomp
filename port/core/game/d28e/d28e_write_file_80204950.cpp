#include "w3d_ptr.h"
#line 1 "d28e_write_file_80204950.cpp"
// (Worms 3D GameCube PAL, 0x80204950).
//
// Serialize to a stream: resets, runs the collection pass through the table
// slot at +32, assigns running offsets to the sized map at +44, numbers the
// objects of the map at +60 per type and lists them, writes the header,
// types, guids, tables and body through the section writers, then writes
// each listed object through its table. Returns 0.

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

template<class T> struct Array : Slots<T> { using Slots<T>::cap; using Slots<T>::end; using Slots<T>::begin; using Slots<T>::first; using Slots<T>::last;
    Array(unsigned n) {
        cap = 0; end = 0; begin = 0;
        grow(n);
        end += n * sizeof(T);
    }
    struct Init { T v; Init() : v(0) { } const T &get() const { return v; } };
    void zero_fill(Ptr32<T> f, Ptr32<T> l, const Init &x) { for (; f != l; ++f) *f = x.get(); }
    void assign() { zero_fill(first(), last(), Init()); }
    Array(const Array &o) {
        unsigned bytes = o.end - o.begin;
        begin = (char *)alloc_80212fd4(bytes);
        cap = end = begin + bytes;
        memcpy_802eee50(begin, o.begin, bytes);
    }
    ~Array() { if (begin) free_802134fc(begin); }
    void grow(unsigned n) {
        unsigned used = end - begin;
        unsigned c = cap - begin;
        unsigned bytes = v_max((int)(c + n), (int)(c + (c >> 1))) * sizeof(T);
        Ptr32<char> data = (Ptr32<char>)alloc_80212fd4(bytes);
        if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
        begin = data; end = data + used; cap = data + bytes;
    }
};
template<class T, class V> inline void v_fill_(T *, T *, const V &);

extern "C" Ptr32<void> w3d_rb_increment_80351ef8(Ptr32<void>);
template<class V> struct TreeNode { int color; Ptr32<TreeNode < V >> parent; Ptr32<TreeNode < V >> left; Ptr32<TreeNode < V >> right; V value; };
template<class V> struct TreeIter {
    Ptr32<TreeNode < V >> node;
    template <class W3dU> TreeIter<V>(Ptr32<W3dU> w3d_p) : TreeIter<V>((TreeNode < V > *)w3d_p.get()) {}
 TreeIter(TreeNode<V> *n) : node(n) { }
    TreeIter(const TreeIter &o) : node(o.node) { }
    bool operator!=(const TreeIter &o) const { return node != o.node; }
    V &operator*() const { return node->value; }
    TreeIter &operator++() { node = (Ptr32<TreeNode < V >>)w3d_rb_increment_80351ef8(node); return *this; }
};
template<class V> struct Tree {
    int alloc; Ptr32<TreeNode < V >> header; unsigned count; int cmp;
    unsigned size() const { return count; }
    TreeIter<V> begin() { return TreeIter<V>(header->left); }
    TreeIter<V> end() { return TreeIter<V>(header); }
};
struct Stream;
struct Sized { Ptr32<void> key; int size; int off0; int off1; };
struct SizedPair { unsigned k; Sized second; };
struct Item { void w3d_r_v8() __asm__(W3D_SYM("_ZN4Item2v8Ev")); void w3d_r_v12() __asm__(W3D_SYM("_ZN4Item3v12Ev")); void w3d_r_v16() __asm__(W3D_SYM("_ZN4Item3v16Ev")); unsigned w3d_r_id() __asm__(W3D_SYM("_ZN4Item2idEv")); void w3d_r_write(Ptr32<struct Writer>) __asm__(W3D_SYM("_ZN4Item5writeEP6Writer"));  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline unsigned int id() { return ((unsigned int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void write(Ptr32<struct Writer> w3d_a0) { ((void (*)(w3d_u32, Ptr32<struct Writer>))w3d::vfn(this->w3d_vptr_Item, 6))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Item; };
struct Value16 { char u[12]; int next; };
struct Slotted { Ptr32<Item> item; int slot; };
struct Self;
extern "C" void fn_80204850(Ptr32<Self>);
extern "C" int w3d_auto_801ffea8(Ptr32<void>);
extern "C" Ptr32<Value16> fn_80205654(Ptr32<Self>, unsigned);
extern "C" void f7c_header_80204c18(Ptr32<Self>);
extern "C" int f7c_types_80204d88(Ptr32<Self>);
extern "C" int f7c_guids_80204f08(Ptr32<Self>);
extern "C" int fn_80204ffc(Ptr32<Self>);
extern "C" int fn_80205258(Ptr32<Self>);
extern "C" int w3d_auto_80205648(Ptr32<Self>);
struct Writer { void w3d_r_v8() __asm__(W3D_SYM("_ZN6Writer2v8Ev")); void w3d_r_v12() __asm__(W3D_SYM("_ZN6Writer3v12Ev")); void w3d_r_v16() __asm__(W3D_SYM("_ZN6Writer3v16Ev")); void w3d_r_v20() __asm__(W3D_SYM("_ZN6Writer3v20Ev")); void w3d_r_v24() __asm__(W3D_SYM("_ZN6Writer3v24Ev")); void w3d_r_v28() __asm__(W3D_SYM("_ZN6Writer3v28Ev")); void w3d_r_begin_stream(Ptr32<Stream>, int) __asm__(W3D_SYM("_ZN6Writer12begin_streamEP6Streami"));  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Writer, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Writer, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Writer, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Writer, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Writer, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Writer, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void begin_stream(Ptr32<Stream> w3d_a0, int w3d_a1) { ((void (*)(w3d_u32, Ptr32<Stream>, int))w3d::vfn(this->w3d_vptr_Writer, 8))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_Writer; };
struct Self : Writer {
    char u4[20] __attribute__((aligned(__alignof__(Writer)))); int state; char u28[16];
    Tree<SizedPair> sized; Tree<Slotted> slotted; char u76[72]; Ptr32<Stream> stream;
};
extern "C" int w3d_d28e_write_file_80204950(Ptr32<Self> self, Ptr32<Stream> s)
{
    self->stream = s;
    fn_80204850(self);
    self->state = 1;
    self->begin_stream(s, 0);
    self->state = 2;
    int offset = 1;
    for (TreeIter<SizedPair> it = self->sized.begin(); it != self->sized.end(); ++it) {
        Sized &e = (*it).second;
        w3d_auto_801ffea8(e.key);
        e.off0 = offset;
        e.off1 = offset;
        offset += e.size;
    }
    int count = self->slotted.size();
    Array <Ptr32<Item> > list(count + 1);
    for (TreeIter<Slotted> j = self->slotted.begin(); j != self->slotted.end(); ++j) {
        Ptr32<Item> o = (*j).item;
        Ptr32<Value16> v = fn_80205654(self, o->id());
        (*j).slot = v->next++;
        list[(*j).slot] = o;
    }
    f7c_header_80204c18(self);
    f7c_types_80204d88(self);
    f7c_guids_80204f08(self);
    fn_80204ffc(self);
    fn_80205258(self);
    w3d_auto_80205648(self);
    for (int i = 1; i <= count; i++) {
        Ptr32<Item> o = list[i];
        fn_80205654(self, o->id());
        o->write((Ptr32<Writer>)self);
    }
    self->state = 0;
    return 0;
}



#include "w3d_ptr.h"
#line 1 "d40e_renumber_classes_801e925c.cpp"
// (Worms 3D GameCube PAL, 0x801e925c).
//
// Renumbers the class registry at 0x8045e080. Each registered class with a
// wanted index keeps it, the rest take free slots searched with 0x80356934.
// If any index moved, the table is rebuilt in the new order, moved classes
// are told their index (0x801e9090), the hook list of 0x801ea954 runs under
// its lock, and 0x801e80f0 is called. The allocator 0x80212fd4 is declared by
// its C name malloc: the compiler treats its result as unaliased, which is why
// the zero fill of a new array hoists its load past the stores.

extern "C" Ptr32<void> w3d_d24k_heap_resize_80213750(Ptr32<void>, unsigned);
extern "C" Ptr32<void> malloc(unsigned);
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
            Ptr32<char> data = (Ptr32<char>)malloc(bytes);
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
            Ptr32<char> data = (Ptr32<char>)malloc(bytes);
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
            Ptr32<char> data = (Ptr32<char>)malloc(bytes);
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
    Array() { }
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
        begin = (char *)malloc(bytes);
        cap = end = begin + bytes;
        memcpy_802eee50(begin, o.begin, bytes);
    }
    ~Array() { if (begin) free_802134fc(begin); }
    void grow(unsigned n) {
        unsigned used = end - begin;
        unsigned c = cap - begin;
        unsigned bytes = v_max((int)(c + n), (int)(c + (c >> 1))) * sizeof(T);
        Ptr32<char> data = (Ptr32<char>)malloc(bytes);
        if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
        begin = data; end = data + used; cap = data + bytes;
    }
};
template<class T, class V> inline void v_fill_(T *, T *, const V &);
template<class A> inline void v_swap(A &a, A &b) { A t(a); a = b; b = t; }
struct Obj { char u[32]; unsigned int rest:22; unsigned int index:10; };
struct Info { char u[4]; unsigned wanted; char pad[0]; };
struct Info2 { char u[6]; unsigned short id; };

struct Lockable { void w3d_r_v8() __asm__(W3D_SYM("_ZN8Lockable2v8Ev")); void w3d_r_retain() __asm__(W3D_SYM("_ZN8Lockable6retainEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN8Lockable7releaseEv"));  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lockable, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lockable, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lockable, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Lockable; };
struct Hooked { void w3d_r_v8() __asm__(W3D_SYM("_ZN6Hooked2v8Ev")); void w3d_r_call() __asm__(W3D_SYM("_ZN6Hooked4callEv"));  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Hooked, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void call() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Hooked, 3))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Hooked; };
struct ListNode { Ptr32<ListNode> next; Ptr32<ListNode> prev; Ptr32<Hooked> obj; };
struct ListIter {
    Ptr32<ListNode> node;
    template <class W3dU> ListIter(Ptr32<W3dU> w3d_p) : ListIter((ListNode *)w3d_p.get()) {}
 ListIter(ListNode *n) : node(n) { }
    ListIter(const ListIter &o) : node(o.node) { }
    bool operator!=(const ListIter &o) const { return node != o.node; }
};
struct CIter { Ptr32<ListNode> node; CIter(const ListIter &i) : node(i.node) { } bool operator!=(CIter o) const { return node != o.node; } Ptr32<Hooked> get() const { return node->obj; } Ptr32<ListNode> next() const { return node->next; } void set(Ptr32<ListNode> n) { node = n; } };
struct HookList { char u[4]; Ptr32<ListNode> head; ListIter begin() { return ListIter(head->next); } ListIter end() { return ListIter(head); } };
struct Registry : Lockable { HookList hooks __attribute__((aligned(__alignof__(Lockable)))); };
struct Lock { Ptr32<Lockable> p; template <class W3dU> Lock(Ptr32<W3dU> w3d_p) : Lock((Lockable *)w3d_p.get()) {}
 Lock(Lockable *q) : p(q) { p->retain(); } Lock(const Lock &o) : p(o.p) { } ~Lock() { p->release(); } };
extern Array <Ptr32<Obj> > lbl_8045e080;
extern "C" Ptr32<void> f5c_search_801e8ff8(Ptr32<Obj>);
extern "C" Ptr32<int> w3d_find_80356934(Ptr32<int>, Ptr32<int>, Ptr32<const int>);
extern "C" void w3d_s21_set_class_801e9090(Ptr32<Obj>, int);
extern "C" Ptr32<Registry> w3d_local_static_801ea954();
extern "C" void w3d_auto_801e80f0(int);
inline void call_hooks(CIter first, CIter last) {
    while (first != last) {
        Ptr32<ListNode> next = first.next();
        first.get()->call();
        first.set(next);
    }
}
extern "C" void w3d_d40e_renumber_classes_801e925c()
{
    unsigned n = lbl_8045e080.size();
    unsigned n0 = n;
    Array<unsigned short> map(n);
    Array<int> used(n);
    used.assign();
    int idx = 0;
    int changed = 0;
    for (Ptr32<Obj> *it = lbl_8045e080.first(),*e = lbl_8045e080.last(); it != e; ++it, ++idx) {
        int none = -1;
        if (*it != 0) {
            Ptr32<char> info = (Ptr32<char>)f5c_search_801e8ff8(*it);
            if (info != 0) {
                map[idx] = ((Ptr32<Info2>)info)->id;
                unsigned v = ((Ptr32<Info>)info)->wanted;
                if (v >= n) {
                    n = v + 1;
                    used.resize(n);
                }
                used[((Ptr32<Info>)info)->wanted] = 1;
                if (idx != ((Ptr32<Info>)info)->wanted) changed = 1;
            } else map[idx] = none;
        } else map[idx] = none;
    }
    lbl_8045e080.resize(n);
    int i = n0 - 1;
    if (i >= 0) { int one = 1; do {
        if (map[i] == 0xffff) {
            if (used[i] == 0) {
                used[i] = one;
                map[i] = i;
            } else {
                int none = 0;
                changed = 1;
                Ptr32<int> p = w3d_find_80356934(used.first(), used.last(), &none);
                *p = one;
                map[i] = p - used.first();
            }
        }
    } while (--i >= 0); }
    if (changed) {
        Array <Ptr32<Obj> > old(n);
        old.assign();
        for (int j = 0; j < (int)n0; j++) old[map[j]] = lbl_8045e080[j];
        v_swap(old, lbl_8045e080);
        for (int k = 0; k < (int)n; k++) {
            Ptr32<Obj> o = lbl_8045e080[k];
            if (old[k] != o && o) w3d_s21_set_class_801e9090(o, k);
        }
        {
            Ptr32<Registry> r = w3d_local_static_801ea954();
            Lock lock(r);
            HookList &hooks = r->hooks;
            CIter it = hooks.begin();
            CIter stop = hooks.end();
            while (it != stop) {
                Ptr32<ListNode> next = it.next();
                it.get()->call();
                it.set(next);
            }
        }
        w3d_auto_801e80f0(0);
    }
}



#include "w3d_ptr.h"
#line 1 "d27j_rebuild_masks_8019a010.cpp"
// Rebuild the per-channel mask lists, GWMP8P rev0 0x8019a010. Clears the list
// of bit vectors, sizes it to the bank's channel count with a zeroed vector of
// (bits - 1) / 32 + 1 words, then sets one bit per enabled entry of each
// channel in the registry. The vectors are STLport-shaped: the end of storage
// sits in an allocator proxy at +8 (stored through its own pointer), and the
// default allocator argument is the empty class temporary that leaves the
// stack gap at sp+24 below the zero fill value at sp+32.

struct Rec {
    float t0, t1, t2, t3;
    unsigned short channel, tag, state, seq;
    ~Rec() {}
};
struct FalseType { char w3d_empty; };
template <class T> inline void DestroyAux(T *first, T *last, const FalseType &) { for (; first != last; ++first) first->~T(); }
template <class T> inline void DestroyValue(T *first, T *last, T *) { DestroyAux(w3d::R(first), w3d::R(last), FalseType()); }
template <class T> inline void DestroyRange(T *first, T *last) { DestroyValue(w3d::R(first), w3d::R(last), w3d::R(first)); }
template <class T> inline void Distance(T *first, T *last, int &n) { n += last - first; }
template <class T> inline Ptr32<T> CopyRange(T *first, T *last, T *result) {
    int n = 0;
    Distance(w3d::R(first), w3d::R(last), n);
    for (; n > 0; --n) { *result = *first; ++first; ++result; }
    return result;
}
template <class T> struct List {
    Ptr32<T> start; Ptr32<T> finish; Ptr32<T> cap; Ptr32<T> alloc;
    Ptr32<T> begin() { return start; }
    Ptr32<T> end() { return finish; }
    Ptr32<T> erase(Ptr32<T> pos) {
        if (pos + 1 != finish) CopyRange(w3d::R(pos + 1), w3d::R(finish), w3d::R(pos));
        --finish;
        finish->~T();
        return pos;
    }
    Ptr32<T> erase(Ptr32<T> first, Ptr32<T> last) {
        Ptr32<T> e = CopyRange(w3d::R(last), w3d::R(finish), w3d::R(first));
        DestroyRange(w3d::R(e), w3d::R(finish));
        finish = e;
        return first;
    }
    void clear() { erase(begin(), end()); }
};
extern "C" void release_801907d0(Ptr32<void>);
struct Alloc { Alloc() {} Alloc(const Alloc &) {}  char w3d_empty; };
template <class T> struct Proxy { int a; Ptr32<T> data; Proxy(const Alloc &, Ptr32<T> p) : data(p) {} };
struct IntVec {
    Ptr32<int> start; Ptr32<int> finish;
    Proxy<int> cap;
    IntVec(const Alloc &a = Alloc()) : start(0), finish(0), cap(a, 0) {}
    ~IntVec() { if (start) release_801907d0(start); }
    unsigned size() const { return finish - start; }
    Ptr32<int> begin() { return start; }
    Ptr32<int> end() { return finish; }
    int &operator[](unsigned i) { return start[i]; }
    void erase(Ptr32<int> first, Ptr32<int> last) {
        Ptr32<int> e = CopyRange(w3d::R(last), w3d::R(finish), w3d::R(first));
        finish = e;
    }
    void resize(unsigned n, const int &x = 0);
};
extern "C" Ptr32<int> insert_80350a78(Ptr32<IntVec>, Ptr32<int>, unsigned, Ptr32<const int>);
inline void IntVec::resize(unsigned n, const int &x) {
    if (n < size()) erase(begin() + n, end());
    else insert_80350a78(this, end(), n - size(), &x);
}
struct MaskList {
    Ptr32<IntVec> start; Ptr32<IntVec> finish; Ptr32<IntVec> alloc; Ptr32<IntVec> cap;
    unsigned size() const { return finish - start; }
    Ptr32<IntVec> begin() { return start; }
    Ptr32<IntVec> end() { return finish; }
    IntVec &operator[](unsigned i) { return start[i]; }
    void erase(Ptr32<IntVec> from, Ptr32<IntVec> to) {
        Ptr32<IntVec> e = CopyRange(w3d::R(to), w3d::R(finish), w3d::R(from));
        DestroyRange(w3d::R(e), w3d::R(finish));
        finish = e;
    }
    void clear() { erase(begin(), end()); }
    void resize(unsigned n, const IntVec &x);
};
extern "C" void insert_80350dd8(Ptr32<MaskList>, Ptr32<IntVec>, unsigned, Ptr32<const IntVec>);
inline void MaskList::resize(unsigned n, const IntVec &x) {
    if (n < size()) erase(begin() + n, end());
    else insert_80350dd8(this, end(), n - size(), &x);
}
struct Entry { unsigned short id, u0; /* PPC +2: mitad baja de la palabra */ unsigned char u4[4]; unsigned short enabled; unsigned char ua[2]; };
struct EntryList { Ptr32<Entry> start; Ptr32<Entry> finish; Ptr32<Entry> alloc; Ptr32<Entry> cap; unsigned size() const { return finish - start; } Entry &operator[](unsigned i) { return start[i]; } };
struct Bank { unsigned u0; unsigned count; unsigned bits; };
struct Registry;
struct RegistryVtable { Ptr32<void> u0[8]; Ptr32<Ptr32<Bank> (Ptr32<Registry>)> bank; };
struct EntryLists { Ptr32<EntryList> start; EntryList &operator[](unsigned i) { return start[i]; } };
struct Registry { Ptr32<RegistryVtable> vtable; unsigned char u4[48]; EntryLists lists; };
struct Mixer;
struct MixerVtable { Ptr32<void> u0[7]; Ptr32<Ptr32<Registry> (Ptr32<Mixer>)> registry; };
struct Mixer { Ptr32<MixerVtable> vtable; };
struct Player { Ptr32<void> vtable; unsigned char u4[16]; Ptr32<Mixer> mixer; float time; unsigned char u1c[4]; List<Rec> active; List<Rec> queued; int seq; MaskList masks; };
extern "C" void d27j_rebuild_masks_8019a010(Ptr32<Player> self) {
    self->masks.clear();
    Ptr32<Registry> g = self->mixer->vtable->registry(self->mixer);
    unsigned n = g->vtable->bank(g)->count;
    g = self->mixer->vtable->registry(self->mixer);
    unsigned bits = g->vtable->bank(g)->bits;
    {
    IntVec m;
    IntVec &rm = m;
    unsigned words = ((bits - 1) >> 5) + 1;
    rm.resize(words);
    for (unsigned i = 0; i < words; ++i) rm[i] = 0;
    self->masks.resize(n, rm);
    }
    Ptr32<Registry> r = self->mixer->vtable->registry(self->mixer);
    for (unsigned c = 0; c < n; ++c) {
        for (unsigned j = 0; j < r->lists[c].size(); ++j) {
            Entry &e = r->lists[c][j];
            if (e.enabled) self->masks[c][e.id >> 5] |= 1 << (e.id & 31);
        }
    }
}



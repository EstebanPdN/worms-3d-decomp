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
struct FalseType {};
template <class T> inline void DestroyAux(T *first, T *last, const FalseType &) { for (; first != last; ++first) first->~T(); }
template <class T> inline void DestroyValue(T *first, T *last, T *) { DestroyAux(first, last, FalseType()); }
template <class T> inline void DestroyRange(T *first, T *last) { DestroyValue(first, last, first); }
template <class T> inline void Distance(T *first, T *last, int &n) { n += last - first; }
template <class T> inline T *CopyRange(T *first, T *last, T *result) {
    int n = 0;
    Distance(first, last, n);
    for (; n > 0; --n) { *result = *first; ++first; ++result; }
    return result;
}
template <class T> struct List {
    T *start, *finish, *cap, *alloc;
    T *begin() { return start; }
    T *end() { return finish; }
    T *erase(T *pos) {
        if (pos + 1 != finish) CopyRange(pos + 1, finish, pos);
        --finish;
        finish->~T();
        return pos;
    }
    T *erase(T *first, T *last) {
        T *e = CopyRange(last, finish, first);
        DestroyRange(e, finish);
        finish = e;
        return first;
    }
    void clear() { erase(begin(), end()); }
};
extern "C" void release_801907d0(void *);
struct Alloc { Alloc() {} Alloc(const Alloc &) {} };
template <class T> struct Proxy { int a; T *data; Proxy(const Alloc &, T *p) : data(p) {} };
struct IntVec {
    int *start, *finish;
    Proxy<int> cap;
    IntVec(const Alloc &a = Alloc()) : start(0), finish(0), cap(a, 0) {}
    ~IntVec() { if (start) release_801907d0(start); }
    unsigned size() const { return finish - start; }
    int *begin() { return start; }
    int *end() { return finish; }
    int &operator[](unsigned i) { return start[i]; }
    void erase(int *first, int *last) {
        int *e = CopyRange(last, finish, first);
        finish = e;
    }
    void resize(unsigned n, const int &x = 0);
};
extern "C" int *insert_80350a78(IntVec *, int *, unsigned, const int *);
inline void IntVec::resize(unsigned n, const int &x) {
    if (n < size()) erase(begin() + n, end());
    else insert_80350a78(this, end(), n - size(), &x);
}
struct MaskList {
    IntVec *start, *finish, *alloc, *cap;
    unsigned size() const { return finish - start; }
    IntVec *begin() { return start; }
    IntVec *end() { return finish; }
    IntVec &operator[](unsigned i) { return start[i]; }
    void erase(IntVec *from, IntVec *to) {
        IntVec *e = CopyRange(to, finish, from);
        DestroyRange(e, finish);
        finish = e;
    }
    void clear() { erase(begin(), end()); }
    void resize(unsigned n, const IntVec &x);
};
extern "C" void insert_80350dd8(MaskList *, IntVec *, unsigned, const IntVec *);
inline void MaskList::resize(unsigned n, const IntVec &x) {
    if (n < size()) erase(begin() + n, end());
    else insert_80350dd8(this, end(), n - size(), &x);
}
struct Entry { unsigned short u0, id; unsigned char u4[4]; unsigned short enabled; unsigned char ua[2]; };
struct EntryList { Entry *start, *finish, *alloc, *cap; unsigned size() const { return finish - start; } Entry &operator[](unsigned i) { return start[i]; } };
struct Bank { unsigned u0; unsigned count; unsigned bits; };
struct Registry;
struct RegistryVtable { void *u0[8]; Bank *(*bank)(Registry *); };
struct EntryLists { EntryList *start; EntryList &operator[](unsigned i) { return start[i]; } };
struct Registry { RegistryVtable *vtable; unsigned char u4[48]; EntryLists lists; };
struct Mixer;
struct MixerVtable { void *u0[7]; Registry *(*registry)(Mixer *); };
struct Mixer { MixerVtable *vtable; };
struct Player { void *vtable; unsigned char u4[16]; Mixer *mixer; float time; unsigned char u1c[4]; List<Rec> active; List<Rec> queued; int seq; MaskList masks; };
extern "C" void d27j_rebuild_masks_8019a010(Player *self) {
    self->masks.clear();
    Registry *g = self->mixer->vtable->registry(self->mixer);
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
    Registry *r = self->mixer->vtable->registry(self->mixer);
    for (unsigned c = 0; c < n; ++c) {
        for (unsigned j = 0; j < r->lists[c].size(); ++j) {
            Entry &e = r->lists[c][j];
            if (e.enabled) self->masks[c][e.id >> 5] |= 1 << (e.id & 31);
        }
    }
}

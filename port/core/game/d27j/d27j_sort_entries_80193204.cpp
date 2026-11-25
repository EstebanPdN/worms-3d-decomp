#include "w3d_ptr.h"
#line 1 "d27j_sort_entries_80193204.cpp"
// Sort the channel entries and every record's element list by name, GWMP8P
// rev0 0x80193204. Builds an index vector, bubble sorts it by name then two
// byte keys (the second strcmp repeats the first), copies the entries in
// sorted order through a temporary vector and back with reference-counted
// string assignment, then reorders each list the same way through a temporary
// element vector. Vectors are STLport-shaped with the end of storage in a
// proxy at +8. The string constructor and destructor take their address
// through a small accessor, which keeps it in a saved register.

extern "C" void fn_8020c5c4(Ptr32<void>);
extern "C" void fn_80341588(Ptr32<void>);
extern "C" void fn_8020bb2c(Ptr32<void>);
extern "C" Ptr32<void> fn_803426b8(Ptr32<void>);
extern "C" void fn_8034f190(Ptr32<void>);
extern "C" void fn_801907d0(Ptr32<void>);
extern "C" void fn_802134fc(Ptr32<void>);
extern "C" int strcmp_802ef234(Ptr32<const char>, Ptr32<const char>);
struct Hdr { unsigned short refs; };
struct Str {
    Ptr32<char> text;
    Ptr32<void> self() { return this; }
    Str() { fn_803426b8(self()); }
    ~Str() { fn_8020c5c4(self()); fn_80341588(self()); }
    Str &operator=(const Str &o) {
        ((Ptr32<Hdr>)(o.text - 6))->refs++;
        Ptr32<Hdr> h = (Ptr32<Hdr>)(text - 6);
        if (--h->refs == 0) fn_8020bb2c(h);
        text = o.text;
        return *this;
    }
};
struct Entry {
    Str name;
    unsigned char a, b;
    unsigned short c;
    Entry &operator=(const Entry &o) { name = o.name; a = o.a; b = o.b; c = o.c; return *this; }
};
inline bool less(const Entry &x, const Entry &y) {
    if (strcmp_802ef234(x.name.text, y.name.text) < 0) return true;
    if (strcmp_802ef234(x.name.text, y.name.text) == 0) {
        if (x.a < y.a) return true;
        if (x.a == y.a && x.b < y.b) return true;
    }
    return false;
}
struct Inner { Inner() { fn_8034f190(this); } int a, b; };
struct Elem { int word; Inner inner; ~Elem() {} };
template<class T> inline void v_dist(T *first, T *last, int &n) { n += last - first; }
template<class T> inline Ptr32<T> v_copy(T *first, T *last, T *out) {
    int n = 0;
    v_dist(w3d::R(first), w3d::R(last), n);
    for (; n > 0; --n) { *out = *first; ++first; ++out; }
    return out;
}
struct VAl { VAl() {} VAl(const VAl &) {}  char w3d_empty; };
inline VAl v_convert(const VAl &a) { return a; }
template<class T> struct VEnd { int a; Ptr32<T> data; VEnd(const VAl &, Ptr32<T> p) { data = p; } };
struct IntVec {
    Ptr32<int> start; Ptr32<int> finish;
    VEnd<int> end;
    IntVec(const VAl &a = VAl()) : start(0), finish(0), end(a, 0) {}
    ~IntVec() { if (start) fn_802134fc(start); }
    unsigned size() const { return finish - start; }
    int &operator[](unsigned i) { return start[i]; }
    void erase(Ptr32<int> first, Ptr32<int> last) { finish = first; }
    void resize(unsigned n, const int &x = 0);
};
extern "C" void insert_80344380(Ptr32<IntVec>, Ptr32<int>, unsigned, Ptr32<const int>);
inline void IntVec::resize(unsigned n, const int &x) {
    if (n < size()) erase(start + n, finish);
    else insert_80344380(this, finish, n - size(), &x);
}
struct EntryVec {
    Ptr32<Entry> start; Ptr32<Entry> finish;
    VEnd<Entry> end;
    EntryVec(const VAl &a = VAl()) : start(0), finish(0), end(a, 0) {}
    ~EntryVec() {
        Ptr32<Entry> l = finish;
        for (Ptr32<Entry> p = start; p != l; ++p) p->~Entry();
        if (start) fn_802134fc(start);
    }
    unsigned size() const { return finish - start; }
    Entry &operator[](unsigned i) { return start[i]; }
    void erase(Ptr32<Entry> first, Ptr32<Entry> last) {
        Ptr32<Entry> e = v_copy(w3d::R(last), w3d::R(finish), w3d::R(first));
        Ptr32<Entry> l = finish;
        for (Ptr32<Entry> p = e; p != l; ++p) p->~Entry();
        finish = e;
    }
    void resize(unsigned n, const Entry &x);
};
extern "C" void insert_8034d568(Ptr32<EntryVec>, Ptr32<Entry>, unsigned, Ptr32<const Entry>);
inline void EntryVec::resize(unsigned n, const Entry &x) {
    if (n < size()) {
        erase(start + n, finish);
    } else insert_8034d568(this, finish, n - size(), &x);
}
struct ElemVec {
    Ptr32<Elem> start; Ptr32<Elem> finish;
    VEnd<Elem> end;
    ElemVec(const VAl &a = VAl()) : start(0), finish(0), end(a, 0) {}
    ~ElemVec() {
        Ptr32<Elem> l = finish;
        for (Ptr32<Elem> p = start; p != l; ++p) p->~Elem();
        if (start) fn_801907d0(start);
    }
    unsigned size() const { return finish - start; }
    Elem &operator[](unsigned i) { return start[i]; }
    void erase(Ptr32<Elem> first, Ptr32<Elem> last) {
        Ptr32<Elem> e = v_copy(w3d::R(last), w3d::R(finish), w3d::R(first));
        Ptr32<Elem> l = finish;
        for (Ptr32<Elem> p = e; p != l; ++p) p->~Elem();
        finish = e;
    }
    void resize(unsigned n, const Elem &x);
};
extern "C" void insert_8034d1c8(Ptr32<ElemVec>, Ptr32<Elem>, unsigned, Ptr32<const Elem>);
inline void ElemVec::resize(unsigned n, const Elem &x) {
    if (n < size()) {
        erase(start + n, finish);
    } else insert_8034d1c8(this, finish, n - size(), &x);
}
struct Lists { Ptr32<ElemVec> start; ElemVec &operator[](unsigned i) { return start[i]; } };
struct Entries { Ptr32<Entry> start; Entry &operator[](unsigned i) { return start[i]; } };
struct Self { char u0[20]; Entries entries; char u18[28]; Lists lists; char u38[16]; unsigned listCount; unsigned count; };
extern "C" void d27j_sort_entries_80193204(Ptr32<Self> self) {
    unsigned c = self->count;
    if (c == 0) return;
    IntVec order;
    order.resize(c);
    unsigned i;
    for (i = 0; i < self->count; ++i) order[i] = i;
    for (unsigned last = self->count - 1; last != 0; --last) {
        for (unsigned j = 0; j < last; ++j) {
            if (less(self->entries[order[j + 1]], self->entries[order[j]])) {
                int t = order[j];
                order[j] = order[j + 1];
                order[j + 1] = t;
            }
        }
    }
    EntryVec sorted;
    { unsigned n = self->count; Entry e; Entry &re = e; sorted.resize(n, re); }
    for (i = 0; i < self->count; ++i) sorted[i] = self->entries[order[i]];
    for (i = 0; i < self->count; ++i) self->entries[i] = sorted[i];
    ElemVec tmp;
    { unsigned n = self->count; Elem e; Elem &re = e; tmp.resize(n, re); }
    for (unsigned l = 0; l < self->listCount; ++l) {
        for (i = 0; i < self->count; ++i) tmp[i] = self->lists[l][order[i]];
        for (i = 0; i < self->count; ++i) self->lists[l][i] = tmp[i];
    }
}



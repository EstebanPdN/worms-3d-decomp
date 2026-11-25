#include "w3d_ptr.h"
#line 1 "d28j_resolve_conflicts_801993f8.cpp"
// Resolve conflicting queued sounds, GWMP8P rev0 0x801993f8. For each active
// record in state 1 it collects the other active records whose channel masks
// intersect its own in a function-local static pointer list (guard at
// 0x804b02ec, object 0x8045ccac, exit handler 0x801993c8; declared here as
// external views of those objects). With no conflict the record becomes steady
// (state 3). Otherwise, if any pair of collected records does not intersect,
// it drops and erases them all from the end and restarts from the first
// record. The drop call takes the list slot pointer before the decrement, as
// the original does. The push_back is inlined STLport growth for a trivial
// element.

struct Rec {
    float t0, t1, t2, t3;
    unsigned short channel, tag, state;
    unsigned short :15; unsigned short loop:1;
    ~Rec() {}
};
template <class T> inline Ptr32<T> CopyRange(T *first, T *last, T *result) {
    int n = last - first;
    for (; n > 0; --n) { *result = *first; ++first; ++result; }
    return result;
}
struct Active {
    Ptr32<Rec> start; Ptr32<Rec> finish; Ptr32<Rec> cap; Ptr32<Rec> alloc;
    Ptr32<Rec> begin() { return start; }
    Ptr32<Rec> end() { return finish; }
    Ptr32<Rec> erase(Ptr32<Rec> pos) {
        if (pos + 1 != finish) CopyRange(w3d::R(pos + 1), w3d::R(finish), w3d::R(pos));
        --finish;
        finish->~Rec();
        return pos;
    }
};
struct Mask {
    Ptr32<unsigned int> start; Ptr32<unsigned int> finish;
    int a; Ptr32<unsigned int> cap;
    bool intersects(const Mask &o) const {
        Ptr32<const unsigned int> p = start; Ptr32<const unsigned int> q = o.start;
        for (; p != finish; ++p, ++q) if (*p & *q) return true;
        return false;
    }
};
struct Masks { Ptr32<Mask> start; Mask &operator[](unsigned i) { return start[i]; } };
extern "C" Ptr32<void> alloc_80212fd4(unsigned);
extern "C" Ptr32<void> fallback_803413d8(unsigned);
extern "C" void release_802134fc(Ptr32<void>);
extern "C" Ptr32<void> memmove_802eeef4(Ptr32<void>, Ptr32<const void>, unsigned);
struct True { True() {} True(const True &) {}  char w3d_empty; };
inline const unsigned &maximum(const unsigned &a, const unsigned &b) { return a < b ? b : a; }
inline Ptr32<void> allocate(unsigned n) {
    Ptr32<void> r = alloc_80212fd4(n);
    if (r == 0) r = fallback_803413d8(n);
    return r;
}
inline Ptr32<Ptr32<Rec>> copyTrivial(Ptr32<Ptr32<Rec>> first, Ptr32<Ptr32<Rec>> last, Ptr32<Ptr32<Rec>> out) {
    if (last != first) {
        unsigned k = (Ptr32<char>)last - (Ptr32<char>)first;
        return (Ptr32<Ptr32<Rec>>)((Ptr32<char>)memmove_802eeef4(out, first, k) + k);
    }
    return out;
}
inline Ptr32<Ptr32<Rec>> fillN(Ptr32<Ptr32<Rec>> out, unsigned n, Ptr32<Rec> const &x) {
    for (; n != 0; --n, ++out) *out = x;
    return out;
}
struct Ptrs {
    Ptr32<Ptr32<Rec>> start; Ptr32<Ptr32<Rec>> finish;
    int a;
    Ptr32<Ptr32<Rec>> cap;
    unsigned size() const { return finish - start; }
    void clear() { finish = start; }
    void set(Ptr32<Ptr32<Rec>> s, Ptr32<Ptr32<Rec>> f, Ptr32<Ptr32<Rec>> e) { cap = e; finish = f; start = s; }
    void overflow(Ptr32<Ptr32<Rec>> pos, Ptr32<Rec> const &x, const True &, unsigned n) {
        const unsigned old = size();
        const unsigned length = old + maximum(old, n);
        Ptr32<Ptr32<Rec>> ns = length ? w3d::R((Ptr32<Ptr32<Rec>>)allocate(length * 4)) : 0;
        Ptr32<Ptr32<Rec>> nf = fillN(copyTrivial(start, pos, ns), n, x);
        if (start) release_802134fc(start);
        set(ns, nf, ns + length);
    }
    void push_back(Ptr32<Rec> const &x) {
        if (finish != cap) {
            if (finish) *finish = x;
            ++finish;
        } else overflow(finish, x, True(), 1);
    }
};
struct Player { unsigned char u0[32]; Active active; unsigned char u30[20]; Masks masks; };
extern int guard_804b02ec;
extern Ptrs lbl_8045ccac;
extern "C" int atexit_802ed7e0(Ptr32<void (void)>);
extern "C" void dtor_801993c8();
extern "C" int drop_8019ab0c(Ptr32<Player>, Ptr32<Ptr32<Rec>>);
extern "C" void d28j_resolve_conflicts_801993f8(Ptr32<Player> self) {
    Ptr32<Rec> p = self->active.begin();
    Ptr32<Ptrs> l;
    if (guard_804b02ec == 0) {
        lbl_8045ccac.finish = 0;
        lbl_8045ccac.start = 0;
        guard_804b02ec = 1;
        lbl_8045ccac.cap = 0;
        atexit_802ed7e0(dtor_801993c8);
    }
    while (p != self->active.end()) {
        if (p->state == 1) {
            for (Ptr32<Rec> q = self->active.begin(); q != self->active.end(); ++q) {
                if (p != q && self->masks[p->channel].intersects(self->masks[q->channel])) lbl_8045ccac.push_back(&*q);
            }
            if (lbl_8045ccac.size() == 0) {
                p->state = 3;
                continue;
            }
            bool found = false;
            Ptr32<Ptr32<Rec>> a;
            for (a = lbl_8045ccac.start; !found; ++a) {
                if (a == lbl_8045ccac.finish) break;
                for (Ptr32<Ptr32<Rec>> b = a + 1; !found && b != lbl_8045ccac.finish; ++b) {
                    if (!self->masks[(*a)->channel].intersects(self->masks[(*b)->channel])) found = true;
                }
            }
            if (found) {
                a = lbl_8045ccac.finish;
                while (a != lbl_8045ccac.start) {
                    drop_8019ab0c(self, a);
                    --a;
                    self->active.erase(*a);
                }
                p = self->active.begin();
            } else ++p;
            l = &lbl_8045ccac;
            l->clear();
        } else ++p;
    }
    l = &lbl_8045ccac;
    l->clear();
}



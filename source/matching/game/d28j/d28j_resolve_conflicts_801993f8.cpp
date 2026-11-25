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
    unsigned loop : 1;
    ~Rec() {}
};
template <class T> inline T *CopyRange(T *first, T *last, T *result) {
    int n = last - first;
    for (; n > 0; --n) { *result = *first; ++first; ++result; }
    return result;
}
struct Active {
    Rec *start, *finish, *cap, *alloc;
    Rec *begin() { return start; }
    Rec *end() { return finish; }
    Rec *erase(Rec *pos) {
        if (pos + 1 != finish) CopyRange(pos + 1, finish, pos);
        --finish;
        finish->~Rec();
        return pos;
    }
};
struct Mask {
    unsigned *start, *finish;
    int a; unsigned *cap;
    bool intersects(const Mask &o) const {
        const unsigned *p = start, *q = o.start;
        for (; p != finish; ++p, ++q) if (*p & *q) return true;
        return false;
    }
};
struct Masks { Mask *start; Mask &operator[](unsigned i) { return start[i]; } };
extern "C" void *alloc_80212fd4(unsigned);
extern "C" void *fallback_803413d8(unsigned);
extern "C" void release_802134fc(void *);
extern "C" void *memmove_802eeef4(void *, const void *, unsigned);
struct True { True() {} True(const True &) {} };
inline const unsigned &maximum(const unsigned &a, const unsigned &b) { return a < b ? b : a; }
inline void *allocate(unsigned n) {
    void *r = alloc_80212fd4(n);
    if (r == 0) r = fallback_803413d8(n);
    return r;
}
inline Rec **copyTrivial(Rec **first, Rec **last, Rec **out) {
    if (last != first) {
        unsigned k = (char *)last - (char *)first;
        return (Rec **)((char *)memmove_802eeef4(out, first, k) + k);
    }
    return out;
}
inline Rec **fillN(Rec **out, unsigned n, Rec *const &x) {
    for (; n != 0; --n, ++out) *out = x;
    return out;
}
struct Ptrs {
    Rec **start, **finish;
    int a;
    Rec **cap;
    unsigned size() const { return finish - start; }
    void clear() { finish = start; }
    void set(Rec **s, Rec **f, Rec **e) { cap = e; finish = f; start = s; }
    void overflow(Rec **pos, Rec *const &x, const True &, unsigned n) {
        const unsigned old = size();
        const unsigned length = old + maximum(old, n);
        Rec **ns = length ? (Rec **)allocate(length * 4) : 0;
        Rec **nf = fillN(copyTrivial(start, pos, ns), n, x);
        if (start) release_802134fc(start);
        set(ns, nf, ns + length);
    }
    void push_back(Rec *const &x) {
        if (finish != cap) {
            if (finish) *finish = x;
            ++finish;
        } else overflow(finish, x, True(), 1);
    }
};
struct Player { unsigned char u0[32]; Active active; unsigned char u30[20]; Masks masks; };
extern int guard_804b02ec;
extern Ptrs lbl_8045ccac;
extern "C" int atexit_802ed7e0(void (*)());
extern "C" void dtor_801993c8();
extern "C" int drop_8019ab0c(Player *, Rec **);
extern "C" void d28j_resolve_conflicts_801993f8(Player *self) {
    Rec *p = self->active.begin();
    Ptrs *l;
    if (guard_804b02ec == 0) {
        lbl_8045ccac.finish = 0;
        lbl_8045ccac.start = 0;
        guard_804b02ec = 1;
        lbl_8045ccac.cap = 0;
        atexit_802ed7e0(dtor_801993c8);
    }
    while (p != self->active.end()) {
        if (p->state == 1) {
            for (Rec *q = self->active.begin(); q != self->active.end(); ++q) {
                if (p != q && self->masks[p->channel].intersects(self->masks[q->channel])) lbl_8045ccac.push_back(&*q);
            }
            if (lbl_8045ccac.size() == 0) {
                p->state = 3;
                continue;
            }
            bool found = false;
            Rec **a;
            for (a = lbl_8045ccac.start; !found; ++a) {
                if (a == lbl_8045ccac.finish) break;
                for (Rec **b = a + 1; !found && b != lbl_8045ccac.finish; ++b) {
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

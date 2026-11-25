// GWMP8P rev0 0x80294408. Walks four retained handles from a lookup, locks
// the word array at +20 of the last and fills it with one value. The count
// sits in a one-word local whose inline accessor is read in the loop test;
// that form is chosen for its instruction effect (the preheader copy of the
// bound) and is listed under caveats.
// Observed handle and locked array views; roles inferred.
struct Obj { void **vtable; };
struct Held {
    Obj *p;
    Held(Obj *n) : p(n) { if (p) ((void (*)(Obj *))p->vtable[3])(p); }
    Held(const Held &);
    ~Held() { if (p) ((void (*)(Obj *))p->vtable[4])(p); }
    char *c() const { return (char *)p; }
};
struct ArrayHeader { char pad[4]; unsigned short refs; char pad6[18]; unsigned count; unsigned short locks; char pad30[2]; int data[1]; };
struct Array {
    ArrayHeader *h;
    int *Lock();
};
extern "C" int *w3d_k5b_array_ref_lock_8(Array *, unsigned, int, int);
inline int *Array::Lock() {
    ArrayHeader *hd = h;
    unsigned n = hd->count;
    if (hd->refs == 1) { hd->locks++; return hd->data; }
    return w3d_k5b_array_ref_lock_8(this, n, 4, 2);
}
extern "C" Obj *w3d_auto_801750d4(void *);
struct Level3 { char pad[72]; Obj *o; };
struct Inner { char pad[32]; Obj *o; };
struct L1 { char pad[44]; Inner *inner; };
struct L2 { char pad[48]; Obj *o; };
struct L4 { char pad[20]; Array array; };
struct Sized { unsigned c; unsigned Size() const { return c; } };
extern "C" void d28f_fill_held_array_80294408(void **self, const int &value) {
    Held a(w3d_auto_801750d4(*self));
    Held b(((L1 *)a.p)->inner->o);
    Held c(((L2 *)b.p)->o);
    Held d(((Level3 *)c.p)->o);
    Array &array = ((L4 *)d.p)->array;
    unsigned n = array.h->count;
    int *data = array.Lock();
    Sized s; s.c = n;
    for (unsigned i = 0; i < s.Size(); i++)
        data[i] = value;
}

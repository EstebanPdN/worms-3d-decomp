#include "w3d_ptr.h"
#line 1 "d28f_fill_held_array_80294408.cpp"
// GWMP8P rev0 0x80294408. Walks four retained handles from a lookup, locks
// the word array at +20 of the last and fills it with one value. The count
// sits in a one-word local whose inline accessor is read in the loop test;
// that form is chosen for its instruction effect (the preheader copy of the
// bound) and is listed under caveats.
// Observed handle and locked array views; roles inferred.
struct Obj { Ptr32<Ptr32<void>> vtable; };
struct Held {
    Ptr32<Obj> p;
    template <class W3dU> Held(Ptr32<W3dU> w3d_p) : Held((Obj *)w3d_p.get()) {}
 Held(Obj *n) : p(n) { if (p) ((Ptr32<void (Ptr32<Obj>)>)p->vtable[3])(p); }
    Held(const Held &);
    ~Held() { if (p) ((Ptr32<void (Ptr32<Obj>)>)p->vtable[4])(p); }
    Ptr32<char> c() const { return (Ptr32<char>)p; }
};
struct ArrayHeader { char pad[4]; unsigned short refs; char pad6[18]; unsigned count; unsigned short locks; char pad30[2]; int data[1]; };
struct Array {
    Ptr32<ArrayHeader> h;
    Ptr32<int> Lock();
};
extern "C" Ptr32<int> w3d_k5b_array_ref_lock_8(Ptr32<Array>, unsigned, int, int);
inline Ptr32<int> Array::Lock() {
    Ptr32<ArrayHeader> hd = h;
    unsigned n = hd->count;
    if (hd->refs == 1) { hd->locks++; return hd->data; }
    return w3d_k5b_array_ref_lock_8(this, n, 4, 2);
}
extern "C" Ptr32<Obj> w3d_auto_801750d4(Ptr32<void>);
struct Level3 { char pad[72]; Ptr32<Obj> o; };
struct Inner { char pad[32]; Ptr32<Obj> o; };
struct L1 { char pad[44]; Ptr32<Inner> inner; };
struct L2 { char pad[48]; Ptr32<Obj> o; };
struct L4 { char pad[20]; Array array; };
struct Sized { unsigned c; unsigned Size() const { return c; } };
extern "C" void d28f_fill_held_array_80294408(Ptr32<Ptr32<void>> self, const int &value) {
    Held a(w3d_auto_801750d4(*self));
    Held b(((Ptr32<L1>)a.p)->inner->o);
    Held c(((Ptr32<L2>)b.p)->o);
    Held d(((Ptr32<Level3>)c.p)->o);
    Array &array = ((Ptr32<L4>)d.p)->array;
    unsigned n = array.h->count;
    Ptr32<int> data = array.Lock();
    Sized s; s.c = n;
    for (unsigned i = 0; i < s.Size(); i++)
        data[i] = value;
}



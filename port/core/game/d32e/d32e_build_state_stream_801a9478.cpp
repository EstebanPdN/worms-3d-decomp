#include "w3d_ptr.h"
#line 1 "d32e_build_state_stream_801a9478.cpp"
// (Worms 3D GameCube PAL, 0x801a9478).
//
// Builds the render state stream of a mesh: counts three words per attribute
// across the group list, locks the output array, then for each attribute
// writes the looked-up table entry for each of its three bit-field keys only
// when the key changed, followed by its value; shrinks the array to the
// words written, clears the dirty flag at +284 and returns the output
// object.

struct Hdr { int u0; unsigned short rc; char u6[18]; int size; unsigned short lock; char u30[2]; int data[1]; };
struct ArrayRef;
extern "C" Ptr32<void> w3d_k5b_array_ref_lock_801ef048(Ptr32<ArrayRef>, unsigned, unsigned, int);
struct ArrayRef {
    Ptr32<Hdr> h;
    Ptr32<void> Lock(unsigned n, int copy) {
        if (h->rc == 1 && n == (unsigned)h->size) { Ptr32<int> d = h->data; h->lock++; return d; }
        return w3d_k5b_array_ref_lock_801ef048(this, n, 4, copy);
    }
    void Unlock(unsigned n) {
        if (h->rc == 1 && n == (unsigned)h->size) { h->lock++; return; }
        w3d_k5b_array_ref_lock_801ef048(this, n, 4, 0);
    }
};
struct Result { char u0[20]; ArrayRef arr; };
struct Attr { int u0; int value; int u8; unsigned int b:7; unsigned int c:9; unsigned int a:16; };
struct Group { Ptr32<Ptr32<Attr>> first; Ptr32<Ptr32<Attr>> last; int u8; int u12; };
struct Mesh {
    char u0[176]; Ptr32<Result> out;
    char u180[60];
    Ptr32<int> ta; char u244[8]; Ptr32<int> tb; char u256[12]; Ptr32<int> tc; char u272[12];
    int dirty; Ptr32<Group> gfirst; Ptr32<Group> glast;
};
extern "C" Ptr32<Result> w3d_d32e_build_state_stream_801a9478(Ptr32<Mesh> self)
{
    unsigned total = 0;
    unsigned n = self->glast - self->gfirst;
    for (unsigned k = 0; k < n; k++) {
        Ptr32<Group> g = &self->gfirst[k];
        total += (g->last - g->first) * 3;
    }
    Ptr32<Result> r = self->out;
    Ptr32<int> dst = (Ptr32<int>)r->arr.Lock(total, 1);
    Ptr32<int> base = dst;
    int pa = -1, pc = 0, pb = -1;
    for (unsigned i = 0; i < n; i++) {
        Ptr32<Group> g = &self->gfirst[i];
        Ptr32<Ptr32<Attr>> p = g->first; Ptr32<Ptr32<Attr>> e = g->last;
        for (; p != e; p++) {
            if (pb != (*p)->b) { pb = (*p)->b; *dst++ = *(Ptr32<int>)((Ptr32<char>)self->tb + (pb << 2)); }
            if (pa != (*p)->a) { pa = (*p)->a; *dst++ = *(Ptr32<int>)((Ptr32<char>)self->ta + (pa << 2)); }
            if (pc != (*p)->c) { pc = (*p)->c; *dst++ = *(Ptr32<int>)((Ptr32<char>)self->tc + (pc << 2)); }
            *dst++ = (*p)->value;
        }
    }
    r->arr.Unlock(dst - base);
    self->dirty = 0;
    return r;
}



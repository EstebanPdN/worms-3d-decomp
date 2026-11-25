#include "w3d_ptr.h"
#line 1 "d26j_set_colour_80173df0.cpp"
// Per-vertex colour write through a buffer, GWMP8P rev0 0x80173df0. An
// unchanged colour returns at once. Otherwise stores it, retains the owner's
// buffer, locks the colour array (4-byte elements), and when the array is
// empty grows it by the vertex count and fills it with opaque white, then
// stores the colour at this writer's index. Sibling of 0x80173778. The
// retained buffer handle is one word with a user-visible retain and release.
// Counts for the lock and for the fill are separate variables; the fill bound
// passes through an inline, which makes the loop's exit-test copy the original
// keeps (mr r10,r31). The fill uses an int-parameter setter, as the original
// stores the constant from li r0,-1.

struct Rgba { unsigned char r, g, b, a; void set(int x, int y, int z, int w) { r = x; g = y; b = z; a = w; } };
struct Header { unsigned char u0[4]; unsigned short mode; unsigned char u6[18]; unsigned count; unsigned short locks; unsigned char u1e[2]; };
struct Buffer;
struct BufferVtable { Ptr32<void> u0[3]; Ptr32<int (Ptr32<Buffer>)> retain; Ptr32<int (Ptr32<Buffer>)> release; };
struct Buffer {
    Ptr32<BufferVtable> vtable;
    unsigned char u4[60];
    Ptr32<Header> vertices;
    unsigned char u68[16];
    Ptr32<Header> colors;
    Ptr32<Header> weights;
};
struct Owner { unsigned char u[48]; Ptr32<Buffer> buffer; };
struct Writer { unsigned char u120[120]; Rgba color; int index; Ptr32<Owner> owner; };
extern "C" Ptr32<void> lock_801ef048(Ptr32<Ptr32<Header>>, unsigned, unsigned, unsigned);
struct Retained {
    Ptr32<Buffer> p;
    template <class W3dU> Retained(Ptr32<W3dU> w3d_p) : Retained((Buffer *)w3d_p.get()) {}
 Retained(Buffer *q) : p(q) { if (p) p->vtable->retain(p); }
    ~Retained() { if (p) p->vtable->release(p); }
};
inline Ptr32<void> lockArray(Ptr32<Ptr32<Header>> st, unsigned n) {
    Ptr32<Header> h = *st;
    if (h->mode == 1 && n == h->count) { ++h->locks; return h + 1; }
    return lock_801ef048(st, n, 4, 2);
}
inline unsigned same(const unsigned &x) { return x; }
inline void fillColors(Ptr32<Rgba> d, unsigned n) { for (unsigned i = 0; i < same(n); ++i) d[i].set(-1, -1, -1, -1); }
extern "C" int d26j_set_colour_80173df0(Ptr32<Writer> self, Ptr32<const Rgba> value)
{
    if (value->a != self->color.a || value->r != self->color.r || value->g != self->color.g || value->b != self->color.b) {
        self->color = *value;
        Retained b(self->owner->buffer);
        unsigned n = b.p->colors->count;
        Ptr32<Rgba> d = (Ptr32<Rgba>)lockArray(&b.p->colors, n);
        if (n == 0) {
            unsigned m = b.p->vertices->count;
            d = (Ptr32<Rgba>)lockArray(&b.p->colors, b.p->colors->count + m);
            fillColors(d, m);
        }
        d[self->index] = *value;
    }
    return 0;
}



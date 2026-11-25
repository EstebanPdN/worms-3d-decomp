// Per-vertex weight write through a buffer, GWMP8P rev0 0x80173778. Retains
// the owner's buffer, locks its float array (4-byte elements; lock 0x801ef048
// or the single-user fast path), and when the array is empty grows it by the
// vertex count and clears the new elements to 0.0f, then stores the value's z
// at this writer's index. Sibling of 0x801736a8 and 0x80173df0. The retained
// buffer handle is one word with a user-visible retain and release. Counts for
// the lock and for the fill are separate variables; the fill bound passes
// through an inline, which makes the loop's exit-test copy the original keeps
// (mr r0,r31). The 0.0f literal is the pool word 0x803a6704.

struct Header { unsigned char u0[4]; unsigned short mode; unsigned char u6[18]; unsigned count; unsigned short locks; unsigned char u1e[2]; };
struct Buffer;
struct BufferVtable { void *u0[3]; int (*retain)(Buffer *); int (*release)(Buffer *); };
struct Buffer {
    BufferVtable *vtable;
    unsigned char u4[60];
    Header *vertices;
    unsigned char u68[16];
    Header *colors;
    Header *weights;
};
struct Owner { unsigned char u[48]; Buffer *buffer; };
struct Writer { unsigned char u120[120]; unsigned char color[4]; int index; Owner *owner; };
extern "C" void *lock_801ef048(Header **, unsigned, unsigned, unsigned);
struct Retained {
    Buffer *p;
    Retained(Buffer *q) : p(q) { if (p) p->vtable->retain(p); }
    ~Retained() { if (p) p->vtable->release(p); }
};
inline void *lockArray(Header **st, unsigned n) {
    Header *h = *st;
    if (h->mode == 1 && n == h->count) { ++h->locks; return h + 1; }
    return lock_801ef048(st, n, 4, 2);
}
inline unsigned same(const unsigned &x) { return x; }
inline void fillWeights(float *d, unsigned n) { for (unsigned i = 0; i < same(n); ++i) d[i] = 0.0f; }
extern "C" int d26j_set_weight_80173778(Writer *self, const float *value)
{
    Retained b(self->owner->buffer);
    unsigned n = b.p->weights->count;
    float *d = (float *)lockArray(&b.p->weights, n);
    if (n == 0) {
        unsigned m = b.p->vertices->count;
        d = (float *)lockArray(&b.p->weights, b.p->weights->count + m);
        fillWeights(d, m);
    }
    d[self->index] = value[2];
    return 0;
}

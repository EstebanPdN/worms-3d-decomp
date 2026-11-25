// d40i: 0x80122864. Trail graphic: locks the current mesh vertices, shifts
// the row of a trail one segment back, writes the new end points and
// advances the used count up to the length limit.
struct Vec3 { float x, y, z; };
struct Pair { Vec3 a, b; };
struct ArrayHeader {
    unsigned char unknown00[4];
    unsigned short kind;
    unsigned char unknown06[18];
    int count;
    unsigned short locks;
    unsigned char unknown1e[2];
    Vec3 data[1];
};
struct ArrayRef { ArrayHeader *header; };
extern "C" Vec3 *array_lock_801ef048(ArrayRef *, int, int, int);
struct Mesh { unsigned char unknown00[20]; ArrayRef vertices; };
struct Owner { unsigned char unknown00[80]; Mesh *current; };
struct Trail {
    unsigned char unknown00[28];
    unsigned short length;
    unsigned char unknown1e[2];
    Mesh *front;           // +32
    Mesh *back;            // +36
    unsigned char unknown28[4];
    Owner *owner;          // +44
    unsigned char unknown30[12];
    unsigned short used[156]; // +60
    Pair hist[8];          // +372
};
inline Vec3 *Pick(ArrayRef *a, ArrayHeader *h, int n) { Vec3 *r; if (h->kind == 1) { ++h->locks; r = h->data; } else r = array_lock_801ef048(a, n, 12, 2); return r; }
extern "C" void d40i_trail_push_segment_80122864(Trail *self, const Vec3 *a, const Vec3 *b, int idx) {
    Mesh *cur = self->owner->current;
    Vec3 *v;
    int i;
    ArrayRef *r;
    ArrayHeader *h;
    if (cur == self->front) { r = &cur->vertices; h = r->header; i = h->count; v = Pick(r, h, i); }
    else { r = &self->back->vertices; h = r->header; i = h->count; v = Pick(r, h, i); }
    v += idx * ((self->length << 1) + 4);
    for (i = self->length - 2; i >= 0; i--) {
        v[2 * i + 5] = v[2 * i + 1];
        v[2 * i + 6] = v[2 * i + 2];
    }
    ((Pair *)v)[self->length + 1].b = ((Pair *)v)[self->length + 1].a;
    v[0] = *a;
    v[1] = *a;
    v[2] = *b;
    unsigned short st = self->used[idx];
    if (st == 0) {
        v[3] = *b;
    } else {
        if (st == 2) v[5] = self->hist[idx].b;
        v[3] = self->hist[idx].a;
        v[4] = self->hist[idx].b;
    }
    self->hist[idx].a = *a;
    self->hist[idx].b = *b;
    unsigned short c = self->used[idx] += 2;
    unsigned short lim = self->length * 2 + 2;
    if (c > lim) self->used[idx] = self->length * 2 + 2;
}

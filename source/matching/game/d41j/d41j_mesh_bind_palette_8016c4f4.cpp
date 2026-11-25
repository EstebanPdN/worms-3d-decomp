// Mesh palette binding, GWMP8P rev0 0x8016c4f4. The first use builds the palette
// object: it scans the colours for alpha (RGB565 when opaque, RGB5A3 otherwise),
// converts them into a new table, flushes it, initialises the palette object and
// hands it to the owner through a virtual call. It then loads the palette in slot 0.
// Returns 0. Field and type names are inferred; unread fields are partial views.
extern "C" {
void fn_802fa988(void *, unsigned);
void *fn_80166fd0(void *, unsigned);
void fn_8030a270(void *, void *, int, unsigned short);
void fn_8030a2a8(void *, int);
}
extern void *heap_804b1884;
struct Rgba { unsigned char r, g, b, a; };
struct Buf { char p[24]; unsigned bytes; char q[4]; Rgba data[1]; };
struct Tlut { void *obj; unsigned short *lut; };
struct Mesh { char p[24]; Tlut *tlut; Buf *colors; };
struct Sink2;
struct Sink2Vt { void *u[7]; void (*bind)(Sink2 *, Mesh *, Tlut *); };
struct Sink2 { Sink2Vt *vt; };
struct R { char p[148]; Sink2 *owner; };
struct Sink { void *vt; };
inline unsigned Get(const unsigned &lim) { return lim; }

extern "C" int w3d_d41j_mesh_bind_palette_8016c4f4(Sink *sink, Mesh *mesh) {
  R *self = sink ? (R *)((char *)sink - 4) : 0;
  Tlut *t = mesh->tlut;
  if (!t) {
    int fmt = 1; unsigned i;
    unsigned n = mesh->colors->bytes >> 2;
    
    Rgba *c = mesh->colors->data;
    for (i = 0; i < Get(n); i++, c++) {
      if (c->a != 255) { fmt = 2; break; }
    }
    t = (Tlut *)fn_80166fd0(heap_804b1884, 8);
    t->obj = fn_80166fd0(heap_804b1884, 12);
    unsigned short *d = (unsigned short *)fn_80166fd0(heap_804b1884, n * 2);
    t->lut = d;
    c = mesh->colors->data;
    if (fmt == 1) {
      for (i = 0; i < Get(n); i++, c++, d++)
        *d = ((c->b << 8) & 0xf800) | ((c->g << 3) & 0x7e0) | (c->r >> 3);
    } else if (fmt == 2) {
      for (i = 0; i < Get(n); i++, c++) {
        unsigned a = c->a; unsigned short v;
        if (a > 223) v = ((c->b << 7) & 0x7c00) | ((c->g << 2) & 0x3e0) | (c->r >> 3) | 0x8000;
        else v = ((c->b << 4) & 0xf00) | (c->g & 0xf0) | (c->r >> 4) | ((a << 7) & 0x7000);
        *d++ = v;
      }
    }
    fn_802fa988(t->lut, n * 2);
    fn_8030a270(t->obj, t->lut, fmt, *(unsigned *)&n);
    mesh->tlut = t;
    self->owner->vt->bind(self->owner, mesh, t);
  }
  if (t) fn_8030a2a8(t->obj, 0);
  return 0;
}

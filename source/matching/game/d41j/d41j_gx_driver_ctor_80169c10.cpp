// Graphics driver constructor, GWMP8P rev0 0x80169c10. Stores the three table
// pointers of its class chain in turn, initialises the tag at +4 and the list at
// +136, copies the global identity transform into the 4x4 matrix at +44, creates
// the temporary buffer object, binds it, reads setting XSGX.TempGeomBufferSize
// (default 0x40000) and resets colours, counters and the eight-word table at +328.
// Field and class names are inferred; unread fields are partial views.
struct Vec { float x, y, z; };
struct Mat34 { Vec r0, r1, r2, p; };
extern Mat34 identity_8045e748;
extern "C" void *tag_init_801e81c8(void *);
extern "C" void *construct_801f2678(void *);
extern "C" int setting_read_80206920(const char *, unsigned *);
struct Geo; struct GeoVt { void *u[3]; int (*retain)(Geo *); int (*release)(Geo *); };
struct Geo { GeoVt *vt; };
extern "C" Geo *new_buffers_801a25a0();
extern "C" void bind_source_801a31ec(Geo *, void *, void *);
extern void *vt_80411de0[], *vt_80411d70[], *vt_80411d00[];
struct Mat44 { float m[16];
  void Set(const Mat34 &o) {
    m[0] = o.r0.x; m[1] = o.r0.y; m[2] = o.r0.z; m[3] = 0.0f;
    m[4] = o.r1.x; m[5] = o.r1.y; m[6] = o.r1.z; m[7] = 0.0f;
    m[8] = o.r2.x; m[9] = o.r2.y; m[10] = o.r2.z; m[11] = 0.0f;
    const Vec &p = o.p;
    m[12] = p.x; m[13] = p.y; m[14] = p.z; m[15] = 1.0f;
  }
};
struct Ref { Geo *p;
  void operator=(Geo *q) { if (q) q->vt->retain(q); if (p) p->vt->release(p); p = q; }
};
struct Driver {
  void **vt;
  char tag[36];
  float f40;
  Mat44 view;
  int f108; int p112;
  Ref buffers; int f120; char p124[12]; char member136[12]; int f148; char p152[28];
  unsigned b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, :25; char p184[24];
  unsigned char c208, c209, c210, c211; char p212[8]; unsigned char f220; char p221[7];
  int f228; unsigned buffer_size; char p236[48]; int f284, f288, f292; char p296[16]; int f312;
  unsigned char c316, c317, c318; char p319[9]; int a[8];
  Driver();
};
extern "C" Driver *w3d_d41j_gx_driver_ctor_80169c10(Driver *self) {
  self->vt = vt_80411de0;
  tag_init_801e81c8(self->tag);
  self->buffers.p = 0; self->f120 = 0;
  self->vt = vt_80411d70;
  construct_801f2678(self->member136);
  self->view.Set(identity_8045e748);
  self->f40 = 0.0f; self->f108 = 1;
  self->vt = vt_80411d00;
  self->f148 = 0;
  Geo *g = new_buffers_801a25a0();
  self->buffers = g;
  bind_source_801a31ec(g, self->tag, self);
  self->buffer_size = 0x40000;
  setting_read_80206920("XSGX.TempGeomBufferSize", &self->buffer_size);
  self->f228 = 0; self->f288 = 0; self->f292 = 0; self->f284 = 0; self->f220 = 0;
  self->f312 = 0;
  self->c316 = 16; self->c317 = 16; self->c318 = 16;
  self->c208 = 255; self->c209 = 255; self->c210 = 255; self->c211 = 255;
  self->b6 = 0;
  for (unsigned i = 0; i < 8; i++) self->a[i] = 0;
  return self;
}

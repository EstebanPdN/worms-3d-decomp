// Builds a sprite grid for a material slot: image, texture, material, UV and
// step arrays. GWMP8P rev0 0x80170bac.
extern "C" {
void *w3d_s10_service_forward_8020b680(void *);
void w3d_string_base_init(void *);
unsigned short *w3d_string_header(void *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
void w3d_string_release_header(void *);
void w3d_k5b_iface_array_field_append_801ef174(void *, int, int, void *);
}
struct Iface { virtual void a0(); virtual void add(); virtual void release(); };
template <class T> struct Ref {
  T *p;
  Ref() { p = 0; }
  Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  T *operator->() { return p; }
  Ref &operator=(T *q) { if (q) q->add(); if (p) p->release(); p = q; return *this; }
  Ref &operator=(const Ref &o) { T *old = p; p = o.p; if (p) p->add(); if (old) old->release(); return *this; }
  template <class U> Ref &operator=(const Ref<U> &o) { if (o.p) o.p->add(); if (p) p->release(); p = o.p; return *this; }
};
struct Str {
  char *p;
  Str(const char *);
  Str(const Str &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
  Str &operator=(const Str &o) {
    ++*(unsigned short *)(o.p - 6);
    unsigned short *h = (unsigned short *)(p - 6);
    if (--*h == 0) w3d_string_release_header(h);
    p = o.p;
    return *this;
  }
};
inline void use(Str) {}
extern "C" void *fn_802eee50(void *, const void *, ...);
struct Vec2 { float x, y; float &Y() { return y; } };
struct Vec { float x, y, z; };
struct Sphere { Vec c; float r; };
struct Box { Vec lo; Vec hi; };
struct Blob { char p0[4]; unsigned short kind; char p6[18]; int count; unsigned short locks; char p1e[2]; char data[1]; };
struct Handle;
extern "C" void *w3d_k5b_array_ref_lock_801ef048(Handle *, int, int, int);
struct Handle {
  Blob *b;
  Vec2 *lock(int n, int stride) {
    Blob *x = b;
    if (x->kind == 1 && n == x->count) { x->locks++; return (Vec2 *)x->data; }
    return (Vec2 *)w3d_k5b_array_ref_lock_801ef048(this, n, stride, 1);
  }
};
struct Bits { char p0[7]; unsigned char flags; void mark() { flags |= 4; } };
struct Tex : Iface { char p4[40]; unsigned short w; unsigned short h; };
struct Image : Iface { char p4[16]; Str name; char p18[12]; Handle st; Handle uv; };
struct Mat : Iface { char p4[32]; int z36; int z40; char p2c[12]; int z56; Ref<Tex> tex; char p40[16]; int z80; };
struct Cfg : Iface { virtual void s20(); virtual void set(Tex *); virtual void s28(); virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52(); virtual void setWrap(int); virtual void s60(); virtual void setMip(int); virtual void s68(); virtual void s72(); virtual void s76(); virtual void setName(const char *, int); virtual void s84(); virtual void s88(); virtual void s92(); virtual void s96(); virtual void s100(); virtual void s104(); virtual void s108(); virtual void s112(); virtual void s116(); virtual void s120(); virtual void s124(); virtual void s128(); virtual void s132(); virtual void s136(); virtual void s140(); virtual void setFilter(int); };
struct Mod : Iface { Bits bits; char p4[8]; Box box; int z44; void setBox(const Box &v) { box = v; } };
struct Geo : Iface { void setBound(const Sphere &v) { bound = v; } char p4[16]; Sphere bound; Str name; int z40; char p2c[4]; Ref<Mod> mod; Ref<Image> image; };
struct Inst : Iface { void setBound(const Sphere &v) { bound = v; } char p4[16]; Sphere bound; Str name; int z40; };
struct Loader : Iface { virtual void s20(); virtual void s24(); virtual void s28(); virtual int load(char *, Ref<Tex> *); };
struct Root : Iface { virtual void s20(); virtual void s24(); virtual void s28(); virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52(); virtual void s56(); virtual void s60(); virtual void s64(); virtual void s68(); virtual void s72(); virtual void s76(); virtual void s80(); virtual void s84(); virtual void s88(); virtual Loader *loader(void *); };
extern "C" Root *w3d_auto_8020b648();
struct Sink : Iface { virtual void s20(); virtual int attach(Iface *); };
struct Self {
  char p0[20]; Str name; union { int flags; struct { char f0; unsigned char kind; } b; }; char p1c[4]; char *path; unsigned short cols; unsigned short rows; unsigned short cw; unsigned short ch; unsigned short tw; unsigned short th; unsigned short count; unsigned short opts; char p34[24]; Ref<Image> img;
};
extern "C" Mod *w3d_s20_get_selected_material_80172088(Self *, unsigned char);
extern "C" int fn_801720fc(Self *, unsigned char);
extern "C" int w3d_auto_80171b1c(Self *, int);
extern "C" int w3d_auto_80171ab8(Self *, int);
extern "C" int w3d_auto_80171b80(Self *, int);
extern "C" void * w3d_auto_801d0858(Image *, int *);
extern "C" void w3d_auto_801d086c(Image *, Mat *);
extern "C" void w3d_auto_801d0898(Image *, Mat *, int);
extern "C" void w3d_cx13b_sphere_bounds_801f5724(Box *, Sphere *);
extern void *lbl_804b012c, *lbl_804b0130, *lbl_804b013c;
struct SinkP { Sink *p; };
extern char lbl_80415b50[], lbl_804143e0[], lbl_80413db0[], lbl_80415d60[], lbl_80414518[], lbl_80414600[], lbl_804144f8[];
inline Loader *get_loader(void *type) { return w3d_auto_8020b648()->loader(type); }
inline void bind(Image *i, Mat *m) {
  int on;
  w3d_auto_801d0858(i, &on);
  if (on) w3d_auto_801d0898(i, m, 0); else w3d_auto_801d086c(i, m);
}
extern const int lbl_803a65d0[5]; // {11, 13, 12, 19, 20}
extern "C" int d31j_build_material_image_grid_80170bac(Self *self) {
  int on = (self->flags >> 15) & 1;
  if (on) return 0x80004005;
  self->img = (Image *)w3d_s10_service_forward_8020b680(lbl_80415b50);
  Loader *l = get_loader(lbl_804143e0);
  Ref<Tex> tex;
  Str path(self->path);
  {
    Image *ip = self->img.p;
    ip->name = Str(self->path);
  }
  if (l->load(path.p, &tex) < 0) {
    use(path), use(self->name);
    return 0x80004005;
  }
  Ref<Mat> m((Mat *)w3d_s10_service_forward_8020b680(lbl_80415d60));
  m->tex = tex;
  m->z56 = 1;
  m->z80 = 1;
  if (self->opts & 128) {
    m->z40 = 1;
    m->z36 = 1;
  } else {
    m->z40 = 3;
    m->z36 = 3;
  }
  bind(self->img.p, m.p);
  w3d_k5b_iface_array_field_append_801ef174(self->img.p, 28, 3, lbl_804b012c);
  w3d_k5b_iface_array_field_append_801ef174(self->img.p, 28, 3, lbl_804b0130);
  w3d_k5b_iface_array_field_append_801ef174(self->img.p, 28, 3, lbl_804b013c);
  w3d_s20_get_selected_material_80172088(self, self->b.kind)->bits.mark();
  fn_801720fc(self, self->b.kind);
  int ha = tex->h;
  self->tw = ha;
  unsigned short ta = ha;
  int hb = tex->w;
  self->th = hb;
  unsigned short tb = hb;
  if (self->opts & 32) {
    self->cw = ta / self->cols;
    self->ch = tb / self->rows;
  } else {
    self->cols = ta / self->cw;
    self->rows = tb / self->ch;
  }
  Vec2 step;
  step.x = (float)self->cw / (float)(int)self->tw;
  step.Y() = (float)self->ch / (float)(int)self->th;
  self->count = self->cols * self->rows;
  int k2 = 0;
  Vec2 *a = self->img->uv.lock(self->count, 8);
  Vec2 *b = self->img->st.lock(self->count, 8);
  for (float v = 1.0f - step.Y(); v >= 0.0f; v -= step.Y()) {
    for (float u = 0.0f; u <= 1.0f - step.x; u += step.x) {
      b[k2] = step;
      a[k2].x = u;
      a[k2].y = v;
      k2++;
    }
  }
  self->flags |= 0x8000;
  if (self->opts & 2) w3d_auto_80171b1c(self, 1); else w3d_auto_80171b1c(self, 0);
  if (self->opts & 1) w3d_auto_80171ab8(self, 1); else w3d_auto_80171ab8(self, 0);
  if (self->opts & 16) w3d_auto_80171b80(self, 1); else w3d_auto_80171b80(self, 0);
  if (!(self->opts & 256)) {
    Ref<Cfg> c((Cfg *)w3d_s10_service_forward_8020b680(lbl_80413db0));
    c->setWrap(4);
    c->setFilter(0);
    c->setMip(1);
    c->setName((const char *)lbl_803a65d0, 5);
    c->set(tex.p);
  }
  return 0;
}

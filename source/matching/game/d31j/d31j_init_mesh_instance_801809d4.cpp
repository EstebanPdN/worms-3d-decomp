// Initialises a mesh instance from its descriptor: resets references, builds the
// instance and texture, copies the clip and option bits, and optionally builds
// rig, hook and skin nodes. GWMP8P rev0 0x801809d4.
extern "C" {
void *w3d_s10_service_forward_8020b680(void *);
int w3d_auto_80179aec(void *, void *, unsigned char);
void * w3d_string_default(void *);
void w3d_string_format(void *, const char *, ...);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
void w3d_string_release_header(void *);
void w3d_k5b_iface_array_field_append_801ef174(void *, int, int, void *);
void w3d_auto_801f2798(void *);
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
};
struct Str {
  char *p;
  Str() {}
  Str(const Str &);
  ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
  Str &operator=(const Str &o) {
    ++*(unsigned short *)(o.p - 6);
    unsigned short *h = (unsigned short *)(p - 6);
    if (--*h == 0) w3d_string_release_header(h);
    p = o.p;
    return *this;
  }
};
struct Vec { float x, y, z; void set(float f) { x = f; y = f; z = f; } };
struct Bits { char p0[7]; unsigned char flags; void mark() { flags |= 2; } };
struct Tex : Iface {
  Bits bits; char pc[60];
  Vec a; Vec b; Vec c;
  void setA(const Vec &v) { a = v; bits.mark(); }
  void setB(const Vec &v) { b = v; bits.mark(); }
  void setC(const Vec &v) { c = v; bits.mark(); }
};
struct Mod : Iface {};
struct Inst : Iface { char p4[32]; Str name; char p28[8]; Ref<Iface> tex; };
struct Item : Iface { virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual const Str &text(); };
struct Holder { char p0[20]; Iface *value; };
struct Reg : Iface { virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19(); virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24(); virtual void a25(); virtual void a26(); virtual Holder *find(unsigned char *); };
struct Attr { char p0[20]; int b; int a; };
struct Desc : Iface { char p4[32]; unsigned short opts; char p26[10]; Ref<Iface> clip; Attr *attr; };
struct Clip : Iface {};
struct Self;
struct Rig : Iface { virtual void a3(); virtual void attach(Iface *); virtual void a5(); virtual void a6(); virtual void add36(Iface *); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void mode(int); virtual void a13(); virtual Iface *clip(); virtual void a15(); virtual void callback(void (*)(void *, void *, void *), void *); };
struct Hook : Iface { virtual void a3(); virtual void on(void *, void (*)(void *, void *), int); };
struct Conn : Iface { virtual void a3(); virtual void attach(Iface *); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual Hook *hook(); };
struct Fl { unsigned top : 1; unsigned bit30 : 1; unsigned bit29 : 1; unsigned a : 1; unsigned b : 1; unsigned c : 1; unsigned d : 1; unsigned e : 1; };
struct Self {
  void *vt; int p4; int flags; Vec c; Vec b; Vec a; int z48; char p34[64]; Ref<Desc> desc; Ref<Inst> inst; char p7c[40]; int z164; Iface *r168; char pac[8]; Fl fl; Ref<Iface> r184; Ref<Iface> clip; Ref<Rig> r192; Ref<Rig> r196; float z200;
};
extern "C" Desc *w3d_empty_80341348(void *);
extern "C" void w3d_mesh_instance_collect(Self *, Iface *);
extern "C" Iface *w3d_mesh_descriptor_get_clip(Desc *);
extern "C" int fn_801804c8(void *, int, void *);
extern "C" int fn_80180804(void *, void *);
extern Reg *lbl_804ab5fc;
extern int lbl_804ab628;
extern Iface *lbl_804b01c4;
extern char lbl_804144f8[], lbl_80414970[], lbl_80414940[], lbl_80413b28[], lbl_80414850[], lbl_80417000[], lbl_80413368[], lbl_80413418[], lbl_80414ae0[], lbl_80362984[];
extern "C" int d31j_init_mesh_instance_801809d4(Self *self, Item *item, unsigned char kind) {
  int hr = w3d_auto_80179aec(self, item, kind);
  if (hr < 0) return hr;
  self->r196 = 0;
  self->r192 = 0;
  self->inst = 0;
  self->clip = 0;
  Desc *desc = w3d_empty_80341348(item);
  self->inst = (Inst *)w3d_s10_service_forward_8020b680(lbl_804144f8);
  Ref<Tex> tex;
  if (desc->opts & 16) tex = (Tex *)w3d_s10_service_forward_8020b680(lbl_80414970);
  else tex = (Tex *)w3d_s10_service_forward_8020b680(lbl_80414940);
  Str name;
  Str *pn = &name;
  w3d_string_default(pn);
  w3d_string_format(pn, "Instance-%s", item->text().p);
  {
    Inst *ni = self->inst.p;
    ni->name = name;
  }
  self->a.set(1.0f);
  self->c.set(0.0f);
  self->b.set(0.0f);
  tex->setA(self->a);
  tex->setC(self->c);
  tex->setB(self->b);
  self->inst->tex = *(Ref<Iface> *)&tex;
  self->desc = desc;
  Ref<Iface> clip(desc->clip.p);
  w3d_mesh_instance_collect(self, clip.p);
  self->clip = w3d_mesh_descriptor_get_clip(desc);
  self->fl.a = desc->opts & 1;
  self->fl.b = (desc->opts >> 1) & 1;
  self->fl.c = (desc->opts >> 3) & 1;
  if (desc->attr) {
    self->fl.d = desc->attr->a;
    self->fl.e = desc->attr->b;
  }
  if (self->clip.p) goto on;
  if (self->fl.a) goto on;
  if (self->fl.b) goto on;
  if (self->r168) {
    on:
    Ref<Rig> n((Rig *)w3d_s10_service_forward_8020b680(lbl_80413b28));
    n->mode(1);
    n->callback((void (*)(void *, void *, void *))fn_801804c8, self);
    n->attach(clip.p);
    clip = n->clip();
    if (self->fl.a) {
      self->r184 = (Iface *)w3d_s10_service_forward_8020b680(lbl_80414850);
      Ref<Conn> c((Conn *)w3d_s10_service_forward_8020b680(lbl_80417000));
      Ref<Hook> h(c->hook());
      h->on(lbl_80362984, (void (*)(void *, void *))fn_80180804, 0);
      lbl_804b01c4 = self->r184.p;
      c->attach(clip.p);
    }
    if (self->clip.p) {
      self->r192 = (Rig *)w3d_s10_service_forward_8020b680(lbl_80413368);
      self->r196 = (Rig *)w3d_s10_service_forward_8020b680(lbl_80413418);
      self->r192->attach(self->clip.p);
      self->r192->add36(clip.p);
      self->r196->attach(self->r192.p);
    }
    w3d_auto_801f2798(&self->r168);
    w3d_mesh_instance_collect(self, clip.p);
    self->fl.top = 1;
  } else {
    self->fl.top = 0;
  }
  if (self->fl.c) {
    Ref<Inst> m((Inst *)w3d_s10_service_forward_8020b680(lbl_804144f8));
    Ref<Iface> g((Iface *)w3d_s10_service_forward_8020b680(lbl_80414ae0));
    m->tex = g;
    w3d_k5b_iface_array_field_append_801ef174(m.p, 44, 3, clip.p);
    clip = m.p;
  }
  w3d_k5b_iface_array_field_append_801ef174(self->inst.p, 44, 3, clip.p);
  {
    Ref<Iface> r(lbl_804ab5fc->find(&kind)->value);
    w3d_k5b_iface_array_field_append_801ef174(r.p, 44, 3, self->inst.p);
self->flags |= 1; self->z164 = 1; self->fl.bit30 = 0; self->fl.bit29 = 0; self->z48 = 0; self->z200 = 0.0f;    lbl_804ab628++;
  }
  return 0;
}

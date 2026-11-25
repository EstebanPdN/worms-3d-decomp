// Initialise an object instance from a source resource: run the base
// initialiser, hold the item, optionally convert the source image through the
// converter service, create the instance and its texture state named
// Instance-<item>, copy its three colours, link the image and register the
// instance with the type holder for its kind. GWMP8P rev0 0x80174bcc.
struct Src;
extern "C" {
void *w3d_s10_service_forward_8020b680(void *);
int w3d_auto_80179aec(void *, void *, unsigned char);
char *strcat(char *, const char *);
char *strcpy(char *, const char *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
void w3d_string_release_header(void *);
Src *w3d_empty_8034bf48(void *);
void w3d_k5b_iface_array_field_append_801ef174(void *, int, int, void *);
}
struct Iface { virtual void a0(); virtual void add(); virtual void release(); };
template <class T> struct Ref {
  T *p;
  Ref() {}
  Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  T *operator->() { return p; }
  void assign(T *q) { if (q) q->add(); if (p) p->release(); p = q; }
  Ref &operator=(T *q) { if (q) q->add(); if (p) p->release(); p = q; return *this; }
  Ref &operator=(const Ref &o) { T *old = p; p = o.p; if (p) p->add(); if (old) old->release(); return *this; }
};
struct Str {
  char *p;
  Str(const char *);
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
struct Inst : Iface { char p4[32]; Str name; char p28[8]; Ref<Tex> tex; };
struct Item : Iface { virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual const Str &text(); };
struct Holder { char p0[20]; Iface *value; };
struct Reg : Iface { virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19(); virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24(); virtual void a25(); virtual void a26(); virtual Holder *find(unsigned char *); };
extern Reg *lbl_804ab5fc;
extern int lbl_804ab59c;
extern char lbl_804144f8[], lbl_80414940[], lbl_80413b28[], lbl_80364694[];
struct Conv : Iface { virtual void s20(); virtual void set(Iface *); virtual void s28(); virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52(); virtual void mode(int); virtual void s60(); virtual Iface *result(); virtual void format(void *); };
struct Src { char p0[40]; Iface *image; unsigned short opts; };
struct Self {
  void *vt; int p4; int flags; Vec c; Vec b; Vec a; int p30; char p34[64]; Ref<Item> item; Ref<Inst> inst; char p7c[44]; int on; int off;
};
extern "C" int d30j_init_instance_converted_80174bcc(Self *self, Item *item, unsigned char kind) {
  int hr = w3d_auto_80179aec(self, item, kind);
  if (hr < 0) return hr;
  self->item = item;
  Src *src = w3d_empty_8034bf48(item);
  Ref<Iface> img(src->image);
  int on = src->opts & 1;
  if (on) {
    Ref<Conv> c((Conv *)w3d_s10_service_forward_8020b680(lbl_80413b28));
    c->mode(2);
    c->format(lbl_80364694);
    c->set(img.p);
    img.assign(c->result());
    self->on = 1;
  } else self->on = on;
  self->inst = (Inst *)w3d_s10_service_forward_8020b680(lbl_804144f8);
  {
    Ref<Tex> tex((Tex *)w3d_s10_service_forward_8020b680(lbl_80414940));
    char buf[256];
    strcpy(buf, "Instance-");
    strcat(buf, item->text().p);
    self->inst->name = Str(buf);
    tex->setA(self->a);
    tex->setC(self->c);
    tex->setB(self->b);
    self->inst->tex = tex;
    w3d_k5b_iface_array_field_append_801ef174(self->inst.p, 44, 3, img.p);
    {
      Ref<Iface> reg(lbl_804ab5fc->find(&kind)->value);
      w3d_k5b_iface_array_field_append_801ef174(reg.p, 44, 3, self->inst.p);
      self->flags |= 1;
      self->p30 = 0;
      lbl_804ab59c++;
    }
  }
  return 0;
}

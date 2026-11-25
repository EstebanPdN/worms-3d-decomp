// Initialise a mesh resource instance: hold the item, clear the work buffer,
// create the instance, its modifier and texture state, fetch the shared geometry
// and link them, register with the type holder for its kind, reset the colours
// and copy them to the texture state. GWMP8P rev0 0x8018bf18.
struct Src;
extern "C" {
void *w3d_s10_service_forward_8020b680(void *);
int w3d_auto_80179aec(void *, void *, unsigned char);
char *strcat(char *, const char *);
char *strcpy(char *, const char *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
void w3d_string_release_header(void *);
Src *w3d_empty_8034435c(void *);
struct Geo;
Geo *w3d_s21_fetch_801ea470(void *);
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
extern int lbl_804ab6b0;
extern Str lbl_804b06a0[];
extern char lbl_804144f8[], lbl_80414940[], lbl_80414b30[];
extern "C" void *fn_802eee50(void *, const void *, ...);
struct Src { char p0[40]; void *res; char p2c[16]; unsigned short opts; };
struct Mod : Iface { char p4[80]; unsigned char blend; };
struct Geo : Iface { char p4[44]; Ref<Mod> mod; Ref<Iface> ref52; };
struct Clr { char *a; char *b; };
struct Self {
  void *vt; int p4; int flags; Vec c; Vec b; Vec a; int p30; char p34[64]; Ref<Iface> item; Ref<Inst> inst; char p7c[44]; Ref<Iface> ref168; Ref<Mod> mod; Ref<Geo> geo; Clr clr; char pbc[4]; int z192; char pc4[40]; int z236; int fl240; int p244; Str name;
};
extern "C" int d30j_init_instance_mesh_8018bf18(Self *self, Item *item, unsigned char kind) {
  int hr = w3d_auto_80179aec(self, item, kind);
  if (hr < 0) return hr;
  self->item = (Iface *)w3d_empty_8034435c(item);
  {
    Clr *v = &self->clr;
    char *s = v->a;
    char *e = v->b;
    int n = e - s;
    fn_802eee50(s, e, 0);
    v->b -= n;
  }
  self->inst = (Inst *)w3d_s10_service_forward_8020b680(lbl_804144f8);
  self->mod = (Mod *)w3d_s10_service_forward_8020b680(lbl_80414b30);
  {
    Ref<Tex> tex((Tex *)w3d_s10_service_forward_8020b680(lbl_80414940));
    if (w3d_empty_8034435c(item)->opts & 1024) self->mod->blend = 1;
    self->inst->tex = tex;
    self->geo = w3d_s21_fetch_801ea470(w3d_empty_8034435c(self->item.p)->res);
    self->ref168 = self->geo->ref52.p;
    self->geo->mod = self->mod;
    w3d_k5b_iface_array_field_append_801ef174(self->inst.p, 44, 3, self->geo.p);
    {
      Ref<Iface> reg(lbl_804ab5fc->find(&kind)->value);
      w3d_k5b_iface_array_field_append_801ef174(reg.p, 44, 3, self->inst.p);
      self->flags |= 1;
      self->c.set(0.0f);
      self->b.set(0.0f);
      self->a.set(1.0f);
      self->p30 = 0;
      self->z192 = 0;
      self->z236 = 0;
      self->name = lbl_804b06a0[0];
      self->fl240 = (w3d_empty_8034435c(self->item.p)->opts >> 9) & 1;
      tex->setC(self->c);
      tex->setB(self->b);
      tex->setA(self->a);
      lbl_804ab6b0++;
    }
  }
  return 0;
}

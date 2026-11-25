// Constructor of a render object: on the first instance it fetches thirteen
// shared service objects into reference-counted globals, sets their parameters
// and flags, and names one state object. Then it fills its own colours, zeros
// and fade limits and counts the instance. The base constructor 0x801902e8
// returns the object. GWMP8P rev0 0x80189afc.
inline void *operator new(unsigned int, void *p) { return p; }
extern "C" void *fn_801902e8(void *);
struct Iface { virtual void a0(); virtual void add(); virtual void release(); };
struct Bits { char p0[7]; unsigned char flags; void mark2() { flags |= 2; } void mark1() { flags |= 1; } };
struct Obj : Iface {
  Bits bits; char pc[12]; int f24, f28, f32, f36; char p28[12]; int f52;
  void set24(int v) { f24 = v; bits.mark2(); } void set28(int v) { f28 = v; bits.mark2(); } void set32(int v) { f32 = v; bits.mark2(); } void set36(int v) { f36 = v; bits.mark2(); } void set52(int v) { f52 = v; bits.mark2(); }
};
struct Cfg : Iface {
  virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11();
  virtual void setA(int); virtual void a13(); virtual void setB(int); virtual void a15(); virtual void a16(); virtual void a17();
  virtual void setName(const char *, int);
};
template <class T> struct Ref { T *p; T *operator->() { return p; }
  Ref &operator=(T *q) { if (q) q->add(); if (p) p->release(); p = q; return *this; } };
struct Color { unsigned char r, g, b, a;
  Color(unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_) { r = r_; g = g_; b = b_; a = a_; } };
extern "C" void *fn_8020b680(const void *);
extern int lbl_804b18a8;
extern void *vt_80412ee0[];
extern const char type_80413db0[];
extern const char type_80414210[];
extern const char type_80414260[];
extern const char type_80415bb0[];
extern const char type_80415c00[];
extern const char type_80415c10[];
extern const char type_80415c30[];
extern const char type_80415c80[];
extern const char type_80415cb0[];
extern const char type_804166b0[];
extern const char type_80416750[];
extern Ref<Obj> lbl_804b0238;
extern Ref<Obj> lbl_804b023c;
extern Ref<Obj> lbl_804b0240;
extern Ref<Obj> lbl_804b0244;
extern Ref<Obj> lbl_804b0248;
extern Ref<Obj> lbl_804b024c;
extern Ref<Obj> lbl_804b0250;
extern Ref<Obj> lbl_804b0254;
extern Ref<Obj> lbl_804b0258;
extern Ref<Obj> lbl_804b025c;
extern Ref<Obj> lbl_804b0264;
extern Ref<Obj> lbl_804b0268;
extern Ref<Cfg> lbl_804b0260;
extern Ref<Cfg> lbl_804b026c;
struct Self { void **vt; char p4[28]; void *z32; void *z36; void *z40; float k44, k48; Color c52; Color c56; unsigned short z60; int z64, z68, z72;
  void init();
};
extern const float lbl_803a7c54[], lbl_803a7c58[];
extern const char lbl_803a7c40[];
extern "C" Self *d32j_setup_shared_render_state_v2_80189afc(Self *self) {
  fn_801902e8(self);
  self->vt = vt_80412ee0;
  self->z32 = 0; self->z36 = 0; self->z40 = 0;
  if (lbl_804b18a8 == 0) {
    { const char *t = type_80415c10; lbl_804b0238 = (Obj *)fn_8020b680(t);
    lbl_804b023c = (Obj *)fn_8020b680(t); }
    lbl_804b0240 = (Obj *)fn_8020b680(type_80415c80);
    lbl_804b0244 = (Obj *)fn_8020b680(type_80415bb0);
    { const char *t = type_80415cb0; lbl_804b0248 = (Obj *)fn_8020b680(t);
    lbl_804b024c = (Obj *)fn_8020b680(t); }
    lbl_804b0250 = (Obj *)fn_8020b680(type_80415c30);
    { const char *t = type_80415c00; lbl_804b0254 = (Obj *)fn_8020b680(t);
    lbl_804b0258 = (Obj *)fn_8020b680(t); }
    lbl_804b025c = (Obj *)fn_8020b680(type_804166b0);
    lbl_804b0264 = (Obj *)fn_8020b680(type_80414210);
    lbl_804b0268 = (Obj *)fn_8020b680(type_80416750);
    lbl_804b0260 = (Cfg *)fn_8020b680(type_80414260);
    lbl_804b0238->set32(3);
    lbl_804b0238->set36(1);
    lbl_804b0238->bits.mark1();
    lbl_804b023c->set32(7);
    lbl_804b023c->set36(1);
    lbl_804b023c->bits.mark1();
    lbl_804b0240->set52(0);
    lbl_804b0240->bits.mark1();
    lbl_804b0244->set28(4);
    lbl_804b0244->set32(1);
    lbl_804b0244->bits.mark1();
    lbl_804b0248->set28(6);
    lbl_804b0248->set24(7);
    lbl_804b0248->bits.mark1();
    lbl_804b024c->set28(6);
    lbl_804b024c->set24(1);
    lbl_804b024c->bits.mark1();
    lbl_804b0250->set24(0);
    lbl_804b0250->bits.mark1();
    lbl_804b0254->set24(0);
    lbl_804b0254->bits.mark1();
    lbl_804b0258->set24(1);
    lbl_804b0258->bits.mark1();
    lbl_804b0260->setA(1);
    lbl_804b026c = (Cfg *)fn_8020b680(type_80413db0);
    lbl_804b026c->setB(1);
    lbl_804b026c->setName(lbl_803a7c40, 5);
  }
  self->z60 = 0;
  self->z64 = 0;
  self->z68 = 0;
  self->z72 = 0;
  new (&self->c52) Color(255, 255, 255, 255);
  new (&self->c56) Color(0, 0, 0, 255);
  self->k44 = lbl_803a7c54[0];
  self->k48 = lbl_803a7c58[0];
  lbl_804b18a8++;
  return self;
}

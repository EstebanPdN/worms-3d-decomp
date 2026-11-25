// d41x: 0x8017b9c8. Constructor of the scene bin manager: clears tables,
// makes 64 named scene bins and reads the GRM limits. The class is named
// after its table. Names inferred. Flags: -fvtable-thunks.
#include "compat/stlport_sn_oom.h"
#include <vector>
extern "C" void fn_8020c5c4(void *);
extern "C" void fn_80341588(void *);
extern "C" void fn_8020bb2c(void *);
struct Iface { virtual void a0(); virtual void add(); virtual void release(); };
extern "C" void fn_8020bb54(void *, const char *);
struct Str {
  char *text;
  Str() {}
  Str *init();
  Str(const Str &);
  ~Str() { Str *t = this; fn_8020c5c4(t); fn_80341588(t); }
  Str &operator=(const char *);
  Str &operator=(const Str &o) {
    ++*(unsigned short *)(o.text - 6);
    unsigned short *h = (unsigned short *)(text - 6);
    if (--*h == 0) fn_8020bb2c(h);
    text = o.text;
    return *this;
  }
};
template <class T> struct Ref { T *p; Ref() : p(0) {} T *operator->() { return p; }
  Ref &operator=(T *q) { if (q) q->add(); if (p) p->release(); p = q; return *this; } };
// One word with a user copy constructor: block mode, so its slot at 288 is 8 bytes
// and sp+292 is simply that slot's rounding, not padding.
struct NameTemp { char *text; NameTemp() {} NameTemp(const NameTemp &); NameTemp *make(const char *p);
  void assignTo(Str &d) { d = *(Str *)this; } void drop() { fn_8020c5c4(this); fn_80341588(this); } };
struct Slot { Str name; short id; char pad[2]; Slot() { name.init(); name = (const char *)0; id = -1; } };
struct Named : Iface { char p4[32]; Str name; };
struct Pool : Iface {
  virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
  virtual void addNamed(Named *, char *);
};
struct CtxI : Iface { virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual Pool *find(const void *); };
struct Tagged { unsigned pointer : 24; unsigned kind : 8; };
struct Head { unsigned short a, b; Tagged w; Head() { w.kind = 2; w.pointer = 0; } void clr() { a = 0; b = 0; } };
struct Entity : Iface { char p4[16]; Named *owner; unsigned char tag24, tag25;
  void setOwner(Named *n) { Named *old = owner; owner = n; if (n) n->add(); if (old) old->release(); } };
extern "C" void *fn_8020b680(const void *);
extern "C" CtxI *fn_8020b648();
extern "C" int fn_8034cb64(char *, const char *, ...);
extern "C" int fn_80206920(const char *, int *);
extern const char type_804144e8[], type_804149f0[], type_804190e0[], type_804164c0[];
extern Ref<Entity> tab_80456f14[];
extern int t_804a89d8[], t_804a8bd8[], t_804a8dd8[];
struct SceneBins_804127a0;
extern SceneBins_804127a0 *lbl_804ab5fc;
extern int lbl_804ab5e4, lbl_804ab5e8, lbl_804ab5ec, lbl_804ab5f0, lbl_804ab5f4, lbl_804ab5f8;
// Element type of the three vectors is not visible here; V is a partial view.
struct V { int x; };
typedef std::vector<V> Vec;
extern void *vt_80412870[], *vt_804127a0[];
struct Pair { int a, b; Pair() { a = 0; b = 0; } };
struct Root { virtual void vf0(); };
struct Base : Root {
  virtual void vf0();
  Head h; Pair z;
  Base() { h.clr(); }
};
struct SceneBins_804127a0 : Base {
  virtual void vf0();
  unsigned b0 : 1; unsigned b1 : 1; unsigned b2 : 1; unsigned rest : 29;
  Ref<Entity> refs[1920];
  Slot slots[256];
  int z9752;
  Vec v0, v1, v2;
  int z9804; char p9808[4];
  Ref<Pool> pool; Ref<Iface> svc;
  Str s0, s1;
  char p9828[8]; unsigned short c[7];
  SceneBins_804127a0();
};
extern "C" int fn_8017d55c(SceneBins_804127a0 *, int, int, int);
extern "C" int fn_8017dfb4(SceneBins_804127a0 *, int, int);
extern "C" int fn_8017dcc0(SceneBins_804127a0 *, int, unsigned short);

inline void SetName2(Named *o, const Str &t) { o->name = t; }
inline Pool *Find(const void *t) { return fn_8020b648()->find(t); }
SceneBins_804127a0::SceneBins_804127a0() {
  s0.init();
  s1.init();
  lbl_804ab5fc = this;
  for (unsigned i = 0; i <= 255; i++) { slots[i].name = (const char *)0; slots[i].id = -1; }
  for (unsigned i = 0; i <= 1919; i++) { refs[i] = 0; }
  for (unsigned i = 0; i < 128; i++) { t_804a89d8[i] = 0; t_804a8bd8[i] = 0; t_804a8dd8[i] = 0; }
  pool = Find(type_804190e0);
  char buf[256];
  for (unsigned n = 0; n <= 63; n++) {
    Named *o = (Named *)fn_8020b680(type_804144e8);
    char *p = buf;
    fn_8034cb64(p, "Scene Bin %d", n);
    NameTemp tmp;
    NameTemp *pt = &tmp;
    pt->make(p);
    o->name = *(Str *)&tmp;
    pt->drop();
    pool->addNamed(o, buf);
    tab_80456f14[n] = (Entity *)fn_8020b680(type_804149f0);
    tab_80456f14[n]->setOwner(o);
    unsigned char t2 = n << 1;
    tab_80456f14[n]->tag25 = t2;
    tab_80456f14[n]->tag24 = n * 2 + 1;
  }
  b0 = 0; b1 = 0;
  z9752 = 0;
  fn_8017d55c(this, 0, 0, 0);
  lbl_804ab5e4 = 0; lbl_804ab5e8 = 0; lbl_804ab5ec = 0; lbl_804ab5f0 = 0; lbl_804ab5f4 = 0; lbl_804ab5f8 = 0; c[0] = 0; c[1] = 0; c[2] = 0; c[3] = 0; c[4] = 0; c[5] = 0; c[6] = 0; z9804 = 0; b2 = 0;
  fn_8017dfb4(this, 0, 63);
  svc = (Iface *)fn_8020b680(type_804164c0);
  int v;
  if (fn_80206920("GRM.MaxBitmaps", &v) >= 0) fn_8017dcc0(this, 0, v);
  if (fn_80206920("GRM.MaxMeshes", &v) >= 0) fn_8017dcc0(this, 1, v);
  if (fn_80206920("GRM.MaxCustom", &v) >= 0) fn_8017dcc0(this, 2, v);
  if (fn_80206920("GRM.MaxSpriteSets", &v) >= 0) fn_8017dcc0(this, 3, v);
  if (fn_80206920("GRM.MaxParticleSets", &v) >= 0) fn_8017dcc0(this, 4, v);
  if (fn_80206920("GRM.MaxText", &v) >= 0) fn_8017dcc0(this, 5, v);
  if (fn_80206920("GRM.MaxNulls", &v) >= 0) fn_8017dcc0(this, 6, v);
}

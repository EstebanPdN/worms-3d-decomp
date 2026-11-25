#include "w3d_ptr.h"
// Port (v29): los huecos viven en core/native/tabla_recursos.cpp (4096 en vez de 1920).
extern "C" Ptr32<void> *w3d_restab_slots(void);
extern "C" unsigned w3d_restab_cap(void);
#line 1 "d41x_scene_bins_ctor_8017b9c8.cpp"
// d41x: 0x8017b9c8. Constructor of the scene bin manager: clears tables,
// makes 64 named scene bins and reads the GRM limits. The class is named
// after its table. Names inferred. Flags: -fvtable-thunks.
#include "compat/stlport_sn_oom.h"
#include <vector>
extern "C" void fn_8020c5c4(Ptr32<void>);
extern "C" void fn_80341588(Ptr32<void>);
extern "C" void fn_8020bb2c(Ptr32<void>);
struct Iface { void w3d_r_a0() __asm__(W3D_SYM("_ZN5Iface2a0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
extern "C" void fn_8020bb54(Ptr32<void>, Ptr32<const char>);
struct Str {
  Ptr32<char> text;
  Str() {}
  Ptr32<Str> init();
  Str(const Str &);
  ~Str() { Ptr32<Str> t = this; fn_8020c5c4(t); fn_80341588(t); }
  template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((const char *)w3d_p.get()); }
 Str &operator=(const char *);
  Str &operator=(const Str &o) {
    ++*(Ptr32<unsigned short>)(o.text - 6);
    Ptr32<unsigned short> h = (Ptr32<unsigned short>)(text - 6);
    if (--*h == 0) fn_8020bb2c(h);
    text = o.text;
    return *this;
  }
};
template <class T> struct Ref { Ptr32<T> p; Ref() : p(0) {} Ptr32<T> operator->() { return p; }
  template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((T *)w3d_p.get()); }
 Ref &operator=(T *q) { if (q) q->add(); if (p) p->release(); p = q; return *this; } };
// One word with a user copy constructor: block mode, so its slot at 288 is 8 bytes
// and sp+292 is simply that slot's rounding, not padding.
struct NameTemp { Ptr32<char> text; NameTemp() {} NameTemp(const NameTemp &); Ptr32<NameTemp> make(Ptr32<const char> p);
  void assignTo(Str &d) { d = *(Ptr32<Str>)this; } void drop() { fn_8020c5c4(this); fn_80341588(this); } };
struct Slot { Str name; short id; char pad[2]; Slot() { name.init(); name = (Ptr32<const char>)0; id = -1; } };
struct Named : Iface { char p4[32] __attribute__((aligned(__alignof__(Iface)))); Str name; };
struct Pool : Iface {
  void w3d_r_a3() __asm__(W3D_SYM("_ZN4Pool2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN4Pool2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN4Pool2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN4Pool2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN4Pool2a7Ev"));
  void w3d_r_addNamed(Ptr32<Named>, Ptr32<char>) __asm__(W3D_SYM("_ZN4Pool8addNamedEP5NamedPc"));
 __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void addNamed(Ptr32<Named> w3d_a0, Ptr32<char> w3d_a1) { ((void (*)(w3d_u32, Ptr32<Named>, Ptr32<char>))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this), w3d_a0, w3d_a1); } };
struct CtxI : Iface { void w3d_r_s3() __asm__(W3D_SYM("_ZN4CtxI2s3Ev")); void w3d_r_s4() __asm__(W3D_SYM("_ZN4CtxI2s4Ev")); void w3d_r_s5() __asm__(W3D_SYM("_ZN4CtxI2s5Ev")); void w3d_r_s6() __asm__(W3D_SYM("_ZN4CtxI2s6Ev")); void w3d_r_s7() __asm__(W3D_SYM("_ZN4CtxI2s7Ev")); void w3d_r_s8() __asm__(W3D_SYM("_ZN4CtxI2s8Ev")); void w3d_r_s9() __asm__(W3D_SYM("_ZN4CtxI2s9Ev")); void w3d_r_s10() __asm__(W3D_SYM("_ZN4CtxI3s10Ev")); void w3d_r_s11() __asm__(W3D_SYM("_ZN4CtxI3s11Ev")); void w3d_r_s12() __asm__(W3D_SYM("_ZN4CtxI3s12Ev")); void w3d_r_s13() __asm__(W3D_SYM("_ZN4CtxI3s13Ev")); void w3d_r_s14() __asm__(W3D_SYM("_ZN4CtxI3s14Ev")); void w3d_r_s15() __asm__(W3D_SYM("_ZN4CtxI3s15Ev")); void w3d_r_s16() __asm__(W3D_SYM("_ZN4CtxI3s16Ev")); void w3d_r_s17() __asm__(W3D_SYM("_ZN4CtxI3s17Ev")); void w3d_r_s18() __asm__(W3D_SYM("_ZN4CtxI3s18Ev")); void w3d_r_s19() __asm__(W3D_SYM("_ZN4CtxI3s19Ev")); void w3d_r_s20() __asm__(W3D_SYM("_ZN4CtxI3s20Ev")); Ptr32<Pool> w3d_r_find(Ptr32<const void>) __asm__(W3D_SYM("_ZN4CtxI4findEPKv"));  __attribute__((always_inline)) inline void s3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s19() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Pool> find(Ptr32<const void> w3d_a0) { return ((Ptr32<Pool> (*)(w3d_u32, Ptr32<const void>))w3d::vfn(this->w3d_vptr_Iface, 23))(w3d::h2g(this), w3d_a0); } };
struct Tagged { unsigned int kind:8; unsigned int pointer:24; };
struct Head { unsigned short a, b; Tagged w; Head() { w.kind = 2; w.pointer = 0; } void clr() { a = 0; b = 0; } };
struct Entity : Iface { char p4[16] __attribute__((aligned(__alignof__(Iface)))); Ptr32<Named> owner; unsigned char tag24, tag25;
  void setOwner(Ptr32<Named> n) { Ptr32<Named> old = owner; owner = n; if (n) n->add(); if (old) old->release(); } };
extern "C" Ptr32<void> fn_8020b680(Ptr32<const void>);
extern "C" Ptr32<CtxI> fn_8020b648();
extern "C" int fn_8034cb64(Ptr32<char>, Ptr32<const char>, ...);
extern "C" int fn_80206920(Ptr32<const char>, Ptr32<int>);
extern const char type_804144e8[], type_804149f0[], type_804190e0[], type_804164c0[];
extern Ref<Entity> tab_80456f14[];
extern int t_804a89d8[], t_804a8bd8[], t_804a8dd8[];
struct SceneBins_804127a0;
extern Ptr32<SceneBins_804127a0> lbl_804ab5fc;
extern int lbl_804ab5e4, lbl_804ab5e8, lbl_804ab5ec, lbl_804ab5f0, lbl_804ab5f4, lbl_804ab5f8;
// Element type of the three vectors is not visible here; V is a partial view.
struct V { int x; };
typedef std::vector<V> Vec;
extern Ptr32<void> vt_80412870[]; extern Ptr32<void> vt_804127a0[];
struct Pair { int a, b; Pair() { a = 0; b = 0; } };
struct Root { void w3d_r_vf0() __asm__(W3D_SYM("_ZN4Root3vf0Ev"));  __attribute__((always_inline)) inline void vf0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Root, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Root;  Root() { W3D_SET_VPTR(this->w3d_vptr_Root, w3d_vt___vt_4Root, "__vt_4Root"); } };
struct Base : Root {
  void w3d_r_vf0() __asm__(W3D_SYM("_ZN4Base3vf0Ev"));
  Head h __attribute__((aligned(__alignof__(Root)))); Pair z;
  Base() { W3D_SET_VPTR(this->Root::w3d_vptr_Root, w3d_vt___vt_4Base, "__vt_4Base");  h.clr(); }
 __attribute__((always_inline)) inline void vf0() { this->Root::vf0(); } };
struct SceneBins_804127a0 : Base {
  void w3d_r_vf0() __asm__(W3D_SYM("_ZN18SceneBins_804127a03vf0Ev"));
  unsigned int rest:29; unsigned int b2:1; unsigned int b1:1; unsigned int b0:1;
  Ref<Entity> refs[1920];
  Slot slots[256];
  int z9752;
  Vec v0, v1, v2;
  int z9804; char p9808[4];
  Ref<Pool> pool; Ref<Iface> svc;
  Str s0, s1;
  char p9828[8]; unsigned short c[7];
  SceneBins_804127a0();
 __attribute__((always_inline)) inline void vf0() { this->Base::vf0(); } };
extern "C" int fn_8017d55c(Ptr32<SceneBins_804127a0>, int, int, int);
extern "C" int fn_8017dfb4(Ptr32<SceneBins_804127a0>, int, int);
extern "C" int fn_8017dcc0(Ptr32<SceneBins_804127a0>, int, unsigned short);

inline void SetName2(Ptr32<Named> o, const Str &t) { o->name = t; }
inline Ptr32<Pool> Find(Ptr32<const void> t) { return fn_8020b648()->find(t); }
SceneBins_804127a0::SceneBins_804127a0() { W3D_SET_VPTR(this->Base::w3d_vptr_Root, w3d_vt___vt_18SceneBins_804127a0, "__vt_18SceneBins_804127a0"); 
  s0.init();
  s1.init();
  lbl_804ab5fc = this;
  for (unsigned i = 0; i <= 255; i++) { slots[i].name = (Ptr32<const char>)0; slots[i].id = -1; }
  for (unsigned i = 0; i <= 1919; i++) { refs[i] = 0; }
  { Ptr32<void> *n = w3d_restab_slots(); for (unsigned i = 0; i < w3d_restab_cap(); i++) n[i] = 0; }   // port (v29): tabla nativa
  for (unsigned i = 0; i < 128; i++) { t_804a89d8[i] = 0; t_804a8bd8[i] = 0; t_804a8dd8[i] = 0; }
  pool = Find(type_804190e0);
  char buf[256];
  for (unsigned n = 0; n <= 63; n++) {
    Ptr32<Named> o = (Ptr32<Named>)fn_8020b680(type_804144e8);
    Ptr32<char> p = buf;
    fn_8034cb64(p, "Scene Bin %d", n);
    NameTemp tmp;
    Ptr32<NameTemp> pt = &tmp;
    pt->make(p);
    o->name = *(Ptr32<Str>)&tmp;
    pt->drop();
    pool->addNamed(o, buf);
    tab_80456f14[n] = (Ptr32<Entity>)fn_8020b680(type_804149f0);
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
  svc = (Ptr32<Iface>)fn_8020b680(type_804164c0);
  int v;
  if (fn_80206920("GRM.MaxBitmaps", &v) >= 0) fn_8017dcc0(this, 0, v);
  if (fn_80206920("GRM.MaxMeshes", &v) >= 0) fn_8017dcc0(this, 1, v);
  if (fn_80206920("GRM.MaxCustom", &v) >= 0) fn_8017dcc0(this, 2, v);
  if (fn_80206920("GRM.MaxSpriteSets", &v) >= 0) fn_8017dcc0(this, 3, v);
  if (fn_80206920("GRM.MaxParticleSets", &v) >= 0) fn_8017dcc0(this, 4, v);
  if (fn_80206920("GRM.MaxText", &v) >= 0) fn_8017dcc0(this, 5, v);
  if (fn_80206920("GRM.MaxNulls", &v) >= 0) fn_8017dcc0(this, 6, v);
}



#include "w3d_ptr.h"
#line 1 "d32j_setup_shared_render_state_v2_80189afc.cpp"
// Constructor of a render object: on the first instance it fetches thirteen
// shared service objects into reference-counted globals, sets their parameters
// and flags, and names one state object. Then it fills its own colours, zeros
// and fade limits and counts the instance. The base constructor 0x801902e8
// returns the object. GWMP8P rev0 0x80189afc.
inline void *operator new(__SIZE_TYPE__, void *p) { return p; }
extern "C" Ptr32<void> fn_801902e8(Ptr32<void>);
struct Iface { void w3d_r_a0() __asm__(W3D_SYM("_ZN5Iface2a0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
struct Bits { char p0[4]; unsigned char flags; char w3d_tag_rest[3]; void mark2() { flags |= 2; } void mark1() { flags |= 1; } };
struct Obj : Iface {
  Bits bits __attribute__((aligned(__alignof__(Iface)))); char pc[12]; int f24, f28, f32, f36; char p28[12]; int f52;
  void set24(int v) { f24 = v; bits.mark2(); } void set28(int v) { f28 = v; bits.mark2(); } void set32(int v) { f32 = v; bits.mark2(); } void set36(int v) { f36 = v; bits.mark2(); } void set52(int v) { f52 = v; bits.mark2(); }
};
struct Cfg : Iface {
  void w3d_r_a3() __asm__(W3D_SYM("_ZN3Cfg2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN3Cfg2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN3Cfg2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN3Cfg2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN3Cfg2a7Ev")); void w3d_r_a8() __asm__(W3D_SYM("_ZN3Cfg2a8Ev")); void w3d_r_a9() __asm__(W3D_SYM("_ZN3Cfg2a9Ev")); void w3d_r_a10() __asm__(W3D_SYM("_ZN3Cfg3a10Ev")); void w3d_r_a11() __asm__(W3D_SYM("_ZN3Cfg3a11Ev"));
  void w3d_r_setA(int) __asm__(W3D_SYM("_ZN3Cfg4setAEi")); void w3d_r_a13() __asm__(W3D_SYM("_ZN3Cfg3a13Ev")); void w3d_r_setB(int) __asm__(W3D_SYM("_ZN3Cfg4setBEi")); void w3d_r_a15() __asm__(W3D_SYM("_ZN3Cfg3a15Ev")); void w3d_r_a16() __asm__(W3D_SYM("_ZN3Cfg3a16Ev")); void w3d_r_a17() __asm__(W3D_SYM("_ZN3Cfg3a17Ev"));
  void w3d_r_setName(Ptr32<const char>, int) __asm__(W3D_SYM("_ZN3Cfg7setNameEPKci"));
 __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void setA(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void a13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void setB(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Iface, 16))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void a15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void setName(Ptr32<const char> w3d_a0, int w3d_a1) { ((void (*)(w3d_u32, Ptr32<const char>, int))w3d::vfn(this->w3d_vptr_Iface, 20))(w3d::h2g(this), w3d_a0, w3d_a1); } };
template <class T> struct Ref { Ptr32<T> p; Ptr32<T> operator->() { return p; }
  template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((T *)w3d_p.get()); }
 Ref &operator=(T *q) { if (q) q->add(); if (p) p->release(); p = q; return *this; } };
struct Color { unsigned char r, g, b, a;
  Color(unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_) { r = r_; g = g_; b = b_; a = a_; } };
extern "C" Ptr32<void> fn_8020b680(Ptr32<const void>);
extern int lbl_804b18a8;
extern Ptr32<void> vt_80412ee0[];
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
struct Self { Ptr32<Ptr32<void>> vt; char p4[28]; Ptr32<void> z32; Ptr32<void> z36; Ptr32<void> z40; float k44, k48; Color c52; Color c56; unsigned short z60; int z64, z68, z72;
  void init();
};
extern const float lbl_803a7c54[], lbl_803a7c58[];
extern const char lbl_803a7c40[];
extern "C" Ptr32<Self> d32j_setup_shared_render_state_v2_80189afc(Ptr32<Self> self) {
  fn_801902e8(self);
  self->vt = vt_80412ee0;
  self->z32 = 0; self->z36 = 0; self->z40 = 0;
  if (lbl_804b18a8 == 0) {
    { Ptr32<const char> t = type_80415c10; lbl_804b0238 = (Ptr32<Obj>)fn_8020b680(t);
    lbl_804b023c = (Ptr32<Obj>)fn_8020b680(t); }
    lbl_804b0240 = (Ptr32<Obj>)fn_8020b680(type_80415c80);
    lbl_804b0244 = (Ptr32<Obj>)fn_8020b680(type_80415bb0);
    { Ptr32<const char> t = type_80415cb0; lbl_804b0248 = (Ptr32<Obj>)fn_8020b680(t);
    lbl_804b024c = (Ptr32<Obj>)fn_8020b680(t); }
    lbl_804b0250 = (Ptr32<Obj>)fn_8020b680(type_80415c30);
    { Ptr32<const char> t = type_80415c00; lbl_804b0254 = (Ptr32<Obj>)fn_8020b680(t);
    lbl_804b0258 = (Ptr32<Obj>)fn_8020b680(t); }
    lbl_804b025c = (Ptr32<Obj>)fn_8020b680(type_804166b0);
    lbl_804b0264 = (Ptr32<Obj>)fn_8020b680(type_80414210);
    lbl_804b0268 = (Ptr32<Obj>)fn_8020b680(type_80416750);
    lbl_804b0260 = (Ptr32<Cfg>)fn_8020b680(type_80414260);
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
    lbl_804b026c = (Ptr32<Cfg>)fn_8020b680(type_80413db0);
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



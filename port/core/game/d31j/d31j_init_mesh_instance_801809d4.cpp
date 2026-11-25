#include "w3d_ptr.h"
#line 1 "d31j_init_mesh_instance_801809d4.cpp"
// Initialises a mesh instance from its descriptor: resets references, builds the
// instance and texture, copies the clip and option bits, and optionally builds
// rig, hook and skin nodes. GWMP8P rev0 0x801809d4.
extern "C" {
Ptr32<void> w3d_s10_service_forward_8020b680(Ptr32<void>);
int w3d_auto_80179aec(Ptr32<void>, Ptr32<void>, unsigned char);
Ptr32<void> w3d_string_default(Ptr32<void>);
void w3d_string_format(Ptr32<void>, Ptr32<const char>, ...);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
void w3d_string_release_header(Ptr32<void>);
void w3d_k5b_iface_array_field_append_801ef174(Ptr32<void>, int, int, Ptr32<void>);
void w3d_auto_801f2798(Ptr32<void>);
}
struct Iface { void w3d_r_a0() __asm__(W3D_SYM("_ZN5Iface2a0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
template <class T> struct Ref {
  Ptr32<T> p;
  Ref() { p = 0; }
  template <class W3dU> Ref<T>(Ptr32<W3dU> w3d_p) : Ref<T>((T *)w3d_p.get()) {}
 Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  Ptr32<T> operator->() { return p; }
  template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((T *)w3d_p.get()); }
 Ref &operator=(T *q) { if (q) q->add(); if (p) p->release(); p = q; return *this; }
  Ref &operator=(const Ref &o) { Ptr32<T> old = p; p = o.p; if (p) p->add(); if (old) old->release(); return *this; }
};
struct Str {
  Ptr32<char> p;
  Str() {}
  Str(const Str &);
  ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
  Str &operator=(const Str &o) {
    ++*(Ptr32<unsigned short>)(o.p - 6);
    Ptr32<unsigned short> h = (Ptr32<unsigned short>)(p - 6);
    if (--*h == 0) w3d_string_release_header(h);
    p = o.p;
    return *this;
  }
};
struct Vec { float x, y, z; void set(float f) { x = f; y = f; z = f; } };
struct Bits { char p0[4]; unsigned char flags; char w3d_tag_rest[3]; void mark() { flags |= 2; } };
struct Tex : Iface {
  Bits bits __attribute__((aligned(__alignof__(Iface)))); char pc[60];
  Vec a; Vec b; Vec c;
  void setA(const Vec &v) { a = v; bits.mark(); }
  void setB(const Vec &v) { b = v; bits.mark(); }
  void setC(const Vec &v) { c = v; bits.mark(); }
};
struct Mod : Iface {};
struct Inst : Iface { char p4[32] __attribute__((aligned(__alignof__(Iface)))); Str name; char p28[8]; Ref<Iface> tex; };
struct Item : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN4Item2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN4Item2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN4Item2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN4Item2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN4Item2a7Ev")); void w3d_r_a8() __asm__(W3D_SYM("_ZN4Item2a8Ev")); void w3d_r_a9() __asm__(W3D_SYM("_ZN4Item2a9Ev")); void w3d_r_a10() __asm__(W3D_SYM("_ZN4Item3a10Ev")); void w3d_r_a11() __asm__(W3D_SYM("_ZN4Item3a11Ev")); void w3d_r_a12() __asm__(W3D_SYM("_ZN4Item3a12Ev")); void w3d_r_a13() __asm__(W3D_SYM("_ZN4Item3a13Ev")); void w3d_r_a14() __asm__(W3D_SYM("_ZN4Item3a14Ev")); const Str &w3d_r_text() __asm__(W3D_SYM("_ZN4Item4textEv"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline const Str &text() { return *(const Str *)w3d::g2h(((w3d_u32 (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 17))(w3d::h2g(this))); } };
struct Holder { char p0[20]; Ptr32<Iface> value; };
struct Reg : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN3Reg2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN3Reg2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN3Reg2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN3Reg2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN3Reg2a7Ev")); void w3d_r_a8() __asm__(W3D_SYM("_ZN3Reg2a8Ev")); void w3d_r_a9() __asm__(W3D_SYM("_ZN3Reg2a9Ev")); void w3d_r_a10() __asm__(W3D_SYM("_ZN3Reg3a10Ev")); void w3d_r_a11() __asm__(W3D_SYM("_ZN3Reg3a11Ev")); void w3d_r_a12() __asm__(W3D_SYM("_ZN3Reg3a12Ev")); void w3d_r_a13() __asm__(W3D_SYM("_ZN3Reg3a13Ev")); void w3d_r_a14() __asm__(W3D_SYM("_ZN3Reg3a14Ev")); void w3d_r_a15() __asm__(W3D_SYM("_ZN3Reg3a15Ev")); void w3d_r_a16() __asm__(W3D_SYM("_ZN3Reg3a16Ev")); void w3d_r_a17() __asm__(W3D_SYM("_ZN3Reg3a17Ev")); void w3d_r_a18() __asm__(W3D_SYM("_ZN3Reg3a18Ev")); void w3d_r_a19() __asm__(W3D_SYM("_ZN3Reg3a19Ev")); void w3d_r_a20() __asm__(W3D_SYM("_ZN3Reg3a20Ev")); void w3d_r_a21() __asm__(W3D_SYM("_ZN3Reg3a21Ev")); void w3d_r_a22() __asm__(W3D_SYM("_ZN3Reg3a22Ev")); void w3d_r_a23() __asm__(W3D_SYM("_ZN3Reg3a23Ev")); void w3d_r_a24() __asm__(W3D_SYM("_ZN3Reg3a24Ev")); void w3d_r_a25() __asm__(W3D_SYM("_ZN3Reg3a25Ev")); void w3d_r_a26() __asm__(W3D_SYM("_ZN3Reg3a26Ev")); Ptr32<Holder> w3d_r_find(Ptr32<unsigned char>) __asm__(W3D_SYM("_ZN3Reg4findEPh"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a19() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a21() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a22() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a23() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a25() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a26() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Holder> find(Ptr32<unsigned char> w3d_a0) { return ((Ptr32<Holder> (*)(w3d_u32, Ptr32<unsigned char>))w3d::vfn(this->w3d_vptr_Iface, 29))(w3d::h2g(this), w3d_a0); } };
struct Attr { char p0[20]; int b; int a; };
struct Desc : Iface { char p4[32] __attribute__((aligned(__alignof__(Iface)))); unsigned short opts; char p26[10]; Ref<Iface> clip; Ptr32<Attr> attr; };
struct Clip : Iface {};
struct Self;
struct Rig : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN3Rig2a3Ev")); void w3d_r_attach(Ptr32<Iface>) __asm__(W3D_SYM("_ZN3Rig6attachEP5Iface")); void w3d_r_a5() __asm__(W3D_SYM("_ZN3Rig2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN3Rig2a6Ev")); void w3d_r_add36(Ptr32<Iface>) __asm__(W3D_SYM("_ZN3Rig5add36EP5Iface")); void w3d_r_a8() __asm__(W3D_SYM("_ZN3Rig2a8Ev")); void w3d_r_a9() __asm__(W3D_SYM("_ZN3Rig2a9Ev")); void w3d_r_a10() __asm__(W3D_SYM("_ZN3Rig3a10Ev")); void w3d_r_a11() __asm__(W3D_SYM("_ZN3Rig3a11Ev")); void w3d_r_mode(int) __asm__(W3D_SYM("_ZN3Rig4modeEi")); void w3d_r_a13() __asm__(W3D_SYM("_ZN3Rig3a13Ev")); Ptr32<Iface> w3d_r_clip() __asm__(W3D_SYM("_ZN3Rig4clipEv")); void w3d_r_a15() __asm__(W3D_SYM("_ZN3Rig3a15Ev")); void w3d_r_callback(Ptr32<void (Ptr32<void>, Ptr32<void>, Ptr32<void>)>, Ptr32<void>) __asm__(W3D_SYM("_ZN3Rig8callbackEPFvPvS0_S0_ES0_"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void attach(Ptr32<Iface> w3d_a0) { ((void (*)(w3d_u32, Ptr32<Iface>))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add36(Ptr32<Iface> w3d_a0) { ((void (*)(w3d_u32, Ptr32<Iface>))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void mode(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void a13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Iface> clip() { return ((Ptr32<Iface> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void callback(Ptr32<void (Ptr32<void>, Ptr32<void>, Ptr32<void>)> w3d_a0, Ptr32<void> w3d_a1) { ((void (*)(w3d_u32, Ptr32<void (Ptr32<void>, Ptr32<void>, Ptr32<void>)>, Ptr32<void>))w3d::vfn(this->w3d_vptr_Iface, 18))(w3d::h2g(this), w3d_a0, w3d_a1); } };
struct Hook : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN4Hook2a3Ev")); void w3d_r_on(Ptr32<void>, Ptr32<void (Ptr32<void>, Ptr32<void>)>, int) __asm__(W3D_SYM("_ZN4Hook2onEPvPFvS0_S0_Ei"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void on(Ptr32<void> w3d_a0, Ptr32<void (Ptr32<void>, Ptr32<void>)> w3d_a1, int w3d_a2) { ((void (*)(w3d_u32, Ptr32<void>, Ptr32<void (Ptr32<void>, Ptr32<void>)>, int))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); } };
struct Conn : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN4Conn2a3Ev")); void w3d_r_attach(Ptr32<Iface>) __asm__(W3D_SYM("_ZN4Conn6attachEP5Iface")); void w3d_r_a5() __asm__(W3D_SYM("_ZN4Conn2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN4Conn2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN4Conn2a7Ev")); void w3d_r_a8() __asm__(W3D_SYM("_ZN4Conn2a8Ev")); Ptr32<Hook> w3d_r_hook() __asm__(W3D_SYM("_ZN4Conn4hookEv"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void attach(Ptr32<Iface> w3d_a0) { ((void (*)(w3d_u32, Ptr32<Iface>))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Hook> hook() { return ((Ptr32<Hook> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); } };
struct Fl { unsigned int :24; unsigned int e:1; unsigned int d:1; unsigned int c:1; unsigned int b:1; unsigned int a:1; unsigned int bit29:1; unsigned int bit30:1; unsigned int top:1; };
struct Self {
  Ptr32<void> vt; int p4; int flags; Vec c; Vec b; Vec a; int z48; char p34[64]; Ref<Desc> desc; Ref<Inst> inst; char p7c[40]; int z164; Ptr32<Iface> r168; char pac[8]; Fl fl; Ref<Iface> r184; Ref<Iface> clip; Ref<Rig> r192; Ref<Rig> r196; float z200;
};
extern "C" Ptr32<Desc> w3d_empty_80341348(Ptr32<void>);
extern "C" void w3d_mesh_instance_collect(Ptr32<Self>, Ptr32<Iface>);
extern "C" Ptr32<Iface> w3d_mesh_descriptor_get_clip(Ptr32<Desc>);
extern "C" int fn_801804c8(Ptr32<void>, int, Ptr32<void>);
extern "C" int fn_80180804(Ptr32<void>, Ptr32<void>);
extern Ptr32<Reg> lbl_804ab5fc;
extern int lbl_804ab628;
extern Ptr32<Iface> lbl_804b01c4;
extern char lbl_804144f8[], lbl_80414970[], lbl_80414940[], lbl_80413b28[], lbl_80414850[], lbl_80417000[], lbl_80413368[], lbl_80413418[], lbl_80414ae0[], lbl_80362984[];
extern "C" int d31j_init_mesh_instance_801809d4(Ptr32<Self> self, Ptr32<Item> item, unsigned char kind) {
  int hr = w3d_auto_80179aec(self, item, kind);
  if (hr < 0) return hr;
  self->r196 = 0;
  self->r192 = 0;
  self->inst = 0;
  self->clip = 0;
  Ptr32<Desc> desc = w3d_empty_80341348(item);
  self->inst = (Ptr32<Inst>)w3d_s10_service_forward_8020b680(lbl_804144f8);
  Ref<Tex> tex;
  if (desc->opts & 16) tex = (Ptr32<Tex>)w3d_s10_service_forward_8020b680(lbl_80414970);
  else tex = (Ptr32<Tex>)w3d_s10_service_forward_8020b680(lbl_80414940);
  Str name;
  Ptr32<Str> pn = &name;
  w3d_string_default(pn);
  w3d_string_format(pn, "Instance-%s", w3d::VA(item->text().p));
  {
    Ptr32<Inst> ni = self->inst.p;
    ni->name = name;
  }
  self->a.set(1.0f);
  self->c.set(0.0f);
  self->b.set(0.0f);
  tex->setA(self->a);
  tex->setC(self->c);
  tex->setB(self->b);
  self->inst->tex = *(Ptr32<Ref < Iface >>)&tex;
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
    Ref<Rig> n((Ptr32<Rig>)w3d_s10_service_forward_8020b680(lbl_80413b28));
    n->mode(1);
    n->callback((Ptr32<void (Ptr32<void>, Ptr32<void>, Ptr32<void>)>)fn_801804c8, self);
    n->attach(clip.p);
    clip = n->clip();
    if (self->fl.a) {
      self->r184 = (Ptr32<Iface>)w3d_s10_service_forward_8020b680(lbl_80414850);
      Ref<Conn> c((Ptr32<Conn>)w3d_s10_service_forward_8020b680(lbl_80417000));
      Ref<Hook> h(c->hook());
      h->on(lbl_80362984, (Ptr32<void (Ptr32<void>, Ptr32<void>)>)fn_80180804, 0);
      lbl_804b01c4 = self->r184.p;
      c->attach(clip.p);
    }
    if (self->clip.p) {
      self->r192 = (Ptr32<Rig>)w3d_s10_service_forward_8020b680(lbl_80413368);
      self->r196 = (Ptr32<Rig>)w3d_s10_service_forward_8020b680(lbl_80413418);
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
    Ref<Inst> m((Ptr32<Inst>)w3d_s10_service_forward_8020b680(lbl_804144f8));
    Ref<Iface> g((Ptr32<Iface>)w3d_s10_service_forward_8020b680(lbl_80414ae0));
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



#include "w3d_ptr.h"
#line 1 "d31j_build_material_image_grid_80170bac.cpp"
// Builds a sprite grid for a material slot: image, texture, material, UV and
// step arrays. GWMP8P rev0 0x80170bac.
extern "C" {
Ptr32<void> w3d_s10_service_forward_8020b680(Ptr32<void>);
void w3d_string_base_init(Ptr32<void>);
Ptr32<unsigned short> w3d_string_header(Ptr32<void>);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
void w3d_string_release_header(Ptr32<void>);
void w3d_k5b_iface_array_field_append_801ef174(Ptr32<void>, int, int, Ptr32<void>);
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
  template <class U> Ref &operator=(const Ref<U> &o) { if (o.p) o.p->add(); if (p) p->release(); p = o.p; return *this; }
};
struct Str {
  Ptr32<char> p;
  template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *);
  Str(const Str &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
  Str &operator=(const Str &o) {
    ++*(Ptr32<unsigned short>)(o.p - 6);
    Ptr32<unsigned short> h = (Ptr32<unsigned short>)(p - 6);
    if (--*h == 0) w3d_string_release_header(h);
    p = o.p;
    return *this;
  }
};
inline void use(Str) {}
extern "C" Ptr32<void> fn_802eee50(Ptr32<void>, Ptr32<const void>, ...);
struct Vec2 { float x, y; float &Y() { return y; } };
struct Vec { float x, y, z; };
struct Sphere { Vec c; float r; };
struct Box { Vec lo; Vec hi; };
struct Blob { char p0[4]; unsigned short kind; char p6[18]; int count; unsigned short locks; char p1e[2]; char data[1]; };
struct Handle;
extern "C" Ptr32<void> w3d_k5b_array_ref_lock_801ef048(Ptr32<Handle>, int, int, int);
struct Handle {
  Ptr32<Blob> b;
  Ptr32<Vec2> lock(int n, int stride) {
    Ptr32<Blob> x = b;
    if (x->kind == 1 && n == x->count) { x->locks++; return (Ptr32<Vec2>)x->data; }
    return (Ptr32<Vec2>)w3d_k5b_array_ref_lock_801ef048(this, n, stride, 1);
  }
};
struct Bits { char p0[4]; unsigned char flags; char w3d_tag_rest[3]; void mark() { flags |= 4; } };
struct Tex : Iface { char p4[40] __attribute__((aligned(__alignof__(Iface)))); unsigned short w; unsigned short h; };
struct Image : Iface { char p4[16] __attribute__((aligned(__alignof__(Iface)))); Str name; char p18[12]; Handle st; Handle uv; };
struct Mat : Iface { char p4[32] __attribute__((aligned(__alignof__(Iface)))); int z36; int z40; char p2c[12]; int z56; Ref<Tex> tex; char p40[16]; int z80; };
struct Cfg : Iface { void w3d_r_s20() __asm__(W3D_SYM("_ZN3Cfg3s20Ev")); void w3d_r_set(Ptr32<Tex>) __asm__(W3D_SYM("_ZN3Cfg3setEP3Tex")); void w3d_r_s28() __asm__(W3D_SYM("_ZN3Cfg3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN3Cfg3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN3Cfg3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN3Cfg3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN3Cfg3s44Ev")); void w3d_r_s48() __asm__(W3D_SYM("_ZN3Cfg3s48Ev")); void w3d_r_s52() __asm__(W3D_SYM("_ZN3Cfg3s52Ev")); void w3d_r_setWrap(int) __asm__(W3D_SYM("_ZN3Cfg7setWrapEi")); void w3d_r_s60() __asm__(W3D_SYM("_ZN3Cfg3s60Ev")); void w3d_r_setMip(int) __asm__(W3D_SYM("_ZN3Cfg6setMipEi")); void w3d_r_s68() __asm__(W3D_SYM("_ZN3Cfg3s68Ev")); void w3d_r_s72() __asm__(W3D_SYM("_ZN3Cfg3s72Ev")); void w3d_r_s76() __asm__(W3D_SYM("_ZN3Cfg3s76Ev")); void w3d_r_setName(Ptr32<const char>, int) __asm__(W3D_SYM("_ZN3Cfg7setNameEPKci")); void w3d_r_s84() __asm__(W3D_SYM("_ZN3Cfg3s84Ev")); void w3d_r_s88() __asm__(W3D_SYM("_ZN3Cfg3s88Ev")); void w3d_r_s92() __asm__(W3D_SYM("_ZN3Cfg3s92Ev")); void w3d_r_s96() __asm__(W3D_SYM("_ZN3Cfg3s96Ev")); void w3d_r_s100() __asm__(W3D_SYM("_ZN3Cfg4s100Ev")); void w3d_r_s104() __asm__(W3D_SYM("_ZN3Cfg4s104Ev")); void w3d_r_s108() __asm__(W3D_SYM("_ZN3Cfg4s108Ev")); void w3d_r_s112() __asm__(W3D_SYM("_ZN3Cfg4s112Ev")); void w3d_r_s116() __asm__(W3D_SYM("_ZN3Cfg4s116Ev")); void w3d_r_s120() __asm__(W3D_SYM("_ZN3Cfg4s120Ev")); void w3d_r_s124() __asm__(W3D_SYM("_ZN3Cfg4s124Ev")); void w3d_r_s128() __asm__(W3D_SYM("_ZN3Cfg4s128Ev")); void w3d_r_s132() __asm__(W3D_SYM("_ZN3Cfg4s132Ev")); void w3d_r_s136() __asm__(W3D_SYM("_ZN3Cfg4s136Ev")); void w3d_r_s140() __asm__(W3D_SYM("_ZN3Cfg4s140Ev")); void w3d_r_setFilter(int) __asm__(W3D_SYM("_ZN3Cfg9setFilterEi"));  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void set(Ptr32<Tex> w3d_a0) { ((void (*)(w3d_u32, Ptr32<Tex>))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void setWrap(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void s60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void setMip(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Iface, 16))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void s68() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s72() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s76() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void setName(Ptr32<const char> w3d_a0, int w3d_a1) { ((void (*)(w3d_u32, Ptr32<const char>, int))w3d::vfn(this->w3d_vptr_Iface, 20))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline void s84() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s88() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s92() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s96() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s100() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s104() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s108() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s112() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s116() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 29))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s120() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 30))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s124() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 31))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s128() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 32))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s132() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 33))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s136() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 34))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s140() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 35))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void setFilter(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Iface, 36))(w3d::h2g(this), w3d_a0); } };
struct Mod : Iface { Bits bits __attribute__((aligned(__alignof__(Iface)))); char p4[8]; Box box; int z44; void setBox(const Box &v) { box = v; } };
struct Geo : Iface { void setBound(const Sphere &v) { bound = v; } char p4[16] __attribute__((aligned(__alignof__(Iface)))); Sphere bound; Str name; int z40; char p2c[4]; Ref<Mod> mod; Ref<Image> image; };
struct Inst : Iface { void setBound(const Sphere &v) { bound = v; } char p4[16] __attribute__((aligned(__alignof__(Iface)))); Sphere bound; Str name; int z40; };
struct Loader : Iface { void w3d_r_s20() __asm__(W3D_SYM("_ZN6Loader3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN6Loader3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN6Loader3s28Ev")); int w3d_r_load(Ptr32<char>, Ptr32<Ref < Tex >>) __asm__(W3D_SYM("_ZN6Loader4loadEPcP3RefI3TexE"));  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int load(Ptr32<char> w3d_a0, Ptr32<Ref < Tex >> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<char>, Ptr32<Ref < Tex >>))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this), w3d_a0, w3d_a1); } };
struct Root : Iface { void w3d_r_s20() __asm__(W3D_SYM("_ZN4Root3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN4Root3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN4Root3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN4Root3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN4Root3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN4Root3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN4Root3s44Ev")); void w3d_r_s48() __asm__(W3D_SYM("_ZN4Root3s48Ev")); void w3d_r_s52() __asm__(W3D_SYM("_ZN4Root3s52Ev")); void w3d_r_s56() __asm__(W3D_SYM("_ZN4Root3s56Ev")); void w3d_r_s60() __asm__(W3D_SYM("_ZN4Root3s60Ev")); void w3d_r_s64() __asm__(W3D_SYM("_ZN4Root3s64Ev")); void w3d_r_s68() __asm__(W3D_SYM("_ZN4Root3s68Ev")); void w3d_r_s72() __asm__(W3D_SYM("_ZN4Root3s72Ev")); void w3d_r_s76() __asm__(W3D_SYM("_ZN4Root3s76Ev")); void w3d_r_s80() __asm__(W3D_SYM("_ZN4Root3s80Ev")); void w3d_r_s84() __asm__(W3D_SYM("_ZN4Root3s84Ev")); void w3d_r_s88() __asm__(W3D_SYM("_ZN4Root3s88Ev")); Ptr32<Loader> w3d_r_loader(Ptr32<void>) __asm__(W3D_SYM("_ZN4Root6loaderEPv"));  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s64() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s68() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s72() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s76() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s80() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s84() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s88() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Loader> loader(Ptr32<void> w3d_a0) { return ((Ptr32<Loader> (*)(w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_Iface, 23))(w3d::h2g(this), w3d_a0); } };
extern "C" Ptr32<Root> w3d_auto_8020b648();
struct Sink : Iface { void w3d_r_s20() __asm__(W3D_SYM("_ZN4Sink3s20Ev")); int w3d_r_attach(Ptr32<Iface>) __asm__(W3D_SYM("_ZN4Sink6attachEP5Iface"));  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int attach(Ptr32<Iface> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<Iface>))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this), w3d_a0); } };
struct Self {
  char p0[20]; Str name; union { int flags; struct { char w3d_gap0[2]; unsigned char kind; char f0; } b; }; char p1c[4]; Ptr32<char> path; unsigned short cols; unsigned short rows; unsigned short cw; unsigned short ch; unsigned short tw; unsigned short th; unsigned short count; unsigned short opts; char p34[24]; Ref<Image> img;
};
extern "C" Ptr32<Mod> w3d_s20_get_selected_material_80172088(Ptr32<Self>, unsigned char);
extern "C" int fn_801720fc(Ptr32<Self>, unsigned char);
extern "C" int w3d_auto_80171b1c(Ptr32<Self>, int);
extern "C" int w3d_auto_80171ab8(Ptr32<Self>, int);
extern "C" int w3d_auto_80171b80(Ptr32<Self>, int);
extern "C" Ptr32<void> w3d_auto_801d0858(Ptr32<Image>, Ptr32<int>);
extern "C" void w3d_auto_801d086c(Ptr32<Image>, Ptr32<Mat>);
extern "C" void w3d_auto_801d0898(Ptr32<Image>, Ptr32<Mat>, int);
extern "C" void w3d_cx13b_sphere_bounds_801f5724(Ptr32<Box>, Ptr32<Sphere>);
extern Ptr32<void> lbl_804b012c; extern Ptr32<void> lbl_804b0130; extern Ptr32<void> lbl_804b013c;
struct SinkP { Ptr32<Sink> p; };
extern char lbl_80415b50[], lbl_804143e0[], lbl_80413db0[], lbl_80415d60[], lbl_80414518[], lbl_80414600[], lbl_804144f8[];
inline Ptr32<Loader> get_loader(Ptr32<void> type) { return w3d_auto_8020b648()->loader(type); }
inline void bind(Ptr32<Image> i, Ptr32<Mat> m) {
  int on;
  w3d_auto_801d0858(i, &on);
  if (on) w3d_auto_801d0898(i, m, 0); else w3d_auto_801d086c(i, m);
}
extern const int lbl_803a65d0[5]; // {11, 13, 12, 19, 20}
extern "C" int d31j_build_material_image_grid_80170bac(Ptr32<Self> self) {
  int on = (self->flags >> 15) & 1;
  if (on) return 0x80004005;
  self->img = (Ptr32<Image>)w3d_s10_service_forward_8020b680(lbl_80415b50);
  Ptr32<Loader> l = get_loader(lbl_804143e0);
  Ref<Tex> tex;
  Str path(self->path);
  {
    Ptr32<Image> ip = self->img.p;
    ip->name = Str(self->path);
  }
  if (l->load(path.p, &tex) < 0) {
    use(path), use(self->name);
    return 0x80004005;
  }
  Ref<Mat> m((Ptr32<Mat>)w3d_s10_service_forward_8020b680(lbl_80415d60));
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
  Ptr32<Vec2> a = self->img->uv.lock(self->count, 8);
  Ptr32<Vec2> b = self->img->st.lock(self->count, 8);
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
    Ref<Cfg> c((Ptr32<Cfg>)w3d_s10_service_forward_8020b680(lbl_80413db0));
    c->setWrap(4);
    c->setFilter(0);
    c->setMip(1);
    c->setName((Ptr32<const char>)lbl_803a65d0, 5);
    c->set(tex.p);
  }
  return 0;
}



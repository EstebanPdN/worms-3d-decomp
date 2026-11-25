#include "w3d_ptr.h"
#line 1 "d30e_load_tga_resource_801b44f8.cpp"
// (Worms 3D GameCube PAL, 0x801b44f8).
//
// Loads a texture resource from a file: opens the file through the file
// service (slot 4), reads its size via slot 7 into a stat record, creates a
// buffer entry of that size, reads the file into it, and for a tga extension
// decodes through the codec service 0x804165e0 into a new object of type
// 0x80364fa4, then stores the object through out and its name string at +36.
// Returns the failure code of the reads or 0x80004005.

struct String;
extern "C" void w3d_string_base_finish(Ptr32<String>);
extern "C" void w3d_string_release(Ptr32<String>);
extern "C" void w3d_string_release_header(Ptr32<void>);
struct String {
  Ptr32<char> p;
  template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
  String(const String &);
  ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
  String &operator=(const String &o) {
    ++*(Ptr32<unsigned short>)(o.p - 6);
    Ptr32<unsigned short> h = (Ptr32<unsigned short>)(p - 6);
    if (--*h == 0) w3d_string_release_header(h);
    p = o.p;
    return *this;
  }
};
struct Obj { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Obj2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Obj6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN3Obj7ReleaseEv")); int w3d_r_v20(Ptr32<void>, int, int) __asm__(W3D_SYM("_ZN3Obj3v20EPvii")); int w3d_r_v24(Ptr32<const char>, int, Ptr32<void>) __asm__(W3D_SYM("_ZN3Obj3v24EPKciPv")); void w3d_r_v5() __asm__(W3D_SYM("_ZN3Obj2v5Ev")),w3d_r_v6() __asm__(W3D_SYM("_ZN3Obj2v6Ev")); void w3d_r_v36(Ptr32<void>) __asm__(W3D_SYM("_ZN3Obj3v36EPv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int v20(Ptr32<void> w3d_a0, int w3d_a1, int w3d_a2) { return ((int (*)(w3d_u32, Ptr32<void>, int, int))w3d::vfn(this->w3d_vptr_Obj, 5))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  __attribute__((always_inline)) inline int v24(Ptr32<const char> w3d_a0, int w3d_a1, Ptr32<void> w3d_a2) { return ((int (*)(w3d_u32, Ptr32<const char>, int, Ptr32<void>))w3d::vfn(this->w3d_vptr_Obj, 6))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v36(Ptr32<void> w3d_a0) { ((void (*)(w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_Obj, 9))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Obj; };
struct Buf { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Buf2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Buf6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN3Buf7ReleaseEv")); void w3d_r_v3() __asm__(W3D_SYM("_ZN3Buf2v3Ev")),w3d_r_v4() __asm__(W3D_SYM("_ZN3Buf2v4Ev")),w3d_r_v5() __asm__(W3D_SYM("_ZN3Buf2v5Ev")); void w3d_r_v32(int) __asm__(W3D_SYM("_ZN3Buf3v32Ei")); void w3d_r_v36() __asm__(W3D_SYM("_ZN3Buf3v36Ev")); int w3d_r_v40(Ptr32<void>) __asm__(W3D_SYM("_ZN3Buf3v40EPv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Buf, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Buf, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Buf, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Buf, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Buf, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Buf, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v32(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Buf, 8))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void v36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Buf, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int v40(Ptr32<void> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_Buf, 10))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Buf; };
struct Out : Obj { char q[32] __attribute__((aligned(__alignof__(Obj)))); String name; };
template <class T> struct Ref {
  Ptr32<T> p;
  Ref() { p = 0; }
  template <class W3dU> Ref<T>(Ptr32<W3dU> w3d_p) : Ref<T>((T *)w3d_p.get()) {}
 Ref(T *o) { p = o; if (p) p->AddRef(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->Release(); }
  template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((T *)w3d_p.get()); }
 Ref &operator=(T *o) { if (o) o->AddRef(); if (p) p->Release(); p = o; return *this; }
};
struct Self;
struct Stat { int size; int a, b, c; };
struct Dec { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Dec2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Dec6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN3Dec7ReleaseEv")); int w3d_r_v20(Ptr32<Buf>, Ptr32<Out>) __asm__(W3D_SYM("_ZN3Dec3v20EP3BufP3Out"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dec, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dec, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dec, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int v20(Ptr32<Buf> w3d_a0, Ptr32<Out> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<Buf>, Ptr32<Out>))w3d::vfn(this->w3d_vptr_Dec, 5))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_Dec; };
extern char lbl_803aab64[], lbl_804165e0[], lbl_80364fa4[];
extern "C" Ptr32<char> strrchr(Ptr32<const char>, int);
extern "C" int w3d_d24z_strcasecmp_802ef074(Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<Obj> w3d_auto_801b4938(Ptr32<Self>);
extern "C" Ptr32<Buf> w3d_s10_create_entry_80208aac(int);
extern "C" Ptr32<Obj> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern "C" Ptr32<Out> w3d_r24b_invoke_ready_callback_8020fcb4(Ptr32<void>);
extern "C" int w3d_d30e_load_tga_resource_801b44f8(Ptr32<Self> self, Ptr32<const char> name, Ptr32<Ptr32<Out>> out) {
  *out = 0;
  Ref<Obj> fs(w3d_auto_801b4938(self));
  Ref<Out> a;
  int result;
  {
    Ref<Buf> b;
    Ref<Obj> c;
    int hr = fs.p->v24(name, 1, &c.p);
    if (hr < 0) return hr;
    Stat st;
    c.p->v36(&st);
    Ptr32<Buf> n = w3d_s10_create_entry_80208aac(1);
    b = n;
    n->v32(st.size);
    Ptr32<void> data[3];
    n->v40(&data[0]);
    hr = c.p->v20(data[0], st.size, 0);
    if (hr < 0) return hr;
    c = 0;
    Ptr32<const char> ext = strrchr(name, '.');
    if (ext && !w3d_d24z_strcasecmp_802ef074(ext + 1, lbl_803aab64)) c = w3d_s10_service_forward_8020b680(lbl_804165e0);
    if (!c.p) return 0x80004005;
    Ptr32<Out> na = w3d_r24b_invoke_ready_callback_8020fcb4(lbl_80364fa4);
    a = na;
    result = ((Ptr32<Dec>)c.p)->v20(b.p, na);
  }
  if (result < 0) return 0x80004005;
  *out = a.p;
  a.p->AddRef();
  Ptr32<Out> o = a.p;
  o->name = String(name);
  return 0;
}



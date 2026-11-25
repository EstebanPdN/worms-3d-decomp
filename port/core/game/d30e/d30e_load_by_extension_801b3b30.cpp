#include "w3d_ptr.h"
#line 1 "d30e_load_by_extension_801b3b30.cpp"
// (Worms 3D GameCube PAL, 0x801b3b30).
//
// Loads a resource by name: returns a cached entry found in either name
// table, otherwise dispatches on the extension: TGA, TIF and TIFF through
// virtual slot 6, RTG through slot 7, XOM by opening the tagged reader and a
// stream, then testing the root's type chain against 0x80364fa4 and
// 0x80362704 and calling slots 4 or 5. Returns the failure code of each
// step, 0x80004005 for an unknown root and 0x80070057 for an unknown
// extension. Names are inferred.

struct TypeInfo { char p[20]; Ptr32<TypeInfo> parent; };
static inline bool isA(Ptr32<TypeInfo> self, Ptr32<TypeInfo> base) {
  Ptr32<TypeInfo> t = self;
  while (t != base) {
    Ptr32<TypeInfo> n = t->parent;
    if (t == n) return false;
    t = n;
  }
  return true;
}
extern TypeInfo lbl_80364fa4[], lbl_80362704[];
struct Obj { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Obj2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Obj6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN3Obj7ReleaseEv")); Ptr32<TypeInfo> w3d_r_type() __asm__(W3D_SYM("_ZN3Obj4typeEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<TypeInfo> type() { return ((Ptr32<TypeInfo> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Obj; };
struct Stream { void w3d_r_v0() __asm__(W3D_SYM("_ZN6Stream2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN6Stream6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN6Stream7ReleaseEv")); void w3d_r_attach(int) __asm__(W3D_SYM("_ZN6Stream6attachEi")); void w3d_r_v4() __asm__(W3D_SYM("_ZN6Stream2v4Ev")),w3d_r_v5() __asm__(W3D_SYM("_ZN6Stream2v5Ev")); int w3d_r_seek(int, int) __asm__(W3D_SYM("_ZN6Stream4seekEii"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void attach(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Stream, 5))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int seek(int w3d_a0, int w3d_a1) { return ((int (*)(w3d_u32, int, int))w3d::vfn(this->w3d_vptr_Stream, 8))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_Stream; };
struct Tagged { int w[5]; int value; Tagged(); ~Tagged(); int refill(Ptr32<const char>, int); int data() { return value; } };
struct Ref { Ptr32<Stream> p; template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Stream *)w3d_p.get()) {}
 Ref(Stream *o) { p = o; if (p) p->AddRef(); } Ref(const Ref &); ~Ref() { if (p) p->Release(); } };
extern char lbl_803aaab8[], lbl_803aaabc[], lbl_803aaac0[], lbl_803aaac8[], lbl_803aaacc[];
extern "C" Ptr32<char> strrchr(Ptr32<const char>, int);
extern "C" int w3d_d24z_strcasecmp_802ef074(Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<Stream> w3d_auto_8020b6c0();
extern "C" int w3d_auto_801ffea8(Ptr32<TypeInfo>);
struct Loader;
extern "C" int w3d_s10_find_string_801b4060(Ptr32<Loader>, Ptr32<const char>);
extern "C" int w3d_s10_find_string_801b40d0(Ptr32<Loader>, Ptr32<const char>);
struct LoaderBase { void w3d_r_v0() __asm__(W3D_SYM("_ZN10LoaderBase2v0Ev")),w3d_r_v1() __asm__(W3D_SYM("_ZN10LoaderBase2v1Ev")),w3d_r_v2() __asm__(W3D_SYM("_ZN10LoaderBase2v2Ev")),w3d_r_v3() __asm__(W3D_SYM("_ZN10LoaderBase2v3Ev")); int w3d_r_v24(Ptr32<const char>, Ptr32<Obj>) __asm__(W3D_SYM("_ZN10LoaderBase3v24EPKcP3Obj")); int w3d_r_v28(Ptr32<const char>, Ptr32<Obj>) __asm__(W3D_SYM("_ZN10LoaderBase3v28EPKcP3Obj")); int w3d_r_v32(Ptr32<const char>, Ptr32<Ptr32<void>>) __asm__(W3D_SYM("_ZN10LoaderBase3v32EPKcPPv")); int w3d_r_v36(Ptr32<const char>, Ptr32<Ptr32<void>>) __asm__(W3D_SYM("_ZN10LoaderBase3v36EPKcPPv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_LoaderBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_LoaderBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_LoaderBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_LoaderBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int v24(Ptr32<const char> w3d_a0, Ptr32<Obj> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<const char>, Ptr32<Obj>))w3d::vfn(this->w3d_vptr_LoaderBase, 6))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline int v28(Ptr32<const char> w3d_a0, Ptr32<Obj> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<const char>, Ptr32<Obj>))w3d::vfn(this->w3d_vptr_LoaderBase, 7))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline int v32(Ptr32<const char> w3d_a0, Ptr32<Ptr32<void>> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<const char>, Ptr32<Ptr32<void>>))w3d::vfn(this->w3d_vptr_LoaderBase, 8))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline int v36(Ptr32<const char> w3d_a0, Ptr32<Ptr32<void>> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<const char>, Ptr32<Ptr32<void>>))w3d::vfn(this->w3d_vptr_LoaderBase, 9))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_LoaderBase; };
struct Loader : LoaderBase { char p[40] __attribute__((aligned(__alignof__(LoaderBase)))); Ptr32<Ptr32<void>> a; char q[20]; Ptr32<Ptr32<void>> b; };
extern "C" int w3d_d30e_load_by_extension_801b3b30(Ptr32<Loader> self, Ptr32<const char> name, Ptr32<Ptr32<void>> out) {
  int i = w3d_s10_find_string_801b4060(self, name);
  if (i != -1) { *out = *(Ptr32<Ptr32<void>>)((i << 2) + (Ptr32<char>)self->a); return 0; }
  i = w3d_s10_find_string_801b40d0(self, name);
  if (i != -1) { *out = self->b[i]; return 0; }
  Ptr32<const char> ext = strrchr(name, '.');
  if (!ext) return 0x80004005;
  if (w3d_d24z_strcasecmp_802ef074(ext, lbl_803aaab8) || w3d_d24z_strcasecmp_802ef074(ext, lbl_803aaabc) || w3d_d24z_strcasecmp_802ef074(ext, lbl_803aaac0))
    return self->v32(name, out);
  if (w3d_d24z_strcasecmp_802ef074(ext, lbl_803aaac8)) return self->v36(name, out);
  if (w3d_d24z_strcasecmp_802ef074(ext, lbl_803aaacc)) {
    Ptr32<Ptr32<Obj>> root = 0;
    Tagged t;
    int hr = t.refill(name, 1);
    if (hr < 0) return hr;
    Ref s(w3d_auto_8020b6c0());
    s.p->attach(t.data());
    hr = s.p->seek(0, 0);
    if (hr < 0) return hr;
    Ptr32<TypeInfo> ty = (*root)->type();
    if (isA(ty, lbl_80364fa4)) self->v24(name, *root);
    else if (isA(ty, lbl_80362704)) self->v28(name, *root);
    else {
      w3d_auto_801ffea8(ty);
      (*root)->Release();
      return 0x80004005;
    }
    return 0;
  }
  return 0x80070057;
}



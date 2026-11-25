#include "w3d_ptr.h"
#line 1 "d30e_add_gain_801dd7a8.cpp"
// (Worms 3D GameCube PAL, 0x801dd7a8).
//
// Adds a gain entry for a ready source: returns 0x80004005 for a null or
// unready source; otherwise builds a 16-byte entry (constructor 0x801daf38,
// bind 0x801dafbc taking the reference by value) and appends it to the
// vector at +60 with unmodified STLport push_back. Returns 0. Names are
// inferred.

#include "compat/stlport_sn_oom.h"
#include <vector>
struct Unk { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Unk2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Unk6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN3Unk7ReleaseEv")); void w3d_r_v3() __asm__(W3D_SYM("_ZN3Unk2v3Ev")),w3d_r_v4() __asm__(W3D_SYM("_ZN3Unk2v4Ev")),w3d_r_v5() __asm__(W3D_SYM("_ZN3Unk2v5Ev")),w3d_r_v6() __asm__(W3D_SYM("_ZN3Unk2v6Ev")); int w3d_r_ready() __asm__(W3D_SYM("_ZN3Unk5readyEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int ready() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 9))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Unk; };
struct URef {
  Ptr32<Unk> p;
  URef(const URef &o) { p = o.p; if (p) p->AddRef(); }
};
struct Gain {
  Ptr32<Unk> p; int a; int b; float g;
  Gain();
  Gain(const Gain &o) { p = o.p; if (p) p->AddRef(); a = o.a; b = o.b; g = o.g; }
  ~Gain();
  Gain &operator=(const Gain &);
  void bind(URef, int);
};
struct S { char q[60]; std::vector<Gain> gains; };
extern "C" int w3d_d30e_add_gain_801dd7a8(Ptr32<S> self, Ptr32<URef> src, int t) {
  if (!src->p || !src->p->ready()) return 0x80004005;
  Gain g;
  g.bind(*src, t);
  self->gains.push_back(g);
  return 0;
}



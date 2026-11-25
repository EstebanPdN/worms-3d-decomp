#include "w3d_ptr.h"
#line 1 "d33e_set_interface_clear_flag_801f3044.cpp"
// (Worms 3D GameCube PAL, 0x801f3044).
//
// Stores a reference-counted interface pointer at +36, taking a reference on
// the new object and releasing the old one, clears the top flag bit of the
// word at +32 and returns 0.

struct Iface { void w3d_r_v0() __asm__(W3D_SYM("_ZN5Iface2v0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
struct Ref { Ptr32<Iface> p;
  template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Iface *)w3d_p.get()); }
 Ref &operator=(Iface *q) { if (q) q->add(); if (p) p->release(); p = q; return *this; } };
struct HolderB { char pad[32]; unsigned int rest:31; unsigned int flag:1; Ref object; };
extern "C" int w3d_d33e_set_interface_clear_flag_801f3044(Ptr32<HolderB> self, Ptr32<Iface> object) {
  self->object = object;
  do { self->flag = 0; return 0; } while (0);
}



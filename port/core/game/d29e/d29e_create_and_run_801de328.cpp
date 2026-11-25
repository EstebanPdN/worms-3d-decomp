#include "w3d_ptr.h"
#line 1 "d29e_create_and_run_801de328.cpp"
// (Worms 3D GameCube PAL, 0x801de328).
//
// Creates an object through the given factory (the singleton at 0x8020b884
// when null, virtual slot 3, kind 2) into a held reference; on success finds
// the service for 0x80418f78, binds the new object to it (slot 3), runs it
// with self and 0 (slot 6), releases both references and returns the result.
// Names are inferred.

struct Iface {
  void w3d_r_v0() __asm__(W3D_SYM("_ZN5Iface2v0Ev"));
  void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv"));
  void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));
  void w3d_r_bind(Ptr32<Iface>) __asm__(W3D_SYM("_ZN5Iface4bindEPS_"));
  void w3d_r_v4() __asm__(W3D_SYM("_ZN5Iface2v4Ev"));
  void w3d_r_v5() __asm__(W3D_SYM("_ZN5Iface2v5Ev"));
  int w3d_r_run(Ptr32<void>, int) __asm__(W3D_SYM("_ZN5Iface3runEPvi"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void bind(Ptr32<Iface> w3d_a0) { ((void (*)(w3d_u32, Ptr32<Iface>))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int run(Ptr32<void> w3d_a0, int w3d_a1) { return ((int (*)(w3d_u32, Ptr32<void>, int))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_Iface; };
struct Ref {
  Ptr32<Iface> p;
  Ref() : p(0) {}
  template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Iface *)w3d_p.get()) {}
 Ref(Iface *q) : p(q) { if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  Ptr32<Iface> operator->() { return p; }
};
struct Factory {
  void w3d_r_v0() __asm__(W3D_SYM("_ZN7Factory2v0Ev"));
  void w3d_r_v1() __asm__(W3D_SYM("_ZN7Factory2v1Ev"));
  void w3d_r_v2() __asm__(W3D_SYM("_ZN7Factory2v2Ev"));
  int w3d_r_create(Ptr32<void>, int, Ptr32<Ref>) __asm__(W3D_SYM("_ZN7Factory6createEPviP3Ref"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int create(Ptr32<void> w3d_a0, int w3d_a1, Ptr32<Ref> w3d_a2) { return ((int (*)(w3d_u32, Ptr32<void>, int, Ptr32<Ref>))w3d::vfn(this->w3d_vptr_Factory, 5))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  Ptr32<void> w3d_vptr_Factory; };
extern char lbl_80418f78[];
extern "C" Ptr32<Factory> cxc2_singleton_8020b884();
extern "C" Ptr32<Iface> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern "C" int w3d_d29e_create_and_run_801de328(Ptr32<void> self, Ptr32<void> arg, Ptr32<Factory> factory) {
  Ref a;
  Ptr32<Ref> pa = &a;
  if (!factory) factory = cxc2_singleton_8020b884();
  int hr = factory->create(arg, 2, pa);
  if (hr >= 0) {
    Ref b(w3d_s10_service_forward_8020b680(lbl_80418f78));
    b->bind(a.p);
    hr = b->run(self, 0);
    // Empty statement of a compiled-out check: its loop notes pin the
    // destructor's load after the result copy.
    do { } while (0);
  }
  return hr;
}



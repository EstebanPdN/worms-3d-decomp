#include "w3d_ptr.h"
#line 1 "d30e_device_owner_801fb270.cpp"
// (Worms 3D GameCube PAL, 0x801fb270).
//
// Constructs the device owner: base table 0x804182d0, tagged link at +8
// cleared with kind 2, final table 0x80418210, two empty pointer vectors at
// +36 and +52, then runs 0x80301cb4 and, for each of four channels, gets a
// device from service 0x804181f0, opens it through slot 22, appends it (or
// null on failure) to the vector at +52 and, with an added reference, to the
// one at +36. Vectors are unmodified STLport. Names are inferred.

#pragma interface
#include "compat/stlport_sn_oom.h"
#include <vector>
struct Dev { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Dev2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Dev6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN3Dev7ReleaseEv")); void w3d_r_v3() __asm__(W3D_SYM("_ZN3Dev2v3Ev")),w3d_r_v4() __asm__(W3D_SYM("_ZN3Dev2v4Ev")),w3d_r_v5() __asm__(W3D_SYM("_ZN3Dev2v5Ev")),w3d_r_v6() __asm__(W3D_SYM("_ZN3Dev2v6Ev")),w3d_r_v7() __asm__(W3D_SYM("_ZN3Dev2v7Ev")),w3d_r_v8() __asm__(W3D_SYM("_ZN3Dev2v8Ev")),w3d_r_v9() __asm__(W3D_SYM("_ZN3Dev2v9Ev")),w3d_r_v10() __asm__(W3D_SYM("_ZN3Dev3v10Ev")),w3d_r_v11() __asm__(W3D_SYM("_ZN3Dev3v11Ev")),w3d_r_v12() __asm__(W3D_SYM("_ZN3Dev3v12Ev")),w3d_r_v13() __asm__(W3D_SYM("_ZN3Dev3v13Ev")),w3d_r_v14() __asm__(W3D_SYM("_ZN3Dev3v14Ev")),w3d_r_v15() __asm__(W3D_SYM("_ZN3Dev3v15Ev")),w3d_r_v16() __asm__(W3D_SYM("_ZN3Dev3v16Ev")),w3d_r_v17() __asm__(W3D_SYM("_ZN3Dev3v17Ev")),w3d_r_v18() __asm__(W3D_SYM("_ZN3Dev3v18Ev")),w3d_r_v19() __asm__(W3D_SYM("_ZN3Dev3v19Ev")),w3d_r_v20() __asm__(W3D_SYM("_ZN3Dev3v20Ev")),w3d_r_v21() __asm__(W3D_SYM("_ZN3Dev3v21Ev")); int w3d_r_open(int, unsigned, int) __asm__(W3D_SYM("_ZN3Dev4openEiji"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v19() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v21() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Dev, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int open(int w3d_a0, unsigned int w3d_a1, int w3d_a2) { return ((int (*)(w3d_u32, int, unsigned int, int))w3d::vfn(this->w3d_vptr_Dev, 24))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  Ptr32<void> w3d_vptr_Dev; };
struct Ref { Ptr32<Dev> p; template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Dev *)w3d_p.get()) {}
 Ref(Dev *o) { p = o; if (p) p->AddRef(); } Ref(const Ref &); ~Ref() { if (p) p->Release(); } operator Ptr32<Dev>() const { return (Dev *)this->operator Dev *(); }
 operator Dev *() const { return p; } Ptr32<Dev> operator->() const { return p; } };
extern char lbl_804181f0[];
extern "C" int fn_80301cb4();
extern "C" Ptr32<Dev> w3d_s10_service_forward_8020b680(Ptr32<void>);
struct Service { void w3d_r_s0()  __asm__(W3D_SYM("_ZN7Service2s0Ev"));  __attribute__((always_inline)) inline void s0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Service;  Service() { W3D_SET_VPTR(this->w3d_vptr_Service, w3d_vt___vt_7Service, "__vt_7Service"); } };
struct Sub { int a, b; void clear() { a = 0; b = 0; } };
struct Link {
  short a, b;
  unsigned int kind:8; unsigned int pointer:24;
  Sub s;
  Link(unsigned char tag) { kind = tag; pointer = 0; s.clear(); a = 0; b = 0; }
};
struct Node : Service { int x4 __attribute__((aligned(__alignof__(Service)))); Link link; Node() : link(2) { W3D_SET_VPTR(this->Service::w3d_vptr_Service, w3d_vt___vt_4Node, "__vt_4Node"); } };
struct D30eDeviceOwner : Node {
  int y __attribute__((aligned(__alignof__(Node)))); int x28; int x32;
  _STL::vector <Ptr32<Dev> > opened;
  _STL::vector <Ptr32<Dev> > all;
  void w3d_r_ko() __asm__(W3D_SYM("_ZN15D30eDeviceOwner2koEv"));
  D30eDeviceOwner();
 __attribute__((always_inline)) inline void ko() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 3))(w3d::h2g(this)); } };
D30eDeviceOwner::D30eDeviceOwner() { W3D_SET_VPTR(this->Node::w3d_vptr_Service, w3d_vt___vt_15D30eDeviceOwner, "__vt_15D30eDeviceOwner"); 
  fn_80301cb4();
  x28 = 0;
  for (unsigned i = 0; i < 4; i++) {
    Ref dev(w3d_s10_service_forward_8020b680(lbl_804181f0));
    if (dev->open(0, i, 0) >= 0) all.push_back(dev);
    else all.push_back(0);
    dev->AddRef();
    opened.push_back(dev);
  }
}



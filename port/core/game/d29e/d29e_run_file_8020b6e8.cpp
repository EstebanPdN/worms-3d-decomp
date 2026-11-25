#include "w3d_ptr.h"
#line 1 "d29e_run_file_8020b6e8.cpp"
// (Worms 3D GameCube PAL, 0x8020b6e8).
//
// Opens a tagged file reader for name with mode 1, tracing the failure
// unless the flag at 0x804b069c is set; on success gets the services for
// 0x80419848 and 0x80418de0, assigns the reader's data word to the first
// (0x802199c0), binds it to the second (slot 3), runs the second with arg
// (slot 6), traces a negative result, releases both and destroys the reader.
// Returns the result. Names are inferred.

struct Iface {
  void w3d_r_v0() __asm__(W3D_SYM("_ZN5Iface2v0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));
  void w3d_r_bind(Ptr32<Iface>) __asm__(W3D_SYM("_ZN5Iface4bindEPS_"));
  void w3d_r_v4() __asm__(W3D_SYM("_ZN5Iface2v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN5Iface2v5Ev"));
  int w3d_r_run(Ptr32<void>, int) __asm__(W3D_SYM("_ZN5Iface3runEPvi"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void bind(Ptr32<Iface> w3d_a0) { ((void (*)(w3d_u32, Ptr32<Iface>))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int run(Ptr32<void> w3d_a0, int w3d_a1) { return ((int (*)(w3d_u32, Ptr32<void>, int))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_Iface; };
extern char lbl_80419848[], lbl_80418de0[];
extern const char lbl_803b3104[], lbl_803b3130[];
extern int lbl_804b069c;
extern int lbl_804b0640;
extern "C" void w3d_trace_stub_80347324(Ptr32<int>, Ptr32<const char>, ...);
extern "C" Ptr32<Iface> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern "C" void w3d_s10_assign_interface_802199c0(Ptr32<Iface>, Ptr32<void>);
struct Ref {
  Ptr32<Iface> p;
  template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Iface *)w3d_p.get()) {}
 Ref(Iface *q) : p(q) { if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  Ptr32<Iface> operator->() { return p; }
};
struct Tagged {
  int w[5];
  int value;
  Tagged();
  ~Tagged();
  int refill(Ptr32<void>, int);
  int data() { return value; }
};
extern "C" int w3d_d29e_run_file_8020b6e8(Ptr32<void> name, Ptr32<void> arg) {
  Tagged t;
  int hr = t.refill(name, 1);
  if (hr < 0) {
    if (lbl_804b069c == 0) w3d_trace_stub_80347324(&lbl_804b0640, lbl_803b3104, w3d::VA(name));
    return hr;
  }
  Ref a(w3d_s10_service_forward_8020b680(lbl_80419848));
  Ref b(w3d_s10_service_forward_8020b680(lbl_80418de0));
  w3d_s10_assign_interface_802199c0(a.p, (Ptr32<void>)w3d::G((t.data())));
  b->bind(a.p);
  hr = b->run(arg, 0);
  if (hr < 0) w3d_trace_stub_80347324(&lbl_804b0640, lbl_803b3130, w3d::VA(name));
  return hr;
}



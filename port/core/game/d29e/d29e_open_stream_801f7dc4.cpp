#include "w3d_ptr.h"
#line 1 "d29e_open_stream_801f7dc4.cpp"
// (Worms 3D GameCube PAL, 0x801f7dc4).
//
// Clears out, opens a tagged file reader for name with mode 1 (constructor
// 0x80207fec, retain 0x80207f8c, refill 0x802080a0); on success creates a
// stream object from the type at 0x80365808, adds a reference and attaches
// the reader's data word through 0x801f8754, storing the object through out
// on success and releasing it on failure. The reader's destructor 0x8020803c
// runs on every path. Returns the result. Names are inferred.

struct Iface { void w3d_r_v0() __asm__(W3D_SYM("_ZN5Iface2v0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
extern char lbl_80365808[];
extern "C" int w3d_registry_retain_80207f8c(Ptr32<void>);
extern "C" Ptr32<Iface> w3d_r24b_invoke_ready_callback_8020fcb4(Ptr32<void>);
extern "C" int w3d_cx14b_stream_interface_attach_801f8754(Ptr32<Iface>, Ptr32<void>);
struct Tagged {
  int w[5];
  int value;
  Tagged();
  ~Tagged();
  int refill(Ptr32<void>, int);
  int data() { return value; }
};
extern "C" int w3d_d29e_open_stream_801f7dc4(Ptr32<void> self, Ptr32<void> name, Ptr32<Ptr32<Iface>> out) {
  *out = 0;
  Tagged t;
  w3d_registry_retain_80207f8c(&t);
  int hr = t.refill(name, 1);
  if (hr < 0) return hr;
  Ptr32<Iface> o = w3d_r24b_invoke_ready_callback_8020fcb4(lbl_80365808);
  o->add();
  hr = w3d_cx14b_stream_interface_attach_801f8754(o, (Ptr32<void>)w3d::G((t.data())));
  if (hr < 0) { o->release(); return hr; }
  *out = o;
  return 0;
}



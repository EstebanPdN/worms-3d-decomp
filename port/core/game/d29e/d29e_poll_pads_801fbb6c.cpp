#include "w3d_ptr.h"
#line 1 "d29e_poll_pads_801fbb6c.cpp"
// (Worms 3D GameCube PAL, 0x801fbb6c).
//
// Reads the pad states at 0x8045e824 (0x80301e04) and notes whether any were
// read; for each of 4 pads sets its bit in the mask at +28 for error states
// 0 and -3, or collects it for reset for -1; clears and resets the collected
// pads (0x80301a90), runs virtual slot 5 with 1, clamps (0x8030110c), then
// sets the connected bit at +264 of each device in the list at +52 and
// updates it (slot 4 of the device's table), returning the last negative
// result or 0. Names are inferred.

struct Pad { char p[10]; signed char err; char q; };
extern Pad lbl_8045e824[];
extern "C" int fn_80301e04(Ptr32<Pad>);
extern "C" int fn_80301a90(unsigned);
extern "C" void fn_8030110c(Ptr32<Pad>);
struct DeviceBase {
  void w3d_r_v0() __asm__(W3D_SYM("_ZN10DeviceBase2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN10DeviceBase2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN10DeviceBase2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN10DeviceBase2v3Ev"));
  int w3d_r_update(int) __asm__(W3D_SYM("_ZN10DeviceBase6updateEi"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DeviceBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DeviceBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DeviceBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DeviceBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int update(int w3d_a0) { return ((int (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_DeviceBase, 6))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_DeviceBase; };
struct Device : DeviceBase {
  char p[260] __attribute__((aligned(__alignof__(DeviceBase))));
  unsigned int :29; unsigned int connected:1; unsigned int a:2;
};
struct List { Ptr32<Ptr32<Device>> b; Ptr32<Ptr32<Device>> e; };
struct InputBase {
  void w3d_r_v0() __asm__(W3D_SYM("_ZN9InputBase2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN9InputBase2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN9InputBase2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN9InputBase2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN9InputBase2v4Ev"));
  int w3d_r_poll(int) __asm__(W3D_SYM("_ZN9InputBase4pollEi"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_InputBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_InputBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_InputBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_InputBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_InputBase, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int poll(int w3d_a0) { return ((int (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_InputBase, 7))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_InputBase; };
struct Input : InputBase {
  char p[24] __attribute__((aligned(__alignof__(InputBase))));
  unsigned mask;
  char q[20];
  List devices;
};
extern "C" int w3d_d29e_poll_pads_801fbb6c(Ptr32<Input> self) {
  unsigned reset = 0;
  Ptr32<Ptr32<Device>> it = self->devices.b;
  int result = 0;
  int any = 0;
  if (fn_80301e04(lbl_8045e824)) any = 1;
  int i = 0;
  List &list = self->devices;
  for (; i < 4; i++) {
    unsigned bit = 0x80000000u >> i;
    switch (lbl_8045e824[i].err) {
      case -2: break;
      case -3:
      case 0:
        self->mask |= bit;
        break;
      case -1:
        reset |= bit;
        break;
    }
  }
  if (reset) {
    self->mask &= ~reset;
    fn_80301a90(reset);
  }
  self->poll(1);
  fn_8030110c(lbl_8045e824);
  for (; it != list.e; it++) {
    if (*it) {
      (*it)->connected = any;
      int hr = (*it)->update(0);
      if (hr < 0) result = hr;
    }
  }
  return result;
}



#include "w3d_ptr.h"
#line 1 "d45e_device_strength_set_801fb0e8.cpp"
// GWMP8P rev0 0x801fb0e8. Sets a device's strength from two byte levels:
// zero for both stops it, otherwise the larger of the scaled first level and
// twice the scaled second level sets a 0 to 15 inverse amount. Partial class
// view; names are inferred.
// Partial view of the device class; only the slot used here is named.
// 255.0f at 0x803b1c0c follows the string "Joypad" in the original module pool,
// read through a data view so the remaining literals keep their addresses.
extern const float kByteScale_803b1c0c[];
struct DevBase {
  void w3d_r_v0() __asm__(W3D_SYM("_ZN7DevBase2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN7DevBase2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN7DevBase2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN7DevBase2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN7DevBase2v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN7DevBase2v5Ev")); void w3d_r_v6() __asm__(W3D_SYM("_ZN7DevBase2v6Ev")); void w3d_r_v7() __asm__(W3D_SYM("_ZN7DevBase2v7Ev")); void w3d_r_v8() __asm__(W3D_SYM("_ZN7DevBase2v8Ev")); void w3d_r_v9() __asm__(W3D_SYM("_ZN7DevBase2v9Ev")); void w3d_r_v10() __asm__(W3D_SYM("_ZN7DevBase3v10Ev")); void w3d_r_v11() __asm__(W3D_SYM("_ZN7DevBase3v11Ev")); void w3d_r_v12() __asm__(W3D_SYM("_ZN7DevBase3v12Ev")); void w3d_r_v13() __asm__(W3D_SYM("_ZN7DevBase3v13Ev")); void w3d_r_v14() __asm__(W3D_SYM("_ZN7DevBase3v14Ev")); void w3d_r_v15() __asm__(W3D_SYM("_ZN7DevBase3v15Ev")); void w3d_r_v16() __asm__(W3D_SYM("_ZN7DevBase3v16Ev"));
  void w3d_r_stop() __asm__(W3D_SYM("_ZN7DevBase4stopEv"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void stop() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_DevBase, 19))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_DevBase; };
struct Dev : DevBase {
  char p[256] __attribute__((aligned(__alignof__(DevBase))));
  unsigned amount;
  unsigned int :31; unsigned int flag:1;
};
extern "C" int w3d_d45e_device_strength_set_801fb0e8(Ptr32<Dev> self, unsigned a, int b) {
  if (a == 0 && b == 0) {
    self->amount = b;
    self->stop();
    return 0;
  }
  unsigned char ca = a, cb = b;
  float k = kByteScale_803b1c0c[0];
  float x = (float)ca / k; float y = (float)cb / k; float w = y + y; float v = x > b ? x : w; if (v > 1.0f) v = 1.0f; unsigned n = (unsigned)((1.0f - v) * 15.0f);
  self->amount = n;
  if (n <= 14) self->flag = 1;
  else self->stop();
  return 0;
}



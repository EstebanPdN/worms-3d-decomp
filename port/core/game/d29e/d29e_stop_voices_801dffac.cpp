#include "w3d_ptr.h"
#line 1 "d29e_stop_voices_801dffac.cpp"
// (Worms 3D GameCube PAL, 0x801dffac).
//
// For each voice in the vector at +36 whose owner id (read through
// 0x801df288 from +88) equals id and that reports active (virtual slot 7),
// calls its slot 5, then scans the 32 slot pointers at +48 for the one whose
// first field equals the voice's sound (slot 16) and passes that slot to
// 0x801e4e6c. Returns 0. Names are inferred.

struct Sound;
struct VoiceBase {
  void w3d_r_v0() __asm__(W3D_SYM("_ZN9VoiceBase2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN9VoiceBase2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN9VoiceBase2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN9VoiceBase2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN9VoiceBase2v4Ev"));
  void w3d_r_prepare() __asm__(W3D_SYM("_ZN9VoiceBase7prepareEv"));
  void w3d_r_w6() __asm__(W3D_SYM("_ZN9VoiceBase2w6Ev"));
  int w3d_r_active() __asm__(W3D_SYM("_ZN9VoiceBase6activeEv"));
  void w3d_r_w8() __asm__(W3D_SYM("_ZN9VoiceBase2w8Ev")); void w3d_r_w9() __asm__(W3D_SYM("_ZN9VoiceBase2w9Ev")); void w3d_r_w10() __asm__(W3D_SYM("_ZN9VoiceBase3w10Ev")); void w3d_r_w11() __asm__(W3D_SYM("_ZN9VoiceBase3w11Ev")); void w3d_r_w12() __asm__(W3D_SYM("_ZN9VoiceBase3w12Ev")); void w3d_r_w13() __asm__(W3D_SYM("_ZN9VoiceBase3w13Ev")); void w3d_r_w14() __asm__(W3D_SYM("_ZN9VoiceBase3w14Ev")); void w3d_r_w15() __asm__(W3D_SYM("_ZN9VoiceBase3w15Ev"));
  Ptr32<Sound> w3d_r_sound() __asm__(W3D_SYM("_ZN9VoiceBase5soundEv"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void prepare() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int active() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Sound> sound() { return ((Ptr32<Sound> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_VoiceBase, 18))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_VoiceBase; };
struct Voice : VoiceBase {
  char p[84] __attribute__((aligned(__alignof__(VoiceBase))));
  Ptr32<void> owner;
};
struct Slot { Ptr32<Sound> sound; };
struct Vec {
  Ptr32<Ptr32<Voice>> b; Ptr32<Ptr32<Voice>> e;
  unsigned size() const { return e - b; }
  Ptr32<Voice> & operator[](unsigned i) { return b[i]; }
};
struct Mixer {
  char p[36];
  Vec voices;
  char p1[4];
  Ptr32<Slot> slots[32];
};
extern "C" int w3d_get_801df288(Ptr32<void>);
extern "C" int w3d_auto_801e4e6c(Ptr32<Slot>);
extern "C" int w3d_d29e_stop_voices_801dffac(Ptr32<Mixer> self, int id) {
  for (unsigned i = 0; i < self->voices.size(); i++) {
    if (w3d_get_801df288(self->voices[i]->owner) == id && self->voices[i]->active()) {
      self->voices[i]->prepare();
      unsigned k = 0;
      do {
        Ptr32<Sound> s = self->slots[k]->sound;
        if (s == self->voices[i]->sound()) {
          w3d_auto_801e4e6c(self->slots[k]);
          break;
        }
        k++;
      } while (k <= 31);
    }
  }
  return 0;
}



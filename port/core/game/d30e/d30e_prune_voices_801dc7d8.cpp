#include "w3d_ptr.h"
#line 1 "d30e_prune_voices_801dc7d8.cpp"
// (Worms 3D GameCube PAL, 0x801dc7d8).
//
// Per-frame update of a sound object: returns 0x80004005 until ready (+176).
// Updates each listener in the array at +48 through virtual slot 10, steps
// each 16-byte gain entry in the vector at +60 with 0x801db06c, erasing
// finished ones (element copy with AddRef and Release, out-of-line
// destructor), then erases dead entries of the array at +76 (virtual slot
// 7). Names are inferred.

struct Unk { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Unk2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Unk6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN3Unk7ReleaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Unk; };
struct Gain {
  Ptr32<Unk> p; int a; int b; float g;
  ~Gain();
  Gain &operator=(const Gain &o) {
    if (o.p) o.p->AddRef();
    if (p) p->Release();
    p = o.p; a = o.a; b = o.b; g = o.g;
    return *this;
  }
};
extern "C" int w3d_r25b_step_gain_801db06c(Ptr32<Gain>, int);
static inline void copyGains(Ptr32<Gain> first, Ptr32<Gain> last, Ptr32<Gain> to) {
  for (int n = last - first; n > 0; --n) { *to = *first; ++first; ++to; }
}
struct GainVec {
  Ptr32<Gain> b; Ptr32<Gain> e;
  Ptr32<Gain> erase(Ptr32<Gain> pos) {
    if (pos + 1 != e) copyGains(pos + 1, e, pos);
    --e;
    e->~Gain();
    return pos;
  }
};
struct Upd { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Upd2v0Ev")),w3d_r_v1() __asm__(W3D_SYM("_ZN3Upd2v1Ev")),w3d_r_v2() __asm__(W3D_SYM("_ZN3Upd2v2Ev")),w3d_r_v3() __asm__(W3D_SYM("_ZN3Upd2v3Ev")),w3d_r_v4() __asm__(W3D_SYM("_ZN3Upd2v4Ev")),w3d_r_v5() __asm__(W3D_SYM("_ZN3Upd2v5Ev")),w3d_r_v6() __asm__(W3D_SYM("_ZN3Upd2v6Ev")),w3d_r_v7() __asm__(W3D_SYM("_ZN3Upd2v7Ev")),w3d_r_v8() __asm__(W3D_SYM("_ZN3Upd2v8Ev")),w3d_r_v9() __asm__(W3D_SYM("_ZN3Upd2v9Ev")); void w3d_r_update(int) __asm__(W3D_SYM("_ZN3Upd6updateEi"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Upd, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Upd, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Upd, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Upd, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Upd, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Upd, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Upd, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Upd, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Upd, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Upd, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void update(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Upd, 12))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Upd; };
struct Live { void w3d_r_v0() __asm__(W3D_SYM("_ZN4Live2v0Ev")),w3d_r_v1() __asm__(W3D_SYM("_ZN4Live2v1Ev")),w3d_r_v2() __asm__(W3D_SYM("_ZN4Live2v2Ev")),w3d_r_v3() __asm__(W3D_SYM("_ZN4Live2v3Ev")),w3d_r_v4() __asm__(W3D_SYM("_ZN4Live2v4Ev")),w3d_r_v5() __asm__(W3D_SYM("_ZN4Live2v5Ev")),w3d_r_v6() __asm__(W3D_SYM("_ZN4Live2v6Ev")); int w3d_r_alive() __asm__(W3D_SYM("_ZN4Live5aliveEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Live, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Live, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Live, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Live, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Live, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Live, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Live, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int alive() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Live, 9))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Live; };
struct UpdArr { unsigned n; int c; Ptr32<Ptr32<Upd>> d; Ptr32<Upd> operator[](unsigned i) { return d[i]; } };
struct LiveArr { unsigned n; int c; Ptr32<Ptr32<Live>> d;
  Ptr32<Ptr32<Live>> begin() { return d; }
  Ptr32<Ptr32<Live>> end() { return d + n; }
};
extern "C" void f4c_erase_80210dd8(Ptr32<LiveArr>, Ptr32<Ptr32<Live>>, Ptr32<Ptr32<Live>>);
struct S { char p[48]; UpdArr ups; GainVec gains; int r[2]; LiveArr lives; char s[176 - 88]; int ready; };
extern "C" int w3d_d30e_prune_voices_801dc7d8(Ptr32<S> self, int t) {
  if (!self->ready) return 0x80004005;
  for (unsigned i = 0; i < self->ups.n; i++) self->ups[i]->update(t);
  GainVec &gains = self->gains;
  for (Ptr32<Gain> g = gains.b; g != gains.e;) {
    if (w3d_r25b_step_gain_801db06c(g, t)) g++;
    else gains.erase(g);
  }
  LiveArr &lives = self->lives;
  for (Ptr32<Ptr32<Live>> p = lives.d; p != lives.d + self->lives.n;) {
    if ((*p)->alive()) p++;
    else f4c_erase_80210dd8(&lives, p, p + 1);
  }
  return 0;
}



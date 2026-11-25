#include "w3d_ptr.h"
#line 1 "d30e_voice_start_801e5b80.cpp"
// (Worms 3D GameCube PAL, 0x801e5b80).
//
// Starts a voice from a source: refuses if the source's stream is unusable,
// there are no channels or it is already playing; takes the id from source
// virtual slot 16, runs stream slots 23 to 25, and unless the stream is open
// or the voice active, claims a free entry of the 16-channel table at
// 0x8045dbc8 for each stream channel, sets it up through 0x802f51e4 and
// 0x802f5568 with a lazily allocated 96-byte buffer and the 0x801e59b4
// callback. On failure it releases through stream slot 21 and returns 0.
// Names are inferred.

struct File;
struct Stream { void w3d_r_v0() __asm__(W3D_SYM("_ZN6Stream2v0Ev")),w3d_r_v1() __asm__(W3D_SYM("_ZN6Stream2v1Ev")),w3d_r_v2() __asm__(W3D_SYM("_ZN6Stream2v2Ev")),w3d_r_v3() __asm__(W3D_SYM("_ZN6Stream2v3Ev")),w3d_r_v4() __asm__(W3D_SYM("_ZN6Stream2v4Ev")),w3d_r_v5() __asm__(W3D_SYM("_ZN6Stream2v5Ev")),w3d_r_v6() __asm__(W3D_SYM("_ZN6Stream2v6Ev")),w3d_r_v7() __asm__(W3D_SYM("_ZN6Stream2v7Ev")),w3d_r_v8() __asm__(W3D_SYM("_ZN6Stream2v8Ev")),w3d_r_v9() __asm__(W3D_SYM("_ZN6Stream2v9Ev")),w3d_r_v10() __asm__(W3D_SYM("_ZN6Stream3v10Ev")),w3d_r_v11() __asm__(W3D_SYM("_ZN6Stream3v11Ev")),w3d_r_v12() __asm__(W3D_SYM("_ZN6Stream3v12Ev")),w3d_r_v13() __asm__(W3D_SYM("_ZN6Stream3v13Ev")),w3d_r_v14() __asm__(W3D_SYM("_ZN6Stream3v14Ev")),w3d_r_v15() __asm__(W3D_SYM("_ZN6Stream3v15Ev")),w3d_r_v16() __asm__(W3D_SYM("_ZN6Stream3v16Ev")),w3d_r_v17() __asm__(W3D_SYM("_ZN6Stream3v17Ev")),w3d_r_v18() __asm__(W3D_SYM("_ZN6Stream3v18Ev")),w3d_r_v19() __asm__(W3D_SYM("_ZN6Stream3v19Ev")),w3d_r_v20() __asm__(W3D_SYM("_ZN6Stream3v20Ev")); void w3d_r_v92() __asm__(W3D_SYM("_ZN6Stream3v92Ev")); void w3d_r_v96() __asm__(W3D_SYM("_ZN6Stream3v96Ev")); void w3d_r_v100() __asm__(W3D_SYM("_ZN6Stream4v100Ev")); void w3d_r_v104() __asm__(W3D_SYM("_ZN6Stream4v104Ev")); void w3d_r_v108() __asm__(W3D_SYM("_ZN6Stream4v108Ev")); void w3d_r_v26() __asm__(W3D_SYM("_ZN6Stream3v26Ev")),w3d_r_v27() __asm__(W3D_SYM("_ZN6Stream3v27Ev")),w3d_r_v28() __asm__(W3D_SYM("_ZN6Stream3v28Ev")),w3d_r_v29() __asm__(W3D_SYM("_ZN6Stream3v29Ev")),w3d_r_v30() __asm__(W3D_SYM("_ZN6Stream3v30Ev")),w3d_r_v31() __asm__(W3D_SYM("_ZN6Stream3v31Ev")),w3d_r_v32() __asm__(W3D_SYM("_ZN6Stream3v32Ev")),w3d_r_v33() __asm__(W3D_SYM("_ZN6Stream3v33Ev")); Ptr32<File> w3d_r_v144(int) __asm__(W3D_SYM("_ZN6Stream4v144Ei"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v19() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v92() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v96() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v100() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v104() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v108() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v26() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v27() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 29))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 30))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v29() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 31))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v30() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 32))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v31() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 33))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 34))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v33() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 35))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<File> v144(int w3d_a0) { return ((Ptr32<File> (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Stream, 36))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Stream; };
struct SourceBase { void w3d_r_v0() __asm__(W3D_SYM("_ZN10SourceBase2v0Ev")),w3d_r_v1() __asm__(W3D_SYM("_ZN10SourceBase2v1Ev")),w3d_r_v2() __asm__(W3D_SYM("_ZN10SourceBase2v2Ev")),w3d_r_v3() __asm__(W3D_SYM("_ZN10SourceBase2v3Ev")),w3d_r_v4() __asm__(W3D_SYM("_ZN10SourceBase2v4Ev")),w3d_r_v5() __asm__(W3D_SYM("_ZN10SourceBase2v5Ev")),w3d_r_v6() __asm__(W3D_SYM("_ZN10SourceBase2v6Ev")),w3d_r_v7() __asm__(W3D_SYM("_ZN10SourceBase2v7Ev")),w3d_r_v8() __asm__(W3D_SYM("_ZN10SourceBase2v8Ev")),w3d_r_v9() __asm__(W3D_SYM("_ZN10SourceBase2v9Ev")),w3d_r_v10() __asm__(W3D_SYM("_ZN10SourceBase3v10Ev")),w3d_r_v11() __asm__(W3D_SYM("_ZN10SourceBase3v11Ev")),w3d_r_v12() __asm__(W3D_SYM("_ZN10SourceBase3v12Ev")),w3d_r_v13() __asm__(W3D_SYM("_ZN10SourceBase3v13Ev")),w3d_r_v14() __asm__(W3D_SYM("_ZN10SourceBase3v14Ev")),w3d_r_v15() __asm__(W3D_SYM("_ZN10SourceBase3v15Ev")); int w3d_r_v72() __asm__(W3D_SYM("_ZN10SourceBase3v72Ev"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int v72() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 18))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_SourceBase; };
struct Source : SourceBase { char p[60] __attribute__((aligned(__alignof__(SourceBase)))); Ptr32<Stream> s; };
struct Chan { char p[60]; unsigned int :30; unsigned int b:1; unsigned int a:1; };
extern Chan lbl_8045dbc8[];
struct Mgr;
extern "C" int w3d_stream_is_open(Ptr32<Mgr>, int);
extern Ptr32<Mgr> w3d_stream_system_804ab85c;
extern "C" int fn_802f51e4(int, Ptr32<Chan>);
extern "C" int fn_802f5568(Ptr32<Chan>, Ptr32<void>, int, int, Ptr32<void (void)>, int);
extern "C" Ptr32<void> w3d_aligned_allocate(int, int);
extern "C" void fn_801e59b4(Ptr32<void>, Ptr32<void>);
struct Voice {
  int id; unsigned short slot[2];
  // v33: la palabra de +8 como en el original y en sus otros escritores (constructor 801e5a60: &= 0xff1fffff; parada
  // 801e5dfc: 0x400000; ocupado 801e5fd4: 0x200000 y 0x800000): bits 21-23 y el contador en el byte alto. Antes era un
  // campo de 16 bits (bits 5-7 del byte +8) que el constructor no limpiaba: con basura en la memoria nueva (la consola)
  // el canal se creía cargando cabeceras, no abría nunca el archivo y la música no sonaba.
  unsigned int :21; unsigned int active:1; unsigned int opened:1; unsigned int started:1; unsigned int count:8;
  char q[4]; unsigned n; char r[28]; int x48; int y; int h; Ptr32<void> buf[2];
};
extern "C" int w3d_auto_801e64c0(Ptr32<Voice>, Ptr32<Stream>);
extern "C" int w3d_s21_is_playing_801e6c48(Ptr32<Voice>, Ptr32<File>);
extern "C" int w3d_d30e_voice_start_801e5b80(Ptr32<Voice> self, Ptr32<Source> src) {
  Ptr32<Stream> s = src->s;
  Ptr32<Mgr> mgr = w3d_stream_system_804ab85c;
  if (!w3d_auto_801e64c0(self, s) || !self->n || !src || w3d_s21_is_playing_801e6c48(self, s->v144(0))) return 0;
  self->x48 = 0;
  *(Ptr32<Ptr32<Source>>)((Ptr32<char>)self + 164) = src;
  self->id = src->v72();
  s->v100();
  s->v104();
  s->v108();
  if (!w3d_stream_is_open(mgr, self->h) && !self->active) {
    for (unsigned i = 0; i < self->n; i++) {
      if (s->v144(i) != (Ptr32<File>)w3d::G(-1)) {
        self->slot[i] = 0xffff;
        for (unsigned k = 0; k <= 15; k++) {
          if (!lbl_8045dbc8[k].b) { self->slot[i] = k; break; }
        }
        Ptr32<Chan> c = &lbl_8045dbc8[self->slot[i]];
        if (!fn_802f51e4((int)w3d::H((s->v144(i))), c)) {
          s->v92();
          self->slot[i] = 0xffff;
          return 0;
        }
        if (!self->buf[i]) self->buf[i] = w3d_aligned_allocate(96, 32);
        fn_802f5568(c, self->buf[i], 96, 0, (Ptr32<void (void)>)fn_801e59b4, 2);
        c->a = 0;
        c->b = 1;
      }
    }
    self->active = 1;
    self->count = 0;
  }
  self->started = 1;
  return 1;
}



#include "w3d_ptr.h"
#line 1 "d30e_voice_update_801e6054.cpp"
// (Worms 3D GameCube PAL, 0x801e6054).
//
// Per-frame voice update. While starting, polls each claimed channel of the
// table at 0x8045dbc8, copies the decoded header from the DMA buffer into a
// 48-byte stream block, counts ready channels and, once all are ready, opens
// a mono or stereo stream at the configured volume. Otherwise applies volume
// and facing mix to the open stream, reopens a looping stream if needed, and
// when the voice stops releases its source and returns 0. Names are
// inferred.

struct File;
struct Stream { void w3d_r_v0() __asm__(W3D_SYM("_ZN6Stream2v0Ev")),w3d_r_v1() __asm__(W3D_SYM("_ZN6Stream2v1Ev")),w3d_r_v2() __asm__(W3D_SYM("_ZN6Stream2v2Ev")),w3d_r_v3() __asm__(W3D_SYM("_ZN6Stream2v3Ev")),w3d_r_v4() __asm__(W3D_SYM("_ZN6Stream2v4Ev")),w3d_r_v5() __asm__(W3D_SYM("_ZN6Stream2v5Ev")),w3d_r_v6() __asm__(W3D_SYM("_ZN6Stream2v6Ev")),w3d_r_v7() __asm__(W3D_SYM("_ZN6Stream2v7Ev")),w3d_r_v8() __asm__(W3D_SYM("_ZN6Stream2v8Ev")),w3d_r_v9() __asm__(W3D_SYM("_ZN6Stream2v9Ev")),w3d_r_v10() __asm__(W3D_SYM("_ZN6Stream3v10Ev")),w3d_r_v11() __asm__(W3D_SYM("_ZN6Stream3v11Ev")),w3d_r_v12() __asm__(W3D_SYM("_ZN6Stream3v12Ev")),w3d_r_v13() __asm__(W3D_SYM("_ZN6Stream3v13Ev")),w3d_r_v14() __asm__(W3D_SYM("_ZN6Stream3v14Ev")),w3d_r_v15() __asm__(W3D_SYM("_ZN6Stream3v15Ev")),w3d_r_v16() __asm__(W3D_SYM("_ZN6Stream3v16Ev")),w3d_r_v17() __asm__(W3D_SYM("_ZN6Stream3v17Ev")),w3d_r_v18() __asm__(W3D_SYM("_ZN6Stream3v18Ev")),w3d_r_v19() __asm__(W3D_SYM("_ZN6Stream3v19Ev")),w3d_r_v20() __asm__(W3D_SYM("_ZN6Stream3v20Ev")); void w3d_r_v92() __asm__(W3D_SYM("_ZN6Stream3v92Ev")); void w3d_r_v22() __asm__(W3D_SYM("_ZN6Stream3v22Ev")),w3d_r_v23() __asm__(W3D_SYM("_ZN6Stream3v23Ev")),w3d_r_v24() __asm__(W3D_SYM("_ZN6Stream3v24Ev")),w3d_r_v25() __asm__(W3D_SYM("_ZN6Stream3v25Ev")),w3d_r_v26() __asm__(W3D_SYM("_ZN6Stream3v26Ev")),w3d_r_v27() __asm__(W3D_SYM("_ZN6Stream3v27Ev")),w3d_r_v28() __asm__(W3D_SYM("_ZN6Stream3v28Ev")),w3d_r_v29() __asm__(W3D_SYM("_ZN6Stream3v29Ev")),w3d_r_v30() __asm__(W3D_SYM("_ZN6Stream3v30Ev")),w3d_r_v31() __asm__(W3D_SYM("_ZN6Stream3v31Ev")),w3d_r_v32() __asm__(W3D_SYM("_ZN6Stream3v32Ev")),w3d_r_v33() __asm__(W3D_SYM("_ZN6Stream3v33Ev")); Ptr32<File> w3d_r_v144(int) __asm__(W3D_SYM("_ZN6Stream4v144Ei"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v19() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v92() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v22() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v23() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v25() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v26() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v27() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 29))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 30))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v29() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 31))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v30() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 32))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v31() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 33))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 34))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v33() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 35))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<File> v144(int w3d_a0) { return ((Ptr32<File> (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Stream, 36))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Stream; };
struct SourceBase { void w3d_r_v0() __asm__(W3D_SYM("_ZN10SourceBase2v0Ev")),w3d_r_v1() __asm__(W3D_SYM("_ZN10SourceBase2v1Ev")),w3d_r_v2() __asm__(W3D_SYM("_ZN10SourceBase2v2Ev")),w3d_r_v3() __asm__(W3D_SYM("_ZN10SourceBase2v3Ev")); void w3d_r_v24() __asm__(W3D_SYM("_ZN10SourceBase3v24Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN10SourceBase2v5Ev")),w3d_r_v6() __asm__(W3D_SYM("_ZN10SourceBase2v6Ev")); int w3d_r_v36() __asm__(W3D_SYM("_ZN10SourceBase3v36Ev")); void w3d_r_v8() __asm__(W3D_SYM("_ZN10SourceBase2v8Ev")),w3d_r_v9() __asm__(W3D_SYM("_ZN10SourceBase2v9Ev")),w3d_r_v10() __asm__(W3D_SYM("_ZN10SourceBase3v10Ev")),w3d_r_v11() __asm__(W3D_SYM("_ZN10SourceBase3v11Ev")),w3d_r_v12() __asm__(W3D_SYM("_ZN10SourceBase3v12Ev")),w3d_r_v13() __asm__(W3D_SYM("_ZN10SourceBase3v13Ev")),w3d_r_v14() __asm__(W3D_SYM("_ZN10SourceBase3v14Ev")),w3d_r_v15() __asm__(W3D_SYM("_ZN10SourceBase3v15Ev")),w3d_r_v16() __asm__(W3D_SYM("_ZN10SourceBase3v16Ev")),w3d_r_v17() __asm__(W3D_SYM("_ZN10SourceBase3v17Ev")); int w3d_r_v80() __asm__(W3D_SYM("_ZN10SourceBase3v80Ev"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int v36() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int v80() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SourceBase, 20))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_SourceBase; };
struct Source : SourceBase { char p[60] __attribute__((aligned(__alignof__(SourceBase)))); Ptr32<Stream> s; };
struct Chan { char p[60]; unsigned int :30; unsigned int b:1; unsigned int a:1; };
extern Chan lbl_8045dbc8[];
struct Mgr;
struct Cfg { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Cfg2v0Ev")),w3d_r_v1() __asm__(W3D_SYM("_ZN3Cfg2v1Ev")),w3d_r_v2() __asm__(W3D_SYM("_ZN3Cfg2v2Ev")),w3d_r_v3() __asm__(W3D_SYM("_ZN3Cfg2v3Ev")),w3d_r_v4() __asm__(W3D_SYM("_ZN3Cfg2v4Ev")),w3d_r_v5() __asm__(W3D_SYM("_ZN3Cfg2v5Ev")),w3d_r_v6() __asm__(W3D_SYM("_ZN3Cfg2v6Ev")),w3d_r_v7() __asm__(W3D_SYM("_ZN3Cfg2v7Ev")),w3d_r_v8() __asm__(W3D_SYM("_ZN3Cfg2v8Ev")),w3d_r_v9() __asm__(W3D_SYM("_ZN3Cfg2v9Ev")),w3d_r_v10() __asm__(W3D_SYM("_ZN3Cfg3v10Ev")),w3d_r_v11() __asm__(W3D_SYM("_ZN3Cfg3v11Ev")),w3d_r_v12() __asm__(W3D_SYM("_ZN3Cfg3v12Ev")),w3d_r_v13() __asm__(W3D_SYM("_ZN3Cfg3v13Ev")),w3d_r_v14() __asm__(W3D_SYM("_ZN3Cfg3v14Ev")),w3d_r_v15() __asm__(W3D_SYM("_ZN3Cfg3v15Ev")),w3d_r_v16() __asm__(W3D_SYM("_ZN3Cfg3v16Ev")),w3d_r_v17() __asm__(W3D_SYM("_ZN3Cfg3v17Ev")),w3d_r_v18() __asm__(W3D_SYM("_ZN3Cfg3v18Ev")),w3d_r_v19() __asm__(W3D_SYM("_ZN3Cfg3v19Ev")),w3d_r_v20() __asm__(W3D_SYM("_ZN3Cfg3v20Ev")),w3d_r_v21() __asm__(W3D_SYM("_ZN3Cfg3v21Ev")),w3d_r_v22() __asm__(W3D_SYM("_ZN3Cfg3v22Ev")),w3d_r_v23() __asm__(W3D_SYM("_ZN3Cfg3v23Ev")),w3d_r_v24() __asm__(W3D_SYM("_ZN3Cfg3v24Ev")),w3d_r_v25() __asm__(W3D_SYM("_ZN3Cfg3v25Ev")),w3d_r_v26() __asm__(W3D_SYM("_ZN3Cfg3v26Ev")),w3d_r_v27() __asm__(W3D_SYM("_ZN3Cfg3v27Ev")),w3d_r_v28() __asm__(W3D_SYM("_ZN3Cfg3v28Ev")),w3d_r_v29() __asm__(W3D_SYM("_ZN3Cfg3v29Ev")),w3d_r_v30() __asm__(W3D_SYM("_ZN3Cfg3v30Ev")); float w3d_r_v132(int) __asm__(W3D_SYM("_ZN3Cfg4v132Ei"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v19() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v21() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v22() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v23() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v25() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v26() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v27() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 29))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 30))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v29() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 31))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v30() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cfg, 32))(w3d::h2g(this)); }  __attribute__((always_inline)) inline float v132(int w3d_a0) { return ((float (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Cfg, 33))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Cfg; };
extern Ptr32<Mgr> w3d_stream_system_804ab85c;
extern Ptr32<Cfg> w3d_sound_config_804ab80c;

struct Info { char x0[4]; unsigned rate; unsigned short kind; char x8[2]; unsigned short loop; char x14[14]; int fmt[8]; };
struct Fmt { int w[8]; };
struct Block { Ptr32<File> file; unsigned short kind; int size; unsigned len; Fmt fmt; };
struct Voice {
  int id; unsigned short slot[2];
  // v33: la palabra de +8 como en el original y en sus otros escritores (constructor 801e5a60: &= 0xff1fffff; parada
  // 801e5dfc: 0x400000; ocupado 801e5fd4: 0x200000 y 0x800000): bits 21-23 y el contador en el byte alto. Antes era un
  // campo de 16 bits (bits 5-7 del byte +8) que el constructor no limpiaba: con basura en la memoria nueva (la consola)
  // el canal se creía cargando cabeceras, no abría nunca el archivo y la música no sonaba.
  unsigned int :21; unsigned int active:1; unsigned int opened:1; unsigned int started:1; unsigned int count:8;
  char q[4]; unsigned n; char r[24]; int sample; int x48; int y; int h; Ptr32<Info> buf[2]; Block block[2]; Ptr32<Source> src;
};
extern "C" int w3d_stream_is_open(Ptr32<Mgr>, int);
extern "C" void fn_802fa988(Ptr32<void>, int);
extern "C" int w3d_s21_link_query_801e65fc(Ptr32<Voice>);
extern "C" void w3d_s21_reset_801e6bbc(Ptr32<Voice>);
extern "C" int w3d_sound_sample_get_44(Ptr32<void>);
extern "C" int fn_801e41d0(Ptr32<Mgr>, Ptr32<Block>, Ptr32<Block>, int);
extern "C" int w3d_stream_open_mono(Ptr32<Mgr>, Ptr32<Block>, int, int);
extern "C" void w3d_s21_register_stream_801e6cd0(Ptr32<Voice>, Ptr32<File>);
extern "C" int w3d_s21_is_busy_801e5fd4(Ptr32<Voice>);
extern "C" float w3d_d26e_voice_volume_801e68d4(Ptr32<Voice>, Ptr32<void>);
extern "C" float w3d_facing_term_801e663c(Ptr32<Voice>, Ptr32<void>);
extern "C" float w3d_facing_term_801e6788(Ptr32<Voice>, Ptr32<void>);
extern "C" void w3d_stream_set_mix(Ptr32<Mgr>, int, int, int, int);
static inline void setMix(Ptr32<Mgr> m, int h, float v, float p, float q) { w3d_stream_set_mix(m, h, (unsigned char)(v * 127.0f), (unsigned char)(p * 127.0f), (unsigned char)(q * 127.0f)); }
static inline void setMix2(Ptr32<Mgr> m, int h, float v, float p, float q) { w3d_stream_set_mix(m, h, (unsigned char)(v * 127.0f), (unsigned char)((p + 1.0f) * 0.5f * 127.0f), (unsigned char)((q + 1.0f) * 0.5f * 127.0f)); }
extern "C" void w3d_open_stream_801e6b1c(Ptr32<Voice>);
extern "C" void w3d_auto_801e5dfc(Ptr32<Voice>);
extern "C" int w3d_d30e_voice_update_801e6054(Ptr32<Voice> self, int unused, int t) {
  if (self->active && self->src) {
    for (unsigned i = 0; i < self->n; i++) {
      if (self->slot[i] <= 15 && lbl_8045dbc8[self->slot[i]].a) {
        Ptr32<Info> in = self->buf[i];
        Ptr32<Stream> s = self->src->s;
        Ptr32<Block> b = &self->block[i];
        fn_802fa988(in, 96);
        b->fmt = *(Ptr32<Fmt>)in->fmt;
        b->file = s->v144(i);
        b->kind = in->kind;
        b->len = (in->rate >> 1) & 0x7fffffe0;
        b->size = 96;
        if (w3d_s21_link_query_801e65fc(self)) in->loop = 1;
        else in->loop = 0;
        if (b->kind != 32000) w3d_s21_reset_801e6bbc(self);
        else self->count++;
        Ptr32<Chan> c = &lbl_8045dbc8[self->slot[i]];
        c->a = 0;
        c->b = 0;
        self->slot[i] = 0xffff;
      }
    }
    if (self->n == self->count) {
      self->active = 0;
      self->count = 0;
      Ptr32<Stream> s0 = self->src->s;
      Ptr32<Mgr> mgr = w3d_stream_system_804ab85c;
      if (s0) s0->v92();
      Ptr32<Cfg> cfg = w3d_sound_config_804ab80c;
      float v = cfg->v132(w3d_sound_sample_get_44((Ptr32<void>)w3d::G(self->sample))) * 127.0f;
      int vol = (unsigned char)v;
      Ptr32<Stream> s = self->src->s;
      if (self->n > 1) self->h = fn_801e41d0(mgr, &self->block[0], &self->block[1], vol);
      else self->h = w3d_stream_open_mono(mgr, &self->block[0], vol, 64);
      w3d_s21_register_stream_801e6cd0(self, s->v144(0));
      self->opened = 1;
    }
    return 1;
  }
  if (w3d_s21_is_busy_801e5fd4(self)) {
    Ptr32<Mgr> mgr = w3d_stream_system_804ab85c;
    if (self->src->v80()) {
      float a = w3d_d26e_voice_volume_801e68d4(self, (Ptr32<void>)w3d::G(t));
      float b = w3d_facing_term_801e663c(self, (Ptr32<void>)w3d::G(t));
      float c = w3d_facing_term_801e6788(self, (Ptr32<void>)w3d::G(t));
      a *= 127.0f;
      b = (b + 1.0f) * 0.5f * 127.0f;
      c = (c + 1.0f) * 0.5f * 127.0f;
      w3d_stream_set_mix(mgr, self->h, (unsigned char)a, (unsigned char)b, (unsigned char)c);
    } else {
      float v = w3d_d26e_voice_volume_801e68d4(self, (Ptr32<void>)w3d::G(t));
      w3d_stream_set_mix(mgr, self->h, (unsigned char)(v * 127.0f), 64, 0);
    }
    if (w3d_s21_link_query_801e65fc(self) && self->started && !w3d_stream_is_open(mgr, self->h)) w3d_open_stream_801e6b1c(self);
  }
  if (!w3d_s21_is_busy_801e5fd4(self)) {
    self->started = 0;
    if (self->src) {
      if (self->src->v36()) self->src->v24();
      w3d_auto_801e5dfc(self);
    }
    return 0;
  }
  return 1;
}



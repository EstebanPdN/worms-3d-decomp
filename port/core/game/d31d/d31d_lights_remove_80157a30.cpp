#include "w3d_ptr.h"
#line 1 "d31d_lights_remove_80157a30.cpp"
// GWMP8P rev0 0x80157a30. Removes the sixteen numbered worm lights and weapon
// lights by name from the engine's light manager, then finishes the world's
// manager. Names are read from the strings in the original; virtual slots are
// reference-ABI observations.
#pragma interface
struct Lights {
    void w3d_r_s2() __asm__(W3D_SYM("_ZN6Lights2s2Ev"));
    void w3d_r_s3() __asm__(W3D_SYM("_ZN6Lights2s3Ev"));
    void w3d_r_s4() __asm__(W3D_SYM("_ZN6Lights2s4Ev"));
    void w3d_r_s5() __asm__(W3D_SYM("_ZN6Lights2s5Ev"));
    void w3d_r_s6() __asm__(W3D_SYM("_ZN6Lights2s6Ev"));
    void w3d_r_s7() __asm__(W3D_SYM("_ZN6Lights2s7Ev"));
    void w3d_r_s8() __asm__(W3D_SYM("_ZN6Lights2s8Ev"));
    void w3d_r_s9() __asm__(W3D_SYM("_ZN6Lights2s9Ev"));
    void w3d_r_s10() __asm__(W3D_SYM("_ZN6Lights3s10Ev"));
    void w3d_r_s11() __asm__(W3D_SYM("_ZN6Lights3s11Ev"));
    void w3d_r_s12() __asm__(W3D_SYM("_ZN6Lights3s12Ev"));
    void w3d_r_s13() __asm__(W3D_SYM("_ZN6Lights3s13Ev"));
    void w3d_r_s14() __asm__(W3D_SYM("_ZN6Lights3s14Ev"));
    void w3d_r_s15() __asm__(W3D_SYM("_ZN6Lights3s15Ev"));
    void w3d_r_s16() __asm__(W3D_SYM("_ZN6Lights3s16Ev"));
    void w3d_r_s17() __asm__(W3D_SYM("_ZN6Lights3s17Ev"));
    void w3d_r_s18() __asm__(W3D_SYM("_ZN6Lights3s18Ev"));
    void w3d_r_s19() __asm__(W3D_SYM("_ZN6Lights3s19Ev"));
    void w3d_r_s20() __asm__(W3D_SYM("_ZN6Lights3s20Ev"));
    void w3d_r_s21() __asm__(W3D_SYM("_ZN6Lights3s21Ev"));
    void w3d_r_s22() __asm__(W3D_SYM("_ZN6Lights3s22Ev"));
    void w3d_r_s23() __asm__(W3D_SYM("_ZN6Lights3s23Ev"));
    void w3d_r_s24() __asm__(W3D_SYM("_ZN6Lights3s24Ev"));
    void w3d_r_s25() __asm__(W3D_SYM("_ZN6Lights3s25Ev"));
    void w3d_r_s26() __asm__(W3D_SYM("_ZN6Lights3s26Ev"));
    void w3d_r_s27() __asm__(W3D_SYM("_ZN6Lights3s27Ev"));
    void w3d_r_s28() __asm__(W3D_SYM("_ZN6Lights3s28Ev"));
    void w3d_r_s29() __asm__(W3D_SYM("_ZN6Lights3s29Ev"));
    void w3d_r_s30() __asm__(W3D_SYM("_ZN6Lights3s30Ev"));
    void w3d_r_s31() __asm__(W3D_SYM("_ZN6Lights3s31Ev"));
    void w3d_r_s32() __asm__(W3D_SYM("_ZN6Lights3s32Ev"));
    void w3d_r_s33() __asm__(W3D_SYM("_ZN6Lights3s33Ev"));
    void w3d_r_s34() __asm__(W3D_SYM("_ZN6Lights3s34Ev"));
    void w3d_r_s35() __asm__(W3D_SYM("_ZN6Lights3s35Ev"));
    void w3d_r_s36() __asm__(W3D_SYM("_ZN6Lights3s36Ev"));
    void w3d_r_s37() __asm__(W3D_SYM("_ZN6Lights3s37Ev"));
    void w3d_r_s38() __asm__(W3D_SYM("_ZN6Lights3s38Ev"));
    void w3d_r_s39() __asm__(W3D_SYM("_ZN6Lights3s39Ev"));
    void w3d_r_s40() __asm__(W3D_SYM("_ZN6Lights3s40Ev"));
    void w3d_r_s41() __asm__(W3D_SYM("_ZN6Lights3s41Ev"));
    void w3d_r_s42() __asm__(W3D_SYM("_ZN6Lights3s42Ev"));
    void w3d_r_s43() __asm__(W3D_SYM("_ZN6Lights3s43Ev"));
    void w3d_r_s44() __asm__(W3D_SYM("_ZN6Lights3s44Ev"));
    void w3d_r_s45() __asm__(W3D_SYM("_ZN6Lights3s45Ev"));
    void w3d_r_s46() __asm__(W3D_SYM("_ZN6Lights3s46Ev"));
    void w3d_r_s47() __asm__(W3D_SYM("_ZN6Lights3s47Ev"));
    void w3d_r_s48() __asm__(W3D_SYM("_ZN6Lights3s48Ev"));
    int w3d_r_remove(Ptr32<char>, int) __asm__(W3D_SYM("_ZN6Lights6removeEPci"));
 __attribute__((always_inline)) inline void s2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s19() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s21() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s22() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s23() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s25() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s26() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s27() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s29() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 29))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s30() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 30))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s31() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 31))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 32))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s33() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 33))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s34() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 34))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s35() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 35))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 36))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s37() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 37))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s38() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 38))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s39() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 39))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 40))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s41() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 41))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s42() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 42))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s43() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 43))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 44))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s45() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 45))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s46() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 46))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s47() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 47))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Lights, 48))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int remove(Ptr32<char> w3d_a0, int w3d_a1) { return ((int (*)(w3d_u32, Ptr32<char>, int))w3d::vfn(this->w3d_vptr_Lights, 49))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_Lights; };
struct Engine { char u0[116]; Ptr32<Lights> lights; };
struct Mgr;
struct MgrVt { char u0[88]; Ptr32<void (Ptr32<Mgr>, int)> finish; };
struct Mgr { Ptr32<MgrVt> vt; };
struct World { char u0[68]; Ptr32<Mgr> mgr; };
extern Ptr32<Engine> engine_804b17ec;
extern Ptr32<World> world_804b1788;
extern "C" int format_803442b4(Ptr32<char>, Ptr32<const char>, ...);
struct Name { char s[32]; Ptr32<char> c_str() { return s; } Ptr32<char> Fmt(Ptr32<const char> f, unsigned i) { format_803442b4(s, f, i); return s; } };
extern "C" void w3d_d31d_lights_remove_80157a30() {
    Name buf;
    for (unsigned i = 0; i <= 15; i++) {
        engine_804b17ec->lights->remove((format_803442b4(buf.s, "WormLight.%d", i), buf.c_str()), 4);
        engine_804b17ec->lights->remove(buf.Fmt("WeaponLight.%d", i), 4);
    }
    world_804b1788->mgr->vt->finish(world_804b1788->mgr, 4);
}



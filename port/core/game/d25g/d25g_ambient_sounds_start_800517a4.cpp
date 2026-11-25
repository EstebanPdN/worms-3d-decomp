#include "w3d_ptr.h"
#line 1 "d25g_ambient_sounds_start_800517a4.cpp"
/* Worms 3D GameCube PAL 0x800517a4. Starts the four ambient loops: when the audio loader exists, stamps the current time, gives each slot a random due time up to 870 ticks away and a clear wait, picks a random name that differs from the previous pick, loads it into the slot, sends it its position and calls its setup slot with (1, 0.0f); finally stores the level. Without a loader it calls the base start. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Vec3 { float x, y, z; };
struct Part;
struct Part { void w3d_r_v0() __asm__(W3D_SYM("_ZN4Part2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN4Part2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN4Part2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN4Part2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN4Part2v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN4Part2v5Ev")); void w3d_r_v6() __asm__(W3D_SYM("_ZN4Part2v6Ev")); void w3d_r_v7() __asm__(W3D_SYM("_ZN4Part2v7Ev")); void w3d_r_v8() __asm__(W3D_SYM("_ZN4Part2v8Ev")); void w3d_r_v9() __asm__(W3D_SYM("_ZN4Part2v9Ev")); void w3d_r_v10() __asm__(W3D_SYM("_ZN4Part3v10Ev"));
    void w3d_r_setup(int, float) __asm__(W3D_SYM("_ZN4Part5setupEif")); int w3d_r_send(int, const Vec3 &) __asm__(W3D_SYM("_ZN4Part4sendEiRK4Vec3"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Part, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Part, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Part, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Part, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Part, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Part, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Part, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Part, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Part, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Part, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Part, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void setup(int w3d_a0, float w3d_a1) { ((void (*)(w3d_u32, int, float))w3d::vfn(this->w3d_vptr_Part, 13))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline int send(int w3d_a0, const Vec3 &w3d_a1) { return ((int (*)(w3d_u32, int, w3d_u32))w3d::vfn(this->w3d_vptr_Part, 14))(w3d::h2g(this), w3d_a0, w3d::h2g(__builtin_addressof(w3d_a1))); }  Ptr32<void> w3d_vptr_Part; };
struct Loader { void w3d_r_v0() __asm__(W3D_SYM("_ZN6Loader2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN6Loader2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN6Loader2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN6Loader2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN6Loader2v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN6Loader2v5Ev")); void w3d_r_v6() __asm__(W3D_SYM("_ZN6Loader2v6Ev")); void w3d_r_v7() __asm__(W3D_SYM("_ZN6Loader2v7Ev")); void w3d_r_v8() __asm__(W3D_SYM("_ZN6Loader2v8Ev")); void w3d_r_v9() __asm__(W3D_SYM("_ZN6Loader2v9Ev")); void w3d_r_v10() __asm__(W3D_SYM("_ZN6Loader3v10Ev")); void w3d_r_v11() __asm__(W3D_SYM("_ZN6Loader3v11Ev")); void w3d_r_v12() __asm__(W3D_SYM("_ZN6Loader3v12Ev")); void w3d_r_v13() __asm__(W3D_SYM("_ZN6Loader3v13Ev")); void w3d_r_v14() __asm__(W3D_SYM("_ZN6Loader3v14Ev")); void w3d_r_v15() __asm__(W3D_SYM("_ZN6Loader3v15Ev")); void w3d_r_v16() __asm__(W3D_SYM("_ZN6Loader3v16Ev")); void w3d_r_v17() __asm__(W3D_SYM("_ZN6Loader3v17Ev")); void w3d_r_v18() __asm__(W3D_SYM("_ZN6Loader3v18Ev")); void w3d_r_v19() __asm__(W3D_SYM("_ZN6Loader3v19Ev")); void w3d_r_v20() __asm__(W3D_SYM("_ZN6Loader3v20Ev"));
    int w3d_r_load(Ptr32<const char>, Ptr32<Ptr32<Part>>) __asm__(W3D_SYM("_ZN6Loader4loadEPKcPP4Part"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v19() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int load(Ptr32<const char> w3d_a0, Ptr32<Ptr32<Part>> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<const char>, Ptr32<Ptr32<Part>>))w3d::vfn(this->w3d_vptr_Loader, 23))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_Loader; };
struct Game { char u[108]; Ptr32<Loader> loader; };
struct Engine { char u[52]; int time; };
struct Motion;
struct Self {
    char u0[28];
    int wait[4];
    Ptr32<Part> parts[4];
    int due[4];
    float level;
    int now;
};
extern Ptr32<Game> game_804b1788;
extern Ptr32<const char> names_803f40f4[];
extern const float zero_80378178[];
extern "C" void base_update_8015fd1c(Ptr32<Self>);
extern "C" Ptr32<Engine> engine_80165254();
extern "C" unsigned random_8015ff5c(Ptr32<Self>);
extern "C" Vec3 position_80066894(Ptr32<Motion>);
extern "C" float factor_800668e4(Ptr32<Motion>);
extern "C" Vec3 offset_80051a24(Ptr32<Self>, const Vec3 &, float);
extern "C" float level_80051a18(Ptr32<Self>, float);
extern "C" void w3d_d25g_ambient_sounds_start_800517a4(Ptr32<Self> self, Ptr32<Motion> motion)
{
    if (!game_804b1788->loader) { base_update_8015fd1c(self); return; }
    self->now = engine_80165254()->time;
    int last = 4;
    for (int i = 0; i < 4; i++) {
        Ptr32<Ptr32<Part>> part = &self->parts[i];
        int prev = last;
        unsigned r = random_8015ff5c(self);
        r = r % 870;
        self->due[i] = self->now + r;
        self->wait[i] = 0;
        last = random_8015ff5c(self) & 3;
        if (last == prev) last = (last + 1) % 4;
        game_804b1788->loader->load(names_803f40f4[last], part);
        Vec3 pos = position_80066894(motion);
        (*part)->send(3, offset_80051a24(self, pos, factor_800668e4(motion)));
        (*part)->setup(1, zero_80378178[0]);
    }
    self->level = level_80051a18(self, factor_800668e4(motion));
}



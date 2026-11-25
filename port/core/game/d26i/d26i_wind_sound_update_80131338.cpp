#include "w3d_ptr.h"
#line 1 "d26i_wind_sound_update_80131338.cpp"
// GWMP8P rev0 0x80131338. Updates the wind sound volume and level from the
// wind phase.
extern "C" float sin_802e88ac(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec &operator-=(const Vec &o) { x -= o.x; y -= o.y; z -= o.z; return *this; }
};
struct Source { void w3d_r_v0() __asm__(W3D_SYM("_ZN6Source2v0Ev"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Source; };
struct World { char u0[112]; Ptr32<void> source; };
extern Ptr32<World> world_804b1788;
struct Gauge {
    char u0[84]; float phase; char u88[16]; Ptr32<void> sound; float level; int volume;
};
extern "C" Ptr32<void> w3d_wind_direction_80131520(Ptr32<Vec>, Ptr32<Gauge>);
typedef Ptr32<void (Ptr32<void>, Vec &)> GetPos;
typedef Ptr32<void (Ptr32<void>, int, Ptr32<int>)> GetVal;
typedef Ptr32<void (Ptr32<void>, int, int)> SetInt;
typedef Ptr32<void (Ptr32<void>, int, float)> SetFlt;
extern "C" void d26i_wind_sound_update_80131338(Ptr32<Gauge> self) {
    Vec pos;
    Ptr32<void> src = world_804b1788->source;
    (*(Ptr32<GetPos>)(*(Ptr32<Ptr32<char>>)src + 56))(src, pos);
    Vec dir;
    w3d_wind_direction_80131520(&dir, self);
    pos -= dir;
    int base;
    Ptr32<void> snd = self->sound;
    (*(Ptr32<GetVal>)(*(Ptr32<Ptr32<char>>)snd + 60))(snd, 12, &base);
    int offset = (int)((float)base * (self->phase - 0.5f) * 1.5f);
    int volume = (int)((float)self->volume * 0.9875f + (float)(base + offset) * 0.0125f);
    self->volume = volume;
    Ptr32<void> s6 = self->sound;
    (*(Ptr32<SetInt>)(*(Ptr32<Ptr32<char>>)s6 + 48))(s6, 2, volume);
    float w = sin_802e88ac(self->phase * 1.5707964f + 4.712389f);
    w += 1.0f; self->level = self->level * 0.99f + w * 0.01f;
    Ptr32<void> s7 = self->sound;
    (*(Ptr32<SetFlt>)(*(Ptr32<Ptr32<char>>)s7 + 52))(s7, 1, self->level);
}



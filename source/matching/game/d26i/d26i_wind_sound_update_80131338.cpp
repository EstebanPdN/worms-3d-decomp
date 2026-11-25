// GWMP8P rev0 0x80131338. Updates the wind sound volume and level from the
// wind phase.
extern "C" float sin_802e88ac(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec &operator-=(const Vec &o) { x -= o.x; y -= o.y; z -= o.z; return *this; }
};
struct Source { virtual void v0(); };
struct World { char u0[112]; void *source; };
extern World *world_804b1788;
struct Gauge {
    char u0[84]; float phase; char u88[16]; void *sound; float level; int volume;
};
extern "C" void * w3d_wind_direction_80131520(Vec *, Gauge *);
typedef void (*GetPos)(void *, Vec &);
typedef void (*GetVal)(void *, int, int *);
typedef void (*SetInt)(void *, int, int);
typedef void (*SetFlt)(void *, int, float);
extern "C" void d26i_wind_sound_update_80131338(Gauge *self) {
    Vec pos;
    void *src = world_804b1788->source;
    (*(GetPos *)(*(char **)src + 56))(src, pos);
    Vec dir;
    w3d_wind_direction_80131520(&dir, self);
    pos -= dir;
    int base;
    void *snd = self->sound;
    (*(GetVal *)(*(char **)snd + 60))(snd, 12, &base);
    int offset = (int)((float)base * (self->phase - 0.5f) * 1.5f);
    int volume = (int)((float)self->volume * 0.9875f + (float)(base + offset) * 0.0125f);
    self->volume = volume;
    void *s6 = self->sound;
    (*(SetInt *)(*(char **)s6 + 48))(s6, 2, volume);
    float w = sin_802e88ac(self->phase * 1.5707964f + 4.712389f);
    w += 1.0f; self->level = self->level * 0.99f + w * 0.01f;
    void *s7 = self->sound;
    (*(SetFlt *)(*(char **)s7 + 52))(s7, 1, self->level);
}

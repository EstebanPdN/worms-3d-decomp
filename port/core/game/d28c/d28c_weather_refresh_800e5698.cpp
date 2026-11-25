#include "w3d_ptr.h"
#line 1 "d28c_weather_refresh_800e5698.cpp"
// d28c: 0x800e5698. Weather refresh: reads rain or snow probability settings, formats the particle group name, starts or stops the group by a random draw, and posts the next refresh message. Names are inferred; classes are partial views.
struct Name { char buf[128]; };
struct Key { Ptr32<const char> key; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *k) { key = k; } };
struct Self { char u0[28]; int group; int f32; };
struct Msg { unsigned short id; Ptr32<const void> vt; };
struct Ctx { char u0[52]; int now; };
extern "C" int setting_800fc230(Ptr32<Key>, Ptr32<unsigned int>);
extern "C" Name format_803434d4(Ptr32<const char>, ...);
extern "C" unsigned random_80162ba8();
extern char zero_8045e788[];
extern "C" int spawn_800e5da0(Ptr32<Self>, Ptr32<const void>, Ptr32<const char>, unsigned, float);
extern "C" void physics_800e58fc(Ptr32<Self>, int);
extern "C" void stop_800e5bb8(int);
extern "C" Ptr32<Ctx> context_80165254();
extern Ptr32<void> arena_804b1754;
extern "C" Ptr32<Msg> arena_alloc_801613f0(Ptr32<void>, int);
extern "C" int cached_8015f5a0(Ptr32<int>, int);
extern int id_804aede4;
extern char vt_8040db38[];
extern "C" int pool_add_800c53a0(Ptr32<Msg>, int);
extern "C" void d28c_weather_refresh_800e5698(Ptr32<Self> self) {
    Name name;
    Ptr32<Name> s = &name; s->buf[0] = 0;
    unsigned prob;
    Key rain("Particle.Rain.Prob");
    setting_800fc230(&rain, &prob);
    Ptr32<Name> p = s; s = 0;
    if (prob == 0) {
        Key snow("Particle.Snow.Prob");
        setting_800fc230(&snow, &prob);
        *p = format_803434d4("ParticleSnowfall");
    } else {
        *p = format_803434d4("ParticleRainfall");
    }
    if (prob > 100) prob = 100;
    unsigned r = random_80162ba8() % 100;
    if (self->group == 0) {
        if (r < prob) {
            self->group = spawn_800e5da0(self, zero_8045e788, p->buf, 0, 0.0f);
            physics_800e58fc(self, 1);
        }
    } else if (r > prob) {
        stop_800e5bb8(self->group);
        self->group = 0;
        physics_800e58fc(self, 0);
    }
    Key k("Particle.Weather.RefreshFreq");
    int refresh;
    setting_800fc230(&k, (Ptr32<unsigned int>)&refresh);
    int at = context_80165254()->now + refresh;
    Ptr32<Msg> m = arena_alloc_801613f0(arena_804b1754, 8);
    m->id = cached_8015f5a0(&id_804aede4, 1);
    m->vt = vt_8040db38;
    self->f32 = pool_add_800c53a0(m, at);
}



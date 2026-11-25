// d28c: 0x800e5698. Weather refresh: reads rain or snow probability settings, formats the particle group name, starts or stops the group by a random draw, and posts the next refresh message. Names are inferred; classes are partial views.
struct Name { char buf[128]; };
struct Key { const char *key; Key(const char *k) { key = k; } };
struct Self { char u0[28]; int group; int f32; };
struct Msg { unsigned short id; const void *vt; };
struct Ctx { char u0[52]; int now; };
extern "C" int setting_800fc230(Key *, unsigned *);
extern "C" Name format_803434d4(const char *, ...);
extern "C" unsigned random_80162ba8();
extern char zero_8045e788[];
extern "C" int spawn_800e5da0(Self *, const void *, const char *, unsigned, float);
extern "C" void physics_800e58fc(Self *, int);
extern "C" void stop_800e5bb8(int);
extern "C" Ctx *context_80165254();
extern void *arena_804b1754;
extern "C" Msg *arena_alloc_801613f0(void *, int);
extern "C" int cached_8015f5a0(int *, int);
extern int id_804aede4;
extern char vt_8040db38[];
extern "C" int pool_add_800c53a0(Msg *, int);
extern "C" void d28c_weather_refresh_800e5698(Self *self) {
    Name name;
    Name *s = &name; s->buf[0] = 0;
    unsigned prob;
    Key rain("Particle.Rain.Prob");
    setting_800fc230(&rain, &prob);
    Name *p = s; s = 0;
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
    setting_800fc230(&k, (unsigned *)&refresh);
    int at = context_80165254()->now + refresh;
    Msg *m = arena_alloc_801613f0(arena_804b1754, 8);
    m->id = cached_8015f5a0(&id_804aede4, 1);
    m->vt = vt_8040db38;
    self->f32 = pool_add_800c53a0(m, at);
}

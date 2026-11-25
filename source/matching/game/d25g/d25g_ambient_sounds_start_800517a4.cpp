/* Worms 3D GameCube PAL 0x800517a4. Starts the four ambient loops: when the audio loader exists, stamps the current time, gives each slot a random due time up to 870 ticks away and a clear wait, picks a random name that differs from the previous pick, loads it into the slot, sends it its position and calls its setup slot with (1, 0.0f); finally stores the level. Without a loader it calls the base start. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Vec3 { float x, y, z; };
struct Part;
struct Part { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void setup(int, float); virtual int send(int, const Vec3 &); };
struct Loader { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual int load(const char *, Part **); };
struct Game { char u[108]; Loader *loader; };
struct Engine { char u[52]; int time; };
struct Motion;
struct Self {
    char u0[28];
    int wait[4];
    Part *parts[4];
    int due[4];
    float level;
    int now;
};
extern Game *game_804b1788;
extern const char *names_803f40f4[];
extern const float zero_80378178[];
extern "C" void base_update_8015fd1c(Self *);
extern "C" Engine *engine_80165254();
extern "C" unsigned random_8015ff5c(Self *);
extern "C" Vec3 position_80066894(Motion *);
extern "C" float factor_800668e4(Motion *);
extern "C" Vec3 offset_80051a24(Self *, const Vec3 &, float);
extern "C" float level_80051a18(Self *, float);
extern "C" void w3d_d25g_ambient_sounds_start_800517a4(Self *self, Motion *motion)
{
    if (!game_804b1788->loader) { base_update_8015fd1c(self); return; }
    self->now = engine_80165254()->time;
    int last = 4;
    for (int i = 0; i < 4; i++) {
        Part **part = &self->parts[i];
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

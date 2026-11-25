// GWMP8P rev0 0x80150828. Predict where a launched worm lands: with non-zero
// velocity, read Water.Level, find the time to reach it (0x800419cc), clamp
// it to the trace time (0x800b0824), and store the landing point and
// velocity by constant acceleration; otherwise copy the start point and
// velocity. Then point the camera properties at this worm, post an empty
// message and play the track sound. Names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline bool fle(const float &a, const float &b) { return a <= b; }
struct Message { unsigned short id; void **vtable; };
struct Worm {
    char u0[20]; int id; char u18[536]; Vec pos; char u23c[104]; Vec vel; Vec acc;
    char u2bc[556]; Vec landing; Vec landVel;
};
extern "C" void start_80150b38(Worm *, Vec *);
extern "C" int float_prop_800fc270(const char **, float *);
extern "C" int water_time_800419cc(float *, const Vec &, const Vec &, const Vec &, float);
extern "C" void test_800b0824(const Vec &, const Vec &, const Vec &, int, int);
extern "C" int prop_string_800fc550(const char **, const char *);
extern "C" int prop_int_800fc43c(const char **, int);
extern "C" Message *alloc_801613f0(void *, int);
extern "C" short msg_id_8015f5a0(void *, int);
extern "C" int post_8015fc58(Worm *, Message *);
extern "C" void play_800356e0(void *, const char *, float, float);
extern const char waterKey_803a1000[], taskKey_803a1810[], cameraData_803a181c[], track_803a1800[], sound_803a1834[];
extern float zero_803a183c[];
extern int traceFrac_804b1764;
extern void *heap_804b1754;
extern int cache_804afce8;
extern void *sound_804aa8c8;
extern void *vt_8040db38[];
inline Message *init_empty(Message *m, unsigned short id) { m->id = id; m->vtable = vt_8040db38; return m; }
extern "C" void d26d_worm_launch_prediction_80150828(Worm *self) {
    Vec start;
    start_80150b38(self, &start);
    if (self->vel.lenSq() > zero_803a183c[0]) {
        const char *key = waterKey_803a1000;
        float level;
        float_prop_800fc270(&key, &level);
        float t;
        water_time_800419cc(&t, self->pos, self->vel, self->acc, level);
        test_800b0824(self->pos, self->vel, self->acc, (int)t, 1);
        float h = (float)traceFrac_804b1764;
        if (fle(h, t)) t = h;
        self->landing = start + self->vel * t + self->acc * (t * t * 0.5f);
        self->landVel = self->vel + self->acc * t;
    } else {
        self->landVel = self->vel;
        self->landing = start;
    }
    const char *k1 = taskKey_803a1810;
    prop_string_800fc550(&k1, track_803a1800);
    const char *k2 = cameraData_803a181c;
    prop_int_800fc43c(&k2, self->id);
    Message *m = alloc_801613f0(heap_804b1754, 8);
    post_8015fc58(self, init_empty(m, msg_id_8015f5a0(&cache_804afce8, 1)));
    play_800356e0(sound_804aa8c8, sound_803a1834, 0.6f, 0.6f);
}

// d27c: 0x800dff7c. Moves a point toward a target that has been jittered by a descriptor's base and random range. Uses the shared random service in net games and the local linear congruential generator otherwise. Names are inferred; netted is a guess from that split.
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Desc { char u0[44]; Vec3 range; char u56[100]; Vec3 base; char u168[246]; unsigned short netted; };
struct Rng { unsigned seed; };
extern Rng rng_804aecb4;
extern "C" float rand_80162bc8(void);
inline float lrand() { rng_804aecb4.seed = rng_804aecb4.seed * 0x41c64e6d + 12345; return (float)rng_804aecb4.seed * 2.3283064e-10f; }
extern float half_80389cfc[];
inline float spread(float r, float half) { float h = r - half; return h + h; }
extern "C" void d27c_particle_jitter_toward_800dff7c(Vec3 *out, const Vec3 &target, float t, Desc *d) {
    Vec3 v(target);
    if (d->netted) {
        const Vec3 &base = d->base, &range = d->range;
        float r0 = rand_80162bc8();
        float half = half_80389cfc[0];
        v.x += base.x + spread(r0, half) * range.x;
        v.y += base.y + spread(rand_80162bc8(), half) * range.y;
        v.z += base.z + spread(rand_80162bc8(), half) * range.z;
    } else {
        const Vec3 &base = d->base, &range = d->range;
        float r = spread(lrand(), half_80389cfc[0]);
        float a = base.x + r * range.x;
        float q = spread(lrand(), half_80389cfc[0]);
        float b = base.y + q * range.y;
        float s = spread(lrand(), half_80389cfc[0]);
        float c = base.z + s * range.z;
        v.x += a;
        v.y += b;
        v.z += c;
    }
    float x = out->x, y = out->y, z = out->z;
    out->x = t * (v.x - x) + x;
    out->y = t * (v.y - y) + y;
    out->z = t * (v.z - z) + z;
}

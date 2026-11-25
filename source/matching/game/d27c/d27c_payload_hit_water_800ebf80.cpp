// d27c: 0x800ebf80. A payload reaches water: at a shallow angle and enough speed it skips (velocity scaled, bounce effect), otherwise it splashes. The effect height is quantized to 1/16 from the water level. Names are inferred.
extern "C" float sqrt_802e82c0(float);
extern "C" float asin_802e7c30(float);
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
};
inline Vec3 operator*(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x * b.x; r.y = a.y * b.y; r.z = a.z * b.z; return r; }
struct Desc { char u0[164]; Vec3 scale; char u176[44]; float rise; char u224[108]; char *bounceFx; float minSpeed; char u340[24]; float maxAngle; char u368[8]; char *splashFx; char u380[72]; int bounces; };
struct Actor { char u0[180]; void *h180; char u184[8]; void *h192; };
extern "C" void *empty_80341584(void *);
extern "C" Desc *desc_801797b4(void *);
extern "C" void *empty_80342a74(void *);
extern "C" float value_80178df0(void *);
extern "C" int effect_800e5ca4(const Vec3 *, const char *, int, float);
extern "C" void d27c_payload_hit_water_800ebf80(Actor *self, Vec3 *pos, Vec3 *vel) {
    const float two = 2.0f;
    Desc *d = desc_801797b4(empty_80341584(self->h192));
    Vec3 n(*vel);
    n.normalize();
    float angle = asin_802e7c30(n.y);
    float speed = vel->len();
    Vec3 at(*pos);
    float water = value_80178df0(empty_80342a74(self->h180));
    at.y = two + (float)((int)(water * 16.0f) | 1) * 0.0625f;
    float maxAngle = d->maxAngle;
    if (d->bounces && speed > d->minSpeed && angle > maxAngle) {
        Vec3 s(d->scale);
        Vec3 r = *vel * s;
        *vel = r;
        effect_800e5ca4(&at, d->bounceFx, 0, 0.0f);
    } else {
        effect_800e5ca4(&at, d->splashFx, 0, 0.0f);
    }
    pos->y = value_80178df0(empty_80342a74(self->h180)) + d->rise;
}

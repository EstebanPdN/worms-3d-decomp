// d26c: 0x800ec400. Bounce response of an actor: zero when both factors are zero, the setting Bounce.MinSpeed when bouncing,
// otherwise a response with a minimum speed of 0.02. Names are inferred.
extern "C" float sqrt_802e82c0(float);
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize2() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    Vec3 operator*(float s) const { Vec3 r; r.x = x * s; r.y = y * s; r.z = z * s; return r; }
};
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
struct Actor { char u0[304]; float a; char u308[4]; float b; };
extern char key_8038b470[];
extern "C" int read_800fc270(const char **, float *);
extern "C" void respond_800c2494(Vec3 *, void *, float, float, float);
extern "C" void d26c_actor_bounce_velocity_800ec400(Actor *self, int bounce, int unused, Vec3 *out, void *hit) {
    float a = self->a;
    float b = self->b;
    if (a == 0.0f && b == 0.0f) {
        out->x = 0.0f; out->y = 0.0f; out->z = 0.0f;
        return;
    }
    if (bounce) {
        const char *key = key_8038b470;
        float value;
        read_800fc270(&key, &value);
        respond_800c2494(out, hit, a, b, value);
        return;
    }
    respond_800c2494(out, hit, a, b, 0.0f);
    float len = out->len();
    const float zero = 0.0f;
    Vec3 n(*out);
    if (n.lenSq() > zero) n.normalize2();
    float low = 0.02f;
    len = fmax(len, low);
    Vec3 r = n * len;
    *out = r;
}

// d27c: 0x800d489c. Sets a projectile's velocity from its wanted direction, limited to a top speed. A trace then scales it to the free distance, and a brake term is subtracted along the normalized result. Names are inferred; the zero vector at sp+8 is written in the original but never read.
extern "C" float sqrt_802e82c0(float);
struct W { int a, b, c; };
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float v) { x = v; y = v; z = v; }
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    Vec3 &operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    bool same(const W &o) const { const W *t = (const W *)this; return t->a == o.a && t->b == o.b && t->c == o.c; }
};
inline Vec3 operator+(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec3 operator-(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec3 operator*(const Vec3 &a, float s) { Vec3 r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
struct Desc { char u0[60]; float maxSpeed; char u64[12]; float accel; char u80[36]; float brake; };
struct Self { char u0[112]; Vec3 vel; char u124[12]; void *h136; char u140[24]; Vec3 want; };
extern W zero_8045e788[];
extern int traceFrac_804b1764;
extern float lead_80388d24[];
extern "C" void *empty_80341584(void *);
extern "C" Desc *desc_801797b4(void *);
extern "C" int query_800b0788(const Vec3 &, Vec3 &);
extern "C" void d27c_projectile_steer_800d489c(Self *self, const Vec3 &at) {
    Desc *d = desc_801797b4(empty_80341584(self->h136));
    self->vel = self->want;
    self->vel *= d->accel;
    float s = self->vel.len();
    if (s > d->maxSpeed) self->vel *= d->maxSpeed / s;
    Vec3 z(lead_80388d24[0]);
    Vec3 start(at);
    Vec3 end = at + self->vel;
    Vec3 q = end - at;
    query_800b0788(start, q);
    float k = 1000.0f;
    q *= 1.0f / k;
    int frac = traceFrac_804b1764;
    if (frac <= 1000) {
        Vec3 n(q);
        if (!n.same(zero_8045e788[0])) n.normalize();
        self->vel = q * (float)frac - n * d->brake;
    }
}

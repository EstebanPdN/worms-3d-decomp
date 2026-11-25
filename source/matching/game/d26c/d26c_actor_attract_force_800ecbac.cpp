// d26c: 0x800ecbac. Attraction force on an actor: when a target is inside the motion's radius, push toward the motion's
// point scaled by how far inside it is. Names are inferred. The motion getter returns a vector by value (hidden r3).
extern "C" float sqrt_802e82c0(float);
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    Vec3 operator*(float s) const { Vec3 r(x * s, y * s, z * s); return r; }
};
inline float distance(const Vec3 &a, const Vec3 &b) {
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return sqrt_802e82c0(dx * dx + dy * dy + dz * dz);
}
inline Vec3 operator-(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
struct Motion;
extern "C" Vec3 velocity_800668b8(Motion *);
extern "C" float limit_800668dc(Motion *);
extern "C" float rate_800668fc(Motion *);
extern "C" void *empty_80341584(void *);
extern "C" void *desc_801797b4(void *);
struct Actor { char u0[36]; Vec3 pos; char u48[144]; void *h192; };
struct W { int a, b, c; };
extern W zero_8045e788[];
extern "C" void d26c_actor_attract_force_800ecbac(Actor *self, Motion *mo, const Vec3 *target, Vec3 *out) {
    desc_801797b4(empty_80341584(self->h192));
    *(W *)out = zero_8045e788[0];
    float speed = distance(*target, velocity_800668b8(mo));
    float limit = limit_800668dc(mo);
    if (speed < limit) {
        float k = (limit - speed) * rate_800668fc(mo) / limit;
        Vec3 d = self->pos - velocity_800668b8(mo);
        d.normalize();
        Vec3 f = d * k;
        *out = f;
    }
}

// d27c: 0x800d1c1c. Computes the signed angle a velocity would turn a view: the angle between the vectors from a point to the camera position, with and without 20 times the velocity. The sign comes from the velocity's side of the facing. Names are inferred.
extern "C" float sqrt_802e82c0(float);
extern "C" float sin_802e88ac(float);
extern "C" float cos_802e86d4(float);
extern "C" float acos_802e79e0(float);
struct W { int a, b, c; };
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    float dot(const Vec3 &o) const { return x * o.x + y * o.y + z * o.z; }
    bool same(const Vec3 &o) const { const W *a = (const W *)this, *b = (const W *)&o; return a->a == b->a && a->b == b->b && a->c == b->c; }
};
inline Vec3 operator+(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec3 operator-(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec3 operator*(const Vec3 &a, float s) { Vec3 r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline const float &clamp(const float &v, const float &lo, const float &hi) { return fmax(fmin(v, hi), lo); }
struct Self { char u0[28]; Vec3 *pos; };
extern "C" void * raised_800cfd98(Vec3 *, Self *);
extern "C" float d27c_camera_turn_angle_800d1c1c(Self *self, const Vec3 *v, const Vec3 *rot) {
    Vec3 a(*self->pos);
    Vec3 b;
    raised_800cfd98(&b, self);
    Vec3 c = b + *v * 20.0f;
    Vec3 ab = b - a;
    Vec3 ac = c - a;
    float l;
    if (v->lenSq() == 0.0f || ac.same(ab) || (l = ab.lenSq()) == 0.0f || ac.lenSq() == 0.0f) return 0.0f;
    float f = 1.0f / sqrt_802e82c0(l);
    ab.x *= f; ab.y *= f; ab.z *= f;
    ac.normalize();
    float d = ab.dot(ac);
    float ang = acos_802e79e0(clamp(d, -1.0f, 1.0f));
    Vec3 w(*v); w.y = 0.0f;
    if (w.x != 0.0f || w.z != 0.0f) {
        Vec3 h(sin_802e88ac(rot->y), 0.0f, cos_802e86d4(rot->y));
        w.normalize();
        h.normalize();
        float e = w.dot(h);
        if (acos_802e79e0(clamp(e, -1.0f, 1.0f)) <= 1.5707964f) ang = -ang;
    }
    return ang;
}

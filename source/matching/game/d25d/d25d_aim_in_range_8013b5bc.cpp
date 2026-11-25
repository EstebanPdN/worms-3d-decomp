// GWMP8P rev0 0x8013b5bc. Aim range test: flatten the offset between two
// points; fail when its elevation exceeds 60 degrees (asin of height over
// horizontal length) and an output is wanted, or when the angle to the yaw
// direction reaches 60 degrees (acos of the clamped dot). With an output
// pointer also store the local heading from atan2 of the offset rotated by
// the negated yaw. Names are inferred.
extern "C" float sqrt_802e82c0(float);
extern "C" float asin_802e83ec(float);
extern "C" float acos_802e79e0(float);
extern "C" float cos_802e86d4(float);
extern "C" float sin_802e88ac(float);
extern "C" float atan2_802e7e5c(float, float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r(a.x - b.x, a.y - b.y, a.z - b.z); return r; }
inline const float &fmin(const float &a, const float &b) { return b < a ? b : a; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
struct Pos { float x, y, z; Pos(); };
struct Axis { float x, y, z; };
struct Transform {
    Axis axis[3]; Pos position;
    const Axis &A(int i) const { return axis[i]; }
    const Pos &P() const { return position; }
    void apply(Vec &o, const Vec &v) const {
        o.x = v.x * A(0).x + v.y * A(1).x + v.z * A(2).x + P().x;
        o.y = v.x * A(0).y + v.y * A(1).y + v.z * A(2).y + P().y;
        o.z = v.x * A(0).z + v.y * A(1).z + v.z * A(2).z + P().z;
    }
};
extern "C" void construct_801f7538(Transform *, float, float, float, float);
extern "C" int d25d_aim_in_range_8013b5bc(void *self, const Vec &a, const Vec &b, const Vec &rot, float *out) {
    Vec d = a - b;
    Vec h = d;
    h.y = 0.0f;
    if (__builtin_fabsf(asin_802e83ec(d.y / h.len())) > 1.0471976f && out) return 0;
    float ang = 1.5707964f - rot.y;
    float c = cos_802e86d4(ang);
    float s = sin_802e88ac(ang);
    Vec f(c, 0.0f, s);
    h.normalize();
    f.normalize();
    float v = f.dot(h);
    v = fmin(v, 1.0f);
    v = fmax(v, -1.0f);
    if (acos_802e79e0(v) < 1.0471976f) {
        if (out) {
            Transform t;
            construct_801f7538(&t, 0.0f, 1.0f, 0.0f, -rot.y);
            Vec o;
            t.apply(o, h);
            *out = atan2_802e7e5c(o.x, o.z);
        }
        return 1;
    }
    return 0;
}

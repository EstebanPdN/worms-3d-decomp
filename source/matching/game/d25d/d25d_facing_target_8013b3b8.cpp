// GWMP8P rev0 0x8013b3b8. Facing test: true when the worm with rotation rot,
// standing at from, faces to within 0.1309 radians (7.5 degrees) in the
// horizontal plane; also true when both points coincide. Compares the
// normalized horizontal offset with the direction derived from the yaw (pi/2
// - yaw) through acos of the clamped dot product. Names are inferred.
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
extern "C" float cos_802e86d4(float);
extern "C" float sin_802e88ac(float);
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
inline const float &fmin(const float &a, const float &b) { return b < a ? b : a; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
extern "C" int d25d_facing_target_8013b3b8(void *self, const Vec &from, const Vec &rot, const Vec &to) {
    Vec a = from;
    Vec b = to;
    Vec d(b.x - a.x, 0.0f, b.z - a.z);
    if (d.len() == 0.0f) return 1;
    float ang = 1.5707964f - rot.y;
    float c = cos_802e86d4(ang);
    float s = sin_802e88ac(ang);
    Vec f(c, 0.0f, s);
    d.normalize();
    f.normalize();
    float v = f.dot(d);
    v = fmin(v, 1.0f);
    v = fmax(v, -1.0f);
    return acos_802e79e0(v) < 0.1308997f;
}

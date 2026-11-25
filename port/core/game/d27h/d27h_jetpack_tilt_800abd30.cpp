#include "w3d_ptr.h"
#line 1 "d27h_jetpack_tilt_800abd30.cpp"
// GWMP8P rev0 0x800abd30. Jetpack animation tilt. Names are inferred.
// Measures the angle between the flat velocity and the yaw-rotated forward
// vector, normalizes it by pi and clamps it to 0..1; 0.5 when the flat
// velocity is zero.
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    float flatSq(float y0) const { return x * x + y0 + z * z; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
};
struct Pos { float x, y, z; };
struct Axis { float x, y, z; };
struct Transform { Axis axis[3]; Pos position; const Pos &P() const { return position; } };
struct Row { float x, y, z, w; };
struct Mat44 {
    Row row[4];
    Mat44(const Transform &t) {
        row[0].x = t.axis[0].x; row[0].y = t.axis[0].y; row[0].z = t.axis[0].z; row[0].w = 0.0f;
        row[1].x = t.axis[1].x; row[1].y = t.axis[1].y; row[1].z = t.axis[1].z; row[1].w = 0.0f;
        row[2].x = t.axis[2].x; row[2].y = t.axis[2].y; row[2].z = t.axis[2].z; row[2].w = 0.0f;
        row[3].x = t.P().x; row[3].y = t.P().y; row[3].z = t.P().z; row[3].w = 1.0f;
    }
    const Row &R(int i) const { return row[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
extern "C" void construct_801f7538(Ptr32<Transform>, float, float, float, float);
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline const float &Clamp(const float &v, const float &lo, const float &hi) { return fmax(fmin(v, hi), lo); }
inline const float &fminr(const float &a, const float &b) { return b < a ? b : a; }
struct Jet { char u0[92]; float yaw; char u96[4]; Vec v; char u112[44]; float tilt; };
extern "C" void d27h_jetpack_tilt_800abd30(Ptr32<Jet> self) {
    float zero = 0.0f;
    Vec h(self->v.x, zero, self->v.z);
    if (h.flatSq(zero) == zero) {
        self->tilt = 0.5f;
        return;
    }
    float one = 1.0f;
    Vec fwd;
    Ptr32<Vec> q = &fwd;
    q->x = zero;
    q->y = zero;
    q->z = one;
    Transform m;
    construct_801f7538(&m, zero, one, zero, self->yaw);
    Vec out;
    Mat44(m).rotate(out, fwd);
    out.normalize();
    h.normalize();
    float d = h.dot(out);
    float a = acos_802e79e0(Clamp(d, -1.0f, 1.0f));
    self->tilt = a / 3.1415927f;
    self->tilt = fminr(self->tilt, 1.0f);
    self->tilt = fmax(self->tilt, 0.0f);
}



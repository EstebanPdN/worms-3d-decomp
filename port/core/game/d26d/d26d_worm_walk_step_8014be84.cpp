#include "w3d_ptr.h"
#line 1 "d26d_worm_walk_step_8014be84.cpp"
// GWMP8P rev0 0x8014be84. Turn a worm toward a walk direction and return its
// velocity: normalise the direction in place, measure the angle from the
// current forward axis by a clamped dot product, add it to the yaw by the
// side of the cross product, scale the direction by the body speed and step
// speed, and store the yaw only when +716 is set or the mode is 1. The
// advanced position copy is never written back in the original. Returns the
// direction times 10. Names are inferred.
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    Vec &operator*=(float k) { x *= k; y *= k; z *= k; return *this; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline float clamp(const float &v, const float &lo, const float &hi) { return fmax(fmin(v, hi), lo); }
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
struct Worm {
    char u0[552]; Ptr32<void> body; char u22c[4]; Vec pos; Vec rot;
    char u248[132]; int f2cc; char u2d0[40]; int mode;
};
extern "C" void construct_801f7538(Ptr32<Transform>, float, float, float, float);
extern "C" Ptr32<void> same_80342a74(Ptr32<void>);
extern "C" float scale_80178df0(Ptr32<void>);
extern Transform identity_8045e748;
extern "C" Vec d26d_worm_walk_step_8014be84(Ptr32<Worm> self, Vec &dir, float speed) {
    Transform m;
    m = identity_8045e748;
    Vec zero(0.0f, 0.0f, 0.0f);
    float a = 0.0f;
    Vec p = self->pos;
    Vec r = self->rot;
    float scale = scale_80178df0(same_80342a74(self->body));
    float rate = 10.0f;
    float l = dir.lenSq();
    if (l > 0.0f) {
        float f = 1.0f / sqrt_802e82c0(l);
        dir.x *= f; dir.y *= f; dir.z *= f;
    }
    construct_801f7538(&m, 0.0f, 1.0f, 0.0f, r.y);
    Vec fw(0.0f, 0.0f, 0.0f);
    Vec u(0.0f, 0.0f, 1.0f);
    m.apply(fw, u);
    float c = fw.dot(dir);
    c = clamp(c, -1.0f, 0.99999f);
    float side = (fw.z * dir.x - fw.x * dir.z) / (1.0f - c);
    a = acos_802e79e0(c);
    if (a > 6.2831855f) a = 6.2831855f;
    if (a < 0.0f) a = 0.0f;
    if (side > 0.0f) r.y += a;
    else r.y -= a;
    dir *= scale * speed;
    p += dir;
    if (self->f2cc || self->mode == 1) self->rot = r;
    Vec v = dir * rate;
    return v;
}



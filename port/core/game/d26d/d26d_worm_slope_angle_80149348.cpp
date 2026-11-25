#include "w3d_ptr.h"
#line 1 "d26d_worm_slope_angle_80149348.cpp"
// GWMP8P rev0 0x80149348. Compute a worm's slope angle (+768): zero on flat
// ground rules, otherwise the angle between the surface normal (0x80146f10)
// and up. It also computes the signed heading of the slope against the
// worm's forward axis and wraps it, but only uses it to decide whether the
// flattened normal has length; a zero-length flat normal stores 0. The
// wrapped heading is never read in the original. Names are inferred.
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
extern "C" float asin_802e7c30(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void flat(const Vec &o) { x = o.x; z = o.z; y = 0.0f; }
    void flatInto(Vec &h) const { h.x = x; h.y = 0.0f; h.z = z; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    void unit() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
};
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
struct Worm { char u0[576]; float yaw; char u244[136]; int f2cc; char u2d0[48]; float slope; char u304[52]; int f338; };
extern "C" void construct_801f7538(Ptr32<Transform>, float, float, float, float);
extern "C" Vec normal_80146f10(Ptr32<Worm>);
extern "C" void d26d_worm_slope_angle_80149348(Ptr32<Worm> self) {
    if (!self->f2cc && self->f338 >= 0) { self->slope = 0.0f; return; }
    Vec n = normal_80146f10(self);
    if (n.len() > 0.0f) {
        n.unit();
        Vec up(0.0f, 1.0f, 0.0f);
        Vec w;
        float c = up.dot(n);
        c = fmin(c, 1.0f);
        c = fmax(c, -1.0f);
        float angle = acos_802e79e0(c);
        Vec fw(0.0f, 0.0f, -1.0f);
        Transform m;
        construct_801f7538(&m, 0.0f, 1.0f, 0.0f, self->yaw);
        m.apply(w, fw);
        w.unit();
        Vec h; h.flat(n);
        if (h.len() > 0.0f) {
            h.unit();
            float e = w.dot(h);
            e = fmin(e, 1.0f);
            e = fmax(e, -1.0f);
            float t = asin_802e7c30(e);
            while (t < -3.1415927f) t += 6.2831855f;
            while (t > 3.1415927f) t -= 6.2831855f;
            self->slope = angle;
            return;
        }
        self->slope = 0.0f;
    }
}



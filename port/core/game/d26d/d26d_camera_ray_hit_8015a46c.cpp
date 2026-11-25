#include "w3d_ptr.h"
#line 1 "d26d_camera_ray_hit_8015a46c.cpp"
// GWMP8P rev0 0x8015a46c. Cast a camera ray: scale the direction by 1/1000,
// trace it up to 1000 steps and on a hit copy the trace point and normal.
// Clear the state value, then unless water is excluded find the step where
// the ray meets the water level; when that comes before the hit, report the
// water point with an up normal and set the state value. Returns whether
// anything was hit. Names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec &operator/=(float k) { float f = 1.0f / k; x *= f; y *= f; z *= f; return *this; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
struct Camera { char u0[64]; Ptr32<void> water; Ptr32<void> state; };
extern "C" void test_800b0824(const Vec &, const Vec &, const Vec &, int, int);
extern "C" void compute_800bd920();
extern "C" int update_80178d28(Ptr32<void>, Ptr32<int>);
extern "C" float level_80178df0(Ptr32<void>);
inline void setValue(Ptr32<void> p, int v) { update_80178d28(p, &v); }
extern int traceFrac_804b1764;
extern int traceReady_804b1784;
extern Vec tracePoint_8043ae20;
extern Vec traceNormal_8043ae38;
extern "C" int d26d_camera_ray_hit_8015a46c(Ptr32<Camera> self, const Vec &origin, Vec &dir, Vec &hit, Vec &normal, int noWater) {
    Vec zero(0.0f, 0.0f, 0.0f);
    dir /= 1000.0f;
    test_800b0824(origin, dir, zero, 1000, 1);
    int found = 1;
    int frac = traceFrac_804b1764;
    if (frac == 1001) found = 0;
    if (found) {
        hit = tracePoint_8043ae20;
        if (!traceReady_804b1784) compute_800bd920();
        normal = traceNormal_8043ae38;
    }
    setValue(self->state, 0);
    if (!noWater) {
        int t = (int)((level_80178df0(self->water) - origin.y) / dir.y);
        if (t > 0 && (!found || t < frac)) {
            found = 1;
            hit = origin + dir * (float)t;
            normal = Vec(0.0f, 1.0f, 0.0f);
            setValue(self->state, found);
        }
    }
    return found;
}



#include "w3d_ptr.h"
#line 1 "d24h_in_range_800cc070.cpp"
// Worms 3D GameCube PAL, 0x800cc070 (216 bytes). Line-of-fire range test:
// traces 1/100th of the segment from origin to target through 0x800b0824
// with range 100 and mode 1, then reports whether the distance global
// 0x804b1764 stayed at or below 100. Self is unused.
//
// The divisor goes through an inline operator/, so GCC 2.95 keeps the
// run-time division: 1.0f / 100.0f, pool order 100.0f then 1.0f. The result
// goes through a temporary and member-wise assignment, which reproduces the
// direction slot at +24, the difference at +40 and the temporary at +56.
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    void operator=(const Vec3 &o) { x = o.x; y = o.y; z = o.z; }
    Vec3(const Vec3 &o) { x = o.x; y = o.y; z = o.z; }
    Vec3 operator-(const Vec3 &o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator/(float f) const { float k = 1.0f / f; return Vec3(x * k, y * k, z * k); }
};

extern const Vec3 lbl_8045e788[];   // Zero vector.
extern int lbl_804b1764;            // Distance reached by the last trace.

extern "C" int fn_800b0824(Ptr32<const Vec3> from, Ptr32<const Vec3> dir, Ptr32<const Vec3> up, int range, int mode);

extern "C" int w3d_d24h_in_range_800cc070(Ptr32<void> self, Ptr32<const Vec3> target, Ptr32<const Vec3> origin) {
    Vec3 up(*lbl_8045e788);
    Vec3 dir;
    Vec3 d = *target - *origin;
    dir = d / 100.0f;
    fn_800b0824(origin, &dir, &up, 100, 1);
    return lbl_804b1764 <= 100;
}



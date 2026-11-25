#include "w3d_ptr.h"
#line 1 "d26e_camera_axes_801a0cf4.cpp"
// (Worms 3D GameCube PAL, 0x801a0cf4).
//
// Builds a camera's orthonormal axes: forward is eye minus target,
// normalized; side is the up vector minus its projection on forward. If that
// is degenerate, side falls back to the Y axis, then to the Z axis, each
// minus its projection; side is normalized, and up is side cross forward.
// Names are inferred from the arithmetic and from 0x801a1008, which reads
// these outputs.

struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec(const Vec &o) : x(o.x), y(o.y), z(o.z) {}
    Vec operator-(const Vec &o) const { Vec r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    Vec operator*(float s) const { Vec r; r.x = x * s; r.y = y * s; r.z = z * s; return r; }
    Vec &operator-=(const Vec &o) { x -= o.x; y -= o.y; z -= o.z; return *this; }
    float Dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    float LengthSq() const { return x * x + y * y + z * z; }
};
struct Camera { char unknown00[176]; Vec eye; Vec target; Vec up; };
extern "C" float fn_802e82c0(float);
extern const float constant_803a9b38[], constant_803a9b3c[], constant_803a9b40[];
extern "C" void w3d_d26e_camera_axes_801a0cf4(Ptr32<Camera> self, Ptr32<Vec> up, Ptr32<Vec> side, Ptr32<Vec> forward) {
    *forward = self->eye - self->target;
    float len0 = fn_802e82c0(forward->LengthSq());
    float one = constant_803a9b38[0];
    float inv = one / len0;
    forward->x *= inv; forward->y *= inv; forward->z *= inv;
    *side = self->up - *forward * self->up.Dot(*forward);
    float len = fn_802e82c0(side->LengthSq());
    float eps = constant_803a9b3c[0];
    if (len < eps) {
        float zero = constant_803a9b40[0];
        side->y = one; side->x = zero; side->z = zero;
        *side -= *forward * forward->y;
        if (fn_802e82c0(side->LengthSq()) < eps) {
            side->x = zero; side->y = zero; side->z = one;
            *side -= *forward * forward->z;
        }
    }
    float s = constant_803a9b38[0] / fn_802e82c0(side->LengthSq());
    side->x *= s; side->y *= s; side->z *= s;
    up->x = side->y * forward->z - side->z * forward->y;
    up->y = side->z * forward->x - side->x * forward->z;
    up->z = side->x * forward->y - side->y * forward->x;
}



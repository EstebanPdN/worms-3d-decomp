#include "w3d_ptr.h"
#line 1 "d17d_direction_slope_8014ca54.cpp"
// d17d: 0x8014ca54 (308 bytes). Slope angle of a direction: normalise it and
// return acos of its dot product with the up axis clamped to [-1, 1], or
// pi/2 for a zero vector. Built with -mps-float (SN paired-single mode).
struct D17dVec3 {
    float x, y, z;
    D17dVec3(const D17dVec3 &v) { x = v.x; y = v.y; z = v.z; }
    D17dVec3(float a, float b, float c) { x = a; y = b; z = c; }
    float Dot(const D17dVec3 &v) const { float vz = v.z; return z * vz + (x * v.x + y * v.y); }
    void Scale(float s) { x *= s; y *= s; z *= s; }
};
static inline const float &d17d_min(const float &a, const float &b) { return b < a ? b : a; }
static inline const float &d17d_max(const float &a, const float &b) { return a < b ? b : a; }
extern "C" float w3d_sqrt_802e82c0(float);
extern "C" float w3d_acos_802e79e0(float);
extern "C" float d17d_direction_slope_8014ca54(Ptr32<const D17dVec3> direction)
{
    D17dVec3 d(*direction);
    float squared = d.Dot(d);
    if (squared == 0.0f) return 1.5707963705062866f;
    d.Scale(1.0f / w3d_sqrt_802e82c0(squared));
    D17dVec3 up(0.0f, 1.0f, 0.0f);
    float c = up.Dot(d);
    c = d17d_min(c, 1.0f);
    c = d17d_max(c, -1.0f);
    return w3d_acos_802e79e0(c);
}



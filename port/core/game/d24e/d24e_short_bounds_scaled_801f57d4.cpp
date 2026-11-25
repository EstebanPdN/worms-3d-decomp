#include "w3d_ptr.h"
#line 1 "d24e_short_bounds_scaled_801f57d4.cpp"
// Bounds of a short-vector array, scaled (Worms 3D GameCube PAL, 0x801f57d4).
//
// Finds the per-axis minimum and maximum of count packed vectors, then writes
// six floats: min then max, each axis multiplied by scale[axis] and by the
// constant 0x803b15c0. Built with -mfast-cast: the short to float conversions
// are the quantized psq_l loads.
struct d24e_ShortVec {
    short x, y, z;
    void Min(const d24e_ShortVec &v) { if (v.x < x) x = v.x; if (v.y < y) y = v.y; if (v.z < z) z = v.z; }
    void Max(const d24e_ShortVec &v) { if (v.x > x) x = v.x; if (v.y > y) y = v.y; if (v.z > z) z = v.z; }
};
extern const float constant_803b15c0[];

extern "C" void w3d_d24e_short_bounds_scaled_801f57d4(Ptr32<float> out, Ptr32<const d24e_ShortVec> p, int count, Ptr32<const float> scale) {
    d24e_ShortVec minimum = *p;
    d24e_ShortVec maximum = *p;
    for (int i = 1; i < count; ++i) {
        const d24e_ShortVec &v = p[i];
        minimum.Min(v);
        maximum.Max(v);
    }
    float c = constant_803b15c0[0];
    out[0] = scale[0] * minimum.x * c;
    out[1] = scale[1] * minimum.y * c;
    out[2] = scale[2] * minimum.z * c;
    out[3] = scale[0] * maximum.x * c;
    out[4] = scale[1] * maximum.y * c;
    out[5] = scale[2] * maximum.z * c;
}



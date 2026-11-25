// Bounds of a short-vector array, fixed point (Worms 3D GameCube PAL, 0x801f5970).
//
// Finds the per-axis minimum and maximum of count packed vectors, then writes
// six floats, min then max, each axis multiplied by 1 / (1 << shift); the 1.0f
// is the constant 0x803b15d0. Built with -mfast-cast: the short to float
// conversions are the quantized psq_l loads.
struct d24e_ShortVec {
    short x, y, z;
    void Min(const d24e_ShortVec &v) { if (v.x < x) x = v.x; if (v.y < y) y = v.y; if (v.z < z) z = v.z; }
    void Max(const d24e_ShortVec &v) { if (v.x > x) x = v.x; if (v.y > y) y = v.y; if (v.z > z) z = v.z; }
};
extern const float constant_803b15d0[];
extern "C" void w3d_d24e_short_bounds_fixed_801f5970(float *out, const d24e_ShortVec *p, int count, int shift) {
    d24e_ShortVec minimum = *p;
    d24e_ShortVec maximum = *p;
    for (int i = 1; i < count; ++i) {
        const d24e_ShortVec &v = p[i];
        minimum.Min(v);
        maximum.Max(v);
    }
    float c = constant_803b15d0[0] / (float)(1 << shift);
    out[0] = minimum.x * c;
    out[1] = minimum.y * c;
    out[2] = minimum.z * c;
    out[3] = maximum.x * c;
    out[4] = maximum.y * c;
    out[5] = maximum.z * c;
}

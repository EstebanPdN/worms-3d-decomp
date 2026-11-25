// GWMP8P rev0 0x8001bc1c. AI ballistic aim solver: returns an aim vector
// from one point to another, or a fixed 'no solution' vector (built once)
// when the target is above or too far. Starts from zero and iterates five
// times with halving step: predicts the offset of the current aim from the
// wind parameters (0x8001c134, and 0x8001c250 with interpolation for far
// drops), compares it with the wanted offset and moves the aim by the error.
// Names and the guard's form are inferred.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    Vec operator*(float f) const { Vec r; r.x = x * f; r.y = y * f; r.z = z * f; return r; }
    Vec operator-(const Vec &o) const { Vec r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
inline Vec Lerp(Vec a, Vec b, float t) { Vec r; r.x = (b.x - a.x) * t + a.x; r.y = (b.y - a.y) * t + a.y; r.z = (b.z - a.z) * t + a.z; return r; }
extern "C" void w3d_d33a_wind_aim_angle_8001c36c(const Vec *, Vec *, float *);
extern "C" Vec cc25a_vector_scaled_offsets_8001c134(const Vec *, const Vec *, const Vec *, float);
extern "C" Vec cc25a_vector_scaled_offsets_v2_8001c250(const Vec *, const Vec *, const Vec *, float);
extern int g_none_ready_804ac8ec;
extern Vec g_none_8041e774[];
extern Vec zero_8045e788[];
extern "C" Vec w3d_d40a_aim_solver_8001bc1c(const Vec &from, const Vec &to)
{
    if (!g_none_ready_804ac8ec) {
        g_none_8041e774[0].x = 2.0f;
        g_none_8041e774[0].y = 0.0f;
        g_none_8041e774[0].z = 0.0f;
        g_none_ready_804ac8ec = 1;
    }
    Vec d = to - from;
    Vec flat = d;
    flat.y = 0.0f;
    if (d.y >= 0.0f || flat.len() > 500.0f) return g_none_8041e774[0];
    Vec p = zero_8045e788[0];
    Vec out;
    float angle;
    float step = 1.0f;
    float half = 0.5f;
    w3d_d33a_wind_aim_angle_8001c36c(&p, &out, &angle);
    if (d.y >= -29.0f) {
        for (int i = 0; i <= 4; i++) {
            Vec a = cc25a_vector_scaled_offsets_8001c134(zero_8045e788, &p, &out, angle);
            float t = d.y / -29.0f;
            Vec v;
            v.x = a.x * t;
            v.y = a.y * t;
            v.z = a.z * t;
            Vec e = d - v;
            if (e.len() / -d.y > 0.75f) return g_none_8041e774[0];
            Vec f = e;
            p += f * step;
            step *= half;
        }
    } else {
        for (int i = 0; i <= 4; i++) {
            Vec a = cc25a_vector_scaled_offsets_8001c134(zero_8045e788, &p, &out, angle);
            Vec b = cc25a_vector_scaled_offsets_v2_8001c250(zero_8045e788, &p, &out, angle);
            Vec v = Lerp(a, b, (d.y + 29.0f) / -28.0f);
            Vec e = d - v;
            if (e.len() / -d.y > 1.6206896f) return g_none_8041e774[0];
            Vec f = e;
            f.normalize();
            p += f * step;
            step *= half;
        }
    }
    return p;
}

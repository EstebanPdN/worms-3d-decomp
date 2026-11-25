#include "w3d_ptr.h"
#line 1 "d27a_ballistic_refine_contact_80040ff4.cpp"
// GWMP8P rev0 0x80040ff4. Refines the time at which a ballistic path enters
// a sphere by five bisection steps. Names are inferred from the original
// instructions.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator*(float s) const { Vec r; r.x = x * s; r.y = y * s; r.z = z * s; return r; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
    void SetSum(const Vec &a, const Vec &b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; }
    float LengthSq() const { return x * x + y * y + z * z; }
};
extern Vec g_velocity_80427414;
extern Vec g_accel_80427438;
extern Vec g_position_80427444;
extern float g_radius_804b17d8;
extern float g_time_804b17d4;
extern "C" int w3d_d27a_ballistic_refine_contact_80040ff4(float a, float b)
{
    Vec p;
    Vec step;
    Vec half;
    half = g_accel_80427438 * (a * a * 0.5f);
    step = g_velocity_80427414 * a;
    p.SetSum(g_position_80427444, step);
    p += half;
    if (p.LengthSq() <= g_radius_804b17d8) return 1;
    int found = 0;
    for (int i = 0; i < 5; i++) {
        float mid = (a + b) * 0.5f;
        half = g_accel_80427438 * (a * a * 0.5f);
        step = g_velocity_80427414 * a;
        p.SetSum(g_position_80427444, step);
        p += half;
        if (p.LengthSq() <= g_radius_804b17d8) {
            b = mid;
            found = 1;
            g_time_804b17d4 = b;
        } else {
            a = mid;
        }
    }
    return found;
}



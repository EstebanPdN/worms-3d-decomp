#include "w3d_ptr.h"
#line 1 "d27a_follow_update_8002ce24.cpp"
// GWMP8P rev0 0x8002ce24. Eases the positions and direction of a follow
// object towards their goals by property-driven rates. Names are inferred
// from the original instructions.
extern "C" float w3d_auto_80178df0(Ptr32<void>);
extern "C" float w3d_cx9c_cosf_802e86d4(float);
extern "C" float w3d_cx9c_sinf_802e88ac(float);
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator*(float s) const { Vec r; r.x = x * s; r.y = y * s; r.z = z * s; return r; }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
    Vec operator-(const Vec &o) const { Vec r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    float LengthSq() const { return x * x + y * y + z * z; }
    void Normalize() { float k = 1.0f / sqrt_802e82c0(LengthSq()); x *= k; y *= k; z *= k; }
};
inline const float &Min(const float &a, const float &b) { return a < b ? a : b; }
inline const float &Max(const float &a, const float &b) { return a < b ? b : a; }
inline void Clamp(float &v, const float &lo, const float &hi) { v = Max(Min(v, hi), lo); }
struct Follow {
    int unknown00;
    Vec a;             /* +4 */
    Vec b;             /* +16 */
    Vec dir;           /* +28 */
    char unknown28[40];
    float angle;       /* +80 */
    float target;      /* +84 */
    Vec a_goal;        /* +88 */
    Vec b_goal;        /* +100 */
    Vec dir_goal;      /* +112 */
    char unknown7c[8];
    int k_a;           /* +132 */
    int k_b;           /* +136 */
    int k_dir;         /* +140 */
    int unknown90;
    int k_angle;       /* +148 */
    char unknown98[20];
    int limit;         /* +172 */
};
extern "C" void w3d_d27a_follow_update_8002ce24(Ptr32<Follow> self)
{
    float ka = w3d_auto_80178df0((Ptr32<void>)w3d::G(self->k_a));
    float kb = w3d_auto_80178df0((Ptr32<void>)w3d::G(self->k_b));
    float kd = w3d_auto_80178df0((Ptr32<void>)w3d::G(self->k_dir));
    float t = w3d_auto_80178df0((Ptr32<void>)w3d::G(self->k_angle));
    self->angle = self->target * t + self->angle * (1.0f - t);
    float c = w3d_cx9c_cosf_802e86d4(self->angle);
    float s = w3d_cx9c_sinf_802e88ac(self->angle);
    self->dir_goal.Set(c, 0.0f, s);
    const float start = 500.0f;
    const float rate = 0.0001f;
    float da = (self->a - self->a_goal).LengthSq();
    float db = (self->b - self->b_goal).LengthSq();
    if (da > start) ka *= (da - start) * rate + 1.0f;
    if (db > start) kb *= (db - start) * rate + 1.0f;
    float lo = 0.0f, hi = 1.0f;
    Clamp(ka, lo, hi);
    float lo2 = 0.0f, hi2 = 1.0f;
    Clamp(kb, lo2, hi2);
    self->a = self->a * (1.0f - ka) + self->a_goal * ka;
    self->b = self->b * (1.0f - kb) + self->b_goal * kb;
    self->dir = self->dir * (1.0f - kd) + self->dir_goal * kd;
    self->dir.Normalize();
    self->a.y = Min(w3d_auto_80178df0((Ptr32<void>)w3d::G(self->limit)), self->a.y);
    self->a_goal.y = Min(w3d_auto_80178df0((Ptr32<void>)w3d::G(self->limit)), self->a_goal.y);
}



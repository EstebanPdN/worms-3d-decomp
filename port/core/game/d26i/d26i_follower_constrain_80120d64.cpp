#include "w3d_ptr.h"
#line 1 "d26i_follower_constrain_80120d64.cpp"
// GWMP8P rev0 0x80120d64. Constrains a follower's position to a reach around
// a target and blends towards it.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
};
inline float dist(const Vec &a, const Vec &b) {
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return sqrt_802e82c0(dx * dx + dy * dy + dz * dz);
}
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float s) { Vec r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
struct Config { char u0[32]; float reach; float blend; };
struct Follower { char u0[4]; Vec pos; char u16[72]; Ptr32<void> config; };
extern "C" Ptr32<void> w3d_ref_80341584(Ptr32<void>);
extern "C" Ptr32<Config> w3d_cfg_801797b4(Ptr32<void>);
extern "C" void w3d_a_801211a0(Ptr32<Follower>, Vec &, const Vec &);
extern "C" void w3d_b_801212d4(Ptr32<Follower>, Vec &, const Vec &);
extern "C" void w3d_pull_8012100c(Ptr32<Follower>, Vec &, const Vec &);
extern "C" void d26i_follower_constrain_80120d64(Ptr32<Follower> self, const Vec &from, const Vec &to) {
    Ptr32<Config> cfg = w3d_cfg_801797b4(w3d_ref_80341584(self->config));
    float reach = cfg->reach;
    float d0 = dist(from, self->pos);
    float d1 = dist(to, self->pos);
    if (d1 <= d0 && d1 > 0.0f && d1 < reach) {
        Vec dir = self->pos - to;
        dir.normalize();
        Vec goal = to + dir * reach;
        w3d_a_801211a0(self, goal, self->pos);
        w3d_b_801212d4(self, goal, self->pos);
        w3d_pull_8012100c(self, goal, self->pos);
        self->pos = goal * cfg->blend + self->pos * (1.0f - cfg->blend);
    }
}



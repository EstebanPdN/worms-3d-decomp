#include "w3d_ptr.h"
#line 1 "d32i_camera_update_80120354.cpp"
// d32i: 0x80120354. Camera per-frame update: advances the tick counter, runs
// the two follow solvers while the timer is active, applies the position
// change, then blends look, aim and zoom.
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
struct Config { char u0[28]; float height; float pad32; float pad36; float trail; float blend; };
struct Prop;
extern "C" float w3d_prop_float_80178df0(Ptr32<Prop>);
struct Camera {
    char u0[8]; float zoom; char u12[4]; Vec look; Vec aim; char u40[24]; Ptr32<Prop> base; char u68[8]; Ptr32<void> timer; char u80[4]; unsigned int ticks; Ptr32<void> config;
    char u92[4]; Vec pos; Vec v108; Vec v120; Vec v132; char u144[20]; Ptr32<Prop> rate; int following;
};
extern "C" Ptr32<void> w3d_ref_80341584(Ptr32<void>);
extern "C" Ptr32<Config> w3d_cfg_801797b4(Ptr32<void>);
extern "C" int w3d_active_80164fc8(Ptr32<void>);
extern "C" void w3d_a_80120648(Ptr32<Camera>, Ptr32<Vec>, Ptr32<Vec>, Ptr32<Vec>, Ptr32<Vec>);
extern "C" Ptr32<void> w3d_b_8011fc48(Ptr32<Camera>, Ptr32<Vec>, Ptr32<Vec>, Ptr32<Vec>, Ptr32<Vec>);
extern "C" void w3d_c_80120d64(Ptr32<Camera>, const Vec &, const Vec &);
extern Vec target_8044f2b4[];
extern const float scale_8039b6c4[];
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
extern "C" void d32i_camera_update_80120354(Ptr32<Camera> self, float dt) {
    Ptr32<Config> cfg = w3d_cfg_801797b4(w3d_ref_80341584(self->config));
    self->ticks += (unsigned int)(dt * scale_8039b6c4[0]);
    Vec old(self->pos);
    if (w3d_active_80164fc8(self->timer)) {
        w3d_a_80120648(self, &self->pos, &self->v120, &self->v108, &self->v132);
        w3d_b_8011fc48(self, &self->pos, &self->v120, &self->v108, &self->v132);
    }
    w3d_c_80120d64(self, old, self->pos);
    if (self->following) {
        self->look = self->pos * cfg->blend + self->look * (1.0f - cfg->blend);
    }
    self->aim = target_8044f2b4[0] * cfg->trail + self->aim * (1.0f - cfg->trail);
    float h = w3d_prop_float_80178df0(self->base) + cfg->height;
    float m = fmax(h, self->zoom);
    float a = w3d_prop_float_80178df0(self->rate);
    float b = w3d_prop_float_80178df0(self->rate);
    self->zoom = m * a + self->zoom * (1.0f - b);
}



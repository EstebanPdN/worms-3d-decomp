#include "w3d_ptr.h"
#line 1 "d33g_camera_aim_limits_80071e30.cpp"
// GWMP8P rev0 0x80071e30. Camera aim limits along a flight path: projects
// the camera position onto the flattened path direction, samples the path a
// little ahead, and flags whether the aim is above or below the allowed
// slope; near the end of the path it uses the camera matrix up vector to set
// the swap flag. Field names are inferred.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void operator-=(const Vec &b) { x -= b.x; y -= b.y; z -= b.z; }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    float lenSq() const { return dot(*this); }
    float len() const { return sqrt_802e82c0(lenSq()); }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
struct Mat {
    Vec r[3];
    const Vec &R(int i) const { return r[i]; }
    void apply(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
    Vec operator*(const Vec &v) const { Vec o; apply(o, v); return o; }
};
struct Path { Vec a; Vec b; char u24[152]; float t176; };
extern Path g_8042ff68[];
extern "C" void eval_800d75f0(Ptr32<Path>, Ptr32<Vec>, float);
struct Cam { char u0[36]; Vec pos; Vec aim; char u60[64]; Mat m; char u160[148]; int a308, a312; };
extern int flip_804aaaec;
extern "C" void w3d_d33g_camera_aim_limits_80071e30(Ptr32<Cam> self) {
    Ptr32<Path> path = g_8042ff68;
    Vec p, q;
    const float zero = 0.0f;
    eval_800d75f0(path, &p, path->t176);
    eval_800d75f0(path, &q, zero);
    Vec d = p - q;
    d.y = zero;
    float inv = 1.0f / d.len();
    d.x *= inv; d.y *= inv; d.z *= inv;
    const float bias = 10.0f;
    Vec v = self->pos - path->a;
    Vec f = v;
    f.y = zero;
    Vec g = path->b;
    g.y = zero;
    float n = f.dot(d) + bias;
    float t = n / g.len();
    Vec e;
    eval_800d75f0(path, &e, t);
    Vec x = e - self->pos;
    Vec fx = x;
    fx.y = zero;
    float slope = x.y / fx.dot(d);
    Vec fa = self->aim;
    fa.y = zero;
    self->a312 = 0;
    self->a308 = 0;
    float c = fa.dot(d);
    float s = slope * c;
    float h = c * 0.05f;
    if (self->aim.y > s + h && self->aim.y > -c * bias) self->a308 = 1;
    if (self->aim.y < s - h && self->aim.y < c * bias) self->a312 = 1;
    Vec pt;
    float end = g_8042ff68->t176;
    eval_800d75f0(g_8042ff68, &pt, end);
    Vec to = pt;
    to -= self->pos;
    Vec ft = to;
    ft.y = 0.0f;
    Vec w = ft - fa;
    if (w.lenSq() > ft.lenSq() && t < end) {
        Vec n = self->m * Vec(0.0f, 1.0f, 0.0f);
        if (n.y > 0.0f) flip_804aaaec = 1;
        self->a312 = 0;
        self->a308 = 0;
        if (self->aim.y > 0.0f) self->a308 = 1;
        else self->a312 = 1;
    }
    if (flip_804aaaec) {
        int a = self->a308, b = self->a312;
        self->a312 = a;
        self->a308 = b;
    }
}



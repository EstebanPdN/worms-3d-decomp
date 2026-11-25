#include "w3d_ptr.h"
#line 1 "d31g_free_camera_update_80072534.cpp"
// GWMP8P rev0 0x80072534. Free camera update: turns yaw and pitch from the
// input bits, rebuilds the forward and right vectors from their sines and
// cosines, the up vector by cross product, moves the position along forward,
// right and up by speed times elapsed time, and sets the look point. Bit
// meanings inferred.
extern "C" float sin_802e88ac(float);
extern "C" float cos_802e86d4(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; }
    void operator-=(const Vec &o) { x -= o.x; y -= o.y; z -= o.z; }
};
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline void Cross(Vec &o, const Vec &a, const Vec &b) {
    o.x = a.y * b.z - a.z * b.y;
    o.y = a.z * b.x - a.x * b.z;
    o.z = a.x * b.y - a.y * b.x;
}
extern "C" int flag_80178d1c(Ptr32<void>);
struct Input { unsigned bits; };
struct Cam { char u0[4]; Vec pos; Vec look; Vec up; char u40[36]; float speed; float turn; float yaw; float pitch; Ptr32<void> mode; };
extern float k_8037ccc8[];
extern "C" void w3d_d31g_free_camera_update_80072534(Ptr32<Cam> self, Ptr32<Input> in, float dt) {
    if (in->bits & 0x08000000) self->yaw += self->turn * dt;
    else if (in->bits & 0x04000000) self->yaw -= self->turn * dt;
    if (flag_80178d1c(self->mode)) {
        if (in->bits & 0x01000000) self->pitch += self->turn * dt;
        else if (in->bits & 0x02000000) self->pitch -= self->turn * dt;
    }
    Vec f;
    f.x = sin_802e88ac(self->yaw);
    f.y = sin_802e88ac(self->pitch);
    f.z = cos_802e86d4(self->yaw);
    Vec r;
    r.x = -cos_802e86d4(self->yaw);
    r.y = k_8037ccc8[0];
    r.z = sin_802e88ac(self->yaw);
    Cross(self->up, r, f);
    if (in->bits & 0x10000000) self->pos += f * self->speed * dt;
    else if (in->bits & 0x20000000) self->pos -= Vec(f * self->speed) * dt;
    if ((int)in->bits < 0) self->pos -= r * self->speed * dt;
    else if (in->bits & 0x40000000) self->pos += r * self->speed * dt;
    if (!flag_80178d1c(self->mode)) {
        if (in->bits & 0x01000000) self->pos += self->up * self->speed * dt;
        else if (in->bits & 0x02000000) self->pos -= self->up * self->speed * dt;
    }
    self->look = self->pos + f;
}



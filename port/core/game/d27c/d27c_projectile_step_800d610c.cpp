#include "w3d_ptr.h"
#line 1 "d27c_projectile_step_800d610c.cpp"
// d27c: 0x800d610c. Advances a projectile by one fixed step of 20 by constant acceleration unless a trace hits first. On a hit it snaps to the hit point and stops; below the water level it stops and plays the Splash effect. Names are inferred.
struct W { int a, b, c; };
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec3 &operator+=(const Vec3 &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
inline Vec3 operator+(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec3 operator*(const Vec3 &a, float s) { Vec3 r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
struct Effects { struct V { Ptr32<void> u[24]; Ptr32<void (Ptr32<Effects>, Ptr32<const char>, Ptr32<Vec3>)> play; }; Ptr32<struct V> vtable; };
struct Svc { char u[108]; Ptr32<Effects> fx; };
struct Self {
    char u0[28]; Vec3 pos; Vec3 vel; Vec3 acc; char u64[28];
    int flying; int landed; int stamp0; int stamp1; Ptr32<void> h108; Ptr32<void> h112; Ptr32<void> h116;
};
extern W hit_8043ae20[], zero_8045e788[];
extern unsigned traceFrac_804b1764;
extern int stamp1_804b17a8, stamp0_804b17ac;
extern Ptr32<Svc> svc_804b1788;
extern char splash_80388e58[];
extern "C" float value_80178df0(Ptr32<void>);
extern "C" int trace_800b0824(const Vec3 &, const Vec3 &, const Vec3 &, int, int);
extern "C" void bounds_800d60ac(Ptr32<Self>);
extern "C" void d27c_projectile_step_800d610c(Ptr32<Self> self) {
    float g = value_80178df0(self->h108);
    self->acc.y = g * value_80178df0(self->h112);
    trace_800b0824(self->pos, self->vel, self->acc, 20, 1);
    float dt = 20.0f;
    if (traceFrac_804b1764 <= 20) {
        *(Ptr32<W>)&self->pos = hit_8043ae20[0];
        *(Ptr32<W>)&self->vel = zero_8045e788[0];
        self->stamp0 = stamp0_804b17ac;
        self->stamp1 = stamp1_804b17a8;
        self->flying = 0;
    } else {
        self->pos += self->vel * dt + self->acc * (dt * (dt * 0.5f));
        self->vel += self->acc * dt;
        if (self->pos.y <= value_80178df0(self->h116)) {
            self->flying = 0;
            self->landed = 1;
            Ptr32<Effects> fx = svc_804b1788->fx;
            if (fx) fx->vtable->play(fx, splash_80388e58, &self->pos);
        }
    }
    bounds_800d60ac(self);
}



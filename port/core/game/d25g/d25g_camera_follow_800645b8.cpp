#include "w3d_ptr.h"
#line 1 "d25g_camera_follow_800645b8.cpp"
/* Worms 3D GameCube PAL 0x800645b8. Moves a position toward its target: reads the +116 anchor vector and lowers it by the +56 height times the +108 speed; while the +40 blend is positive shows the marker, otherwise uses the +112 anchor. Within 0.3 on every axis it snaps and returns 1, hiding the marker once the blend is zero; otherwise it steps by the +136 rate and returns 0. Refreshes either way. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Object;
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    bool equals(const Vec3 &o, float eps) const;
};
inline bool Vec3::equals(const Vec3 &o, float eps) const {
    for (int i = 0; i < 3; i++)
        if (__builtin_fabsf((&x)[i] - (&o.x)[i]) > eps) return false;
    return true;
}
inline Vec3 operator-(const Vec3 &a, const Vec3 &b) { Vec3 t(a.x - b.x, a.y - b.y, a.z - b.z); return t; }
struct Self { char u0[40]; float blend; char u44[12]; int height; Vec3 position; char u72[24]; int pending; char u100[8]; Ptr32<Object> speed; Ptr32<Object> targetB; Ptr32<Object> targetA; char u120[16]; Ptr32<Object> rate; };
extern "C" Ptr32<const Vec3> vector_80178ec4(Ptr32<Object>);
extern "C" float value_80178df0(Ptr32<Object>);
extern "C" void show_800649e8(Ptr32<Self>, int);
extern "C" void refresh_80064198(Ptr32<Self>);
extern "C" int w3d_d25g_camera_follow_800645b8(Ptr32<Self> self)
{
    Vec3 target(*vector_80178ec4(self->targetA));
    float s = value_80178df0(self->speed);
    target.y -= self->height * s;
    if (self->blend > 0.0f) show_800649e8(self, 1);
    else target = *vector_80178ec4(self->targetB);
    int done = 0;
    if (target.equals(self->position, 0.3f)) {
        done = 1;
        self->position = target;
        if (self->blend == 0.0f && self->pending) {
            self->pending = 0;
            show_800649e8(self, 0);
        }
    } else {
        Vec3 d(target - self->position);
        float r = value_80178df0(self->rate);
        d.x *= r; d.y *= r; d.z *= r;
        Vec3 &cur = self->position;
        cur.x += d.x;
        cur.y += d.y;
        cur.z += d.z;
    }
    refresh_80064198(self);
    return done;
}



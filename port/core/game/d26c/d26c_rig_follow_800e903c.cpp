#include "w3d_ptr.h"
#line 1 "d26c_rig_follow_800e903c.cpp"
// d26c: 0x800e903c. Blend a rig position toward its computed target and set its look angles by mode. Names are inferred.
// The target vector goes by value (the callee reads a temporary copy). The leading 1.0f of the pool stays extern.
extern "C" float sqrt_802e82c0(float);
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() {
        float d = lenSq();
        if (d > 0.0f) { float f = 1.0f / sqrt_802e82c0(d); x *= f; y *= f; z *= f; }
    }
    Vec3 operator*(float s) const { Vec3 r; r.x = x * s; r.y = y * s; r.z = z * s; return r; }
};
struct Desc { char u0[192]; float blend; };
struct Camera { struct V { Ptr32<void> u[20]; Ptr32<void (Ptr32<Camera>, Ptr32<float>, int)> look; }; Ptr32<struct V> vtable; };
struct Rig {
    char u0[28];
    Ptr32<void> h28;
    Ptr32<Camera> camera;
    Vec3 pos;
    float pitch;
    float yaw;
    float roll;
    char u60[24];
    Vec3 target;
    char u96[60];
    unsigned mode;
};
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> desc_801797b4(Ptr32<void>);
extern "C" void angles_800e9204(Ptr32<Rig>, Vec3, Ptr32<Vec3>);
extern "C" float spin_800e9678(Ptr32<Rig>);
inline Vec3 operator+(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
extern float one_8038b244[];
extern "C" void d26c_rig_follow_800e903c(Ptr32<Rig> self, int dt) {
    Ptr32<Desc> d = desc_801797b4(empty_80341584(self->h28));
    Vec3 a;
    angles_800e9204(self, self->target, &a);
    Vec3 goal = a * d->blend + self->pos * (one_8038b244[0] - d->blend);
    self->pos = goal;
    self->yaw = self->pos.y;
    switch (self->mode) {
    case 0: self->pitch = 0.0f; break;
    case 2: self->pitch = self->pos.x; break;
    case 1: self->pitch += spin_800e9678(self) * dt; break;
    }
    self->roll = 0.0f;
    self->camera->vtable->look(self->camera, &self->pitch, 0);
}



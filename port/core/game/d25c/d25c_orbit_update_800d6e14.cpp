#include "w3d_ptr.h"
#line 1 "d25c_orbit_update_800d6e14.cpp"
// d25c: 0x800d6e14. Advance an orbit: step the angle at +104, wrap it into 0..2pi, place the object on the circle
// around (+16, +24) with radius +96, and ease both heights (+8, +20) towards the ground height plus a margin.
// Names are inferred.
struct Vec3 { float x, y, z; };
struct Self {
    char u0[4];
    float x4;
    float f8;
    float z12;
    float cx16;
    float f20;
    float cz24;
    char u28[48];
    Ptr32<void> h76;
    char u80[12];
    Ptr32<void> h92;
    float radius;       // +96
    char u100[4];
    float angle;        // +104
};
extern "C" float value_80178df0(Ptr32<void>);
extern "C" float sinf_802e88ac(float);
extern "C" float cosf_802e86d4(float);
inline const float &greater(const float &a, const float &b) { return a < b ? b : a; }
extern "C" void d25c_orbit_update_800d6e14(Ptr32<Self> self, float dt) {
    self->angle += dt * value_80178df0(self->h76);
    while (self->angle < 0.0f) self->angle += 6.2831855f;
    while (self->angle > 6.2831855f) self->angle -= 6.2831855f;
    float a = self->angle;
    float s = sinf_802e88ac(a);
    float c = cosf_802e86d4(a);
    self->x4 = self->radius * s + self->cx16;
    self->z12 = self->radius * c + self->cz24;
    const float margin = 20.0f;
    float t1 = value_80178df0(self->h92) + margin;
    float hi1 = greater(t1, self->f8);
    float t2 = value_80178df0(self->h92) + margin;
    float hi2 = greater(t2, self->f20);
    const float blend = 0.1f;
    const float keep = 0.9f;
    self->f8 = self->f8 * keep + hi1 * blend;
    self->f20 = self->f20 * keep + hi2 * blend;
}



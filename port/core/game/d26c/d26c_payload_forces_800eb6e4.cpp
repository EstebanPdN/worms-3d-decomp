#include "w3d_ptr.h"
#line 1 "d26c_payload_forces_800eb6e4.cpp"
// d26c: 0x800eb6e4. Rebuild a payload's force for this frame from gravity and wind. Names are inferred from the math; the
// Desc flags at +528 and +480 are partial views.
extern "C" float cos_802e86d4(float);
extern "C" float sin_802e88ac(float);
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec3 operator*(float s) const { Vec3 r; r.x = x * s; r.y = y * s; r.z = z * s; return r; }
    Vec3 &operator+=(const Vec3 &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
struct W { int a, b, c; };
extern W zero_8045e788[];
struct Desc { char u0[480]; int wind; char u484[44]; int gravity; };
struct Actor {
    char u0[52];
    float vy;
    char u56[4];
    Vec3 force;
    char u72[36];
    float terminal;
    char u112[48];
    Ptr32<void> h160; Ptr32<void> h164; Ptr32<void> h168; Ptr32<void> h172; Ptr32<void> h176;
    char u180[12];
    Ptr32<void> h192;
};
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> desc_801797b4(Ptr32<void>);
extern "C" float value_80178df0(Ptr32<void>);
extern "C" Ptr32<void> empty_80342a74(Ptr32<void>);
extern "C" Ptr32<void> name_80342a78(Ptr32<void>);
extern "C" int value_80178d1c(Ptr32<void>);
extern "C" void d26c_payload_forces_800eb6e4(Ptr32<Actor> self) {
    Ptr32<Desc> d = desc_801797b4(empty_80341584(self->h192));
    *(Ptr32<W>)&self->force = zero_8045e788[0];
    if (d->gravity) {
        float g = value_80178df0(self->h172);
        self->force.y += g * value_80178df0(self->h176);
        if (self->terminal > 0.0f && self->vy < -self->terminal) self->force.y = 0.0f;
    }
    if (d->wind) {
        float angle = value_80178df0(empty_80342a74(self->h164));
        Vec3 dir;
        dir.x = cos_802e86d4(angle);
        dir.y = 0.0f;
        dir.z = sin_802e88ac(angle);
        float s = value_80178df0(empty_80342a74(self->h160));
        switch (value_80178d1c(name_80342a78(self->h168))) {
        case 0: self->force += dir * s; break;
        case 1: self->force += dir * s * s; break;
        }
    }
}



#include "w3d_ptr.h"
#line 1 "d26d_worm_apply_impulse_80148c14.cpp"
// GWMP8P rev0 0x80148c14. Apply an impulse scaled by a magnitude clamped to
// 1: skip when the worm is immune (0x80153f38), detach it if grounded, add
// the scaled vector to the velocity (+676, horizontal part dropped when +652
// is set). Above 0.06 the worm reacts; above 0.15 with enough lift it goes
// to mode 11 with the Worm Blasted slot and launches (0x80150828), otherwise
// mode 9 or 26 with the Worm Hit slot. Names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
struct Class { char pad[20]; Ptr32<Class> base; };
inline int is_kind(Ptr32<const Class> c, Ptr32<const Class> t) {
    for (; c != t; c = c->base) if (c == c->base) return 0;
    return 1;
}
struct Worm {
    Ptr32<Ptr32<void>> vtable; char u4[648];
    int f28c; char u290[20]; Vec vel; char u2b0[28]; int f2cc; char u2d0[40]; int mode; char u2fc[40]; int f324[5]; int f338;
    Ptr32<Class> cls() { return ((Ptr32<Ptr32<Class> (Ptr32<Worm>)>)vtable[5])(this); }
};
extern "C" int immune_80153f38(Ptr32<Worm>);
extern "C" int grounded_801510c4(Ptr32<Worm>);
extern "C" void detach_8014df84(Ptr32<Worm>, int);
extern "C" void launch_80150828(Ptr32<Worm>);
extern "C" int slot_80022e20(Ptr32<const char>, Ptr32<const char>, int, Ptr32<int>);
extern Class classA_80361860[], classC_803618f0[];
extern const char blasted_803a129c[], hit_803a12ac[], entity_803a0e2c[];
extern "C" void d26d_worm_apply_impulse_80148c14(Ptr32<Worm> self, const Vec &impulse, float mag) {
    if (mag > 1.0f) mag = 1.0f;
    if (immune_80153f38(self)) return;
    if (grounded_801510c4(self)) detach_8014df84(self, 1);
    Vec v = impulse * mag;
    if (self->f28c) { v.z = 0.0f; v.x = 0.0f; }
    self->vel += v;
    if (mag > 0.06f) {
        if (mag > 0.15f && impulse.y > 0.15f) {
            self->mode = 11;
            if (is_kind(self->cls(), classA_80361860) || is_kind(self->cls(), classC_803618f0))
                slot_80022e20(blasted_803a129c, entity_803a0e2c, 2573, self->f324);
            launch_80150828(self);
        } else {
            if (self->f2cc || self->f338 < 0) self->mode = 26;
            else self->mode = 9;
            if (is_kind(self->cls(), classA_80361860) || is_kind(self->cls(), classC_803618f0))
                slot_80022e20(hit_803a12ac, entity_803a0e2c, 2582, self->f324);
        }
    }
}



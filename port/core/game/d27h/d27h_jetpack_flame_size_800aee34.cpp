#include "w3d_ptr.h"
#line 1 "d27h_jetpack_flame_size_800aee34.cpp"
// GWMP8P rev0 0x800aee34. Jetpack flame size. Names are inferred. Grows or
// shrinks the flame height with elapsed milliseconds according to thrust and
// hold flags, hides the flames at zero, otherwise shows them with a height
// wobble over a 500 ms period.
extern "C" float sin_802e88ac(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Part;
struct PartVt {
    Ptr32<void> u0[21];
    Ptr32<void (Ptr32<Part>, Ptr32<const Vec>, int)> scale;  // +84
    Ptr32<void (Ptr32<Part>, int)> show;                // +88
};
struct Part { Ptr32<PartVt> vt; };
struct Jet { char u0[44]; Ptr32<Part> a; Ptr32<Part> b; char u52[48]; Vec size; };
inline const float &fmin(const float &a, const float &b) { return b < a ? b : a; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
extern "C" void d27h_jetpack_flame_size_800aee34(Ptr32<Jet> self, int up, int hold, int ms) {
    if (up) {
        self->size.y += ms * 0.0001f;
        self->size.y = fmin(self->size.y, 10.0f);
    } else if (hold) {
        if (self->size.y > 5.0f) {
            self->size.y -= ms * 0.0005f;
            self->size.y = fmax(self->size.y, 5.0f);
        } else {
            self->size.y += ms * 0.0001f;
            self->size.y = fmin(self->size.y, 5.0f);
        }
    } else {
        self->size.y -= ms * 0.0005f;
        self->size.y = fmax(self->size.y, 0.0f);
    }
    if (self->size.y <= 0.0f) {
        self->a->vt->show(self->a, 0);
        self->b->vt->show(self->b, 0);
    } else {
        self->a->vt->show(self->a, 1);
        self->b->vt->show(self->b, 1);
        Vec s(self->size);
        float k = (int)((unsigned)ms % 500) / 500.0f;
        s.y += sin_802e88ac((k + k) * 3.1415927f) * 0.1f * s.y;
        self->a->vt->scale(self->a, &s, 0);
        self->b->vt->scale(self->b, &s, 0);
    }
}



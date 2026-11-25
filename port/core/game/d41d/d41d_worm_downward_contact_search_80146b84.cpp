#include "w3d_ptr.h"
#line 1 "d41d_worm_downward_contact_search_80146b84.cpp"
// d41d: 0x80146b84. Searches the contacts around a worm for one that blocks
// it: an upward-facing surface under the worm whose direction is more than a
// right angle from its motion, or any such surface when the worm is not
// moving. Class fields are partial views.
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    void unit() { float l = lenSq(); if (l > 0.0f) { float f = 1.0f / sqrt_802e82c0(l); x *= f; y *= f; z *= f; } }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline const float &clamp(const float &v, const float &lo, const float &hi) { return fmax(fmin(v, hi), lo); }
struct Worm {
    unsigned char u0[560]; Vec pos;
    unsigned char u572[104]; Vec vel; Vec u688;
    unsigned char u700[444]; char finder[4];
};
extern "C" void start_801263bc(Ptr32<void>, Ptr32<Vec>, Ptr32<Vec>, int);
extern "C" int next_801264fc(Ptr32<void>);
extern "C" void end_80126524(Ptr32<void>);
extern "C" Ptr32<Vec> target_8003f240(unsigned short);
extern unsigned short id_804aa95e;
inline Vec targetPos() { return *target_8003f240(id_804aa95e); }
extern "C" int w3d_d41d_worm_downward_contact_search_80146b84(Ptr32<Worm> self) {
    int found = 0;
    start_801263bc(self->finder, &self->vel, &self->u688, 20);
    int h = next_801264fc(self->finder);
    Vec p = self->pos;
    Vec d;
    Vec v = self->vel;
    p.y += 10.0f;
    v.unit();
    while (h != 65535) {
        d = p - targetPos();
        float m = d.lenSq();
        if (m > 0.0f) {
            float f = 1.0f / sqrt_802e82c0(m);
            d.x *= f; d.y *= f; d.z *= f;
            if (d.y >= 0.7072f) {
                if (v.lenSq() == 0.0f) { found = 1; break; }
                if (acos_802e79e0(clamp(d.dot(v), -1.0f, 1.0f)) >= 1.5707964f) { found = 1; break; }
            }
        }
        h = next_801264fc(self->finder);
    }
    end_80126524(self->finder);
    return found;
}



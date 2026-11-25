#include "w3d_ptr.h"
#line 1 "d25d_worm_turn_towards_8013b948.cpp"
// GWMP8P rev0 0x8013b948. Turn the worm towards a target: compute the yaw
// (+68) and target headings with atan2, wrap both into 0..2pi, take the
// angle delta 0x8013aa10, clamp it to plus or minus pi/4, add it to the yaw
// and play the right or left turn clip by sign. Names are inferred.
extern "C" float cos_802e86d4(float);
extern "C" float sin_802e88ac(float);
extern "C" float atan2_802e7e5c(float, float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline const float &fmin(const float &a, const float &b) { return b < a ? b : a; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
struct Mesh;
struct Worm { unsigned char u0[52]; Vec pos; unsigned char u64[4]; float yaw; unsigned char u72[400]; char clips[4]; };
extern "C" float delta_8013aa10(Ptr32<Worm>, float, float);
extern "C" int play_801359ec(Ptr32<Worm>, Ptr32<Mesh>, int, Ptr32<void>, float, float, float);
extern int right_804ab19c, left_804ab1a0;
extern "C" void d25d_worm_turn_towards_8013b948(Ptr32<Worm> self, const Vec &target, Ptr32<Mesh> mesh) {
    float ang = 1.5707964f - self->yaw;
    float c = cos_802e86d4(ang);
    float s = sin_802e88ac(ang);
    Vec f(c, 0.0f, s);
    Vec d = target - self->pos;
    float a = atan2_802e7e5c(f.x, f.z);
    float b = atan2_802e7e5c(d.x, d.z);
    while (a < 0.0f) a += 6.2831855f;
    while (a > 6.2831855f) a -= 6.2831855f;
    while (b < 0.0f) b += 6.2831855f;
    while (b > 6.2831855f) b -= 6.2831855f;
    float t = delta_8013aa10(self, b, a);
    t = fmax(t, -0.7853982f);
    t = fmin(t, 0.7853982f);
    self->yaw += t;
    if (t > 0.0f) play_801359ec(self, mesh, right_804ab19c, self->clips, 1.0f, 0.0f, 0.0f);
    else if (t < 0.0f) play_801359ec(self, mesh, left_804ab1a0, self->clips, 1.0f, 0.0f, 0.0f);
}



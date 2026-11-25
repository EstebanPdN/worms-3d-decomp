#include "w3d_ptr.h"
#line 1 "d25d_worm_turn_step_8014b6b0.cpp"
// GWMP8P rev0 0x8014b6b0. Worm turning step: adjust a copy of the rotation
// by the spin (+588) and, while a turn flag (+632, +636) is set, by a rate
// that grows with the time held, clamped to 500 ticks. Wrap the yaw into
// 0..2pi, store it back in states up to 1, move through 0x800b0824 with
// gravity (0,-10,0) and run 0x80149348 when at most 20 contacts remain.
// Names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void set(float a, float b, float c) { x = a; y = b; z = c; }
};
template <class T> inline const T &tmin(const T &a, const T &b) { return a < b ? a : b; }
template <class T> inline const T &tmax(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &clamp(const T &v, const T &lo, const T &hi) { return tmax(tmin(v, hi), lo); }
struct Context { unsigned char u[52]; int tick; };
struct Worm {
    unsigned char u0[560]; Vec pos; Vec rot; unsigned char u584[4]; float spin;
    unsigned char u592[40]; int turnA; int turnB;
    unsigned char u640[48]; Vec dest;
    unsigned char u700[48]; int startTick;
    unsigned char u752[8]; int state;
};
extern "C" Ptr32<Context> context_80165254();
extern "C" void move_800b0824(Ptr32<Vec>, Ptr32<Vec>, Ptr32<Vec>, int, int);
extern "C" void react_80149348(Ptr32<Worm>);
extern unsigned contacts_804b1764;
extern "C" float w3d_franco_aim_scale(void);   // Port (francotirador de UM): giro ÷ zoom con la mira puesta
extern "C" void d25d_worm_turn_step_8014b6b0(Ptr32<Worm> self) {
    Vec r = self->rot;
    const float k = w3d_franco_aim_scale();
    if (self->spin < 0.0f) r.y += -self->spin * 0.0200000014156f * k;
    if (self->spin > 0.0f) r.y -= self->spin * 0.0200000014156f * k;
    if (self->turnA || self->turnB) {
        int t = context_80165254()->tick - self->startTick;
        t = clamp(t, 0, 500);
        float s = (float)t * 0.001f / 500.0f;
        if (self->turnA) r.y += s * 20.0f * k;
        else r.y -= s * 20.0f * k;
    }
    while (r.y > 6.2831855f) r.y -= 6.2831855f;
    while (r.y < 0.0f) r.y += 6.2831855f;
    if (self->state <= 1) self->rot.y = r.y;
    Vec up(0.0f, -10.0f, 0.0f);
    move_800b0824(&self->pos, &up, &self->dest, 20, 1);
    if (contacts_804b1764 <= 20) react_80149348(self);
}



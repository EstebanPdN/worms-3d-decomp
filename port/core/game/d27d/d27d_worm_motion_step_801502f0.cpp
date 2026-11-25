#include "w3d_ptr.h"
#line 1 "d27d_worm_motion_step_801502f0.cpp"
// GWMP8P rev0 0x801502f0. Run one worm motion step: test the movement
// direction, hand over to the stuck step when moving and no longer
// colliding. When the test fails apply the velocity constraint and, unless
// the worm has stopped, predict 20 ticks ahead under constant acceleration
// and apply that motion, state 9. When it passes stop the worm on a sharp
// turn or low speed, state 10 or 25. Post a message when the speed exceeds
// 0.25. Names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    float len() const;
    void normalize();
};
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
inline float Vec::len() const { return sqrt_802e82c0(lenSq()); }
inline void Vec::normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline const float &clamp(const float &v, const float &lo, const float &hi) { return fmax(fmin(v, hi), lo); }
struct Tracer { int t; };
struct Worm {
    char u0[560]; Vec pos; char u23c[12]; int id;
    char u24c[72]; int f294; char u298[12]; Vec vel; Vec acc; char u2bc[16]; int moving; char u2d0[40]; int state; char u2fc[36]; int f320; char u324[20]; int flags;
    char u33c[324]; Tracer tracer; char u484[92]; Ptr32<void> minSpeed;
};
extern "C" Vec motion_direction_80146f10(Ptr32<Worm>);
extern "C" int blocked_80146b84(Ptr32<Worm>);
extern "C" int owner_8014c488(Ptr32<Worm>);
extern "C" int limit_8014c89c(Ptr32<Vec>);
extern "C" int limit_8014c978(Ptr32<Vec>);
extern "C" int collided_801418c4(Ptr32<Tracer>);
extern "C" void stuck_8014c4f4(Ptr32<Worm>);
extern "C" void constrain_8014b40c(Ptr32<Worm>);
extern "C" void advance_8014c6f4(Ptr32<Worm>);
extern "C" float level_80178df0(Ptr32<void>);
extern "C" void applyMotion_80153f80(Ptr32<Worm>, const Vec &, const Vec &);
extern "C" Ptr32<void> arena_801613f0(Ptr32<void>, int);
extern "C" short msgid_8015f5a0(Ptr32<void>, int);
extern "C" Ptr32<void> msg_init_800a82f0(Ptr32<void>, unsigned short, int);
extern "C" int post_8016239c(Ptr32<void>);
extern Ptr32<void> arena_804b1754;
extern int cache_804afc60;
extern const Vec zero_8045e788[];
extern "C" void d27d_worm_motion_step_801502f0(Ptr32<Worm> self) {
    Vec dir = motion_direction_80146f10(self);
    int ok;
    if (self->flags < 0) ok = blocked_80146b84(self);
    else if (owner_8014c488(self)) ok = limit_8014c89c(&dir);
    else ok = limit_8014c978(&dir);
    if (self->moving && !collided_801418c4(&self->tracer)) {
        stuck_8014c4f4(self);
        return;
    }
    if (!ok) {
        constrain_8014b40c(self);
        if (self->vel.len() < level_80178df0(self->minSpeed)) {
            advance_8014c6f4(self);
            if (self->state == 10) return;
        }
        float t = 20.0f;
        const Vec &p = self->pos;
        Vec out = p + self->vel * t + self->acc * (t * 0.5f * t);
        applyMotion_80153f80(self, p, out);
        self->moving = ok;
        self->state = 9;
    } else {
        if (self->vel.lenSq() == 0.0f) {
            if (!self->f294) self->state = 10;
            else self->state = 25;
            return;
        }
        constrain_8014b40c(self);
        Vec u = self->vel;
        u.normalize();
        Vec d = motion_direction_80146f10(self);
        float a = acos_802e79e0(clamp(u.dot(d), -1.0f, 1.0f));
        int f = self->f320;
        if (f || a <= 0.7853982f || self->vel.len() < level_80178df0(self->minSpeed)) {
            self->vel = zero_8045e788[0];
            if (!self->f294) self->state = 10;
            else self->state = 25;
        } else {
            self->moving = f;
        }
    }
    if (self->vel.len() > 0.25f) {
        Ptr32<void> m = arena_801613f0(arena_804b1754, 12);
        post_8016239c(msg_init_800a82f0(m, msgid_8015f5a0(&cache_804afc60, 1), self->id));
    }
}



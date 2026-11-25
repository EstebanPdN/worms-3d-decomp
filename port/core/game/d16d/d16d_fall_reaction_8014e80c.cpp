#include "w3d_ptr.h"
#line 1 "d16d_fall_reaction_8014e80c.cpp"
/* Fall reaction choice recovered from 0x8014e80c (SN ProDG g++ 2.95).
 * When the actor may fall (0x80153f58), a probe step is built from the actor
 * position to a point 40 units above it, scaled down by 1000, and the ground
 * probe 0x800b0824 runs 1000 steps with a zero offset vector. A probe result
 * of at most 1000 steps (0x804b1764) or a clock below 0.5 (0x801610a0) gives
 * mode 23 / actor value 25, otherwise mode 22 / value 24.
 * The difference vector is built by a two-point constructor that writes each
 * component in turn into its temporary, which is why the original stores the
 * difference to the stack slot later reused by the zero vector temporary.
 * operator/ multiplies by the reciprocal; after RTL inlining g++ keeps the
 * 1.0 / 1000.0 division. Float constants are pool literals in their original
 * order (0x803a1748 40.0, 0x803a174c 1000.0, 0x803a1750 1.0, 0x803a1754 0.5).
 * Layouts are partial observed views. */
struct D16dVec3 {
    float x, y, z;
    D16dVec3() {}
    D16dVec3(float a, float b, float c) : x(a), y(b), z(c) {}
    D16dVec3(const D16dVec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    D16dVec3(const D16dVec3 &to, const D16dVec3 &from) { x = to.x - from.x; y = to.y - from.y; z = to.z - from.z; }
};
static inline D16dVec3 operator*(const D16dVec3 &a, float s) { return D16dVec3(a.x * s, a.y * s, a.z * s); }
static inline D16dVec3 operator/(const D16dVec3 &a, float s) { return a * (1.0f / s); }
struct D16dActor {
    unsigned char unknown000[560];
    D16dVec3 position;                     /* +560 */
    unsigned char unknown23c[760 - 572];
    int mode;                              /* +760 */
};
extern "C" {
int w3d_auto_80153f58(Ptr32<D16dActor>);
extern D16dVec3 w3d_zero_8045e788[];
void w3d_fn_800b0824(Ptr32<D16dVec3> origin, Ptr32<D16dVec3> step, const D16dVec3 &offset, int steps, int flags);
extern unsigned int w3d_cast_result_804b1764;
float w3d_auto_801610a0(Ptr32<D16dActor>);
void w3d_motion_set_actor_value(Ptr32<D16dActor>, int);
void d16d_actor_choose_fall_reaction_8014e80c(Ptr32<D16dActor> self);
}

void d16d_actor_choose_fall_reaction_8014e80c(Ptr32<D16dActor> self)
{
    if (w3d_auto_80153f58(self)) {
        D16dVec3 target(self->position);
        target.y += 40.0f;
        D16dVec3 step = D16dVec3(target, self->position) / 1000.0f;
        w3d_fn_800b0824(&self->position, &step,
                        D16dVec3(w3d_zero_8045e788[0].x, w3d_zero_8045e788[0].y, w3d_zero_8045e788[0].z),
                        1000, 1);
        int collision = (int)w3d_cast_result_804b1764 <= 1000;
        float clock = w3d_auto_801610a0(self);
        if (collision || clock < 0.5f) {
            self->mode = 23;
            w3d_motion_set_actor_value(self, 25);
        } else {
            self->mode = 22;
            w3d_motion_set_actor_value(self, 24);
        }
    }
}



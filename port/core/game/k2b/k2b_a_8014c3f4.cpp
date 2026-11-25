#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_8014c3f4.c"
struct K2bVec3 { float x, y, z; };
struct K2bWorm { char pad0[632]; int flag_a; int flag_b; char pad1[160]; int has_input; };
extern Ptr32<void> w3d_motion_get_input_direction(Ptr32<struct K2bVec3> out, Ptr32<struct K2bWorm> self);
static inline float k2b_length_squared(Ptr32<const struct K2bVec3> v)
{
    return v->x * v->x + v->y * v->y + v->z * v->z;
}
int w3d_k2b_has_motion_input_8014c3f4(Ptr32<struct K2bWorm> self)
{
    struct K2bVec3 dir;
    if (self->has_input == 0)
        return 0;
    w3d_motion_get_input_direction(&dir, self);
    if (k2b_length_squared(&dir) != 0.0f || self->flag_a || self->flag_b)
        return 1;
    return 0;
}
// desc: Appears to report whether the worm has pending input: a nonzero input direction or either of two motion flags.

}

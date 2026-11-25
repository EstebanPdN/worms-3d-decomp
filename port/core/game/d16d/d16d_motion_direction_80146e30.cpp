#include "w3d_ptr.h"
#line 1 "d16d_motion_direction_80146e30.cpp"
/* Motion direction normalisation recovered from 0x80146e30 (SN ProDG g++ 2.95).
 * The collider's current vector (0x80141564) is copied with the implicit
 * copy constructor, normalised when its squared length is positive and
 * otherwise replaced by the up vector (0, 1, 0), then copied into the motion
 * object's direction at +1204. The float constants are ordinary literals
 * (pool 0x803a0fec = 0.0, 0x803a0ff0 = 1.0); with literals g++ issues the
 * fallback stores in the original z, x, y order through the inline Set().
 * Layouts are partial observed views. */
struct D16dVec3 {
    float x, y, z;
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    float LengthSquared() const { return x * x + y * y + z * z; }
    void Scale(float s) { x *= s; y *= s; z *= s; }
};
struct D16dMotion {
    unsigned char unknown000[1152];
    unsigned char collider[1204 - 1152];   /* +1152 */
    D16dVec3 direction;                    /* +1204 */
};
extern "C" {
Ptr32<const D16dVec3> w3d_member_80141564(Ptr32<void> collider);
float w3d_sqrt_802e82c0(float);
void d16d_motion_normalize_direction_80146e30(Ptr32<D16dMotion> self);
}

void d16d_motion_normalize_direction_80146e30(Ptr32<D16dMotion> self)
{
    D16dVec3 v = *w3d_member_80141564(self->collider);
    float squared = v.LengthSquared();
    if (squared > 0.0f) {
        v.Scale(1.0f / w3d_sqrt_802e82c0(squared));
    } else {
        v.Set(0.0f, 1.0f, 0.0f);
    }
    self->direction = v;
}



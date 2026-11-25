#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_801e51c8.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family template, 2026-10-22 (third session): facing term between a target's
 * heading and the direction to a goal point, wrapped and folded at a limit. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dVec4 { float x, y, z, w; } W3dVec4;
typedef Ptr32<void (Ptr32<void>, Ptr32<W3dVec4>)> W3dGet1;
typedef Ptr32<void (Ptr32<void>, Ptr32<W3dVec4>, Ptr32<W3dVec4>)> W3dGet2;
typedef Ptr32<void (Ptr32<void>, int, Ptr32<W3dVec4>)> W3dGetI;
float fn_802e7e5c(float, float);
float fn_802e88ac(float);
extern const float lbl_803b06f4[];
extern const float lbl_803b06f8[];
extern const float lbl_803b06fc[];
extern const float lbl_803b0700[];
extern const float lbl_803b0704[];
extern const float lbl_803b07d0[];
extern const float lbl_803b07d4[];
extern const float lbl_803b07d8[];
extern const float lbl_803b07dc[];
extern const float lbl_803b07e0[];

float w3d_facing_term_801e51c8(Ptr32<void> self, Ptr32<void> target)
{
    W3dVec4 position, forward, up, goal;
    float spare[6];
    Ptr32<void> source;
    float dx, dz, heading, angle, limit;
    if (!target)
        return lbl_803b06f4[0];
    (*(Ptr32<W3dGet1>)(*(Ptr32<Ptr32<char>>)target + 56))(target, &position);
    (*(Ptr32<W3dGet2>)(*(Ptr32<Ptr32<char>>)target + 60))(target, &forward, &up);
    source = FIELD(self, void *, 12);
    (*(Ptr32<W3dGetI>)(*(Ptr32<Ptr32<char>>)source + 68))(source, 3, &goal);
    dx = goal.x - position.x;
    dz = goal.z - position.z;
    heading = fn_802e7e5c(forward.x, forward.z);
    angle = fn_802e7e5c(dx, dz) - heading;
    if (angle < lbl_803b06f8[0])
        angle += lbl_803b06fc[0];
    else if (angle > lbl_803b0700[0])
        angle -= lbl_803b06fc[0];
    limit = lbl_803b0704[0];
    if (angle > limit)
        angle = limit - (angle - limit);
    else if (angle < -limit)
        angle = -limit - (angle + limit);
    return fn_802e88ac(angle);
}

float w3d_facing_term_801e663c(Ptr32<void> self, Ptr32<void> target)
{
    W3dVec4 position, forward, up, goal;
    float spare[6];
    Ptr32<void> source;
    float dx, dz, heading, angle, limit;
    if (!target)
        return lbl_803b07d0[0];
    (*(Ptr32<W3dGet1>)(*(Ptr32<Ptr32<char>>)target + 56))(target, &position);
    (*(Ptr32<W3dGet2>)(*(Ptr32<Ptr32<char>>)target + 60))(target, &forward, &up);
    source = FIELD(self, void *, 164);
    (*(Ptr32<W3dGetI>)(*(Ptr32<Ptr32<char>>)source + 68))(source, 3, &goal);
    dx = goal.x - position.x;
    dz = goal.z - position.z;
    heading = fn_802e7e5c(forward.x, forward.z);
    angle = fn_802e7e5c(dx, dz) - heading;
    if (angle < lbl_803b07d4[0])
        angle += lbl_803b07d8[0];
    else if (angle > lbl_803b07dc[0])
        angle -= lbl_803b07d8[0];
    limit = lbl_803b07e0[0];
    if (angle > limit)
        angle = limit - (angle - limit);
    else if (angle < -limit)
        angle = -limit - (angle + limit);
    return fn_802e88ac(angle);
}

}

/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family template, 2026-10-22 (third session): facing term between a target's
 * heading and the direction to a goal point, wrapped and folded at a limit. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dVec4 { float x, y, z, w; } W3dVec4;
typedef void (*W3dGet1)(void *, W3dVec4 *);
typedef void (*W3dGet2)(void *, W3dVec4 *, W3dVec4 *);
typedef void (*W3dGetI)(void *, int, W3dVec4 *);
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

float w3d_facing_term_801e51c8(void *self, void *target)
{
    W3dVec4 position, forward, up, goal;
    float spare[6];
    void *source;
    float dx, dz, heading, angle, limit;
    if (!target)
        return lbl_803b06f4[0];
    (*(W3dGet1 *)(*(char **)target + 56))(target, &position);
    (*(W3dGet2 *)(*(char **)target + 60))(target, &forward, &up);
    source = FIELD(self, void *, 12);
    (*(W3dGetI *)(*(char **)source + 68))(source, 3, &goal);
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

float w3d_facing_term_801e663c(void *self, void *target)
{
    W3dVec4 position, forward, up, goal;
    float spare[6];
    void *source;
    float dx, dz, heading, angle, limit;
    if (!target)
        return lbl_803b07d0[0];
    (*(W3dGet1 *)(*(char **)target + 56))(target, &position);
    (*(W3dGet2 *)(*(char **)target + 60))(target, &forward, &up);
    source = FIELD(self, void *, 164);
    (*(W3dGetI *)(*(char **)source + 68))(source, 3, &goal);
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

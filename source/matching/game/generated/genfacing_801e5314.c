/* Facing-angle terms (z/x axis order), hand-instantiated from
 * analysis/templates-20261022c/families_t2.c with each function's own constants. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dVec4 { float x, y, z, w; } W3dVec4;
typedef void (*W3dGet1)(void *, W3dVec4 *);
typedef void (*W3dGet2)(void *, W3dVec4 *, W3dVec4 *);
typedef void (*W3dGetI)(void *, int, W3dVec4 *);
float fn_802e7e5c(float, float);
float fn_802e88ac(float);
extern const float lbl_803b0708[];
extern const float lbl_803b070c[];
extern const float lbl_803b0710[];
extern const float lbl_803b0714[];
extern const float lbl_803b0718[];

extern const float lbl_803b07e4[];
extern const float lbl_803b07e8[];
extern const float lbl_803b07ec[];
extern const float lbl_803b07f0[];
extern const float lbl_803b07f4[];
float w3d_facing_term_801e5314(void *self, void *target)
{
    W3dVec4 position, forward, up, goal;
    float spare[6];
    void *source;
    float dx, dz, heading, angle, limit;
    if (!target)
        return lbl_803b0708[0];
    (*(W3dGet1 *)(*(char **)target + 56))(target, &position);
    (*(W3dGet2 *)(*(char **)target + 60))(target, &forward, &up);
    source = FIELD(self, void *, 12);
    (*(W3dGetI *)(*(char **)source + 68))(source, 3, &goal);
    dx = goal.x - position.x;
    dz = goal.z - position.z;
    heading = fn_802e7e5c(forward.z, forward.x);
    angle = fn_802e7e5c(dz, dx) - heading;
    if (angle < lbl_803b070c[0])
        angle += lbl_803b0710[0];
    else if (angle > lbl_803b0714[0])
        angle -= lbl_803b0710[0];
    limit = lbl_803b0718[0];
    if (angle > limit)
        angle = limit - (angle - limit);
    else if (angle < -limit)
        angle = -limit - (angle + limit);
    return fn_802e88ac(angle);
}

float w3d_facing_term_801e6788(void *self, void *target)
{
    W3dVec4 position, forward, up, goal;
    float spare[6];
    void *source;
    float dx, dz, heading, angle, limit;
    if (!target)
        return lbl_803b07e4[0];
    (*(W3dGet1 *)(*(char **)target + 56))(target, &position);
    (*(W3dGet2 *)(*(char **)target + 60))(target, &forward, &up);
    source = FIELD(self, void *, 164);
    (*(W3dGetI *)(*(char **)source + 68))(source, 3, &goal);
    dx = goal.x - position.x;
    dz = goal.z - position.z;
    heading = fn_802e7e5c(forward.z, forward.x);
    angle = fn_802e7e5c(dz, dx) - heading;
    if (angle < lbl_803b07e8[0])
        angle += lbl_803b07ec[0];
    else if (angle > lbl_803b07f0[0])
        angle -= lbl_803b07ec[0];
    limit = lbl_803b07f4[0];
    if (angle > limit)
        angle = limit - (angle - limit);
    else if (angle < -limit)
        angle = -limit - (angle + limit);
    return fn_802e88ac(angle);
}

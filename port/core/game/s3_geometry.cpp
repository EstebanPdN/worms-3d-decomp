#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s3_geometry.c"
typedef struct S3Vector { float x, y, z; } S3Vector;
typedef struct S3VectorLocal { float x, y, z, unused; } S3VectorLocal;
typedef struct S3CollisionState { unsigned char pad00[0x24]; unsigned int state; } S3CollisionState;
extern S3Vector w3d_points_80453030[];
extern S3Vector w3d_center_804530a8[];
extern float w3d_radius_804ab3cc;
extern const float w3d_f32_803a0450[];
extern const float w3d_f32_803a0454[];
extern float w3d_fn_802e82c0(float);
static __inline__ void s3_initialize_vector(Ptr32<S3VectorLocal> v, float f)
{
    v->x = f;
    v->y = f;
    v->z = f;
}
#if 0 /* 0x801410f8: vector temporary layout and floating register allocation differ. */
S3CollisionState *w3d_collision_shape_initialize(S3CollisionState *self)
{
    self->state = 10;
    if (w3d_radius_804ab3cc == w3d_f32_803a0450[0]) {
        S3VectorLocal low, high;
        S3Vector *point;
        int count;
        s3_initialize_vector(&low, w3d_f32_803a0450[0]);
        high.x = w3d_f32_803a0450[0];
        high.z = w3d_f32_803a0450[0];
        high.y = w3d_f32_803a0450[0];
        point = w3d_points_80453030;
        count = 10;
        do {
            if (point->x < low.x) low.x = point->x;
            if (point->y < low.y) low.y = point->y;
            if (point->z < low.z) low.z = point->z;
            if (point->x > high.x) high.x = point->x;
            if (point->y > high.y) high.y = point->y;
            if (point->z > high.z) high.z = point->z;
            ++point;
        } while (--count);
        {
            float lz = low.z;
            float hx = high.x;
            float hy = high.y;
            float dx = hx - low.x;
            float sx = low.x + hx;
            float dy = hy - low.y;
            float half = w3d_f32_803a0454[0];
            float sz = lz + high.z;
            float dz = high.z - lz;
            float yy = dy * dy;
            float sy = low.y + hy;
            high.x = dx;
            high.y = dy;
            high.z = dz;
            w3d_center_804530a8[0].x = sx * half;
            w3d_center_804530a8[0].y = sy * half;
            w3d_center_804530a8[0].z = sz * half;
            w3d_radius_804ab3cc = w3d_fn_802e82c0(dx * dx + yy + dz * dz) * half;
        }
    }
    return self;
}
#endif
int w3d_collision_state_is_contact(Ptr32<S3CollisionState> self)
{
    return self->state - 5 <= 4;
}

typedef struct S3Motion {
    unsigned char pad00[0x12c];
    int has_parent;
    unsigned char pad130[0x230-0x130];
    S3Vector position;
    unsigned char pad23c[0x248-0x23c];
    int entity;
    float input_x, input_z;
    unsigned char pad254[0x264-0x254];
    int left, right, forward, backward, blocked, action_a, action_b;
    unsigned char pad280[0x28c-0x280];
    int lock_horizontal, double_speed;
    unsigned char pad294[0x2a4-0x294];
    S3Vector velocity;
    unsigned char pad2b0[0x2cc-0x2b0];
    int airborne;
    unsigned char pad2d0[0x2f8-0x2d0];
    int mode;
    unsigned char pad2fc[0x320-0x2fc];
    int enabled;
    unsigned char pad324[0x338-0x324];
    int contact;
    unsigned char pad33c[0x34c-0x33c];
    int drift_ticks;
    unsigned char pad350[0x464-0x350];
    Ptr32<void> owner_handle;
    unsigned char pad468[0x480-0x468];
    unsigned char collider[0x4a8-0x480];
    Ptr32<void> flag_a; Ptr32<void> flag_b;
    int pad4b0;
    S3Vector direction;
    unsigned char pad4c0[4];
    Ptr32<void> factor;
} S3Motion;
typedef struct S3VectorFrame { S3Vector vector; int unused; } S3VectorFrame;
typedef struct S3ActorValue { unsigned char pad00[0x80]; int value; } S3ActorValue;
extern const float w3d_f32_803a0fc0[], w3d_f32_803a0fc4[], w3d_f32_803a0fc8[], w3d_f32_803a0fcc[], w3d_f32_803a0fd0[];
extern const float w3d_f32_803a0fec[], w3d_f32_803a0ff0[], w3d_f32_803a13a8[];
extern const float w3d_f32_803a1494[], w3d_f32_803a1498[], w3d_f32_803a149c[], w3d_f32_803a14a0[];
extern const float w3d_f32_803a1510[], w3d_f32_803a1514[], w3d_f32_803a1518[];
extern Ptr32<S3Vector> w3d_member_80141564(Ptr32<void>);
extern Ptr32<void> w3d_fn_8014b8ec(Ptr32<S3Vector>, Ptr32<S3Motion>);
extern Ptr32<S3ActorValue> w3d_fn_800fc710(int, Ptr32<int>);
extern void w3d_fn_80178474(Ptr32<int>, int);
extern Ptr32<void> w3d_constructor_native_cast(Ptr32<void>);
extern int w3d_auto_80178d1c(Ptr32<void>);
extern float w3d_auto_80178df0(Ptr32<void>);
extern void w3d_fn_800c2494(Ptr32<S3Vector>, Ptr32<S3Vector>, float, float, float);
extern void w3d_fn_801f67e0(Ptr32<void>);
extern void w3d_fn_8015aa04(Ptr32<void>);
extern Ptr32<unsigned char> w3d_global_804aa8c8;
extern Ptr32<void> w3d_empty_803426b4(Ptr32<void>);
extern int w3d_auto_80178c48(Ptr32<void>);
extern S3Vector w3d_vector_8043ae20[];
extern S3Vector w3d_vector_8045e788[];
extern Ptr32<void> w3d_global_804afdf0;
extern const char w3d_str_803a1214[];
extern void w3d_fn_800fc270(Ptr32<Ptr32<const char>>, Ptr32<float>);
extern float w3d_fn_8014ca54(Ptr32<S3Vector>);

static __inline__ Ptr32<S3Vector> s3_vector_make(Ptr32<S3Vector> out, float x, float y, float z)
{
    out->x = x; out->y = y; out->z = z;
    return out;
}
static __inline__ Ptr32<S3Vector> s3_vector_construct_from(Ptr32<S3Vector> out, Ptr32<const S3Vector> v)
{
    return s3_vector_make(out, v->x, v->y, v->z);
}
static __inline__ void s3_vector_set_up(Ptr32<S3Vector> v, float zero)
{
    float one = w3d_f32_803a0ff0[0];
    v->z = zero;
    v->x = zero;
    v->y = one;
}
static __inline__ void s3_vector_emit(Ptr32<S3Vector> out, Ptr32<const S3Vector> v)
{
    out->x = v->x; out->y = v->y; out->z = v->z;
}
static __inline__ float s3_vector_length_squared(Ptr32<const S3Vector> v)
{
    return v->x*v->x + v->y*v->y + v->z*v->z;
}
static __inline__ void s3_vector_multiply(Ptr32<S3Vector> v, float f)
{
    v->x *= f; v->y *= f; v->z *= f;
}
static __inline__ void s3_vector_accumulate(Ptr32<S3Vector> out, Ptr32<const S3Vector> v)
{
    out->x += v->x; out->y += v->y; out->z += v->z;
}
static __inline__ void s3_vector_copy(Ptr32<S3Vector> out, Ptr32<const S3Vector> v)
{
    *out = *v;
}
static __inline__ S3Vector s3_vector_scaled(Ptr32<const S3Vector> v, float f)
{
    S3Vector result;
    s3_vector_make(&result, v->x*f, v->y*f, v->z*f);
    return result;
}
#if 0 /* 0x80146aa4: vector expression temporaries differ. */
void w3d_motion_integrate_damped(S3Motion *self)
{
    S3VectorFrame step;
    float y;
    step.vector = s3_vector_scaled(&self->velocity, w3d_f32_803a0fc0[0]);
    s3_vector_accumulate(&self->position, &step.vector);
    y = self->velocity.y;
    if (__builtin_fabsf(y) > w3d_f32_803a0fc4[0])
        self->velocity.y = y * w3d_f32_803a0fc8[0];
    else
        self->velocity.y = (w3d_f32_803a0fcc[0] - y) * w3d_f32_803a0fd0[0] + y;
    self->velocity.x *= w3d_f32_803a0fc8[0];
    self->velocity.z *= w3d_f32_803a0fc8[0];
}
#endif
#if 0 /* 0x80146e30: two fallback store instructions differ in order. */
void w3d_motion_normalize_direction(S3Motion *self)
{
    S3VectorFrame local;
    float length;
    local.vector = *w3d_member_80141564(self->collider);
    length = s3_vector_length_squared(&local.vector);
    if (length > w3d_f32_803a0fec[0]) {
        float scale = w3d_f32_803a0ff0[0] / w3d_fn_802e82c0(length);
        s3_vector_multiply(&local.vector, scale);
    } else {
        s3_vector_set_up(&local.vector, w3d_f32_803a0fec[0]);
    }
    self->direction = local.vector;
}
#endif
Ptr32<S3Vector> w3d_motion_get_direction(Ptr32<S3Vector> out, Ptr32<S3Motion> self)
{
    return s3_vector_construct_from(out, &self->direction);
}
void w3d_motion_refresh_velocity(Ptr32<S3Motion> self)
{
    S3VectorFrame local;
    w3d_fn_8014b8ec(&local.vector, self);
    s3_vector_copy(&self->velocity, &local.vector);
    if (self->double_speed) {
        s3_vector_accumulate(&self->velocity, &self->velocity);
    }
}
void w3d_motion_set_actor_value(Ptr32<S3Motion> self, int value)
{
    int handle[2];
    handle[0] = 0;
    handle[1] = 0xe3a8;
    w3d_fn_800fc710(self->entity, handle)->value = value;
    w3d_fn_80178474(handle, 2);
}
int w3d_motion_has_combined_flags(Ptr32<S3Motion> self)
{
    int first = w3d_auto_80178d1c(w3d_constructor_native_cast(self->flag_b));
    int second = w3d_auto_80178d1c(w3d_constructor_native_cast(self->flag_a));
    return first + second != 0;
}
void w3d_motion_apply_velocity_constraint(Ptr32<S3Motion> self)
{
    struct { S3Vector vector; int unused[3]; } local;
    float first, second;
    Ptr32<S3Vector> velocity;
    w3d_motion_get_direction(&local.vector, self);
    if (self->lock_horizontal) {
        self->velocity.z = w3d_f32_803a13a8[0];
        self->velocity.x = w3d_f32_803a13a8[0];
    }
    velocity = &self->velocity;
    first = w3d_auto_80178df0(self->factor);
    second = w3d_auto_80178df0(self->factor);
    w3d_fn_800c2494(velocity, &local.vector, first, second, w3d_f32_803a13a8[0]);
}
#if 0 /* 0x8014be44: argument move and branch order differ. */
void w3d_motion_parent_operation(S3Motion *self, void *value)
{
    if (!self->has_parent) w3d_fn_8015aa04(w3d_global_804aa8c8 + 0x148);
    else w3d_fn_801f67e0(value);
}
#endif
Ptr32<S3Vector> w3d_motion_get_input_direction(Ptr32<S3Vector> out, Ptr32<S3Motion> self)
{
    struct { S3Vector vector; int unused[3]; } local;
    float length;
    s3_initialize_vector((Ptr32<S3VectorLocal>)&local, 0.0f);
    if (!self->blocked) {
        local.vector.x = self->input_x;
        if (self->left == 1 && local.vector.x >= 0.0f) local.vector.x = w3d_f32_803a1498[0];
        if (self->right == 1 && local.vector.x <= 0.0f) local.vector.x = w3d_f32_803a149c[0];
        local.vector.z = self->input_z;
        if (self->forward == 1 && local.vector.z >= 0.0f) local.vector.z = w3d_f32_803a1498[0];
        if (self->backward == 1 && local.vector.z <= 0.0f) local.vector.z = w3d_f32_803a149c[0];
        local.vector.z = -local.vector.z;
    }
    length = s3_vector_length_squared(&local.vector);
    if (length > w3d_f32_803a149c[0]) {
        float scale = w3d_f32_803a149c[0] / w3d_fn_802e82c0(length);
        s3_vector_multiply(&local.vector, scale);
    }
    s3_vector_emit(out, &local.vector);
    return out;
}
#if 0 /* 0x8014c3f4: boolean branch and return allocation differ. */
int w3d_motion_has_input(S3Motion *self)
{
    S3VectorFrame local;
    int result = 0;
    if (self->enabled) {
        w3d_motion_get_input_direction(&local.vector, self);
        if (s3_vector_length_squared(&local.vector) == w3d_f32_803a14a0[0] && !self->action_a && !self->action_b) result = 0;
        else result = 1;
    }
    return result;
}
#endif

int w3d_motion_owner_matches(Ptr32<S3Motion> self)
{
    return w3d_auto_80178c48(w3d_empty_803426b4(self->owner_handle)) == self->entity;
}
Ptr32<S3Vector> w3d_motion_get_contact_point(Ptr32<S3Vector> out)
{
    return s3_vector_make(out, w3d_vector_8043ae20[0].x, w3d_vector_8043ae20[0].y, w3d_vector_8043ae20[0].z);
}
#if 0 /* 0x8014c6f4: vector temporary allocation and signed threshold test differ. */
void w3d_motion_accumulate_air_drift(S3Motion *self)
{
    S3VectorFrame local;
    if (self->airborne || self->contact < 0) {
        w3d_motion_get_direction(&local.vector, self);
        if (s3_vector_length_squared(&local.vector) > w3d_f32_803a1510[0]) {
            local.vector.x *= w3d_f32_803a1514[0];
            local.vector.z *= w3d_f32_803a1514[0];
            local.vector.y *= w3d_f32_803a1514[0];
            self->velocity.x += local.vector.x;
            self->velocity.y += local.vector.y;
            self->velocity.z += local.vector.z;
            ++self->drift_ticks;
            if (self->drift_ticks > 0 && self->drift_ticks > 20) {
                self->velocity = w3d_vector_8045e788[0];
                self->mode = 10;
            }
        }
    }
}
#endif
int w3d_motion_slope_allowed(Ptr32<S3Vector> direction)
{
    Ptr32<const char> key;
    float limit;
    int result;
    float length = s3_vector_length_squared(direction);
    if (length == w3d_f32_803a1518[0]) result = 0;
    else {
        if (!w3d_global_804afdf0) {
            key = w3d_str_803a1214;
            w3d_fn_800fc270(&key, &limit);
        } else limit = w3d_auto_80178df0(w3d_global_804afdf0);
        result = w3d_fn_8014ca54(direction) <= limit;
    }
    return result;
}

}

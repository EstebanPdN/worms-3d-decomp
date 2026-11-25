#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s3_actor_links.c"
typedef struct S3Vec { float x, y, z; } S3Vec;
typedef struct S3VecLocal { S3Vec value; int unused; } S3VecLocal;
typedef struct S3Interface S3Interface;
typedef struct S3Vtable {
    Ptr32<void (void)> unused0; Ptr32<void (void)> unused1; Ptr32<void (void)> unused2;
    Ptr32<void (Ptr32<S3Interface>)> retain;
    Ptr32<void (Ptr32<S3Interface>)> release;
} S3Vtable;
struct S3Interface { Ptr32<S3Vtable> vtable; };
typedef struct S3Type S3Type;
struct S3Type { unsigned char pad00[20]; Ptr32<S3Type> parent; };
typedef struct S3Actor S3Actor;
typedef struct S3ActorVtable {
    Ptr32<void (void)> unused[5];
    Ptr32<Ptr32<S3Type> (Ptr32<S3Actor>)> get_type;
} S3ActorVtable;
struct S3Actor {
    Ptr32<S3ActorVtable> vtable;
    unsigned char pad04[560-4];
    S3Vec position;
    float angle;
    unsigned char pad240[584-576];
    unsigned int entity;
    unsigned char pad24c[604-588];
    int message_a, message_b;
    unsigned char pad264[652-612];
    int locked;
    unsigned char pad290[676-656];
    S3Vec velocity;
    S3Vec cast_direction;
    unsigned char pad2bc[716-700];
    int airborne;
    unsigned char pad2d0[756-720];
    unsigned int next_time;
    int mode;
    unsigned char pad2fc[784-764];
    int link_a, link_b, link_c;
    unsigned char pad31c[804-796];
    int name;
    unsigned char pad328[816-808];
    float impulse_min, impulse_max;
    int contact;
    unsigned char pad33c[1128-828];
    Ptr32<S3Interface> random_uint; Ptr32<S3Interface> random_float;
};
typedef struct S3Linked {
    unsigned char pad00[72];
    int state;
    unsigned char pad4c[120-76];
    int active;
    unsigned char pad7c[164-124];
    int flag_a, flag_b;
    unsigned char padac[268-172];
    float angular_speed;
} S3Linked;
typedef struct S3EntityInfo { unsigned char pad00[132]; int state; unsigned char pad88[213-136]; unsigned char team; } S3EntityInfo;
typedef struct S3Message { unsigned short id, pad02; Ptr32<void> type; } S3Message;
typedef struct S3CachedMessage { int id; Ptr32<const char> name; } S3CachedMessage;
extern Ptr32<S3Interface> w3d_slope_jump_804afdf8; extern Ptr32<S3Interface> w3d_slope_blast_804afdf4;
extern const char w3d_str_803a1230[], w3d_str_803a1250[];
extern void w3d_constructor_lookup_name(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<S3Interface>>);
extern Ptr32<S3Interface> w3d_empty_80342a74(Ptr32<S3Interface>);
extern float w3d_auto_80178df0(Ptr32<S3Interface>);
extern float w3d_fn_8014ca54(Ptr32<S3Vec>);
extern float w3d_fn_802e82c0(float), w3d_fn_802e79e0(float);
extern const float w3d_f32_803a151c[], w3d_f32_803a1520[], w3d_f32_803a1524[], w3d_f32_803a1528[];
extern const float w3d_f32_803a1630[], w3d_f32_803a1634[], w3d_f32_803a1638[];
extern const float w3d_f32_803a1650[], w3d_f32_803a1654[], w3d_f32_803a1688[], w3d_f32_803a168c[];
extern const float w3d_f32_803a1690[], w3d_f32_803a16b8[], w3d_f32_803a16bc[];
extern S3Type w3d_type_80361860[], w3d_type_803618f0[];
extern unsigned int w3d_cast_result_804b1764;
extern int w3d_message_result_804b17a0;
extern void w3d_fn_800b0824(Ptr32<S3Vec>, Ptr32<S3Vec>, Ptr32<S3Vec>, int, int);
extern Ptr32<S3Vec> w3d_fn_8014c4cc(Ptr32<S3Vec>, Ptr32<S3Actor>);
extern Ptr32<S3EntityInfo> w3d_fn_800fc6dc(unsigned int);
extern int w3d_fn_80022e20(Ptr32<const char>, Ptr32<const char>, int, Ptr32<int>);
extern const char w3d_str_803a163c[], w3d_str_803a0e2c[];
extern void w3d_fn_801492ec(Ptr32<S3Actor>, int);
extern Ptr32<void> w3d_global_804b1754;
extern Ptr32<S3Message> w3d_fn_801613f0(Ptr32<void>, int);
extern short w3d_cached_message_id(Ptr32<S3CachedMessage>, int);
extern S3CachedMessage w3d_cached_804afc20, w3d_cached_804afbf8, w3d_cached_804afbf0, w3d_cached_804afc18, w3d_cached_804afbd0, w3d_cached_804afc30;
extern Ptr32<void> w3d_message_type_8040db38[];
extern int w3d_message_post_current(Ptr32<S3Message>);
extern Ptr32<S3Linked> w3d_fn_80164fc8(int);
extern int w3d_fn_800cfc98(Ptr32<S3Linked>);
extern void w3d_fn_800cfe68(Ptr32<S3Linked>, Ptr32<S3Vec>, Ptr32<S3Vec>, Ptr32<float>);
extern Ptr32<S3Message> w3d_fn_8003a264(Ptr32<S3Message>, int, int);
extern Ptr32<S3Message> w3d_message_int_init(Ptr32<S3Message>, unsigned short, unsigned int);
extern int w3d_fn_8014c488(Ptr32<S3Actor>);
extern void w3d_fn_80153dfc(Ptr32<S3Actor>, int);
extern float w3d_auto_801610a0(Ptr32<S3Actor>);
extern void w3d_auto_800ac238(Ptr32<S3Linked>);
extern void w3d_fn_800fc270(Ptr32<Ptr32<const char>>, Ptr32<float>);
extern const char w3d_str_803a16c0[], w3d_str_803a16e0[], w3d_str_803a1700[], w3d_str_803a1714[];

static __inline__ void s3_vec_set(Ptr32<S3Vec> v, float x, float y, float z)
{ v->x = x; v->y = y; v->z = z; }
static __inline__ float s3_vec_squared(Ptr32<const S3Vec> v)
{ return v->x*v->x + v->y*v->y + v->z*v->z; }
static __inline__ void s3_vec_scale(Ptr32<S3Vec> v, float scale)
{ v->x *= scale; v->y *= scale; v->z *= scale; }
static __inline__ float s3_vec_dot(Ptr32<const S3Vec> a, Ptr32<const S3Vec> b)
{ return a->x*b->x + a->y*b->y + a->z*b->z; }
static __inline__ void s3_read_float(Ptr32<float> out, Ptr32<Ptr32<const char>> key)
{ w3d_fn_800fc270(key, out); }
static __inline__ Ptr32<const float> s3_float_min(Ptr32<const float> a, Ptr32<const float> b)
{ if (*b < *a) return b; return a; }
static __inline__ Ptr32<const float> s3_float_max(Ptr32<const float> a, Ptr32<const float> b)
{ if (*a < *b) return b; return a; }

static __inline__ void s3_lookup_interface(Ptr32<Ptr32<S3Interface>> out, Ptr32<Ptr32<const char>> key)
{
    w3d_constructor_lookup_name(key, out);
}
#if 0 /* 0x8014c89c: stack-local address evaluation order differs. */
int w3d_actor_jump_slope_allowed(S3Vec *direction)
{
    S3Interface *object[2];
    const char *key[4];
    S3Interface *held;
    float angle;
    if (!w3d_slope_jump_804afdf8) {
        object[0] = w3d_slope_jump_804afdf8;
        key[0] = w3d_str_803a1230;
        s3_lookup_interface(object, key);
        held = w3d_empty_80342a74(object[0]);
        if (held) held->vtable->retain(held);
        if (w3d_slope_jump_804afdf8) w3d_slope_jump_804afdf8->vtable->release(w3d_slope_jump_804afdf8);
        w3d_slope_jump_804afdf8 = held;
        if (object[0]) object[0]->vtable->release(object[0]);
    }
    angle = w3d_fn_8014ca54(direction);
    return angle <= w3d_auto_80178df0(w3d_slope_jump_804afdf8);
}
#endif
#if 0 /* 0x8014c978: stack-local address evaluation order differs. */
int w3d_actor_blast_slope_allowed(S3Vec *direction)
{
    S3Interface *object[2];
    const char *key[4];
    S3Interface *held;
    float angle;
    if (!w3d_slope_blast_804afdf4) {
        object[0] = w3d_slope_blast_804afdf4;
        key[0] = w3d_str_803a1250;
        s3_lookup_interface(object, key);
        held = w3d_empty_80342a74(object[0]);
        if (held) held->vtable->retain(held);
        if (w3d_slope_blast_804afdf4) w3d_slope_blast_804afdf4->vtable->release(w3d_slope_blast_804afdf4);
        w3d_slope_blast_804afdf4 = held;
        if (object[0]) object[0]->vtable->release(object[0]);
    }
    angle = w3d_fn_8014ca54(direction);
    return angle <= w3d_auto_80178df0(w3d_slope_blast_804afdf4);
}
#endif
#if 0 /* 0x8014ca54: dot-product and clamp temporary allocation differ. */
float w3d_actor_direction_slope(S3Vec *direction)
{
    S3VecLocal local, up;
    struct { float value, upper, lower; int unused[3]; } clamp;
    float length;
    s3_vec_set(&local.value, direction->x, direction->y, direction->z);
    length = s3_vec_squared(&local.value);
    if (length == w3d_f32_803a151c[0]) return w3d_f32_803a1520[0];
    s3_vec_scale(&local.value, w3d_f32_803a1524[0] / w3d_fn_802e82c0(length));
    s3_vec_set(&up.value, w3d_f32_803a151c[0], w3d_f32_803a1524[0], w3d_f32_803a151c[0]);
    clamp.value = s3_vec_dot(&up.value, &local.value);
    clamp.upper = w3d_f32_803a1524[0];
    clamp.value = *s3_float_min(&clamp.value, &clamp.upper);
    clamp.lower = w3d_f32_803a1528[0];
    clamp.value = *s3_float_max(&clamp.value, &clamp.lower);
    return w3d_fn_802e79e0(clamp.value);
}
#endif
#if 0 /* 0x8014d59c: return branch layout differs. */
int w3d_actor_ground_gap_small(S3Actor *self)
{
    S3VecLocal cast, contact, temporary;
    s3_vec_set(&cast.value, w3d_f32_803a1630[0], w3d_f32_803a1634[0], w3d_f32_803a1630[0]);
    w3d_fn_800b0824(&self->position, &cast.value, &self->cast_direction, 20, 1);
    if (w3d_cast_result_804b1764 > 20) goto no_contact;
    {
        w3d_fn_8014c4cc(&temporary.value, self);
        contact.value = temporary.value;
        return self->position.y - contact.value.y < w3d_f32_803a1638[0];
    }
no_contact:
    return 0;
}
#endif
static __inline__ int s3_type_contains(Ptr32<S3Type> type, Ptr32<S3Type> target)
{
    while (type != target) {
        if (type == type->parent) return 0;
        type = type->parent;
    }
    return 1;
}
static __inline__ void s3_post_empty(Ptr32<S3CachedMessage> cache)
{
    Ptr32<S3Message> message = w3d_fn_801613f0(w3d_global_804b1754, 8);
    message->id = w3d_cached_message_id(cache, 1);
    message->type = w3d_message_type_8040db38;
    w3d_message_post_current(message);
}
void w3d_actor_fire_punch_jump(Ptr32<S3Actor> self)
{
    if (w3d_fn_800fc6dc(self->entity)->state == 13 && self->mode != 8) {
        s3_vec_set(&self->velocity, w3d_f32_803a1650[0], w3d_f32_803a1654[0], w3d_f32_803a1650[0]);
        if (s3_type_contains(self->vtable->get_type(self), w3d_type_80361860) || s3_type_contains(self->vtable->get_type(self), w3d_type_803618f0))
            w3d_fn_80022e20(w3d_str_803a163c, w3d_str_803a0e2c, 4358, &self->name);
        self->mode = 21;
        w3d_fn_801492ec(self, 42);
        s3_post_empty(&w3d_cached_804afc20);
    }
}

int w3d_actor_link_c_state(Ptr32<S3Actor> self)
{
    Ptr32<S3Linked> object;
    int result;
    if (self->link_c == -1) result = 0;
    else {
        object = w3d_fn_80164fc8(self->link_c);
        if (object) result = object->state;
        else { self->link_c = -1; result = 0; }
    }
    return result;
}

int w3d_actor_link_b_active(Ptr32<S3Actor> self)
{
    Ptr32<S3Linked> object;
    int result;
    if (self->link_b == -1) result = 0;
    else {
        object = w3d_fn_80164fc8(self->link_b);
        if (object) result = object->active;
        else { self->link_b = -1; result = 0; }
    }
    return result;
}

int w3d_actor_link_a_flag(Ptr32<S3Actor> self)
{
    Ptr32<S3Linked> object;
    int result;
    if (self->link_a == -1) result = 0;
    else {
        object = w3d_fn_80164fc8(self->link_a);
        if (object) result = object->flag_a;
        else { self->link_a = -1; result = 0; }
    }
    return result;
}

int w3d_actor_link_a_state(Ptr32<S3Actor> self)
{
    Ptr32<S3Linked> object;
    int result;
    if (self->link_a == -1) result = 0;
    else {
        object = w3d_fn_80164fc8(self->link_a);
        if (object) result = object->state;
        else { self->link_a = -1; result = 0; }
    }
    return result;
}

int w3d_actor_link_a_second_flag(Ptr32<S3Actor> self)
{
    Ptr32<S3Linked> object;
    int result;
    if (self->link_a == -1) result = 0;
    else {
        object = w3d_fn_80164fc8(self->link_a);
        if (object) result = object->flag_b;
        else { self->link_a = -1; result = 0; }
    }
    return result;
}

int w3d_actor_link_b_query(Ptr32<S3Actor> self)
{
    Ptr32<S3Linked> object;
    int result;
    if (self->link_b == -1) result = 0;
    else {
        object = w3d_fn_80164fc8(self->link_b);
        if (object) result = w3d_fn_800cfc98(object);
        else { self->link_b = -1; result = 0; }
    }
    return result;
}
#if 0 /* 0x8014dd18: entry return register and branch layout differ. */
int w3d_actor_link_b_step(S3Actor *self)
{
    S3Linked *object;
    int result;
    int id = self->link_b;
    if ((unsigned int)(id + 1) == 0) return 0;
    object = w3d_fn_80164fc8(id);
    if (!object) { self->link_b = -1; return 0; }
    result = w3d_fn_800cfc98(object);
    if (result) w3d_fn_800cfe68(object, &self->position, &self->velocity, &self->angle);
    else if (self->airborne || self->contact < 0) {
        if (object->active) { s3_post_empty(&w3d_cached_804afbf8); return 0; }
    } else self->angle += object->angular_speed * w3d_f32_803a1688[0] * w3d_f32_803a168c[0];
    return result;
}
#endif
int w3d_actor_post_pair_query(Ptr32<S3Actor> self)
{
    Ptr32<S3Message> message = w3d_fn_801613f0(w3d_global_804b1754, 12);
    w3d_message_post_current(w3d_fn_8003a264(message, self->message_a, self->message_b));
    return !w3d_message_result_804b17a0;
}
void w3d_actor_clear_links(Ptr32<S3Actor> self, int notify)
{
    int changed = 0;
    if (self->link_a != -1) {
        if (notify) s3_post_empty(&w3d_cached_804afbf0);
        self->link_a = -1; changed = 1;
    }
    if (self->link_b != -1) {
        if (notify) s3_post_empty(&w3d_cached_804afbf8);
        self->link_b = -1; changed = 1;
    }
    if (self->link_c != -1) {
        if (notify) {
            Ptr32<S3Message> message = w3d_fn_801613f0(w3d_global_804b1754, 12);
            w3d_message_post_current(w3d_message_int_init(message, w3d_cached_message_id(&w3d_cached_804afc18, 1), self->entity));
        }
        self->link_c = -1; changed = 1;
    }
    if (w3d_fn_8014c488(self)) {
        w3d_fn_80153dfc(self, 0);
        if (changed) s3_post_empty(&w3d_cached_804afbd0);
    }
}
void w3d_actor_timed_value(Ptr32<S3Actor> self, unsigned int time)
{
    if (time > self->next_time) {
        w3d_fn_801492ec(self, 17);
        { int delay = (int)(w3d_auto_801610a0(self) * w3d_f32_803a1690[0]);
          delay += 1000;
          self->next_time = time + delay; }
    }
}
void w3d_actor_link_c_falling_message(Ptr32<S3Actor> self)
{
    if (self->link_c != -1 && self->velocity.y < w3d_f32_803a16b8[0]) s3_post_empty(&w3d_cached_804afc30);
}
void w3d_actor_link_a_falling_step(Ptr32<S3Actor> self)
{
    Ptr32<S3Linked> object;
    if (self->link_a != -1 && self->velocity.y < w3d_f32_803a16bc[0]) {
        object = w3d_fn_80164fc8(self->link_a);
        if (!object) self->link_a = -1;
        else if (object->flag_a && !object->flag_b) w3d_auto_800ac238(object);
    }
}
#if 0 /* 0x8014e4c8: four argument-address instructions differ in order. */
void w3d_actor_load_random_impulse(S3Actor *self)
{
    struct { const char *minimum, *maximum, *integer, *fraction; } keys;
    keys.minimum = w3d_str_803a16c0;
    w3d_fn_800fc270(&keys.minimum, &self->impulse_min);
    keys.maximum = w3d_str_803a16e0;
    s3_read_float(&self->impulse_max, &keys.maximum);
    keys.integer = w3d_str_803a1700;
    w3d_constructor_lookup_name(&keys.integer, &self->random_uint);
    keys.fraction = w3d_str_803a1714;
    w3d_constructor_lookup_name(&keys.fraction, &self->random_float);
}
#endif
void w3d_actor_other_entity_reaction(Ptr32<S3Actor> self, unsigned int entity)
{
    if (self->entity != entity && !self->locked) {
        if (entity > 15) w3d_fn_801492ec(self, 0);
        else {
            Ptr32<S3EntityInfo> other = w3d_fn_800fc6dc(entity);
            Ptr32<S3EntityInfo> own = w3d_fn_800fc6dc(self->entity);
            if (own->team == other->team) w3d_fn_801492ec(self, 21);
            else w3d_fn_801492ec(self, 22);
        }
    }
}

}

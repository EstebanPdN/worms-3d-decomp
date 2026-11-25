typedef struct S3Vec { float x, y, z; } S3Vec;
typedef struct S3VecLocal { S3Vec value; int unused; } S3VecLocal;
typedef struct S3Interface S3Interface;
typedef struct S3Vtable {
    void (*unused0)(void), (*unused1)(void), (*unused2)(void);
    void (*retain)(S3Interface *);
    void (*release)(S3Interface *);
} S3Vtable;
struct S3Interface { S3Vtable *vtable; };
typedef struct S3Type S3Type;
struct S3Type { unsigned char pad00[20]; S3Type *parent; };
typedef struct S3Actor S3Actor;
typedef struct S3ActorVtable {
    void (*unused[5])(void);
    S3Type *(*get_type)(S3Actor *);
} S3ActorVtable;
struct S3Actor {
    S3ActorVtable *vtable;
    unsigned char pad04[20-4];
    int owner;
    unsigned char pad18[560-24];
    S3Vec position;
    float angle;
    float heading;
    int pad244;
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
    unsigned char pad2d0[736-720];
    int jump_requested;
    unsigned int jump_start, jump_time;
    unsigned char pad2ec[756-748];
    unsigned int next_time;
    int mode;
    unsigned char pad2fc[784-764];
    int link_a, link_b, link_c;
    int pad31c;
    S3Interface *enabled;
    int name;
    unsigned char pad328[816-808];
    float impulse_min, impulse_max;
    int contact;
    unsigned char pad33c[1108-828];
    S3Interface *cleanup;
    unsigned char pad458[1128-1112];
    S3Interface *random_uint, *random_float;
    unsigned char pad470[1144-1136];
    unsigned char timer[8];
    unsigned char pad480[1200-1152];
    S3Interface *special;
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
typedef struct S3Message { unsigned short id, pad02; void *type; } S3Message;
typedef struct S3CachedMessage { int id; const char *name; } S3CachedMessage;
extern S3Interface *w3d_slope_jump_804afdf8, *w3d_slope_blast_804afdf4;
extern const char w3d_str_803a1230[], w3d_str_803a1250[];
extern void w3d_constructor_lookup_name(const char **, S3Interface **);
extern S3Interface *w3d_empty_80342a74(S3Interface *);
extern float w3d_auto_80178df0(S3Interface *);
extern float w3d_fn_8014ca54(S3Vec *);
extern float w3d_fn_802e82c0(float), w3d_fn_802e79e0(float);
extern const float w3d_f32_803a151c[], w3d_f32_803a1520[], w3d_f32_803a1524[], w3d_f32_803a1528[];
extern const float w3d_f32_803a1630[], w3d_f32_803a1634[], w3d_f32_803a1638[];
extern const float w3d_f32_803a1650[], w3d_f32_803a1654[], w3d_f32_803a1688[], w3d_f32_803a168c[];
extern const float w3d_f32_803a1690[], w3d_f32_803a16b8[], w3d_f32_803a16bc[];
extern S3Type w3d_type_80361860[], w3d_type_803618f0[];
extern unsigned int w3d_cast_result_804b1764;
extern int w3d_message_result_804b17a0;
extern void w3d_fn_800b0824(S3Vec *, S3Vec *, S3Vec *, int, int);
extern S3Vec *w3d_fn_8014c4cc(S3Vec *, S3Actor *);
extern S3EntityInfo *w3d_fn_800fc6dc(unsigned int);
extern int w3d_fn_80022e20(const char *, const char *, int, int *);
extern const char w3d_str_803a163c[], w3d_str_803a0e2c[];
extern void w3d_fn_801492ec(S3Actor *, int);
extern void *w3d_global_804b1754;
extern S3Message *w3d_fn_801613f0(void *, int);
extern short w3d_cached_message_id(S3CachedMessage *, int);
extern S3CachedMessage w3d_cached_804afc20, w3d_cached_804afbf8, w3d_cached_804afbf0, w3d_cached_804afc18, w3d_cached_804afbd0, w3d_cached_804afc30;
extern void *w3d_message_type_8040db38[];
extern int w3d_message_post_current(S3Message *);
extern S3Linked *w3d_fn_80164fc8(int);
extern int w3d_fn_800cfc98(S3Linked *);
extern void w3d_fn_800cfe68(S3Linked *, S3Vec *, S3Vec *, float *);
extern S3Message *w3d_fn_8003a264(S3Message *, int, int);
extern S3Message *w3d_message_int_init(S3Message *, unsigned short, unsigned int);
extern int w3d_fn_8014c488(S3Actor *);
extern void w3d_fn_80153dfc(S3Actor *, int);
extern float w3d_auto_801610a0(S3Actor *);
extern void w3d_auto_800ac238(S3Linked *);
extern void w3d_fn_800fc270(const char **, float *);
extern const char w3d_str_803a16c0[], w3d_str_803a16e0[], w3d_str_803a1700[], w3d_str_803a1714[];

static __inline__ void s3_vec_set(S3Vec *v, float x, float y, float z)
{ v->x = x; v->y = y; v->z = z; }
static __inline__ float s3_vec_squared(const S3Vec *v)
{ return v->x*v->x + v->y*v->y + v->z*v->z; }
static __inline__ void s3_vec_scale(S3Vec *v, float scale)
{ v->x *= scale; v->y *= scale; v->z *= scale; }
static __inline__ float s3_vec_dot(const S3Vec *a, const S3Vec *b)
{ return a->x*b->x + a->y*b->y + a->z*b->z; }
static __inline__ void s3_read_float(float *out, const char **key)
{ w3d_fn_800fc270(key, out); }
static __inline__ const float *s3_float_min(const float *a, const float *b)
{ if (*b < *a) return b; return a; }
static __inline__ const float *s3_float_max(const float *a, const float *b)
{ if (*a < *b) return b; return a; }

static __inline__ void s3_lookup_interface(S3Interface **out, const char **key)
{
    w3d_constructor_lookup_name(key, out);
}

extern const float w3d_f32_803a1748[], w3d_f32_803a174c[], w3d_f32_803a1750[], w3d_f32_803a1754[];
extern const float w3d_f32_803a179c[], w3d_f32_803a17a0[], w3d_f32_803a17b0[], w3d_f32_803a17b4[];
extern const float w3d_f32_803a17b8[], w3d_f32_803a17bc[], w3d_f32_803a17d0[], w3d_f32_803a1850[];
extern S3Vec w3d_zero_8045e788[], w3d_jump_origin_804538d4[];
extern void *w3d_constructor_native_cast(S3Interface *);
extern int w3d_auto_80178d1c(void *);
extern int w3d_get_800a830c(void *);
extern void w3d_handle_member_query_8012629c(void *, float);
extern int w3d_fn_800fdc80(int, int, S3Vec *, int, int, int);
extern S3CachedMessage w3d_cached_804afca8;
extern void w3d_empty_80343740(S3Vec *);
typedef struct S3Matrix { S3Vec axis[3]; S3Vec position; } S3Matrix;
typedef struct S3Matrix4 { float row[4][4]; } S3Matrix4;
extern void w3d_fn_801f7538(S3Matrix *, float, float, float, float);
extern S3Vec *w3d_auto_80178ec4(S3Interface *);
extern S3Interface *w3d_global_804afde8;
extern const char w3d_str_803a17c0[], w3d_str_803a1800[];
typedef struct S3Context { unsigned char pad00[52]; unsigned int time; } S3Context;
extern S3Context *w3d_engine_get_context(void);
typedef struct S3Player { unsigned char pad00[49]; unsigned char effect; } S3Player;
extern S3Player *w3d_fn_800fc7f8(int);
extern S3Message *w3d_fn_8004d870(S3Message *, S3Vec *, S3Vec *, int, unsigned int);
typedef struct S3ActorHandle { unsigned char pad00[220]; int active; } S3ActorHandle;
extern S3ActorHandle *w3d_fn_800fc710(unsigned int, int *);
extern void w3d_fn_80178474(int *, int);
extern int w3d_fn_80178d28(void *, unsigned int *);
extern void w3d_auto_8015fd1c(S3Actor *);
typedef struct S3View { int unused; S3Vec position; } S3View;
typedef struct S3Scene { unsigned char pad00[312]; unsigned int view_index; S3View **views; } S3Scene;
extern S3Scene *w3d_scene_804aa8c8;
typedef struct S3Camera { unsigned char pad00[48]; float range; } S3Camera;
extern S3Camera *w3d_auto_801797b4(S3Interface *);
extern S3Interface *w3d_empty_80341584(S3Interface *);
extern int w3d_fn_80035b50(S3Scene *, S3Vec *), w3d_fn_80121330(S3Vec *);
extern void w3d_fn_80150828(S3Actor *);
typedef struct S3Created { S3Vtable *vtable; unsigned char pad04[160-4]; int value; unsigned int entity; } S3Created;
extern void *w3d_factory_8040fe30[];
extern S3Created *w3d_fn_8020b680(void *);
extern void w3d_fn_800dc3dc(S3Created *, S3Vec *, float *);
extern int w3d_fn_80164514(void *, S3Created *, int);
extern void *volatile w3d_global_804b178c;
extern int w3d_fn_8014dcbc(S3Actor *), w3d_fn_8014de70(S3Actor *), w3d_fn_8014dc04(S3Actor *);
extern int w3d_auto_80153f58(S3Actor *);
void w3d_actor_camera_target_position(S3Actor *, S3Vec *);

static __inline__ void s3_vec_copy(S3Vec *out, const S3Vec *v) { *out = *v; }
static __inline__ void s3_vec_make_from(S3Vec *out, const S3Vec *v) { s3_vec_set(out, v->x, v->y, v->z); }
static __inline__ void s3_vec_subtract(S3Vec *out, const S3Vec *v) { out->x -= v->x; out->y -= v->y; out->z -= v->z; }
static __inline__ int s3_type_contains(S3Type *type, S3Type *target)
{
    while (type != target) {
        if (type == type->parent) return 0;
        type = type->parent;
    }
    return 1;
}
static __inline__ void s3_created_assign(S3Created **out, S3Created *value)
{
    if (value) value->vtable->retain((S3Interface *)value);
    if (*out) (*out)->vtable->release((S3Interface *)*out);
    *out = value;
}
static __inline__ void s3_vec_set_xzy(S3Vec *out, float x, float y, float z)
{ out->x = x; out->z = z; out->y = y; }
static __inline__ int s3_signed_ge(int value, int threshold) { return value >= threshold; }
static __inline__ void s3_vec_difference(S3Vec *out, const S3Vec *a, const S3Vec *b)
{ s3_vec_set(out, a->x-b->x, a->y-b->y, a->z-b->z); }
static __inline__ void s3_matrix_expand(S3Matrix4 *out, const S3Matrix *in)
{
    out->row[0][0] = in->axis[0].x; out->row[0][1] = in->axis[0].y; out->row[0][2] = in->axis[0].z; out->row[0][3] = w3d_f32_803a17b0[0];
    out->row[1][0] = in->axis[1].x; out->row[1][1] = in->axis[1].y; out->row[1][2] = in->axis[1].z; out->row[1][3] = w3d_f32_803a17b0[0];
    out->row[2][0] = in->axis[2].x; out->row[2][1] = in->axis[2].y; out->row[2][2] = in->axis[2].z; out->row[2][3] = w3d_f32_803a17b0[0];
    out->row[3][0] = in->position.x; out->row[3][1] = in->position.y; out->row[3][2] = in->position.z; out->row[3][3] = w3d_f32_803a17b4[0];
}
static __inline__ void s3_matrix_transform_direction(S3Vec *out, const S3Matrix4 *m, const S3Vec *v)
{
    out->x = v->x*m->row[0][0] + v->y*m->row[1][0] + v->z*m->row[2][0];
    out->y = v->x*m->row[0][1] + v->y*m->row[1][1] + v->z*m->row[2][1];
    out->z = v->x*m->row[0][2] + v->y*m->row[1][2] + v->z*m->row[2][2];
}
static __inline__ float s3_vec_distance_squared(const S3Vec *a, const S3Vec *b)
{
    float x = a->x-b->x, y = a->y-b->y, z = a->z-b->z;
    return x*x + y*y + z*z;
}
#if 0 /* 0x8014e80c: vector temporary and floating register allocation differ. */
void w3d_actor_choose_fall_reaction(S3Actor *self)
{
    if (w3d_auto_80153f58(self)) {
        S3VecLocal target, step, zero;
        int collision;
        float clock;
        float scale = w3d_f32_803a1750[0] / w3d_f32_803a174c[0];
        s3_vec_make_from(&target.value, &self->position);
        target.value.y += w3d_f32_803a1748[0];
        s3_vec_difference(&zero.value, &target.value, &self->position);
        s3_vec_set(&step.value, zero.value.x*scale, zero.value.y*scale, zero.value.z*scale);
        s3_vec_make_from(&zero.value, w3d_zero_8045e788);
        w3d_fn_800b0824(&self->position, &step.value, &zero.value, 1000, 1);
        collision = (int)w3d_cast_result_804b1764 <= 1000;
        clock = w3d_auto_801610a0(self);
        if (collision || clock < w3d_f32_803a1754[0]) {
            self->mode = 23;
            w3d_fn_801492ec(self, 25);
        } else {
            self->mode = 22;
            w3d_fn_801492ec(self, 24);
        }
    }
}
#endif
int w3d_actor_special_flag(S3Actor *self)
{
    return w3d_auto_80178d1c(w3d_constructor_native_cast(self->special)) != 0;
}
void w3d_actor_lock_for_team_message(S3Actor *self, void *message)
{
    int team = w3d_get_800a830c(message);
    if (team == w3d_fn_800fc6dc(self->entity)->team) {
        self->locked = 1;
        if (w3d_fn_8014c488(self)) {
            if (self->enabled) self->enabled->vtable->release(self->enabled);
            self->enabled = 0;
        }
        w3d_handle_member_query_8012629c(self->timer, w3d_f32_803a179c[0]);
        w3d_fn_800fdc80(100, 0, &self->position, 500, -1, -1);
    }
}
void w3d_actor_unlock_for_team_message(S3Actor *self, void *message)
{
    int team = w3d_get_800a830c(message);
    if (team == w3d_fn_800fc6dc(self->entity)->team && self->locked) {
        if (!w3d_fn_8014c488(self)) w3d_fn_801492ec(self, 21);
        self->locked = 0;
        w3d_handle_member_query_8012629c(self->timer, w3d_f32_803a17a0[0]);
    }
}
void w3d_actor_post_team_message(S3Actor *self)
{
    int team = w3d_fn_800fc6dc(self->entity)->team;
    S3Message *message = w3d_fn_801613f0(w3d_global_804b1754, 12);
    w3d_message_post_current(w3d_message_int_init(message, w3d_cached_message_id(&w3d_cached_804afca8, 1), team));
}
#if 0 /* 0x8014fb40: matrix expansion and floating register allocation differ. */
void w3d_actor_apply_rotated_velocity(S3Actor *self)
{
    S3Matrix matrix;
    S3Matrix4 full;
    S3Vec *input;
    int i;
    w3d_empty_80343740(&matrix.position);
    w3d_fn_801f7538(&matrix, w3d_f32_803a17b0[0], w3d_f32_803a17b4[0], w3d_f32_803a17b0[0], self->heading);
    input = w3d_auto_80178ec4(w3d_global_804afde8);
    s3_matrix_expand(&full, &matrix);
    s3_matrix_transform_direction(&self->velocity, &full, input);
    self->mode = 6;
    w3d_fn_801492ec(self, 32);
}
#endif
int w3d_actor_ground_cast_clear(S3Actor *self)
{
    S3VecLocal direction, zero;
    s3_vec_set(&direction.value, w3d_f32_803a17b8[0], w3d_f32_803a17bc[0], w3d_f32_803a17b8[0]);
    s3_vec_make_from(&zero.value, w3d_zero_8045e788);
    w3d_fn_800b0824(&self->position, &direction.value, &zero.value, 100, 1);
    return s3_signed_ge((int)w3d_cast_result_804b1764, 101);
}
void w3d_actor_start_jump(S3Actor *self)
{
    s3_vec_copy(w3d_jump_origin_804538d4, &self->position);
    self->jump_requested = 1;
    if (!self->jump_time) {
        if ((unsigned int)self->mode > 1) return;
        s3_vec_copy(&self->velocity, w3d_zero_8045e788);
        if (s3_type_contains(self->vtable->get_type(self), w3d_type_80361860) || s3_type_contains(self->vtable->get_type(self), w3d_type_803618f0))
            w3d_fn_80022e20(w3d_str_803a17c0, w3d_str_803a0e2c, 5479, &self->name);
        w3d_fn_801492ec(self, 2);
        self->mode = 2;
        self->jump_start = w3d_engine_get_context()->time;
        self->jump_time = w3d_engine_get_context()->time;
    } else if (self->mode == 2 && w3d_engine_get_context()->time < self->jump_time + 500) self->mode = 4;
}
void w3d_actor_post_player_effect(S3Actor *self)
{
    S3VecLocal position, direction;
    int effect;
    s3_vec_make_from(&position.value, &self->position);
    position.value.y += w3d_f32_803a17d0[0];
    s3_vec_set_xzy(&direction.value, w3d_zero_8045e788[0].x, self->heading, w3d_zero_8045e788[0].z);
    effect = w3d_fn_800fc7f8(w3d_fn_800fc6dc(self->entity)->team)->effect;
    if ((unsigned int)effect < 6) {
        S3Message *message = w3d_fn_801613f0(w3d_global_804b1754, 40);
        w3d_message_post_current(w3d_fn_8004d870(message, &position.value, &direction.value, effect, self->entity));
    }
}
void w3d_actor_clear_active_state(S3Actor *self)
{
    int handle[2];
    handle[0] = 0;
    handle[1] = 0xe3a8;
    w3d_fn_800fc710(self->entity, handle)->active = 0;
    w3d_fn_80178474(handle, 2);
    w3d_fn_80178d28(w3d_constructor_native_cast(self->cleanup), &self->entity);
    w3d_auto_8015fd1c(self);
}
#if 0 /* 0x801506f8: one indexed-load operand order differs after eight attempts. */
void w3d_actor_check_track_camera(S3Actor *self)
{
    S3Scene *scene = w3d_scene_804aa8c8;
    if (scene) {
        S3VecLocal position;
        struct { S3Interface *object; int unused; const char *key; } local;
        S3Camera *camera;
        int first, second, outside, change;
        float length;
        w3d_actor_camera_target_position(self, &position.value);
        local.object = 0;
        local.key = w3d_str_803a1800;
        w3d_constructor_lookup_name(&local.key, &local.object);
        camera = w3d_auto_801797b4(w3d_empty_80341584(local.object));
        first = w3d_fn_80035b50(scene, &position.value);
        second = w3d_fn_80121330(&position.value);
        { S3View *view = *(S3View **)((unsigned long)scene->views + (unsigned long)scene->view_index * sizeof(*scene->views));
          length = w3d_fn_802e82c0(s3_vec_distance_squared(&position.value, &view->position)); }
        outside = length > camera->range;
        change = 0;
        if (!first || !second || outside) change = 1;
        if (change) w3d_fn_80150828(self);
        if (local.object) local.object->vtable->release(local.object);
    }
}
#endif
void w3d_actor_camera_target_position(S3Actor *self, S3Vec *out)
{
    s3_vec_copy(out, &self->position);
    out->y += w3d_f32_803a1850[0];
}
void w3d_actor_create_third_link(S3Actor *self, int value)
{
    struct { S3Created *volatile object; int unused; } local;
    S3Created *created;
    local.object = 0;
    created = w3d_fn_8020b680(w3d_factory_8040fe30);
    if (created) created->vtable->retain((S3Interface *)created);
    { S3Created *old = local.object;
      if (old) old->vtable->release((S3Interface *)old); }
    local.object = created;
    created->value = value;
    local.object->entity = self->entity;
    w3d_fn_800dc3dc(local.object, &self->position, &self->angle);
    { void *service = w3d_global_804b178c;
      S3Created *object = local.object;
      self->link_c = w3d_fn_80164514(service, object, self->owner); }
    { S3Created *old = local.object;
      if (old) old->vtable->release((S3Interface *)old); }
}
int w3d_actor_has_active_link(S3Actor *self)
{
    if (w3d_fn_8014dcbc(self)) return 1;
    if (w3d_fn_8014de70(self)) return 1;
    if (w3d_fn_8014dc04(self)) return 1;
    return 0;
}

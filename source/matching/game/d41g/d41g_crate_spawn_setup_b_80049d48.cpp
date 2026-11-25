// GWMP8P rev0 0x80049d48. Crate spawner setup: reads its properties, loads
// gravity, low-gravity and water resources, picks the spawn point,
// subscribes to nine messages, posts a creation message and configures the
// physics actor.
struct Type { char u[20]; Type *parent; };
extern Type type_a_80361860[], type_b_803618f0[];
struct Object;
struct ObjectVt { char u[12]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVt *vt; };
struct Handle {
    Object *value;
    Handle() {}
    Handle(const Handle &);
};
struct Key { const char *name; };
struct MessageSlot { int a, b; };
struct MsgId { short id; };
struct ObjectId { unsigned value; ObjectId(unsigned v) { value = v; } };
struct Crate;
struct CrateVt { char u[20]; Type *(*type)(Crate *); };
struct Actor;
struct Crate {
    CrateVt *vt; char u4[20 - 4]; unsigned id; char u24[28 - 24]; int kind; char u32[40 - 32]; float pos[3]; char u52[64 - 52]; float scale;
    char u68[144 - 68]; int showered; char u148[176 - 148]; Object *gravity; Object *lowGravity; Object *water; char u188[196 - 188];
    int subs[9]; int bounce; char actor[244 - 236]; int spawn; char u248[252 - 248]; int canDrop; char u256[280 - 256]; int disable;
    template <Type *T> bool isA() {
        Type *c = vt->type(this);
        Type *t = T;
        while (c != t) {
            if (c == c->parent) return false;
            c = c->parent;
        }
        return true;
    }
};
struct Bouncer { struct Vt { char u[92]; void (*read)(Bouncer *, const char *, int *); } *vt; };
struct Engine { char u[108]; Bouncer *bouncer; };
extern "C" {
int w3d_assert_80022e20(const char *, const char *, int, void *);
int w3d_auto_800fc230(Key *, int *);
int w3d_auto_800fc2b0(Key *, const char **);
int w3d_constructor_lookup_name(Key *, Object **);
Object *w3d_empty_80342a74(Object *);
int w3d_auto_800fc1f0(Key *, int *);
void w3d_find_spawn_point_8004a608(Crate *, const char *);
void w3d_d28g_spawner_pick_clear_spot_8004a408(Crate *);
int w3d_auto_800fc2f0(Key *, float *);
void w3d_fn_8004a7f4(Crate *, const char *);
int w3d_cached_message_id(MessageSlot *, int);
int d24d_acquire_message_80162024(Crate *, MsgId *, int *);
void *tsonnet_b33_arena_801613f0(void *, int);
void *w3d_created_message_init_800c1620(void *, const ObjectId &);
int w3d_message_post_current(void *);
void w3d_actor_handle_member_set_word(void *, int);
void w3d_actor_handle_member_set_slot_word(void *, int);
void w3d_handle_member_query_80126308(void *, unsigned);
void w3d_handle_member_query_801262c0(void *, float *);
void w3d_handle_member_query_8012629c(void *, float);
}
extern char s_spawn_80376e3c[], s_file_80376e48[], s_disable_80376e60[], s_spawnname_80376e78[], s_type_80376e84[], s_gravity_80376e90[], s_low_80376e98[], s_water_80376eb0[], s_drop_80376ebc[], s_show_80376ed4[], s_rand_80376ee4[], s_expl_80376efc[], s_bounce_80376f14[];
extern MessageSlot m0_804ad388, m1_804ad390, m2_804ad3a8, m3_804ad3c0, m4_804ad3d0, m5_804ad3d8, m6_804ad3e0, m7_804ad370, m8_804ad3e8;
extern void *arena_804b1754;
extern Engine *engine_804b1788;
inline void ReadFlag(int *out, const char *name) { Key k; k.name = name; w3d_auto_800fc1f0(&k, out); }
inline void LoadResource(Key &key, Handle &h, Object *&slot)
{
    h.value = 0;
    w3d_constructor_lookup_name(&key, &h.value);
    Object *object = w3d_empty_80342a74(h.value);
    if (object) object->vt->retain(object);
    if (slot) slot->vt->release(slot);
    slot = object;
    if (h.value) h.value->vt->release(h.value);
}
extern "C" void d41g_crate_spawn_setup_b_80049d48(Crate *self)
{
    if (self->isA<type_a_80361860>() || self->isA<type_b_803618f0>())
        w3d_assert_80022e20(s_spawn_80376e3c, s_file_80376e48, 259, &self->spawn);
    Handle handle;
    const char *spawn = 0;
    const char *type = 0;
    Key k0 = {s_disable_80376e60};
    w3d_auto_800fc230(&k0, &self->disable);
    Key k1 = {s_spawnname_80376e78};
    w3d_auto_800fc2b0(&k1, &spawn);
    Key k2 = {s_type_80376e84};
    w3d_auto_800fc2b0(&k2, &type);
    Key g0 = {s_gravity_80376e90}; LoadResource(g0, handle, self->gravity);
    Key g1 = {s_low_80376e98}; LoadResource(g1, handle, self->lowGravity);
    Key g2 = {s_water_80376eb0}; LoadResource(g2, handle, self->water);
    Key k3 = {s_drop_80376ebc};
    int drop = 1;
    w3d_auto_800fc1f0(&k3, &drop);
    if (drop) self->canDrop = 1; else self->canDrop = 0;
    ReadFlag(&self->showered, s_show_80376ed4);
    Key k5 = {s_rand_80376ee4};
    int mode = 0;
    w3d_auto_800fc1f0(&k5, &mode);
    switch (mode) {
    case 0: w3d_find_spawn_point_8004a608(self, spawn); break;
    case 1: w3d_d28g_spawner_pick_clear_spot_8004a408(self); break;
    case 2: { Key k6 = {s_expl_80376efc}; w3d_auto_800fc2f0(&k6, self->pos); break; }
    }
    w3d_fn_8004a7f4(self, type);
    MsgId i0; i0.id = w3d_cached_message_id(&m0_804ad388, 1); d24d_acquire_message_80162024(self, &i0, &self->subs[0]);
    MsgId i1; i1.id = w3d_cached_message_id(&m1_804ad390, 1); d24d_acquire_message_80162024(self, &i1, &self->subs[1]);
    MsgId i2; i2.id = w3d_cached_message_id(&m2_804ad3a8, 1); d24d_acquire_message_80162024(self, &i2, &self->subs[2]);
    MsgId i3; i3.id = w3d_cached_message_id(&m3_804ad3c0, 1); d24d_acquire_message_80162024(self, &i3, &self->subs[3]);
    MsgId i4; i4.id = w3d_cached_message_id(&m4_804ad3d0, 1); d24d_acquire_message_80162024(self, &i4, &self->subs[4]);
    MsgId i5; i5.id = w3d_cached_message_id(&m5_804ad3d8, 1); d24d_acquire_message_80162024(self, &i5, &self->subs[5]);
    MsgId i6; i6.id = w3d_cached_message_id(&m6_804ad3e0, 1); d24d_acquire_message_80162024(self, &i6, &self->subs[6]);
    MsgId i7; i7.id = w3d_cached_message_id(&m7_804ad370, 1); d24d_acquire_message_80162024(self, &i7, &self->subs[7]);
    MsgId i8; i8.id = w3d_cached_message_id(&m8_804ad3e8, 1); d24d_acquire_message_80162024(self, &i8, &self->subs[8]);
    void *m = tsonnet_b33_arena_801613f0(arena_804b1754, 12);
    w3d_message_post_current(w3d_created_message_init_800c1620(m, self->id));
    if (engine_804b1788->bouncer) engine_804b1788->bouncer->vt->read(engine_804b1788->bouncer, s_bounce_80376f14, &self->bounce);
    if (self->kind == 1) w3d_actor_handle_member_set_slot_word(self->actor, 4);
    else if (self->kind == 3) w3d_actor_handle_member_set_slot_word(self->actor, 32);
    else w3d_actor_handle_member_set_slot_word(self->actor, 2);
    w3d_actor_handle_member_set_word(self->actor, 63);
    w3d_handle_member_query_80126308(self->actor, self->id);
    w3d_handle_member_query_801262c0(self->actor, self->pos);
    w3d_handle_member_query_8012629c(self->actor, self->scale);
}

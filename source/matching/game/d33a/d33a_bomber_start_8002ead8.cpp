// GWMP8P rev0 0x8002ead8. Starts the airstrike bomber: acquires its two
// messages, reads the airstrike direction, target and up vector and the
// bomber speed, blitz time and bomb count, works out the flight side vector
// and start point, advances the shared animation index, queues one message
// per bomb and one at the end of the clip, publishes Bomber.Mesh, sets up
// its perspective shape and starts the fly-by. Names are inferred from the
// original strings and instructions.
extern "C" float fn_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Cross(const Vec &a, const Vec &b) { x = a.y * b.z - a.z * b.y; y = a.z * b.x - a.x * b.z; z = a.x * b.y - a.y * b.x; }
    void Normalise() { float k = 1.0f / fn_802e82c0(x * x + y * y + z * z); x *= k; y *= k; z *= k; }
    void operator-=(const Vec &o) { x -= o.x; y -= o.y; z -= o.z; }
};
inline void Trace(const char *, Vec, const char *, Vec, const char *) {}
inline Vec operator*(const Vec &a, float f) { Vec r; r.x = a.x * f; r.y = a.y * f; r.z = a.z * f; return r; }
struct Key { const char *name; Key(const char *n) { name = n; } };
struct Type { char pad[20]; Type *base; };
struct Obj;
struct ObjTable { char pad[12]; void (*add)(Obj *); void (*release)(Obj *); char pad2[140]; Obj *(*find)(Obj *, const char *); };
struct Obj { ObjTable *t; char pad[116]; void *f120; };
struct Hold { Obj *p; Hold(Obj *q) { p = q; if (p) p->t->add(p); } Hold(const Hold &o); ~Hold() { if (p) p->t->release(p); } };
struct Data { char pad[152]; unsigned char b152, b153; };
struct Id { int words[2]; };
struct Msg { unsigned short id; void **table; };
struct Self;
struct SelfTable { char pad[20]; Type *(*type)(Self *); };
struct Self {
    SelfTable *t; char pad[16]; int id; char pad2[4]; Obj *owner; Vec start; Vec side; float speed; int frame; int msg1; int msg2; int handle;
};
struct Context { char pad[52]; int time; };
extern Id g_a_804acd34, g_b_804acd2c, g_c_804acd3c;
extern void *g_arena_804b1754;
extern void *g_msg_table_8040db38[];
extern const char *g_clip1_803f3c7c[], *g_clip2_803f3c90[];
extern const char s_80372cec[];
extern Type t_80361860[], t_803618f0[];
extern "C" int w3d_cached_message_id(Id *, int);
extern "C" int d24d_acquire_message_80162024(Self *, const unsigned short &, int *);
extern "C" int w3d_auto_800fc2f0(const Key &, Vec *);
extern "C" int w3d_auto_800fc270(const Key &, float *);
extern "C" int w3d_auto_800fc230(const Key &, void *);
extern "C" int s8_property_write_800fc43c(const Key &, int);
extern "C" int s8_property_read_800fc5dc(const Key &, Vec *);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Data *w3d_auto_801797b4(Obj *);
extern "C" Vec w3d_d20a_bomber_position_8002f098(Data *, const Vec *, const Vec *);
extern "C" int w3d_k7a_clip_frames_8002f764(Self *, const char **);
extern "C" Context *w3d_engine_get_context();
extern "C" void *tsonnet_b33_arena_801613f0(void *, int);
extern "C" int w3d_d24h_pool_add_800c53a0(Msg *, int);
extern "C" void *w3d_created_message_init_800c1620(void *, const int *);
extern "C" int w3d_message_post_current(void *);
extern "C" void *w3d_auto_800361f8(void *, unsigned short, Obj *, void *);
extern "C" int FUN_80022e20(const char *, const char *, int, int *);
extern "C" int w3d_s20_forward_global4_800fdd80(int, int, const Vec *, int, int);
inline int IsA(Type *t, Type *want)
{
    while (t != want) {
        if (t == t->base) return 0;
        t = t->base;
    }
    return 1;
}
inline void *Alloc(void *&a, const int &n) { return tsonnet_b33_arena_801613f0(a, n); }
extern "C" void w3d_d33a_bomber_start_8002ead8(Self *self)
{
    Vec target, dir, up;
    d24d_acquire_message_80162024(self, (unsigned short)w3d_cached_message_id(&g_a_804acd34, 1), &self->msg1);
    d24d_acquire_message_80162024(self, (unsigned short)w3d_cached_message_id(&g_b_804acd2c, 1), &self->msg2);
    w3d_auto_800fc2f0(Key(s_80372cec), &dir);
    w3d_auto_800fc2f0(Key("Airstrike.TargetPoint"), &target);
    w3d_auto_800fc2f0(Key("Airstrike.UpVector"), &up);
    w3d_auto_800fc270(Key("Bomber.GroundSpeed"), &self->speed);
    unsigned blitz, bombs;
    w3d_auto_800fc230(Key("Bomber.BlitzDuration"), &blitz);
    w3d_auto_800fc230(Key("Bomber.NumBombs"), &bombs);
    Trace("BomberLogicEntity::Initialize: Target = ", target, ", Direction = ", dir, "\n");
    Data *data = w3d_auto_801797b4(w3d_empty_80341584(self->owner));
    self->side.Cross(dir, up);
    self->side.y = 0.0f;
    self->side.Normalise();
    self->start = w3d_d20a_bomber_position_8002f098(data, &target, &self->side);
    self->start -= self->side * (self->speed * (float)blitz * 0.5f);
    int anim;
    const char *animName = "Bomber.AnimIndex";
    w3d_auto_800fc230(Key(animName), &anim);
    anim++;
    if (g_clip1_803f3c7c[anim] == 0) anim = 0;
    s8_property_write_800fc43c(Key(animName), anim);
    unsigned i = 0;
    s8_property_read_800fc5dc(Key("Bomber.Direction"), &self->side);
    int clip = w3d_k7a_clip_frames_8002f764(self, &g_clip1_803f3c7c[anim]);
    int at = w3d_engine_get_context()->time + clip;
    self->frame = at;
    while (i < bombs) {
        i++;
        Msg *m = (Msg *)Alloc(g_arena_804b1754, 8);
        m->id = w3d_cached_message_id(&g_a_804acd34, 1);
        m->table = g_msg_table_8040db38;
        w3d_d24h_pool_add_800c53a0(m, at);
        at += blitz / bombs;
    }
    int clip2 = w3d_k7a_clip_frames_8002f764(self, &g_clip2_803f3c90[anim]);
    Msg *m = (Msg *)Alloc(g_arena_804b1754, 8);
    m->id = w3d_cached_message_id(&g_b_804acd2c, 1);
    m->table = g_msg_table_8040db38;
    w3d_d24h_pool_add_800c53a0(m, w3d_engine_get_context()->time + clip + clip2);
    const char *meshName = "Bomber.Mesh";
    s8_property_write_800fc43c(Key(meshName), 0);
    {
        void *mem = Alloc(g_arena_804b1754, 12);
        int id = self->id;
        w3d_message_post_current(w3d_created_message_init_800c1620(mem, &id));
    }
    Obj *found;
    w3d_auto_800fc230(Key(meshName), &found);
    Obj *mesh = found;
    if (mesh) {
        Hold shape(mesh->t->find(mesh, "perspShape"));
        void *mem = Alloc(g_arena_804b1754, 16);
        w3d_message_post_current(w3d_auto_800361f8(mem, (unsigned short)w3d_cached_message_id(&g_c_804acd3c, 1), shape.p, mesh->f120));
    }
    if (IsA(self->t->type(self), t_80361860) || IsA(self->t->type(self), t_803618f0))
        FUN_80022e20("BomberLogicEntity exists", "BomberLogicEntity.cpp", 175, &self->handle);
    w3d_s20_forward_global4_800fdd80(data->b153, data->b152, &self->start, 250, 1);
}

// GWMP8P rev0 0x8002df8c. Sets up the bomber: flattens and normalises its
// flight direction and derives a heading from it, loads the Bomber object
// and its three attached parts, attaches a light, plays two named clips
// picked by Bomber.AnimIndex, posts a message, adds the two effects named by
// Bomber.EffectName, starts the two Bomber.Engine sounds with the second
// one's value raised by 50, and publishes the mesh as Bomber.Mesh. Names are
// inferred from the original strings and instructions.
struct String;
extern "C" void w3d_string_base_finish(String *);
extern "C" void w3d_string_release(String *);
struct String {
    const char *text;
    String(const char *);
    String(const String &o);
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
extern "C" float fn_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    float Length() const { return fn_802e82c0(x * x + y * y + z * z); }
    void Normalise() { float k = 1.0f / Length(); x *= k; y *= k; z *= k; }
};
struct Obj;
struct ObjTable {
    char pad[12]; void (*add)(Obj *); char pad2[44]; int (*kind)(Obj *);
    char pad3[12]; int (*pos)(Obj *, const void *, int); int (*rot)(Obj *, const Vec *, int);
    char pad4[8]; int (*link)(Obj *, Obj *, int);
};
struct Obj { ObjTable *t; };
struct Hold { Obj *p; Hold(Obj *q) { p = q; if (p) p->t->add(p); } Hold(const Hold &o); };
struct Effect;
struct EffectTable { char pad[20]; int (*start)(Effect *); char pad2[24]; int (*set)(Effect *, int, int); char pad3[8]; int (*get)(Effect *, int, int *); };
struct Effect { EffectTable *t; };
struct Lib;
struct LibTable { char pad[92]; int (*load)(Lib *, const char *, Effect **); };
struct Lib { LibTable *t; };
struct Engine { char pad[108]; Lib *lib; };
struct Id { int words[2]; };
struct Msg { unsigned short id; void **table; };
struct Self {
    char pad[28]; Obj *body; Obj *left; Obj *right; Obj *tail; void *anim; char anim2[4];
    Vec dir; char pos[4]; int f80pad[3]; int e80; int e84; Effect *engine1; Effect *engine2; void *member;
};
extern void *g_af5bc_804af5bc;
extern Engine *g_engine_804b1788;
extern void *g_arena_804b1754;
extern Id g_id_804acd10;
extern void *g_msg_table_8040db38[];
extern int g_8a0_804aa8a0, g_8a4_804aa8a4, g_8a8_804aa8a8, g_898_804aa898, g_89c_804aa89c;
extern const char *g_clip1_803f3c7c[], *g_clip2_803f3c90[];
extern char s_80372b54[];
extern "C" float fn_802e7c30(float);
extern "C" int w3d_handle_set_name(const String &, Obj **, int);
extern "C" void *w3d_heap_allocate(void **, int);
extern "C" void *w3d_handle_member_init_kind_8012656c(void *, int);
extern "C" int w3d_light_member_attach_80126610(void *, Hold);
extern "C" void w3d_k7a_follow_transform_8002e670(Self *);
extern "C" void *w3d_empty_80343584(Obj *);
extern "C" int w3d_auto_800fc230(const char **, int *);
extern "C" int w3d_auto_800fc2b0(const char **, const char **);
extern "C" int s8_property_write_800fc43c(const char **, void *);
extern "C" int w3d_cc21b_play_named_clip_80181640(void *, const char *, void *, int, float, float, float);
extern "C" int w3d_s20_forward_global5_800e5cf0(void *, int, const char *, int, int);
extern "C" void *tsonnet_b33_arena_801613f0(void *, int);
extern "C" int w3d_cached_message_id(Id *, int);
extern "C" int w3d_message_post_current(Msg *);
extern "C" void w3d_cx12a_forward_positions_8002e59c(Self *);
extern "C" void w3d_d32a_bomber_setup_8002df8c(Self *self)
{
    Vec rot(0.0f, 0.0f, 0.0f);
    self->dir.y = 0.0f;
    self->dir.Normalise();
    float a = fn_802e7c30(self->dir.x);
    if (self->dir.z < 0.0f) a = 3.1415927f - a;
    rot.y = a;
    w3d_handle_set_name(String(s_80372b54), &self->body, 255);
    self->body->t->pos(self->body, (char *)self + 64, 0);
    self->body->t->rot(self->body, &rot, 0);
    w3d_handle_set_name(String("NULL"), &self->left, 255);
    w3d_handle_set_name(String("NULL"), &self->right, 255);
    self->body->t->link(self->body, self->left, g_8a0_804aa8a0);
    self->body->t->link(self->body, self->right, g_8a4_804aa8a4);
    w3d_handle_set_name(String("NULL"), &self->tail, 255);
    self->body->t->link(self->body, self->tail, g_8a8_804aa8a8);
    void *mem = w3d_heap_allocate(&g_af5bc_804af5bc, 4);
    self->member = w3d_handle_member_init_kind_8012656c(mem, self->body->t->kind(self->body));
    if (self->member) w3d_light_member_attach_80126610(self->member, Hold(self->body));
    w3d_k7a_follow_transform_8002e670(self);
    self->anim = 0;
    self->anim = w3d_empty_80343584(self->body);
    const char *n1 = "Bomber.AnimIndex";
    int idx;
    w3d_auto_800fc230(&n1, &idx);
    w3d_cc21b_play_named_clip_80181640(self->anim, g_clip1_803f3c7c[idx], self->anim2, 0, 1.0f, 0.0f, 0.0f);
    w3d_cc21b_play_named_clip_80181640(self->anim, g_clip2_803f3c90[idx], self->anim2, 0, 1.0f, -1.0f, 0.0f);
    Msg *m = (Msg *)tsonnet_b33_arena_801613f0(g_arena_804b1754, 8);
    m->id = w3d_cached_message_id(&g_id_804acd10, 1);
    m->table = g_msg_table_8040db38;
    w3d_message_post_current(m);
    const char *n2 = "Bomber.EffectName";
    const char *eff;
    w3d_auto_800fc2b0(&n2, &eff);
    self->e80 = w3d_s20_forward_global5_800e5cf0(self->anim, g_898_804aa898, eff, -1, 0);
    self->e84 = w3d_s20_forward_global5_800e5cf0(self->anim, g_89c_804aa89c, eff, -1, 0);
    g_engine_804b1788->lib->t->load(g_engine_804b1788->lib, "Bomber.Engine", &self->engine1);
    g_engine_804b1788->lib->t->load(g_engine_804b1788->lib, "Bomber.Engine", &self->engine2);
    int v;
    self->engine2->t->get(self->engine2, 12, &v);
    v += 50;
    self->engine2->t->set(self->engine2, 2, v);
    w3d_cx12a_forward_positions_8002e59c(self);
    self->engine1->t->start(self->engine1);
    self->engine2->t->start(self->engine2);
    const char *n3 = "Bomber.Mesh";
    s8_property_write_800fc43c(&n3, self->anim);
}

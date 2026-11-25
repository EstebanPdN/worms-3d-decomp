#include "w3d_ptr.h"
#line 1 "d32a_bomber_setup_8002df8c.cpp"
// GWMP8P rev0 0x8002df8c. Sets up the bomber: flattens and normalises its
// flight direction and derives a heading from it, loads the Bomber object
// and its three attached parts, attaches a light, plays two named clips
// picked by Bomber.AnimIndex, posts a message, adds the two effects named by
// Bomber.EffectName, starts the two Bomber.Engine sounds with the second
// one's value raised by 50, and publishes the mesh as Bomber.Mesh. Names are
// inferred from the original strings and instructions.
struct String;
extern "C" void w3d_string_base_finish(Ptr32<String>);
extern "C" void w3d_string_release(Ptr32<String>);
struct String {
    Ptr32<const char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
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
    char pad[12]; Ptr32<void (Ptr32<Obj>)> add; char pad2[44]; Ptr32<int (Ptr32<Obj>)> kind;
    char pad3[12]; Ptr32<int (Ptr32<Obj>, Ptr32<const void>, int)> pos; Ptr32<int (Ptr32<Obj>, Ptr32<const Vec>, int)> rot;
    char pad4[8]; Ptr32<int (Ptr32<Obj>, Ptr32<Obj>, int)> link;
};
struct Obj { Ptr32<ObjTable> t; };
struct Hold { Ptr32<Obj> p; template <class W3dU> Hold(Ptr32<W3dU> w3d_p) : Hold((Obj *)w3d_p.get()) {}
 Hold(Obj *q) { p = q; if (p) p->t->add(p); } Hold(const Hold &o); };
struct Effect;
struct EffectTable { char pad[20]; Ptr32<int (Ptr32<Effect>)> start; char pad2[24]; Ptr32<int (Ptr32<Effect>, int, int)> set; char pad3[8]; Ptr32<int (Ptr32<Effect>, int, Ptr32<int>)> get; };
struct Effect { Ptr32<EffectTable> t; };
struct Lib;
struct LibTable { char pad[92]; Ptr32<int (Ptr32<Lib>, Ptr32<const char>, Ptr32<Ptr32<Effect>>)> load; };
struct Lib { Ptr32<LibTable> t; };
struct Engine { char pad[108]; Ptr32<Lib> lib; };
struct Id { int words[2]; };
struct Msg { unsigned short id; Ptr32<Ptr32<void>> table; };
struct Self {
    char pad[28]; Ptr32<Obj> body; Ptr32<Obj> left; Ptr32<Obj> right; Ptr32<Obj> tail; Ptr32<void> anim; char anim2[4];
    Vec dir; char pos[4]; int f80pad[3]; int e80; int e84; Ptr32<Effect> engine1; Ptr32<Effect> engine2; Ptr32<void> member;
};
extern Ptr32<void> g_af5bc_804af5bc;
extern Ptr32<Engine> g_engine_804b1788;
extern Ptr32<void> g_arena_804b1754;
extern Id g_id_804acd10;
extern Ptr32<void> g_msg_table_8040db38[];
extern int g_8a0_804aa8a0, g_8a4_804aa8a4, g_8a8_804aa8a8, g_898_804aa898, g_89c_804aa89c;
extern Ptr32<const char> g_clip1_803f3c7c[]; extern Ptr32<const char> g_clip2_803f3c90[];
extern char s_80372b54[];
extern "C" float fn_802e7c30(float);
extern "C" int w3d_handle_set_name(const String &, Ptr32<Ptr32<Obj>>, int);
extern "C" Ptr32<void> w3d_heap_allocate(Ptr32<Ptr32<void>>, int);
extern "C" Ptr32<void> w3d_handle_member_init_kind_8012656c(Ptr32<void>, int);
extern "C" int w3d_light_member_attach_80126610(Ptr32<void>, Hold);
extern "C" void w3d_k7a_follow_transform_8002e670(Ptr32<Self>);
extern "C" Ptr32<void> w3d_empty_80343584(Ptr32<Obj>);
extern "C" int w3d_auto_800fc230(Ptr32<Ptr32<const char>>, Ptr32<int>);
extern "C" int w3d_auto_800fc2b0(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<const char>>);
extern "C" int s8_property_write_800fc43c(Ptr32<Ptr32<const char>>, Ptr32<void>);
extern "C" int w3d_cc21b_play_named_clip_80181640(Ptr32<void>, Ptr32<const char>, Ptr32<void>, int, float, float, float);
extern "C" int w3d_s20_forward_global5_800e5cf0(Ptr32<void>, int, Ptr32<const char>, int, int);
extern "C" Ptr32<void> tsonnet_b33_arena_801613f0(Ptr32<void>, int);
extern "C" int w3d_cached_message_id(Ptr32<Id>, int);
extern "C" int w3d_message_post_current(Ptr32<Msg>);
extern "C" void w3d_cx12a_forward_positions_8002e59c(Ptr32<Self>);
extern "C" void w3d_d32a_bomber_setup_8002df8c(Ptr32<Self> self)
{
    Vec rot(0.0f, 0.0f, 0.0f);
    self->dir.y = 0.0f;
    self->dir.Normalise();
    float a = fn_802e7c30(self->dir.x);
    if (self->dir.z < 0.0f) a = 3.1415927f - a;
    rot.y = a;
    w3d_handle_set_name(String(s_80372b54), &self->body, 255);
    self->body->t->pos(self->body, (Ptr32<char>)self + 64, 0);
    self->body->t->rot(self->body, &rot, 0);
    w3d_handle_set_name(String("NULL"), &self->left, 255);
    w3d_handle_set_name(String("NULL"), &self->right, 255);
    self->body->t->link(self->body, self->left, g_8a0_804aa8a0);
    self->body->t->link(self->body, self->right, g_8a4_804aa8a4);
    w3d_handle_set_name(String("NULL"), &self->tail, 255);
    self->body->t->link(self->body, self->tail, g_8a8_804aa8a8);
    Ptr32<void> mem = w3d_heap_allocate(&g_af5bc_804af5bc, 4);
    self->member = w3d_handle_member_init_kind_8012656c(mem, self->body->t->kind(self->body));
    if (self->member) w3d_light_member_attach_80126610(self->member, Hold(self->body));
    w3d_k7a_follow_transform_8002e670(self);
    self->anim = 0;
    self->anim = w3d_empty_80343584(self->body);
    Ptr32<const char> n1 = "Bomber.AnimIndex";
    int idx;
    w3d_auto_800fc230(&n1, &idx);
    w3d_cc21b_play_named_clip_80181640(self->anim, g_clip1_803f3c7c[idx], self->anim2, 0, 1.0f, 0.0f, 0.0f);
    w3d_cc21b_play_named_clip_80181640(self->anim, g_clip2_803f3c90[idx], self->anim2, 0, 1.0f, -1.0f, 0.0f);
    Ptr32<Msg> m = (Ptr32<Msg>)tsonnet_b33_arena_801613f0(g_arena_804b1754, 8);
    m->id = w3d_cached_message_id(&g_id_804acd10, 1);
    m->table = g_msg_table_8040db38;
    w3d_message_post_current(m);
    Ptr32<const char> n2 = "Bomber.EffectName";
    Ptr32<const char> eff;
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
    Ptr32<const char> n3 = "Bomber.Mesh";
    s8_property_write_800fc43c(&n3, self->anim);
}



#include "w3d_ptr.h"
#line 1 "d32a_camera_director_update_80033208.cpp"
// GWMP8P rev0 0x80033208. Runs the camera director for one tick: it updates
// the current camera and copies its eye, look and up vectors. Unless a
// forced send is pending, it applies any queued lens settings, picks the
// blended or direct vectors, lets the owner adjust them and pushes each one
// that changed to the render camera. It then posts the change messages and
// runs the follow-up and logic hook. Names are inferred from the original
// instructions.
struct Vec { int x, y, z; bool operator==(const Vec &o) const { return x == o.x && y == o.y && z == o.z; } };
struct State { int a; int b; int c; int d; int e; };
struct Cam;
struct CamTable { char pad[12]; Ptr32<int (Ptr32<Cam>, Ptr32<State>, float)> update; };
struct Cam { char pad[4]; Vec eye; Vec look; Vec up; char pad2[8]; int mode; char pad3[20]; Ptr32<CamTable> t; };
struct Blend { char pad[4]; Vec eye; Vec look; Vec up; };
struct Ref;
struct RefTable { char pad[16]; Ptr32<void (Ptr32<Ref>)> release; char pad2[4]; Ptr32<int (Ptr32<Ref>)> p24; char pad3[8]; Ptr32<int (Ptr32<Ref>)> p36; };
struct Ref { Ptr32<RefTable> t; };
struct Light;
struct LightTable { char pad[28]; Ptr32<int (Ptr32<Light>, int)> s28; char pad2[8]; Ptr32<int (Ptr32<Light>, int)> s40; Ptr32<int (Ptr32<Light>, Ptr32<const Vec>)> eye; Ptr32<int (Ptr32<Light>, Ptr32<const Vec>)> look; Ptr32<int (Ptr32<Light>, Ptr32<const Vec>)> up; Ptr32<Ptr32<const Vec> (Ptr32<Light>)> geteye; Ptr32<Ptr32<const Vec> (Ptr32<Light>)> getlook; Ptr32<Ptr32<const Vec> (Ptr32<Light>)> getup; };
struct Light { Ptr32<LightTable> t; };
struct Engine { char pad[48]; Ptr32<Light> light; };
struct Self {
    char pad[312]; int cur; Ptr32<Ptr32<Cam>> cams; char pad2[12]; Vec eye; Vec look; Vec up; char pad3[36];
    Blend blend; char pad4[144]; int blending; int ready; State bs; char pad5[112]; State cs; char pad6[40];
    Ptr32<void> target; Ptr32<Ref> ref; char pad7[8]; int force;
    Ptr32<Cam> & Current() { return *(Ptr32<Ptr32<Cam>>)((Ptr32<char>)cams + (cur << 2)); }
};
struct Id { int words[2]; };
struct Msg { unsigned short id; Ptr32<Ptr32<void>> table; };
extern Ptr32<Engine> g_engine_804b1788;
extern Ptr32<void> g_arena_804b1754;
extern Ptr32<void> g_hook_804b1794;
extern Id g_id_804acf2c, g_id_804acf24;
extern Ptr32<void> g_msg_table_8040db38[];
extern "C" void s19_set_priority_flags_80032c18(Ptr32<Self>);
extern "C" void s19_send_range_800336d0(Ptr32<Self>);
extern "C" void w3d_auto_80032bb0(Ptr32<Self>, int);
extern "C" void w3d_auto_80108224(Ptr32<Blend>, Ptr32<State>, float);
extern "C" float w3d_auto_80178df0(Ptr32<void>);
extern "C" void w3d_auto_800359e4(Ptr32<Self>, Ptr32<Vec>, Ptr32<Vec>, Ptr32<Vec>, float);
extern "C" void fn_80035528(Ptr32<Self>);
extern "C" void w3d_logic_hook_800c88c4(Ptr32<void>);
extern "C" Ptr32<void> tsonnet_b33_arena_801613f0(Ptr32<void>, int);
extern "C" int w3d_cached_message_id(Ptr32<Id>, int);
extern "C" int w3d_message_post_current(Ptr32<Msg>);
inline void Post(Id &i)
{
    Ptr32<Msg> m = (Ptr32<Msg>)tsonnet_b33_arena_801613f0(g_arena_804b1754, 8);
    m->id = w3d_cached_message_id(&i, 1);
    m->table = g_msg_table_8040db38;
    w3d_message_post_current(m);
}
extern "C" int w3d_d32a_camera_director_update_80033208(Ptr32<Self> self)
{
    float dt = 0.02f;
    s19_set_priority_flags_80032c18(self);
    Ptr32<State> st = &self->cs;
    Ptr32<Cam> c = self->Current();
    int changed = 0;
    c->t->update(c, st, dt);
    st->c = 0;
    st->d = 0;
    st->e = 0;
    self->look = c->look;
    self->eye = c->eye;
    self->up = c->up;
    if (self->force) {
        s19_send_range_800336d0(self);
        changed = 1;
    } else {
        if (self->ref) {
            g_engine_804b1788->light->t->s28(g_engine_804b1788->light, self->ref->t->p24(self->ref));
            g_engine_804b1788->light->t->s40(g_engine_804b1788->light, self->ref->t->p36(self->ref));
            if (self->ref) self->ref->t->release(self->ref);
            self->ref = 0;
            w3d_auto_80032bb0(self, c->mode);
        }
        Vec b, a, d;
        if (self->blending && self->ready) {
            Ptr32<State> bs = &self->bs;
            w3d_auto_80108224(&self->blend, bs, dt);
            bs->c = 0;
            bs->d = 0;
            bs->e = 0;
            a = self->blend.eye;
            b = self->blend.look;
            d = self->blend.up;
        } else {
            a = self->eye;
            b = self->look;
            d = self->up;
        }
        w3d_auto_80178df0(self->target);
        w3d_auto_800359e4(self, &a, &b, &d, dt);
        if (!(*g_engine_804b1788->light->t->geteye(g_engine_804b1788->light) == a)) {
            changed = 1;
            g_engine_804b1788->light->t->eye(g_engine_804b1788->light, &a);
        }
        if (!(*g_engine_804b1788->light->t->getlook(g_engine_804b1788->light) == b)) {
            changed = 1;
            g_engine_804b1788->light->t->look(g_engine_804b1788->light, &b);
        }
        if (!(*g_engine_804b1788->light->t->getup(g_engine_804b1788->light) == d)) {
            changed = 1;
            g_engine_804b1788->light->t->up(g_engine_804b1788->light, &d);
        }
        if (changed) Post(g_id_804acf2c);
    }
    if (changed) Post(g_id_804acf24);
    fn_80035528(self);
    if (g_hook_804b1794) w3d_logic_hook_800c88c4(g_hook_804b1794);
    return 20;
}



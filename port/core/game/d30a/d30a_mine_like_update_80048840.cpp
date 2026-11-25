#include "w3d_ptr.h"
#line 1 "d30a_mine_like_update_80048840.cpp"
// GWMP8P rev0 0x80048840. Per-frame update of a placed object: copies its
// target's position to the body and members, when first active shows it and
// spawns attached effects, and once the target is free plays a named clip on
// its part and detaches it when the clip ends. Names are inferred from the
// original instructions.
struct Vec {
    float x, y, z;
    Vec(float a, float b, float c) { z = c; x = a; y = b; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec Above(float h) const { return Vec(x, y + h, z); }
};
inline Vec Copy(const Vec &o) { return Vec(o); }
struct Iface;
typedef Ptr32<void (Ptr32<Iface>, Ptr32<const Vec>, int)> SlotP;
typedef Ptr32<void (Ptr32<Iface>, int)> SlotI;
typedef Ptr32<void (Ptr32<Iface>, Ptr32<Iface>)> SlotO;
typedef Ptr32<void (Ptr32<Iface>)> SlotV;
struct Table { char pad[16]; SlotV release; char pad2[56]; SlotP place; char pad3[8]; SlotI show; char pad4[4]; SlotO attach; };
struct Iface { Ptr32<Table> t; };
struct Thing { char pad[40]; Vec pos; char pad2[44]; int busy; char pad3[12]; int locked; };
struct Member;
struct Self {
    char pad[28]; int id; Ptr32<Iface> body; Ptr32<Iface> part; Ptr32<Member> m1; Ptr32<Member> m2; int active; char pad2[20]; int clip; int started;
};
extern char g_clip_name_803766bc[];
extern "C" Ptr32<Thing> w3d_s20_lookup_handle_object_80164fc8(int);
extern "C" void w3d_fn_80049108(Ptr32<Self>);
extern "C" void w3d_fn_80049180(Ptr32<Self>);
extern "C" int s19_handle_not_minus1_80049298(Ptr32<Self>);
extern "C" void fn_800492cc(Ptr32<Self>, Ptr32<const Vec>);
extern "C" void w3d_handle_member_query_801265ec(Ptr32<Member>, Ptr32<const Vec>);
extern "C" void w3d_handle_member_destroy_801265a4(Ptr32<Member>, int);
extern "C" Ptr32<void> w3d_empty_80343584(Ptr32<Iface>);
extern "C" int w3d_mesh_instance_control_3c(Ptr32<void>, int);
extern "C" int w3d_cc21b_play_named_clip_80181640(Ptr32<void>, Ptr32<const char>, Ptr32<int>, float, float, float, int);
extern "C" int w3d_mesh_instance_is_playing(Ptr32<void>, int);
extern "C" void w3d_d30a_mine_like_update_80048840(Ptr32<Self> self)
{
    Ptr32<Thing> t = w3d_s20_lookup_handle_object_80164fc8(self->id);
    if (!t) return;
    Vec pos = Copy(t->pos);
    self->body->t->place(self->body, &pos, 0);
    if (self->active) {
        if (t->busy) return;
        self->active = 0;
        self->body->t->show(self->body, 1);
        if (self->part) {
            self->part->t->show(self->part, 1);
            w3d_fn_80049108(self);
        }
        w3d_fn_80049180(self);
        if (s19_handle_not_minus1_80049298(self)) {
            Vec p = Copy(t->pos);
            fn_800492cc(self, &p);
        }
    }
    if (self->m2) { Vec a = pos.Above(30.0f); w3d_handle_member_query_801265ec(self->m2, &a); }
    if (self->m1) { Vec a = pos.Above(10.0f); w3d_handle_member_query_801265ec(self->m1, &a); }
    if (t->locked) return;
    if (!self->part) return;
    Ptr32<void> mesh = w3d_empty_80343584(self->part);
    if (!self->started) {
        self->started = 1;
        w3d_mesh_instance_control_3c(mesh, -1);
        w3d_cc21b_play_named_clip_80181640(mesh, g_clip_name_803766bc, &self->clip, 1.0f, 0.0f, 0.0f, 0);
    } else if (w3d_mesh_instance_is_playing(mesh, self->clip)) {
        self->body->t->attach(self->body, self->part);
        if (self->m2) w3d_handle_member_destroy_801265a4(self->m2, 3);
        self->m2 = 0;
        if (self->part) self->part->t->release(self->part);
        self->part = 0;
    }
}



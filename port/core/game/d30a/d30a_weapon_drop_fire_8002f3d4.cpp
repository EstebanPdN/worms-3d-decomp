#include "w3d_ptr.h"
#line 1 "d30a_weapon_drop_fire_8002f3d4.cpp"
// GWMP8P rev0 0x8002f3d4. Releases a weapon projectile from its carrier: a
// scaled drop vector and the time since it started give the end point; one
// named object is routed through weapon property defaults, every other one
// gets a new effect through the service lookup with its start and end
// points. Names are inferred from the original instructions.
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
struct Res;
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Res &o);
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Res {
    float x, y, z;
    Res(const Vec &a, float f) { x = a.x * f; y = a.y * f; z = a.z * f; }
    Res(const Vec &a, const Vec &b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; }
};
inline Vec::Vec(const Res &o) { x = o.x; y = o.y; z = o.z; }
inline Vec Mul(const Vec &a, float f) { Res r(a, f); return Vec(r); }
inline Vec Add(const Vec &a, const Vec &b) { Res r(a, b); return Vec(r); }
struct Iface;
typedef Ptr32<void (Ptr32<Iface>)> Plain;
typedef Ptr32<Ptr32<const char> (Ptr32<Iface>)> Name;
typedef Ptr32<void (Ptr32<Iface>, Ptr32<const Vec>)> SetV;
struct Table { char pad[12]; Plain add; Plain release; char pad2[12]; Name name; char pad3[4]; SetV dir; };
struct Iface { Ptr32<Table> t; };
struct Ref {
    Ptr32<Iface> p;
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Iface *)w3d_p.get()) {}
 Ref(Iface *q) { p = q; if (p) p->t->add(p); }
    Ref(const Ref &o);
    ~Ref() { if (p) p->t->release(p); }
};
struct Hold { Ptr32<Iface> p; template <class W3dU> Hold(Ptr32<W3dU> w3d_p) : Hold((Iface *)w3d_p.get()) {}
 Hold(Iface *q) { p = q; if (p) p->t->add(p); } Hold(const Hold &o); };
struct Sub { char pad[24]; int on; };
struct Thing { char pad[232]; Ptr32<Sub> sub; char pad2[244]; int fixed; };
struct Team { char pad[20]; int id; };
struct Self { char pad[28]; Ptr32<Iface> body; Vec pos; Vec dir; float speed; unsigned int start; };
struct Id { int words[2]; };
struct Msg { unsigned short id; Ptr32<Ptr32<void>> table; };
extern Ptr32<Team> g_team_804aab4c;
extern Ptr32<void> g_arena_804b1754;
extern Ptr32<void> g_hub_804b178c;
extern Id g_msg_804acd44;
extern Ptr32<void> g_msg_table_8040db38[];
extern Vec g_fixed_8045e788[];
extern char g_key_8040fd78[];
extern char s_80372e98[], s_80372eb0[], s_80372ec8[], s_80372edc[], s_80372ee8[], s_80372ef0[], s_80372f00[], s_80372f18[];
extern "C" Ptr32<void> w3d_empty_80341584(Ptr32<Iface>);
extern "C" Ptr32<Thing> w3d_auto_801797b4(Ptr32<void>);
extern "C" void f10b_crate_defaults_8008a044(Ptr32<Team>);
extern "C" void w3d_cx9a_service_result_append_80089eec(Ptr32<Team>);
extern "C" int w3d_auto_800fc1f0(Ptr32<Ptr32<const char>>, Ptr32<int>);
extern "C" int s8_property_write_800fc3b0(Ptr32<Ptr32<const char>>, int);
extern "C" int s8_property_read_800fc550(Ptr32<Ptr32<const char>>, Ptr32<const char>);
extern "C" int s8_property_read_800fc5dc(Ptr32<Ptr32<const char>>, Ptr32<const Vec>);
extern "C" Ptr32<void> tsonnet_b33_arena_801613f0(Ptr32<void>, int);
extern "C" int w3d_cached_message_id(Ptr32<Id>, int);
extern "C" int w3d_message_post_current(Ptr32<Msg>);
extern "C" Ptr32<Iface> w3d_s10_service_forward_8020b680(Ptr32<const void>);
extern "C" void w3d_assign_interface_arg_800eb65c(Ptr32<Iface>, Ptr32<Ptr32<Iface>>);
extern "C" void w3d_copy12_800eb8f0(Ptr32<Iface>, Ptr32<const Vec>);
extern "C" void w3d_copy12_800eb8d0(Ptr32<Iface>, Ptr32<const Vec>);
extern "C" int fn_80164514(Ptr32<void>, Ptr32<Iface>, int);
extern "C" void w3d_d30a_weapon_drop_fire_8002f3d4(Ptr32<Self> self, unsigned int now)
{
    Ptr32<Thing> t = w3d_auto_801797b4(w3d_empty_80341584(self->body));
    Ptr32<Team> team = g_team_804aab4c;
    Vec d = Mul(self->dir, self->speed);
    Ptr32<const Vec> g;
    if (t->fixed) g = g_fixed_8045e788; else g = &d;
    Vec from(*g);
    Vec end = Add(self->pos, Mul(d, (float)(now - self->start)));
    if (strcmp(self->body->t->name(self->body), s_80372e98) == 0) {
        f10b_crate_defaults_8008a044(g_team_804aab4c);
        Ptr32<const char> n1 = s_80372eb0; int v;
        w3d_auto_800fc1f0(&n1, &v);
        Ptr32<const char> n2 = s_80372ec8;
        s8_property_write_800fc3b0(&n2, v);
        Ptr32<const char> n3 = s_80372edc;
        s8_property_read_800fc550(&n3, s_80372ee8);
        Ptr32<const char> n4 = s_80372ef0;
        s8_property_write_800fc3b0(&n4, 1);
        Ptr32<const char> n5 = s_80372f00;
        s8_property_write_800fc3b0(&n5, 2);
        Ptr32<const char> n6 = s_80372f18;
        s8_property_read_800fc5dc(&n6, &end);
        w3d_cx9a_service_result_append_80089eec(g_team_804aab4c);
        return;
    }
    if (t->sub->on) {
        Ptr32<Msg> m = (Ptr32<Msg>)tsonnet_b33_arena_801613f0(g_arena_804b1754, 8);
        m->id = w3d_cached_message_id(&g_msg_804acd44, 1);
        m->table = g_msg_table_8040db38;
        w3d_message_post_current(m);
    }
    Ref r(w3d_s10_service_forward_8020b680(g_key_8040fd78));
    Hold o(self->body);
    w3d_assign_interface_arg_800eb65c(r.p, &o.p);
    w3d_copy12_800eb8f0(r.p, &from);
    w3d_copy12_800eb8d0(r.p, &end);
    r.p->t->dir(r.p, &self->dir);
    fn_80164514(g_hub_804b178c, r.p, team->id);
}



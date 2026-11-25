#include "w3d_ptr.h"
#line 1 "d30a_crate_spawn_announce_800492cc.cpp"
// GWMP8P rev0 0x800492cc. Announces a new crate: plays the spawn particle
// and sound at its position, finds the living team nearest to it, posts the
// crate kind message and queues the target message for that team. Names are
// inferred from the original instructions.
struct Vec {
    float x, y, z;
    float Dist2(const Vec &o) const { float dy = y - o.y, dx = x - o.x, dz = z - o.z; return dx * dx + dy * dy + dz * dz; }
};
struct Self { char pad[28]; int id; };
struct Iface;
typedef Ptr32<void (Ptr32<Iface>, Ptr32<const char>, Ptr32<const Vec>)> Say;
struct Table { char pad[96]; Say say; };
struct Iface { Ptr32<Table> t; };
struct Engine { char pad[108]; Ptr32<Iface> sound; };
struct Team { char pad[80]; Vec pos; char pad2[128]; int alive; };
struct Thing { char pad[28]; int kind; };
struct Id { int words[2]; };
struct Msg { unsigned short id; Ptr32<Ptr32<void>> table; };
extern Ptr32<Engine> g_engine_804b1788;
extern Ptr32<void> g_arena_804b1754;
extern Id g_health_804ad2f8, g_weapon_804ad300, g_utility_804ad308, g_target_804ad2e0;
extern Ptr32<void> g_msg_table_8040db38[];
extern char g_a_80376764[], g_b_80376774[];
extern "C" int w3d_s20_forward_global_800e5ca4(Ptr32<const Vec>, Ptr32<const char>, int, float);
extern "C" Ptr32<Team> s8_index_query_800fc6dc(int);
extern "C" Ptr32<Thing> w3d_s20_lookup_handle_object_80164fc8(int);
extern "C" Ptr32<void> tsonnet_b33_arena_801613f0(Ptr32<void>, int);
extern "C" int w3d_cached_message_id(Ptr32<Id>, int);
extern "C" int w3d_message_post_current(Ptr32<Msg>);
extern "C" Ptr32<void> w3d_message_int_init(Ptr32<void>, unsigned short, int);
extern "C" int w3d_d24h_pool_add_800c53a0(Ptr32<void>, int);
inline void Announce(Ptr32<Id> which, int team)
{
    Ptr32<Msg> m = (Ptr32<Msg>)tsonnet_b33_arena_801613f0(g_arena_804b1754, 8);
    m->id = w3d_cached_message_id(which, 1);
    m->table = g_msg_table_8040db38;
    w3d_message_post_current(m);
    Ptr32<void> t = tsonnet_b33_arena_801613f0(g_arena_804b1754, 12);
    w3d_d24h_pool_add_800c53a0(w3d_message_int_init(t, w3d_cached_message_id(&g_target_804ad2e0, 1), team), 2400);
}
extern "C" void w3d_d30a_crate_spawn_announce_800492cc(Ptr32<Self> self, Ptr32<const Vec> pos)
{
    w3d_s20_forward_global_800e5ca4(pos, g_a_80376764, 0, 0.0f);
    Ptr32<Iface> s = g_engine_804b1788->sound;
    if (s) s->t->say(s, g_b_80376774, pos);
    int best = -1;
    float d = 1000000.0f;
    for (int i = 0; i < 16; i++) {
        Ptr32<Team> t = s8_index_query_800fc6dc(i);
        if (t->alive) {
            float e = t->pos.Dist2(*pos);
            if (best == -1 || e < d) { d = e; best = i; }
        }
    }
    Ptr32<Thing> o = w3d_s20_lookup_handle_object_80164fc8(self->id);
    if (!o) return;
    switch (o->kind) {
    case 0: Announce(&g_health_804ad2f8, best); break;
    case 2: Announce(&g_weapon_804ad300, best); break;
    case 1: Announce(&g_utility_804ad308, best); break;
    }
}



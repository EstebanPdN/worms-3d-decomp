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
typedef void (*Say)(Iface *, const char *, const Vec *);
struct Table { char pad[96]; Say say; };
struct Iface { Table *t; };
struct Engine { char pad[108]; Iface *sound; };
struct Team { char pad[80]; Vec pos; char pad2[128]; int alive; };
struct Thing { char pad[28]; int kind; };
struct Id { int words[2]; };
struct Msg { unsigned short id; void **table; };
extern Engine *g_engine_804b1788;
extern void *g_arena_804b1754;
extern Id g_health_804ad2f8, g_weapon_804ad300, g_utility_804ad308, g_target_804ad2e0;
extern void *g_msg_table_8040db38[];
extern char g_a_80376764[], g_b_80376774[];
extern "C" int w3d_s20_forward_global_800e5ca4(const Vec *, const char *, int, float);
extern "C" Team *s8_index_query_800fc6dc(int);
extern "C" Thing *w3d_s20_lookup_handle_object_80164fc8(int);
extern "C" void *tsonnet_b33_arena_801613f0(void *, int);
extern "C" int w3d_cached_message_id(Id *, int);
extern "C" int w3d_message_post_current(Msg *);
extern "C" void *w3d_message_int_init(void *, unsigned short, int);
extern "C" int w3d_d24h_pool_add_800c53a0(void *, int);
inline void Announce(Id *which, int team)
{
    Msg *m = (Msg *)tsonnet_b33_arena_801613f0(g_arena_804b1754, 8);
    m->id = w3d_cached_message_id(which, 1);
    m->table = g_msg_table_8040db38;
    w3d_message_post_current(m);
    void *t = tsonnet_b33_arena_801613f0(g_arena_804b1754, 12);
    w3d_d24h_pool_add_800c53a0(w3d_message_int_init(t, w3d_cached_message_id(&g_target_804ad2e0, 1), team), 2400);
}
extern "C" void w3d_d30a_crate_spawn_announce_800492cc(Self *self, const Vec *pos)
{
    w3d_s20_forward_global_800e5ca4(pos, g_a_80376764, 0, 0.0f);
    Iface *s = g_engine_804b1788->sound;
    if (s) s->t->say(s, g_b_80376774, pos);
    int best = -1;
    float d = 1000000.0f;
    for (int i = 0; i < 16; i++) {
        Team *t = s8_index_query_800fc6dc(i);
        if (t->alive) {
            float e = t->pos.Dist2(*pos);
            if (best == -1 || e < d) { d = e; best = i; }
        }
    }
    Thing *o = w3d_s20_lookup_handle_object_80164fc8(self->id);
    if (!o) return;
    switch (o->kind) {
    case 0: Announce(&g_health_804ad2f8, best); break;
    case 2: Announce(&g_weapon_804ad300, best); break;
    case 1: Announce(&g_utility_804ad308, best); break;
    }
}

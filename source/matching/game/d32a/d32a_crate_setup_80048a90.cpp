// GWMP8P rev0 0x80048a90. Sets up a dropped crate from its spawn record:
// reads ActiveWormIndex, picks the Crate.Health, Weapon, Utility or Target
// model, scales and places it, adds its light and optional Crate.Chute with
// a Parachute link, hides both while it drops or else announces the spawn
// and runs its two follow-ups, then subscribes four message handlers. Names
// are inferred from the original strings and instructions.
struct String;
extern "C" void w3d_string_base_finish(String *);
extern "C" void w3d_string_release(String *);
struct String {
    const char *text;
    String(const char *);
    String(const String &o);
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Obj;
struct ObjTable {
    char pad[12]; void (*add)(Obj *); void (*release)(Obj *); char pad2[40]; int (*kind)(Obj *);
    char pad3[12]; int (*pos)(Obj *, const Vec *, int); char pad4[4]; int (*scale)(Obj *, const Vec *, int);
    int (*vis)(Obj *, int); int (*link)(Obj *, Obj *, const char *);
};
struct Obj { ObjTable *t; };
struct Hold { Obj *p; Hold(Obj *q) { p = q; if (p) p->t->add(p); } Hold(const Hold &o); };
struct Crate { char pad[28]; int kind; char pad2[8]; Vec pos; char pad3[44]; int drop; char pad4[12]; int chute; char pad5[36]; float scale; };
struct Self {
    char pad[28]; int id; Obj *body; Obj *chute; void *m40; void *m44; int landed;
    char h52[4]; char h56[4]; char h60[4]; char h64[4]; char pad2[12]; Obj *index;
};
struct Id { int words[2]; };
struct Key { const char *name; };
struct Ref { Obj *p; Ref() {} Ref(const Ref &); ~Ref() { if (p) p->t->release(p); } };
extern void *g_heap_804af5bc;
extern Id g_id_804ad2e8, g_id_804ad2f0, g_id_804ad310, g_id_804ad318;
extern "C" Crate *w3d_s20_lookup_handle_object_80164fc8(int);
extern "C" int w3d_constructor_lookup_name(Key *, Ref *);
extern "C" Obj *w3d_empty_803426b4(Obj *);
extern "C" Obj *w3d_empty_80343584(Obj *);
extern "C" int w3d_handle_set_name(const String &, Obj **, int);
extern "C" void *w3d_heap_allocate(void **, int);
extern "C" void *w3d_handle_member_init_kind_8012656c(void *, int);
extern "C" int w3d_handle_member_query_801265ec(void *, const Vec *);
extern "C" int w3d_light_member_attach_80126610(void *, Hold);
extern "C" int s19_handle_not_minus1_80049298(Self *);
extern "C" void w3d_d30a_crate_spawn_announce_800492cc(Self *, const Vec *);
extern "C" void w3d_fn_80049180(Self *);
extern "C" void w3d_fn_80049108(Self *);
extern "C" int w3d_cached_message_id(Id *, int);
extern "C" int d24d_acquire_message_80162024(Self *, const unsigned short &, void *);
inline void Fetch(Key &k, Ref &r) { r.p = 0; w3d_constructor_lookup_name(&k, &r); }
inline void Load(const char *name, Obj *&slot)
{
    Ref h;
    Key key;
    key.name = name;
    Fetch(key, h);
    Obj *o = w3d_empty_803426b4(h.p);
    if (o) o->t->add(o);
    if (slot) slot->t->release(slot);
    slot = o;
}
extern "C" void w3d_d32a_crate_setup_80048a90(Self *self)
{
    Crate *c = w3d_s20_lookup_handle_object_80164fc8(self->id);
    if (!c) return;
    Load("ActiveWormIndex", self->index);
    switch (c->kind) {
    case 1: w3d_handle_set_name(String("Crate.Health"), &self->body, 255); break;
    case 0: w3d_handle_set_name(String("Crate.Weapon"), &self->body, 255); break;
    case 2: w3d_handle_set_name(String("Crate.Utility"), &self->body, 255); break;
    case 3: w3d_handle_set_name(String("Crate.Target"), &self->body, 255); break;
    }
    Vec s(c->scale, c->scale, c->scale);
    self->body->t->scale(self->body, &s, 0);
    Vec p(c->pos);
    { Obj *o = w3d_empty_80343584(self->body); o->t->pos(o, &p, 0); }
    self->m40 = w3d_handle_member_init_kind_8012656c(w3d_heap_allocate(&g_heap_804af5bc, 4), self->body->t->kind(self->body));
    w3d_handle_member_query_801265ec(self->m40, &p);
    w3d_light_member_attach_80126610(self->m40, Hold(self->body));
    if (c->chute) {
        w3d_handle_set_name(String("Crate.Chute"), &self->chute, 255);
        self->body->t->link(self->body, self->chute, "Parachute");
        self->m44 = w3d_handle_member_init_kind_8012656c(w3d_heap_allocate(&g_heap_804af5bc, 4), self->chute->t->kind(self->chute));
        w3d_handle_member_query_801265ec(self->m44, &p);
        w3d_light_member_attach_80126610(self->m44, Hold(self->chute));
    }
    if (c->drop) {
        self->body->t->vis(self->body, 0);
        if (self->chute) self->chute->t->vis(self->chute, 0);
        self->landed = 1;
    } else {
        if (s19_handle_not_minus1_80049298(self)) { Vec q(c->pos); w3d_d30a_crate_spawn_announce_800492cc(self, &q); }
        w3d_fn_80049180(self);
        w3d_fn_80049108(self);
    }
    d24d_acquire_message_80162024(self, w3d_cached_message_id(&g_id_804ad2e8, 1), self->h56);
    d24d_acquire_message_80162024(self, w3d_cached_message_id(&g_id_804ad2f0, 1), self->h52);
    d24d_acquire_message_80162024(self, w3d_cached_message_id(&g_id_804ad310, 1), self->h60);
    d24d_acquire_message_80162024(self, w3d_cached_message_id(&g_id_804ad318, 1), self->h64);
}

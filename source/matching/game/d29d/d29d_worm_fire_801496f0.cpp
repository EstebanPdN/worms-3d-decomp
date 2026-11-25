// GWMP8P rev0 0x801496f0. Worm fires its selected weapon: checks ammunition,
// clears links, then creates the weapon's entity from its descriptor and sends
// it to the entity service. Names are inferred from use; virtual slots are
// reference-ABI observations.
struct Type;
struct Obj;
struct ObjVt { char u0[12]; void (*retain)(Obj *); void (*release)(Obj *); Type *(*type)(Obj *); };
struct Obj { ObjVt *vt; char u4[36]; int f40; char u2c[248]; int f292; char u128[444]; int f740; };
struct Type { char u0[20]; Type *parent; bool is_a(Type *target) { Type *t = this; while (t != target) { if (t == t->parent) return false; t = t->parent; } return true; } };
struct Ref {
    Obj *p;
    Ref() { p = 0; }
    Ref(Obj *o) { p = o; if (p) p->vt->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
    void operator=(Obj *q) { if (q) q->vt->retain(q); if (p) p->vt->release(p); p = q; }
};
struct Handle { int value; unsigned key; Handle(int v) { value = v; key = 58280; } ~Handle(); };
struct Plain { short id; void *vt; };
struct Item { char u0[132]; int f132; };
struct Worm { void *vt; char u4[16]; int f20; char u18[560]; int f584; char u24c[196]; int f784; int f788; char u31c[4]; int f796; };
extern "C" {
int avail_800fcea0();
Item *item_800fc710(int, const Handle &);
void *alloc_801613f0(void *, int);
short message_id_8015f5a0(int *, int);
int post_8016239c(void *);
Item *query_800fc6dc(int);
int auto_80151128(Worm *);
int link_8014dcbc(Worm *);
void clear_links_8014df84(Worm *, int);
int send_to_8015fc58(Worm *, void *);
int get_800fc330(const void *, Obj **);
Obj *create_8020b680(void *);
void use_800ee904(Obj *, int);
void use_8009c820(Obj *, int);
void logic_800c31f4(Obj *, int);
int send_80164514(void *, Obj *, int);
void set_fire_80153dfc(Worm *, int);
void third_80150b6c(Worm *, int);
int owner_8014c488(Worm *);
void use_8002b070(Obj *, int);
}
extern void *heap_804b1754;
extern void *service_804b178c;
extern unsigned char vt_8040db38[];
extern Type type_80368328[];
extern int table_803eb63c[];
extern int table2_803eb700[], table2_803eb710[];
extern Worm *owner_804aab4c;
extern char desc_80410258[];
extern char desc_8040e398[];
extern char desc_8040ed18[];
extern char desc_8040eed8[];
extern char desc_8040f0d0[];
extern char desc_8040f1e8[];
extern char desc_8040f380[];
extern char desc_8040f680[];
extern char desc_8040f8d8[];
extern char desc_8040f998[];
extern char desc_8040fbf8[];
extern char desc_8040fc38[];
extern char desc_80410418[];
extern char desc_80410550[];
extern char desc_80410628[];
extern char desc_80410840[];
extern char desc_80410940[];
extern char desc_80410f70[];
extern int cache_804afb98;
extern int cache_804afbc8;
extern int cache_804afcb8;
extern int cache_804afcd8;
extern int cache_804afdc0;
inline void post_plain(int *cache) {
    Plain *p = (Plain *)alloc_801613f0(heap_804b1754, 8);
    p->id = message_id_8015f5a0(cache, 1);
    p->vt = vt_8040db38;
    post_8016239c(p);
}
inline void post_to(Worm *self, int *cache) {
    Plain *p = (Plain *)alloc_801613f0(heap_804b1754, 8);
    p->id = message_id_8015f5a0(cache, 1);
    p->vt = vt_8040db38;
    send_to_8015fc58(self, p);
}
extern "C" void d29d_worm_fire_801496f0(Worm *self) {
    int spent = 0;
    unsigned i;
    int r;
    i = 0;
    goto test;
body:
    if (i - 49 > 1) {
        Handle h(r);
        spent = 1;
        item_800fc710(self->f584, h)->f132 = i;
    }
    i++;
test:
    if (i <= 59) goto check;
    {
        Handle h(0);
        item_800fc710(self->f584, h)->f132 = 58;
        post_plain(&cache_804afdc0);
        return;
    }
check:
    r = avail_800fcea0();
    if (!r) goto body;
    int weapon = query_800fc6dc(self->f584)->f132;
    if (spent) { post_plain(&cache_804afbc8); return; }
    if (auto_80151128(self)) {
        if (self->f788 != -1 && !link_8014dcbc(self)) {
            clear_links_8014df84(self, 1);
        } else {
            switch (weapon) {
            case 18: case 4: case 7: case 23: case 24: case 33: break;
            default: clear_links_8014df84(self, 1); break;
            }
        }
    }
    self->f796 = 1;
    post_to(self, &cache_804afb98);
    {
        Obj *o;
        get_800fc330(&table_803eb63c[weapon], &o);
        if (o->vt->type(o)->is_a(type_80368328)) {
            Ref r(create_8020b680(desc_80410258));
            use_800ee904(r.p, table_803eb63c[weapon]);
            send_80164514(service_804b178c, r.p, self->f20);
        } else {
        switch ((unsigned)weapon) {
    case 8: case 9: case 30:
        { Ref r(create_8020b680(desc_8040f380)); use_8009c820(r.p, table_803eb63c[weapon]); send_80164514(service_804b178c, r.p, self->f20); } break;
    case 10: case 11: case 12: case 13:
        clear_links_8014df84(self, 1);
        { Ref r(create_8020b680(desc_8040f998)); logic_800c31f4(r.p, table_803eb63c[weapon]); send_80164514(service_804b178c, r.p, self->f20); } break;
    case 47:
        { Ref r(create_8020b680(desc_80410940)); send_80164514(service_804b178c, r.p, self->f20); } break;
    case 48:
        clear_links_8014df84(self, 1);
        { Ref r(create_8020b680(desc_8040f680)); self->f784 = send_80164514(service_804b178c, r.p, self->f20); set_fire_80153dfc(self, 1); } break;
    case 41:
        clear_links_8014df84(self, 1);
        {
            Ref r;
            r = create_8020b680(desc_8040fbf8);
            self->f788 = send_80164514(service_804b178c, r.p, self->f20);
            r.p->f292 = self->f20;
            post_to(self, &cache_804afb98);
            set_fire_80153dfc(self, 1);
        } break;
    case 42:
        clear_links_8014df84(self, 1);
        third_80150b6c(self, 0);
        if (owner_8014c488(self)) set_fire_80153dfc(self, 1);
        break;
    case 49:
        { Ref r(create_8020b680(desc_80410628)); use_8002b070(r.p, *table2_803eb700); send_80164514(service_804b178c, r.p, self->f20); } break;
    case 17:
        { Ref r(create_8020b680(desc_8040ed18)); send_80164514(service_804b178c, r.p, owner_804aab4c->f20); } break;
    case 43:
        { Ref r(create_8020b680(desc_80410550)); send_80164514(service_804b178c, r.p, self->f20); } break;
    case 39:
        { Ref r(create_8020b680(desc_8040f1e8)); send_80164514(service_804b178c, r.p, self->f20); } break;
    case 40:
        { Ref r(create_8020b680(desc_8040f1e8)); r.p->f740 = 5; send_80164514(service_804b178c, r.p, self->f20); } break;
    case 26:
        { Ref r(create_8020b680(desc_8040fc38)); send_80164514(service_804b178c, r.p, self->f20); } break;
    case 44:
        { Ref r(create_8020b680(desc_8040f8d8)); r.p->f40 = self->f20; send_80164514(service_804b178c, r.p, self->f20); } break;
    case 52:
        { Ref r(create_8020b680(desc_8040f0d0)); send_80164514(service_804b178c, r.p, self->f20); } break;
    case 45:
        { Ref r(create_8020b680(desc_8040eed8)); send_80164514(service_804b178c, r.p, self->f20); } break;
    case 51:
        { Ref r(create_8020b680(desc_80410f70)); send_80164514(service_804b178c, r.p, self->f20); post_plain(&cache_804afcd8); } break;
    case 50:
        { Ref r(create_8020b680(desc_80410840)); send_80164514(service_804b178c, r.p, self->f20); } break;
    case 35:
        { Ref r(create_8020b680(desc_8040e398)); send_80164514(service_804b178c, r.p, self->f20); } break;
    case 53:
        { Ref r(create_8020b680(desc_80410418)); use_8002b070(r.p, *table2_803eb710); send_80164514(service_804b178c, r.p, self->f20); } break;
        }
        }
    }
    post_plain(&cache_804afcb8);
}

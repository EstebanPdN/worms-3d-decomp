// GWMP8P rev0 0x80148ef0. Worm pending damage. Names are inferred from use
// and the log strings. Virtual slots are reference-ABI observations.
struct Vec { float x, y, z; };
struct TypeDesc {
    char pad[20];
    TypeDesc *parent;
    bool is_a(TypeDesc *target) {
        TypeDesc *t = this;
        while (t != target) {
            if (t == t->parent) return false;
            t = t->parent;
        }
        return true;
    }
};
extern TypeDesc type_80361860[];
extern TypeDesc type_803618f0[];
struct Object {
    virtual int query_interface();
    virtual void retain();
    virtual void release();
    virtual TypeDesc *type();
};
struct Worm : Object {
    char u4[16]; int id; char u18[560]; int index; char u24c[60]; int dying; char u28c[8]; int f660; char u298[52]; int moving; char u2d0[88]; int slotA; int slotB; char u32c[8]; int flags; char u33c[284];
    void *barA; void *barB; char u460[132]; void *anim;
};
struct Info { char u0[164]; int alive; char u168[45]; unsigned char team; char ud6[6]; int active; };
struct Item { char u0[80]; Vec v; char u5c[72]; int pending; char ua8[2]; unsigned short hp; };
struct Anim { char u0[60]; int mode; };
struct Handle { int value; unsigned key; Handle(int v) { value = v; key = 58280; } ~Handle(); };
struct Message;
struct Plain { short id; void *vt; };
extern "C" Info *query_800fc6dc(int);
extern "C" Anim *anim_801797b4(void *);
extern "C" Item *item_800fc710(int, const Handle &);
extern "C" int log_80022e20(const char *, const char *, int, int *);
extern const char logic_entity_803a0e2c[];
extern const char active_worm_803a0e0c[];
extern "C" void *alloc_801613f0(void *, int);
extern "C" short msg_id_8015f5a0(void *, int);
extern "C" void *target_message_801190b4(void *, unsigned short, int);
extern "C" void *int_message_800a82f0(void *, unsigned short, int);
extern "C" int post_8016239c(void *);
extern "C" int setting_800fc1f0(const char **, int *);
extern "C" void set_state_801492ec(Worm *, int);
extern "C" void *get_803426b4(void *);
extern "C" void *get_80342fa4(void *);
extern "C" int update_80178c54(void *, const int *);
extern "C" int set_vector_80178fa4(void *, const Vec *);
struct Engine { char u0[52]; int now; };
extern "C" Engine *engine_80165254();
extern "C" int pool_add_800c53a0(void *, int);
extern "C" void check_801506f8(Worm *);
extern void *heap_804b1754;
extern int cacheA_804afcf0, cacheB_804afd10, cacheC_804afba0, cacheD_804afd78;
extern unsigned char vt_8040db38[];
extern "C" void d28d_worm_take_damage_80148ef0(Worm *self) {
    int zero = 0;
    self->f660 = zero;
    Info *info = query_800fc6dc(self->index);
    if (!info->active) return;
    if (!info->alive) return;
    if (anim_801797b4(self->anim)->mode == 1) return;
    Handle h(zero);
    Item *it = item_800fc710(self->index, h);
    int hp = it->hp;
    int dmg = it->pending;
    if (dmg >= hp) {
        it->hp = zero;
        self->dying = 1;
        if (self->type()->is_a(type_80361860) || self->type()->is_a(type_803618f0)) log_80022e20("Worm Waiting To Die", logic_entity_803a0e2c, 2610, &self->slotA);
        post_8016239c(target_message_801190b4(alloc_801613f0(heap_804b1754, 12), msg_id_8015f5a0(&cacheA_804afcf0, 1), self->id));
    } else {
        if (dmg > 0) {
            const char *name = active_worm_803a0e0c;
            int active = zero;
            setting_800fc1f0(&name, &active);
            int team = query_800fc6dc(active)->team;
            if (team == query_800fc6dc(self->index)->team)
                post_8016239c(int_message_800a82f0(alloc_801613f0(heap_804b1754, 12), msg_id_8015f5a0(&cacheB_804afd10, 1), -dmg));
            else
                post_8016239c(int_message_800a82f0(alloc_801613f0(heap_804b1754, 12), msg_id_8015f5a0(&cacheB_804afd10, 1), dmg));
        }
        it->hp = hp - (unsigned short)dmg;
        if (dmg > 0 && (self->moving || self->flags < 0)) set_state_801492ec(self, 11);
    }
    it->pending = 0;
    update_80178c54(get_803426b4(self->barA), &dmg);
    set_vector_80178fa4(get_80342fa4(self->barB), &it->v);
    Plain *m = (Plain *)alloc_801613f0(heap_804b1754, 8);
    m->id = msg_id_8015f5a0(&cacheC_804afba0, 1);
    m->vt = vt_8040db38;
    post_8016239c(m);
    Plain *n = (Plain *)alloc_801613f0(heap_804b1754, 8);
    n->id = msg_id_8015f5a0(&cacheD_804afd78, 1);
    n->vt = vt_8040db38;
    pool_add_800c53a0(n, engine_80165254()->now + 2500);
    if (self->type()->is_a(type_80361860) || self->type()->is_a(type_803618f0)) log_80022e20("Worm Taking Damage", logic_entity_803a0e2c, 2655, &self->slotB);
    check_801506f8(self);
}

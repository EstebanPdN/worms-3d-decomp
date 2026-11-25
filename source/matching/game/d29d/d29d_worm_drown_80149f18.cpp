// GWMP8P rev0 0x80149f18. Worm drowning check: once below the water level by the
// drown height the worm loses all hit points, plays the splash, is given a new
// state and a replacement active worm is chosen. Names are inferred from use and
// the log strings; virtual slots are reference-ABI observations.
struct Triple { int a, b, c; };
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
struct Plain { short id; void *vt; };
struct Handle { int value; unsigned key; Handle(int v) { value = v; key = 58280; } ~Handle(); };
struct Item { char u0[80]; Vec v80; char u5c[36]; int f128; char u84[32]; int f164; char ua8[2]; unsigned short hp; char uac[41]; unsigned char team; char ud6[6]; int f220; };
struct Engine { char u0[52]; int now; };
struct Base {
    virtual int query_interface();
    virtual void retain();
    virtual void release();
    virtual TypeDesc *type();
};
struct Worm : Base {
    char u4[556]; Vec f560; char u23c[12]; int f584; char u24c[60]; int f648; char u28c[16]; int f668; char u2a0[4]; Vec f676; Triple f688; char u2bc[60]; int f760; char u2fc[40]; int f804; char u328[316]; void *f1124; char u468[100]; void *f1228; void *f1232;
};
extern "C" {
float value_80178df0(void *);
Item *item_800fc710(int, const Handle &);
void *alloc_801613f0(void *, int);
short message_id_8015f5a0(int *, int);
void *int_message_800a82f0(void *, unsigned short, int);
int post_8016239c(void *);
int owner_8014c488(Worm *);
void clear_links_8014df84(Worm *, int);
int falling_8014fcac(Worm *);
void set_state_801492ec(Worm *, int);
Engine *engine_80165254();
int log_80022e20(const char *, const char *, int, int *);
int splash_800e5ca4(Vec *, const char *, int, float);
void *get_803426b4(void *);
int active_80178c48(void *);
int get_80158dc4(void *);
void set_80158dcc(void *, int);
Item *query_800fc6dc(int);
float sqrt_802e82c0(float);
}
extern void *heap_804b1754;
extern unsigned char vt_8040db38[];
extern Triple triple_8045e788[];
extern int cache_804afb60;
extern int cache_804afb68;
extern int cache_804afd30;
extern int cache_804afd38;
extern int cache_804afc58;
extern void *turns_804ab400;
extern const char str_803a1308[];
extern const char str_803a131c[];
extern const char str_803a1328[];
extern const char str_803a0e2c[];
inline void splash(Worm *self, const Vec &o) {
    float a = o.x, b = o.y, c = o.z;
    Vec v;
    v.x = a; v.y = b; v.z = c;
    float k = value_80178df0(self->f1232);
    int n = (int)(k * 16.0f);
    v.y = (float)(n | 1) * 0.0625f;
    splash_800e5ca4(&v, str_803a131c, 0, 0.0f);
}
inline void post_plain(int *cache) {
    Plain *p = (Plain *)alloc_801613f0(heap_804b1754, 8);
    p->id = message_id_8015f5a0(cache, 1);
    p->vt = vt_8040db38;
    post_8016239c(p);
}
extern "C" void d29d_worm_drown_80149f18(Worm *self) {
    if (self->f648 && (self->f760 == 19 || self->f760 == 27)) return;
    float level = value_80178df0(self->f1232);
    level -= value_80178df0(self->f1228);
    if (!(self->f560.y < level)) return;
    Handle h(0);
    Item *it = item_800fc710(self->f584, h);
    it->hp = 0;
    int *dead = &self->f648;
    *dead = 1;
    {
        void *m = alloc_801613f0(heap_804b1754, 12);
        post_8016239c(int_message_800a82f0(m, message_id_8015f5a0(&cache_804afb60, 1), self->f584));
    }
    if (owner_8014c488(self)) clear_links_8014df84(self, 1);
    if (!falling_8014fcac(self)) {
        self->f760 = 27;
        set_state_801492ec(self, 33);
        *(Triple *)&self->f676 = *triple_8045e788;
        self->f668 = engine_80165254()->now + 4000;
        if (self->type()->is_a(type_80361860) || self->type()->is_a(type_803618f0)) log_80022e20(str_803a1308, str_803a0e2c, 3025, &self->f804);
    } else {
        self->f760 = 19;
        set_state_801492ec(self, 13);
        self->f668 = engine_80165254()->now + 1000;
        splash(self, self->f560);
        if (self->type()->is_a(type_80361860) || self->type()->is_a(type_803618f0)) log_80022e20(str_803a1328, str_803a0e2c, 3034, &self->f804);
    }
    if (owner_8014c488(self)) post_plain(&cache_804afb68);
    self->f688 = *triple_8045e788;
    self->f676.x *= 0.4f;
    self->f676.z *= 0.4f;
    self->f676.y *= 0.6f;
    int active = active_80178c48(get_803426b4(self->f1124));
    if ((unsigned)active > 15) return;
    if (get_80158dc4(turns_804ab400)) {
        set_80158dcc(turns_804ab400, 0);
        if (!owner_8014c488(self)) {
            void *m = alloc_801613f0(heap_804b1754, 12);
            post_8016239c(int_message_800a82f0(m, message_id_8015f5a0(&cache_804afd30, 1), active));
        }
        goto tail;
    }
    {
    int team = it->team;
    float best = 1000000.0f;
    int found = -1;
    if (query_800fc6dc(active)->team != team) {
        post_plain(&cache_804afd38);
        return;
    }
    int i = 0;
    Vec &me = self->f560;
    for (; i <= 15; i++) {
        Item *q = query_800fc6dc(i);
        if (i == self->f584) continue;
        if (q->f220 != 1) continue;
        if (q->team != team) continue;
        int taken = q->f164;
        if (q->hp - taken <= 0) continue;
        int st = q->f128;
        if (st == 20) continue;
        if (st == 19) continue;
        if (st == 27) continue;
        Vec &o = q->v80;
        float dy = o.y - me.y;
        float dx = o.x - self->f560.x;
        float dz = o.z - me.z;
        float d = sqrt_802e82c0(dx * dx + dy * dy + dz * dz);
        if (d < best) { best = d; found = i; }
    }
    if (found != -1) {
        void *m = alloc_801613f0(heap_804b1754, 12);
        post_8016239c(int_message_800a82f0(m, message_id_8015f5a0(&cache_804afc58, 1), found));
    }
    }
tail:
    ;
}

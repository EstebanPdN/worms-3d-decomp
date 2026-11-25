// GWMP8P rev0 0x8029d0ec. Front-end game start check: for a local game reads
// the initial game data, counts distinct teams by four slots across up to
// four team records, sets the start tip text and writes FE.CanGameStart and
// FE.CanWeAddTeam. Property roles come from the original strings; team
// record fields are a partial view. The dead values set in the switch are
// overwritten by the total, so only their compares survive; the stored
// values are placeholders.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *);
struct Str {
    char *p;
    Str(const Str &);
    ~Str() { fn_8020c5c4(this); fn_80341588(this); }
    unsigned short len() const { return *(unsigned short *)(p - 4); }
};
struct Res;
struct ResVt { char u0[16]; void (*destroy)(Res *); };
struct Res { ResVt *vt; };
struct Held {
    Res *r;
    Held() : r(0) {}
    Held(const Held &);
    ~Held() { if (r) r->vt->destroy(r); }
};
struct Key { const char *p; };
struct Teams {
    char u0[28]; int f28;
    char u32[24]; int n56;
    char u60[32]; unsigned count;
    char u96[12]; int f108;
    char u112[24]; int n136;
    char u140[12]; int i152;
    char u156[24]; int f180;
    char u184[24]; int n208;
    char u212[12]; int i224, i228;
    char u232[4]; int i236;
    char u240[16]; int f256;
};
struct State { char u0[3168]; int ready; bool isReady() const { return ready != 0; } };
struct Game { char u0[68]; State *state; };
extern "C" int fn_800fc43c(const Key *, int);
extern "C" int fn_800fc2b0(const Key *, const char **);
extern "C" int fn_800fc230(const Key *, int *);
extern "C" int fn_800fc1b0(const Key *, Held *);
extern "C" int fn_800fc550(const Key *, const char *);
extern "C" Res *fn_80341584(Res *);
extern "C" Teams *fn_801797b4(Res *);
extern "C" int strcmp(const char *, const char *);
extern "C" void *memset(void *, int, ...);
extern Game *game_804abb7c;
extern const char canStart_803d0ce0[], tipStart_803d0cf0[], local_803d0d04[], init_803d0bf0[], tipPlease_803d0d10[], finished_803d0d20[], tipGen_803d0d30[], text_803d0d44[], canAdd_803d0d54[];
extern "C" void d29l_game_start_state_8029d0ec(void *self, Str type) {
    if (!type.len()) {
        Key k; k.p = canStart_803d0ce0;
        fn_800fc43c(&k, 0);
        return;
    }
    const char *tip;
    { Key k; k.p = tipStart_803d0cf0; fn_800fc2b0(&k, &tip); }
    int can = 0, add = 0;
    if (!strcmp(local_803d0d04, type.p)) {
        Held h;
        Key k; k.p = init_803d0bf0;
        if (fn_800fc1b0(&k, &h) < 0) {
            Key k2; k2.p = canStart_803d0ce0;
            fn_800fc43c(&k2, 0);
            return;
        }
        unsigned sum = 0;
        Teams *t = fn_801797b4(fn_80341584(h.r));
        if (t->count > 1) {
            int on[4];
            int *fl = on;
            memset(fl, 0, 16);
            int d;
            switch (t->count) {
            case 4:
                fl[t->i236] = 1;
                add = 1;
                if (t->f256) d = t->i152; else d = t->i224;
            case 3:
                fl[t->i228] = 1;
                sum += t->n208; if (t->f180) d = t->i152; else d = t->i224;
            case 2:
                fl[t->i224] = 1;
                sum += t->n136; if (t->f108) d = t->i152; else d = t->i224;
            case 1:
                fl[t->i152] = 1;
                sum += t->n56; if (t->f28) d = t->i152; else d = t->i224;
            }
            d = on[0] + on[1] + on[2] + on[3];
            if ((unsigned)d > 1) can = 1;
        }
        if (!can) {
            Key k3; k3.p = tipPlease_803d0d10;
            fn_800fc2b0(&k3, &tip);
        } else {
            can = 0;
            Game *g = game_804abb7c;
            if (g && g->state && !g->state->isReady()) can = 1;
            int done = 0;
            Key k4; k4.p = finished_803d0d20;
            fn_800fc230(&k4, &done);
            if (!done) can = 0;
            if (!can) {
                Key k5; k5.p = tipGen_803d0d30;
                fn_800fc2b0(&k5, &tip);
            }
        }
        if (sum > 15) add = 1;
    }
    { Key k; k.p = text_803d0d44; fn_800fc550(&k, tip); }
    { Key k; k.p = canStart_803d0ce0; fn_800fc43c(&k, can); }
    { Key k; k.p = canAdd_803d0d54; fn_800fc43c(&k, add); }
}

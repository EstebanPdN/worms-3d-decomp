// GWMP8P rev0 0x802b0b84. Panel base setup: stores the owner and font,
// subscribes thirteen cached messages, resolves the tooltip and highlight
// colours, sets up frame nodes and resources, then evaluates the optional
// enable switch named by the config (a leading ! inverts it; literal false
// disables; otherwise a game-data value of type int, native or string).
// Field names are inferred.
extern "C" void fn_8020c5c0(void *), fn_8020c5c4(void *), fn_80341588(void *);
struct Header { unsigned short refs, length, capacity; };
extern "C" Header *fn_80341884(void *);
struct Str {
    char *p;
    Str(const Str &o) {
        Str *t = this;
        fn_8020c5c0(t);
        p = o.p;
        Header *h = fn_80341884(t);
        ++h->refs;
    }
    ~Str() { Str *t = this; fn_8020c5c4(t); fn_80341588(t); }
    unsigned length() const { return *(unsigned short *)(p - 4); }
};
struct Key { const char *name; Key(const char *n) : name(n) {} };
struct Msg { char u[8]; };
struct Res;
struct ResVt { char u0[24]; int (*type)(Res *); };
struct Res { ResVt *vt; };
struct Ent { char u[16]; int w16; };
struct Panel;
struct PanelVt { char u[68]; void (*enable)(Panel *, int); };
struct Cfg { char u0[60]; Str s60; };
struct Panel {
    char u0[4];
    int font;
    int w8;
    Cfg *cfg;
    Ent *e[7];
    Ent *e44, *e48, *e52, *e56, *e60, *e64;
    Res *tip, *hi, *val;
    Str err;
    char u84[40];
    int w124;
    char u128[40];
    int w168;
    char u172[8];
    PanelVt *vt;
};
extern int font_804abb60;
extern Msg msg_804b0f80, msg_804b0f88, msg_804b0f90, msg_804b0f98, msg_804b0fa0, msg_804b0fa8, msg_804b0fb0, msg_804b0fc8, msg_804b0fd8, msg_804b0fe0, msg_804b0fe8, msg_804b0fd0, msg_804b0ff0;
extern char str_803d79c8[], str_803d79d4[], str_803d79e8[], str_803d79f0[];
extern "C" {
int fn_8015f5a0(Msg *, int);
int fn_80162024(void *, const unsigned short &, Ent **);
int fn_800fc1b0(const Key &, Res **);
int fn_800fd62c(Str *, void (*)(void *, void *), Panel *, int *);
int fn_802b2374(void *, void *);
void fn_802b192c(Panel *);
void fn_802b1d98(Panel *);
Str *fn_8020bd38(Str *, const char *);
int strcmp(const char *, const char *);
void fn_8020c510(void *, const char *, ...);
void *fn_803426b4(Res *);
int fn_80178c48(void *);
void *fn_80342a78(Res *);
int fn_80178d1c(void *);
void *fn_80343744(Res *);
Str *fn_80179170(void *);
}
extern "C" void d31l_panel_init_802b0b84(Panel *self, void *o, int d) {
    self->w168 = d;
    self->font = font_804abb60;
    fn_80162024(o, fn_8015f5a0(&msg_804b0f80, 1), &self->e[0]);
    fn_80162024(o, fn_8015f5a0(&msg_804b0f88, 1), &self->e[1]);
    fn_80162024(o, fn_8015f5a0(&msg_804b0f90, 1), &self->e[2]);
    fn_80162024(o, fn_8015f5a0(&msg_804b0f98, 1), &self->e[3]);
    fn_80162024(o, fn_8015f5a0(&msg_804b0fa0, 1), &self->e[4]);
    fn_80162024(o, fn_8015f5a0(&msg_804b0fa8, 1), &self->e[5]);
    fn_80162024(o, fn_8015f5a0(&msg_804b0fb0, 1), &self->e[6]);
    fn_80162024(o, fn_8015f5a0(&msg_804b0fc8, 1), &self->e44);
    fn_80162024(o, fn_8015f5a0(&msg_804b0fd8, 1), &self->e56);
    fn_80162024(o, fn_8015f5a0(&msg_804b0fe0, 1), &self->e60);
    fn_80162024(o, fn_8015f5a0(&msg_804b0fe8, 1), &self->e52);
    fn_80162024(o, fn_8015f5a0(&msg_804b0fd0, 1), &self->e48);
    fn_80162024(o, fn_8015f5a0(&msg_804b0ff0, 1), &self->e64);
    self->e[0]->w16 = 0;
    self->e[1]->w16 = 0;
    self->e[2]->w16 = 0;
    self->e[3]->w16 = 0;
    self->e[4]->w16 = 0;
    self->e[5]->w16 = 0;
    self->e[6]->w16 = 0;
    fn_800fc1b0(Key(str_803d79c8), &self->tip);
    fn_800fc1b0(Key(str_803d79d4), &self->hi);
    fn_802b192c(self);
    fn_802b1d98(self);
    Cfg *c = self->cfg;
    if (c->s60.length()) {
        Str s(c->s60);
        Str *ps = &s;
        if (*s.p == '!') {
            self->w124 = 1;
            fn_8020bd38(ps, s.p + 1);
        }
        if (s.length()) {
            if (strcmp(s.p, str_803d79e8) == 0)
                self->vt->enable(self, 0);
            else if (fn_800fc1b0(Key(s.p), &self->val) >= 0) {
                fn_800fd62c(ps, (void (*)(void *, void *))fn_802b2374, self, &self->w8);
                switch (self->val->vt->type(self->val)) {
                case 0:
                    self->vt->enable(self, fn_80178c48(fn_803426b4(self->val)) != 0);
                    break;
                case 1:
                    self->vt->enable(self, fn_80178d1c(fn_80342a78(self->val)) != 0);
                    break;
                case 4: {
                    Str t(*fn_80179170(fn_80343744(self->val)));
                    if (t.length() == 0 || *t.p == ' ')
                        self->vt->enable(self, 0);
                    else
                        self->vt->enable(self, 1);
                    break;
                }
                }
            } else
                fn_8020c510(&self->err, str_803d79f0, self->cfg->s60.p);
        }
    }
}

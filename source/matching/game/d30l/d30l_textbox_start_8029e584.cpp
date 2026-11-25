// GWMP8P rev0 0x8029e584. Textbox start: sets up the sub-panel and null
// node, loads FE.Textbox.Back, reads the border, background, shadow and
// scroll properties, takes the initial alpha from the background colour, and
// resolves the optional game data item whose string becomes the text
// (FE.ToolTip marks a tooltip). Strings and literals are from the original;
// field names are inferred.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *);
extern "C" void *fn_803426b8(void *);
struct Str {
    char *p;
    Str() { fn_803426b8(this); }
    Str(const char *);
    Str(const Str &);
    ~Str() { fn_8020c5c4(this); fn_80341588(this); }
    unsigned length() const { return *(unsigned short *)(p - 4); }
};
struct Vec {
    float x, y, z;
    Vec() {}
};
struct Res;
struct ResVt { char u0[12]; void (*acquire)(Res *); void (*destroy)(Res *); char u20[56]; int (*pos)(Res *, const Vec &, int); int (*rot)(Res *, const Vec &, int); int (*scale)(Res *, const Vec &, int); char u88[4]; void (*add)(Res *, Res *, int); };
struct Res { ResVt *vt; };
struct Ref {
    Res *p;
    void operator=(Res *q) {
        if (q) q->vt->acquire(q);
        if (p) p->vt->destroy(p);
        p = q;
    }
};
struct Held {
    Res *r;
    Held() : r(0) {}
    Held(const Held &);
    ~Held() { if (r) r->vt->destroy(r); }
};
struct Key { const char *name; Key(const char *n) : name(n) {} };
struct Colour { unsigned char r, g, b, a; };
struct Cfg { char u0[120]; float f120; char u124[4]; int w128; char u132[4]; Str s136; };
struct Ctx { char u[52]; int a52; };
struct Panel;
struct PanelVt { char u[44]; void (*text)(Panel *, char *); };
struct Panel {
    PanelVt *vt;
    char u4[24];
    char sub[7];
    unsigned char font;
    char u36[4];
    Cfg *cfg;
    char u44[68];
    Res *group;
    char u116[60];
    int w176;
    char u180[32];
    int w212, w216;
    Ref back;
    char u224[36];
    int s260;
    char u264[8];
    int w272;
    char u276[4];
    float f280, f284;
    char u288[20];
    Res *node;
    Res *game;
    float f316;
    Ref shadow, minh, enc, bg;
};
extern "C" {
Ctx *fn_80165254();
void fn_802b0b84(char *, Panel *, int);
int fn_8015adf4(const Str &, Res **, int);
Res *fn_8034357c(Res *);
int fn_800fc1b0(const Key &, Res **);
Res *fn_80342a74(Res *), *fn_80343df4(Res *), *fn_80343744(Res *);
float fn_80178df0(Res *);
Colour *fn_80178f54(Res *);
void fn_8029fc78(Panel *);
int fn_800fd62c(const Str &, void (*)(), Panel *, int *);
int fn_8029fb54(void *, void *);
int strcmp(const char *, const char *);
Str *fn_80179170(Res *);
int fn_801fe45c();
}
inline void load(Ref &d, const Str &n, unsigned char t) {
    Held h;
    fn_8015adf4(n, &h.r, t);
    d = fn_8034357c(h.r);
}
extern "C" void d30l_textbox_start_8029e584(Panel *self) {
    fn_802b0b84(self->sub, self, fn_80165254()->a52);
    fn_8015adf4(Str("NULL"), &self->node, 255);
    Vec v;
    Vec *pv = &v;
    float z = 0.0f;
    v.x = z; pv->y = z; pv->z = z;
    self->node->vt->pos(self->node, *pv, 0);
    self->node->vt->rot(self->node, *pv, 0);
    v.x = 1.0f; pv->y = 1.0f; pv->z = 1.0f;
    self->node->vt->scale(self->node, *pv, 0);
    self->group->vt->add(self->group, self->node, 0);
    Held a;
    Str s;
    Cfg *c = self->cfg;
    load(self->back, Str("FE.Textbox.Back"), (unsigned char)(self->font + 29));
    self->group->vt->add(self->group, self->back.p, 0);
    Held h;
    fn_800fc1b0(Key("FE.BorderThickness"), &h.r);
    self->f316 = fn_80178df0(fn_80342a74(h.r));
    if (c->f120 != z) self->f316 = c->f120;
    if (!c->w128) self->f316 = z;
    fn_800fc1b0(Key("FE.TextBoxBackground"), &h.r);
    self->bg = fn_80343df4(h.r);
    fn_800fc1b0(Key("FE.ShadowOffset"), &h.r);
    self->shadow = fn_80342a74(h.r);
    fn_800fc1b0(Key("FE.MinScrollButtonHeight"), &h.r);
    self->minh = fn_80342a74(h.r);
    fn_800fc1b0(Key("FE.ScrollBorderEncroachment"), &h.r);
    self->enc = fn_80342a74(h.r);
    self->w176 = 0;
    Str &t = c->s136;
    Colour col = *fn_80178f54(self->bg.p);
    self->f284 = self->f280 = (float)col.a;
    fn_8029fc78(self);
    if (t.length()) {
        if (fn_800fc1b0(Key(t.p), &self->game) >= 0) {
            fn_800fd62c(t, (void (*)())fn_8029fb54, self, &self->s260);
            if (!strcmp(c->s136.p, "FE.ToolTip")) self->w216 = 1;
            Str *n = fn_80179170(fn_80343744(self->game));
            self->vt->text(self, n->p);
        }
    }
    self->w272 = 1;
    self->w212 = fn_801fe45c();
}

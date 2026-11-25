// GWMP8P rev0 0x8029fc78. Builds a framed panel from its configuration:
// loads the two named border sprites, attaches them, sizes and positions
// them against the panel's measured extent, builds the child boxes and
// scroll parts on demand, sets their visibility by the panel's current mode
// and marks it ready.
extern "C" void fn_8020c5c0(void *), fn_8020c5c4(void *), fn_80341588(void *), fn_8020bb2c(void *);
struct Header { unsigned short refs, length, capacity; };
extern "C" Header *fn_80341884(void *);
extern "C" void fn_803426b8(void *);
struct Str {
    char *p;
    Str();
    Str(const char *);
    Str(const Str &o) {
        fn_8020c5c0(this);
        p = o.p;
        Header *h = fn_80341884(this);
        ++h->refs;
    }
    ~Str() { Str *t = this; fn_8020c5c4(t); fn_80341588(t); }
    unsigned length() const { return *(unsigned short *)(p - 4); }
};
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Colour { signed char r, g, b, a; };
struct Res;
struct ResVt { char u0[12]; void (*acquire)(Res *); void (*destroy)(Res *); char u20[56]; int (*pos)(Res *, const Vec &, int); char u80[4]; int (*scale)(Res *, const Vec &, int); int (*vis)(Res *, int); void (*add)(Res *, Res *, int); };
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
struct Cfg { char u0[20]; Vec size; char u32[28]; Str s60; char u64[64]; int w128; };
struct Mesh; struct Scroll;
struct Item {
    char u0[35];
    unsigned char font;
    char u36[4];
    Cfg *cfg;
    char u44[68];
    Res *node;
    char u116[24];
    bool w140;
    char u144[32];
    int w176;
    char u180[36];
    int w216;
    Res *w220;
    Ref a[2];
    Mesh *b[3];
    Scroll *s[3];
    char u256[20];
    int w276;
    char u280[36];
    float f316;
    void *w320;
    char u324[8];
    void *w332;
    char u336[40];
    int w376;
};
extern Vec table_8045e788;
extern char str_803d1de4[], str_803d1df8[], str_803d1e0c[], str_803d1e1c[], str_803d1e34[];
extern "C" {
void fn_8020bd38(void *, const char *);
void *fn_801fe1d8(unsigned);
int fn_8015adf4(const Str &, Held *, unsigned char);
Res *fn_8034357c(Res *);
int fn_80173df0(Res *, const Colour *);
int fn_80173f88(Res *, const unsigned char &);
float fn_80178df0(void *);
Colour *fn_80178f54(void *);
char *fn_80263bb8(int);
char *fn_80263c24(int);
char *fn_80263c90(int);
int fn_80263608(Str, int);
void fn_802a0e20(Item *, int, int);
Mesh *fn_8025dffc(void *, const char *, unsigned char);
void fn_8025e128(Mesh *, float, float, float);
void fn_8025ee60(Mesh *, const Vec &);
void fn_8025ee94(Mesh *, Res *);
void fn_8025f064(Mesh *, int);
Scroll *fn_80293460(void *, const char *, unsigned char);
void fn_8029358c(Scroll *, float, float, float, float);
void fn_80294398(Scroll *, const Vec &);
void fn_802943cc(Scroll *, Res *);
void fn_8029459c(Scroll *, int);
}
inline void load(Ref &d, const Str &n, unsigned char t) {
    Held h;
    Held *ph = &h;
    fn_8015adf4(n, ph, t);
    d = fn_8034357c(h.r);
}
inline void Put(Vec &d, const Vec &o) { d = o; }
inline const float &mx(const float &a, const float &b) { return a < b ? b : a; }
extern "C" void d44l_bordered_panel_build_8029fc78(Item *self) {
    Str name;
    Cfg *c = self->cfg;
    if (c->w128 == 0 || c->w128 == 3) {
        self->a[0] = 0;
        self->a[1] = 0;
        self->w216 = 1;
        fn_802a0e20(self, 1, 1);
        if (c->w128 == 0)
            self->w220->vt->vis(self->w220, 0);
        else {
            Colour col = *fn_80178f54(self->w332);
            self->w220->vt->scale(self->w220, c->size, 0);
            fn_80173df0(self->w220, &col);
        }
        return;
    }
    float k = self->f316;
        Mesh **bx = self->b;
    Scroll **sx = self->s;
    float tall = k * fn_80178df0(self->w320);
    float bar = k * 0.5f;
    if (!self->w276) {
        fn_8020bd38(&name, fn_80263bb8(c->w128));
        Str s1(str_803d1de4);
        fn_80263608(name, 0);
        fn_80263608(s1, 0);
        load(self->a[0], name, (unsigned char)(self->font + 31));
        load(self->a[1], s1, (unsigned char)(self->font + 31));
        for (unsigned i = 0; i < 2; i++) {
            int gp = (i << 2) + (int)self; gp += 224;
            Ref *p = (Ref *)gp;
            fn_80173f88(p->p, 65);
            self->node->vt->add(self->node, p->p, 0);
        }
        Vec v(table_8045e788);
        Cfg *cc = self->cfg;
        Vec &sz = cc->size;
        Vec e(sz);
        e.x = mx(k, e.x);
        e.y = mx(k, e.y);
        Put(sz, e);
        Vec sc(self->cfg->size.x - bar, bar, 1.0f);
        Vec pos(v.x, v.y + e.y - k - bar + tall, v.z);
        for (int j = 0; j < 2; j++) {
            int gp = (j << 2) + (int)self; gp += 224;
            Ref *p = (Ref *)gp;
            p->p->vt->pos(p->p, pos, 0);
            p->p->vt->scale(p->p, sc, 0);
        }
        Colour col = *fn_80178f54(self->w332);
        e.x -= bar;
        e.y -= bar;
        self->w220->vt->scale(self->w220, e, 0);
        fn_80173df0(self->w220, &col);
    }
    if (!self->w376) {
        if (self->s[0]) fn_802a0e20(self, 0, 1);
        if (!self->b[0]) {
            self->b[0] = fn_8025dffc(fn_801fe1d8(4), fn_80263c24(c->w128), (unsigned char)(self->font + 32));
            self->b[1] = fn_8025dffc(fn_801fe1d8(4), str_803d1df8, (unsigned char)(self->font + 32));
            if (c->s60.length())
                self->b[2] = fn_8025dffc(fn_801fe1d8(4), str_803d1e0c, (unsigned char)(self->font + 32));
            Vec o(table_8045e788);
            for (unsigned i = 0; i <= 2; i++) {
                if (bx[i]) {
                    Vec &cs = c->size;
                    fn_8025e128(bx[i], k, cs.x, cs.y);
                    fn_8025ee60(bx[i], o);
                    fn_8025ee94(bx[i], self->node);
                }
            }
        }
    } else {
        if (self->b[0]) fn_802a0e20(self, 1, 0);
        if (!self->s[0]) {
            self->s[0] = fn_80293460(fn_801fe1d8(4), fn_80263c90(c->w128), (unsigned char)(self->font + 32));
            self->s[1] = fn_80293460(fn_801fe1d8(4), str_803d1e1c, (unsigned char)(self->font + 32));
            if (c->s60.length())
                self->s[2] = fn_80293460(fn_801fe1d8(4), str_803d1e34, (unsigned char)(self->font + 32));
            Vec o(table_8045e788);
            for (unsigned i = 0; i <= 2; i++) {
                if (sx[i]) {
                    Vec &cs = c->size;
                    fn_8029358c(sx[i], k, cs.x, cs.y, k * 0.25f);
                    fn_80294398(sx[i], o);
                    fn_802943cc(sx[i], self->node);
                }
            }
        }
    }
    int on = 0;
    if (self->w176) on = 1;
    for (unsigned i = 0; i <= 1; i++) {
        int v = on == i;
        int gp = (i << 2) + (int)self; gp += 224;
        Ref *p = (Ref *)gp;
        p->p->vt->vis(p->p, v);
        if (bx[i]) fn_8025f064(bx[i], v);
        if (sx[i]) fn_8029459c(sx[i], v);
    }
    if (self->b[2]) fn_8025f064(self->b[2], !self->w140);
    if (self->s[2]) fn_8029459c(self->s[2], !self->w140);
    self->w276 = 1;
}

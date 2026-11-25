// GWMP8P rev0 0x8015d2f4. Debug text setup: creates the text mesh and material,
// loads the font texture, and fills one quad size and one uv pair for every
// 16x16 cell of the font. Names are inferred; virtual slots are table views.
#pragma interface
extern "C" void string_finish_8020c5c4(void *);
extern "C" void string_release_80341588(void *);
extern "C" void string_release_header_8020bb2c(void *);
struct String {
    char *text;
    String(const char *);
    String(const String &);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
    void operator=(const String &o) {
        ++*(unsigned short *)(o.text - 6);
        unsigned short *header = (unsigned short *)(text - 6);
        if (--*header == 0) string_release_header_8020bb2c(header);
        text = o.text;
    }
};
struct Item { virtual void s2(); virtual void retain(); virtual void release(); virtual void s5(); virtual void attach(Item *); };
struct Ref {
    Item *p;
    void operator=(Item *e) { if (e) e->retain(); if (p) p->release(); p = e; }
    void put(Item *e) { Item *old = p; p = e; if (e) e->retain(); if (old) old->release(); }
};
struct Loader;
struct Local {
    inline int load(Loader *l, const char *file);
    Item *p;
    Local() { p = 0; }
    Local(Item *e) { p = e; if (e) e->retain(); }
    Local(const Local &);
    ~Local() { if (p) p->release(); }
};
struct Flags { char u[7]; unsigned char v; };
struct Hdr { char u0[4]; unsigned short kind; char u6[18]; int count; unsigned short refs; char u30[2]; };
struct Field;
extern "C" void *lock_801ef048(Field *, int, int, int);
struct Field {
    Hdr *h;
    void *lock(int n) {
        Hdr *p = h;
        if (p->kind == 1 && n == p->count) { p->refs++; return p + 1; }
        return lock_801ef048(this, n, 8, 1);
    }
};
struct Vec2 { float x, y; float Y() const { return y; } void SetY(float v) { y = v; } };
struct Mesh : Item { char u4[32]; Field sizes; Field uvs; };
struct Texture : Item { char u4[40]; unsigned short w; unsigned short h; int u48; };
struct TexProp : Item { char u4[52]; int f56; Ref tex; char u64[16]; int f80; };
struct Text : Item { char u4[32]; String name; char u40[8]; Ref mat; Ref mesh; };
struct P1 { char u0[4]; Flags flags; char u12[20]; int f32; int f36; };
struct P2 { char u0[4]; Flags flags; char u12[40]; int f52; };
struct P3 { char u0[4]; Flags flags; char u12[12]; float f24; int f28; int f32; };
struct P4 { char u0[4]; Flags flags; char u12[12]; int f24; int f28; };
struct P5 { char u0[4]; Flags flags; char u12[12]; int f24; };
struct Loader { virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual int load(const char *, Local *); };
inline int Local::load(Loader *l, const char *file) { return l->load(file, this); }
struct Service {
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual Loader *find(void *);
};
extern "C" void *forward_8020b680(void *);
extern "C" Service *service_8020b648();
extern "C" void * count_801d0858(Mesh *, int *);
extern "C" void add_801d086c(Mesh *, TexProp *);
extern "C" void add_801d0898(Mesh *, TexProp *, int);
extern "C" void append_801ef174(Mesh *, int, int, void *);
extern unsigned char d_80414518[], d_80414610[], d_80415b50[], d_804143e0[], d_80415d60[], d_80415c10[], d_80415c80[], d_80415bb0[], d_80415cb0[], d_80415c30[], d_804166b0[], d_80414260[];
struct Self { char u0[16]; Ref text; Ref mat; };
inline Loader *find(void *d) { return service_8020b648()->find(d); }
extern "C" void w3d_d32d_debug_text_setup_8015d2f4(Self *self, const char *file) {
    self->text = (Item *)forward_8020b680(d_80414518);
    self->mat = (Item *)forward_8020b680(d_80414610);
    Mesh *m = (Mesh *)forward_8020b680(d_80415b50);
    Loader *l = find(d_804143e0);
    Local tex;
    if (tex.load(l, file) < 0) return;
    TexProp *tp = (TexProp *)forward_8020b680(d_80415d60);
    tp->tex.put(tex.p);
    tp->f56 = 1;
    tp->f80 = 1;
    int n;
    count_801d0858(m, &n);
    if (n) add_801d0898(m, tp, 0);
    else add_801d086c(m, tp);
    {
        P1 *p = (P1 *)forward_8020b680(d_80415c10);
        Flags *f = &p->flags;
        p->f32 = 1;
        f->v |= 2;
        p->f36 = 1;
        f->v |= 3;
        append_801ef174(m, 28, 3, p);
    }
    {
        P2 *p = (P2 *)forward_8020b680(d_80415c80);
        Flags *f = &p->flags;
        p->f52 = 0;
        f->v |= 3;
        append_801ef174(m, 28, 3, p);
    }
    {
        P3 *p = (P3 *)forward_8020b680(d_80415bb0);
        Flags *f = &p->flags;
        p->f28 = 4;
        f->v |= 2;
        p->f24 = 0.05f;
        f->v |= 2;
        p->f32 = 1;
        f->v |= 3;
        append_801ef174(m, 28, 3, p);
    }
    {
        P4 *p = (P4 *)forward_8020b680(d_80415cb0);
        Flags *f = &p->flags;
        p->f28 = 6;
        f->v |= 2;
        p->f24 = 7;
        f->v |= 2;
        append_801ef174(m, 28, 3, p);
    }
    {
        P5 *p = (P5 *)forward_8020b680(d_80415c30);
        Flags *f = &p->flags;
        p->f24 = 0;
        f->v |= 3;
        append_801ef174(m, 28, 3, p);
    }
    Texture *t = (Texture *)tex.p;
    Vec2 c;
    c.x = 16.0f / (float)(int)t->h;
    c.SetY(16.0f / (float)(int)t->w);
    int cells = (((Texture *)tex.p)->h >> 4) * (((Texture *)tex.p)->w >> 4);
    int i = 0;
    Vec2 *uv = (Vec2 *)m->uvs.lock(cells);
    Vec2 *size = (Vec2 *)m->sizes.lock(cells);
    for (float v = 1.0f - c.Y(); v >= 0.0f; v -= c.Y()) {
        for (float u = 0.0f; u <= 1.0f - c.x; u += c.x) {
            size[i] = c;
            uv[i].x = u;
            uv[i].y = v;
            i++;
        }
    }
    {
        Text *o = (Text *)self->text.p;
        o->name = String("Debug Text");
    }
    ((Text *)self->text.p)->mat.put(self->mat.p);
    ((Text *)self->text.p)->mesh.put(m);
    Local a((Item *)forward_8020b680(d_804166b0));
    a.p->attach(self->text.p);
    Local b((Item *)forward_8020b680(d_80414260));
    b.p->attach(self->text.p);
}

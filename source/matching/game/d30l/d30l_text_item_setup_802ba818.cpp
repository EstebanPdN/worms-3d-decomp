// GWMP8P rev0 0x802ba818. Text item setup: removes the old text sprite,
// looks up the optional localised string by name (or wraps it in the two
// marker strings when missing), loads the configured font, scales it, aligns
// it by the six alignment modes, and sets text and colour. Literals and
// string addresses are from the original; field names are inferred.
extern "C" void fn_8020c5c0(void *), fn_8020c5c4(void *), fn_80341588(void *), fn_8020bb2c(void *);
// GWMP8P rev0 0x802ba818. Text item setup: removes the old text sprite,
// looks up the optional localised string by name (or wraps it in the two
// marker strings when missing), loads the configured font, scales it, aligns
// it by the six alignment modes, and sets text and colour. Literals and
// string addresses are from the original; field names are inferred.
extern "C" void * fn_803426b8(void *);
struct Header { unsigned short refs, length, capacity; };
extern "C" Header *fn_80341884(void *);
struct Str {
    char *p;
    Str() { fn_803426b8(this); }
    Str(int) {}
    Str(const char *);
    Str(const Str &o) {
        fn_8020c5c0(this);
        p = o.p;
        Header *h = fn_80341884(this);
        ++h->refs;
    }
    void init(const Str &o) { fn_8020c5c0(this); p = o.p; Header *h = fn_80341884(this); ++h->refs; }
    ~Str() { Str *t = this; fn_8020c5c4(t); fn_80341588(t); }
    unsigned length() const { return *(unsigned short *)(p - 4); }
    Str &operator=(const Str &o) {
        ++((Header *)(o.p - 6))->refs;
        Header *h = (Header *)(p - 6);
        if (--h->refs == 0) fn_8020bb2c(h);
        p = o.p;
        return *this;
    }
};
extern "C" void fn_8020bd38(Str *, const char *);
extern "C" void * fn_8020bf2c(Str *, const char *);
inline Str operator+(const Str &a, const char *b) {
    Str r(a);
    fn_8020bf2c(&r, b);
    return r;
}
inline Str operator+(const Str &a, const Str &b) {
    Str r(0);
    Str *pr = &r;
    pr->init(a);
    fn_8020bf2c(pr, b.p);
    return r;
}
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Colour { signed char r, g, b, a; Colour(unsigned char x, unsigned char y, unsigned char z, unsigned char w) { r = x; g = y; b = z; a = w; } };
struct Key { const char *name; Key(const char *n) : name(n) {} };
struct Res;
struct ResVt { char u0[16]; void (*destroy)(Res *); char u20[56]; int (*pos)(Res *, const Vec &, int); char u80[4]; int (*scale)(Res *, const Vec &, int); char u88[4]; void (*add)(Res *, Res *, int); void (*remove)(Res *, Res *); };
struct Res { ResVt *vt; };
struct Cfg { char u0[20]; Vec pos; char u32[84]; int bias; int align; float off; unsigned char u128[3], b131, u132[3], b135, u136[3], b139; Str s140, s144; };
struct Sub { char u[4]; };
struct Panel {
    char u0[28];
    Sub sub;
    char u32[3];
    unsigned char font;
    char u36[4];
    Cfg *cfg;
    char u44[68];
    Res *group;
    char u116[96];
    Res *text;
};
extern "C" {
int fn_800fc2b0(const Key &, const char **);
int fn_8015adf4(const Str &, Res **, int);
Res *fn_80343580(Res *);
float fn_802b1880(Sub *);
int fn_8018d324(Res *, int);
int fn_8018c5b0(Res *, char *);
int fn_8018d35c(Res *, const Colour *);
}
extern const char s_803d8220[], s_803d8224[];
inline void quote(Str &s) {
    Str t;
    t = Str(s_803d8220) + s + s_803d8224;
    s = t;
}
extern "C" void d30l_text_item_setup_802ba818(Panel *self) {
    Cfg *c = self->cfg;
    if (c->s144.length()) {
        int bias = c->bias;
        if (self->text) {
            self->group->vt->remove(self->group, self->text);
            if (self->text) self->text->vt->destroy(self->text);
            self->text = 0;
        }
        if (c->s140.length()) {
            Str s(c->s140);
            const char *out;
            if (fn_800fc2b0(Key(s.p), &out) >= 0)
                fn_8020bd38(&s, out);
            else {
                Str t(0);
                Str *pt = &t;
                fn_803426b8(pt);
                t = Str(s_803d8220) + s + s_803d8224;
                s = t;
            }
            fn_8015adf4(c->s144, &self->text, (unsigned char)(self->font + (bias + 29)));
            self->group->vt->add(self->group, self->text, 0);
            Res *x = fn_80343580(self->text);
            float w = fn_802b1880(&self->sub);
            Vec v;
            Vec *pv = &v;
            v.x = w; v.y = w; pv->z = 1.0f;
            x->vt->scale(x, *pv, 0);
            Vec p(self->cfg->pos);
            float y = 0.0f;
            float a = y;
            int al = 4;
            float off = c->off;
            switch (c->align) {
            case 0: a = y - p.x + off; y = p.y; break;
            case 1: y = p.y; al = 0; break;
            case 2: a = p.x - off; al = 8; y = p.y; break;
            case 3: a = y - p.x + off; y -= p.y; break;
            case 4: y -= p.y; al = 0; break;
            case 5: a = p.x - off; al = 8; y -= p.y; break;
            }
            fn_8018d324(x, al);
            Vec q(a, y, 0.0f);
            x->vt->pos(x, q, 0);
            fn_8018c5b0(x, s.p);
            Colour col(c->b139, c->b135, c->b131, 255);
            fn_8018d35c(x, &col);
        }
    }
}

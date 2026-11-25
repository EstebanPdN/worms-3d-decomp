#include "w3d_ptr.h"
#line 1 "d31l_panel_refresh_802a520c.cpp"
// GWMP8P rev0 0x802a520c. Panel refresh: looks up the highlight sprites
// named by the config format, then the shade, then the colour and grey
// variants; on first use loads the eight box border parts and the infinity
// sprite, lays them out from the panel size, and finally sets visibility and
// colour from the panel state. Strings and vtable slots come from the
// original; field names are inferred.
extern "C" void fn_8020c5c0(Ptr32<void>), fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020bb2c(Ptr32<void>);
struct Header { unsigned short refs, length, capacity; };
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
extern "C" Ptr32<void> fn_803426b8(Ptr32<void>);
struct Str {
    Ptr32<char> p;
    Str(int) {}
    template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *);
    Str(const Str &o) {
        fn_8020c5c0(this);
        p = o.p;
        Ptr32<Header> h = fn_80341884(this);
        ++h->refs;
    }
    ~Str() { Ptr32<Str> t = this; fn_8020c5c4(t); fn_80341588(t); }
    unsigned length() const { return *(Ptr32<unsigned short>)(p - 4); }
};
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &);
    void set(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Colour {
    signed char r, g, b, a;
    Colour() {}
    void set(signed char x, signed char y, signed char z, signed char w) { r = x; g = y; b = z; a = w; }
};
struct Res;
struct ResVt { char u0[12]; Ptr32<void (Ptr32<Res>)> acquire; Ptr32<void (Ptr32<Res>)> destroy; char u20[56]; Ptr32<int (Ptr32<Res>, const Vec &, int)> pos; char u80[4]; Ptr32<int (Ptr32<Res>, const Vec &, int)> scale; Ptr32<int (Ptr32<Res>, int)> vis; Ptr32<void (Ptr32<Res>, Ptr32<Res>, int)> add; };
struct Res { Ptr32<ResVt> vt; };
struct Ref {
    Ptr32<Res> p;
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Res *)w3d_p.get()); }
 void operator=(Res *q) {
        if (q) q->vt->acquire(q);
        if (p) p->vt->destroy(p);
        p = q;
    }
};
struct Held {
    Ptr32<Res> r;
    Held() : r(0) {}
    Held(const Held &);
    ~Held() { Ptr32<Held> t = this; if (t->r) t->r->vt->destroy(t->r); }
};
struct Cfg { char u0[20]; Vec size; char u32[92]; int colour; Str fmt; };
struct Pair { Ref a, b; };
struct Panel {
    char u0[28];
    char sub[4];
    unsigned char font; char w3d_tag_rest[3];
    char u36[4];
    Ptr32<Cfg> cfg;
    char u44[64];
    Str err;
    Ptr32<Res> node;
    char u116[24];
    int w140;
    char u144[32];
    int w176;
    char u180[32];
    Ptr32<Res> hl[3];
    Ptr32<Res> inner;
    Ref shade;
    Ref inf;
    char u236[8];
    Ref parts[8];
    char u276[68];
    float f344, f348, f352, f356, f360, f364, f368;
};
extern char str_803d6024[], str_803d6030[], str_803d6054[], str_803d605c[], str_803d6064[], str_803d606c[], str_803d6070[], str_803d60a4[], str_803d60ac[], str_803d60c0[];
extern "C" {
void fn_8020c510(Ptr32<void>, Ptr32<const char>, ...);
void fn_8020bd38(Ptr32<void>, Ptr32<const char>);
int fn_802b1510(Ptr32<char>, Ptr32<const char>, Ptr32<Ptr32<Res>>, unsigned char);
int fn_8015adf4(const Str &, Ptr32<Held>, unsigned char);
Ptr32<Res> fn_8034357c(Ptr32<Res>);
int fn_80173df0(Ptr32<Res>, Ptr32<const Colour>);
int fn_80173f88(Ptr32<Res>, const unsigned char &);
Ptr32<char> fn_80263bb8(int);
int fn_80263608(Str, int);
int fn_802a7998(Ptr32<struct Panel>);
}
inline void load(Ref &d, const Str &n, unsigned char t) {
    Held h;
    Ptr32<Held> ph = &h;
    fn_8015adf4(n, ph, t);
    d = fn_8034357c(h.r);
}
inline int show(Ptr32<Panel> self, const Str &name, Ptr32<Ptr32<Res>> d) {
    return fn_802b1510(self->sub, name.p, d, (unsigned char)(self->font + 31));
}
extern "C" void d31l_panel_refresh_802a520c(Ptr32<Panel> self) {
    Ptr32<Cfg> c = self->cfg;
    Str name(0);
    fn_803426b8((Ptr32<void>)&name);
    Ptr32<Str> pn = &name;
    Vec size;
    Vec pos;
    size = self->cfg->size;
    float w = size.x;
    size.x = size.y;
    Vec scale(size.y * 1.1875f, size.y * 1.1875f, 1.0f);
    float zero = 0.0f;
    float x = zero - w + size.x;
    if (!self->hl[0]) {
    Ptr32<Ptr32<Res>> d1 = &self->hl[1];
    if (!self->hl[1] && c->fmt.length()) {
        fn_8020c510(pn, c->fmt.p, w3d::VA(str_803d6024));
        if (show(self, name, d1) < 0)
            fn_8020c510(&self->err, str_803d6030, w3d::VA(name.p));
        else {
            Ptr32<Res> n = self->node;
            n->vt->add(n, self->hl[1], 0);
            self->hl[1]->vt->scale(self->hl[1], scale, 0);
            Ptr32<Vec> pp = &pos;
            pp->x = x;
            pp->y = zero;
            pp->z = zero;
            self->hl[1]->vt->pos(self->hl[1], pos, 0);
            load(self->shade, *pn, (unsigned char)(self->font + 30));
            self->node->vt->add(self->node, self->shade.p, 0);
            Colour col;
            col.set(0, 0, 0, 70);
            fn_80173df0(self->shade.p, &col);
            self->shade.p->vt->scale(self->shade.p, scale, 0);
            pp->x = scale.x * 0.1f + x;
            pp->y = zero;
            pp->z = zero;
            self->shade.p->vt->pos(self->shade.p, pos, 0);
        }
        if (c->colour) {
            switch (c->colour) {
            case 1: fn_8020c510(&name, c->fmt.p, w3d::VA(str_803d6054)); break;
            case 2: fn_8020c510(&name, c->fmt.p, w3d::VA(str_803d605c)); break;
            case 3: fn_8020c510(&name, c->fmt.p, w3d::VA(str_803d6054)); break;
            case 4: fn_8020c510(&name, c->fmt.p, w3d::VA(str_803d6064)); break;
            case 5: fn_8020c510(&name, c->fmt.p, w3d::VA(str_803d606c)); break;
            default: fn_8020bd38(&name, str_803d6070); break;
            }
            if (show(self, name, &self->hl[0]) < 0)
                fn_8020c510(&self->err, str_803d6030, w3d::VA(name.p));
            else {
                self->node->vt->add(self->node, self->hl[0], 0);
                self->hl[0]->vt->scale(self->hl[0], scale, 0);
                { Ptr32<Vec> q = &pos; q->x = x; q->y = 0.0f; q->z = 0.0f; }
                self->hl[0]->vt->pos(self->hl[0], pos, 0);
            }
            fn_8020c510(&name, c->fmt.p, w3d::VA(str_803d60a4));
            if (show(self, name, &self->hl[2]) < 0)
                fn_8020c510(&self->err, str_803d6030, w3d::VA(name.p));
            else {
                self->node->vt->add(self->node, self->hl[2], 0);
                self->hl[2]->vt->scale(self->hl[2], scale, 0);
                { Ptr32<Vec> q = &pos; q->x = x; q->y = 0.0f; q->z = 0.0f; }
                self->hl[2]->vt->pos(self->hl[2], pos, 0);
            }
        }
    }
    }
    Colour col;
    if (!self->parts[0].p) {
        Str s0(fn_80263bb8(c->colour));
        Str s1(str_803d60ac);
        fn_80263608(s0, 0);
        fn_80263608(s1, 0);
        load(self->parts[0], s0, (unsigned char)(self->font + 29));
        load(self->parts[2], s0, (unsigned char)(self->font + 29));
        load(self->parts[4], s0, (unsigned char)(self->font + 29));
        load(self->parts[6], s0, (unsigned char)(self->font + 29));
        load(self->parts[1], s1, (unsigned char)(self->font + 29));
        load(self->parts[3], s1, (unsigned char)(self->font + 29));
        load(self->parts[5], s1, (unsigned char)(self->font + 29));
        load(self->parts[7], s1, (unsigned char)(self->font + 29));
        load(self->inf, Str(str_803d60c0), (unsigned char)(self->font + 30));
        for (unsigned i = 0; i < 2; i++) {
            Ptr32<Ref> p = &self->parts[i + 6];
            fn_80173f88(p[-6].p, 8);
            fn_80173f88(p[-4].p, 8);
            fn_80173f88(p[-2].p, 10);
            fn_80173f88(p[0].p, 10);
            self->inner->vt->add(self->inner, p[-6].p, 0);
            self->inner->vt->add(self->inner, p[-4].p, 0);
            self->inner->vt->add(self->inner, p[-2].p, 0);
            self->inner->vt->add(self->inner, p[0].p, 0);
        }
        float tot = -x + self->cfg->size.x;
        float a = scale.x * 0.5f;
        float l = (tot - a) * 0.5f;
        float m = (tot + a) * 0.5f;
        float e = (scale.y + scale.y) * 0.1f * 0.5f;
        float g = scale.y * 0.4f;
        float k = e * 0.5f;
        float top = scale.y - g;
        float bot = 0.0f - scale.y + g;
        Vec v0(w - l - e, top, 0.0f);
        Vec v1(w - m - e, bot, 0.0f);
        Vec v2(v0.x + l + k, top, 0.0f);
        float lo = top - e;
        Vec v3(v1.x + m + k, bot, 0.0f);
        Vec s0v(l, e, 1.0f);
        Vec s1v(m, e, 1.0f);
        Vec s2v(k, e, 1.0f);
        self->f352 = self->f356 = v0.x - s0v.x;
        self->f344 = self->f348 = v1.x - s1v.x;
        self->f360 = v2.x - k;
        self->f368 = lo;
        self->f364 = bot + e;
        for (int j = 0; j < 2; j++) {
            Ptr32<Ref> p = &self->parts[j + 6];
            p[-6].p->vt->pos(p[-6].p, v0, 0);
            p[-4].p->vt->pos(p[-4].p, v1, 0);
            p[-2].p->vt->pos(p[-2].p, v2, 0);
            p[0].p->vt->pos(p[0].p, v3, 0);
            p[-6].p->vt->scale(p[-6].p, s0v, 0);
            p[-4].p->vt->scale(p[-4].p, s1v, 0);
            p[-2].p->vt->scale(p[-2].p, s2v, 0);
            p[0].p->vt->scale(p[0].p, s2v, 0);
        }
        if (self->inf.p) {
            Vec s(l / 1.5f, l / 3.0f, 1.0f);
            Vec p(v0.x, 0.0f, 0.0f);
            self->inner->vt->add(self->inner, self->inf.p, 0);
            self->inf.p->vt->scale(self->inf.p, s, 0);
            self->inf.p->vt->pos(self->inf.p, p, 0);
            self->inf.p->vt->vis(self->inf.p, 0);
        }
    }
    int a = 0, b = 0;
    if (!self->w140 || fn_802a7998(self)) {
        col.set(-56, -106, -56, -1);
        a = 2;
        b = 2;
    } else
        col.set(-1, -1, -1, -1);
    if (self->w176) {
        if (b != 2) b = 1;
        a = 1;
    }
    if (self->hl[0]) self->hl[0]->vt->vis(self->hl[0], a == 0);
    if (self->hl[1]) self->hl[1]->vt->vis(self->hl[1], a == 1);
    if (self->hl[2]) self->hl[2]->vt->vis(self->hl[2], a == 2);
    if (self->parts[1].p) self->parts[1].p->vt->vis(self->parts[1].p, b == 1);
    if (self->parts[3].p) self->parts[3].p->vt->vis(self->parts[3].p, b == 1);
    if (self->parts[5].p) self->parts[5].p->vt->vis(self->parts[5].p, b == 1);
    if (self->parts[7].p) self->parts[7].p->vt->vis(self->parts[7].p, b == 1);
    if (self->parts[0].p) {
        self->parts[0].p->vt->vis(self->parts[0].p, b != 1);
        fn_80173df0(fn_8034357c(self->parts[0].p), &col);
    }
    if (self->parts[2].p) {
        self->parts[2].p->vt->vis(self->parts[2].p, b != 1);
        fn_80173df0(fn_8034357c(self->parts[2].p), &col);
    }
    if (self->parts[4].p) {
        self->parts[4].p->vt->vis(self->parts[4].p, b != 1);
        fn_80173df0(fn_8034357c(self->parts[4].p), &col);
    }
    if (self->parts[6].p) {
        self->parts[6].p->vt->vis(self->parts[6].p, b != 1);
        fn_80173df0(fn_8034357c(self->parts[6].p), &col);
    }
}



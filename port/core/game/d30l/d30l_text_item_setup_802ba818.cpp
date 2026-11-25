#include "w3d_ptr.h"
#line 1 "d30l_text_item_setup_802ba818.cpp"
// GWMP8P rev0 0x802ba818. Text item setup: removes the old text sprite,
// looks up the optional localised string by name (or wraps it in the two
// marker strings when missing), loads the configured font, scales it, aligns
// it by the six alignment modes, and sets text and colour. Literals and
// string addresses are from the original; field names are inferred.
extern "C" void fn_8020c5c0(Ptr32<void>), fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020bb2c(Ptr32<void>);
// GWMP8P rev0 0x802ba818. Text item setup: removes the old text sprite,
// looks up the optional localised string by name (or wraps it in the two
// marker strings when missing), loads the configured font, scales it, aligns
// it by the six alignment modes, and sets text and colour. Literals and
// string addresses are from the original; field names are inferred.
extern "C" Ptr32<void> fn_803426b8(Ptr32<void>);
struct Header { unsigned short refs, length, capacity; };
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
struct Str {
    Ptr32<char> p;
    Str() { fn_803426b8(this); }
    Str(int) {}
    template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *);
    Str(const Str &o) {
        fn_8020c5c0(this);
        p = o.p;
        Ptr32<Header> h = fn_80341884(this);
        ++h->refs;
    }
    void init(const Str &o) { fn_8020c5c0(this); p = o.p; Ptr32<Header> h = fn_80341884(this); ++h->refs; }
    ~Str() { Ptr32<Str> t = this; fn_8020c5c4(t); fn_80341588(t); }
    unsigned length() const { return *(Ptr32<unsigned short>)(p - 4); }
    Str &operator=(const Str &o) {
        ++((Ptr32<Header>)(o.p - 6))->refs;
        Ptr32<Header> h = (Ptr32<Header>)(p - 6);
        if (--h->refs == 0) fn_8020bb2c(h);
        p = o.p;
        return *this;
    }
};
extern "C" void fn_8020bd38(Ptr32<Str>, Ptr32<const char>);
extern "C" Ptr32<void> fn_8020bf2c(Ptr32<Str>, Ptr32<const char>);
inline Str operator+(const Str &a, const char *b) {
    Str r(a);
    fn_8020bf2c(&r, b);
    return r;
}
inline Str operator+(const Str &a, const Str &b) {
    Str r(0);
    Ptr32<Str> pr = &r;
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
struct Key { Ptr32<const char> name; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *n) : name(n) {} };
struct Res;
struct ResVt { char u0[16]; Ptr32<void (Ptr32<Res>)> destroy; char u20[56]; Ptr32<int (Ptr32<Res>, const Vec &, int)> pos; char u80[4]; Ptr32<int (Ptr32<Res>, const Vec &, int)> scale; char u88[4]; Ptr32<void (Ptr32<Res>, Ptr32<Res>, int)> add; Ptr32<void (Ptr32<Res>, Ptr32<Res>)> remove; };
struct Res { Ptr32<ResVt> vt; };
struct Cfg { char u0[20]; Vec pos; char u32[84]; int bias; int align; float off; unsigned char b131, u129[3], b135, u133[3], b139, u137[3]; /* enteros: PPC +0x83/+0x87/+0x8b son el byte bajo, en el anfitrión +0x80/+0x84/+0x88 */ Str s140, s144; };
struct Sub { char u[4]; };
struct Panel {
    char u0[28];
    Sub sub;
    unsigned char font; char u32[3];
    char u36[4];
    Ptr32<Cfg> cfg;
    char u44[68];
    Ptr32<Res> group;
    char u116[96];
    Ptr32<Res> text;
};
extern "C" {
int fn_800fc2b0(const Key &, Ptr32<Ptr32<const char>>);
int fn_8015adf4(const Str &, Ptr32<Ptr32<Res>>, int);
Ptr32<Res> fn_80343580(Ptr32<Res>);
float fn_802b1880(Ptr32<Sub>);
int fn_8018d324(Ptr32<Res>, int);
int fn_8018c5b0(Ptr32<Res>, Ptr32<char>);
int fn_8018d35c(Ptr32<Res>, Ptr32<const Colour>);
}
extern const char s_803d8220[], s_803d8224[];
inline void quote(Str &s) {
    Str t;
    t = Str(s_803d8220) + s + s_803d8224;
    s = t;
}
extern "C" void d30l_text_item_setup_802ba818(Ptr32<Panel> self) {
    Ptr32<Cfg> c = self->cfg;
    if (c->s144.length()) {
        int bias = c->bias;
        if (self->text) {
            self->group->vt->remove(self->group, self->text);
            if (self->text) self->text->vt->destroy(self->text);
            self->text = 0;
        }
        if (c->s140.length()) {
            Str s(c->s140);
            Ptr32<const char> out;
            if (fn_800fc2b0(Key(s.p), &out) >= 0)
                fn_8020bd38(&s, out);
            else {
                Str t(0);
                Ptr32<Str> pt = &t;
                fn_803426b8(pt);
                t = Str(s_803d8220) + s + s_803d8224;
                s = t;
            }
            fn_8015adf4(c->s144, &self->text, (unsigned char)(self->font + (bias + 29)));
            self->group->vt->add(self->group, self->text, 0);
            Ptr32<Res> x = fn_80343580(self->text);
            float w = fn_802b1880(&self->sub);
            Vec v;
            Ptr32<Vec> pv = &v;
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



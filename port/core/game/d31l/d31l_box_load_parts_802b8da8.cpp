#include "w3d_ptr.h"
#line 1 "d31l_box_load_parts_802b8da8.cpp"
// GWMP8P rev0 0x802b8da8. Loads the six highlight box parts: three from the
// box style name and three from FE.Box.Highlight, then sets their frame
// bytes, adds them to the node and hides them. Strings and vtable slots come
// from the original; field names are inferred.
extern "C" void fn_8020c5c0(Ptr32<void>), fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020bb2c(Ptr32<void>);
struct Header { unsigned short refs, length, capacity; };
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
extern "C" void fn_803426b8(Ptr32<void>);
struct Str {
    Ptr32<char> p;
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
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void set(float a, float b, float c) { x = a; y = b; z = c; }
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
struct Cfg { char u0[20]; Vec size; char u32[116]; int w148; };
struct Box {
    char u0[32];
    unsigned char font; char w3d_tag_rest[3];
    char u36[4];
    Ptr32<Cfg> cfg;
    char u44[68];
    Ptr32<Res> node;
    char u116[260];
    Ref parts[6];
};
extern char str_803d8018[];
extern "C" {
int fn_8015adf4(const Str &, Ptr32<Held>, unsigned char);
Ptr32<Res> fn_8034357c(Ptr32<Res>);
int fn_80173f88(Ptr32<Res>, const unsigned char &);
Ptr32<char> fn_80263bb8(int);
int fn_80263608(Str, int);
}
inline void load(Ref &d, const Str &n, unsigned char t) {
    Held h;
    Ptr32<Held> ph = &h;
    fn_8015adf4(n, ph, t);
    d = fn_8034357c(h.r);
}
extern "C" void d31l_box_load_parts_802b8da8(Ptr32<Box> self) {
    Vec size(self->cfg->size);
    Str s0(fn_80263bb8(self->cfg->w148));
    Str s1(str_803d8018);
    fn_80263608(s0, 0);
    fn_80263608(s1, 0);
    load(self->parts[0], s0, (unsigned char)(self->font + 35));
    load(self->parts[2], s0, (unsigned char)(self->font + 35));
    load(self->parts[4], s0, (unsigned char)(self->font + 35));
    load(self->parts[1], s1, (unsigned char)(self->font + 35));
    load(self->parts[3], s1, (unsigned char)(self->font + 35));
    load(self->parts[5], s1, (unsigned char)(self->font + 35));
    for (unsigned i = 0; i < 2; i++) {
        Ptr32<Ref> b = self->parts;
        Ptr32<Ref> p = &b[i + 2];
        fn_80173f88(p[2].p, 8);
        fn_80173f88(p[-2].p, 9);
        fn_80173f88(p[0].p, 10);
        self->node->vt->add(self->node, p[2].p, 0);
        self->node->vt->add(self->node, p[-2].p, 0);
        self->node->vt->add(self->node, p[0].p, 0);
        p[2].p->vt->vis(p[2].p, 0);
        p[-2].p->vt->vis(p[-2].p, 0);
        p[0].p->vt->vis(p[0].p, 0);
    }
}



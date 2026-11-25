#include "w3d_ptr.h"
#line 1 "d28i_ribbon_strip_80122bfc.cpp"
// GWMP8P rev0 0x80122bfc. Builds the shared strip mesh of the ribbon renderer:
// creates the state objects and buffers, fills the index, position, normal and
// texture arrays for every strip and adds the mesh to the owner.
struct Obj;
struct ObjVt { char u0[12]; Ptr32<void (Ptr32<Obj>)> add; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct Ref {
    Ptr32<Obj> p;
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Obj *)w3d_p.get()) {}
 Ref(Obj *q) { p = q; if (p) p->vt->add(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
    void operator=(const Ref &o) {
        if (o.p) o.p->vt->add(o.p);
        if (p) p->vt->release(p);
        p = o.p;
    }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 void operator=(Obj *q) {
        if (q) q->vt->add(q);
        if (p) p->vt->release(p);
        p = q;
    }
};
inline void link(Ptr32<Obj> &slot, Ptr32<Obj> q) {
    Ptr32<Obj> old = slot;
    slot = q;
    if (q) q->vt->add(q);
    if (old) old->vt->release(old);
}
struct Vec { float x, y, z; };
struct Uv { float u, v; };
struct Colour { float r, g, b, a; Colour(float f) { r = f; g = f; b = f; a = f; } };
struct Header { char u0[4]; unsigned short references; char u6[18]; unsigned count; unsigned short locks; char u30[2]; };
struct Flags { char u0[4]; unsigned char bits; char w3d_tag_rest[3]; void mark() { bits |= 2; } };
struct State : Obj {
    Flags flags __attribute__((aligned(__alignof__(Obj)))); char u12[12]; int a; int b;
    void setA(int v) { a = v; flags.mark(); }
    void setB(int v) { b = v; flags.mark(); }
};
struct Buffer : Obj { char u4[16] __attribute__((aligned(__alignof__(Obj)))); Ptr32<Header> data; };
struct Indices : Obj { char u4[20] __attribute__((aligned(__alignof__(Obj)))); Ptr32<Header> data; };
struct Tint : Obj { char u4[16] __attribute__((aligned(__alignof__(Obj)))); Colour c; void set(const Colour &o) { c = o; } };
struct Mesh : Obj { char u4[44] __attribute__((aligned(__alignof__(Obj)))); Ptr32<Obj> slot48; Ptr32<Obj> slot52; };
struct Shape : Obj {
    char u4[64] __attribute__((aligned(__alignof__(Obj)))); Ptr32<Obj> uvs; Ptr32<Obj> tint; char u76[4]; Ptr32<Obj> pos; unsigned count; char u88[4]; Ptr32<Obj> indices; Ptr32<Header> lengths;
};
struct Shared { char u0[28]; unsigned short segments; char u30[2]; Ptr32<Buffer> pos; Ptr32<Buffer> nor; Ptr32<Uv> uvs; Ptr32<Obj> shape; char u48[8]; Ptr32<Obj> sprite; char u60[60]; unsigned short strips; };
extern Ptr32<Shared> shared_804b186c;
extern char t_80414518[], t_80415b00[], t_80414710[], t_804148d0[], t_80415cb0[], t_80415c30[], t_80415c00[], t_80414780[], t_80414870[], t_80414850[];
extern "C" Ptr32<Obj> make_8020b680(Ptr32<char>);
extern "C" void iface_801ef174(Ptr32<Obj>, int, int, Ptr32<Obj>);
extern "C" int query_801d0858(Ptr32<Obj>, Ptr32<int>);
extern "C" void texA_801d0898(Ptr32<Obj>, Ptr32<Obj>, int);
extern "C" void texB_801d086c(Ptr32<Obj>, Ptr32<Obj>);
extern "C" Ptr32<void> lock_801ef048(Ptr32<Ptr32<Header>>, unsigned, unsigned, unsigned);
extern "C" int attach_801750f4(Ptr32<void>, Ptr32<Obj>);
inline Ptr32<void> lockArray(Ptr32<Ptr32<Header>> ref, unsigned n, unsigned size, unsigned mode) {
    Ptr32<Header> h = *ref;
    Ptr32<void> p;
    if (h->references == 1 && n == h->count) { ++h->locks; p = h + 1; }
    else p = lock_801ef048(ref, n, size, mode);
    return p;
}
inline void zero(Ptr32<Vec> v, float f) { v->x = f; v->y = f; v->z = f; }
inline void setUv(Ptr32<Uv> t, float a, float b) { t->u = a; t->v = b; }
extern "C" int d28i_ribbon_strip_80122bfc(Ptr32<void> self) {
    Ref mesh(make_8020b680(t_80414518));
    Ref material(make_8020b680(t_80415b00));
    Ref shape(make_8020b680(t_80414710));
    Ref indices(make_8020b680(t_804148d0));
    Ref s1(make_8020b680(t_80415cb0));
    Ref s2(make_8020b680(t_80415c30));
    Ref s3(make_8020b680(t_80415c00));
    ((Ptr32<State>)s2.p)->setA(0);
    ((Ptr32<State>)s3.p)->setA(0);
    ((Ptr32<State>)s1.p)->setB(1);
    ((Ptr32<State>)s1.p)->setA(1);
    iface_801ef174(material.p, 28, 3, s1.p);
    iface_801ef174(material.p, 28, 3, s2.p);
    iface_801ef174(material.p, 28, 3, s3.p);
    {
        Ptr32<Obj> m = material.p;
        Ptr32<Obj> sprite = shared_804b186c->sprite;
        int on;
        query_801d0858(m, &on);
        if (on) texA_801d0898(m, sprite, 0);
        else texB_801d086c(m, sprite);
    }
    link(((Ptr32<Mesh>)mesh.p)->slot52, material.p);
    link(((Ptr32<Mesh>)mesh.p)->slot48, shape.p);
    Ptr32<char> bufType = t_80414780;
    (*(Ptr32<Ref>)&shared_804b186c->pos) = make_8020b680(bufType);
    (*(Ptr32<Ref>)&shared_804b186c->nor) = make_8020b680(bufType);
    Ref uvs(make_8020b680(t_80414870));
    link(((Ptr32<Shape>)shape.p)->pos, (Ptr32<Obj>)shared_804b186c->pos);
    link(((Ptr32<Shape>)shape.p)->uvs, uvs.p);
    Ptr32<Shared> g0 = shared_804b186c;
    unsigned short segs = g0->segments;
    unsigned stride = (segs << 1) + 4;
    unsigned n = stride * g0->strips;
    Colour white(1.0f);
    Ref tint(make_8020b680(t_80414850));
    ((Ptr32<Tint>)tint.p)->set(white);
    link(((Ptr32<Shape>)shape.p)->tint, tint.p);
    Ptr32<Vec> pos = (Ptr32<Vec>)lockArray(&shared_804b186c->pos->data, n, 12, 1);
    Ptr32<Vec> nor = (Ptr32<Vec>)lockArray(&shared_804b186c->nor->data, n, 12, 1);
    Ptr32<Uv> uv = (Ptr32<Uv>)lockArray(&((Ptr32<Buffer>)uvs.p)->data, n, 8, 1);
    Ptr32<Shared> g2 = shared_804b186c;
    g2->uvs = uv;
    *(Ptr32<Ref>)&g2->shape = shape;
    *(Ptr32<unsigned short>)lockArray(&((Ptr32<Shape>)shape.p)->lengths, 1, 2, 1) = n;
    ((Ptr32<Shape>)shape.p)->count = 1;
    Ptr32<unsigned short> idx = (Ptr32<unsigned short>)lockArray(&((Ptr32<Indices>)indices.p)->data, n, 2, 0);
    unsigned short i;
    for (i = 0; i < n; i++) idx[i] = i;
    link(((Ptr32<Shape>)shape.p)->indices, indices.p);
    for (unsigned short q = 0; q < shared_804b186c->strips; q++) {
        unsigned base = q * stride;
        Ptr32<Vec> p = pos + base;
        Ptr32<Vec> m = nor + base;
        Ptr32<Uv> u = shared_804b186c->uvs + base + 1;
        zero(p++, 0.0f);
        zero(m++, 0.0f);
        for (i = 0; i <= segs; i++) {
            float t = (float)i / (float)segs;
            { Uv &a = *u++; a.u = t; a.v = 0.0f; }
            { Uv &b = *u++; b.u = t; b.v = 1.0f; }
            zero(p++, 0.0f);
            zero(p++, 0.0f);
            zero(m++, 0.0f);
            zero(m++, 0.0f);
        }
        zero(p++, 0.0f);
        zero(m++, 0.0f);
    }
    attach_801750f4(self, mesh.p);
    return 0;
}



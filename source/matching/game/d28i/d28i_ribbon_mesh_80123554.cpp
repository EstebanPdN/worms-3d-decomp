// GWMP8P rev0 0x80123554. Builds the shared quad mesh of the ribbon renderer:
// creates the state objects and buffers, fills the index, position, normal and
// texture arrays for every quad and adds the mesh to the owner.
struct Obj;
struct ObjVt { char u0[12]; void (*add)(Obj *); void (*release)(Obj *); };
struct Obj { ObjVt *vt; };
struct Ref {
    Obj *p;
    Ref(Obj *q) { p = q; if (p) p->vt->add(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
    void operator=(const Ref &o) {
        if (o.p) o.p->vt->add(o.p);
        if (p) p->vt->release(p);
        p = o.p;
    }
    void operator=(Obj *q) {
        if (q) q->vt->add(q);
        if (p) p->vt->release(p);
        p = q;
    }
};
inline void link(Obj *&slot, Obj *q) {
    Obj *old = slot;
    slot = q;
    if (q) q->vt->add(q);
    if (old) old->vt->release(old);
}
struct Vec { float x, y, z; };
struct Uv { float u, v; };
struct Colour { float r, g, b, a; Colour(float f) { r = f; g = f; b = f; a = f; } };
struct Header { char u0[4]; unsigned short references; char u6[18]; unsigned count; unsigned short locks; char u30[2]; };
struct Flags { char u0[7]; unsigned char bits; void mark() { bits |= 2; } };
struct State : Obj {
    Flags flags; char u12[12]; int a; int b;
    void setA(int v) { a = v; flags.mark(); }
    void setB(int v) { b = v; flags.mark(); }
};
struct Buffer : Obj { char u4[16]; Header *data; };
struct Indices : Obj { char u4[20]; Header *data; };
struct Tint : Obj { char u4[16]; Colour c; void set(const Colour &o) { c = o; } };
struct Mesh : Obj { char u4[44]; Obj *slot48; Obj *slot52; };
struct Shape : Obj {
    char u4[64]; Obj *uvs; Obj *tint; char u76[4]; Obj *pos; unsigned tris; char u88[4]; Obj *indices;
};
struct Shared { char u0[32]; Buffer *pos; Buffer *nor; Uv *uvs; char u44[4]; Obj *shape; char u52[4]; Obj *sprite; char u60[60]; unsigned short quads; };
extern Shared *shared_804b186c;
extern char t_80414518[], t_80415b00[], t_804146e0[], t_804148d0[], t_80415cb0[], t_80415c30[], t_80415c00[], t_80414780[], t_80414870[], t_80414850[];
extern "C" Obj *make_8020b680(char *);
extern "C" void iface_801ef174(Obj *, int, int, Obj *);
extern "C" int query_801d0858(Obj *, int *);
extern "C" void texA_801d0898(Obj *, Obj *, int);
extern "C" void texB_801d086c(Obj *, Obj *);
extern "C" void *lock_801ef048(Header **, unsigned, unsigned, unsigned);
extern "C" int attach_801750f4(void *, Obj *);
inline void *lockArray(Header **ref, unsigned n, unsigned size, unsigned mode) {
    Header *h = *ref;
    void *p;
    if (h->references == 1 && n == h->count) { ++h->locks; p = h + 1; }
    else p = lock_801ef048(ref, n, size, mode);
    return p;
}
inline void zero(Vec *v, float f) { v->x = f; v->y = f; v->z = f; }
inline void setUv(Uv *t, float a, float b) { t->u = a; t->v = b; }
extern "C" int d28i_ribbon_mesh_80123554(void *self) {
    Ref mesh(make_8020b680(t_80414518));
    Ref material(make_8020b680(t_80415b00));
    Ref shape(make_8020b680(t_804146e0));
    Ref indices(make_8020b680(t_804148d0));
    Ref s1(make_8020b680(t_80415cb0));
    Ref s2(make_8020b680(t_80415c30));
    Ref s3(make_8020b680(t_80415c00));
    ((State *)s2.p)->setA(0);
    ((State *)s3.p)->setA(0);
    ((State *)s1.p)->setB(1);
    ((State *)s1.p)->setA(1);
    iface_801ef174(material.p, 28, 3, s1.p);
    iface_801ef174(material.p, 28, 3, s2.p);
    iface_801ef174(material.p, 28, 3, s3.p);
    {
        Obj *m = material.p;
        Obj *sprite = shared_804b186c->sprite;
        int on;
        query_801d0858(m, &on);
        if (on) texA_801d0898(m, sprite, 0);
        else texB_801d086c(m, sprite);
    }
    link(((Mesh *)mesh.p)->slot52, material.p);
    link(((Mesh *)mesh.p)->slot48, shape.p);
    char *bufType = t_80414780;
    (*(Ref *)&shared_804b186c->pos) = make_8020b680(bufType);
    (*(Ref *)&shared_804b186c->nor) = make_8020b680(bufType);
    Ref uvs(make_8020b680(t_80414870));
    link(((Shape *)shape.p)->pos, (Obj *)shared_804b186c->pos);
    link(((Shape *)shape.p)->uvs, uvs.p);
    unsigned n = shared_804b186c->quads * 6;
    Colour white(1.0f);
    Ref tint(make_8020b680(t_80414850));
    ((Tint *)tint.p)->set(white);
    link(((Shape *)shape.p)->tint, tint.p);
    Vec *pos = (Vec *)lockArray(&shared_804b186c->pos->data, n, 12, 1);
    Vec *nor = (Vec *)lockArray(&shared_804b186c->nor->data, n, 12, 1);
    Uv *uv = (Uv *)lockArray(&((Buffer *)uvs.p)->data, n, 8, 1);
    Shared *g2 = shared_804b186c;
    g2->uvs = uv;
    *(Ref *)&g2->shape = shape;
    ((Shape *)shape.p)->tris = n / 3;
    unsigned short *idx = (unsigned short *)lockArray(&((Indices *)indices.p)->data, n, 2, 0);
    unsigned short i;
    for (i = 0; i < n; i++) idx[i] = i;
    link(((Shape *)shape.p)->indices, indices.p);
    Shared *g = shared_804b186c;
    uv = g->uvs;
    for (i = 0; i < g->quads; i++) {
        zero(pos++, 0.0f); zero(pos++, 0.0f); zero(pos++, 0.0f); zero(pos++, 0.0f); zero(pos++, 0.0f); zero(pos++, 0.0f);
        zero(nor++, 0.0f); zero(nor++, 0.0f); zero(nor++, 0.0f); zero(nor++, 0.0f); zero(nor++, 0.0f); zero(nor++, 0.0f);
        { Uv &t = *uv++; t.u = 0.0f; t.v = 1.0f; }
        { Uv &t = *uv++; t.u = 1.0f; t.v = 1.0f; }
        { Uv &t = *uv++; t.u = 0.0f; t.v = 0.0f; }
        { Uv &t = *uv++; t.u = 1.0f; t.v = 1.0f; }
        { Uv &t = *uv++; t.u = 0.0f; t.v = 0.0f; }
        { Uv &t = *uv++; t.u = 1.0f; t.v = 0.0f; }
    }
    attach_801750f4(self, mesh.p);
    return 0;
}

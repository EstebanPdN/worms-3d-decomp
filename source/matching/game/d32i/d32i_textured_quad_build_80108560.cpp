// d32i: 0x80108560. Builds a textured quad scene node: loads the named
// texture, sizes it to the next power of two capped at 256, and links state,
// material, mesh and shape nodes.
struct Obj;
struct ObjVt {
    char u0[12];
    void (*add)(Obj *);      // +12
    void (*release)(Obj *);  // +16
    char u14[4];
    void (*set24)(Obj *, Obj *);       // +24
    char u1c[4];
    int (*load)(Obj *, int, Obj **);   // +32
    char u24[12];
    void (*set48)(Obj *, int);         // +48
    char u34[4];
    union { void (*set56)(Obj *, int); void (*flush56)(Obj *); };  // +56
    char u3c[4];
    void (*set64)(Obj *, int);         // +64
    char u44[12];
    void (*set80)(Obj *, const int *, int);  // +80
    char u54[8];
    Obj *(*find)(Obj *, const char *);       // +92
    char u60[48];
    void (*set144)(Obj *, int);        // +144
};
struct Obj { ObjVt *vt; };
struct Ref {
    Obj *p;
    Ref() : p(0) {}
    Ref(Obj *q) { p = q; if (p) p->vt->add(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
};
inline void link(Obj *&slot, Obj *q) {
    Obj *old = slot;
    slot = q;
    if (q) q->vt->add(q);
    if (old) old->vt->release(old);
}
struct Vec { float x, y, z; };
struct Uv { float u, v; };
struct Rgba { char r, g, b, a; };
struct Header { char u0[4]; unsigned short references; char u6[18]; unsigned count; unsigned short locks; char u30[2]; };
struct Flags { char u0[7]; unsigned char bits; void mark() { bits |= 2; } void mark1() { bits |= 1; } };
struct State : Obj {
    Flags flags; char u12[12]; int a;
    void setA(const int &v) { a = v; flags.mark(); }
};
struct Texture { char u0[44]; unsigned short w, h; };
struct Buffer : Obj { char u4[16]; Header *data; };
struct Indices : Obj { char u4[20]; Header *data; };
struct Mesh : Obj { char u4[44]; Obj *shape; Obj *material; };
struct TexBind : Obj { char u4[32]; int b; int c; char u2c[12]; int a; Obj *tex; char u40[16]; int d; };
struct Shape : Obj {
    Flags flags; char u0c[56]; Obj *uvs; Obj *cols; char u4c[4]; Obj *pos; int tris; char u58[4]; Obj *indices;
};
struct Self { char u0[48]; int id; };
struct Global { char u0[132]; Obj *renderer; };
extern Global *global_804b1788;
extern char t_804143e0[], t_804144f8[], t_80415c30[], t_80415c00[], t_80413db0[], t_80414518[], t_80415b00[], t_80415d60[], t_804146e0[], t_80414780[], t_804148d0[], t_80414870[], t_80414830[];
extern const int blend_80399bd8[];
extern "C" Obj *service_8020b648();
extern "C" Obj *make_8020b680(char *);
extern "C" void iface_801ef174(Obj *, int, int, Obj *);
extern "C" void * query_801d0858(Obj *, int *);
extern "C" void texA_801d0898(Obj *, Obj *, int);
extern "C" void texB_801d086c(Obj *, Obj *);
extern "C" void *lock_801ef048(Header **, unsigned, unsigned, unsigned);
extern "C" int add_801d4544(Obj *, Obj *);
extern "C" void replace_80174820(Self *, Obj *);
template <unsigned N, unsigned S> inline void *lockArray(Header **ref) {
    Header *h = *ref;
    void *p;
    if (h->references == 1 && h->count == N) { ++h->locks; p = h + 1; }
    else p = lock_801ef048(ref, N, S, 0);
    return p;
}
template <class T> inline const T &lesser(const T &a, const T &b) { return b < a ? b : a; }
struct Size { unsigned short h, w; Size(unsigned short a, unsigned short b) { w = b; h = a; } Size(const Size &); };
inline void power_of_two(unsigned short &v, unsigned short n) {
    while (n > v) { unsigned short d = v << 1; v = d; }
}
inline void setUv(Uv *t, float a, float b) { t->u = a; t->v = b; }
inline void setVec(Vec *t, float a, float b, float c) { t->x = a; t->y = b; t->z = c; }
extern "C" int d32i_textured_quad_build_80108560(Self *self) {
    Ref tex;
    Obj **slot = &tex.p;
    const char *cls = t_804143e0;
    Obj *svc = service_8020b648();
    Obj *mgr = svc->vt->find(svc, cls);
    if (mgr->vt->load(mgr, self->id, slot) < 0) return 0x80004005;
    Obj *root = make_8020b680(t_804144f8);
    Obj *r = global_804b1788->renderer;
    if (r) r->vt->flush56(r);
    Size size(1, 1);
    {
        Texture *t = (Texture *)tex.p;
        unsigned short tw = t->w;
        unsigned short th = t->h;
        power_of_two(size.h, th);
        power_of_two(size.w, tw);
        size.h = size.h >> 1;
        size.w = size.w >> 1;
        size.h = lesser<unsigned short>(size.h, 256);
        size.w = lesser<unsigned short>(size.w, 256);
    }
    Ref s1(make_8020b680(t_80415c30));
    ((State *)s1.p)->setA(0);
    Ref s2(make_8020b680(t_80415c00));
    ((State *)s2.p)->setA(0);
    ((State *)s2.p)->flags.mark1();
    Ref blend(make_8020b680(t_80413db0));
    blend.p->vt->set56(blend.p, 4);
    blend.p->vt->set144(blend.p, 0);
    blend.p->vt->set64(blend.p, 1);
    blend.p->vt->set80(blend.p, blend_80399bd8, 5);
    blend.p->vt->set24(blend.p, tex.p);
    Ref mesh(make_8020b680(t_80414518));
    Ref material(make_8020b680(t_80415b00));
    add_801d4544(material.p, s2.p);
    Ref bind(make_8020b680(t_80415d60));
    link(((TexBind *)bind.p)->tex, tex.p);
    ((TexBind *)bind.p)->a = 1;
    ((TexBind *)bind.p)->c = 3;
    ((TexBind *)bind.p)->b = 3;
    ((TexBind *)bind.p)->d = 2;
    link(((Mesh *)mesh.p)->material, material.p);
    iface_801ef174(material.p, 28, 3, s1.p);
    {
        Obj *m = material.p;
        Obj *sprite = bind.p;
        int on;
        query_801d0858(m, &on);
        if (on) texA_801d0898(m, sprite, 0);
        else texB_801d086c(m, sprite);
    }
    iface_801ef174(root, 44, 3, mesh.p);
    Ref shape(make_8020b680(t_804146e0));
    Ref buffer(make_8020b680(t_80414780));
    Ref indices(make_8020b680(t_804148d0));
    Ref uvs(make_8020b680(t_80414870));
    Ref colours(make_8020b680(t_80414830));
    link(((Shape *)shape.p)->pos, buffer.p);
    link(((Shape *)shape.p)->indices, indices.p);
    link(((Shape *)shape.p)->uvs, uvs.p);
    link(((Shape *)shape.p)->cols, colours.p);
    Vec *pos = (Vec *)lockArray<4, 12>(&((Buffer *)buffer.p)->data);
    unsigned short *idx = (unsigned short *)lockArray<6, 2>(&((Indices *)indices.p)->data);
    Uv *uv = (Uv *)lockArray<4, 8>(&((Buffer *)uvs.p)->data);
    Rgba *c = (Rgba *)lockArray<4, 4>(&((Buffer *)colours.p)->data);
    for (int i = 0; i < 4; i++) {
        c->r = -1; c->g = -1; c->b = -1; c->a = -1;
        c++;
    }
    ((Shape *)shape.p)->flags.mark1();
    ((Shape *)shape.p)->tris = 2;
    setUv(&uv[0], 0.0f, 0.0f);
    setUv(&uv[1], 1.0f, 0.0f);
    setUv(&uv[2], 1.0f, 1.0f);
    setUv(&uv[3], 0.0f, 1.0f);
    setVec(&pos[0], -1.0f, -1.0f, 0.0f);
    setVec(&pos[1], 1.0f, -1.0f, 0.0f);
    setVec(&pos[2], 1.0f, 1.0f, 0.0f);
    setVec(&pos[3], -1.0f, 1.0f, 0.0f);
    idx[0] = 0; idx[1] = 1; idx[2] = 2; idx[3] = 0; idx[4] = 2; idx[5] = 3;
    link(((Mesh *)mesh.p)->shape, shape.p);
    replace_80174820(self, root);
    mgr->vt->set48(mgr, 0);
    return 0;
}

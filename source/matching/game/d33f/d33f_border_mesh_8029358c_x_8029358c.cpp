// GWMP8P rev0 0x8029358c. Rebuilds a bordered quad mesh: twenty corner
// points from the half sizes and border width, expanded through the index
// table at 0x80401880 into the locked vertex array, then the bounding box
// and sphere are refreshed.
struct Vec3 { float x, y, z; Vec3() {} void set(float a, float b, float c) { x = a; y = b; z = c; } };
struct Box { Vec3 lo, hi; };
struct Sphere { Vec3 c; float r; };
struct Obj;
struct ObjVt { void *u[3]; void (*retain)(Obj *); void (*release)(Obj *); };
struct Hdr { char u0[4]; unsigned short refs; char u6[18]; unsigned count; unsigned short gen; char u30[2]; Vec3 data[1]; };
struct Arr { Hdr *h; };
extern "C" Vec3 *fn_801ef048(Arr *, unsigned, int, int);
struct Mesh;
struct Geom;
struct Vtx;
struct Obj { ObjVt *vt; };
struct Held {
    Obj *p;
    Held(Obj *o) : p(o) { if (o) o->vt->retain(o); }
    Held(const Held &);
    ~Held() { if (p) p->vt->release(p); }
};
struct Vtx : Obj { char u4[16]; Arr verts; };
struct Geom : Obj { char u4[16]; Box box; char u44[36]; Vtx *vtx; void SetBox(const Box &b) { box = b; } };
struct Bound { char u0[7]; unsigned char flags; char u8[8]; Sphere sphere; char u32[4]; int zero; void Dirty() { flags &= ~1; } void SetSphere(const Sphere &o) { sphere = o; } };
struct Mesh : Obj { Bound bound; char u44[4]; Geom *geom; };
struct Inst : Obj { char u4[28]; Mesh *mesh; };
struct Root : Obj { char u4[40]; Inst *inst; };
extern "C" Root *fn_801750d4(void *);
extern "C" void * fn_801f55ec(Sphere *, const Box *);
inline const float &Min(const float &a, const float &b) { return b < a ? b : a; }

extern unsigned char lbl_80401880[];
inline Vec3 *Lock(Arr *a, unsigned count) {
    Hdr *h = a->h;
    if (h->refs == 1) { h->gen++; return h->data; }
    return fn_801ef048(a, count, 12, 2);
}
inline bool Less(const unsigned &a, const unsigned &b) { return a < b; }
extern "C" void d33f_border_mesh_8029358c_x_8029358c(void **source, float border, float w, float h, float inset) {
    if (w < border || h < border + inset) {
        border = Min(w, h);
        inset = 0.0f;
    }
    Held ra(fn_801750d4(*source));
    Held rb(((Root *)ra.p)->inst->mesh);
    Held rc(((Mesh *)rb.p)->geom);
    Held rd(((Geom *)rc.p)->vtx);
    Vtx *vtx = (Vtx *)rd.p;
    unsigned count = vtx->verts.h->count;
    Vec3 *out = Lock(&vtx->verts, count);
    Vec3 v[20];
    for (int i = 0; i < 4; i++) {
        v[i].y = h;
        v[i + 4].y = h - border;
        v[i + 8].y = border - h;
        v[i + 12].y = -h;
    }
    for (int i = 0; i < 4; i++) {
        v[i * 4].x = -w;
        v[i * 4 + 1].x = border - w;
        v[i * 4 + 2].x = w - border;
        v[i * 4 + 3].x = w;
    }
    v[16].set(w - border, h - border - inset, 0.0f);
    v[17].set(w, h - border - inset, 0.0f);
    v[18].set(w - border, border - h + inset, 0.0f);
    v[19].set(w, border - h + inset, 0.0f);
    for (unsigned i = 0; Less(i, count); i++) {
        *out = v[lbl_80401880[i]];
        out->z = 0.0f;
        out++;
    }
    ((Mesh *)rb.p)->bound.Dirty();
    int none = 0;
    float bw = w, bh = h;
    Box box;
    box.lo.set(-bw, -bh, 0.0f);
    box.hi.set(bw, bh, 0.0f);
    Sphere s;
    fn_801f55ec(&s, &box);
    ((Geom *)rc.p)->SetBox(box);
    ((Mesh *)rb.p)->bound.SetSphere(s);
    ((Mesh *)rb.p)->bound.zero = none;
}

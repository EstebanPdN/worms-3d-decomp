#include "w3d_ptr.h"
#line 1 "d31h_land_attach_model_800b87d0.cpp"
// GWMP8P rev0 0x800b87d0. Attaches a model to a land object. Names are
// inferred. Takes a reference on the new model through virtual slot 12 and
// releases the old one through slot 16, caches the transform with
// 0x800b8cf0, moves the model's offset by the transform, computes a bounding
// sphere from the box at +348 and +360 about the pivot at +288 with the
// scale at +372 and the basis at +240, adding the world origin, marks the
// flag at +40, locks the array at +440 (a resident array only counts the
// lock), rebuilds with 0x800b8140, takes the bounds twice with 0x800b7ed0,
// publishes them to the land service when present, and registers every list
// item with 0x8008e7d4. Class layouts are partial views.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Set(const Vec &o) { x = o.x; y = o.y; z = o.z; }
    void Mul(const Vec &o) { x *= o.x; y *= o.y; z *= o.z; }
    float lenSq() const { return x * x + y * y + z * z; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
struct Axis { float x, y, z; };
struct Transform {
    Axis axis[3]; Axis position;
    const Axis &R(int i) const { return axis[i]; }
    const Axis &P() const { return position; }
    void apply(Vec &o, const Vec &v) const {
        Ptr32<Vec> q = &o;
        q->x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + P().x;
        q->y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + P().y;
        q->z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + P().z;
    }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
struct Sphere { Vec c; float r; };
struct Header { char unknown0[4]; unsigned short kind; char unknown6[18]; int count; unsigned short locks; };
struct ArrayRef { Ptr32<Header> header; };
extern "C" Ptr32<void> reserve_801ef048(Ptr32<ArrayRef>, int, int, int);
struct Item;
struct List { char unknown0[24]; unsigned count; char unknown28[4]; Ptr32<Item> items[1]; };
struct Model {
    Ptr32<Ptr32<void>> vt; char unknown4[16]; Sphere sphere; int unknown36; int flag40; Ptr32<List> list; char unknown48[192];
    Axis basis[3]; char unknown276[12]; Vec pivot; char unknown300[48]; Vec low; Vec high; Vec scale; Vec offset; char unknown396[44]; ArrayRef array;
    void AddRef() { ((Ptr32<void (Ptr32<Model>)>)*(Ptr32<Ptr32<void>>)((Ptr32<char>)vt + 12))(this); }
    void Release() { ((Ptr32<void (Ptr32<Model>)>)*(Ptr32<Ptr32<void>>)((Ptr32<char>)vt + 16))(this); }
    const Axis &R(int i) const { return basis[i]; }
    Vec Pos(const Vec &v) const { return offset + v; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
struct World { char unknown0[104]; Vec origin; Vec Shift(const Vec &v) const { return v + origin; } };
extern Ptr32<World> lbl_804b17e0;
struct Land { Ptr32<Ptr32<void>> vt; Ptr32<Model> model; };
extern "C" void cache_800b8cf0(Ptr32<Land>, Ptr32<const Transform>);
extern "C" void rebuild_800b8140(Ptr32<Land>);
extern "C" void bounds_800b7ed0(Ptr32<Land>, Ptr32<Vec>, Ptr32<Vec>);
extern "C" void publish_800bae54(Ptr32<World>, const Vec &, const Vec &);
extern "C" void set_80251398(Ptr32<Item>, unsigned char);
extern "C" void attach_8008e7d4(Ptr32<Model>, Ptr32<Item>);
inline const float &Max(const float &a, const float &b) { return a < b ? b : a; }
inline Vec Sum3(const Vec &a, const Vec &b, const Vec &c) { return (a + b) + c; }
inline Vec Plus(const Vec &a, const Vec &b) { return a + b; }
inline void Set20(Ptr32<Model> m, const Sphere &s) { m->sphere = s; }
extern "C" void d31h_land_attach_model_800b87d0(Ptr32<Land> self, Ptr32<Model> model, Ptr32<const Transform> t) {
    if (model) model->AddRef();
    if (self->model) self->model->Release();
    self->model = model;
    cache_800b8cf0(self, t);
    Vec v;
    t->apply(v, self->model->offset);
    self->model->offset = v;
    Ptr32<Model> m = self->model;
    Vec half = (m->low + m->high) * 0.5f;
    float r2 = half.lenSq();
    Vec c = half - m->pivot;
    c.Mul(m->scale);
    Vec d;
    m->rotate(d, c);
    float rad = sqrt_802e82c0(r2);
    Ptr32<Model> o = self->model;
    Sphere sph;
    {
        Vec w = (o->offset + d) + lbl_804b17e0->origin;
        sph.c = w;
    }
    Vec sc = o->scale;
    sph.r = rad * Max(Max(sc.x, sc.y), sc.z);
    o->flag40 = 0;
    Set20(self->model, sph);
    Ptr32<ArrayRef> a = &self->model->array;
    Ptr32<Header> h = a->header;
    int n = h->count;
    if (h->kind == 1) ++h->locks;
    else reserve_801ef048(a, n, 4, 2);
    Vec low, high;
    rebuild_800b8140(self);
    bounds_800b7ed0(self, &low, &high);
    bounds_800b7ed0(self, &low, &high);
    if (lbl_804b17e0) {
        Vec a2 = low, b2 = high;
        publish_800bae54(lbl_804b17e0, a2, b2);
    }
    Ptr32<List> list = self->model->list;
    unsigned cnt = list->count;
    Ptr32<Ptr32<Item>> items = list->items;
    for (unsigned i = 0; i < cnt; i++) {
        set_80251398(items[i], 1);
        attach_8008e7d4(self->model, items[i]);
    }
}



#include "w3d_ptr.h"
#line 1 "d28i_camera_look_80120648.cpp"
// GWMP8P rev0 0x80120648. Finds the point of interest a camera follows from
// its target object's type and hands out the look-at vectors.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
};
struct TypeInfo { char u0[20]; Ptr32<TypeInfo> base; };
struct Object;
struct ObjectVt { char u0[20]; Ptr32<Ptr32<TypeInfo> (Ptr32<Object>)> type; char u24[20]; Ptr32<void (Ptr32<Object>, Ptr32<void>, Ptr32<Vec>)> a; Ptr32<void (Ptr32<Object>, Ptr32<void>, Ptr32<Vec>)> b; Ptr32<void (Ptr32<Object>, Ptr32<void>, Ptr32<Vec>)> c; };
struct Object { Ptr32<ObjectVt> vt; };
template <TypeInfo *TYPE> inline bool isKind(Ptr32<Object> o) {
    Ptr32<TypeInfo> c = o->vt->type(o);
    Ptr32<TypeInfo> t = TYPE;
    while (c != t) {
        Ptr32<TypeInfo> n = c->base;
        if (c == n) return false;
        c = n;
    }
    return true;
}
struct Prop : Object {
    char u4[36] __attribute__((aligned(__alignof__(Object)))); Vec p40; Vec p52; char u64[196]; Vec p260; char u272[4]; Vec p276; Vec p288;
    void bounds(Vec &lo, Vec &hi) const { lo = p276; hi = p288; }
    Vec P40() const { return p40; }
    Vec P52() const { return p52; }
    Vec P260() const { return p260; }
};
struct Actor : Object { char u4[580] __attribute__((aligned(__alignof__(Object)))); Ptr32<void> index; char u588[88]; Vec v676; char u688[568]; Vec v1256; Vec v1268;
    void bounds(Vec &lo, Vec &hi) const { lo = v1256; hi = v1268; }
};
struct Angles { float u0; float angle; };
struct Heading { char u0[68]; Angles angles; };
struct Engine { char u0[52]; Ptr32<void> view; };
struct Camera { char u0[64]; Ptr32<void> curve; char u68[8]; Ptr32<void> target; char u80[88]; bool moved; };
extern TypeInfo type_80360e10[], type_803615f0[], type_803600c0[];
extern "C" Ptr32<Object> lookup_80164fc8(Ptr32<void>);
extern "C" Ptr32<Engine> engine_80165254();
extern "C" void actor_80150b38(Ptr32<Object>, Ptr32<Vec>);
extern "C" Ptr32<Heading> index_800fc6dc(int);
extern "C" float sinf_802e88ac(float);
extern "C" float cosf_802e86d4(float);
extern "C" float height_80178df0(Ptr32<void>);
extern "C" void planar_80120bec(Ptr32<Camera>, const Vec &, Vec, Vec, Vec &, Vec &);
extern "C" void d28i_camera_look_80120648(Ptr32<Camera> self, Vec &out1, Vec &out2, Vec &out3, Vec &out4) {
    Vec a(0.0f, 0.0f, 0.0f);
    Vec b(0.0f, 0.0f, 0.0f);
    Vec c(0.0f, 0.0f, 0.0f);
    Vec d, e, f, g, h;
    Ptr32<Object> o = lookup_80164fc8(self->target);
    if (isKind<type_80360e10>(o)) {
        Ptr32<void> view = engine_80165254()->view;
        o->vt->a(o, view, &d);
        o->vt->b(o, view, &h);
        ((Ptr32<Prop>)o)->bounds(e, b);
        o->vt->c(o, view, &c);
        if (c.lenSq() == 0.0f) c = Vec(0.0f, 0.0f, 1.0f);
        planar_80120bec(self, c, a, b, f, g);
    } else if (isKind<type_803615f0>(o)) {
        actor_80150b38(o, &d);
        h = ((Ptr32<Actor>)o)->v676;
        ((Ptr32<Actor>)o)->bounds(e, b);
        Angles &r = index_800fc6dc((int)w3d::H((((Ptr32<Actor>)o)->index)))->angles;
        float s = sinf_802e88ac(r.angle);
        c = Vec(s, 0.0f, cosf_802e86d4(r.angle));
        planar_80120bec(self, c, a, b, f, g);
    } else if (isKind<type_803600c0>(o)) {
        d = ((Ptr32<Prop>)o)->P40();
        e = ((Ptr32<Prop>)o)->P260();
        h = ((Ptr32<Prop>)o)->P52();
        f = Vec(0.0f, 0.0f, 1.0f);
        g = Vec(0.0f, 0.0f, 1.0f);
    }
    if (d.y > height_80178df0(self->curve)) {
        out1 = d;
        a = h;
        out2 = f;
        out3 = e;
        out4 = g;
    }
    self->moved = self->moved | a.lenSq() > 0.0f;
}



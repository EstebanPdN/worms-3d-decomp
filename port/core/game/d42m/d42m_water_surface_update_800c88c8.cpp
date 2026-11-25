#include "w3d_ptr.h"
#line 1 "d42m_water_surface_update_800c88c8.cpp"
// GWMP8P rev0 0x800c88c8. Per-frame water update: scrolls the texture offset
// from the tweak speed, sets the mesh tint from the colour tweak, places the
// plane at the level height (quantised to odd sixteenths), mirrors the
// camera transform for the reflection service, scales the mesh by eye height
// and rebuilds the wave colours via 0x800c96f0. Names are inferred.
extern "C" float sqrt_802e82c0(float);
extern "C" float tan_802e8988(float);
extern "C" float fabsf(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { Ptr32<Vec> p = this; x = a; p->y = b; p->z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Bits(const Vec &o) { *(Ptr32<int>)&x = *(Ptr32<int>)&o.x; *(Ptr32<int>)&y = *(Ptr32<int>)&o.y; *(Ptr32<int>)&z = *(Ptr32<int>)&o.z; }
    float flatSq(float y0) const { return x * x + y0 + z * z; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void operator*=(float f) { x *= f; y *= f; z *= f; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
struct Mat { unsigned m[16]; };
struct Mat64 { float a[12]; Vec t; float w; };
struct Colour { unsigned char r, g, b, a; };
struct Tint { float r, g, b, a; void Set(float cr, float cg, float cb, float ca) { Ptr32<Tint> p = this; r = cr; p->g = cg; p->b = cb; p->a = ca; } };
struct Uv { float u, v; };
struct Node;
struct NodeVtable {
    Ptr32<void> unknown00[19];
    Ptr32<int (Ptr32<Node>, Ptr32<const Vec>, int)> set_position;  /* +76 */
    Ptr32<void> unknown80;
    Ptr32<int (Ptr32<Node>, Ptr32<const Vec>, int)> set_scale;     /* +84 */
    Ptr32<void> unknown88[5];
    Ptr32<Ptr32<const Vec> (Ptr32<Node>)> scale;                    /* +108 */
};
struct Node { Ptr32<NodeVtable> vtable; };
inline int Put(Ptr32<Node> n, Ptr32<const Vec> v, int f) { return n->vtable->set_position(n, v, f); }
inline int Put2(Ptr32<Node> n, const Vec &v) { return n->vtable->set_position(n, &v, 0); }
struct Tweak { char unknown00[120]; Colour colour; };
struct Key { Ptr32<const char> name; };
struct Game { char unknown00[208]; int mode; };
struct Water { char unknown00[28]; Ptr32<Node> plane; char unknown32[4]; Ptr32<Node> mesh; char unknown40[316]; Ptr32<void> level; float offset; unsigned time; };
struct Service;
struct ServiceVtable {
    Ptr32<void> unknown00[6];
    Ptr32<Ptr32<const Mat> (Ptr32<Service>)> view;                 /* +24 */
    Ptr32<void (Ptr32<Service>, Ptr32<const Mat>)> put;           /* +28 */
    Ptr32<void> unknown32;
    Ptr32<int (Ptr32<Service>)> get36;                       /* +36 */
    Ptr32<void (Ptr32<Service>, int)> set40;                 /* +40 */
};
struct Service { Ptr32<ServiceVtable> vtable; };
struct Eye;
struct EyeVtable { Ptr32<void> unknown00[14]; Ptr32<Ptr32<const Vec> (Ptr32<Eye>)> from; Ptr32<Ptr32<const Vec> (Ptr32<Eye>)> to; };
struct Eye { Ptr32<EyeVtable> vtable; };
struct Runtime { char unknown00[48]; Ptr32<Eye> eye; };
extern Ptr32<Runtime> lbl_804b1788;
extern Ptr32<Game> lbl_804aaabc;
extern char lbl_80387af8[], lbl_80387b04[], lbl_80387b14[];
extern const Vec lbl_8044b688[];
extern "C" int read_800fc270(Ptr32<Key>, Ptr32<float>);
extern "C" int read_800fc2b0(Ptr32<Key>, Ptr32<Key>);
extern "C" int read_800fc330(Ptr32<Key>, Ptr32<Ptr32<Tweak>>);
extern "C" int set_tint_80182178(Ptr32<Node>, Ptr32<Tint>);
extern "C" Ptr32<void> as_value_80342a74(Ptr32<void>);
extern "C" float value_80178df0(Ptr32<void>);
extern "C" Ptr32<Service> request_8015cd04(Ptr32<Runtime>, int);
extern "C" int inverse_801f69ec(Ptr32<Mat64>, Ptr32<const Mat64>);
extern "C" int waves_800c96f0(Ptr32<Water>, Ptr32<Uv>, float, float, float, float);
inline float HeightToWorld(int h) { return (float)h * 0.0625f; }
extern "C" int water_surface_update_800c88c8(Ptr32<Water> self, unsigned time) {
    Key speedKey; speedKey.name = lbl_80387af8;
    float speed;
    read_800fc270(&speedKey, &speed);
    self->time = time;
    self->offset = (float)time / 1000.0f * 0.03f * speed;
    Key tweakKey; tweakKey.name = lbl_80387b04;
    Key name;
    read_800fc2b0(&tweakKey, &name);
    Ptr32<Tweak> tweak = 0;
    if (lbl_804aaabc->mode != 7) {
        Key fe; fe.name = lbl_80387b14;
        read_800fc330(&fe, &tweak);
    } else {
        read_800fc330(&name, &tweak);
    }
    Colour colour = tweak->colour;
    Tint tint;
    float red = colour.r;
    const Colour &c = colour;
    float green = c.g, blue = c.b, alpha = c.a;
    tint.Set(red / 255.0f, green / 255.0f, blue / 255.0f, alpha / 255.0f);
    set_tint_80182178(self->mesh, &tint);
    int height = (int)(value_80178df0(as_value_80342a74(self->level)) * 16.0f);
    Vec pos;
    Vec t;
    Vec at;
    Mat64 view;
    Mat64 inv;
    Ptr32<Vec> p = &pos;
    pos.y = HeightToWorld(height | 1);
    pos.x = 0.0f;
    p->z = 0.0f;
    Put(self->plane, p, 0);
    Ptr32<Service> a = request_8015cd04(lbl_804b1788, 4);
    Ptr32<Service> b = request_8015cd04(lbl_804b1788, 9);
    b->vtable->set40(b, a->vtable->get36(a));
    *(Ptr32<Mat>)&view = *a->vtable->view(a);
    inverse_801f69ec(&inv, &view);
    t.x = inv.t.x; t.y = inv.t.y; t.z = inv.t.z;
    at = t;
    Uv uv;
    float u = t.x / self->plane->vtable->scale(self->plane)->x;
    float v = t.z / self->plane->vtable->scale(self->plane)->z;
    uv.u = u;
    uv.v = v;
    Vec sc(0.7f, 0.99f - 0.7f / (t.y / 500.0f + 1.0f), 0.7f);
    if (self->mesh) self->mesh->vtable->set_scale(self->mesh, &sc, 0);
    float zero = 0.0f;
    inv.t.y = t.y;
    t.x = zero;
    t.z = zero;
    inv.t.x = zero;
    inv.t.z = zero;
    inverse_801f69ec(&view, &inv);
    b->vtable->put(b, (Ptr32<Mat>)&view);
    Ptr32<const Vec> from = lbl_804b1788->eye->vtable->from(lbl_804b1788->eye);
    Ptr32<const Vec> to = lbl_804b1788->eye->vtable->to(lbl_804b1788->eye);
    Vec n = *from - *to;
    n *= 1.0f / n.len();
    n.y = fabsf(n.y);
    Vec sun;
    sun.Bits(lbl_8044b688[0]);
    Vec right(1.0f, 0.0f, 0.0f);
    Vec fwd(0.0f, 0.0f, 1.0f);
    Vec e = at - sun;
    e.y = zero;
    float k = 1.0f / sqrt_802e82c0(e.flatSq(zero));
    e *= k;
    float lo = 0.87266463f, hi = 1.3962634f;
    tan_802e8988(lo);
    tan_802e8988(hi);
    float outer = 0.35f, inner = 0.1f;
    waves_800c96f0(self, &uv, inner, outer, at.y, n.y);
    return 0;
}



#include "w3d_ptr.h"
#line 1 "d41m_lens_flare_update_800bf320.cpp"
// GWMP8P rev0 0x800bf320. Lens flare update. Takes the sun position through
// the view transforms, hides the mesh when off screen or occluded, fades it,
// then writes kind, colour, size and position for every flare element into
// the mesh arrays. Built with -mfast-cast and -mps-float. Names are
// inferred.
extern "C" float sqrt_802e82c0(float);
struct Object;
struct ObjectVtable { Ptr32<void> unknown00[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
inline Ptr32<void> Slot(Ptr32<Object> o, int off) { return *(Ptr32<Ptr32<void>>)((Ptr32<char>)o->vtable + off); }
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
struct Axis { float x, y, z; };
extern "C" void position_ctor_80343740(Ptr32<Axis>);
struct Transform {
    Axis axis[3]; Axis position;
    Transform() { position_ctor_80343740(&position); }
    const Axis &R(int i) const { return axis[i]; }
    const Axis &P() const { return position; }
    void apply(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + P().x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + P().y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + P().z;
    }
};
struct Mtx44 { float m[16]; };
struct Camera : Object {};
struct Scene { char unknown0[48]; Ptr32<Object> camera; char unknown52[80]; Ptr32<Object> camera2; };
extern Ptr32<Scene> scene_804b1788;
extern Axis sun_8044b688;
typedef Ptr32<Ptr32<const Vec> (Ptr32<Object>)> GetVec;
typedef Ptr32<Ptr32<const Mtx44> (Ptr32<Object>)> GetMtx;
typedef Ptr32<int (Ptr32<Object>, int)> SetFn;
extern "C" void from44_801f74d0(Ptr32<Transform>, Ptr32<const Mtx44>);
extern "C" int invert_801f76e0(Ptr32<Transform>, Ptr32<const Transform>);
extern "C" Ptr32<Object> cast_8034380c(Ptr32<Object>);
extern "C" Ptr32<Object> cast_80341584(Ptr32<Object>);
struct Item { int Kind() const { return shape; } char unknown0[20]; int shape; unsigned char colour[4]; float scale; float size; float offset; };
struct ItemList { char unknown0[24]; unsigned count; char unknown28[4]; Ptr32<Item> items[1]; };
struct Flare { char unknown0[20]; Ptr32<ItemList> list; float width; float base; int active; };
extern "C" Ptr32<Flare> flare_801797b4(Ptr32<Object>);
extern "C" void trace_800b0824(Ptr32<const Vec>, Ptr32<const Vec>, Ptr32<const Vec>, int, int);
extern unsigned hits_804b1764;
extern "C" void query_801262c0(Ptr32<void>, Ptr32<const Vec>);
extern "C" void call_80126384(Ptr32<void>, Ptr32<const Vec>, int);
extern "C" int clock_801264fc(Ptr32<void>);
extern "C" void query_80126524(Ptr32<void>);
extern "C" int resize_8018920c(Ptr32<Object>, int);
struct Uv { float u, v; void Set(float a, float b) { u = a; v = b; } };
struct Pos { float x, y, z; void Set(float a, float b, float c) { x = a; y = b; z = c; } };
struct Rgba { unsigned char r, g, b; signed char a; };
extern "C" Ptr32<unsigned char> kinds_80189828(Ptr32<Object>);
extern "C" Ptr32<Rgba> colours_80189760(Ptr32<Object>);
extern "C" Ptr32<Uv> uvs_8018963c(Ptr32<Object>);
extern "C" Ptr32<Pos> positions_80189518(Ptr32<Object>);
inline unsigned char Scale(const int &c, const float &k) { return (unsigned char)((float)c * k); }
struct LensFlare { char unknown0[28]; Ptr32<void> handle; Ptr32<Object> mesh; Ptr32<Object> source; Ptr32<Flare> flare; int now; int last; float fade; };
extern const float one_80382e4c[];
extern "C" void d41m_lens_flare_update_800bf320(Ptr32<LensFlare> self) {
    Ptr32<Object> mesh = cast_8034380c(self->mesh);
    Ptr32<Flare> fl = flare_801797b4(cast_80341584(self->source));
    self->flare = fl;
    if (!fl->active) {
        ((SetFn)Slot(mesh, 88))(mesh, 0);
        return;
    }
    {
        Vec sun; *(Ptr32<Axis>)&sun = sun_8044b688;
        Vec dir;
        Vec cam(*((GetVec)Slot(scene_804b1788->camera, 56))(scene_804b1788->camera));
        Mtx44 a = *((GetMtx)Slot(scene_804b1788->camera, 24))(scene_804b1788->camera);
        Mtx44 b = *((GetMtx)Slot(scene_804b1788->camera, 32))(scene_804b1788->camera);
        Mtx44 c = *((GetMtx)Slot(scene_804b1788->camera2, 24))(scene_804b1788->camera2);
        Mtx44 d = *((GetMtx)Slot(scene_804b1788->camera2, 32))(scene_804b1788->camera2);
        Transform t0, t1, t2, t3, t4, t5;
        from44_801f74d0(&t0, &a);
        from44_801f74d0(&t1, &b);
        from44_801f74d0(&t2, &c);
        from44_801f74d0(&t3, &d);
        invert_801f76e0(&t4, &t2);
        invert_801f76e0(&t5, &t3);
        Vec v1, v2, v3;
        t0.apply(v1, sun);
        t1.apply(v2, v1);
        t5.apply(v1, v2);
        t4.apply(v3, v1);
        float px = v3.x / v3.z;
        float py = v3.y / v3.z;
        float dist = sqrt_802e82c0(px * px + py * py);
        if (dist < one_80382e4c[0]) {
            ((SetFn)Slot(mesh, 88))(mesh, 1);
            int hidden = 0;
            {
                Vec t = sun - cam;
                dir = t;
            }
            float inv = one_80382e4c[0] / sqrt_802e82c0(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
            dir.x *= inv; dir.y *= inv; dir.z *= inv;
            Vec zero;
            Ptr32<Vec> pz = &zero;
            pz->x = 0.0f; pz->y = 0.0f; pz->z = 0.0f;
            trace_800b0824(&cam, &dir, &zero, 20000, 0);
            if (hits_804b1764 <= 19999) {
                hidden = 1;
                if (self->fade == 0.0f) ((SetFn)Slot(mesh, 88))(mesh, 0);
            }
            Vec end;
            float dx = dir.x, dy = dir.y, dz = dir.z, cx = cam.x, cy = cam.y, cz = cam.z;
            end.x = dx * 20.0f + cx;
            end.y = dy * 20.0f + cy;
            end.z = dz * 20.0f + cz;
            query_801262c0(self->handle, &end);
            call_80126384(self->handle, &dir, 20000);
            if (clock_801264fc(self->handle) != 0xffff) {
                query_80126524(self->handle);
                if (self->fade == 0.0f) ((SetFn)Slot(mesh, 88))(mesh, 0);
            } else {
            query_80126524(self->handle);
            unsigned ela = self->now - self->last;
            self->last = self->now;
            float dt = (float)ela;
            float f;
            if (hidden) {
                f = self->fade;
                if (f > 0.0f) self->fade = f - dt * 0.005f;
                if (self->fade < 0.0f) self->fade = 0.0f;
            } else {
                f = self->fade;
                if (f < one_80382e4c[0]) self->fade = dt * 0.005f + f;
                if (self->fade > one_80382e4c[0]) self->fade = one_80382e4c[0];
            }
            Ptr32<Flare> g = self->flare;
            Ptr32<ItemList> list = g->list;
            unsigned n = list->count;
            Ptr32<Ptr32<Item>> items = list->items;
            float oy = px * v3.z, ox = py * v3.z;
            float nx = -oy, ny = -ox;
            resize_8018920c(mesh, n);
            float base, width;
            base = self->flare->base;
            width = self->flare->width;
            for (unsigned i = 0; i < n; i++) {
                float size = base;
                if (items[i]->shape == 0) size = (one_80382e4c[0] - dist) * 0.5f + 0.5f;
                float k;
                float s = items[i]->scale;
                if (s > one_80382e4c[0]) k = one_80382e4c[0]; else k = (one_80382e4c[0] - dist) * s;
                Ptr32<Item> it = items[i];
                Ptr32<const unsigned char> cc = it->colour;
                float off2 = it->offset;
                off2 = off2 + off2;
                float x = nx * off2 + v3.x;
                k *= self->fade;
                off2 = ny * off2 + v3.y;
                kinds_80189828(mesh)[i] = items[i]->Kind();
                Ptr32<Rgba> col = colours_80189760(mesh);
                int c0 = cc[0], c1 = cc[1], c2 = cc[2];
                col[i].r = Scale(c0, k);
                col[i].a = -1;
                col[i].g = Scale(c1, k);
                col[i].b = Scale(c2, k);
                Ptr32<Uv> uv = uvs_8018963c(mesh);
                float q = items[i]->size * size;
                ((Ptr32<Uv>)((Ptr32<char>)uv + (i << 3)))->Set(q, q);
                positions_80189518(mesh)[i].Set(x, off2, v3.z * width);
            }
            }
        } else {
            self->fade = one_80382e4c[0];
            ((SetFn)Slot(mesh, 88))(mesh, 0);
        }
    }
}



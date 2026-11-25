#include "w3d_ptr.h"
#line 1 "d29c_trail_update_800f1f70.cpp"
// d29c: 0x800f1f70. Marker trail update: spawns up to three markers along the camera direction, ages and removes old ones, fills the mesh's position, size, colour and flag arrays, then sets the billboard vectors. Names are inferred; classes are partial views.
extern "C" float sqrt_802e82c0(float);
struct W { int a, b, c; };
struct V {
    float x, y, z;
    V() {}
    V(float a, float b, float c) { x = a; y = b; z = c; }
    V(const V &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void scale(float s) { x *= s; y *= s; z *= s; }
    void set3(float a, float b, float c) { x = a; y = b; z = c; }
    void set(const V &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    V operator-(const V &o) const { V r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    bool operator==(const V &o) const { return *(Ptr32<int>)&x == *(Ptr32<int>)&o.x && *(Ptr32<int>)&y == *(Ptr32<int>)&o.y && *(Ptr32<int>)&z == *(Ptr32<int>)&o.z; }
};
struct Entry { V pos; float size; unsigned char alpha; char u[3]; };
struct Colour { signed char r, g, b; unsigned char a; void set(signed char x, signed char y, signed char z, unsigned char w) { r = x; g = y; b = z; a = w; } };
struct Size { float w, h; };
struct Mesh;
struct Trail {
    char u0[28]; Ptr32<Mesh> mesh; Entry entries[50]; unsigned count; unsigned time; char u1040[4]; int flag;
};
struct Camera { struct T { Ptr32<void> u[14]; Ptr32<Ptr32<const V> (Ptr32<Camera>)> target; Ptr32<Ptr32<const V> (Ptr32<Camera>)> eye; }; Ptr32<struct T> vt; };
struct Scene { char u[48]; Ptr32<Camera> camera; };
extern Ptr32<Scene> scene_804b1788;
extern V zero_8045e788[];
extern "C" int probe_800f235c(Ptr32<Trail>, Ptr32<V>, Ptr32<const V>, Ptr32<const V>, Ptr32<V>);
extern "C" void push_800f2810(Ptr32<Trail>, Ptr32<V>);
extern "C" void remove_800f287c(Ptr32<Trail>, unsigned);
extern "C" Ptr32<V> positions_80189518(Ptr32<Mesh>);
extern "C" Ptr32<Size> sizes_8018963c(Ptr32<Mesh>);
extern "C" Ptr32<unsigned char> flags_80189704(Ptr32<Mesh>);
extern "C" Ptr32<Colour> colours_80189760(Ptr32<Mesh>);
extern "C" int set_vectors_8018993c(Ptr32<Mesh>, Ptr32<V>, Ptr32<V>);
extern "C" Ptr32<void> memset(Ptr32<void>, int, unsigned int);
extern "C" int d29c_trail_update_800f1f70(Ptr32<Trail> self, unsigned now) {
    unsigned i;
    V f; V p; V up; V n;
    Ptr32<const V> a = scene_804b1788->camera->vt->target(scene_804b1788->camera);
    Ptr32<const V> b = scene_804b1788->camera->vt->eye(scene_804b1788->camera);
    p.x = a->x - b->x; p.y = a->y - b->y; p.z = a->z - b->z;
    f.x = p.x; f.y = p.y; f.z = p.z;
    up.set3(0.0f, 1.0f, 0.0f);
    f.normalize();
    if (self->flag == 0) {
        for (i = 0; i < 3 && self->count < 50; i++) {
            if (probe_800f235c(self, &p, a, b, &f)) push_800f2810(self, &p);
        }
    }
    {
    Ptr32<V> pos = positions_80189518(self->mesh);
    Ptr32<Size> size = sizes_8018963c(self->mesh);
    Ptr32<unsigned char> flags = flags_80189704(self->mesh);
    Ptr32<Colour> col = colours_80189760(self->mesh);
    for (i = 0; i < self->count; i++) {
        if (now > self->time) {
            self->entries[i].size += 0.4f;
            self->entries[i].alpha -= 16;
        }
        if (self->entries[i].alpha <= 10) remove_800f287c(self, i);
        *(Ptr32<W>)&pos[i] = *(Ptr32<W>)&self->entries[i].pos;
        size[i].h = size[i].w = self->entries[i].size;
        col[i].set(-1, -1, -1, self->entries[i].alpha);
    }
    f.y = 0.0f;
    if (zero_8045e788[0] == f) {
        f.set3(1.0f, 0.0f, 0.0f);
    }
    float l = f.lenSq();
    if (l == 0.0f) {
        n.set3(1.0f, 0.0f, 0.0f);
        f.set3(0.0f, 0.0f, 1.0f);
    } else {
        float s = 1.0f / sqrt_802e82c0(l);
        f.scale(s);
        const V &g = f;
        n.x = up.y * g.z - up.z * g.y;
        n.y = up.z * g.x - up.x * g.z;
        n.z = up.x * g.y - up.y * g.x;
    }
    set_vectors_8018993c(self->mesh, &n, &f);
    memset(flags, 1, self->count);
    memset(flags + self->count, 0, 50 - self->count);
    }
    if (now > self->time) self->time = now + 7;
    return 0;
}



#include "w3d_ptr.h"
#line 1 "d27d_worm_linked_step_80151ea4.cpp"
// GWMP8P rev0 0x80151ea4. Step a worm attached to a linked object: with no
// link post an empty message; find the offset to the target and detach,
// posting two messages, when it is within 10 or outside state 7 within 20
// horizontally. Otherwise evaluate the path through the anchor at the
// horizontal ratio, turn the link on or off from the height, fall speed and
// distance tests, and write the output vector: the offset, or in state 7 the
// offset times 0.0001, swapped on a sharp turn and zeroed when moving away.
// Names are inferred.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void flat(const Vec &o) { x = o.x; z = o.z; y = 0.0f; }
    void flatz(const Vec &o) { z = o.z; x = o.x; y = 0.0f; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    void unit() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    Vec &operator*=(float k) { x *= k; y *= k; z *= k; return *this; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec sub(const Vec &a, const Vec &b) { return Vec(a.x - b.x, a.y - b.y, a.z - b.z); }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline float fabs(float v) { return __builtin_fabs(v); }
struct Worm {
    char u0[312]; Vec target; char u144[28]; Vec anchor; Vec dir; char u178[184]; Vec pos; char u23c[104]; Vec vel; char u2b0[28]; int moving; char u2d0[40]; int state; char u2fc[20]; int link; char u314[36]; int flags;
};
struct Linked { char u0[72]; int active; char u4c[40]; int linked; };
struct Message { unsigned short id; Ptr32<Ptr32<void>> vtable; };
extern "C" Ptr32<Message> alloc_801613f0(Ptr32<void>, int);
extern "C" short msg_id_8015f5a0(Ptr32<void>, int);
extern "C" int post_8016239c(Ptr32<Message>);
extern "C" Ptr32<Message> init_80131b50(Ptr32<Message>, int);
extern "C" Ptr32<Linked> lookup_80164fc8(int);
extern "C" void reset_8015286c(Ptr32<Worm>);
extern "C" void pointAt_800d75f0(Ptr32<Vec>, float, Ptr32<Vec>);
extern "C" void tangentAt_800d76dc(Ptr32<Vec>, float, Ptr32<Vec>);
extern "C" void activate_800ac278(Ptr32<Linked>);
extern "C" void deactivate_800aba08(Ptr32<Linked>);
extern Ptr32<void> heap_804b1754;
extern Ptr32<Ptr32<void>> vt_8040db38[];
extern int cacheA_804afc90, cacheB_804afbf0;
struct Tuning { char u0[328]; float limit; };
extern Ptr32<Tuning> tuning_804aa6d8;
inline Ptr32<Message> init_empty(Ptr32<Message> m, unsigned short id) { m->id = id; m->vtable = (Ptr32<Ptr32<void>>)vt_8040db38; return m; }
extern "C" void d27d_worm_linked_step_80151ea4(Ptr32<Worm> self, Ptr32<Vec> out) {
    if (self->link == -1) {
        Ptr32<Message> m = alloc_801613f0(heap_804b1754, 8);
        post_8016239c(init_empty(m, msg_id_8015f5a0(&cacheA_804afc90, 1)));
        return;
    }
    Ptr32<Linked> l = lookup_80164fc8(self->link);
    Vec d = self->target - self->pos;
    Vec h;
    h.flatz(d);
    float hl = h.len();
    if (d.len() < 10.0f || (self->state != 7 && hl < 20.0f)) {
        reset_8015286c(self);
        Ptr32<Message> m = alloc_801613f0(heap_804b1754, 8);
        post_8016239c(init_empty(m, msg_id_8015f5a0(&cacheB_804afbf0, 1)));
        post_8016239c(init_80131b50(alloc_801613f0(heap_804b1754, 12), 5));
        return;
    }
    l->linked = 1;
    float zero = 0.0f;
    Vec to = self->pos - self->anchor;
    Vec fl;
    fl.flat(to);
    float along = fl.len();
    Vec df;
    df.flatz(self->dir);
    float t = along / df.len();
    Vec p1, p2;
    pointAt_800d75f0(&self->anchor, t, &p1);
    float dy = p1.y - self->pos.y;
    tangentAt_800d76dc(&self->anchor, t, &p2);
    float limit = tuning_804aa6d8->limit;
    int on = dy > zero;
    if (dy < zero && self->vel.y < zero && dy / self->vel.y < limit) on = 1;
    if (dy > 0.0f && self->vel.y > 0.0f && dy / self->vel.y < limit) on = 1;
    if (self->vel.y < -0.125f) on = 1;
    Vec sf;
    sf.flat(sub(self->target, self->anchor));
    if (along > sf.len() && self->pos.y < self->target.y && self->vel.y < 0.0f && !self->moving && self->flags >= 0) on = 1;
    if (on) {
        if (!l->active) activate_800ac278(l);
    } else {
        if (l->active) deactivate_800aba08(l);
    }
    if (self->state == 7) {
    float zero2 = 0.0f;
    *out = d * 0.0001f;
    Vec o;
    o.flat(*out);
    o.unit();
    Vec u = h;
    u.unit();
    if (o.dot(u) < -0.8f) {
        float x = out->x;
        out->x = out->z;
        out->z = x;
        return;
    }
    if (p2.y < zero2 && !on) *out *= zero2;
    Vec a;
    a.flatz(p2);
    float al = a.len();
    Vec b;
    b.flatz(self->vel);
    float bl = b.len();
    if (p2.y != 0.0f && self->vel.y != 0.0f && fabs(bl / self->vel.y) > fabs(al / p2.y)) *out *= 0.0f;
        return;
    }
    *out = d;
}



#include "w3d_ptr.h"
#line 1 "d25d_worm_aim_point_80152474.cpp"
// GWMP8P rev0 0x80152474. Worm aim point while falling: at non-positive
// vertical speed look up the target handle (+792), clear it when the object
// is gone, post a landing message when link test 0x8014dc04 fails, and drop
// the target when it is dead, above the worm or the worm is grounded or
// dying. Writes the offset to the aim point (+312) less the velocity scaled
// to the same height. Names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
struct Worm {
    unsigned char u0[312]; Vec aim;
    unsigned char u324[236]; Vec pos;
    unsigned char u572[104]; Vec vel;
    unsigned char u688[28]; int grounded;
    unsigned char u720[72]; int target;
    unsigned char u796[28]; int health;
};
struct Target { unsigned char u[72]; int alive; };
struct Message { short id; Ptr32<const void> vt; };
extern "C" void reset_8015286c(Ptr32<Worm>);
extern "C" Ptr32<void> arena_801613f0(Ptr32<void>, int);
extern "C" Ptr32<void> msg_80131b50(Ptr32<void>, int);
extern "C" int post_8016239c(Ptr32<void>);
extern "C" Ptr32<Target> lookup_80164fc8(int);
extern "C" int link_8014dc04(Ptr32<Worm>);
extern "C" short msgid_8015f5a0(Ptr32<void>, int);
extern Ptr32<void> arena_804b1754;
extern int cache_804afe04;
extern const unsigned char mvt_8040db38[];
extern "C" void d25d_worm_aim_point_80152474(Ptr32<Worm> self, Ptr32<Vec> out) {
    if (self->vel.y <= 0.0f) {
        if (self->target == -1) {
            reset_8015286c(self);
            post_8016239c(msg_80131b50(arena_801613f0(arena_804b1754, 12), 5));
        }
        Ptr32<Target> t = lookup_80164fc8(self->target);
        if (!t) { self->target = -1; return; }
        if (!link_8014dc04(self)) {
            Ptr32<Message> m = (Ptr32<Message>)arena_801613f0(arena_804b1754, 8);
            m->id = msgid_8015f5a0(&cache_804afe04, 1);
            m->vt = mvt_8040db38;
            post_8016239c(m);
            return;
        }
        Vec d = self->aim - self->pos;
        if (!t->alive || d.y > 0.0f || self->grounded || self->health < 0) {
            reset_8015286c(self);
            post_8016239c(msg_80131b50(arena_801613f0(arena_804b1754, 12), 5));
        }
        *out = d - self->vel * d.y * (1.0f / self->vel.y);
    }
}



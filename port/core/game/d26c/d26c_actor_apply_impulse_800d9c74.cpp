#include "w3d_ptr.h"
#line 1 "d26c_actor_apply_impulse_800d9c74.cpp"
// d26c: 0x800d9c74. Apply an impulse to the actor: refresh position and velocity from the virtual getters, add the
// impulse divided by the Desc speed, with the vertical part at least 0.3 of the impulse length. Names are inferred.
extern "C" float sqrt_802e82c0(float);
struct Vec3 {
    float x, y, z;
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
};
struct Desc { char u0[288]; float speed; };
struct Actor {
    struct V { Ptr32<void> u[11]; Ptr32<void (Ptr32<Actor>, int, Ptr32<Vec3>)> position; Ptr32<void (Ptr32<Actor>, int, Ptr32<Vec3>)> velocity; }; Ptr32<struct V> vtable;
    char u4[32];
    Vec3 pos;
    Vec3 vel;
    char u60[132];
    Ptr32<void> h192;
    char u196[104];
    int state;
    char u304[64];
    int when;
};
struct Context { char u0[52]; int now; };
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> desc_801797b4(Ptr32<void>);
extern "C" Ptr32<Context> ctx_80165254(void);
extern "C" void leave_800eb6e4(Ptr32<Actor>);
extern "C" void land_800d8b4c(Ptr32<Actor>);
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
extern "C" void d26c_actor_apply_impulse_800d9c74(Ptr32<Actor> self, Ptr32<const Vec3> dir) {
    Ptr32<Desc> d = desc_801797b4(empty_80341584(self->h192));
    float speed = d->speed;
    if (speed > 0.0f && dir->lenSq() > 0.0f) {
        int now = ctx_80165254()->now;
        Vec3 p, v;
        self->vtable->position(self, now, &p);
        self->vtable->velocity(self, now, &v);
        self->pos = p;
        self->vel.x = v.x + dir->x / speed;
        self->vel.z = v.z + dir->z / speed;
        float limit = dir->len() * 0.3f;
        self->vel.y = v.y + fmax(limit, dir->y) / speed;
        leave_800eb6e4(self);
        self->when = now;
        land_800d8b4c(self);
        self->state = 0;
    }
}



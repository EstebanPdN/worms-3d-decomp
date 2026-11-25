#include "w3d_ptr.h"
#line 1 "d25c_actor_move_attached_800eac84.cpp"
// d25c: 0x800eac84. Add the actor's motion for this frame to a position and hand it to its two attached
// members. Names are inferred.
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { x = o.x; y = o.y; z = o.z; }
    Vec3(float v) { x = v; y = v; z = v; }
    Vec3 &operator+=(const Vec3 &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
struct Context { char u[52]; int dt; };
struct Actor {
    struct V { Ptr32<void> u[15]; Ptr32<void (Ptr32<Actor>, int, Ptr32<Vec3>)> velocity; }; Ptr32<struct V> vtable;
    char u4[188];
    Ptr32<void> h192;
    char u196[56];
    Ptr32<void> h252;
    Ptr32<void> h256;
};
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<void> desc_801797b4(Ptr32<void>);
extern "C" Ptr32<Context> ctx_80165254(void);
extern "C" void set_801262c0(Ptr32<void>, Ptr32<Vec3>);
extern "C" void d25c_actor_move_attached_800eac84(Ptr32<Actor> self, Ptr32<const Vec3> pos) {
    desc_801797b4(empty_80341584(self->h192));
    Vec3 p(*pos);
    Vec3 v(0.0f);
    int dt = ctx_80165254()->dt;
    self->vtable->velocity(self, dt, &v);
    p += v;
    if (self->h256) set_801262c0(self->h256, &p);
    if (self->h252) set_801262c0(self->h252, &p);
}



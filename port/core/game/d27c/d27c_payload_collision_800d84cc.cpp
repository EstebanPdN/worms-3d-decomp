#include "w3d_ptr.h"
#line 1 "d27c_payload_collision_800d84cc.cpp"
// d27c: 0x800d84cc. Payload collision message: copies position and velocity from the message, then by message id shoots, fires or lands, reports a hit through its virtual, enters water, sinks or finishes, and clears its force on the last id. Names are inferred.
struct W { int a, b, c; };
struct Vec3 {
    float x, y, z;
    Vec3() {}
    void set(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
};
struct Message { unsigned short id; char u2[10]; int stamp; Vec3 pos; Vec3 vel; Vec3 arg; };
struct Desc { char u0[460]; int f460; char u464[12]; int f476; };
struct Actor;
struct ActorV { Ptr32<void> u[23]; Ptr32<void (Ptr32<Actor>, int, long long, int, Ptr32<Vec3>)> hit; };
struct Actor {
    Ptr32<ActorV> vtable; char u4[32]; Vec3 pos; Vec3 vel; Vec3 acc; char u72[12]; int stamp; int armed; char u92[100]; Ptr32<void> h192; char u196[172]; int start;
};
extern W zero_8045e788[];
extern int id_804aeb40, id_804aeb00, id_804aeb08, id_804aeb10, id_804aeb18, id_804aeb20, id_804aeb38;
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> desc_801797b4(Ptr32<void>);
extern "C" int same_8015f65c(unsigned short, Ptr32<int>);
extern "C" void shoot_800ec6a8(Ptr32<Actor>, Ptr32<Vec3>, Ptr32<Vec3>, Ptr32<Vec3>);
extern "C" void land_800d8b4c(Ptr32<Actor>);
extern "C" void fire_800d973c(Ptr32<Actor>, Ptr32<Vec3>, Ptr32<Vec3>, Ptr32<Vec3>);
extern "C" void finish_800ecb20(Ptr32<Actor>);
extern "C" void water_800ebf80(Ptr32<Actor>, Ptr32<Vec3>, Ptr32<Vec3>);
extern "C" void sink_800ec1b4(Ptr32<Actor>, Ptr32<Vec3>, Ptr32<Vec3>);
extern "C" void reset_800eba70(Ptr32<Actor>);
extern "C" void d27c_payload_collision_800d84cc(Ptr32<Actor> self, Ptr32<Message> m) {
    Vec3 v;
    Ptr32<Vec3> pv = &v;
    Ptr32<Vec3> pos = &self->pos; Ptr32<Vec3> vel = &self->vel;
    Ptr32<Desc> d = desc_801797b4(empty_80341584(self->h192));
    { const Vec3 &o = m->pos; float a = o.x, b = o.y, c = o.z; v.x = a; v.y = b; v.z = c; }
    *(Ptr32<W>)pos = *(Ptr32<W>)pv;
    { const Vec3 &o = m->vel; float a = o.x, b = o.y, c = o.z; v.x = a; v.y = b; v.z = c; }
    *(Ptr32<W>)vel = *(Ptr32<W>)pv;
    self->start = m->stamp;
    { const Vec3 &o = m->arg; float b = o.y, c = o.z, a = o.x; v.x = a; v.y = b; v.z = c; }
    unsigned short id = m->id;
    if (same_8015f65c(id, &id_804aeb40)) {
        shoot_800ec6a8(self, pos, vel, pv);
        if (vel->lenSq() > 0.0f || self->acc.lenSq() > 0.0f) land_800d8b4c(self);
    } else if (same_8015f65c(id, &id_804aeb00)) {
        if (d->f476 && self->armed) {
            fire_800d973c(self, pos, vel, pv);
        } else if (d->f460 && self->armed) {
            if (self->vel.lenSq() == 0.0f && self->acc.lenSq() == 0.0f) {
                fire_800d973c(self, &self->pos, &self->vel, &v);
            } else {
                self->stamp = -1;
                land_800d8b4c(self);
            }
        } else {
            finish_800ecb20(self);
        }
    } else if (same_8015f65c(id, &id_804aeb08)) {
        self->vtable->hit(self, 1, 0x40000000LL, self->start, pv);
    } else if (same_8015f65c(id, &id_804aeb10)) {
        water_800ebf80(self, pos, vel);
        self->pos.y -= 1.0f;
        land_800d8b4c(self);
    } else if (same_8015f65c(id, &id_804aeb18)) {
        sink_800ec1b4(self, pos, vel);
        self->pos.y -= 1.0f;
        reset_800eba70(self);
        land_800d8b4c(self);
    } else if (same_8015f65c(id, &id_804aeb20)) {
        finish_800ecb20(self);
    }
    if (same_8015f65c(id, &id_804aeb38)) {
        *(Ptr32<W>)&self->acc = zero_8045e788[0];
        land_800d8b4c(self);
    }
}



#include "w3d_ptr.h"
#line 1 "d28c_payload_stop_800d8938.cpp"
// d28c: 0x800d8938. Payload stop: posts the stop message, clears velocity and force, records the last position and the time, then fires, hands off its owner, or schedules the remaining time. Names are inferred; classes are partial views.
struct W { int a, b, c; };
struct Vec3 { float x, y, z; Vec3() {} Vec3(float v) { x = v; y = v; z = v; } };
struct Message { unsigned short id; Ptr32<Ptr32<void>> vtable; };
struct Object { struct V { Ptr32<void> u[4]; Ptr32<void (Ptr32<Object>)> release; }; Ptr32<struct V> vtable; };
struct Desc { char u0[460]; Ptr32<Object> owner; char u464[76]; int stops; };
struct Context { char u0[52]; int now; };
struct Actor {
    char u0[36]; Vec3 pos; Vec3 vel; Vec3 acc; char u72[12]; int stamp; char u88[12]; Ptr32<Object> owner; char u104[88]; Ptr32<void> h192; char u196[80];
    Vec3 lastPos; Vec3 lastVel; char u300[68]; int start; char u372[8]; int stopped;
};
extern W zero_8045e788[];
extern Ptr32<void> heap_804b1754;
extern int idA_804aeb50, idB_804aeb80, idC_804aeb00;
extern Ptr32<void> vt_8040db38[];
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> desc_801797b4(Ptr32<void>);
extern "C" Ptr32<void> alloc_801613f0(Ptr32<void>, int);
extern "C" short msg_id_8015f5a0(Ptr32<void>, int);
extern "C" Ptr32<void> init_80126000(Ptr32<void>, unsigned short, Ptr32<Vec3>);
extern "C" int post_8016239c(Ptr32<void>);
extern "C" void base_800edbbc(Ptr32<Actor>);
extern "C" void span_800ecee8(Ptr32<Actor>, int, int, Ptr32<Vec3>);
extern "C" void speed_800ecf54(Ptr32<Actor>, Ptr32<Vec3>);
extern "C" Ptr32<Context> ctx_80165254(void);
extern "C" void fire_800d973c(Ptr32<Actor>, Ptr32<Vec3>, Ptr32<Vec3>, Ptr32<Vec3>);
extern "C" void schedule_800d8ed8(Ptr32<Actor>, unsigned short, int, Ptr32<Vec3>, Ptr32<Vec3>, Ptr32<Vec3>);
extern "C" void d28c_payload_stop_800d8938(Ptr32<Actor> self) {
    Ptr32<Vec3> pos = &self->pos;
    Ptr32<Desc> d = desc_801797b4(empty_80341584(self->h192));
    Ptr32<void> n = alloc_801613f0(heap_804b1754, 20);
    post_8016239c(init_80126000(n, msg_id_8015f5a0(&idA_804aeb50, 1), pos));
    if (d->stops) base_800edbbc(self);
    Vec3 v(0.0f);
    Ptr32<Vec3> t = &self->vel;
    span_800ecee8(self, 0, 0, &v);
    Ptr32<int> p = (Ptr32<int>)&v; int a = p[0], b = p[1], c = p[2]; Ptr32<int> q = (Ptr32<int>)t; q[0] = a; q[1] = b; q[2] = c; q = (Ptr32<int>)&self->acc; q[0] = a; q[1] = b; q[2] = c;
    Ptr32<Vec3> vel = t; t = 0;
    speed_800ecf54(self, &v);
    *(Ptr32<W>)&self->lastPos = *(Ptr32<W>)pos;
    *(Ptr32<W>)&self->lastVel = zero_8045e788[0];
    self->stopped = ctx_80165254()->now;
    Ptr32<Object> o = d->owner;
    if (o && self->stamp == -1) {
        fire_800d973c(self, pos, vel, &v);
    } else {
        if (self->stamp == -1) {
            if (self->owner) self->owner->vtable->release(self->owner);
            self->owner = o;
        } else {
            int limit = self->start + 5000;
            if (self->stamp > limit) {
                self->stamp = limit;
                Ptr32<Message> m = (Ptr32<Message>)alloc_801613f0(heap_804b1754, 8);
                m->id = msg_id_8015f5a0(&idB_804aeb80, 1);
                m->vtable = vt_8040db38;
                post_8016239c(m);
            }
            int rest = self->stamp - self->start;
            schedule_800d8ed8(self, msg_id_8015f5a0(&idC_804aeb00, 1), rest, &self->pos, vel, &v);
        }
    }
}



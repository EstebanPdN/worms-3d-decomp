#include "w3d_ptr.h"
#line 1 "d26c_actor_die_or_spawn_800ed13c.cpp"
// d26c: 0x800ed13c. Either fire a final shot, or when the descriptor is of one exact type spawn a replacement, copy this
// actor's motion to it and retire. Names are inferred. Handle is the one-word ref-counted handle (virtual +12/+16) with a
// user copy constructor; the by-value argument of 0x800eb65c is the slot at sp+16, reused later for a vector.
struct Vec3 { float x, y, z; Vec3() {} Vec3(float v) { x = v; y = v; z = v; } };
struct Type;
struct Object {
    struct V { Ptr32<void> u0[3]; Ptr32<void (Ptr32<Object>)> add_ref; Ptr32<void (Ptr32<Object>)> release; Ptr32<Ptr32<const Type> (Ptr32<Object>)> type; }; Ptr32<struct V> vtable;
};
struct Handle {
    Ptr32<Object> p;
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Object *)w3d_p.get()) {}
 Handle(Object *o) { p = o; if (o) o->vtable->add_ref(o); }
    Handle(const Handle &);
    ~Handle() { if (p) p->vtable->release(p); }
};
struct Spawned : Object { };
struct Desc : Object { char u4[452] __attribute__((aligned(__alignof__(Object)))); int f456; };
struct Actor {
    struct V { Ptr32<void> u[11]; Ptr32<void (Ptr32<Actor>, int, Ptr32<Vec3>)> position; Ptr32<void (Ptr32<Actor>, int, Ptr32<Vec3>)> velocity; Ptr32<void (Ptr32<Actor>, int, Ptr32<Vec3>)> rotation; }; Ptr32<struct V> vtable;
    char u4[80];
    int w84;
    char u88[104];
    Ptr32<Object> h192;
};
struct Context { char u0[52]; int now; };
struct Item {
    struct V { Ptr32<void> u[10]; Ptr32<void (Ptr32<Item>, Ptr32<Vec3>)> set_rotation; }; Ptr32<struct V> vtable;
    char u4[28];
    int w32;
};
struct Owner { char u0[20]; int id; };
extern Ptr32<Owner> owner_804aab4c;
extern Ptr32<void> service_804b178c;
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> desc_801797b4(Ptr32<void>);
extern "C" Ptr32<Context> ctx_80165254(void);
extern "C" void shoot_800ec6a8(Ptr32<Actor>, Ptr32<Vec3>, Ptr32<Vec3>, Ptr32<Vec3>);
extern "C" Ptr32<Object> forward_8020b680(Ptr32<const void>);
extern "C" void assign_800eb65c(Ptr32<Object>, Handle);
extern "C" void copy_800eb8d0(Ptr32<Object>, Ptr32<Vec3>);
extern "C" void copy_800eb8f0(Ptr32<Object>, Ptr32<Vec3>);
extern "C" int attach_80164514(Ptr32<void>, Ptr32<Object>, int);
extern "C" void finish_8015fd1c(Ptr32<Actor>);
extern const Type type_80368418[];
extern char key_8040f038[];
extern "C" void d26c_actor_die_or_spawn_800ed13c(Ptr32<Actor> self) {
    Ptr32<Desc> d = desc_801797b4(empty_80341584(self->h192));
    if (d->f456) {
        int now = ctx_80165254()->now;
        Vec3 p, v;
        self->vtable->position(self, now, &p);
        self->vtable->velocity(self, now, &v);
        Vec3 z(0.0f);
        shoot_800ec6a8(self, &p, &v, &z);
    } else if (d->vtable->type(d) == type_80368418) {
        Handle h(forward_8020b680(key_8040f038));
        assign_800eb65c(h.p, Handle(self->h192));
        int now = ctx_80165254()->now;
        Vec3 p, r, v;
        self->vtable->position(self, now, &p);
        self->vtable->rotation(self, now, &r);
        self->vtable->velocity(self, now, &v);
        copy_800eb8d0(h.p, &p);
        Ptr32<Item> it = (Ptr32<Item>)h.p;
        it->vtable->set_rotation(it, &r);
        copy_800eb8f0(h.p, &v);
        { int w = self->w84; Ptr32<Item> i2 = (Ptr32<Item>)h.p; if (w >= 0) w -= now; i2->w32 = w; }
        attach_80164514(service_804b178c, h.p, owner_804aab4c->id);
        finish_8015fd1c(self);
    }
}



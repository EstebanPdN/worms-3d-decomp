// d26c: 0x800ed13c. Either fire a final shot, or when the descriptor is of one exact type spawn a replacement, copy this
// actor's motion to it and retire. Names are inferred. Handle is the one-word ref-counted handle (virtual +12/+16) with a
// user copy constructor; the by-value argument of 0x800eb65c is the slot at sp+16, reused later for a vector.
struct Vec3 { float x, y, z; Vec3() {} Vec3(float v) { x = v; y = v; z = v; } };
struct Type;
struct Object {
    struct V { void *u0[3]; void (*add_ref)(Object *); void (*release)(Object *); const Type *(*type)(Object *); } *vtable;
};
struct Handle {
    Object *p;
    Handle(Object *o) { p = o; if (o) o->vtable->add_ref(o); }
    Handle(const Handle &);
    ~Handle() { if (p) p->vtable->release(p); }
};
struct Spawned : Object { };
struct Desc : Object { char u4[452]; int f456; };
struct Actor {
    struct V { void *u[11]; void (*position)(Actor *, int, Vec3 *); void (*velocity)(Actor *, int, Vec3 *); void (*rotation)(Actor *, int, Vec3 *); } *vtable;
    char u4[80];
    int w84;
    char u88[104];
    Object *h192;
};
struct Context { char u0[52]; int now; };
struct Item {
    struct V { void *u[10]; void (*set_rotation)(Item *, Vec3 *); } *vtable;
    char u4[28];
    int w32;
};
struct Owner { char u0[20]; int id; };
extern Owner *owner_804aab4c;
extern void *service_804b178c;
extern "C" void *empty_80341584(void *);
extern "C" Desc *desc_801797b4(void *);
extern "C" Context *ctx_80165254(void);
extern "C" void shoot_800ec6a8(Actor *, Vec3 *, Vec3 *, Vec3 *);
extern "C" Object *forward_8020b680(const void *);
extern "C" void assign_800eb65c(Object *, Handle);
extern "C" void copy_800eb8d0(Object *, Vec3 *);
extern "C" void copy_800eb8f0(Object *, Vec3 *);
extern "C" int attach_80164514(void *, Object *, int);
extern "C" void finish_8015fd1c(Actor *);
extern const Type type_80368418[];
extern char key_8040f038[];
extern "C" void d26c_actor_die_or_spawn_800ed13c(Actor *self) {
    Desc *d = desc_801797b4(empty_80341584(self->h192));
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
        Item *it = (Item *)h.p;
        it->vtable->set_rotation(it, &r);
        copy_800eb8f0(h.p, &v);
        { int w = self->w84; Item *i2 = (Item *)h.p; if (w >= 0) w -= now; i2->w32 = w; }
        attach_80164514(service_804b178c, h.p, owner_804aab4c->id);
        finish_8015fd1c(self);
    }
}

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
    struct V { void *u[15]; void (*velocity)(Actor *, int, Vec3 *); } *vtable;
    char u4[188];
    void *h192;
    char u196[56];
    void *h252;
    void *h256;
};
extern "C" void *empty_80341584(void *);
extern "C" void *desc_801797b4(void *);
extern "C" Context *ctx_80165254(void);
extern "C" void set_801262c0(void *, Vec3 *);
extern "C" void d25c_actor_move_attached_800eac84(Actor *self, const Vec3 *pos) {
    desc_801797b4(empty_80341584(self->h192));
    Vec3 p(*pos);
    Vec3 v(0.0f);
    int dt = ctx_80165254()->dt;
    self->vtable->velocity(self, dt, &v);
    p += v;
    if (self->h256) set_801262c0(self->h256, &p);
    if (self->h252) set_801262c0(self->h252, &p);
}

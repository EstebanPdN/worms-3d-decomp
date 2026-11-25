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
    struct V { void *u[11]; void (*position)(Actor *, int, Vec3 *); void (*velocity)(Actor *, int, Vec3 *); } *vtable;
    char u4[32];
    Vec3 pos;
    Vec3 vel;
    char u60[132];
    void *h192;
    char u196[104];
    int state;
    char u304[64];
    int when;
};
struct Context { char u0[52]; int now; };
extern "C" void *empty_80341584(void *);
extern "C" Desc *desc_801797b4(void *);
extern "C" Context *ctx_80165254(void);
extern "C" void leave_800eb6e4(Actor *);
extern "C" void land_800d8b4c(Actor *);
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
extern "C" void d26c_actor_apply_impulse_800d9c74(Actor *self, const Vec3 *dir) {
    Desc *d = desc_801797b4(empty_80341584(self->h192));
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

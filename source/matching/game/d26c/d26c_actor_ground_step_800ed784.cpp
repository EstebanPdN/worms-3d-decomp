// d26c: 0x800ed784. Look for a contact along the actor's motion; on a hit or a settled position hand it to the
// virtual landing handler, otherwise run the airborne step. Names are inferred. The out int and the long long
// are witnessed by 0x800ea748 writing one word through r8 and two words (high 0) through r9.
struct Vec3 { float x, y, z; };
struct Actor {
    struct V {
        void *u[16];
        int (*settle)(Actor *, Vec3 *, Vec3 *, Vec3 *, Vec3 *);
        void *u68[4];
        void (*land)(Actor *, long long, Vec3 *, Vec3 *, Vec3 *);
    } *vtable;
    char u4[32];
    Vec3 pos;
    Vec3 vel;
};
extern "C" int find_800ea748(Actor *, Vec3 *, Vec3 *, Vec3 *, Vec3 *, int *, long long *);
extern "C" int fall_800eaf14(Actor *);
extern "C" void d26c_actor_ground_step_800ed784(Actor *self) {
    Vec3 a, b;
    int id;
    long long t;
    if (find_800ea748(self, &self->pos, &self->vel, &a, &b, &id, &t)) {
        self->vtable->land(self, t, &b, &self->vel, &a);
    } else if (self->vtable->settle(self, &self->pos, &self->vel, &a, &b)) {
        self->vtable->land(self, 0x40000000LL, &b, &self->vel, &a);
    } else {
        fall_800eaf14(self);
    }
}

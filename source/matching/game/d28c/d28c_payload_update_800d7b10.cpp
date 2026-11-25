// d28c: 0x800d7b10. Payload update: when at rest, re-checks its position and may schedule the fuse; otherwise asks the virtuals for position and velocity, moves, may land, and probes for a hit. Names are inferred; classes are partial views.
struct W { int a, b, c; };
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void set(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
};
struct Actor {
    struct V { void *u[11]; void (*position)(Actor *, int, Vec3 *); void (*velocity)(Actor *, int, Vec3 *); void *u52[10]; void (*hit)(Actor *, int, long long, int, Vec3 *); } *vtable;
    char u4[32];
    Vec3 pos;
    Vec3 vel;
    Vec3 acc;
    char u72[12];
    int stamp;
    char u88[104];
    void *h192;
    char u196[172];
    int start;
};
extern Vec3 zero_8045e788[];
extern int result_804b1944;
extern int msgid_804aeb00;
extern "C" int timer_8006e71c(Actor *);
extern "C" void *empty_80341584(void *);
extern "C" void *desc_801797b4(void *);
extern "C" void move_800eac84(Actor *, const Vec3 *);
extern "C" int check_800eabb0(Actor *, int, Vec3 *, Vec3 *);
extern "C" short msg_id_8015f5a0(void *, int);
extern "C" void schedule_800d8ed8(Actor *, unsigned short, int, Vec3 *, Vec3 *, Vec3 *);
extern "C" void land_800d8b4c(Actor *);
extern "C" int probe_800ea748(Actor *, Vec3 *, Vec3 *, Vec3 *, Vec3 *, int *, long long *);
extern "C" void distance_800ed860(Vec3 *, Vec3 *);
extern "C" int d28c_payload_update_800d7b10(Actor *self, int now) {
    if (timer_8006e71c(self)) return 20;
    desc_801797b4(empty_80341584(self->h192));
    Vec3 p, v, a, b;
    int c;
    long long e;
    Vec3 *vp;
    if (self->vel.lenSq() == 0.0f && self->acc.lenSq() == 0.0f) {
        *(W *)&p = *(W *)&self->pos;
        Vec3 *t = &v;
        *(W *)t = *(W *)&zero_8045e788[0];
        move_800eac84(self, &p);
        int hit = check_800eabb0(self, now, &p, t);
        vp = t; t = 0;
        if (hit) {
            int d = self->stamp - self->start;
            unsigned short id = msg_id_8015f5a0(&msgid_804aeb00, 1);
            b.set(zero_8045e788[0]);
            schedule_800d8ed8(self, id, d, &self->pos, &self->vel, &b);
        }
    } else {
        self->vtable->position(self, now, &p);
        Vec3 *t = &v;
        self->vtable->velocity(self, now, t);
        move_800eac84(self, &p);
        int hit = check_800eabb0(self, now, &p, t);
        vp = t; t = 0;
        if (hit) land_800d8b4c(self);
        if (probe_800ea748(self, &p, vp, &a, &b, &c, &e)) {
            *(W *)&self->pos = *(W *)&b;
            self->start = now;
            *(W *)&self->vel = *(W *)vp;
            self->vtable->hit(self, 0, e, now, &a);
        }
    }
    distance_800ed860(&p, vp);
    return result_804b1944;
}

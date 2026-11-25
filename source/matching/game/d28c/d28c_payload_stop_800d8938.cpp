// d28c: 0x800d8938. Payload stop: posts the stop message, clears velocity and force, records the last position and the time, then fires, hands off its owner, or schedules the remaining time. Names are inferred; classes are partial views.
struct W { int a, b, c; };
struct Vec3 { float x, y, z; Vec3() {} Vec3(float v) { x = v; y = v; z = v; } };
struct Message { unsigned short id; void **vtable; };
struct Object { struct V { void *u[4]; void (*release)(Object *); } *vtable; };
struct Desc { char u0[460]; Object *owner; char u464[76]; int stops; };
struct Context { char u0[52]; int now; };
struct Actor {
    char u0[36]; Vec3 pos; Vec3 vel; Vec3 acc; char u72[12]; int stamp; char u88[12]; Object *owner; char u104[88]; void *h192; char u196[80];
    Vec3 lastPos; Vec3 lastVel; char u300[68]; int start; char u372[8]; int stopped;
};
extern W zero_8045e788[];
extern void *heap_804b1754;
extern int idA_804aeb50, idB_804aeb80, idC_804aeb00;
extern void *vt_8040db38[];
extern "C" void *empty_80341584(void *);
extern "C" Desc *desc_801797b4(void *);
extern "C" void *alloc_801613f0(void *, int);
extern "C" short msg_id_8015f5a0(void *, int);
extern "C" void *init_80126000(void *, unsigned short, Vec3 *);
extern "C" int post_8016239c(void *);
extern "C" void base_800edbbc(Actor *);
extern "C" void span_800ecee8(Actor *, int, int, Vec3 *);
extern "C" void speed_800ecf54(Actor *, Vec3 *);
extern "C" Context *ctx_80165254(void);
extern "C" void fire_800d973c(Actor *, Vec3 *, Vec3 *, Vec3 *);
extern "C" void schedule_800d8ed8(Actor *, unsigned short, int, Vec3 *, Vec3 *, Vec3 *);
extern "C" void d28c_payload_stop_800d8938(Actor *self) {
    Vec3 *pos = &self->pos;
    Desc *d = desc_801797b4(empty_80341584(self->h192));
    void *n = alloc_801613f0(heap_804b1754, 20);
    post_8016239c(init_80126000(n, msg_id_8015f5a0(&idA_804aeb50, 1), pos));
    if (d->stops) base_800edbbc(self);
    Vec3 v(0.0f);
    Vec3 *t = &self->vel;
    span_800ecee8(self, 0, 0, &v);
    int *p = (int *)&v; int a = p[0], b = p[1], c = p[2]; int *q = (int *)t; q[0] = a; q[1] = b; q[2] = c; q = (int *)&self->acc; q[0] = a; q[1] = b; q[2] = c;
    Vec3 *vel = t; t = 0;
    speed_800ecf54(self, &v);
    *(W *)&self->lastPos = *(W *)pos;
    *(W *)&self->lastVel = zero_8045e788[0];
    self->stopped = ctx_80165254()->now;
    Object *o = d->owner;
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
                Message *m = (Message *)alloc_801613f0(heap_804b1754, 8);
                m->id = msg_id_8015f5a0(&idB_804aeb80, 1);
                m->vtable = vt_8040db38;
                post_8016239c(m);
            }
            int rest = self->stamp - self->start;
            schedule_800d8ed8(self, msg_id_8015f5a0(&idC_804aeb00, 1), rest, &self->pos, vel, &v);
        }
    }
}

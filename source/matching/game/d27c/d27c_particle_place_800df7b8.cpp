// d27c: 0x800df7b8. Places a particle by its mode flags: at a service position, by constant acceleration from its age, on a circle around its owner, or at its start point. Names are inferred.
extern "C" float sin_802e88ac(float);
extern "C" float cos_802e86d4(float);
struct Vec3 {
    float x, y, z;
    Vec3 &operator+=(const Vec3 &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
struct Provider { struct V { void *u[14]; const Vec3 &(*position)(Provider *); } *vtable; };
struct Desc { char u0[104]; Vec3 at104; char u116[12]; Vec3 offset; };
struct Owner { char u0[68]; Vec3 rot; Vec3 base; };
struct Self {
    char u0[16]; int age; char u20[16]; float radius; char u40[4]; Vec3 acc; Vec3 vel; Vec3 start; Vec3 at;
    char u92[36]; void *h128; char u132[4]; void *h136; char u140[12]; unsigned flags;
};
struct Sink;
struct SinkV { void *u[6]; void (*place)(Sink *, const Vec3 *, const Vec3 *); };
struct Sink { char u0[112]; SinkV *vtable; };
extern void *svc_804b1788;
extern float lift_80389cbc[];
extern "C" void *empty_80341584(void *);
extern "C" Desc *desc_801797b4(void *);
extern "C" Provider *request_8015cd04(void *, int);
extern "C" void *empty_80342a74(void *);
extern "C" float value_80178df0(void *);
extern "C" Owner *owner_800dfdf4(Self *);
extern "C" void d27c_particle_place_800df7b8(Self *self, Sink *sink) {
    Desc *d = desc_801797b4(empty_80341584(self->h128));
    if (self->flags & 128) {
        Provider *p = request_8015cd04(svc_804b1788, 4);
        self->at = p->vtable->position(p);
        self->at.y += lift_80389cbc[0];
    } else if (self->flags & 2) {
        int age = self->age;
        float t = age;
        float h = (age * age) * 0.5f;
        self->at.x = h * self->vel.x + (self->acc.x * t + self->start.x);
        self->at.y = h * self->vel.y + (self->acc.y * t + self->start.y);
        self->at.z = h * self->vel.z + (self->acc.z * t + self->start.z);
        sink->vtable->place(sink, &self->at, &d->at104);
    } else if (self->flags & 512) {
        value_80178df0(empty_80342a74(self->h136));
        Owner *o = owner_800dfdf4(self);
        const Vec3 &rot = o->rot;
        self->at.x = self->radius * sin_802e88ac(rot.y);
        self->at.y = value_80178df0(empty_80342a74(self->h136));
        self->at.z = self->radius * cos_802e86d4(rot.y);
        self->at += o->base;
        self->at += d->offset;
    } else {
        self->at = self->start;
    }
}

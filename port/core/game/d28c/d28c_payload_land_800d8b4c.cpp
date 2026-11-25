#include "w3d_ptr.h"
#line 1 "d28c_payload_land_800d8b4c.cpp"
// d28c: 0x800d8b4c. Payload landing step: queries the deadline, boundary, rise, drop and limit heights for the nearest hit, keeps the hit data, then finishes or schedules it. Names are inferred; classes are partial views.
struct Vec3 { float x, y, z; Vec3() {} Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
static inline void use(Vec3 v) {}
static inline Vec3 scaled(const Vec3 &a, float s) { Vec3 r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
struct Desc { char u0[220]; float rise; char u224[100]; float drop; char u328[144]; int f472; };
struct Obj { struct V { Ptr32<void> u[8]; Ptr32<void (Ptr32<Obj>)> touch; }; Ptr32<struct V> vtable; };
struct Actor {
    Ptr32<void> vtable; char u4[32]; Vec3 pos; Vec3 vel; Vec3 acc; char u72[12]; int f84; char u88[92];
    Ptr32<void> h180; char u184[4]; Ptr32<void> h188; Ptr32<Obj> h192; char u196[80]; Vec3 v276; Vec3 v288; char u300[68]; int f368; char u372[8]; int best;
};
extern int id_804aeb08, id_804aeb10, id_804aeb18, id_804aeb20;
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<void> empty_80342a74(Ptr32<void>);
extern "C" Ptr32<Desc> desc_801797b4(Ptr32<void>);
extern "C" float value_80178df0(Ptr32<void>);
extern "C" int cached_id_8015f5a0(Ptr32<int>, int);
extern "C" int same_8015f65c(unsigned short, Ptr32<int>);
extern "C" void query_800d93d0(Ptr32<Actor>, Ptr32<unsigned short>, Ptr32<int>, Ptr32<Vec3>, Ptr32<Vec3>, Ptr32<Vec3>);
extern "C" void boundary_800d92a8(Ptr32<Actor>, Ptr32<unsigned short>, Ptr32<int>, Ptr32<Vec3>, Ptr32<Vec3>);
extern "C" void record_800d8fdc(Ptr32<Actor>, unsigned short, Ptr32<unsigned short>, Ptr32<int>, Ptr32<Vec3>, Ptr32<Vec3>, Ptr32<Vec3>, float);
extern "C" void arrive_800d911c(Ptr32<Actor>, Ptr32<unsigned short>, Ptr32<int>, Ptr32<Vec3>, Ptr32<Vec3>, Ptr32<Vec3>);
extern "C" void fn_800d8938(Ptr32<Actor>);
extern "C" void fn_8015fd1c(Ptr32<Actor>);
extern "C" void span_800ecee8(Ptr32<Actor>, int, int, Ptr32<Vec3>);
extern "C" void schedule_800d8ed8(Ptr32<Actor>, unsigned short, int, Ptr32<Vec3>, Ptr32<Vec3>, Ptr32<Vec3>);
extern "C" void d28c_payload_land_800d8b4c(Ptr32<Actor> self) {
    Vec3 n, b, c;
    unsigned short id;
    int best;
    Ptr32<Desc> d = desc_801797b4(empty_80341584(self->h192));
    id = 0;
    best = -1;
    float lo = value_80178df0(empty_80342a74(self->h180));
    float hi = value_80178df0(empty_80342a74(self->h188));
    if (self->f84 > 0) {
        query_800d93d0(self, &id, &best, &n, &b, &c);
        self->v276 = n;
        self->v288 = b;
        self->best = best;
    }
    boundary_800d92a8(self, &id, &best, &n, &b);
    record_800d8fdc(self, cached_id_8015f5a0(&id_804aeb10, 1), &id, &best, &n, &b, &c, lo + d->rise);
    if (same_8015f65c(id, &id_804aeb10)) {
        self->v276 = n;
        self->v288 = b;
        self->best = best;
    }
    record_800d8fdc(self, cached_id_8015f5a0(&id_804aeb18, 1), &id, &best, &n, &b, &c, lo - d->drop);
    record_800d8fdc(self, cached_id_8015f5a0(&id_804aeb20, 1), &id, &best, &n, &b, &c, hi);
    if (best > 0) {
        arrive_800d911c(self, &id, &best, &n, &b, &c);
        if (same_8015f65c(id, &id_804aeb08)) {
            self->v276 = n;
            self->v288 = b;
            self->best = best;
        }
        if (best == 0 && d->f472 == 0) {
            fn_800d8938(self);
            return;
        }
    }
    if (id == 0 || best == -1) {
        self->h192->vtable->touch(self->h192);
        use(self->pos);
        use(self->vel);
        use(self->acc);
        fn_8015fd1c(self);
    }
    Vec3 v = scaled(c, d->rise);
    span_800ecee8(self, self->f368, best, &v);
    schedule_800d8ed8(self, id, best, &n, &b, &c);
}



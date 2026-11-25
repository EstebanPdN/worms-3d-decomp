#include "w3d_ptr.h"
#line 1 "d31h_actor_step_probe_800af6b4.cpp"
// GWMP8P rev0 0x800af6b4. Actor step decision. Names are inferred. Reads the
// message id and the actor's parameters, then chooses a step vector: when
// the input's y is negative it backs away along the negated velocity;
// otherwise it probes forward from a lerped height with 0x800afb78, falls
// back to a lower probe and second message id when the first fails or the
// actor is above the global view position by more than the limit, or when
// too few samples hit it probes backward then along the negated velocity,
// and stores the direction when a random draw is under the store chance. It
// then probes the chosen step, posts a message with the sample count and
// starts landing, or stops when nothing hit. Class layouts are partial
// views.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator-() const { return Vec(-x, -y, -z); }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void Normalize() { float i = 1.0f / len(); x *= i; y *= i; z *= i; }
};
struct Params { char unknown0[508]; int alt; char unknown512[32]; unsigned minCount; float storeChance; float maxDrop; float a556; float a560; float a564; float a568; float a572; float a576; };
struct Actor { char unknown0[36]; Vec pos; Vec vel; char unknown60[12]; Vec dir; char unknown84[108]; Ptr32<void> owner; };
struct Msg;
extern "C" unsigned message_id_8015f5a0(Ptr32<int>, int);
extern "C" Ptr32<void> owner_80341584(Ptr32<void>);
extern "C" Ptr32<Params> params_801797b4(Ptr32<void>);
extern "C" float random_801610a0(Ptr32<Actor>);
extern "C" float lerp_800afc8c(Ptr32<Actor>, float, float);
extern "C" int query_800afb78(Ptr32<Actor>, Ptr32<const Vec>, Ptr32<const Vec>, Ptr32<unsigned int>, Ptr32<int>);
extern "C" void fire_800d973c(Ptr32<Actor>, Ptr32<Vec>, Ptr32<Vec>, Ptr32<const Vec>);
extern "C" Ptr32<void> alloc_801613f0(Ptr32<void>, int);
extern "C" Ptr32<Msg> init_80125fdc(Ptr32<void>, unsigned short, unsigned);
extern "C" void post_8015fc58(Ptr32<Actor>, Ptr32<Msg>);
extern "C" void land_800d8b4c(Ptr32<Actor>);
extern "C" void stop_800d8938(Ptr32<Actor>);
extern int lbl_804ae42c;
extern int lbl_804ae424;
extern Ptr32<void> lbl_804b1754;
extern Vec lbl_8043ae20[];
extern "C" void d31h_actor_step_probe_800af6b4(Ptr32<Actor> self, Ptr32<const Vec> in) {
    unsigned short id = message_id_8015f5a0(&lbl_804ae42c, 1);
    Ptr32<Params> p = params_801797b4(owner_80341584(self->owner));
    Vec u;
    unsigned count;
    int flag = in->y < 0.0f;
    if (flag) {
        if (p->alt) { fire_800d973c(self, &self->pos, &self->vel, in); return; }
        u = Vec(-self->vel.x, -self->vel.y, -self->vel.z);
        if (random_801610a0(self) < p->storeChance) self->dir = u;
    } else {
        Vec &dir = self->dir;
        Vec d;
        d.x = dir.x; d.z = dir.z; d.y = 0.0f;
        d.Normalize();
        float k = p->a576;
        float h = lerp_800afc8c(self, p->a572, p->a568);
        {
            Vec t;
            t.x = k * d.x; t.y = h; t.z = k * d.z;
            u = t;
        }
        int hit = query_800afb78(self, &self->pos, &u, &count, &flag);
        Vec g = lbl_8043ae20[0];
        int far = self->pos.y - g.y > p->maxDrop;
        if (hit == 0 || far) {
            k = p->a564;
            h = lerp_800afc8c(self, p->a560, p->a556);
            Vec w;
            w.x = k * d.x; w.y = h; w.z = k * d.z;
            u = w;
            id = message_id_8015f5a0(&lbl_804ae424, 1);
        } else {
        unsigned lim = p->minCount;
        if (count < lim) {
            if (p->alt) { fire_800d973c(self, &self->pos, &self->vel, in); return; }
            float n = -p->a576;
            {
                Vec w(n * d.x, p->a568, n * d.z);
                u = w;
            }
            query_800afb78(self, &self->pos, &u, &count, &flag);
            lim = p->minCount;
            if (count < lim) {
                u = Vec(-self->vel.x, -self->vel.y, -self->vel.z);
                query_800afb78(self, &self->pos, &u, &count, &flag);
            }
            if (random_801610a0(self) < p->storeChance) dir = u;
        } else {
            k = p->a576;
            Vec w(k * d.x, p->a572, k * d.z);
            query_800afb78(self, &g, &w, &count, &flag);
            lim = p->minCount;
            if (count < lim) {
                k = p->a564;
                h = lerp_800afc8c(self, p->a560, p->a556);
                Vec e;
                e.x = k * d.x; e.y = h; e.z = k * d.z;
                u = e;
                id = message_id_8015f5a0(&lbl_804ae424, 1);
            }
        }
        }
    }
    query_800afb78(self, &self->pos, &u, &count, &flag);
    if (count) {
        post_8015fc58(self, init_80125fdc(alloc_801613f0(lbl_804b1754, 12), id, count));
        self->vel = u;
        land_800d8b4c(self);
    } else {
        stop_800d8938(self);
    }
}



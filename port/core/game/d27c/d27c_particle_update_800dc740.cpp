#include "w3d_ptr.h"
#line 1 "d27c_particle_update_800dc740.cpp"
// d27c: 0x800dc740. Updates one particle in a batch's parallel arrays: expiry, position, optional pull and jitter, water or height kill test, colour, orientation, animation and spin, then the alive flag and angle. Names are inferred; State is a partial view.
struct W { int a, b, c; };
struct Vec3 { float x, y, z; };
struct Pair { int a, b; };
struct Part;
struct PartV { Ptr32<void> u[9]; Ptr32<void (Ptr32<Part>, unsigned int, Ptr32<Vec3>, Ptr32<void>, int)> move; Ptr32<void> u40; Ptr32<void (Ptr32<Part>, unsigned int, Ptr32<int>, Ptr32<void>)> color; };
struct Part { W pos; char u12[80]; int dur; char u96[4]; unsigned start; unsigned char active; char u105[7]; Ptr32<PartV> vtable; };
struct Desc { char u0[420]; unsigned short forever; char u422[10]; int above; char u436[12]; int immortal; char u452[20]; int follow; };
struct State {
    unsigned flags; int index; Ptr32<Vec3> pos; Ptr32<int> color; Ptr32<Vec3> orient; Ptr32<float> angle; Ptr32<char> bytes; Ptr32<Pair> spin; Ptr32<char> alive; int spawning; unsigned char byte; char u41[3];
    W at; Ptr32<void> h56; Ptr32<void> h60; Ptr32<void> h64; Ptr32<Vec3> target; unsigned char wide;
};
extern "C" Ptr32<void> empty_80342fa4(Ptr32<void>);
extern "C" Ptr32<Vec3> vec_80178ec4(Ptr32<void>);
extern "C" Ptr32<void> cast_80342a78(Ptr32<void>);
extern "C" int value_80178d1c(Ptr32<void>);
extern "C" void pull_800dfe84(Ptr32<Part>, Ptr32<Vec3>, unsigned, Ptr32<Vec3>, int);
extern "C" float fraction_800de5b4(Ptr32<Part>, unsigned);
extern "C" void jitter_800dff7c(Ptr32<Vec3>, Ptr32<Vec3>, float, Ptr32<Desc>);
extern "C" Ptr32<void> empty_80342a74(Ptr32<void>);
extern "C" float fvalue_80178df0(Ptr32<void>);
extern "C" void orient_800de40c(Ptr32<Part>, unsigned, Ptr32<Vec3>, Ptr32<Desc>);
extern "C" void anim_800de4c4(Ptr32<Part>, unsigned, Ptr32<char>, Ptr32<Desc>, unsigned char);
extern "C" void timed_800ddcbc(Ptr32<Part>, unsigned, Ptr32<Pair>, Ptr32<Desc>, int, Ptr32<Vec3>);
extern "C" unsigned char d27c_particle_update_800dc740(Ptr32<Part> self, unsigned now, Ptr32<State> st, Ptr32<Desc> d) {
    if (!self->active) return 0;
    if (d->forever != 0xffff && now >= self->start + self->dur) {
        st->alive[st->index] = 0;
        self->active = 0;
        return 0;
    }
    if (st->flags & 32) self->pos = st->at;
    self->vtable->move(self, now, &st->pos[st->index], d, 0);
    if (st->flags & 8) {
        Ptr32<Vec3> p = &st->pos[st->index];
        Ptr32<Vec3> t = vec_80178ec4(empty_80342fa4(st->h60));
        pull_800dfe84(self, p, now, t, value_80178d1c(cast_80342a78(st->h64)));
    }
    if (st->flags & 1024) {
        Ptr32<Vec3> p = &st->pos[st->index];
        float f = fraction_800de5b4(self, now);
        jitter_800dff7c(p, st->target, f, d);
    }
    {
        float h = fvalue_80178df0(empty_80342a74(st->h56));
        bool dead = st->pos[st->index].y < h;
        if (d->above) dead = !dead;
        else if (d->immortal) dead = false;
        if (dead) {
            self->active = 0;
            st->alive[st->index] = 0;
        } else {
            Vec3 v;
            self->vtable->color(self, now, &st->color[st->index], d);
            orient_800de40c(self, now, st->orient, d);
            anim_800de4c4(self, now, st->bytes + st->index, d, st->byte);
            timed_800ddcbc(self, now, &st->spin[st->index], d, st->wide != 0, &v);
            if (d->follow) st->pos[st->index].y -= v.y;
            st->alive[st->index] = st->spawning == 0;
            st->angle[st->index] = st->orient->z;
        }
    }
    return self->active;
}



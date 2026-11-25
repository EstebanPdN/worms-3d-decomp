#include "w3d_ptr.h"
#line 1 "d31c_emitter_render_update_800e2a28.cpp"
// d31c: 0x800e2a28. Emitter render update: reads the mesh arrays or per-part sinks, starts the emitter once, then updates every active part's position, colour, orientation, animation and timing. Names are inferred; classes are partial views.
// Emitter render update.
struct Vec3 { float x, y, z; };
struct Pair { float a, b; };
struct Rgba4 { float r, g, b, a; Rgba4(float v) { r = v; g = v; b = v; a = v; } };
struct Part;
struct PartV { Ptr32<void> u[9]; Ptr32<void (Ptr32<Part>, unsigned int, Ptr32<Vec3>, Ptr32<void>, int)> move; Ptr32<void> u40; Ptr32<void (Ptr32<Part>, unsigned int, Ptr32<void>, Ptr32<void>)> color; };
struct Part { char u0[104]; unsigned char active; char u105[7]; Ptr32<PartV> vtable; bool Active() { bool on = true; if (!active) on = false; return on; } };
struct Desc { char u0[284]; float f284; char u288[184]; int follow; };
struct Mesh;
struct GroupV { Ptr32<void> u[5]; Ptr32<Ptr32<Part> (Ptr32<struct Group>, unsigned int)> at; };
struct Group { Ptr32<GroupV> vt; };
struct Emitter { char u0[32]; Ptr32<Group> group; char u36[104]; unsigned count; char u144[12]; Ptr32<void> owner; char u160[12]; int mode; char u176[4]; unsigned flags; char u184[32]; bool still; char u220[20]; Ptr32<void> h240; Ptr32<void> h244; };
struct Sink;
struct SinkV { Ptr32<void> u[19]; Ptr32<int (Ptr32<Sink>, Ptr32<Vec3>, int)> a; Ptr32<int (Ptr32<Sink>, Ptr32<Vec3>, int)> b; Ptr32<int (Ptr32<Sink>, Ptr32<Vec3>, int)> c; Ptr32<int (Ptr32<Sink>, int)> on; };
struct Sink { Ptr32<SinkV> vt; };
struct Starter;
struct StarterV { Ptr32<void> u[5]; Ptr32<void (Ptr32<Starter>)> start; };
struct Starter { Ptr32<StarterV> vt; };
struct Self { char u0[28]; int handle; Ptr32<Mesh> mesh; Ptr32<Ptr32<Sink>> sinks; char u40[4]; int started; Ptr32<Starter> starter; };
extern "C" Ptr32<Emitter> lookup_80164fc8(int);
extern "C" int constant_800e3434(Ptr32<Self>, unsigned);
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> cast_801797b4(Ptr32<void>);
extern "C" Ptr32<Vec3> positions_80189518(Ptr32<Mesh>);
extern "C" Ptr32<int> colours_80189760(Ptr32<Mesh>);
extern "C" Ptr32<float> rotations_80189574(Ptr32<Mesh>);
extern "C" Ptr32<unsigned char> bytes_80189828(Ptr32<Mesh>);
extern "C" Ptr32<unsigned char> flags_80189704(Ptr32<Mesh>);
extern "C" Ptr32<Pair> sizes_8018963c(Ptr32<Mesh>);
extern "C" int byte_80189504(Ptr32<Mesh>);
extern "C" void orient_800de40c(Ptr32<Part>, unsigned, Ptr32<Vec3>, Ptr32<Desc>);
extern "C" void anim_800de4c4(Ptr32<Part>, unsigned, Ptr32<unsigned char>, Ptr32<Desc>, unsigned char);
extern "C" void timed_800ddcbc(Ptr32<Part>, unsigned, Ptr32<Pair>, Ptr32<Desc>, int, Ptr32<Vec3>);
extern "C" Ptr32<void> empty_80342fa4(Ptr32<void>);
extern "C" Ptr32<Vec3> vec_80178ec4(Ptr32<void>);
extern "C" Ptr32<void> cast_80342a78(Ptr32<void>);
extern "C" int value_80178d1c(Ptr32<void>);
extern "C" void pull_800dfe84(Ptr32<Part>, Ptr32<Vec3>, unsigned, Ptr32<Vec3>, int);
struct Message { unsigned short id; Ptr32<void> text; };
extern "C" Ptr32<Message> arena_801613f0(Ptr32<void>, int);
extern "C" short cached_id_8015f5a0(Ptr32<void>, int);
extern "C" int post_8016239c(Ptr32<Message>);
extern Ptr32<void> arena_804b1754;
extern char cache_804aed14;
extern char empty_8040db38[];
extern "C" int d31c_emitter_render_update_800e2a28(Ptr32<Self> self, unsigned now) {
    Ptr32<Emitter> e = lookup_80164fc8(self->handle);
    if (!e->group) return constant_800e3434(self, now);
    Vec3 a, c, p;
    Rgba4 white(1.0f);
    Vec3 b;
    int col;
    Pair s0, s1;
    Ptr32<Vec3> pos = 0;
    Ptr32<int> cols = 0;
    Ptr32<float> rot = 0;
    Ptr32<unsigned char> bytes = 0;
    Ptr32<unsigned char> flags = 0;
    Ptr32<Pair> sizes = 0;
    Ptr32<Desc> d = cast_801797b4(empty_80341584(e->owner));
    if (e->mode == 1) {
        pos = positions_80189518(self->mesh);
        cols = colours_80189760(self->mesh);
        rot = rotations_80189574(self->mesh);
        bytes = bytes_80189828(self->mesh);
        flags = flags_80189704(self->mesh);
        sizes = sizes_8018963c(self->mesh);
    }
    if (!self->started) {
        self->starter->vt->start(self->starter);
        self->started = 1;
    }
    if (e->flags & 8) {
        Ptr32<Message> m = arena_801613f0(arena_804b1754, 8);
        m->id = cached_id_8015f5a0(&cache_804aed14, 1);
        m->text = empty_8040db38;
        post_8016239c(m);
    }
    for (unsigned i = 0; i < e->count; i++) {
        Ptr32<Part> it = e->group->vt->at(e->group, i);
        bool on = it->Active();
        if (on) {
            if (e->mode == 1) {
                it->vtable->move(it, now, &pos[i], d, 0);
                it->vtable->color(it, now, &cols[i], d);
                orient_800de40c(it, now, &p, d);
                anim_800de4c4(it, now, &bytes[i], d, byte_80189504(self->mesh));
                if (d->follow) {
                    timed_800ddcbc(it, now, &sizes[i], d, 0, 0);
                } else {
                    timed_800ddcbc(it, now, &sizes[i], d, 0, &a);
                    pos[i].y -= a.y;
                }
                rot[i] = p.z;
                flags[i] = !e->still;
                if (e->flags & 8) {
                    Ptr32<Vec3> v = vec_80178ec4(empty_80342fa4(e->h240));
                    pull_800dfe84(it, &pos[i], now, v, value_80178d1c(cast_80342a78(e->h244)));
                }
            } else {
                it->vtable->move(it, now, &a, d, 0);
                it->vtable->color(it, now, &col, d);
                orient_800de40c(it, now, &p, d);
                if (d->follow) {
                    timed_800ddcbc(it, now, &s1, d, d->f284 < 0.0f, 0);
                } else {
                    timed_800ddcbc(it, now, &s1, d, d->f284 < 0.0f, &b);
                    a.y -= b.y;
                }
                c.x = s1.a;
                c.y = s1.b;
                c.z = s1.a;
                if (e->flags & 8) {
                    Ptr32<Vec3> v = vec_80178ec4(empty_80342fa4(e->h240));
                    pull_800dfe84(it, &a, now, v, value_80178d1c(cast_80342a78(e->h244)));
                }
                self->sinks[i]->vt->a(self->sinks[i], &a, 0);
                self->sinks[i]->vt->c(self->sinks[i], &c, 0);
                self->sinks[i]->vt->b(self->sinks[i], &p, 0);
                self->sinks[i]->vt->on(self->sinks[i], 1);
            }
        } else if (e->mode == 1) {
            flags[i] = on;
        } else {
            self->sinks[i]->vt->on(self->sinks[i], 0);
        }
    }
    return 0;
}



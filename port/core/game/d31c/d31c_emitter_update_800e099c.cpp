#include "w3d_ptr.h"
#line 1 "d31c_emitter_update_800e099c.cpp"
// d31c: 0x800e099c. Particle emitter update: binds the state to the mesh arrays or locals, advances age and delay, runs the mode-specific part loop (mesh, per-part sinks, a target object, plain) and retires the emitter. Names are inferred; classes are partial views.
// Particle emitter update.
struct Vec3 { float x, y, z; };
struct Spin { float a, b; };
extern "C" void string_init_8020c5c0(Ptr32<void>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<void>);
struct String {
    Ptr32<char> text;
    String(const String &o) {
        string_init_8020c5c0(this);
        text = o.text;
        ++*string_header_80341884(this);
    }
    ~String();
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Desc { char u0[340]; String s340; char u344[50]; unsigned short u394; char u396[2]; unsigned short u398; char u400[16]; unsigned short u416; char u418[2]; unsigned short u420; char u422[38]; int u460; };
struct State {
    unsigned flags; unsigned index; Ptr32<Vec3> pos; Ptr32<int> color; Ptr32<Vec3> orient; Ptr32<float> angle; Ptr32<char> bytes; Ptr32<Spin> spin; Ptr32<char> alive; int spawning; unsigned char byte; char u41[3];
    int at[3]; Ptr32<void> h56; Ptr32<void> h60; Ptr32<void> h64; Ptr32<void> target; unsigned char wide;
};
struct Part;
struct PartV { Ptr32<void> u[3]; Ptr32<int (Ptr32<Part>, unsigned int, Ptr32<State>, Ptr32<Desc>)> tick; Ptr32<void> u16[5]; Ptr32<void (Ptr32<Part>, unsigned int, Ptr32<Vec3>, Ptr32<Desc>, int)> move; };
struct Part { char u0[104]; unsigned char active; char u105[7]; Ptr32<PartV> vtable; bool Active() { bool on = true; if (!active) on = false; return on; } };
struct Group;
struct GroupV { Ptr32<void> u[5]; Ptr32<Ptr32<Part> (Ptr32<Group>, unsigned int)> at; };
struct Group { Ptr32<GroupV> vt; };
struct Sink;
struct SinkV { Ptr32<void> u[19]; Ptr32<int (Ptr32<Sink>, Ptr32<Vec3>, int)> a; Ptr32<int (Ptr32<Sink>, Ptr32<Vec3>, int)> b; Ptr32<int (Ptr32<Sink>, Ptr32<Vec3>, int)> c; Ptr32<int (Ptr32<Sink>, int)> on; };
struct Sink { Ptr32<SinkV> vt; };
struct Starter;
struct StarterV { Ptr32<void> u[5]; Ptr32<void (Ptr32<Starter>)> start; };
struct Starter { Ptr32<StarterV> vt; };
struct Mesh;
struct Holder { char u0[68]; Vec3 v; char u80[36]; float f116; };
struct Emitter {
    char u0[28]; int h28; Ptr32<Group> group; unsigned u36; int u40; int age; int u48; int u52, u56; char u60[48]; char u108[16]; int u124; unsigned u128; char u132[8]; unsigned count; char u144[12]; Ptr32<void> owner; char u160[12]; int mode; unsigned state; State st; char u256[4]; Ptr32<Mesh> mesh; Ptr32<Ptr32<Sink>> sinks; char u268[16]; int started; Ptr32<Starter> starter; int warned; int h296;
};
struct Class { char pad[20]; Ptr32<Class> base; };
inline int is_kind(Ptr32<const Class> c, Ptr32<const Class> t) {
    for (; c != t; c = c->base) if (c == c->base) return 0;
    return 1;
}
struct Target;
struct TargetV { Ptr32<void> u[5]; Ptr32<Ptr32<Class> (Ptr32<Target>)> cls; };
struct Target { Ptr32<TargetV> vt; };
extern Class class_803613b0[];
extern "C" int lifetime_800e1e68(Ptr32<Emitter>, unsigned);
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> cast_801797b4(Ptr32<void>);
extern "C" Ptr32<Vec3> positions_80189518(Ptr32<Mesh>);
extern "C" Ptr32<int> colours_80189760(Ptr32<Mesh>);
extern "C" Ptr32<float> rotations_80189574(Ptr32<Mesh>);
extern "C" Ptr32<char> bytes_80189828(Ptr32<Mesh>);
extern "C" Ptr32<char> flags_80189704(Ptr32<Mesh>);
extern "C" Ptr32<Spin> sizes_8018963c(Ptr32<Mesh>);
extern "C" int byte_80189504(Ptr32<Mesh>);
extern "C" int sweep_800df570(Ptr32<int>);
extern "C" int query_800e25dc(Ptr32<Emitter>, Ptr32<int>);
extern "C" int fire_800e1268(Ptr32<Emitter>, Ptr32<Part>, unsigned, unsigned);
extern "C" void kill_800e1f40(Ptr32<Emitter>, unsigned);
extern "C" Ptr32<Holder> holder_800dfdf4(Ptr32<int>);
extern "C" Ptr32<Target> lookup_80164fc8(int);
extern "C" void apply_80122580(Ptr32<Target>, Ptr32<Vec3>, unsigned short, float);
extern "C" void remove_8015fd1c(Ptr32<Emitter>);
struct Message { unsigned short id; Ptr32<void> text; };
extern "C" Ptr32<Message> arena_801613f0(Ptr32<void>, int);
extern "C" short cached_id_8015f5a0(Ptr32<void>, int);
extern "C" int post_8016239c(Ptr32<Message>);
extern Ptr32<void> arena_804b1754;
extern char cache_804aecf8;
extern char empty_8040db38[];
extern "C" int d31c_emitter_update_800e099c(Ptr32<Emitter> e, unsigned now) {
    if (!e->group) return lifetime_800e1e68(e, now);
    Vec3 orient, pos;
    char pair[3];
    Vec3 col;
    int live = 0;
    Ptr32<Desc> d = cast_801797b4(empty_80341584(e->owner));
    int color;
    Spin spin;
    float angle;
    if (e->mode == 1) {
        e->st.pos = positions_80189518(e->mesh);
        e->st.color = colours_80189760(e->mesh);
        e->st.angle = rotations_80189574(e->mesh);
        e->st.bytes = bytes_80189828(e->mesh);
        e->st.alive = flags_80189704(e->mesh);
        e->st.spin = sizes_8018963c(e->mesh);
    } else {
        e->st.pos = &pos;
        e->st.color = &color;
        e->st.bytes = &pair[0];
        e->st.alive = &pair[1];
        e->st.spin = &spin;
        e->st.angle = &angle;
    }
    e->st.byte = 1;
    e->st.target = e->u108;
    e->st.orient = &orient;
    e->st.index = 0;
    e->u124 = 0;
    int delta;
    if (!e->u48) {
        e->u48 = now;
        delta = 0;
        e->u40 = d->u416;
    } else {
        delta = now - e->u36;
    }
    e->u40 += delta;
    e->u36 = now;
    int fire;
    if (e->state) fire = 0;
    else fire = e->u40 >= d->u416 + e->u56;
    if (e->age >= d->u394) {
        if (!e->started) {
            e->starter->vt->start(e->starter);
            e->started = 1;
        }
        if (e->h28) {
            if (d->u460) {
                if (!sweep_800df570(&e->h28)) {
                    e->state = 3;
                    fire = 0;
                }
            }
            e->h28 = 0;
        }
        if (e->st.flags & 8) {
            Ptr32<Message> m = arena_801613f0(arena_804b1754, 8);
            m->id = cached_id_8015f5a0(&cache_804aecf8, 1);
            m->text = empty_8040db38;
            post_8016239c(m);
        }
        if (e->st.flags & 32) query_800e25dc(e, e->st.at);
        switch (e->mode) {
        case 1:
            for (e->st.index = 0; e->st.index < e->count; e->st.index++) {
                Ptr32<Part> it = e->group->vt->at(e->group, e->st.index);
                e->st.byte = byte_80189504(e->mesh);
                if (fire && !it->Active()) fire = fire_800e1268(e, it, e->st.index, now);
                if (!it->vtable->tick(it, now, &e->st, d)) {
                    kill_800e1f40(e, e->st.index);
                } else {
                    if (e->st.flags & 2048) {
                        Vec3 &p = *(Ptr32<Vec3>)w3d::G((e->st.index * 12 + (int)w3d::H(e->st.pos)));
                        p.x = 0.0f; p.y = 0.0f; p.z = 0.0f;
                    }
                    live++;
                }
            }
            break;
        case 2:
            for (unsigned i = 0; i < e->count; i++) {
                Ptr32<Part> it = e->group->vt->at(e->group, i);
                if (fire && !it->Active()) fire = fire_800e1268(e, it, i, now);
                if (!it->vtable->tick(it, now, &e->st, d)) {
                    e->sinks[i]->vt->on(e->sinks[i], 0);
                    kill_800e1f40(e, i);
                } else {
                    col.x = spin.a;
                    col.y = spin.b;
                    col.z = spin.a;
                    if (!e->warned) {
                        if (pos.x > 150000.0f || pos.x < -150000.0f || pos.y > 150000.0f || pos.y < -150000.0f || pos.z > 150000.0f || pos.z < -150000.0f) {
                            { String name(d->s340); }
                            e->warned = 1;
                        }
                    }
                    e->sinks[i]->vt->a(e->sinks[i], &pos, 0);
                    e->sinks[i]->vt->c(e->sinks[i], &col, 0);
                    e->sinks[i]->vt->b(e->sinks[i], &orient, 0);
                    e->sinks[i]->vt->on(e->sinks[i], pair[1] != 0);
                    if (e->st.flags & 512) {
                        Ptr32<Holder> h = holder_800dfdf4(&e->h28);
                        Ptr32<Vec3> o2 = &orient;
                        *o2 = h->v;
                        orient.x = -h->f116;
                        e->sinks[i]->vt->b(e->sinks[i], o2, 0);
                    }
                    live++;
                }
            }
            break;
        case 3: {
            Ptr32<Target> t = lookup_80164fc8(e->h296);
            if (!t) break;
            if (is_kind(t->vt->cls(t), class_803613b0)) {
                for (unsigned i = 0; i < e->count; i++) {
                    Ptr32<Part> it = e->group->vt->at(e->group, i);
                    int reset = 0;
                    if (!it->Active()) {
                        if (fire) {
                            fire = fire_800e1268(e, it, i, now);
                            reset = 1;
                        } else {
                            Ptr32<Vec3> p = e->st.pos;
                            p->x = 0.0f; p->y = 0.0f; p->z = 0.0f;
                            Ptr32<Spin> q = e->st.spin;
                            q->a = 0.0f; q->b = 0.0f;
                        }
                    }
                    if (!it->vtable->tick(it, now, &e->st, d)) {
                        kill_800e1f40(e, i);
                        it->vtable->move(it, now, e->st.pos, d, 0);
                        Ptr32<Spin> q = e->st.spin;
                        q->a = 0.0f; q->b = 0.0f;
                    } else {
                        live++;
                    }
                    if (reset) { Ptr32<Spin> q = e->st.spin; q->a = 0.0f; q->b = 0.0f; }
                    apply_80122580(t, e->st.pos, i, e->st.spin->a);
                }
            }
            break;
        }
        case 0:
        default:
            for (unsigned i = 0; i < e->count; i++) {
                Ptr32<Part> it = e->group->vt->at(e->group, i);
                if (fire && !it->Active()) fire = fire_800e1268(e, it, i, now);
                if (!it->vtable->tick(it, now, &e->st, d)) kill_800e1f40(e, i);
                else live++;
            }
            break;
        }
    }
    if (e->state > 1) {
        bool done = live == 0;
        if (d->u420 == 0xffff) {
            if (d->u398 == d->u420 || e->state != 2) done = true;
        }
        if (done) remove_8015fd1c(e);
    } else {
        e->age += delta;
        if ((e->st.flags & 1) == 0) {
            if (e->age > d->u398 + e->u52 && e->u128 >= e->count) e->state = 2;
        }
    }
    return 0;
}



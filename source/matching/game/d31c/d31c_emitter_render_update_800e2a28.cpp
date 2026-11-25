// d31c: 0x800e2a28. Emitter render update: reads the mesh arrays or per-part sinks, starts the emitter once, then updates every active part's position, colour, orientation, animation and timing. Names are inferred; classes are partial views.
// Emitter render update.
struct Vec3 { float x, y, z; };
struct Pair { float a, b; };
struct Rgba4 { float r, g, b, a; Rgba4(float v) { r = v; g = v; b = v; a = v; } };
struct Part;
struct PartV { void *u[9]; void (*move)(Part *, unsigned, Vec3 *, void *, int); void *u40; void (*color)(Part *, unsigned, void *, void *); };
struct Part { char u0[104]; unsigned char active; char u105[7]; PartV *vtable; bool Active() { bool on = true; if (!active) on = false; return on; } };
struct Desc { char u0[284]; float f284; char u288[184]; int follow; };
struct Mesh;
struct GroupV { void *u[5]; Part *(*at)(struct Group *, unsigned); };
struct Group { GroupV *vt; };
struct Emitter { char u0[32]; Group *group; char u36[104]; unsigned count; char u144[12]; void *owner; char u160[12]; int mode; char u176[4]; unsigned flags; char u184[32]; bool still; char u220[20]; void *h240, *h244; };
struct Sink;
struct SinkV { void *u[19]; int (*a)(Sink *, Vec3 *, int); int (*b)(Sink *, Vec3 *, int); int (*c)(Sink *, Vec3 *, int); int (*on)(Sink *, int); };
struct Sink { SinkV *vt; };
struct Starter;
struct StarterV { void *u[5]; void (*start)(Starter *); };
struct Starter { StarterV *vt; };
struct Self { char u0[28]; int handle; Mesh *mesh; Sink **sinks; char u40[4]; int started; Starter *starter; };
extern "C" Emitter *lookup_80164fc8(int);
extern "C" int constant_800e3434(Self *, unsigned);
extern "C" void *empty_80341584(void *);
extern "C" Desc *cast_801797b4(void *);
extern "C" Vec3 *positions_80189518(Mesh *);
extern "C" int *colours_80189760(Mesh *);
extern "C" float *rotations_80189574(Mesh *);
extern "C" unsigned char *bytes_80189828(Mesh *);
extern "C" unsigned char *flags_80189704(Mesh *);
extern "C" Pair *sizes_8018963c(Mesh *);
extern "C" int byte_80189504(Mesh *);
extern "C" void orient_800de40c(Part *, unsigned, Vec3 *, Desc *);
extern "C" void anim_800de4c4(Part *, unsigned, unsigned char *, Desc *, unsigned char);
extern "C" void timed_800ddcbc(Part *, unsigned, Pair *, Desc *, int, Vec3 *);
extern "C" void *empty_80342fa4(void *);
extern "C" Vec3 *vec_80178ec4(void *);
extern "C" void *cast_80342a78(void *);
extern "C" int value_80178d1c(void *);
extern "C" void pull_800dfe84(Part *, Vec3 *, unsigned, Vec3 *, int);
struct Message { unsigned short id; void *text; };
extern "C" Message *arena_801613f0(void *, int);
extern "C" short cached_id_8015f5a0(void *, int);
extern "C" int post_8016239c(Message *);
extern void *arena_804b1754;
extern char cache_804aed14;
extern char empty_8040db38[];
extern "C" int d31c_emitter_render_update_800e2a28(Self *self, unsigned now) {
    Emitter *e = lookup_80164fc8(self->handle);
    if (!e->group) return constant_800e3434(self, now);
    Vec3 a, c, p;
    Rgba4 white(1.0f);
    Vec3 b;
    int col;
    Pair s0, s1;
    Vec3 *pos = 0;
    int *cols = 0;
    float *rot = 0;
    unsigned char *bytes = 0;
    unsigned char *flags = 0;
    Pair *sizes = 0;
    Desc *d = cast_801797b4(empty_80341584(e->owner));
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
        Message *m = arena_801613f0(arena_804b1754, 8);
        m->id = cached_id_8015f5a0(&cache_804aed14, 1);
        m->text = empty_8040db38;
        post_8016239c(m);
    }
    for (unsigned i = 0; i < e->count; i++) {
        Part *it = e->group->vt->at(e->group, i);
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
                    Vec3 *v = vec_80178ec4(empty_80342fa4(e->h240));
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
                    Vec3 *v = vec_80178ec4(empty_80342fa4(e->h240));
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

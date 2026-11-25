#include "w3d_ptr.h"
#line 1 "d32c_emitter_setup_800e1420.cpp"
// d32c: 0x800e1420. Emitter start-up: subscribes its messages, reads its settings, sizes its particle pool against the display limit, and loads either the sink list or the trail or mesh resources. Names are inferred; classes are partial views.
// Particle emitter start-up.
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
    unsigned short Length() const { return ((Ptr32<unsigned short>)text)[-2]; }
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Object;
struct ObjectVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVt> vt; };
extern "C" Ptr32<void> array_alloc_801fe220(unsigned);
extern "C" void array_free_801fe240(Ptr32<void>);
struct Sink;
struct SinkVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Sink>)> retain; Ptr32<void (Ptr32<Sink>)> release; Ptr32<void> u20[17]; Ptr32<void (Ptr32<Sink>, int)> on; };
struct Sink { Ptr32<SinkVt> vt; };
struct SinkRef {
    Ptr32<Sink> value;
    SinkRef() { value = 0; }
    ~SinkRef() { if (value) value->vt->release(value); }
    static void *operator new[](__SIZE_TYPE__ n) { return array_alloc_801fe220(n); }
    static void operator delete[](void *p) { array_free_801fe240(p); }
};
struct Ref {
    Ptr32<Object> value;
    Ref() { value = 0; }
    Ref(const Ref &);
    ~Ref() { if (value) value->vt->release(value); }
};
struct Table { char u0[24]; unsigned count; char u28[4]; String names[1]; };
struct Desc { char u0[284]; float f284; char u288[8]; String s296; char u300[4]; int u304; char u308[24]; Ptr32<Table> table; String s336; char u340[8]; unsigned u348; char u352[76]; int u428; int u432; char u436[12]; int u448; };
struct Key { Ptr32<const char> name; };
struct MessageId { unsigned short value; };
struct Emitter;
struct Owner;
struct OwnerVt { Ptr32<void> u[8]; Ptr32<void (Ptr32<Owner>)> fail; };
struct Owner { Ptr32<OwnerVt> vt; };
struct Audio;
struct AudioVt { Ptr32<void> u[14]; Ptr32<int (Ptr32<Audio>, int, Ptr32<void>)> bind; };
struct Audio { Ptr32<AudioVt> vt; };
struct Emitter {
    char u0[28]; char h28[68]; char u96[4]; float f100; char u104[36]; unsigned count; char u144[12]; Ptr32<Owner> owner; char u160[12]; int mode; int state; unsigned flags; char u184[52]; Ptr32<void> h236; char u240[4]; int u244; char u248[4]; unsigned char wide; char u253[7]; Ptr32<Object> mesh; Ptr32<SinkRef> sinks; int s268, s272, s276, s280; int started; Ptr32<Audio> audio; char u292[4]; int h296;
};
struct Loader;
struct LoaderVt { Ptr32<void> u[23]; Ptr32<void (Ptr32<Loader>, Ptr32<char>, Ptr32<Ptr32<Audio>>)> load; };
struct Loader { Ptr32<LoaderVt> vt; };
struct Manager { char u0[108]; Ptr32<Loader> loader; };
extern Ptr32<Manager> manager_804b1788;
struct Pool;
struct PoolVt { Ptr32<void> u[45]; Ptr32<unsigned short (Ptr32<Pool>, int)> count; };
struct Pool { Ptr32<PoolVt> vt; };
struct Display { char u0[116]; Ptr32<Pool> pool; };
extern Ptr32<Display> display_804b17ec;
struct Named;
struct NamedVt { Ptr32<void> u[19]; Ptr32<unsigned char (Ptr32<Named>)> type; };
struct Named { Ptr32<NamedVt> vt; };
extern "C" short cached_id_8015f5a0(Ptr32<void>, int);
extern "C" int subscribe_80162024(Ptr32<Emitter>, Ptr32<MessageId>, Ptr32<void>);
extern "C" int read_setting_800fc1b0(Ptr32<Key>, Ptr32<void>);
extern "C" int init_800dec8c(Ptr32<void>);
extern "C" void remove_8015fd1c(Ptr32<Emitter>);
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> cast_801797b4(Ptr32<void>);
extern "C" void cleanup_800e1cbc(Ptr32<Emitter>);
extern "C" Ptr32<Named> named_8015ae3c(const String &);
extern "C" unsigned random_8015ff5c(Ptr32<Emitter>);
extern "C" int load_8015adf4(const String &, Ptr32<Ptr32<Object>>, unsigned char);
extern "C" Ptr32<Sink> as_sink_80343584(Ptr32<Object>);
extern "C" Ptr32<Object> as_mesh_8034380c(Ptr32<Object>);
extern "C" Ptr32<void> create_8020b680(Ptr32<const void>);
extern "C" int attach_80164514(Ptr32<void>, Ptr32<void>, int);
extern "C" void trail_init_801222cc(Ptr32<void>, String, int, int, unsigned short);
extern "C" int resize_8018920c(Ptr32<Object>, unsigned);
extern "C" Ptr32<char> flags_80189704(Ptr32<Object>);
extern "C" Ptr32<void> empty_80342a74(Ptr32<void>);
extern "C" float value_80178df0(Ptr32<void>);
static inline unsigned pick(Ptr32<Emitter> self, const unsigned &n) { return random_8015ff5c(self) % n; }
static inline int load_mesh(Ptr32<Emitter> self, const String &name, unsigned char type) {
    Ref found;
    int r = load_8015adf4(name, &found.value, type);
    Ptr32<Object> v = as_mesh_8034380c(found.value);
    if (v) v->vt->retain(v);
    if (self->mesh) self->mesh->vt->release(self->mesh);
    self->mesh = v;
    return r;
}
extern char c_804aed00, c_804aece0, c_804aece8, c_804aecf0;
extern const char s_payload_80389dd0[];
struct Global { char u0[20]; int u20; };
extern Ptr32<Global> global_804aaecc;
extern Ptr32<void> world_804b178c;
extern char type_80410b08[];
extern "C" void d32c_emitter_setup_800e1420(Ptr32<Emitter> self) {
    unsigned need = 1;
    { MessageId id; id.value = cached_id_8015f5a0(&c_804aed00, 1); subscribe_80162024(self, &id, &self->s280); }
    { MessageId id; id.value = cached_id_8015f5a0(&c_804aece0, 1); subscribe_80162024(self, &id, &self->s268); }
    { MessageId id; id.value = cached_id_8015f5a0(&c_804aece8, 1); subscribe_80162024(self, &id, &self->s272); }
    { MessageId id; id.value = cached_id_8015f5a0(&c_804aecf0, 1); subscribe_80162024(self, &id, &self->s276); }
    { Key key; key.name = s_payload_80389dd0; read_setting_800fc1b0(&key, &self->u244); }
    if (init_800dec8c(self->h28) < 0) {
        self->state = 3;
        remove_8015fd1c(self);
        return;
    }
    Ptr32<Desc> d = cast_801797b4(empty_80341584(self->owner));
    int kind;
    if (d->s336.Length() == 0) {
        kind = 1;
        need = self->count;
    } else {
        kind = 3;
    }
    unsigned limit = (unsigned)((float)display_804b17ec->pool->vt->count(display_804b17ec->pool, kind) * 0.100000024f);
    if (need > (unsigned)(display_804b17ec->pool->vt->count(display_804b17ec->pool, kind) - limit)) {
        if (kind == 1) {
            Ptr32<Table> t = d->table;
            unsigned n = t->count;
            Ptr32<String> names = t->names;
            unsigned i = 0;
            if (i < n) {
                Ptr32<String> p = names;
                do {
                    i++;
                    String s(*p);
                    p++;
                } while (i < n);
            }
        } else {
            String s(d->s336);
        }
        goto fail;
    }
    if (d->s336.Length() == 0) {
        Ref holder;
        Ptr32<Table> t = d->table;
        unsigned n = t->count;
        Ptr32<String> names = t->names;
        if (n) {
            if (self->sinks) {
                w3d::delete_array(self->sinks);
                self->sinks = 0;
            }
            Ptr32<Named> nm = named_8015ae3c(names[0]);
            unsigned char type = nm->vt->type(nm);
            int extra = d->u348;
            if (extra) type = extra + 18;
            self->sinks = w3d::new_array<SinkRef>(self->count);
            for (unsigned i = 0; i < self->count; i++) {
                unsigned idx = pick(self, n);
                Ptr32<SinkRef> arr = self->sinks;
                int rc;
                {
                    Ref found;
                    rc = load_8015adf4(*(Ptr32<String>)w3d::G(((idx << 2) + (int)w3d::H(names))), &found.value, type);
                    Ptr32<Sink> v = as_sink_80343584(found.value);
                    if (v) v->vt->retain(v);
                    if (arr[i].value) arr[i].value->vt->release(arr[i].value);
                    arr[i].value = v;
                }
                if (rc < 0) {
                    self->state = 3;
                    { String s(*(Ptr32<String>)w3d::G(((idx << 2) + (int)w3d::H(names)))); }
                    cleanup_800e1cbc(self);
                    remove_8015fd1c(self);
                }
                self->sinks[i].value->vt->on(self->sinks[i].value, 0);
            }
            self->mode = 2;
            self->wide = d->f284 < 0.0f;
        } else {
            self->mode = n;
        }
    } else if (d->u304 == 3) {
        self->mode = 3;
        Ptr32<Global> g = global_804aaecc;
        Ptr32<void> o = create_8020b680(type_80410b08);
        self->h296 = attach_80164514(world_804b178c, o, g->u20);
        trail_init_801222cc(o, d->s336, 25, 0, self->count);
    } else {
        int rc;
        if (self->flags & 256) {
            rc = load_mesh(self, d->s336, 0);
        } else {
            Ptr32<Named> nm = named_8015ae3c(d->s336);
            if (!nm) {
                { String s(d->s336); }
                self->owner->vt->fail(self->owner);
                goto fail;
            }
            unsigned char type = nm->vt->type(nm);
            int extra = d->u348;
            if (extra) type = extra + 18;
            if (d->u432 && type != 27) type = 10;
            if (d->u448 && type != 27) {
                if (value_80178df0(empty_80342a74(self->h236)) >= self->f100) type = 10;
            }
            rc = load_mesh(self, d->s336, type);
            if (type == 27) self->flags |= 2048;
        }
        if (rc < 0) {
            { String s(d->s336); }
fail:
            self->state = 3;
            cleanup_800e1cbc(self);
            remove_8015fd1c(self);
            return;
        }
        resize_8018920c(self->mesh, self->count);
        Ptr32<char> p = flags_80189704(self->mesh);
        for (unsigned i = 0; i < self->count; i++) p[i] = 0;
        self->mode = 1;
        self->wide = 0;
    }
    if (d->s296.Length()) {
        manager_804b1788->loader->vt->load(manager_804b1788->loader, d->s296.text, &self->audio);
        self->audio->vt->bind(self->audio, 3, self->u96);
    } else {
        self->started = 1;
    }
    if (d->u428) self->flags |= 1024;
    if ((self->flags & 1056) == 1056) self->flags &= ~32;
}



#include "w3d_ptr.h"
#line 1 "d24c_particle_mesh_load_800e2f30.cpp"
// d24c: 0x800e2f30 (1016 bytes). Load a particle system's meshes. Without a mesh
// name: read the name table from the settings (or, when it is empty, from the
// "Particle.MeshNames" setting), replace the reference array at +36 and fill it
// with randomly chosen meshes, disabling each. With a mesh name: load it into +32
// using flag 0 for a shared owner (+180 bit 256), else the service's load flag
// (10 when either option is set), size it and clear its particle flags. Finally
// open the settings' sound into +48 and play it, or mark the system silent (+44).
// Names are inferred. The flags pointer is declared at the top with 0: CSE reuses
// that register for the reference initialisers on the fall-through paths, while
// the third path needs its own zero. Holding the loaded reference in an inline
// helper gives it a separate frame block, so its 8-byte slot is not reused and the
// later references land at sp+8. The count is passed by const reference: this
// keeps the register copy seen before the loop. 0x8015adf4 has a status return.
typedef unsigned int size_t;
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;       // +12
    Ptr32<void (Ptr32<Object>)> release;      // +16
    Ptr32<void> unknown14[17];
    Ptr32<void (Ptr32<Object>, int)> enable;  // +88
};
struct Object { Ptr32<ObjectVtable> vtable; };
extern "C" Ptr32<void> array_new_801fe220(size_t);
extern "C" void array_delete_801fe240(Ptr32<void>);
struct Ref {
    Ptr32<Object> value;
    ~Ref() { if (value) value->vtable->release(value); }
    static void *operator new[](__SIZE_TYPE__ n) { return array_new_801fe220(n); }
    static void operator delete[](void *p) { array_delete_801fe240(p); }
};
struct Slot {
    Ptr32<Object> value;
    Slot() : value(0) {}
    ~Slot() { if (value) value->vtable->release(value); }
    static void *operator new[](__SIZE_TYPE__ n) { return array_new_801fe220(n); }
    static void operator delete[](void *p) { array_delete_801fe240(p); }
};
struct Text {
    Ptr32<char> text;
    int length() const { return ((Ptr32<unsigned short>)text)[-2]; }
};
struct Key { Ptr32<const char> text; };
struct NameTable { unsigned char u[24]; unsigned count; unsigned u28; Text names[1]; };
struct Settings {
    unsigned char u0[20];
    Ptr32<NameTable> names;           // +20
    unsigned char u24[272];
    Text sound;                 // +296
    unsigned char u300[32];
    Ptr32<NameTable> mesh_names;      // +332
    Text mesh;                  // +336
    unsigned char u340[92];
    int option432;              // +432
    unsigned char u436[12];
    int option448;              // +448
};
struct Owner {
    unsigned char u0[96];
    unsigned char sound_arg[44]; // +96
    unsigned count;              // +140
    unsigned char u144[12];
    Ptr32<void> resource;              // +156
    unsigned char u160[20];
    unsigned flags;              // +180
};
struct Sound {
    struct V { Ptr32<void> u[14]; Ptr32<void (Ptr32<Sound>, int, Ptr32<void>)> play; }; Ptr32<struct V> vtable;
};
struct Particles {
    unsigned char u0[28];
    int handle;     // +28
    Ptr32<Object> mesh;   // +32
    Ptr32<Slot> meshes;   // +36
    unsigned char u40[4];
    int silent;     // +44
    Ptr32<Sound> sound;   // +48
};
struct Service { struct V { Ptr32<void> u[19]; Ptr32<unsigned char (Ptr32<Service>)> flags; }; Ptr32<struct V> vtable; };
struct SoundSystem { struct V { Ptr32<void> u[23]; Ptr32<void (Ptr32<SoundSystem>, Ptr32<char>, Ptr32<Ptr32<Sound>>)> open; }; Ptr32<struct V> vtable; };
struct Engine { unsigned char u[108]; Ptr32<SoundSystem> sound; };
extern Ptr32<Engine> engine_804b1788;
extern "C" Ptr32<Owner> lookup_80164fc8(int);
extern "C" Ptr32<void> identity_80341584(Ptr32<void>);
extern "C" Ptr32<Settings> settings_801797b4(Ptr32<void>);
extern "C" int read_800fc1b0(Ptr32<Key>, Ptr32<Ref>);
extern "C" unsigned random_8015ff5c(Ptr32<Particles>);
extern "C" int load_8015adf4(Ptr32<const Text>, Ptr32<Ref>, unsigned char);
extern "C" Ptr32<Service> service_8015ae3c(Ptr32<const Text>);
extern "C" Ptr32<Object> as_text_80343584(Ptr32<Object>);
extern "C" Ptr32<Object> as_mesh_8034380c(Ptr32<Object>);
extern "C" int mesh_alloc_8018920c(Ptr32<Object>, unsigned);
extern "C" Ptr32<unsigned char> mesh_flags_80189704(Ptr32<Object>);
extern const char mesh_names_80389fd4[];
inline unsigned pick_index(Ptr32<Particles> self, const unsigned &count) {
    return random_8015ff5c(self) % count;
}
inline void load_slot(Ptr32<Text> name, Ptr32<Slot> p, unsigned i) {
    Ref loaded;
    loaded.value = 0;
    load_8015adf4(name, &loaded, 255);
    Ptr32<Object> m = as_text_80343584(loaded.value);
    if (m) m->vtable->retain(m);
    if (p[i].value) p[i].value->vtable->release(p[i].value);
    p[i].value = m;
}
extern "C" void d24c_particle_mesh_load_800e2f30(Ptr32<Particles> self) {
    Ptr32<unsigned char> flags = 0;
    Ptr32<Owner> o = lookup_80164fc8(self->handle);
    Ptr32<Settings> s = settings_801797b4(identity_80341584(o->resource));
    if (s->mesh.length() == 0) {
        Ref ref;
        ref.value = 0;
        Ptr32<Ref> out = &ref;
        Ptr32<NameTable> t = s->mesh_names;
        unsigned count = t->count;
        Ptr32<Text> names = t->names;
        if (count == 0) {
            Key key;
            key.text = mesh_names_80389fd4;
            read_800fc1b0(&key, out);
            Ptr32<NameTable> u = settings_801797b4(identity_80341584(ref.value))->names;
            count = u->count;
            names = u->names;
        }
        w3d::delete_array(self->meshes);
        self->meshes = w3d::new_array<Slot>(o->count);
        for (unsigned i = 0; i < o->count; i++) {
            unsigned pick = pick_index(self, count);
            load_slot(names + pick, self->meshes, i);
            self->meshes[i].value->vtable->enable(self->meshes[i].value, 0);
        }
    } else {
        if (o->flags & 256) {
            Ref r;
            r.value = 0;
            load_8015adf4(&s->mesh, &r, 0);
            Ptr32<Object> m = as_mesh_8034380c(r.value);
            if (m) m->vtable->retain(m);
            if (self->mesh) self->mesh->vtable->release(self->mesh);
            self->mesh = m;
        } else {
            Ptr32<Service> svc = service_8015ae3c(&s->mesh);
            unsigned char flag = svc->vtable->flags(svc);
            if (s->option432 || s->option448) flag = 10;
            Ref r;
            r.value = 0;
            load_8015adf4(&s->mesh, &r, flag);
            Ptr32<Object> m = as_mesh_8034380c(r.value);
            if (m) m->vtable->retain(m);
            if (self->mesh) self->mesh->vtable->release(self->mesh);
            self->mesh = m;
        }
        mesh_alloc_8018920c(self->mesh, o->count);
        flags = mesh_flags_80189704(self->mesh);
        for (unsigned i = 0; i < o->count; i++) flags[i] = 0;
    }
    if (s->sound.length()) {
        Ptr32<SoundSystem> a = engine_804b1788->sound;
        a->vtable->open(a, s->sound.text, &self->sound);
        self->sound->vtable->play(self->sound, 3, o->sound_arg);
    } else {
        self->silent = 1;
    }
}



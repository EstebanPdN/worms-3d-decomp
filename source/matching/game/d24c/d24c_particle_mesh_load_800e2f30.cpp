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
    void *unknown00[3];
    void (*retain)(Object *);       // +12
    void (*release)(Object *);      // +16
    void *unknown14[17];
    void (*enable)(Object *, int);  // +88
};
struct Object { ObjectVtable *vtable; };
extern "C" void *array_new_801fe220(size_t);
extern "C" void array_delete_801fe240(void *);
struct Ref {
    Object *value;
    ~Ref() { if (value) value->vtable->release(value); }
    static void *operator new[](size_t n) { return array_new_801fe220(n); }
    static void operator delete[](void *p) { array_delete_801fe240(p); }
};
struct Slot {
    Object *value;
    Slot() : value(0) {}
    ~Slot() { if (value) value->vtable->release(value); }
    static void *operator new[](size_t n) { return array_new_801fe220(n); }
    static void operator delete[](void *p) { array_delete_801fe240(p); }
};
struct Text {
    char *text;
    int length() const { return ((unsigned short *)text)[-2]; }
};
struct Key { const char *text; };
struct NameTable { unsigned char u[24]; unsigned count; unsigned u28; Text names[1]; };
struct Settings {
    unsigned char u0[20];
    NameTable *names;           // +20
    unsigned char u24[272];
    Text sound;                 // +296
    unsigned char u300[32];
    NameTable *mesh_names;      // +332
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
    void *resource;              // +156
    unsigned char u160[20];
    unsigned flags;              // +180
};
struct Sound {
    struct V { void *u[14]; void (*play)(Sound *, int, void *); } *vtable;
};
struct Particles {
    unsigned char u0[28];
    int handle;     // +28
    Object *mesh;   // +32
    Slot *meshes;   // +36
    unsigned char u40[4];
    int silent;     // +44
    Sound *sound;   // +48
};
struct Service { struct V { void *u[19]; unsigned char (*flags)(Service *); } *vtable; };
struct SoundSystem { struct V { void *u[23]; void (*open)(SoundSystem *, char *, Sound **); } *vtable; };
struct Engine { unsigned char u[108]; SoundSystem *sound; };
extern Engine *engine_804b1788;
extern "C" Owner *lookup_80164fc8(int);
extern "C" void *identity_80341584(void *);
extern "C" Settings *settings_801797b4(void *);
extern "C" int read_800fc1b0(Key *, Ref *);
extern "C" unsigned random_8015ff5c(Particles *);
extern "C" int load_8015adf4(const Text *, Ref *, unsigned char);
extern "C" Service *service_8015ae3c(const Text *);
extern "C" Object *as_text_80343584(Object *);
extern "C" Object *as_mesh_8034380c(Object *);
extern "C" int mesh_alloc_8018920c(Object *, unsigned);
extern "C" unsigned char *mesh_flags_80189704(Object *);
extern const char mesh_names_80389fd4[];
inline unsigned pick_index(Particles *self, const unsigned &count) {
    return random_8015ff5c(self) % count;
}
inline void load_slot(Text *name, Slot *p, unsigned i) {
    Ref loaded;
    loaded.value = 0;
    load_8015adf4(name, &loaded, 255);
    Object *m = as_text_80343584(loaded.value);
    if (m) m->vtable->retain(m);
    if (p[i].value) p[i].value->vtable->release(p[i].value);
    p[i].value = m;
}
extern "C" void d24c_particle_mesh_load_800e2f30(Particles *self) {
    unsigned char *flags = 0;
    Owner *o = lookup_80164fc8(self->handle);
    Settings *s = settings_801797b4(identity_80341584(o->resource));
    if (s->mesh.length() == 0) {
        Ref ref;
        ref.value = 0;
        Ref *out = &ref;
        NameTable *t = s->mesh_names;
        unsigned count = t->count;
        Text *names = t->names;
        if (count == 0) {
            Key key;
            key.text = mesh_names_80389fd4;
            read_800fc1b0(&key, out);
            NameTable *u = settings_801797b4(identity_80341584(ref.value))->names;
            count = u->count;
            names = u->names;
        }
        delete[] self->meshes;
        self->meshes = new Slot[o->count];
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
            Object *m = as_mesh_8034380c(r.value);
            if (m) m->vtable->retain(m);
            if (self->mesh) self->mesh->vtable->release(self->mesh);
            self->mesh = m;
        } else {
            Service *svc = service_8015ae3c(&s->mesh);
            unsigned char flag = svc->vtable->flags(svc);
            if (s->option432 || s->option448) flag = 10;
            Ref r;
            r.value = 0;
            load_8015adf4(&s->mesh, &r, flag);
            Object *m = as_mesh_8034380c(r.value);
            if (m) m->vtable->retain(m);
            if (self->mesh) self->mesh->vtable->release(self->mesh);
            self->mesh = m;
        }
        mesh_alloc_8018920c(self->mesh, o->count);
        flags = mesh_flags_80189704(self->mesh);
        for (unsigned i = 0; i < o->count; i++) flags[i] = 0;
    }
    if (s->sound.length()) {
        SoundSystem *a = engine_804b1788->sound;
        a->vtable->open(a, s->sound.text, &self->sound);
        self->sound->vtable->play(self->sound, 3, o->sound_arg);
    } else {
        self->silent = 1;
    }
}

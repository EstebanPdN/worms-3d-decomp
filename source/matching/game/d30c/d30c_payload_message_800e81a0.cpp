// d30c: 0x800e81a0. Payload message handler: start and stop messages, then a chain of cached ids that load meshes and clips by the type's strings and read or write settings; every path ends in the base handler. Names are inferred; classes are partial views.
extern "C" void string_init_8020c5c0(void *);
extern "C" unsigned short *string_header_80341884(void *);
extern "C" int strcmp_802ef234(const char *, const char *);
extern char empty_8038b1f8[];
struct String {
    char *text;
    String(const String &o) {
        string_init_8020c5c0(this);
        text = o.text;
        ++*string_header_80341884(this);
    }
    ~String();
    bool operator!=(const char *o) const { int c = strcmp_802ef234(text, o); bool r = true; if (c == 0) r = false; return r; }
};
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Object;
struct ObjectVtable { void *u[4]; void (*release)(Object *); void (*activate)(Object *); void (*stop)(Object *); };
struct Object { ObjectVtable *vtable; };
struct Loader;
struct LoaderVt { void *u[23]; void (*load)(Loader *, char *, Object **); void (*bind)(Loader *, char *, void *); };
struct Loader { LoaderVt *vt; };
struct Manager { char u0[108]; Loader *loader; };
extern Manager *manager_804b1788;
struct Type { char u0[204]; String s204; char u208[0]; int u208v; int u212; char u216[136]; String s352; char u356[4]; String s360; char u364[16]; String s380; char u384[32]; int u416; char u420[12]; String s432; };
struct Msg { unsigned short id; unsigned short Id() { return id; } };
struct Self { char u0[20]; int u20; char u24[4]; void *u28; int u32; char u36[24]; char u60[100]; int u160; char u164[4]; Object *o168, *o172; char u176[4]; Object *o180; int u184; char u188[20]; Object *o208; };
extern int c58_804aee58, c68_804aee68, c60_804aee60, c90_804aee90, c78_804aee78, c88_804aee88, c80_804aee80, c98_804aee98, ca0_804aeea0, ca8_804aeea8, cb0_804aeeb0, cb8_804aeeb8, cc0_804aeec0;
extern char mesh_8038b1fc[], task_8038b20c[];
struct Key { const char *name; };
extern "C" int base_8015fb34(Self *, Msg *);
extern "C" int start_800e8bb0(Self *);
extern "C" int stopped_800e88e0(Self *);
extern "C" int same_8015f65c(unsigned short, int *);
extern "C" int play_800e99cc(Self *);
extern "C" int check_8018179c(void *, int, int);
extern "C" int value_80125ff8(Msg *);
extern "C" void *empty_80341584(void *);
extern "C" Type *cast_801797b4(void *);
extern "C" void notify_800e8a88(Self *);
extern "C" int find_800e8f40(Self *, char *);
extern "C" void clip_800e96d8(Self *, int, int *);
extern "C" void flag_800e8ee0(Self *, void *, Object **);
extern "C" int write_800fc43c(Key *, int);
extern "C" void scene_800e9e04(Self *);
extern "C" int d30c_payload_message_800e81a0(Self *self, Msg *m) {
    unsigned short id = m->Id();
    switch (m->Id()) {
    case 64:
        if (base_8015fb34(self, m) >= 0) {
            start_800e8bb0(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        stopped_800e88e0(self);
        return base_8015fb34(self, m);
    }
    if (same_8015f65c(id, &c58_804aee58)) {
        play_800e99cc(self);
    } else if (same_8015f65c(id, &c68_804aee68)) {
        self->u160 = -1;
        if (self->o172) self->o172->vtable->stop(self->o172);
        if (self->u184 != -1) check_8018179c((void *)self->u32, self->u184, 0);
    } else if (same_8015f65c(id, &c60_804aee60)) {
        self->u160 = value_80125ff8(m);
        Type *t = cast_801797b4(empty_80341584(self->u28));
        String a(t->s360);
        String b(t->s432);
        if (a != "") {
            manager_804b1788->loader->vt->load(manager_804b1788->loader, a.text, &self->o168);
            self->o168->vtable->activate(self->o168);
        }
        if (b != "") {
            manager_804b1788->loader->vt->load(manager_804b1788->loader, b.text, &self->o172);
            self->o172->vtable->activate(self->o172);
        }
        notify_800e8a88(self);
        String c(t->s204);
        if (c != "") self->u184 = find_800e8f40(self, c.text);
    } else if (same_8015f65c(id, &c90_804aee90)) {
        self->u160 = value_80125ff8(m);
    } else if (same_8015f65c(id, &c78_804aee78)) {
        Type *t = cast_801797b4(empty_80341584(self->u28));
        String a(t->s352);
        if (a != "") manager_804b1788->loader->vt->bind(manager_804b1788->loader, a.text, self->u60);
    } else if (same_8015f65c(id, &c88_804aee88)) {
        Type *t = cast_801797b4(empty_80341584(self->u28));
        String a(t->s352);
        if (a != "") manager_804b1788->loader->vt->bind(manager_804b1788->loader, a.text, self->u60);
        int v = value_80125ff8(m);
        int w = t->u212;
        clip_800e96d8(self, v, &w);
    } else if (same_8015f65c(id, &c80_804aee80)) {
        Type *t = cast_801797b4(empty_80341584(self->u28));
        String a(t->s352);
        if (a != "") manager_804b1788->loader->vt->bind(manager_804b1788->loader, a.text, self->u60);
        String b(t->s380);
        if (b != "") manager_804b1788->loader->vt->bind(manager_804b1788->loader, b.text, self->u60);
        int v = value_80125ff8(m);
        int w = t->u208v;
        clip_800e96d8(self, v, &w);
    } else if (same_8015f65c(id, &c98_804aee98)) {
        Type *t = cast_801797b4(empty_80341584(self->u28));
        if (self->o180) {
            self->o180->vtable->stop(self->o180);
            if (self->o180) self->o180->vtable->release(self->o180);
            self->o180 = 0;
        }
        String a(t->s380);
        if (a != "") manager_804b1788->loader->vt->bind(manager_804b1788->loader, a.text, self->u60);
    } else if (same_8015f65c(id, &ca0_804aeea0)) {
        Type *t = cast_801797b4(empty_80341584(self->u28));
        flag_800e8ee0(self, (void *)t->u416, &self->o180);
    } else if (same_8015f65c(id, &ca8_804aeea8)) {
        Key k; k.name = "Payload.Mesh"; write_800fc43c(&k, self->u32);
    } else if (same_8015f65c(id, &cb0_804aeeb0)) {
        Key k; k.name = "Camera.Graphic.TaskId"; write_800fc43c(&k, self->u20);
    } else if (same_8015f65c(id, &cb8_804aeeb8)) {
        scene_800e9e04(self);
    } else if (same_8015f65c(id, &cc0_804aeec0)) {
        if (self->o208) self->o208->vtable->release(self->o208);
        self->o208 = 0;
    }
    return base_8015fb34(self, m);
}

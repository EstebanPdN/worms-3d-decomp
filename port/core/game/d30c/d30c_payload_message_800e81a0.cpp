#include "w3d_ptr.h"
#line 1 "d30c_payload_message_800e81a0.cpp"
// d30c: 0x800e81a0. Payload message handler: start and stop messages, then a chain of cached ids that load meshes and clips by the type's strings and read or write settings; every path ends in the base handler. Names are inferred; classes are partial views.
extern "C" void string_init_8020c5c0(Ptr32<void>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<void>);
extern "C" int strcmp_802ef234(Ptr32<const char>, Ptr32<const char>);
extern char empty_8038b1f8[];
struct String {
    Ptr32<char> text;
    String(const String &o) {
        string_init_8020c5c0(this);
        text = o.text;
        ++*string_header_80341884(this);
    }
    ~String();
    bool operator!=(const char *o) const { int c = strcmp_802ef234(text, o); bool r = true; if (c == 0) r = false; return r; }
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Object;
struct ObjectVtable { Ptr32<void> u[4]; Ptr32<void (Ptr32<Object>)> release; Ptr32<void (Ptr32<Object>)> activate; Ptr32<void (Ptr32<Object>)> stop; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Loader;
struct LoaderVt { Ptr32<void> u[23]; Ptr32<void (Ptr32<Loader>, Ptr32<char>, Ptr32<Ptr32<Object>>)> load; Ptr32<void (Ptr32<Loader>, Ptr32<char>, Ptr32<void>)> bind; };
struct Loader { Ptr32<LoaderVt> vt; };
struct Manager { char u0[108]; Ptr32<Loader> loader; };
extern Ptr32<Manager> manager_804b1788;
struct Type { char u0[204]; String s204; char u208[0]; int u208v; int u212; char u216[136]; String s352; char u356[4]; String s360; char u364[16]; String s380; char u384[32]; int u416; char u420[12]; String s432; };
struct Msg { unsigned short id; unsigned short Id() { return id; } };
struct Self { char u0[20]; int u20; char u24[4]; Ptr32<void> u28; int u32; char u36[24]; char u60[100]; int u160; char u164[4]; Ptr32<Object> o168; Ptr32<Object> o172; char u176[4]; Ptr32<Object> o180; int u184; char u188[20]; Ptr32<Object> o208; };
extern int c58_804aee58, c68_804aee68, c60_804aee60, c90_804aee90, c78_804aee78, c88_804aee88, c80_804aee80, c98_804aee98, ca0_804aeea0, ca8_804aeea8, cb0_804aeeb0, cb8_804aeeb8, cc0_804aeec0;
extern char mesh_8038b1fc[], task_8038b20c[];
struct Key { Ptr32<const char> name; };
extern "C" int base_8015fb34(Ptr32<Self>, Ptr32<Msg>);
extern "C" int start_800e8bb0(Ptr32<Self>);
extern "C" int stopped_800e88e0(Ptr32<Self>);
extern "C" int same_8015f65c(unsigned short, Ptr32<int>);
extern "C" int play_800e99cc(Ptr32<Self>);
extern "C" int check_8018179c(Ptr32<void>, int, int);
extern "C" int value_80125ff8(Ptr32<Msg>);
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Type> cast_801797b4(Ptr32<void>);
extern "C" void notify_800e8a88(Ptr32<Self>);
extern "C" int find_800e8f40(Ptr32<Self>, Ptr32<char>);
extern "C" void clip_800e96d8(Ptr32<Self>, int, Ptr32<int>);
extern "C" void flag_800e8ee0(Ptr32<Self>, Ptr32<void>, Ptr32<Ptr32<Object>>);
extern "C" int write_800fc43c(Ptr32<Key>, int);
extern "C" void scene_800e9e04(Ptr32<Self>);
extern "C" int d30c_payload_message_800e81a0(Ptr32<Self> self, Ptr32<Msg> m) {
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
        if (self->u184 != -1) check_8018179c((Ptr32<void>)w3d::G(self->u32), self->u184, 0);
    } else if (same_8015f65c(id, &c60_804aee60)) {
        self->u160 = value_80125ff8(m);
        Ptr32<Type> t = cast_801797b4(empty_80341584(self->u28));
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
        Ptr32<Type> t = cast_801797b4(empty_80341584(self->u28));
        String a(t->s352);
        if (a != "") manager_804b1788->loader->vt->bind(manager_804b1788->loader, a.text, self->u60);
    } else if (same_8015f65c(id, &c88_804aee88)) {
        Ptr32<Type> t = cast_801797b4(empty_80341584(self->u28));
        String a(t->s352);
        if (a != "") manager_804b1788->loader->vt->bind(manager_804b1788->loader, a.text, self->u60);
        int v = value_80125ff8(m);
        int w = t->u212;
        clip_800e96d8(self, v, &w);
    } else if (same_8015f65c(id, &c80_804aee80)) {
        Ptr32<Type> t = cast_801797b4(empty_80341584(self->u28));
        String a(t->s352);
        if (a != "") manager_804b1788->loader->vt->bind(manager_804b1788->loader, a.text, self->u60);
        String b(t->s380);
        if (b != "") manager_804b1788->loader->vt->bind(manager_804b1788->loader, b.text, self->u60);
        int v = value_80125ff8(m);
        int w = t->u208v;
        clip_800e96d8(self, v, &w);
    } else if (same_8015f65c(id, &c98_804aee98)) {
        Ptr32<Type> t = cast_801797b4(empty_80341584(self->u28));
        if (self->o180) {
            self->o180->vtable->stop(self->o180);
            if (self->o180) self->o180->vtable->release(self->o180);
            self->o180 = 0;
        }
        String a(t->s380);
        if (a != "") manager_804b1788->loader->vt->bind(manager_804b1788->loader, a.text, self->u60);
    } else if (same_8015f65c(id, &ca0_804aeea0)) {
        Ptr32<Type> t = cast_801797b4(empty_80341584(self->u28));
        flag_800e8ee0(self, (Ptr32<void>)w3d::G(t->u416), &self->o180);
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



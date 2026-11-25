#include "w3d_ptr.h"
#line 1 "d24c_powerbar_init_800f03a0.cpp"
// d24c: 0x800f03a0 (1508 bytes). Initialise the HUD power bar: load the
// "HUD.Powerbar" mesh into +28; read seven settings into retained references
// (+92..+116: active worm, fill, maximum, next, position, size, chat); read the
// bar size; copy the position value to +32 and hand it to the mesh; size the
// mesh for one sprite, colour it from the shared colour with alpha from the next
// setting, set its two 2D pairs from the pool floats; subscribe five message
// handlers (+44..+60); and open the bazooka power sound into +88. Names are
// inferred. READ and LISTEN expand the repeated statements in place: an inline
// helper would give each its own frame block, which only the first load has in
// the original. 0x8015adf4 is declared with a status return. One-word String
// and handle classes with user copy constructors (d24r).
typedef unsigned int size_t;
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;       // +12
    Ptr32<void (Ptr32<Object>)> release;      // +16
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Ref {
    Ptr32<Object> value;
    Ref() {}
    Ref(const Ref &o) : value(o.value) { if (value) value->vtable->retain(value); }
    ~Ref() { if (value) value->vtable->release(value); }
};
struct Key { Ptr32<const char> text; };
struct Vec3 {
    float x, y, z;
    Vec3() {}
};
struct Words { int a, b, c; };
struct Rgba { unsigned char r, g, b, a; };
struct Vec2 { float x, y; };
struct MessageId { short value; };
struct Mesh {
    struct V {
        Ptr32<void> u[19];
        Ptr32<void (Ptr32<Mesh>, Ptr32<Words>, int)> set_position;  // +76
    }; Ptr32<struct V> vtable;
};
struct Powerbar {
    unsigned char u0[28];
    Ptr32<Mesh> mesh;         // +28
    Words position;     // +32
    int msg44, msg48, msg52, msg56, msg60;
    unsigned char u64[24];
    Ptr32<void> sound;        // +88
    Ptr32<Object> worm;       // +92
    Ptr32<Object> fill;       // +96
    Ptr32<Object> maximum;    // +100
    Ptr32<Object> next;       // +104
    Ptr32<Object> pos;        // +108
    Ptr32<Object> size;       // +112
    Ptr32<Object> chat;       // +116
};
struct Sounds { struct V { Ptr32<void> u[23]; Ptr32<void (Ptr32<Sounds>, Ptr32<const char>, Ptr32<Ptr32<void>>)> open; }; Ptr32<struct V> vtable; };
struct Engine { unsigned char u[108]; Ptr32<Sounds> sound; };
extern Ptr32<Engine> engine_804b1788;
extern Rgba colour_804af024;
extern "C" int load_8015adf4(Ptr32<const String>, Ptr32<void>, unsigned char);
extern "C" int read_800fc1b0(Ptr32<Key>, Ptr32<void>);
extern "C" int read_800fc2f0(Ptr32<Key>, Ptr32<void>);
extern "C" Ptr32<Object> as_803426b4(Ptr32<Object>);
extern "C" Ptr32<Object> as_80342a78(Ptr32<Object>);
extern "C" Ptr32<Object> as_80342fa4(Ptr32<Object>);
extern "C" Ptr32<Object> as_mesh_8034380c(Ptr32<Object>);
extern "C" Ptr32<void> value_80178ec4(Ptr32<Object>);
extern "C" int count_80178d1c(Ptr32<Object>);
extern "C" int mesh_set_80189450(Ptr32<Mesh>, int);
extern "C" int mesh_alloc_8018920c(Ptr32<Mesh>, int);
extern "C" Ptr32<unsigned char> mesh_a_80189828(Ptr32<Mesh>);
extern "C" Ptr32<unsigned char> mesh_flags_80189704(Ptr32<Mesh>);
extern "C" Ptr32<Rgba> mesh_colours_80189760(Ptr32<Mesh>);
extern "C" Ptr32<Vec2> mesh_b_80189884(Ptr32<Mesh>);
extern "C" Ptr32<Vec2> mesh_c_801898e0(Ptr32<Mesh>);
extern "C" short message_id_8015f5a0(Ptr32<int>, int);
extern "C" int subscribe_80162024(Ptr32<Powerbar>, Ptr32<MessageId>, Ptr32<int>);
extern int cache_804af038, cache_804af040, cache_804af048, cache_804af050, cache_804af058;
extern const char powerbar_8038c148[], worm_8038c15c[], fill_8038c16c[], max_8038c184[], next_8038c19c[],
    pos_8038c1b4[], size_8038c1cc[], chat_8038c1e0[], bar_8038c1ec[], sound_8038c204[];
extern const float half_8038c214[], one_8038c218[];
#define READ(slot, name, cast) { \
    Ref r; \
    r.value = 0; \
    Key key; \
    key.text = name; \
    read_800fc1b0(&key, &r); \
    Object *o = cast(r.value); \
    if (o) o->vtable->retain(o); \
    if (self->slot) self->slot->vtable->release(self->slot); \
    self->slot = o; \
}
#define LISTEN(id, cache, field) \
    id.value = message_id_8015f5a0(&cache, 1); \
    subscribe_80162024(self, &id, &self->field);
inline void load_mesh(Ptr32<Powerbar> self, Ptr32<const String> name) {
    Ref r;
    r.value = 0;
    load_8015adf4(name, &r, 255);
    Ptr32<Object> o = as_mesh_8034380c(r.value);
    if (o) o->vtable->retain(o);
    if (self->mesh) ((Ptr32<Object>)self->mesh)->vtable->release((Ptr32<Object>)self->mesh);
    self->mesh = (Ptr32<Mesh>)o;
}
extern "C" void d24c_powerbar_init_800f03a0(Ptr32<Powerbar> self) {
    {
        String name(powerbar_8038c148);
        load_mesh(self, &name);
    }
    READ(worm, worm_8038c15c, as_803426b4)
    READ(fill, fill_8038c16c, as_80342a78)
    READ(maximum, max_8038c184, as_80342a78)
    READ(next, next_8038c19c, as_80342a78)
    READ(pos, pos_8038c1b4, as_80342fa4)
    READ(size, size_8038c1cc, as_80342fa4)
    READ(chat, chat_8038c1e0, as_80342a78)
    Vec3 bar;
    {
        Key key;
        key.text = bar_8038c1ec;
        read_800fc2f0(&key, &bar);
    }
    self->position = *(Ptr32<Words>)value_80178ec4(self->pos);
    self->mesh->vtable->set_position(self->mesh, &self->position, 0);
    mesh_set_80189450(self->mesh, 1);
    mesh_alloc_8018920c(self->mesh, 1);
    Rgba c = colour_804af024;
    c.a = count_80178d1c(self->next);
    mesh_a_80189828(self->mesh)[0] = 0;
    mesh_flags_80189704(self->mesh)[0] = 1;
    *mesh_colours_80189760(self->mesh) = c;
    Ptr32<Vec2> b = mesh_b_80189884(self->mesh);
    float h = half_8038c214[0];
    b->x = h;
    b->y = h;
    Ptr32<Vec2> d = mesh_c_801898e0(self->mesh);
    float one = one_8038c218[0];
    d->x = one;
    d->y = one;
    MessageId i0, i1, i2, i3, i4;
    LISTEN(i0, cache_804af038, msg44)
    LISTEN(i1, cache_804af040, msg48)
    LISTEN(i2, cache_804af048, msg52)
    LISTEN(i3, cache_804af050, msg56)
    LISTEN(i4, cache_804af058, msg60)
    Ptr32<Sounds> a = engine_804b1788->sound;
    a->vtable->open(a, sound_8038c204, &self->sound);
}



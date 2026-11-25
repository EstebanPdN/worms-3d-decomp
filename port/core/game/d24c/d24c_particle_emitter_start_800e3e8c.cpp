#include "w3d_ptr.h"
#line 1 "d24c_particle_emitter_start_800e3e8c.cpp"
// d24c: 0x800e3e8c (844 bytes). Start a particle emitter entity: subscribe the
// three message handlers, initialise the sub-object at +28, read the settings,
// choose the emission mode (+172: 1 with a name, 2 with a fallback, else 0) and
// announce the entity when a mode is set; build the emitter handle (+272); when
// trigger balls are enabled allocate one reference per particle and load
// "Trigger.Ball" into every stride-th slot, clearing the others; clear the
// 64-byte table at +284; assert (ParticleEmitterLogicEntity.cpp:409) when a
// checked emitter derives from either of the two listed classes. Names are
// inferred. MessageId is a one-short struct: as a plain short the three ids take
// the lowest stack slots, as a struct they land after the vector and the string,
// as in the original. 0x8015adf4 is declared with a status return. One-word
// String and handle classes with user copy constructors (d24r).
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
    Ptr32<void> unknown14[17];
    Ptr32<void (Ptr32<Object>, int)> enable;  // +88
};
struct Object { Ptr32<ObjectVtable> vtable; };
extern "C" Ptr32<void> array_new_801fe220(size_t);
struct Ref {
    Ptr32<Object> value;
    Ref() : value(0) {}
    ~Ref() { if (value) value->vtable->release(value); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Object *)w3d_p.get()); }
 void operator=(Object *v) {
        if (value) value->vtable->release(value);
        value = v;
    }
    static void *operator new[](__SIZE_TYPE__ n) { return array_new_801fe220(n); }
};
struct Type { unsigned char unknown00[20]; Ptr32<const Type> parent; };
struct Settings {
    unsigned char u0[332];
    struct w3d_anon_1981 { unsigned char u[24]; int value; }; Ptr32<w3d_anon_1981> fallback;  // +332
    Ptr32<char> name;                                            // +336
    unsigned char u340[44];
    float scale;                                           // +384
    unsigned char u388[12];
    unsigned short count;                                  // +400
    unsigned char u402[12];
    unsigned short stride;                                 // +414
    unsigned char u416[48];
    int check;                                             // +464
    unsigned char u468[12];
    int flagged;                                           // +480
    unsigned char u484[4];
    int balls;                                             // +488
};
struct Vec3 { float x, y, z; };
struct Emitter {
    struct V { Ptr32<void> u[5]; Ptr32<Ptr32<const Type> (Ptr32<Emitter>)> type; }; Ptr32<struct V> vtable;  // +0
    unsigned char u4[16];
    int id;              // +20
    unsigned char u24[4];
    unsigned char sub[128]; // +28
    Ptr32<void> owner;         // +156
    unsigned char u160[12];
    int mode;            // +172
    unsigned char u176[4];
    unsigned flags;      // +180
    unsigned char u184[76];
    int msg260;          // +260
    int msg264;          // +264
    int msg268;          // +268
    Ptr32<void> handle;        // +272
    int has_balls;       // +276
    Ptr32<Ref> balls;          // +280
    unsigned char table[64]; // +284
    unsigned char assert_arg[4]; // +348
};
extern "C" short message_id_8015f5a0(Ptr32<int>, int);
struct MessageId { short value; };
extern "C" int subscribe_80162024(Ptr32<Emitter>, Ptr32<MessageId>, Ptr32<int>);
extern "C" int sub_init_800dec8c(Ptr32<void>);
extern "C" Ptr32<void> identity_80341584(Ptr32<void>);
extern "C" Ptr32<Settings> settings_801797b4(Ptr32<void>);
extern "C" Ptr32<void> arena_801613f0(Ptr32<void>, int);
extern "C" Ptr32<void> message_init_800c1620(Ptr32<void>, Ptr32<int>);
extern "C" int message_post_8016239c(Ptr32<void>);
extern "C" Ptr32<void> heap_alloc_802098d8(Ptr32<void>, int);
extern "C" Ptr32<void> handle_ctor_801261bc(Ptr32<void>, float, Ptr32<Vec3>, int, int);
extern "C" int handle_query_80126308(Ptr32<void>, int);
extern "C" int load_8015adf4(Ptr32<String>, Ptr32<Ref>, unsigned char);
extern "C" Ptr32<void> memset(Ptr32<void>, int, size_t);
extern "C" int assert_80022e20(Ptr32<const char>, Ptr32<const char>, int, Ptr32<void>);
extern int cache_804aed4c, cache_804aed44, cache_804aed6c;
extern Ptr32<void> arena_804b1754;
extern unsigned char pool_804af5bc;
extern const float zero_8038a094[];
extern const char ball_8038a050[];
extern const char title_8038a060[];
extern const char file_8038a074[];
extern const Type type_80361860[];
extern const Type type_803618f0[];
inline bool is_a(Ptr32<const Type> t, Ptr32<const Type> target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
extern "C" void d24c_particle_emitter_start_800e3e8c(Ptr32<Emitter> self) {
    MessageId a, b, c;
    a.value = message_id_8015f5a0(&cache_804aed4c, 1);
    subscribe_80162024(self, &a, &self->msg264);
    b.value = message_id_8015f5a0(&cache_804aed44, 1);
    subscribe_80162024(self, &b, &self->msg260);
    c.value = message_id_8015f5a0(&cache_804aed6c, 1);
    subscribe_80162024(self, &c, &self->msg268);
    sub_init_800dec8c(self->sub);
    Ptr32<Settings> s = settings_801797b4(identity_80341584(self->owner));
    if (s->flagged == 1) self->flags |= 520;
    if (((Ptr32<unsigned short>)s->name)[-2] == 0) {
        if (s->fallback->value) self->mode = 2;
        else self->mode = 0;
    } else self->mode = 1;
    if (self->mode) {
        Ptr32<void> m = arena_801613f0(arena_804b1754, 12);
        int id = self->id;
        message_post_8016239c(message_init_800c1620(m, &id));
    }
    Vec3 v;
    Ptr32<Vec3> p = &v;
    float z = zero_8038a094[0];
    Ptr32<unsigned char> table = self->table;
    v.x = z;
    p->y = z;
    p->z = z;
    Ptr32<void> h = heap_alloc_802098d8(&pool_804af5bc, 8);
    h = handle_ctor_801261bc(h, s->scale, p, 0, 1);
    self->handle = h;
    handle_query_80126308(h, self->id);
    if (s->balls) {
        self->has_balls = 1;
        self->balls = w3d::new_array<Ref>(s->count);
        for (unsigned i = 0; i < s->count; i++) {
            if (i % s->stride == 0) {
                {
                    String name(ball_8038a050);
                    load_8015adf4(&name, &self->balls[i], 255);
                }
                self->balls[i].value->vtable->enable(self->balls[i].value, 0);
            } else {
                self->balls[i] = 0;
            }
        }
    }
    memset(table, 0, 64);
    if (s->check) {
        if (is_a(self->vtable->type(self), type_80361860) || is_a(self->vtable->type(self), type_803618f0))
            assert_80022e20(title_8038a060, file_8038a074, 409, self->assert_arg);
    }
}



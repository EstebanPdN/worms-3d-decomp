#include "w3d_ptr.h"
#line 1 "d24c_actor_settings_start_800d5d44.cpp"
// d24c: 0x800d5d44 (596 bytes). Start an actor: place it, subscribe four message
// handlers (+72..+84), read the water level, gravity and low gravity settings
// into retained references (+116, +108, +112), post a creation message with the
// entity id, and bind the member handle at +64 to the id. Names are inferred.
// The holder is one function-level stack object with no destructor,
// cleared and released by hand around each read: this keeps its address and the
// zero in saved registers from before the first call. MessageId is a one-short
// struct, which places the ids after the holder. One-word String and handle
// classes with user copy constructors (d24r).
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
struct Key { Ptr32<const char> text; };
extern "C" int read_800fc1b0(Ptr32<Key>, Ptr32<void>);

struct Holder {
    Ptr32<Object> value;
    Holder() {}
    Holder(const Holder &o) : value(o.value) { if (value) value->vtable->retain(value); }
};
#define READ(slot, name, cast) { \
    out->value = none; \
    Key key; \
    key.text = name; \
    read_800fc1b0(&key, out); \
    Object *o = cast(out->value); \
    if (o) o->vtable->retain(o); \
    if (slot) slot->vtable->release(slot); \
    slot = o; \
    if (out->value) out->value->vtable->release(out->value); \
}

struct MessageId { short value; };
struct Actor {
    unsigned char u0[20];
    int id;                  // +20
    unsigned char u24[40];
    unsigned char handle[8]; // +64
    int m72, m76, m80, m84;  // +72..+84
    unsigned char u88[20];
    Ptr32<Object> gravity;         // +108
    Ptr32<Object> low_gravity;     // +112
    Ptr32<Object> water;           // +116
};
extern "C" void place_800d5ff0(Ptr32<Actor>);
extern "C" short message_id_8015f5a0(Ptr32<int>, int);
extern "C" int subscribe_80162024(Ptr32<Actor>, Ptr32<MessageId>, Ptr32<int>);
extern "C" Ptr32<void> arena_801613f0(Ptr32<void>, int);
extern "C" Ptr32<void> msg_init_800c1620(Ptr32<void>, Ptr32<int>);
extern "C" int post_8016239c(Ptr32<void>);
extern "C" int member_query_80126308(Ptr32<void>, int);
extern "C" Ptr32<Object> as_a_80342a74(Ptr32<Object>);
extern Ptr32<void> arena_804b1754;
extern int c1_804aea58, c2_804aea60, c3_804aea68, c4_804aea78;
extern const char water_80388e20[], gravity_80388e2c[], low_80388e34[];
#define LISTEN(id, cache, field) \
    id.value = message_id_8015f5a0(&cache, 1); \
    subscribe_80162024(self, &id, &self->field);
extern "C" void d24c_actor_settings_start_800d5d44(Ptr32<Actor> self) {
    Holder h;
    Ptr32<Holder> out = &h;
    Ptr32<Object> none = 0;
    place_800d5ff0(self);
    MessageId i0, i1, i2, i3;
    LISTEN(i0, c1_804aea58, m72)
    LISTEN(i1, c2_804aea60, m76)
    LISTEN(i2, c3_804aea68, m80)
    LISTEN(i3, c4_804aea78, m84)
    READ(self->water, water_80388e20, as_a_80342a74)
    READ(self->gravity, gravity_80388e2c, as_a_80342a74)
    READ(self->low_gravity, low_80388e34, as_a_80342a74)
    Ptr32<void> m = arena_801613f0(arena_804b1754, 12);
    int id = self->id;
    post_8016239c(msg_init_800c1620(m, &id));
    member_query_80126308(self->handle, self->id);
}



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
    char *text;
    String(const char *);
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);       // +12
    void (*release)(Object *);      // +16
};
struct Object { ObjectVtable *vtable; };
struct Key { const char *text; };
extern "C" int read_800fc1b0(Key *, void *);

struct Holder {
    Object *value;
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
    Object *gravity;         // +108
    Object *low_gravity;     // +112
    Object *water;           // +116
};
extern "C" void place_800d5ff0(Actor *);
extern "C" short message_id_8015f5a0(int *, int);
extern "C" int subscribe_80162024(Actor *, MessageId *, int *);
extern "C" void *arena_801613f0(void *, int);
extern "C" void *msg_init_800c1620(void *, int *);
extern "C" int post_8016239c(void *);
extern "C" int member_query_80126308(void *, int);
extern "C" Object *as_a_80342a74(Object *);
extern void *arena_804b1754;
extern int c1_804aea58, c2_804aea60, c3_804aea68, c4_804aea78;
extern const char water_80388e20[], gravity_80388e2c[], low_80388e34[];
#define LISTEN(id, cache, field) \
    id.value = message_id_8015f5a0(&cache, 1); \
    subscribe_80162024(self, &id, &self->field);
extern "C" void d24c_actor_settings_start_800d5d44(Actor *self) {
    Holder h;
    Holder *out = &h;
    Object *none = 0;
    place_800d5ff0(self);
    MessageId i0, i1, i2, i3;
    LISTEN(i0, c1_804aea58, m72)
    LISTEN(i1, c2_804aea60, m76)
    LISTEN(i2, c3_804aea68, m80)
    LISTEN(i3, c4_804aea78, m84)
    READ(self->water, water_80388e20, as_a_80342a74)
    READ(self->gravity, gravity_80388e2c, as_a_80342a74)
    READ(self->low_gravity, low_80388e34, as_a_80342a74)
    void *m = arena_801613f0(arena_804b1754, 12);
    int id = self->id;
    post_8016239c(msg_init_800c1620(m, &id));
    member_query_80126308(self->handle, self->id);
}

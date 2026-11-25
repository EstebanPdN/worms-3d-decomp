#include "w3d_ptr.h"
#line 1 "d25i_trigger_zone_start_80125108.cpp"
// d25i: 0x80125108. Trigger zone start: subscribes two cached messages, finds
// the spawn point named by Trigger.Spawn, reads the Trigger settings,
// validates radius and hit points with error messages, posts a created message
// when Trigger.Visibility is 1, then configures the collision handle member at
// +100.
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;       // +12
    Ptr32<void (Ptr32<Object>)> release;      // +16
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Key { Ptr32<const char> name; };
struct Ref {
    Ptr32<Object> value;
    Ref() { value = 0; }
    Ref(const Ref &);
    ~Ref() { if (value) value->vtable->release(value); }
};
extern "C" int read_setting_800fc1b0(Ptr32<Key>, Ptr32<void>);
static inline void assign(Ptr32<Object> &slot, Ptr32<Object> value) {
    if (value) value->vtable->retain(value);
    if (slot) slot->vtable->release(slot);
    slot = value;
}
struct MessageId { unsigned short value; };
extern "C" unsigned short cached_id_8015f5a0(Ptr32<void>, int);

struct Vec3 { float x, y, z; };
struct Message;
struct ObjectId { int value; };
struct Trigger {
    unsigned char unknown00[20];
    int id;              // +20
    unsigned char unknown18[4];
    Vec3 position;       // +28
    float radius;        // +40
    int index;           // +44
    int hit_points;      // +48
    int team_destroy;    // +52
    int team_collect;    // +56
    int worm_collect;    // +60
    int sheep_collect;   // +64
    int payload_collect; // +68
    int affects_ai;      // +72
    unsigned char unknown4c[8];
    int girder_collect;  // +84
    unsigned char unknown58[4];
    int sub_a;           // +92
    int sub_b;           // +96
    unsigned char member[8]; // +100
    Ptr32<Object> active_worm; // +108
};
extern "C" int subscribe_80162024(Ptr32<void>, Ptr32<MessageId>, Ptr32<void>);
extern "C" int read_key_800fc2b0(Ptr32<Key>, Ptr32<Key>);
extern "C" int read_int_800fc1f0(Ptr32<Key>, Ptr32<int>);
extern "C" int read_float_800fc270(Ptr32<Key>, Ptr32<float>);
extern "C" void find_spawn_801254a0(Ptr32<Trigger>, Ptr32<const char>);
extern "C" void post_text_8012568c(Ptr32<Trigger>, Ptr32<const char>);
extern "C" Ptr32<void> arena_alloc_801613f0(Ptr32<void>, int);
extern "C" Ptr32<Message> created_init_800c1620(Ptr32<void>, Ptr32<ObjectId>);
extern "C" int post_8016239c(Ptr32<Message>);
extern "C" void member_slot_801262e4(Ptr32<void>, int);
extern "C" int filter_flags_80125e00(Ptr32<Trigger>);
extern "C" void member_word_8012632c(Ptr32<void>, int);
extern "C" void member_id_80126308(Ptr32<void>, int);
extern "C" void member_vec_801262c0(Ptr32<void>, Ptr32<Vec3>);
extern "C" void member_float_8012629c(Ptr32<void>, float);
extern Ptr32<void> arena_804b1754;
extern char cache_804af544, cache_804af54c;
extern const char n_8039b934[], n_8039b944[], n_8039b954[], n_8039b964[], n_8039b978[], n_8039b98c[], n_8039b9a0[], n_8039b9b4[], n_8039b9cc[], n_8039b9e0[], n_8039b9f8[], n_8039ba10[], n_8039ba20[], n_8039ba40[], n_8039ba64[];
extern "C" Ptr32<Object> cast_803426b4(Ptr32<Object>);
static inline void load_803426b4(Ptr32<Object> &slot, Ptr32<const char> name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, cast_803426b4(found.value));
}

static inline void read_int(Ptr32<int> out, Ptr32<const char> name) {
    Key key;
    key.name = name;
    read_int_800fc1f0(&key, out);
}
extern "C" void d25i_trigger_zone_start_80125108(Ptr32<Trigger> self) {
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af544, 1); subscribe_80162024(self, &id, &self->sub_a); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af54c, 1); subscribe_80162024(self, &id, &self->sub_b); }
    Key spawn;
    Key spawn_name;
    spawn_name.name = 0;
    spawn.name = n_8039b934;
    read_key_800fc2b0(&spawn, &spawn_name);
    find_spawn_801254a0(self, spawn_name.name);
    read_int(&self->index, n_8039b944);
    {
        Key key;
        key.name = n_8039b954;
        read_float_800fc270(&key, &self->radius);
    }
    read_int(&self->hit_points, n_8039b964);
    read_int(&self->team_collect, n_8039b978);
    read_int(&self->worm_collect, n_8039b98c);
    read_int(&self->team_destroy, n_8039b9a0);
    read_int(&self->sheep_collect, n_8039b9b4);
    read_int(&self->affects_ai, n_8039b9cc);
    read_int(&self->payload_collect, n_8039b9e0);
    Key girder_key;
    girder_key.name = n_8039b9f8;
    int girder = 0;
    read_int_800fc1f0(&girder_key, &girder);
    if (girder) self->girder_collect = 1;
    load_803426b4(self->active_worm, n_8039ba10);
    if (self->radius <= 0.0f) {
        post_text_8012568c(self, n_8039ba20);
        self->radius = 1.0f;
    }
    if (self->hit_points <= 0) {
        post_text_8012568c(self, n_8039ba40);
        self->hit_points = 1;
    }
    Key visibility_key;
    visibility_key.name = n_8039ba64;
    int visibility;
    read_int_800fc1f0(&visibility_key, &visibility);
    if (visibility == 1) {
        Ptr32<void> m = arena_alloc_801613f0(arena_804b1754, 12);
        ObjectId id;
        id.value = self->id;
        post_8016239c(created_init_800c1620(m, &id));
    }
    Ptr32<void> member = self->member;
    member_slot_801262e4(member, 64);
    member_word_8012632c(member, filter_flags_80125e00(self));
    member_id_80126308(member, self->id);
    member_vec_801262c0(member, &self->position);
    member_float_8012629c(member, self->radius);
}



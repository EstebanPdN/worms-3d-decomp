#include "w3d_ptr.h"
#line 1 "d30c_rope_start_800ce48c.cpp"
// d30c: 0x800ce48c. Ninja rope start-up: subscribes eighteen cached messages, publishes the aim limits, posts the created messages, binds the retained rope settings and sets up its timer. Names are inferred; classes are partial views.
struct Object;
struct ObjectVtable { Ptr32<void> unknown00[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Key { Ptr32<const char> name; };
struct Ref {
    Ptr32<Object> value;
    Ref() { value = 0; }
    Ref(const Ref &);
    ~Ref() { if (value) value->vtable->release(value); }
};
extern "C" int read_setting_800fc1b0(Ptr32<Key>, Ptr32<void>);
extern "C" int read_int_800fc1f0(Ptr32<Key>, Ptr32<void>);
extern "C" int write_float_800fc4c8(Ptr32<Key>, float);
static inline void assign(Ptr32<Object> &slot, Ptr32<Object> value) {
    if (value) value->vtable->retain(value);
    if (slot) slot->vtable->release(slot);
    slot = value;
}
extern "C" Ptr32<Object> cast_80342a74(Ptr32<Object>);
extern "C" Ptr32<Object> cast_803426b4(Ptr32<Object>);
static inline void load(Ptr32<Object> &slot, Ptr32<const char> name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, cast_80342a74(found.value));
}
static inline void load2(Ptr32<Object> &slot, Ptr32<const char> name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, cast_803426b4(found.value));
}
struct MessageId { unsigned short value; };
extern "C" short cached_id_8015f5a0(Ptr32<void>, int);
struct Message;
extern "C" Ptr32<Message> arena_alloc_801613f0(Ptr32<void>, int);
extern "C" Ptr32<Message> message_init_800c1620(Ptr32<Message>, Ptr32<int>);
extern "C" Ptr32<Message> target_init_801190b4(Ptr32<Message>, unsigned short, int);
extern "C" int message_post_8016239c(Ptr32<void>);
struct Plain { unsigned short id; Ptr32<void> text; };
extern Ptr32<void> g_arena_804b1754;
extern char empty_8040db38[];
struct Timer { int u; };
extern "C" void timer_mode_801262e4(Ptr32<Timer>, int);
extern "C" void timer_rate_8012632c(Ptr32<Timer>, int);
extern "C" int timer_owner_80126308(Ptr32<Timer>, int);
extern "C" int timer_time_8012629c(Ptr32<Timer>, float);
struct Rope;
extern "C" int subscribe_80162024(Ptr32<Rope>, Ptr32<MessageId>, Ptr32<void>);
struct Rope {
    char u0[20]; int id; char u24[24]; int shots; char u52[76];
    int subs[18];
    Ptr32<Object> f200; Ptr32<Object> f204; Ptr32<Object> f208; Ptr32<Object> f212; Ptr32<Object> f216; Ptr32<Object> f220; Ptr32<Object> f224; Ptr32<Object> f228; Ptr32<Object> f232; Ptr32<Object> f236; Ptr32<Object> f240; Ptr32<Object> f244; Ptr32<Object> f248; Ptr32<Object> f252;
    char u256[16]; int worm; char u276[32]; Timer timer;
};
extern char cache_804ae8a8;
extern char cache_804ae8b0;
extern char cache_804ae8b8;
extern char cache_804ae8d8;
extern char cache_804ae8e0;
extern char cache_804ae8e8;
extern char cache_804ae8f0;
extern char cache_804ae8f8;
extern char cache_804ae900;
extern char cache_804ae908;
extern char cache_804ae910;
extern char cache_804ae928;
extern char cache_804ae930;
extern char cache_804ae918;
extern char cache_804ae920;
extern char cache_804ae8c8;
extern char cache_804ae980;
extern char cache_804ae988;
extern char cache_804ae898, cache_804ae890, cache_804ae9a8;
extern const char n_80387f00[];
extern const char n_80387f14[];
extern const char n_80387f28[];
extern const char n_80387f30[];
extern const char n_80387f48[];
extern const char n_80387f58[];
extern const char n_80387f68[];
extern const char n_80387f78[];
extern const char n_80387f94[];
extern const char n_80387fb0[];
extern const char n_80387fc8[];
extern const char n_80387fe4[];
extern const char n_80388000[];
extern const char n_80388014[];
extern const char n_80388034[];
extern const char n_80388044[];
extern const char n_80388060[];
extern const char n_80388078[];
static inline void post_plain(Ptr32<char> cache) {
    Ptr32<Plain> m = (Ptr32<Plain>)arena_alloc_801613f0(g_arena_804b1754, 8);
    m->id = cached_id_8015f5a0(cache, 1);
    m->text = empty_8040db38;
    message_post_8016239c(m);
}
extern "C" void d30c_rope_start_800ce48c(Ptr32<Rope> self) {
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae8a8, 1); subscribe_80162024(self, &id, &self->subs[0]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae8b0, 1); subscribe_80162024(self, &id, &self->subs[1]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae8b8, 1); subscribe_80162024(self, &id, &self->subs[2]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae8d8, 1); subscribe_80162024(self, &id, &self->subs[3]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae8e0, 1); subscribe_80162024(self, &id, &self->subs[4]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae8e8, 1); subscribe_80162024(self, &id, &self->subs[5]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae8f0, 1); subscribe_80162024(self, &id, &self->subs[6]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae8f8, 1); subscribe_80162024(self, &id, &self->subs[7]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae900, 1); subscribe_80162024(self, &id, &self->subs[8]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae908, 1); subscribe_80162024(self, &id, &self->subs[9]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae910, 1); subscribe_80162024(self, &id, &self->subs[10]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae928, 1); subscribe_80162024(self, &id, &self->subs[11]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae930, 1); subscribe_80162024(self, &id, &self->subs[12]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae918, 1); subscribe_80162024(self, &id, &self->subs[13]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae920, 1); subscribe_80162024(self, &id, &self->subs[14]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae8c8, 1); subscribe_80162024(self, &id, &self->subs[15]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae980, 1); subscribe_80162024(self, &id, &self->subs[16]); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae988, 1); subscribe_80162024(self, &id, &self->subs[17]); }
    { Key k; k.name = n_80387f00; write_float_800fc4c8(&k, -0.5235988f); }
    { Key k; k.name = n_80387f14; write_float_800fc4c8(&k, 1.5707964f); }
    message_post_8016239c(target_init_801190b4(arena_alloc_801613f0(g_arena_804b1754, 12), cached_id_8015f5a0(&cache_804ae898, 1), self->id));
    post_plain(&cache_804ae890);
    { Ptr32<Message> m = arena_alloc_801613f0(g_arena_804b1754, 12); int id = self->id; message_post_8016239c(message_init_800c1620(m, &id)); }
    load(self->f200, n_80387f28);
    load(self->f204, n_80387f30);
    { Key k; k.name = n_80387f48; read_int_800fc1f0(&k, &self->worm); }
    load(self->f208, n_80387f58);
    load(self->f212, n_80387f68);
    load(self->f216, n_80387f78);
    load2(self->f220, n_80387f94);
    load(self->f224, n_80387fb0);
    load(self->f228, n_80387fc8);
    load(self->f232, n_80387fe4);
    load(self->f236, n_80388000);
    load(self->f240, n_80388014);
    load(self->f244, n_80388034);
    load(self->f248, n_80388044);
    load(self->f252, n_80388060);
    { Key k; k.name = n_80388078; read_int_800fc1f0(&k, &self->shots); }
    timer_mode_801262e4(&self->timer, 0);
    timer_rate_8012632c(&self->timer, 25);
    timer_owner_80126308(&self->timer, self->id);
    timer_time_8012629c(&self->timer, 5.0f);
    post_plain(&cache_804ae9a8);
}



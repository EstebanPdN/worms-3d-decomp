#include "w3d_ptr.h"
#line 1 "d25i_game_stats_start_8010a0f0.cpp"
// d25i: 0x8010a0f0. Game stats tracker start: subscribes 14 cached messages;
// when GameOver.RoundNumber is 0, clears the twelve counters of each of the 16
// GameStats.Worm entries and resets GameStats.StatString; then clears the
// tracker's counts and +120. Descriptor_80178474 has its two written words;
// String and handles have one word and a user copy constructor.
struct String {
    Ptr32<char> text;
    String();
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
extern "C" void string_format_8020c510(Ptr32<String>, Ptr32<const char>, ...);
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;       // +12
    Ptr32<void (Ptr32<Object>)> release;      // +16
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Key { Ptr32<const char> name; };
// Owned type descriptor released through 0x80178474 (two written words).
struct Descriptor_80178474 {
    Ptr32<void> value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Handle {
    Ptr32<Object> value;
    Handle() : value(0) {}
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Object *)w3d_p.get()) {}
 Handle(Object *next) : value(next) { if (value) value->vtable->retain(value); }
    Handle(const Handle &);
    ~Handle() { if (value) value->vtable->release(value); }
    void assign(Ptr32<Object> next) {
        if (next) {
            next->vtable->retain(next);
            if (value) value->vtable->release(value);
            value = next;
        }
    }
};
struct Stats {
    unsigned char unknown00[20];
    int values[12];  // +20
};
extern "C" int read_setting_800fc1b0(Ptr32<Key>, Ptr32<void>);
extern "C" int read_int_800fc230(Ptr32<Key>, Ptr32<int>);
extern "C" int read_text_800fc550(Ptr32<Key>, Ptr32<const char>);
extern "C" Ptr32<void> as_table_80341584(Ptr32<Object>);
extern "C" Ptr32<Object> table_get_80179598(Ptr32<void>, Ptr32<Descriptor_80178474>);
extern "C" void clear_counts_80109ae4(Ptr32<void>);
struct MessageId { unsigned short value; };
extern "C" unsigned short cached_id_8015f5a0(Ptr32<void>, int);
extern "C" int subscribe_80162024(Ptr32<void>, Ptr32<MessageId>, Ptr32<void>);
struct Tracker {
    unsigned char unknown00[28];
    int sub28;  // +28
    int sub32;  // +32
    int sub36;  // +36
    int sub40;  // +40
    int sub44;  // +44
    int sub48;  // +48
    int sub52;  // +52
    int sub56;  // +56
    int sub60;  // +60
    int sub64;  // +64
    int sub68;  // +68
    int sub72;  // +72
    int sub76;  // +76
    int sub80;  // +80
    unsigned char unknown54[36];
    int value120;  // +120
};
extern char cache_804af238;
extern char cache_804af248;
extern char cache_804af240;
extern char cache_804af250;
extern char cache_804af258;
extern char cache_804af260;
extern char cache_804af268;
extern char cache_804af270;
extern char cache_804af278;
extern char cache_804af280;
extern char cache_804af288;
extern char cache_804af290;
extern char cache_804af298;
extern char cache_804af2a0;
extern const char n_80399d20[], n_80399ce8[], n_80399cfc[], n_80399d38[];
extern "C" void d25i_game_stats_start_8010a0f0(Ptr32<Tracker> self) {
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af238, 1); subscribe_80162024(self, &id, &self->sub28); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af248, 1); subscribe_80162024(self, &id, &self->sub32); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af240, 1); subscribe_80162024(self, &id, &self->sub36); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af250, 1); subscribe_80162024(self, &id, &self->sub40); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af258, 1); subscribe_80162024(self, &id, &self->sub44); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af260, 1); subscribe_80162024(self, &id, &self->sub48); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af268, 1); subscribe_80162024(self, &id, &self->sub72); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af270, 1); subscribe_80162024(self, &id, &self->sub52); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af278, 1); subscribe_80162024(self, &id, &self->sub56); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af280, 1); subscribe_80162024(self, &id, &self->sub60); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af288, 1); subscribe_80162024(self, &id, &self->sub64); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af290, 1); subscribe_80162024(self, &id, &self->sub68); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af298, 1); subscribe_80162024(self, &id, &self->sub76); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af2a0, 1); subscribe_80162024(self, &id, &self->sub80); }
    Key round_key;
    round_key.name = n_80399d20;
    int round;
    read_int_800fc230(&round_key, &round);
    if (round == 0) {
        for (unsigned i = 0; i < 16; i++) {
            Descriptor_80178474 descriptor;
            Handle found;
            String name;
            string_format_8020c510(&name, n_80399ce8, i);
            Key key;
            key.name = name.text;
            read_setting_800fc1b0(&key, &found);
            Handle stats;
            {
                Handle value(table_get_80179598(as_table_80341584(found.value), &descriptor));
                stats.assign(value.value);
            }
            Ptr32<Stats> s = (Ptr32<Stats>)stats.value;
            s->values[11] = 0;
            s->values[10] = 0;
            s->values[9] = 0;
            s->values[8] = 0;
            s->values[7] = 0;
            s->values[6] = 0;
            s->values[5] = 0;
            s->values[4] = 0;
            s->values[3] = 0;
            s->values[2] = 0;
            s->values[1] = 0;
            s->values[0] = 0;
        }
        Key text_key;
        text_key.name = n_80399cfc;
        read_text_800fc550(&text_key, n_80399d38);
    }
    clear_counts_80109ae4(self);
    self->value120 = 0;
}



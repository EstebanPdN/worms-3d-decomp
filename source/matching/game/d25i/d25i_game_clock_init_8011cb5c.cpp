// d25i: 0x8011cb5c. Game clock setup: clears +104..+132, subscribes 18 cached
// messages to +28..+96, resolves the 13 retained clock settings (RoundTime
// through ElapsedRoundTime) into +136..+184 and sets ClockDisplayMode to 0
// through 0x80178d28. Handles have one word and a user copy constructor.
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);       // +12
    void (*release)(Object *);      // +16
};
struct Object { ObjectVtable *vtable; };
struct Key { const char *name; };
struct Ref {
    Object *value;
    Ref() { value = 0; }
    Ref(const Ref &);
    ~Ref() { if (value) value->vtable->release(value); }
};
extern "C" int read_setting_800fc1b0(Key *, void *);
static inline void assign(Object *&slot, Object *value) {
    if (value) value->vtable->retain(value);
    if (slot) slot->vtable->release(slot);
    slot = value;
}
struct MessageId { unsigned short value; };
extern "C" unsigned short cached_id_8015f5a0(void *, int);
extern "C" int subscribe_80162024(void *, MessageId *, void *);
extern "C" int set_value_80178d28(Object *, int *);
struct Clock {
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
    int sub84;  // +84
    int sub88;  // +88
    int sub92;  // +92
    int sub96;  // +96
    unsigned char unknown64[4];
    int value104;  // +104
    int value108;  // +108
    int value112;  // +112
    int value116;  // +116
    int value120;  // +120
    int value124;  // +124
    int value128;  // +128
    int value132;  // +132
    Object * round_time;  // +136
    Object * turn_time;  // +140
    Object * hot_seat_time;  // +144
    Object * post_activity_time;  // +148
    Object * retreat_time;  // +152
    Object * round_time_remaining;  // +156
    Object * turn_time_remaining;  // +160
    Object * hot_seat_time_remaining;  // +164
    Object * post_activity_time_remaining;  // +168
    Object * retreat_time_remaining;  // +172
    Object * elapsed_round_time;  // +176
    Object * clock_display_mode;  // +180
    Object * active_worm_index;  // +184
};
extern "C" Object *cast_803426b4(Object *);
static inline void load_803426b4(Object *&slot, const char *name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, cast_803426b4(found.value));
}
extern "C" Object *cast_80342a78(Object *);
static inline void load_80342a78(Object *&slot, const char *name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, cast_80342a78(found.value));
}
extern char cache_804af3b8;
extern char cache_804af3c0;
extern char cache_804af3c8;
extern char cache_804af3d0;
extern char cache_804af3e0;
extern char cache_804af3e8;
extern char cache_804af3f8;
extern char cache_804af400;
extern char cache_804af420;
extern char cache_804af428;
extern char cache_804af410;
extern char cache_804af438;
extern char cache_804af440;
extern char cache_804af448;
extern char cache_804af450;
extern char cache_804af458;
extern char cache_804af460;
extern char cache_804af468;
extern const char n_8039afe4[];  // "RoundTime"
extern const char n_8039aff0[];  // "TurnTime"
extern const char n_8039affc[];  // "HotSeatTime"
extern const char n_8039b008[];  // "PostActivityTime"
extern const char n_8039b01c[];  // "RetreatTime"
extern const char n_8039b028[];  // "RoundTimeRemaining"
extern const char n_8039b03c[];  // "TurnTimeRemaining"
extern const char n_8039b050[];  // "HotSeatTimeRemaining"
extern const char n_8039b068[];  // "PostActivityTimeRemaining"
extern const char n_8039b084[];  // "RetreatTimeRemaining"
extern const char n_8039b09c[];  // "ClockDisplayMode"
extern const char n_8039b0b0[];  // "ActiveWormIndex"
extern const char n_8039afd0[];  // "ElapsedRoundTime"
extern "C" void d25i_game_clock_init_8011cb5c(Clock *self) {
    self->value104 = 0;
    self->value108 = 0;
    self->value112 = 0;
    self->value116 = 0;
    self->value124 = 0;
    self->value120 = 0;
    self->value128 = 0;
    self->value132 = 0;
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af3b8, 1); subscribe_80162024(self, &id, &self->sub28); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af3c0, 1); subscribe_80162024(self, &id, &self->sub32); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af3c8, 1); subscribe_80162024(self, &id, &self->sub36); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af3d0, 1); subscribe_80162024(self, &id, &self->sub40); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af3e0, 1); subscribe_80162024(self, &id, &self->sub44); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af3e8, 1); subscribe_80162024(self, &id, &self->sub48); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af3f8, 1); subscribe_80162024(self, &id, &self->sub52); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af400, 1); subscribe_80162024(self, &id, &self->sub56); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af420, 1); subscribe_80162024(self, &id, &self->sub64); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af428, 1); subscribe_80162024(self, &id, &self->sub68); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af410, 1); subscribe_80162024(self, &id, &self->sub60); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af438, 1); subscribe_80162024(self, &id, &self->sub72); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af440, 1); subscribe_80162024(self, &id, &self->sub76); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af448, 1); subscribe_80162024(self, &id, &self->sub80); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af450, 1); subscribe_80162024(self, &id, &self->sub84); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af458, 1); subscribe_80162024(self, &id, &self->sub88); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af460, 1); subscribe_80162024(self, &id, &self->sub92); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804af468, 1); subscribe_80162024(self, &id, &self->sub96); }
    load_803426b4(self->round_time, n_8039afe4);
    load_803426b4(self->turn_time, n_8039aff0);
    load_803426b4(self->hot_seat_time, n_8039affc);
    load_803426b4(self->post_activity_time, n_8039b008);
    load_803426b4(self->retreat_time, n_8039b01c);
    load_803426b4(self->round_time_remaining, n_8039b028);
    load_803426b4(self->turn_time_remaining, n_8039b03c);
    load_803426b4(self->hot_seat_time_remaining, n_8039b050);
    load_803426b4(self->post_activity_time_remaining, n_8039b068);
    load_803426b4(self->retreat_time_remaining, n_8039b084);
    load_80342a78(self->clock_display_mode, n_8039b09c);
    load_803426b4(self->active_worm_index, n_8039b0b0);
    load_80342a78(self->elapsed_round_time, n_8039afd0);
    int zero = 0;
    set_value_80178d28(self->clock_display_mode, &zero);
}

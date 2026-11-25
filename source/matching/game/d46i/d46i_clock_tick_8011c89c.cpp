struct Key { const char *name; };
struct Message { unsigned short id; void *vtable; };
struct Clock {
    unsigned char unknown00[104];
    int stopped;        // +104
    int hot_seat;       // +108
    int round;          // +112
    int post_activity;  // +116
    int retreat;        // +120
    int turn;           // +124
    int round_hold;     // +128
    int turn_hold;      // +132
    unsigned char unknown88[20];
    void *round_left;   // +156
    void *hot_seat_left;// +160
    void *post_left;    // +164
    void *retreat_left; // +168
    void *turn_left;    // +172
    unsigned char unknownb0[12];
    void *mode;         // +188
};
extern "C" int mode_value_80178d1c(void *);
extern "C" int value_80178c48(void *);
extern "C" int read_int_800fc230(Key *, int *);
extern "C" int write_int_800fc43c(Key *, int);
extern "C" Message *arena_alloc_801613f0(void *, int);
extern "C" int cached_id_8015f5a0(void *, int);
extern "C" void post_8016239c(Message *);
extern "C" void set_round_8011d7d8(Clock *, int);
extern "C" void set_post_8011d804(Clock *, int);
extern "C" void set_retreat_8011d850(Clock *, int);
extern "C" void set_hot_seat_8011d78c(Clock *, int);
extern "C" void set_turn_8011d89c(Clock *, int);
extern void *arena_804b1754;
extern int paused_804aabe8;
extern char cache_804af3d8, cache_804af408, cache_804af418, cache_804af3f0, cache_804af430;
extern const char n_8039afd0[];
extern unsigned char vtable_8040db38[];
static inline void post_timeout(void *cache) {
    Message *m = arena_alloc_801613f0(arena_804b1754, 8);
    m->id = cached_id_8015f5a0(cache, 1);
    m->vtable = vtable_8040db38;
    post_8016239c(m);
}
extern "C" int w3d_d46i_clock_tick_8011c89c(Clock *self) {
    int in_menu = mode_value_80178d1c(self->mode) == 14;
    int paused = paused_804aabe8;
    if (self->stopped) return 10;
    int value = self->round_hold;
    if (!value && !in_menu) {
        Key key;
        key.name = n_8039afd0;
        int elapsed = 0;
        read_int_800fc230(&key, &elapsed);
        elapsed += 10;
        Key key2;
        key2.name = n_8039afd0;
        write_int_800fc43c(&key2, elapsed);
    }
    if (self->round && !self->round_hold && !in_menu) {
        int left = value_80178c48(self->round_left) - 10;
        if (left < 0) {
            post_timeout(&cache_804af3d8);
            self->round = 0;
            left = 0;
        }
        set_round_8011d7d8(self, left);
    }
    int post = self->post_activity;
    if (post) {
        int left = value_80178c48(self->post_left) - 10;
        if (left < 0) {
            self->post_activity = 0;
            post_timeout(&cache_804af408);
            left = 0;
        }
        set_post_8011d804(self, left);
    } else if (self->retreat) {
        int left = value_80178c48(self->retreat_left) - 10;
        if (left < 0) {
            self->retreat = 0;
            post_timeout(&cache_804af418);
            left = 0;
        }
        set_retreat_8011d850(self, left);
    } else if (self->hot_seat && !self->turn_hold && !in_menu && !paused) {
        int left = value_80178c48(self->hot_seat_left) - 10;
        if (left < 0) {
            post_timeout(&cache_804af3f0);
            self->hot_seat = 0;
            left = 0;
        }
        set_hot_seat_8011d78c(self, left);
    } else {
        value = self->turn;
        if (value) {
        int left = value_80178c48(self->turn_left) - 10;
        if (left < 0) {
            self->turn = 0;
            post_timeout(&cache_804af430);
            left = 0;
        }
        set_turn_8011d89c(self, left);
        }
    }
    return 10;
}

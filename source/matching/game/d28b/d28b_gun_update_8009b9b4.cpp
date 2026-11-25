/* Gun weapon logic update (0x8009b9b4; messages name GunWeaponLogicEntity.cpp): returns 50 at once
 * while the scene timer 0x8006e71c is set, otherwise updates the wobble at +148, keeps the frame
 * delta through the static pair 0x804adfd0, lowers the cooldown at +116 and runs the state at +44:
 * 1 waits for the start time, posts the launch message and binds Weapon.GraphicalLaunchLocation, 2 fires
 * through 0x8009c87c counting AI.BulletCount, 3 and 4 wait for the worm value 0x80178c48 and restore
 * Worm.DisableMovementRef or end the turn, 5 finishes through 0x8015fd1c, 6 and 7 run the recovery
 * and reset. Class layouts are partial views with 4-byte virtual table entries; names are inferred
 * from the original instructions; strings, the float and caches are external views of original data.
 * The unit owns no data. */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; void *vtable; };
extern "C" char lbl_8040db38[];
extern "C" void *w3d_arena_alloc_801613f0(void *, int);
extern "C" int w3d_cached_message_id_8015f5a0(MessageCache *, int);
extern "C" int w3d_message_post_8016239c(void *);
extern void *lbl_804b1754;
static inline void Post(MessageCache *c) {
    Message *m = (Message *)w3d_arena_alloc_801613f0(lbl_804b1754, 8);
    m->id = w3d_cached_message_id_8015f5a0(c, 1);
    m->vtable = lbl_8040db38;
    w3d_message_post_8016239c(m);
}
struct PropertyKey { const char *name; PropertyKey(const char *n) : name(n) {} };
struct Effect { unsigned v[4]; };
struct Weapon {
    unsigned Shots() const { return shots; }
    unsigned Delay() const { return delay; }
    char unknown00[52]; int duration; char unknown56[136]; int recover; char unknown196[4];
    unsigned delay; unsigned shots; char unknown208[104]; int created; char unknown316[4]; int graphical;
};
struct Type { char unknown00[20]; Type *parent; };
struct Released { virtual void v0(); virtual void v1(); virtual void Release(); };
struct Entity {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual Type *Kind();
};
struct Gun : Entity {
    char unknown04[16]; int id; char unknown24[4]; void *weapon; char unknown32[4]; void *worm; char unknown40[4];
    int state; unsigned rate; unsigned fired; char unknown56[28];
    unsigned start; int elapsed; char unknown92[4]; Released *held; int disable; char unknown104[12];
    int cooldown; char unknown120[4]; unsigned end; char unknown128[20]; void *wobble;
    template <char *T> bool IsA() {
        Type *t = Kind();
        for (Type *x = (Type *)T; t != x; t = t->parent)
            if (t == t->parent) return false;
        return true;
    }
};
extern "C" int w3d_timer_is_one_8006e71c();
extern "C" void w3d_wobble_8009ddc4(void *, int);
extern "C" void *w3d_cast_80341584(void *);
extern "C" void *w3d_cast_803426b4(void *);
extern "C" Weapon *w3d_weapon_801797b4(void *);
extern "C" int w3d_value_80178c48(void *);
extern "C" int w3d_read_800fc2f0(PropertyKey *, Effect *);
extern "C" int w3d_read_int_800fc230(PropertyKey *, int *);
extern "C" int w3d_write_int_800fc43c(PropertyKey *, int);
extern "C" void w3d_bind_effect_8009d6d4(Gun *, Weapon *, Effect *);
extern "C" void *w3d_created_init_800c1620(void *, int *);
extern "C" int w3d_log_80022e20(const char *, const char *, int, void *);
extern "C" unsigned w3d_rate_8009c850(Gun *);
extern "C" void w3d_fire_8009c87c(Gun *, unsigned, Weapon *, void *);
extern "C" int w3d_sound_8009c0cc(Gun *);
struct Context { char unknown00[52]; unsigned now; };
extern "C" Context *w3d_context_80165254();
extern "C" int w3d_alliance_publish_80155b44(void *);
extern "C" unsigned w3d_alliance_count_80158f68(void *);
extern "C" void w3d_finish_8015fd1c(Gun *);
extern "C" void w3d_clear_8009c758(Gun *);
extern "C" int w3d_strcmp_802ef234(const char *, const char *);
struct Track { char unknown00[60]; const char *name; };
struct Camera { char unknown00[312]; int index; Track **tracks; char unknown320[500]; float zoom;
    Track *&At(int i) { return tracks[i]; } };
extern "C" int w3d_camera_set_80035714(Camera *, const char *, float);
extern "C" int w3d_query_800fcea0();
extern unsigned lbl_804adfd0; extern int lbl_804adfd4;
extern int lbl_804aabe8;
extern void *lbl_804ab400;
extern Camera *lbl_804aa8c8;
extern MessageCache lbl_804ae000, lbl_804ae008, lbl_804ae010, lbl_804ae030, lbl_804ae058, lbl_804ae068, lbl_804ae078, lbl_804ae080, lbl_804ae098;
extern "C" char lbl_80361860[], lbl_803618f0[];
extern float lbl_8038017c[];
extern char lbl_80380078[], lbl_80380088[], lbl_803800e8[], lbl_80380108[], lbl_8038011c[], lbl_80380138[], lbl_80380148[], lbl_80380150[];
static inline void Done(Gun *self) {
    Weapon *w = w3d_weapon_801797b4(w3d_cast_80341584(self->weapon));
    w3d_sound_8009c0cc(self);
    Context *c = w3d_context_80165254();
    self->end = c->now + w->recover;
    self->state = 6;
}
extern "C" int w3d_d28b_gun_update_8009b9b4(Gun *self, unsigned now) {
    int paused = w3d_timer_is_one_8006e71c();
    if (paused) return 50;
    if (self->wobble) w3d_wobble_8009ddc4(self->wobble, self->state == 2);
    if (lbl_804adfd4 == 0) { lbl_804adfd0 = now; lbl_804adfd4 = 1; }
    int dt = now - lbl_804adfd0;
    lbl_804adfd0 = now;
    if (self->cooldown > 0) self->cooldown -= dt;
    switch (self->state) {
    case 1:
        if (now >= self->start) {
            Weapon *w = w3d_weapon_801797b4(w3d_cast_80341584(self->weapon));
            if (w->graphical == 0) {
                Post(&lbl_804ae030);
                Effect effect;
                PropertyKey key(lbl_803800e8);
                w3d_read_800fc2f0(&key, &effect);
                w3d_bind_effect_8009d6d4(self, w, &effect);
            }
            if (w->created != 0) {
                void *m = w3d_arena_alloc_801613f0(lbl_804b1754, 12);
                int id = self->id;
                w3d_message_post_8016239c(w3d_created_init_800c1620(m, &id));
            }
            if (self->IsA<lbl_80361860>() || self->IsA<lbl_803618f0>())
                w3d_log_80022e20(lbl_80380108, lbl_8038011c, 304, &self->held);
            self->state = 2;
        }
        break;
    case 2: {
        Weapon *w = w3d_weapon_801797b4(w3d_cast_80341584(self->weapon));
        unsigned rate = w3d_rate_8009c850(self);
        unsigned shots = self->rate;
        self->fired += shots;
        PropertyKey key(lbl_80380078);
        w3d_write_int_800fc43c(&key, self->fired);
        if (self->fired >= w->Shots()) {
            Post(&lbl_804ae068);
            shots -= self->fired - w->Shots();
            if (now > self->start + w->Delay()) Done(self);
        } else if (w->graphical != 0) {
            lbl_804aabe8 = 1;
            self->state = 3;
        }
        w3d_fire_8009c87c(self, shots, w, (void *)rate);
        Post(&lbl_804ae058);
        break;
    }
    case 3:
        if (w3d_value_80178c48(w3d_cast_803426b4(self->worm)) <= 2) {
            Post(&lbl_804ae078);
            Post(&lbl_804ae080);
            Post(&lbl_804ae098);
            if (w3d_value_80178c48(w3d_cast_803426b4(self->worm)) <= 2) self->state = 4;
        }
        break;
    case 4:
        if (w3d_value_80178c48(w3d_cast_803426b4(self->worm)) <= 2) {
            lbl_804aabe8 = 0;
            w3d_alliance_publish_80155b44(lbl_804ab400);
            PropertyKey key(lbl_80380138);
            unsigned count;
            w3d_read_int_800fc230(&key, (int *)&count);
            if (w3d_alliance_count_80158f68(lbl_804ab400) > 1 && count <= 1) {
                Done(self);
            } else {
                PropertyKey disable(lbl_80380088);
                w3d_read_int_800fc230(&disable, &self->disable);
                PropertyKey clear(lbl_80380088);
                w3d_write_int_800fc43c(&clear, 0);
                self->state = 0;
                Camera *cam = lbl_804aa8c8;
                if (w3d_strcmp_802ef234(cam->At(cam->index)->name, lbl_80380148) == 0)
                    w3d_camera_set_80035714(lbl_804aa8c8, lbl_80380150, lbl_8038017c[0]);
            }
        }
        break;
    case 5:
        if (now > self->end) w3d_finish_8015fd1c(self);
        break;
    case 6:
        self->elapsed += dt;
        if (now > self->end) self->state = 7;
        break;
    case 7: {
        self->elapsed += dt;
        Weapon *w = w3d_weapon_801797b4(w3d_cast_80341584(self->weapon));
        if (self->elapsed > w->duration) {
            if (w->graphical != 0 && self->fired < w->shots) {
                Message *m = (Message *)w3d_arena_alloc_801613f0(lbl_804b1754, 8);
                int id = w3d_cached_message_id_8015f5a0(&lbl_804ae008, 1);
                char *t = lbl_8040db38;
                m->id = id;
                m->vtable = t;
                w3d_message_post_8016239c(m);
            }
            self->state = 0;
            if (self->held) self->held->Release();
            self->held = 0;
            w3d_clear_8009c758(self);
            self->fired = 0;
            PropertyKey key(lbl_80380078);
            w3d_write_int_800fc43c(&key, 0);
            lbl_804aa8c8->zoom = lbl_8038017c[0];
            Post(&lbl_804ae010);
            w3d_alliance_publish_80155b44(lbl_804ab400);
            PropertyKey ac(lbl_80380138);
            unsigned count;
            w3d_read_int_800fc230(&ac, (int *)&count);
            if (w3d_query_800fcea0() == 0 || (w3d_alliance_count_80158f68(lbl_804ab400) > 1 && count <= 1))
                Post(&lbl_804ae000);
        }
        break;
    }
    }
    return 50;
}

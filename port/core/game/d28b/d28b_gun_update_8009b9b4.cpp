#include "w3d_ptr.h"
#line 1 "d28b_gun_update_8009b9b4.cpp"
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
struct Message { unsigned short id; Ptr32<void> vtable; };
extern "C" char lbl_8040db38[];
extern "C" Ptr32<void> w3d_arena_alloc_801613f0(Ptr32<void>, int);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int w3d_message_post_8016239c(Ptr32<void>);
extern Ptr32<void> lbl_804b1754;
static inline void Post(Ptr32<MessageCache> c) {
    Ptr32<Message> m = (Ptr32<Message>)w3d_arena_alloc_801613f0(lbl_804b1754, 8);
    m->id = w3d_cached_message_id_8015f5a0(c, 1);
    m->vtable = lbl_8040db38;
    w3d_message_post_8016239c(m);
}
struct PropertyKey { Ptr32<const char> name; template <class W3dU> PropertyKey(Ptr32<W3dU> w3d_p) : PropertyKey((const char *)w3d_p.get()) {}
 PropertyKey(const char *n) : name(n) {} };
struct Effect { unsigned v[4]; };
struct Weapon {
    unsigned Shots() const { return shots; }
    unsigned Delay() const { return delay; }
    char unknown00[52]; int duration; char unknown56[136]; int recover; char unknown196[4];
    unsigned delay; unsigned shots; char unknown208[104]; int created; char unknown316[4]; int graphical;
};
struct Type { char unknown00[20]; Ptr32<Type> parent; };
struct Released { void w3d_r_v0() __asm__(W3D_SYM("_ZN8Released2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN8Released2v1Ev")); void w3d_r_Release() __asm__(W3D_SYM("_ZN8Released7ReleaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Released, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Released, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Released, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Released; };
struct Entity {
    void w3d_r_v0() __asm__(W3D_SYM("_ZN6Entity2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN6Entity2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN6Entity2v2Ev"));
    Ptr32<Type> w3d_r_Kind() __asm__(W3D_SYM("_ZN6Entity4KindEv"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Entity, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Entity, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Entity, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Type> Kind() { return ((Ptr32<Type> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Entity, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Entity; };
struct Gun : Entity {
    char unknown04[16] __attribute__((aligned(__alignof__(Entity)))); int id; char unknown24[4]; Ptr32<void> weapon; char unknown32[4]; Ptr32<void> worm; char unknown40[4];
    int state; unsigned rate; unsigned fired; char unknown56[28];
    unsigned start; int elapsed; char unknown92[4]; Ptr32<Released> held; int disable; char unknown104[12];
    int cooldown; char unknown120[4]; unsigned end; char unknown128[20]; Ptr32<void> wobble;
    template <char *T> bool IsA() {
        Ptr32<Type> t = Kind();
        for (Ptr32<Type> x = (Ptr32<Type>)T; t != x; t = t->parent)
            if (t == t->parent) return false;
        return true;
    }
};
extern "C" int w3d_timer_is_one_8006e71c();
extern "C" void w3d_wobble_8009ddc4(Ptr32<void>, int);
extern "C" Ptr32<void> w3d_cast_80341584(Ptr32<void>);
extern "C" Ptr32<void> w3d_cast_803426b4(Ptr32<void>);
extern "C" Ptr32<Weapon> w3d_weapon_801797b4(Ptr32<void>);
extern "C" int w3d_value_80178c48(Ptr32<void>);
extern "C" int w3d_read_800fc2f0(Ptr32<PropertyKey>, Ptr32<Effect>);
extern "C" int w3d_read_int_800fc230(Ptr32<PropertyKey>, Ptr32<int>);
extern "C" int w3d_write_int_800fc43c(Ptr32<PropertyKey>, int);
extern "C" void w3d_bind_effect_8009d6d4(Ptr32<Gun>, Ptr32<Weapon>, Ptr32<Effect>);
extern "C" Ptr32<void> w3d_created_init_800c1620(Ptr32<void>, Ptr32<int>);
extern "C" int w3d_log_80022e20(Ptr32<const char>, Ptr32<const char>, int, Ptr32<void>);
extern "C" unsigned w3d_rate_8009c850(Ptr32<Gun>);
extern "C" void w3d_fire_8009c87c(Ptr32<Gun>, unsigned, Ptr32<Weapon>, Ptr32<void>);
extern "C" int w3d_sound_8009c0cc(Ptr32<Gun>);
struct Context { char unknown00[52]; unsigned now; };
extern "C" Ptr32<Context> w3d_context_80165254();
extern "C" int w3d_alliance_publish_80155b44(Ptr32<void>);
extern "C" unsigned w3d_alliance_count_80158f68(Ptr32<void>);
extern "C" void w3d_finish_8015fd1c(Ptr32<Gun>);
extern "C" void w3d_clear_8009c758(Ptr32<Gun>);
extern "C" void w3d_franco_stop(void);
extern "C" void w3d_dbg(const char *, ...);
extern "C" int w3d_strcmp_802ef234(Ptr32<const char>, Ptr32<const char>);
struct Track { char unknown00[60]; Ptr32<const char> name; };
struct Camera { char unknown00[312]; int index; Ptr32<Ptr32<Track>> tracks; char unknown320[500]; float zoom;
    Ptr32<Track> & At(int i) { return tracks[i]; } };
extern "C" int w3d_camera_set_80035714(Ptr32<Camera>, Ptr32<const char>, float);
extern "C" int w3d_query_800fcea0();
extern unsigned lbl_804adfd0; extern int lbl_804adfd4;
extern int lbl_804aabe8;
extern Ptr32<void> lbl_804ab400;
extern Ptr32<Camera> lbl_804aa8c8;
extern MessageCache lbl_804ae000, lbl_804ae008, lbl_804ae010, lbl_804ae030, lbl_804ae058, lbl_804ae068, lbl_804ae078, lbl_804ae080, lbl_804ae098;
extern "C" char lbl_80361860[], lbl_803618f0[];
extern float lbl_8038017c[];
extern char lbl_80380078[], lbl_80380088[], lbl_803800e8[], lbl_80380108[], lbl_8038011c[], lbl_80380138[], lbl_80380148[], lbl_80380150[];
static inline void Done(Ptr32<Gun> self) {
    Ptr32<Weapon> w = w3d_weapon_801797b4(w3d_cast_80341584(self->weapon));
    w3d_sound_8009c0cc(self);
    Ptr32<Context> c = w3d_context_80165254();
    self->end = c->now + w->recover;
    self->state = 6;
}
extern "C" int w3d_d28b_gun_update_8009b9b4(Ptr32<Gun> self, unsigned now) {
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
            Ptr32<Weapon> w = w3d_weapon_801797b4(w3d_cast_80341584(self->weapon));
            if (w->graphical == 0) {
                Post(&lbl_804ae030);
                Effect effect;
                PropertyKey key(lbl_803800e8);
                w3d_read_800fc2f0(&key, &effect);
                w3d_bind_effect_8009d6d4(self, w, &effect);
            }
            if (w->created != 0) {
                Ptr32<void> m = w3d_arena_alloc_801613f0(lbl_804b1754, 12);
                int id = self->id;
                w3d_message_post_8016239c(w3d_created_init_800c1620(m, &id));
            }
            if (self->IsA<lbl_80361860>() || self->IsA<lbl_803618f0>())
                w3d_log_80022e20(lbl_80380108, lbl_8038011c, 304, &self->held);
            self->state = 2;
        }
        break;
    case 2: {
        Ptr32<Weapon> w = w3d_weapon_801797b4(w3d_cast_80341584(self->weapon));
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
        w3d_fire_8009c87c(self, shots, w, (Ptr32<void>)w3d::G(rate));
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
            w3d_read_int_800fc230(&key, (Ptr32<int>)&count);
            if (w3d_alliance_count_80158f68(lbl_804ab400) > 1 && count <= 1) {
                Done(self);
            } else {
                PropertyKey disable(lbl_80380088);
                w3d_read_int_800fc230(&disable, &self->disable);
                PropertyKey clear(lbl_80380088);
                w3d_write_int_800fc43c(&clear, 0);
                self->state = 0;
                Ptr32<Camera> cam = lbl_804aa8c8;
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
        Ptr32<Weapon> w = w3d_weapon_801797b4(w3d_cast_80341584(self->weapon));
        if (self->elapsed > w->duration) {
            if (w->graphical != 0 && self->fired < w->shots) {
                Ptr32<Message> m = (Ptr32<Message>)w3d_arena_alloc_801613f0(lbl_804b1754, 8);
                int id = w3d_cached_message_id_8015f5a0(&lbl_804ae008, 1);
                Ptr32<char> t = lbl_8040db38;
                m->id = id;
                m->vtable = t;
                w3d_message_post_8016239c(m);
            }
            self->state = 0;
            if (self->held) self->held->Release();
            self->held = 0;
            w3d_clear_8009c758(self);
            w3d_dbg("[francotirador] estado 7 (fin del disparo)\n"); w3d_franco_stop();   // Port (francotirador de UM): pasado PostLaunchDelay, como 0x55d650 de UM.
            self->fired = 0;
            PropertyKey key(lbl_80380078);
            w3d_write_int_800fc43c(&key, 0);
            lbl_804aa8c8->zoom = lbl_8038017c[0];
            Post(&lbl_804ae010);
            w3d_alliance_publish_80155b44(lbl_804ab400);
            PropertyKey ac(lbl_80380138);
            unsigned count;
            w3d_read_int_800fc230(&ac, (Ptr32<int>)&count);
            if (w3d_query_800fcea0() == 0 || (w3d_alliance_count_80158f68(lbl_804ab400) > 1 && count <= 1))
                Post(&lbl_804ae000);
        }
        break;
    }
    }
    return 50;
}



#include "w3d_ptr.h"
#line 1 "d31i_game_clock_message_8011c48c.cpp"
// d31i: 0x8011c48c. Game clock message handler: start, stop and reset
// messages for the round, turn and retreat timers.
struct Message { unsigned short id; };
struct Clock {
    unsigned char unknown00[104];
    int paused;      // +104
    int f108, f112, f116, f120, f124, f128, f132;
    Ptr32<void> o136; Ptr32<void> o140;
};
struct Posted { unsigned short id; Ptr32<void> vt; };
extern "C" int base_8015fb34(Ptr32<Clock>, Ptr32<Message>);
extern "C" void init_8011cb5c(Ptr32<Clock>);
extern "C" int eq_8015f620(Ptr32<int>, int);
extern "C" Ptr32<void> inner_80178c48(Ptr32<void>);
extern "C" void clear_8011d6a4(Ptr32<Clock>);
extern "C" int a_8011d6d8(Ptr32<Clock>);
extern "C" void a_8011d7d8(Ptr32<Clock>, int);
extern "C" int b_8011d6fc(Ptr32<Clock>);
extern "C" void b_8011d78c(Ptr32<Clock>, int);
extern "C" int c_8011d720(Ptr32<Clock>);
extern "C" void c_8011d804(Ptr32<Clock>, int);
extern "C" int d_8011d744(Ptr32<Clock>);
extern "C" void d_8011d850(Ptr32<Clock>, int);
extern "C" int e_8011d768(Ptr32<Clock>);
extern "C" void e_8011d89c(Ptr32<Clock>, int);
extern "C" void tick_8011d470(Ptr32<Clock>);
extern "C" Ptr32<void> arena_801613f0(Ptr32<void>, int);
extern "C" int message_id_8015f5a0(Ptr32<void>, int);
extern "C" int post_8016239c(Ptr32<void>);
extern Ptr32<void> arena_804b1754;
extern Ptr32<void> vt_8040db38[];
extern int flag_804abac0;
extern int id_804af3b8, id_804af3c0, id_804af3c8, id_804af3d0, id_804af3e0, id_804af3e8, id_804af3f8, id_804af400, id_804af408, id_804af410, id_804af418, id_804af420, id_804af428, id_804af430, id_804af438, id_804af440, id_804af448, id_804af450, id_804af458, id_804af460, id_804af468;
inline void Post(Ptr32<int> which) {
    Ptr32<Posted> p = (Ptr32<Posted>)arena_801613f0(arena_804b1754, 8);
    p->id = message_id_8015f5a0(which, 1);
    p->vt = vt_8040db38;
    post_8016239c(p);
}
extern "C" int d31i_game_clock_message_8011c48c(Ptr32<Clock> self, Ptr32<Message> m) {
    int id = m->id;
    if (id == 64) {
        if (base_8015fb34(self, m) >= 0) {
            init_8011cb5c(self);
            return 0;
        }
        return 0x80004005;
    }
    {
        int a = eq_8015f620(&id_804af3b8, id);
        if (a) {
            inner_80178c48(self->o136);
            inner_80178c48(self->o140);
            clear_8011d6a4(self);
            a_8011d7d8(self, a_8011d6d8(self));
            if (a_8011d6d8(self) > 0) self->f112 = 1;
            goto tail;
        }
        if (eq_8015f620(&id_804af3c0, id)) {
            self->f108 = a;
            self->f112 = a;
            self->f116 = a;
            self->f124 = a;
            self->f120 = a;
            goto tail;
        }
    }
    {
        int a = eq_8015f620(&id_804af3c8, id);
        if (a) {
            if (self->paused == 0) self->paused = 1;
            goto tail;
        }
        if (eq_8015f620(&id_804af3d0, id)) {
            if (self->paused) self->paused = a;
            goto tail;
        }
    }
    {
        int a = eq_8015f620(&id_804af3e0, id);
        if (a) {
            b_8011d78c(self, b_8011d6fc(self));
            if (b_8011d6fc(self) > 0) self->f108 = 1;
            goto tail;
        }
        if (eq_8015f620(&id_804af3e8, id)) {
            self->f108 = a;
            goto tail;
        }
    }
    {
        int a = eq_8015f620(&id_804af3f8, id);
        if (a) {
            int n = c_8011d720(self);
            if (n > 0) {
                self->f116 = 1;
                c_8011d804(self, n);
            } else Post(&id_804af408);
            goto tail;
        }
        if (eq_8015f620(&id_804af400, id)) {
            self->f116 = a;
            goto tail;
        }
    }
    if (eq_8015f620(&id_804af438, id) && self->f116 && flag_804abac0 == 0) {
        self->f116 = 0;
        Post(&id_804af408);
        goto tail;
    }
    if (eq_8015f620(&id_804af410, id)) {
        d_8011d850(self, d_8011d744(self));
        if (d_8011d744(self) > 0) self->f120 = 1;
        else Post(&id_804af418);
        goto tail;
    }
    {
        int a = eq_8015f620(&id_804af420, id);
        if (a) {
            e_8011d89c(self, e_8011d768(self));
            if (e_8011d768(self) > 0) self->f124 = 1;
            else Post(&id_804af430);
            goto tail;
        }
        if (eq_8015f620(&id_804af428, id)) {
            self->f124 = a;
            goto tail;
        }
    }
    if (eq_8015f620(&id_804af440, id)) {
        tick_8011d470(self);
        goto tail;
    }
    {
        int a = eq_8015f620(&id_804af448, id);
        if (a) {
            self->f128 = 1;
            goto tail;
        }
        if (eq_8015f620(&id_804af450, id)) {
            self->f128 = a;
            goto tail;
        }
    }
    {
        int a = eq_8015f620(&id_804af458, id);
        if (a) {
            self->f132 = 1;
            goto tail;
        }
        int b = eq_8015f620(&id_804af460, id);
        if (b) {
            self->f132 = a;
            goto tail;
        }
        if (eq_8015f620(&id_804af468, id)) self->f124 = b;
    }
tail:
    return base_8015fb34(self, m);
}



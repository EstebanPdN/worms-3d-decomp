#include "w3d_ptr.h"
#line 1 "d24c_emitter_lifetime_800e1e68.cpp"
// d24c: 0x800e1e68 (216 bytes). Advance a particle emitter's lifetime: add the time
// since the last call to +44 and remember the time in +36. When the elapsed time
// reaches the settings' limit (+394): remove the entity if it has no timer object
// (+288); otherwise start the timer once (virtual +20, flag +284); afterwards remove
// the entity when the timer reports finished is false (virtual +36) or +176 is set.
// Returns 0. Names are inferred.
struct Timed {
    struct V { Ptr32<void> u[5]; Ptr32<void (Ptr32<Timed>)> start; Ptr32<void> u24[3]; Ptr32<int (Ptr32<Timed>)> done; }; Ptr32<struct V> vtable;
};
struct Settings { unsigned char u[394]; unsigned short limit; };
struct Emitter {
    unsigned char u0[36];
    int last;        // +36
    unsigned char u40[4];
    int elapsed;     // +44
    unsigned char u48[108];
    Ptr32<void> resource;  // +156
    unsigned char u160[16];
    int keep;        // +176
    unsigned char u180[104];
    int started;     // +284
    Ptr32<Timed> timer;    // +288
};
extern "C" Ptr32<void> identity_80341584(Ptr32<void>);
extern "C" Ptr32<Settings> settings_801797b4(Ptr32<void>);
extern "C" void remove_8015fd1c(Ptr32<Emitter>);
extern "C" int d24c_emitter_lifetime_800e1e68(Ptr32<Emitter> self, int now) {
    int last = self->last;
    int d;
    if (last == 0) d = 0;
    else d = now - last;
    self->elapsed += d;
    self->last = now;
    Ptr32<Settings> s = settings_801797b4(identity_80341584(self->resource));
    if (self->elapsed >= s->limit) {
        if (self->timer == 0) {
            remove_8015fd1c(self);
        } else if (self->started == 0) {
            self->timer->vtable->start(self->timer);
            self->started = 1;
        } else if (self->timer->vtable->done(self->timer) == 0 || self->keep != 0) {
            remove_8015fd1c(self);
        }
    }
    return 0;
}



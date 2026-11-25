// d24c: 0x800e1e68 (216 bytes). Advance a particle emitter's lifetime: add the time
// since the last call to +44 and remember the time in +36. When the elapsed time
// reaches the settings' limit (+394): remove the entity if it has no timer object
// (+288); otherwise start the timer once (virtual +20, flag +284); afterwards remove
// the entity when the timer reports finished is false (virtual +36) or +176 is set.
// Returns 0. Names are inferred.
struct Timed {
    struct V { void *u[5]; void (*start)(Timed *); void *u24[3]; int (*done)(Timed *); } *vtable;
};
struct Settings { unsigned char u[394]; unsigned short limit; };
struct Emitter {
    unsigned char u0[36];
    int last;        // +36
    unsigned char u40[4];
    int elapsed;     // +44
    unsigned char u48[108];
    void *resource;  // +156
    unsigned char u160[16];
    int keep;        // +176
    unsigned char u180[104];
    int started;     // +284
    Timed *timer;    // +288
};
extern "C" void *identity_80341584(void *);
extern "C" Settings *settings_801797b4(void *);
extern "C" void remove_8015fd1c(Emitter *);
extern "C" int d24c_emitter_lifetime_800e1e68(Emitter *self, int now) {
    int last = self->last;
    int d;
    if (last == 0) d = 0;
    else d = now - last;
    self->elapsed += d;
    self->last = now;
    Settings *s = settings_801797b4(identity_80341584(self->resource));
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

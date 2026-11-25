/* desc: Appears to advance an elapsed-time counter by the change since the last stamp, then ask the attached handler to start or poll, falling back to a reset call; always returns zero. */
struct K1cHandler;
struct K1cHandlerMethods { void (*reserved0[5])(void); void (*start)(struct K1cHandler *); void (*reserved1[3])(void); int (*poll)(struct K1cHandler *); };
struct K1cHandler { struct K1cHandlerMethods *methods; };
struct K1cTimed {
    char pad0[36];
    int last_stamp;
    char pad1[4];
    int elapsed;
    char pad2[108];
    int sync_object;
    char pad3[16];
    int busy;
    char pad4[104];
    int started;
    struct K1cHandler *handler;
};
struct K1cConfig { char pad[394]; unsigned short limit; };
extern void fn_80341584(int);
extern struct K1cConfig *fn_801797b4(void);
extern void fn_8015fd1c(struct K1cTimed *);
int w3d_k1c_advance_clock_800e1e68(struct K1cTimed *self, int stamp)
{
    int last = self->last_stamp;
    int delta = stamp - last;
    if (last == 0)
        delta = 0;
    self->last_stamp = stamp;
    self->elapsed = self->elapsed + delta;
    fn_80341584(self->sync_object);
    if (self->elapsed >= fn_801797b4()->limit) {
        struct K1cHandler *handler = self->handler;
        if (handler == 0) {
            fn_8015fd1c(self);
        } else if (self->started == 0) {
            handler->methods->start(handler);
            self->started = 1;
        } else if (handler->methods->poll(handler) == 0 || self->busy != 0) {
            fn_8015fd1c(self);
        }
    }
    return 0;
}

// Weapon logic tick (Worms 3D GameCube PAL, 0x800c2b68, 732 bytes).
//
// State machine driven by the time argument; field names are inferred. The
// zero result of the pause check is reused for the elapsed and state resets.

struct Arena;
extern Arena *lbl_804b1754;
extern "C" void *fn_801613f0(Arena *, unsigned);
struct Cache { unsigned short id; unsigned char u[6]; };
extern "C" int fn_8015f5a0(Cache *, int);
extern "C" int fn_8016239c(void *);
extern char lbl_8040db38[];
struct Message { unsigned short id; const void *vt; };
inline void Post(Cache *cache) {
    Message *m = (Message *)fn_801613f0(lbl_804b1754, 8);
    m->id = fn_8015f5a0(cache, 1);
    m->vt = lbl_8040db38;
    fn_8016239c(m);
}
extern Cache lbl_804ae6e4, lbl_804ae72c, lbl_804ae6f4, lbl_804ae6ec, lbl_804ae6dc;
struct Effect;
struct EffectVt { void *u[9]; int (*busy)(Effect *); };
struct Effect { EffectVt *vt; };
struct Data { unsigned char u0[52]; int delay; unsigned char u56[192]; int hold; };
struct Worm { unsigned char u0[48]; float height; };
struct Logic {
    unsigned char u0[32];
    int state;       // +32
    unsigned char u36[4];
    Effect *effect;  // +40
    Data *data;      // +44
    unsigned char u48[24];
    unsigned start;  // +72
    int elapsed;     // +76
};
extern "C" int fn_8006e71c();
extern "C" Worm *fn_800c3224(Logic *);
extern "C" void fn_800c335c(Logic *, Worm *);
extern "C" void fn_800c31f0(Logic *);
extern "C" void fn_8015fd1c(Logic *);
extern "C" int fn_800fcea0();
extern unsigned lbl_804ae6ac;
extern int lbl_804ae6b0;
extern float lbl_803831d8[];
extern "C" int w3d_d25h_logic_tick_800c2b68(Logic *self, unsigned now) {
    int paused = fn_8006e71c();
    if (paused == 0) {
        if (lbl_804ae6b0 == 0) {
            lbl_804ae6ac = now;
            lbl_804ae6b0 = 1;
        }
        int delta = now - lbl_804ae6ac;
        lbl_804ae6ac = now;
        switch (self->state) {
        case 1:
            if (now >= self->start) {
                Post(&lbl_804ae6e4);
                Post(&lbl_804ae72c);
                fn_800c335c(self, fn_800c3224(self));
                if (self->data->hold) self->state = 2;
                else self->state = 4;
            }
            break;
        case 2:
            Post(&lbl_804ae6f4);
            self->state = 3;
            break;
        case 3: {
            Worm *worm = fn_800c3224(self);
            if (worm->height > lbl_803831d8[0]) fn_800c335c(self, worm);
            break;
        }
        case 4:
            self->elapsed = paused;
            if (self->effect && self->effect->vt->busy(self->effect)) self->state = 6;
            else self->state = 7;
            break;
        case 5:
            if (self->effect->vt->busy(self->effect) == 0) fn_8015fd1c(self);
            break;
        case 6:
            self->elapsed += delta;
            if (self->effect->vt->busy(self->effect) == 0) self->state = 7;
            break;
        case 7:
            self->elapsed += delta;
            if (self->elapsed > self->data->delay) {
                fn_800c31f0(self);
                self->state = paused;
                Post(&lbl_804ae6ec);
                if (fn_800fcea0() == 0) Post(&lbl_804ae6dc);
            }
            break;
        }
    }
    return 50;
}

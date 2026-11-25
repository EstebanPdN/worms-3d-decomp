// GWMP8P rev0 0x800a2e78. Plays the clock tick sound: replaces the held
// sound interface, creates TimerTick at the camera position lifted slightly,
// raises its frequency as the remaining seconds fall, and starts it. The
// TimerTick string and the lift constant are extern views: the pool starts 4
// bytes past an 8-byte boundary and also holds an unreferenced nFreq Tick
// string.
struct Vec { float x, y, z; };
struct Interface;
struct InterfaceRef;
struct InterfaceVt {
    void *u0[4];
    void (*release)(Interface *);                  // +16
    void (*play)(Interface *);                     // +20
    void *u24[6];
    void (*setInt)(Interface *, int, int);         // +48
    void *u52;
    union {
        void (*setVec)(Interface *, int, const Vec *);  // +56 on a sound
        void (*position)(Interface *, Vec *);           // +56 on the camera
    };
    void (*getInt)(Interface *, int, int *);       // +60
    void *u64[7];
    void (*create)(Interface *, const char *, InterfaceRef *);  // +92 on the audio service
};
struct Interface { InterfaceVt *vt; };
struct InterfaceRef { Interface *p; InterfaceRef &operator=(Interface *n) { if (p) p->vt->release(p); p = n; return *this; } };
struct Services { char u0[108]; struct { Interface *p; } audio; Interface *camera; };
extern Services *g_services_804b1788;
struct Clock { char u0[80]; InterfaceRef tick; };
extern char lbl_80380c84[];
extern float lbl_80380ca0[];
extern "C" void d41h_clock_tick_sound_800a2e78(Clock *self, int seconds) {
    if (g_services_804b1788->audio.p) {
        self->tick = 0;
        g_services_804b1788->audio.p->vt->create(g_services_804b1788->audio.p, lbl_80380c84, &self->tick);
        Vec pos;
        g_services_804b1788->camera->vt->position(g_services_804b1788->camera, &pos);
        pos.y += lbl_80380ca0[0];
        self->tick.p->vt->setVec(self->tick.p, 3, &pos);
        int freq;
        self->tick.p->vt->getInt(self->tick.p, 12, &freq);
        freq += (int)(freq * 0.1f * (5 - seconds));
        self->tick.p->vt->setInt(self->tick.p, 2, freq);
        self->tick.p->vt->play(self->tick.p);
    }
}

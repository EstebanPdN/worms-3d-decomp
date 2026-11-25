#include "w3d_ptr.h"
#line 1 "d41h_clock_tick_sound_800a2e78.cpp"
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
    Ptr32<void> u0[4];
    Ptr32<void (Ptr32<Interface>)> release;                  // +16
    Ptr32<void (Ptr32<Interface>)> play;                     // +20
    Ptr32<void> u24[6];
    Ptr32<void (Ptr32<Interface>, int, int)> setInt;         // +48
    Ptr32<void> u52;
    union {
        Ptr32<void (Ptr32<Interface>, int, Ptr32<const Vec>)> setVec;  // +56 on a sound
        Ptr32<void (Ptr32<Interface>, Ptr32<Vec>)> position;           // +56 on the camera
    };
    Ptr32<void (Ptr32<Interface>, int, Ptr32<int>)> getInt;       // +60
    Ptr32<void> u64[7];
    Ptr32<void (Ptr32<Interface>, Ptr32<const char>, Ptr32<InterfaceRef>)> create;  // +92 on the audio service
};
struct Interface { Ptr32<InterfaceVt> vt; };
struct InterfaceRef { Ptr32<Interface> p; template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Interface *)w3d_p.get()); }
 InterfaceRef &operator=(Interface *n) { if (p) p->vt->release(p); p = n; return *this; } };
struct Services { char u0[108]; struct { Ptr32<Interface> p; } audio; Ptr32<Interface> camera; };
extern Ptr32<Services> g_services_804b1788;
struct Clock { char u0[80]; InterfaceRef tick; };
extern char lbl_80380c84[];
extern float lbl_80380ca0[];
extern "C" void d41h_clock_tick_sound_800a2e78(Ptr32<Clock> self, int seconds) {
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



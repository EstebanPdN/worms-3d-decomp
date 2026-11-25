#include "w3d_ptr.h"
#line 1 "d29g_crate_properties_load_8004b448.cpp"
/* Worms 3D GameCube PAL 0x8004b448. Crate start-up: clears the delay and vector state, reads the sixteen Crate.* properties with their defaults, scales hit points by the multiplier, sets the absolute delay and lifetime times from the engine clock, derives fall speed and the UXB, gravity, parachute and pushable flags, and releases the object at +244 unless WaitTillLanded is on. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Vec {
    float x, y, z;
    void set(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Key { Ptr32<const char> name; };
struct Owned { struct Vt { char u[16]; Ptr32<void (Ptr32<Owned>)> release; }; Ptr32<struct Vt> vt; };
struct Ctx { char u[52]; int now; };
struct Crate {
    char u0[32]; int index; char u36[52 - 36]; Vec spin; char u64[68 - 64];
    int contents; int hitpoints; int turns; char u80[84 - 80]; int expire; int delayed; int timed;
    int hasDelay; char u100[108 - 100]; int gravity; int parachute; int pushable; int uxb; int a124; int a128; char u132[136 - 132];
    int collectable; int destructible; char u144[168 - 144]; float hpMult; int a172; char u176[244 - 176]; Ptr32<Owned> a244; char u248[256 - 248]; Ptr32<Owned> a256;
};
extern "C" {
int w3d_auto_800fc1f0(Ptr32<Key>, Ptr32<int>);
int w3d_auto_800fc270(Ptr32<Key>, Ptr32<float>);
Ptr32<Ctx> w3d_engine_get_context();
}
extern "C" void w3d_d29g_crate_properties_load_8004b448(Ptr32<Crate> self)
{
    float speed = 0.0f;
    int gravity = 1, parachute = 1, pushable = 1, uxb = 0, delay = 0, wait = 0, track = 1;
    float life = -1.0f;
    self->a124 = 0;
    self->a128 = 0;
    self->a172 = 0;
    self->spin.set(0.0f, 0.0f, 0.0f);
    Key k0 = {"Crate.Index"}; w3d_auto_800fc1f0(&k0, &self->index);
    Key k1 = {"Crate.NumContents"}; w3d_auto_800fc1f0(&k1, &self->contents);
    Key k2 = {"Crate.Hitpoints"}; w3d_auto_800fc1f0(&k2, &self->hitpoints);
    Key k3 = {"Crate.LifetimeTurns"}; w3d_auto_800fc1f0(&k3, &self->turns);
    Key k4 = {"Crate.Parachute"}; w3d_auto_800fc1f0(&k4, &parachute);
    Key k5 = {"Crate.Gravity"}; w3d_auto_800fc1f0(&k5, &gravity);
    Key k6 = {"Crate.TeamDestructible"}; w3d_auto_800fc1f0(&k6, &self->destructible);
    Key k7 = {"Crate.TeamCollectable"}; w3d_auto_800fc1f0(&k7, &self->collectable);
    Key k8 = {"Crate.UXB"}; w3d_auto_800fc1f0(&k8, &uxb);
    Key k9 = {"Crate.Pushable"}; w3d_auto_800fc1f0(&k9, &pushable);
    Key k10 = {"Crate.DelayMillisec"}; w3d_auto_800fc1f0(&k10, &delay);
    Key k11 = {"Crate.WaitTillLanded"}; w3d_auto_800fc1f0(&k11, &wait);
    Key k12 = {"Crate.TrackCam"}; w3d_auto_800fc1f0(&k12, &track);
    Key k13 = {"Crate.LifetimeSec"}; w3d_auto_800fc270(&k13, &life);
    Key k14 = {"Crate.FallSpeed"}; w3d_auto_800fc270(&k14, &speed);
    Key k15 = {"Crate.HitpointsMultiplier"}; w3d_auto_800fc270(&k15, &self->hpMult);
    if (self->hpMult > 0.0f) self->hitpoints = (int)(self->hitpoints * self->hpMult);
    self->delayed = delay + w3d_engine_get_context()->now;
    if (self->delayed) self->hasDelay = 1; else self->hasDelay = 0;
    if (life > 0.0f) {
        int now = w3d_engine_get_context()->now;
        self->timed = 1;
        self->expire = now + (int)(life * 1000.0f) + delay;
    } else self->timed = 0;
    self->spin.set(0.0f, speed * -0.001f, 0.0f);
    if (uxb == 1) self->uxb = 1; else self->uxb = 0;
    if (gravity == 1) self->gravity = 1; else self->gravity = 0;
    if (parachute == 1) self->parachute = 1; else self->parachute = 0;
    if (pushable == 1) self->pushable = 1; else self->pushable = 0;
    if (wait != 1) {
        if (self->a244) self->a244->vt->release(self->a244);
        self->a244 = 0;
    }
    if (track != 1) self->a256 = 0;
}



#include "w3d_ptr.h"
#line 1 "d28g_hud_input_state_step_8006551c.cpp"
/* Worms 3D GameCube PAL 0x8006551c. Per-frame step of a four-stage state machine: restamps when the resource at +92 is active with a kind other than 10, sets the flag at +116 when the time argument passes the +96 value plus +120, resets to state 0 when either handle at +100 or +104 reports nonzero, then advances the state at +108 by its step callback. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Handle;
struct Info { char u[128]; int kind; };
struct Self {
    char u0[92];
    Ptr32<Handle> a92; Ptr32<Handle> a96; Ptr32<Handle> a100; Ptr32<Handle> a104;
    int state; int f112; int f116; unsigned f120;
};
extern "C" {
int w3d_auto_80178c48(Ptr32<Handle>);
unsigned w3d_auto_80178d1c(Ptr32<Handle>);
Ptr32<Info> s8_index_query_800fc6dc(int);
void w3d_timed_state_stamp_800664c4(Ptr32<Self>);
void w3d_auto_80065c94(Ptr32<Self>, int);
int w3d_fn_80066068(Ptr32<Self>);
int w3d_cx15a_step_four_800660d4(Ptr32<Self>);
int w3d_component_step_80065ff0(Ptr32<Self>);
int w3d_auto_80066010(Ptr32<Self>);
}
extern "C" int w3d_d28g_hud_input_state_step_8006551c(Ptr32<Self> self, unsigned t)
{
    int idx = w3d_auto_80178c48(self->a92);
    if (idx >= 0) {
        if (s8_index_query_800fc6dc(idx)->kind != 10) w3d_timed_state_stamp_800664c4(self);
    }
    unsigned lim = w3d_auto_80178d1c(self->a96) + self->f120;
    if (t > lim) self->f116 = 1; else self->f116 = 0;
    if (w3d_auto_80178d1c(self->a100) != 0 || w3d_auto_80178d1c(self->a104) != 0) {
        self->f116 = 0; self->f112 = 0; self->state = 0;
        w3d_auto_80065c94(self, 0);
    }
    switch (self->state) {
    case 0:
        if (self->f112 || self->f116) self->state = 1;
        break;
    case 1:
        if (w3d_fn_80066068(self)) self->state = 2;
        break;
    case 2:
        if (w3d_cx15a_step_four_800660d4(self)) self->state = 3;
        break;
    case 3:
        if (w3d_component_step_80065ff0(self)) {
            if (self->f112 || self->f116) self->state = 2;
            else self->state = 4;
        }
        break;
    case 4:
        if (w3d_auto_80066010(self)) {
            if (!self->f112) self->state = 0; else self->state = 1;
        }
        break;
    }
    return 0;
}



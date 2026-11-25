#include "w3d_ptr.h"
#line 1 "d29f_fade_state_machine_8028d004.cpp"
// GWMP8P rev0 0x8028d004. Steps a frontend panel's fade state machine: waits
// for fades and moves to finish, starts the enter and leave fades with a
// timer of 500 and runs the two end callbacks when the timer expires. Field
// names are inferred; the unit owns no data.
// Observed widget views; roles inferred.
struct Vec3 { float x, y, z; Vec3(float a, float b, float c) { x = a; y = b; z = c; } };
struct Widget { void w3d_r_s0() __asm__(W3D_SYM("_ZN6Widget2s0Ev"));  __attribute__((always_inline)) inline void s0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Widget, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Widget; };
struct Table { Ptr32<void> s[7]; };
struct Base { char pad[180]; Ptr32<Ptr32<void>> table; };
struct Config { char pad[116]; int enter; int leave; };
struct Ctx { char pad[52]; unsigned time; };
struct Panel {
    char pad[28];
    Base base;
};
struct Fader { Ptr32<Ptr32<void>> table; };
struct Self {
    char pad[28]; char b[12]; Ptr32<Config> cfg; char pad44[68]; Ptr32<Fader> fader; char pad116[8]; int moving; int fading; char pad132[76]; Ptr32<Ptr32<void>> table; char pad212[12]; int state; unsigned timer;
};
extern float lbl_803cff38[], lbl_803cff3c[];
extern "C" void fn_802b0668(Ptr32<void>);
extern "C" Ptr32<Ctx> w3d_engine_get_context(void);
extern "C" void fn_8028d3b8(Ptr32<Self>);
extern "C" void fn_8028d34c(Ptr32<Self>);
inline void Fade(Ptr32<Fader> f, const Vec3 &v) { ((Ptr32<int (Ptr32<Fader>, Ptr32<const Vec3>, int)>)f->table[19])(f, &v, 0); }
extern "C" int d29f_fade_state_machine_8028d004(Ptr32<Self> self) {
    Ptr32<void> b = self->b;
    fn_802b0668(b);
    Ptr32<Fader> fader = self->fader;
    Ptr32<Config> cfg = self->cfg;
    if (fader != 0) {
        switch (self->state) {
        case 2:
            break;
        case 0:
            if (self->fading == 0)
                self->state = 2;
            break;
        case 1:
            if (self->fading == 0) {
                Fade(fader, Vec3(lbl_803cff38[0], lbl_803cff38[0], lbl_803cff38[0]));
                ((Ptr32<void (Ptr32<void>, int)>)self->table[6])(b, cfg->enter);
                self->state = 3;
                self->timer = w3d_engine_get_context()->time + 500;
            }
            break;
        case 3:
            if (self->moving == 0) {
                Fade(fader, Vec3(lbl_803cff3c[0], lbl_803cff3c[0], lbl_803cff38[0]));
                self->state = 4;
            }
            break;
        case 4:
            if (self->timer < w3d_engine_get_context()->time) {
                fn_8028d3b8(self);
                fn_8028d34c(self);
                ((Ptr32<void (Ptr32<void>, int)>)self->table[6])(b, cfg->leave);
                Fade(self->fader, Vec3(lbl_803cff38[0], lbl_803cff38[0], lbl_803cff38[0]));
                self->state = 5;
            }
            break;
        case 5:
            if (self->moving == 0)
                self->state = 2;
            break;
        }
    }
    return 0;
}



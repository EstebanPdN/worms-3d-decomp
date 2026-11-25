// GWMP8P rev0 0x8028d004. Steps a frontend panel's fade state machine: waits
// for fades and moves to finish, starts the enter and leave fades with a
// timer of 500 and runs the two end callbacks when the timer expires. Field
// names are inferred; the unit owns no data.
// Observed widget views; roles inferred.
struct Vec3 { float x, y, z; Vec3(float a, float b, float c) { x = a; y = b; z = c; } };
struct Widget { virtual void s0(); };
struct Table { void *s[7]; };
struct Base { char pad[180]; void **table; };
struct Config { char pad[116]; int enter; int leave; };
struct Ctx { char pad[52]; unsigned time; };
struct Panel {
    char pad[28];
    Base base;
};
struct Fader { void **table; };
struct Self {
    char pad[28]; char b[12]; Config *cfg; char pad44[68]; Fader *fader; char pad116[8]; int moving; int fading; char pad132[76]; void **table; char pad212[12]; int state; unsigned timer;
};
extern float lbl_803cff38[], lbl_803cff3c[];
extern "C" void fn_802b0668(void *);
extern "C" Ctx *w3d_engine_get_context(void);
extern "C" void fn_8028d3b8(Self *);
extern "C" void fn_8028d34c(Self *);
inline void Fade(Fader *f, const Vec3 &v) { ((int (*)(Fader *, const Vec3 *, int))f->table[19])(f, &v, 0); }
extern "C" int d29f_fade_state_machine_8028d004(Self *self) {
    void *b = self->b;
    fn_802b0668(b);
    Fader *fader = self->fader;
    Config *cfg = self->cfg;
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
                ((void (*)(void *, int))self->table[6])(b, cfg->enter);
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
                ((void (*)(void *, int))self->table[6])(b, cfg->leave);
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

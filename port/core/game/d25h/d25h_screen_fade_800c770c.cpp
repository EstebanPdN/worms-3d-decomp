#include "w3d_ptr.h"
#line 1 "d25h_screen_fade_800c770c.cpp"
// Screen fade out (Worms 3D GameCube PAL, 0x800c770c, 568 bytes).
//
// Field names are inferred from the colour calls and the 30-step loop. Float to
// byte conversions go through the paired-single quantized store (-mfast-cast).

struct Flags { unsigned int rest:28; unsigned int d:1; unsigned int c:1; unsigned int b:1; unsigned int a:1; };
struct Color {
    unsigned char r, g, b, a;
    Color(unsigned char x, unsigned char y, unsigned char z, unsigned char w) { r = x; g = y; b = z; a = w; }
};
struct Obj;
struct ObjVt { Ptr32<void> u[4]; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct Ref { Ptr32<Obj> p; void Clear() { if (p) p->vt->release(p); p = 0; } };
struct Fx;
struct FxVt { Ptr32<void> u[12]; Ptr32<void (Ptr32<Fx>)> begin; };
struct Fx { Ptr32<FxVt> vt; };
struct Services;
struct ServicesVt { Ptr32<void> u[16]; Ptr32<void (Ptr32<Services>, int)> wait; };
struct Services { Ptr32<ServicesVt> vt; unsigned char u4[72]; Flags flags; unsigned char u80[28]; Ptr32<Fx> fx; };
extern Ptr32<Services> lbl_804b1788;
extern "C" int fn_80173df0(Ptr32<Obj>, Ptr32<Color>);
extern "C" int fn_8018d35c(Ptr32<Obj>, Ptr32<Color>);
extern "C" int fn_8018d434(Ptr32<Obj>, Ptr32<Color>);
extern "C" void fn_800c7c84(Ptr32<struct Screen>);
struct Screen {
    unsigned char u0[192];
    Ref slots[8];   // +192
    unsigned count; // +224
    unsigned char u228[16];
    Ref back;       // +244
    Flags flags;    // +248
};
extern "C" void w3d_d25h_screen_fade_800c770c(Ptr32<Screen> self) {
    Ptr32<Services> s = lbl_804b1788;
    s->fx->vt->begin(s->fx);
    self->flags.c = 1;
    s->flags.c = self->flags.a;
    if (self->flags.b) {
        s->flags.c = 1;
        s->flags.b = 0;
    }
    Color white(255, 255, 255, 0);
    Color black(0, 0, 0, 0);
    Color solid(0, 0, 0, 255);
    float t = 255.0f;
    float full = t;
    for (int i = 0; i < 30; i++) {
        t -= 8.5f;
        black.a = (unsigned char)(t / full * 180.0f);
        solid.a = white.a = (unsigned char)t;
        fn_80173df0(self->back.p, &black);
        for (unsigned j = 0; j < self->count; j++) {
            fn_8018d35c(self->slots[j].p, &white);
            fn_8018d434(self->slots[j].p, &solid);
        }
        s->vt->wait(s, 0);
    }
    for (int k = 0; k < 8; k++) self->slots[k].Clear();
    self->back.Clear();
    self->count = 0;
    fn_800c7c84(self);
    if (self->flags.b) {
        s->flags.b = 1;
        s->flags.c = 0;
    }
    s->flags.d = 1;
    self->flags.c = 0;
    self->flags.d = 0;
}



#include "w3d_ptr.h"
#line 1 "d24h_jetpack_part_800ae7d4.cpp"
// Jetpack part effect state (Worms 3D GameCube PAL, 0x800ae7d4, 472 bytes).
//
// Part and state dispatch over three parallel effect and state slots; field
// names are inferred from the effect names in the original data. The third
// state reads the slots through a local base pointer with byte offsets, which
// gives the original's base-first indexed loads.

struct Arena;
extern Ptr32<Arena> lbl_804b1754;
extern "C" Ptr32<void> fn_801613f0(Ptr32<Arena>, unsigned);
struct Cache { unsigned short id; unsigned char u[6]; };
extern Cache lbl_804ae3e4;
extern "C" int fn_8015f5a0(Ptr32<Cache>, int);
extern "C" Ptr32<void> fn_80125fdc(Ptr32<void>, unsigned short, int);
extern "C" int fn_8016239c(Ptr32<void>);
extern "C" Ptr32<void> fn_80343584(Ptr32<void>);
extern "C" int fn_800e5cf0(Ptr32<void>, Ptr32<void>, Ptr32<const char>, int, int);
extern Ptr32<void> lbl_804aac8c; extern Ptr32<void> lbl_804aac90; extern Ptr32<void> lbl_804aac94;
extern const char lbl_803821c0[], lbl_80382190[], lbl_803821d8[];
struct Jetpack {
    unsigned char u0[32];
    Ptr32<void> owner;
    unsigned char u36[16];
    int effects[3];   // +52
    int states[3];    // +64
};
extern "C" void w3d_d24h_jetpack_part_800ae7d4(Ptr32<Jetpack> self, int part, int state) {
    Ptr32<void> owner = fn_80343584(self->owner);
    Ptr32<void> model;
    switch (part) {
    case 0: model = lbl_804aac90; break;
    case 1: model = lbl_804aac94; break;
    case 2: model = lbl_804aac8c; break;
    default: return;
    }
    switch (state) {
    case 0:
        if (self->effects[part]) {
            Ptr32<void> m = fn_801613f0(lbl_804b1754, 12);
            fn_8016239c(fn_80125fdc(m, fn_8015f5a0(&lbl_804ae3e4, 1), self->effects[part]));
        }
        self->effects[part] = state;
        self->states[part] = state;
        break;
    case 1:
        if (self->states[part] != 1) {
            if (self->effects[part]) w3d_d24h_jetpack_part_800ae7d4(self, part, 0);
            self->effects[part] = fn_800e5cf0(owner, model, lbl_803821c0, -1, 0);
            self->states[part] = state;
        }
        break;
    case 2:
        if (self->states[part] != 2) {
            Ptr32<int> effects = self->effects;
            if (*(Ptr32<int>)((Ptr32<char>)effects + (part << 2))) w3d_d24h_jetpack_part_800ae7d4(self, part, 0);
            if (part == 2) effects[2] = fn_800e5cf0(owner, model, lbl_80382190, -1, 0);
            else *(Ptr32<int>)((Ptr32<char>)effects + (part << 2)) = fn_800e5cf0(owner, model, lbl_803821d8, -1, 0);
            self->states[part] = 2;
        }
        break;
    }
}



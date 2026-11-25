#include "w3d_ptr.h"
#line 1 "d25g_worm_mesh_set_mode_80069630.cpp"
/* Worms 3D GameCube PAL 0x80069630. Switches the two meshes to a new mode: stops the clip of the current mode on each mesh that has one, plays the new mode's clip by id and name on each mesh that has one, stores the mode, and in mode 3 starts the effect when both effect flags are set. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Self {
    char u0[96];
    Ptr32<void> meshA;
    Ptr32<void> meshB;
    char u104[8];
    int state;
    char u116[4];
    int useA[10];
    int clipA[10];
    char nameA[10][4];
    int useB[10];
    int clipB[10];
    char nameB[10][4];
    int flag360;
    int a364;
    int a368;
    char u372[24];
    int flag396;
};
extern "C" int stop_clip_801817e0(Ptr32<void>, int);
extern "C" int play_80181640(Ptr32<void>, int, Ptr32<void>, float, float, float, int);
extern "C" int start_effect_800e5cf0(Ptr32<void>, int, int, int, int);
/* The two leading switches compute values that the next statements overwrite. Life analysis removes the stores late, so the original keeps their compares. The stored values leave no trace and are placeholders; the compare trees fix the case set 0..8. */
extern "C" void w3d_d25g_worm_mesh_set_mode_80069630(Ptr32<Self> self, int mode)
{
    int p; switch (self->state) { case 0: break; case 1: p = 101; break; case 2: break; case 3: break; case 4: p = 104; break; case 5: break; case 6: p = 106; break; case 7: break; case 8: break; }
    int q = mode == 3; switch (mode) { case 0: break; case 1: q = 101; break; case 2: q = 102; break; case 3: break; case 4: q = 104; break; case 5: break; case 6: q = 106; break; case 7: break; case 8: break; }
    p = self->useA[self->state]; if (p) stop_clip_801817e0(self->meshA, -1);
    q = self->useB[self->state]; if (q) stop_clip_801817e0(self->meshB, -1);
    if (self->useA[mode]) play_80181640(self->meshA, (&self->clipA[0])[mode], self->nameA[mode], 1.0f, 0.0f, 0.0f, 0);
    if (self->useB[mode]) play_80181640(self->meshB, (&self->clipB[0])[mode], self->nameB[mode], 1.0f, 0.0f, 0.0f, 0);
    self->state = mode;
    if (mode == 3 && self->flag360 && self->flag396) start_effect_800e5cf0(self->meshA, self->a368, self->a364, -1, 0);
}



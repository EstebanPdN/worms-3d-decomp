#include "w3d_ptr.h"
#line 1 "d24d_turns_reset_80156884.cpp"
// d24d: 0x80156884 (576 bytes). Reset the turn tables: clear the four lists at
// +100 and the four team lists at +52, rebuild the worm state (0x80157afc), then
// for each of 16 worms with a nonzero state (+220) create its actor when it has
// none (+260, 0x80156ac4), add live ones (+188 == 1) to their team's list and
// apply the worm's named scene value (+108, 0x80158810). Finally sets the two
// displays (+296, +304) to -1, passed as const references to temporaries, and
// runs 0x80156214 in mode 1 (+384). Names are inferred.
#include "d24d_int_list_range.h"
struct d24d_WormInfo {
    unsigned char unknown00[108];
    char scene[80];                      // +108
    int live;                            // +188
    unsigned char unknownc0[21];
    unsigned char team;                  // +213
    unsigned char unknownd6[6];
    int state;                           // +220
    unsigned char unknowne0[36];
    int actor;                           // +260
};
struct d24d_Turns;
extern "C" Ptr32<d24d_WormInfo> d24d_worm_info_800fc6dc(unsigned);
extern "C" Ptr32<void> d24d_display_803426b4(Ptr32<void>);
extern "C" int d24d_display_update_80178c54(Ptr32<void>, const int &);
extern "C" void d24d_turns_rebuild_80157afc(Ptr32<d24d_Turns>);
extern "C" void d24d_turns_create_actor_80156ac4(Ptr32<d24d_Turns>, unsigned);
extern "C" void d24d_turns_apply_scene_80158810(Ptr32<d24d_Turns>, Ptr32<char>);
extern "C" void d24d_turns_begin_80156214(Ptr32<d24d_Turns>);
struct d24d_Turns {
    unsigned char unknown00[52];
    d24d_RangeList team_lists[4];        // +52
    d24d_RangeList other_lists[4];       // +100
    unsigned char unknown94[148];
    Ptr32<void> display_a;                     // +296
    unsigned char unknown12c[4];
    Ptr32<void> display_b;                     // +304
    unsigned char unknown134[76];
    int mode;                            // +384
};

extern "C" void d24d_turns_reset_80156884(Ptr32<d24d_Turns> self) {
    unsigned i;
    for (i = 0; i <= 3; i++) self->other_lists[i].clear();
    for (i = 0; i <= 3; i++) self->team_lists[i].clear();
    d24d_turns_rebuild_80157afc(self);
    for (i = 0; i <= 15; i++) {
        Ptr32<d24d_WormInfo> worm = d24d_worm_info_800fc6dc(i);
        if (worm->state) {
            if (!worm->actor) d24d_turns_create_actor_80156ac4(self, i);
            if (worm->live == 1) self->team_lists[worm->team].push_back(i);
            d24d_turns_apply_scene_80158810(self, worm->scene);
        }
    }
    d24d_display_update_80178c54(d24d_display_803426b4(self->display_a), -1);
    d24d_display_update_80178c54(d24d_display_803426b4(self->display_b), -1);
    if (self->mode == 1) d24d_turns_begin_80156214(self);
}



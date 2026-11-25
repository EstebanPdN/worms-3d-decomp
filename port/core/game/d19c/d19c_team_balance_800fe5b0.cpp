#include "w3d_ptr.h"
#line 1 "d19c_team_balance_800fe5b0.cpp"
// d19c: 0x800fe5b0 (372 bytes). Balance team time (sol35b10's team_balance
// draft, rewritten): sum the spare amount (+170 available minus +164 used) of
// every active worm record (16 records, 0x800fc6dc), average it over the
// player count (0x80158f68), and give every active team (4 records,
// 0x800fc7f8) that average divided by its member count (0x80158e74) through
// 0x80158ea4. Then reset the "RetreatTime" setting to 0 and continue with
// 0x8002ae70. Meanings are inferred.
// Built with -mps-float: one FPR is saved (the average) and the unflagged build
// differed only by the 8-byte frame gap below the register save area. Reading
// the used amount into a named local first gives the original load order
// (available before used). The key is external: a standalone object aligns
// its .rodata to 8 for the conversion bias double, so the 4-aligned string at
// 0x8039820c cannot be owned by this unit.
struct d19c_WormRecord {
    unsigned char unknown00[164];
    unsigned used;                       // +164
    unsigned char unknown168[2];
    unsigned short available;            // +170
    unsigned char unknown172[48];
    int active;                          // +220
};
struct d19c_TeamRecord {
    unsigned char unknown00[72];
    int active;                          // +72
};
struct d19c_SettingKey { Ptr32<const char> text; };
extern "C" Ptr32<d19c_WormRecord> d19c_worm_record_800fc6dc(unsigned);
extern "C" Ptr32<d19c_TeamRecord> d19c_team_record_800fc7f8(unsigned);
extern "C" unsigned d19c_player_count_80158f68(Ptr32<void>);
extern "C" unsigned d19c_team_member_count_80158e74(Ptr32<void>, unsigned);
extern "C" void d19c_team_set_share_80158ea4(Ptr32<void>, unsigned, unsigned);
extern "C" int d19c_property_write_800fc3b0(Ptr32<const d19c_SettingKey>, int);
extern "C" void d19c_continue_8002ae70(Ptr32<void>);
extern Ptr32<void> d19c_teams_804ab400;
extern const char d19c_retreat_time_key_8039820c[];   // "RetreatTime"

extern "C" void d19c_team_balance_800fe5b0(Ptr32<void> self) {
    unsigned sum = 0;
    for (unsigned i = 0; i < 16; ++i) {
        Ptr32<d19c_WormRecord> worm = d19c_worm_record_800fc6dc(i);
        if (worm->active) {
            unsigned used = worm->used;
            sum += worm->available - used;
        }
    }
    float average = float(sum) / float(d19c_player_count_80158f68(d19c_teams_804ab400));
    for (unsigned i = 0; i < 4; ++i) {
        if (d19c_team_record_800fc7f8(i)->active) {
            unsigned count = d19c_team_member_count_80158e74(d19c_teams_804ab400, i);
            d19c_team_set_share_80158ea4(d19c_teams_804ab400, i, unsigned(average / float(count)));
        }
    }
    d19c_SettingKey retreat = { d19c_retreat_time_key_8039820c };
    d19c_property_write_800fc3b0(&retreat, 0);
    d19c_continue_8002ae70(self);
}



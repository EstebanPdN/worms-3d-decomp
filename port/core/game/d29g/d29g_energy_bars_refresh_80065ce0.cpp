#include "w3d_ptr.h"
#line 1 "d29g_energy_bars_refresh_80065ce0.cpp"
/* Worms 3D GameCube PAL 0x80065ce0. Energy bar refresh: sums the health of living worms per team over the 16 worm slots and notes the current worm's team, finds the best total and the number of teams alive, derives the bar scale limited by the handle at +88 and stores the best total at +124, bubble-sorts team indices by total with an xor swap, then updates each of the four bars: current flag, scale, total, resource and flag strings, level, interpolation, team, and display slot from its rank. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
extern "C" void w3d_string_base_finish(Ptr32<void>), w3d_string_release(Ptr32<void>);
struct String {
    Ptr32<char> p;
    String(const String &);
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Handle;
struct Bar;
struct Worm { char u0[170]; unsigned short health; char u172[213 - 172]; unsigned char team; char u214[220 - 214]; int alive; };
struct Bars {
    char u0[28]; int bars[4]; Ptr32<Handle> a44; char u48[88 - 48]; Ptr32<Handle> a88; char u92[124 - 92]; float maxHealth;
};
extern "C" {
Ptr32<Handle> w3d_empty_803426b4(Ptr32<Handle>);
int w3d_auto_80178c48(Ptr32<Handle>);
Ptr32<Worm> s8_index_query_800fc6dc(int);
float w3d_auto_80178df0(Ptr32<Handle>);
Ptr32<Bar> w3d_s20_lookup_handle_object_80164fc8(int);
void w3d_auto_80064d88(Ptr32<Bar>, int);
void w3d_timed_state_set_rate_80064548(Ptr32<Bar>, float);
void w3d_auto_8006456c(Ptr32<Bar>, int);
void w3d_timed_state_resource_mode_80064274(Ptr32<Bar>, Ptr32<char>);
void w3d_k10a_team_flags_apply_80064dcc(Ptr32<Bar>, Ptr32<char>);
int w3d_cx15a_approach_level_80064950(Ptr32<Bar>);
int f7b_interpolate_800647cc(Ptr32<Bar>);
void w3d_d24g_energy_bar_set_team_80064384(Ptr32<Bar>, int);
void w3d_timed_state_set_mode_80064190(Ptr32<Bar>, int);
void w3d_fn_800664f8(Ptr32<Bars>);
}
extern "C" String w3d_auto_80065b5c(Ptr32<Bars>, int);
extern "C" String w3d_auto_80065bf8(Ptr32<Bars>, int);
extern "C" void w3d_d29g_energy_bars_refresh_80065ce0(Ptr32<Bars> self)
{
    int totals[4];
    int order[4];
    unsigned i;
    for (i = 0; i < 4; i++) totals[i] = 0;
    int currentTeam = 0;
    int current = w3d_auto_80178c48(w3d_empty_803426b4(self->a44));
    for (i = 0; i <= 15; i++) {
        Ptr32<Worm> w = s8_index_query_800fc6dc(i);
        if (w->alive) {
            int team = w->team;
            totals[team] += w->health;
            if ((int)i == current) currentTeam = team;
        }
    }
    int best = 0, used = 0;
    for (i = 0; i < 4; i++) {
        if (totals[i] > best) best = totals[i];
        if (totals[i] > 0) used++;
    }
    float scale;
    if ((float)best > w3d_auto_80178df0(self->a88)) scale = w3d_auto_80178df0(self->a88) / (float)best;
    else scale = 1.0f;
    self->maxHealth = (float)best;
    int first = 4 - used;
    for (i = 0; i < 4; i++) order[i] = i;
    bool sorted;
    do {
        sorted = true;
        for (i = 0; i <= 2; i++) {
            if (totals[order[i]] < totals[order[i + 1]]) {
                sorted = false;
order[i] = order[i] ^ order[i + 1]; order[i + 1] = order[i] ^ order[i + 1]; order[i] = order[i] ^ order[i + 1];
            }
        }
    } while (!sorted);
    for (i = 0; i <= 3; i++) {
        Ptr32<Bar> b = w3d_s20_lookup_handle_object_80164fc8(self->bars[i]);
        if ((int)i == currentTeam) w3d_auto_80064d88(b, 1);
        else w3d_auto_80064d88(b, 0);
        w3d_timed_state_set_rate_80064548(b, scale);
        w3d_auto_8006456c(b, totals[i]);
        w3d_timed_state_resource_mode_80064274(b, w3d_auto_80065b5c(self, i).p);
        w3d_k10a_team_flags_apply_80064dcc(b, w3d_auto_80065bf8(self, i).p);
        w3d_cx15a_approach_level_80064950(b);
        f7b_interpolate_800647cc(b);
        w3d_d24g_energy_bar_set_team_80064384(b, i);
        for (unsigned k = 0; k <= 3; k++) {
            if (order[k] == (int)i) w3d_timed_state_set_mode_80064190(b, k + first);
        }
    }
    w3d_fn_800664f8(self);
}



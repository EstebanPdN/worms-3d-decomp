#include "w3d_ptr.h"
#line 1 "f_accessors_b.cpp"
/* Small component accessors and helpers (0x8006bdf4..0x800959cc).
 *
 * Names are inferred from behavior; no original symbols survive. Short
 * methods of the component types in this range: getters, setters, vector
 * sizes, table sums, thin forwarding wrappers and empty hooks. Only the
 * offsets each function touches are described. Pointer vectors are
 * {begin, end} pairs; sizes are element counts.
 */
extern "C" {

typedef struct W3dWordVec3 {
    int x;
    int y;
    int z;
} W3dWordVec3;

typedef struct W3dPose {
    W3dWordVec3 position;
    float scale;
} W3dPose;

typedef struct W3dPairEntry {
    int value;
    int other;
} W3dPairEntry;

typedef struct W3dHandles {
    unsigned char unknown_00[0xd0];
    Ptr32<void> current;
    Ptr32<void> expected;
    unsigned char unknown_d8[0xf0 - 0xd8];
    unsigned int unknown_bits:31; unsigned int enabled:1;
} W3dHandles;

typedef struct W3dPlayerList {
    unsigned char unknown_000[0x7c];
    unsigned char roster[4];
    unsigned char unknown_080[0x124 - 0x80];
    int selection;
    Ptr32<Ptr32<void>> teams_begin;
    Ptr32<Ptr32<void>> teams_end;
    unsigned char unknown_130[0x134 - 0x130];
    Ptr32<Ptr32<void>> worms_begin;
    Ptr32<Ptr32<void>> worms_end;
    unsigned char unknown_13c[0x140 - 0x13c];
    Ptr32<Ptr32<void>> weapons_begin;
    Ptr32<Ptr32<void>> weapons_end;
    unsigned char unknown_148[0x168 - 0x148];
    Ptr32<void> timer;
    unsigned char unknown_16c[0x170 - 0x16c];
    int score_a;
    int score_b;
} W3dPlayerList;

typedef struct W3dPairVector {
    Ptr32<W3dPairEntry> begin;
    Ptr32<W3dPairEntry> end;
} W3dPairVector;

typedef struct W3dRecordOwner {
    unsigned char unknown_000[0xacc];
    unsigned char mode;
    unsigned char unknown_acd[0xad0 - 0xacd];
    W3dPairVector records;
} W3dRecordOwner;

typedef struct W3dPoseOwner {
    unsigned char unknown_000[0x21c];
    W3dPose pose;
} W3dPoseOwner;

typedef struct W3dSceneState {
    unsigned char unknown_00[0xf4];
    Ptr32<void> timer;
} W3dSceneState;

extern const char w3d_str_8037c044[];
extern int w3d_round_value_804abb60;
extern Ptr32<W3dSceneState> w3d_scene_state_804aaabc;
extern short w3d_selected_id_804aab58;
extern Ptr32<void> w3d_selection_target_804aab68;
extern W3dPairEntry w3d_score_table_80431c80[];
extern W3dPairEntry w3d_bonus_table_80431db8[];

void w3d_component_step_8006bce4(Ptr32<void> object);
void w3d_setting_lookup_800fc230(Ptr32<Ptr32<const char>> name, Ptr32<int> value);
int w3d_timer_state_80178d1c(Ptr32<void> timer);
int w3d_timer_set_80178d28(Ptr32<void> timer, Ptr32<int> value);
void w3d_handles_enable_8006eebc(Ptr32<W3dHandles> handles);
void w3d_player_list_refresh_8008a30c(Ptr32<void> object, int first, int second, int force);
int w3d_score_value_800a830c(Ptr32<void> item);
int w3d_selection_apply_8008f1e8(Ptr32<void> target, int value);

void w3d_component_step_8006bdf4(Ptr32<void> object)
{
    w3d_component_step_8006bce4(object);
}

void w3d_component_step_second_8006be14(Ptr32<void> unused, Ptr32<void> object)
{
    w3d_component_step_8006bdf4(object);
}

#if 0 /* 0x8006ce8c: the two local stores are scheduled before the address setup in the original; not reproduced. */
int w3d_round_number_query_8006ce8c(void)
{
    const char *name = w3d_str_8037c044;
    int value = 0;
    w3d_setting_lookup_800fc230(&name, &value);
    return 0;
}
#endif

int w3d_handles_match_8006e10c(Ptr32<W3dHandles> handles)
{
    return handles->current == handles->expected;
}

void w3d_round_value_reset_8006e6f4(Ptr32<void> object, int state)
{
    int match = 0;
    if (state == 5 || state == 7)
        match = 1;
    if (match == 1)
        w3d_round_value_804abb60 = 0;
    else
        w3d_round_value_804abb60 = 0;
}

int w3d_scene_timer_is_one_8006e71c(void)
{
    return w3d_timer_state_80178d1c(w3d_scene_state_804aaabc->timer) == 1;
}

void w3d_scene_timer_set_8006e750(int value)
{
    Ptr32<void> timer = w3d_scene_state_804aaabc->timer;
    int stored = value;
    w3d_timer_set_80178d28(timer, &stored);
}

void w3d_handles_set_enabled_8006ee88(Ptr32<W3dHandles> handles, int enabled)
{
    handles->enabled = enabled;
    if (enabled)
        w3d_handles_enable_8006eebc(handles);
}

void w3d_empty_80070708(void)
{
}

Ptr32<void> w3d_player_list_roster_80071e28(Ptr32<W3dPlayerList> list)
{
    return list->roster;
}

int w3d_return_minus_one_80072fdc(void)
{
    return -1;
}

void w3d_empty_8007304c(void)
{
}

void w3d_empty_80086630(void)
{
}

void w3d_empty_80088f24(void)
{
}

int w3d_player_list_team_count_8008c34c(Ptr32<W3dPlayerList> list)
{
    return list->teams_end - list->teams_begin;
}

int w3d_player_list_worm_count_8008c440(Ptr32<W3dPlayerList> list)
{
    return list->worms_end - list->worms_begin;
}

int w3d_player_list_weapon_count_8008c534(Ptr32<W3dPlayerList> list)
{
    return list->weapons_end - list->weapons_begin;
}

void w3d_player_list_refresh_8008cf14(Ptr32<void> object)
{
    w3d_player_list_refresh_8008a30c(object, 0, 0, 1);
}

#if 0 /* 0x8008da24: the original keeps the even index unreduced (slwi/lwzx); this compiler strength-reduces it. */
int w3d_score_table_total_8008da24(void)
{
    int total = 0;
    int i;
    for (i = 0; i < 40; i += 2)
        total += w3d_score_table_80431c80[i].value;
    return total;
}
#endif

int w3d_bonus_table_total_8008da54(void)
{
    int total = 0;
    int i;
    for (i = 0; i < 20; i++)
        total += w3d_bonus_table_80431db8[i].value;
    return total;
}

int w3d_player_list_timer_active_8008dd18(Ptr32<W3dPlayerList> list)
{
    return w3d_timer_state_80178d1c(list->timer) != 0;
}

int w3d_player_list_selection_8008dd4c(Ptr32<W3dPlayerList> list)
{
    return list->selection;
}

void w3d_player_list_add_score_a_8008e0cc(Ptr32<W3dPlayerList> list, Ptr32<void> item)
{
    list->score_a += w3d_score_value_800a830c(item);
}

void w3d_player_list_add_score_b_8008e108(Ptr32<W3dPlayerList> list, Ptr32<void> item)
{
    list->score_b += w3d_score_value_800a830c(item);
}

int w3d_selection_set_8008ed18(int value, short id)
{
    w3d_selected_id_804aab58 = id;
    if (w3d_selection_target_804aab68)
        return w3d_selection_apply_8008f1e8(w3d_selection_target_804aab68, value);
    return 0;
}

Ptr32<W3dPairEntry> w3d_record_owner_records_80090d7c(Ptr32<W3dRecordOwner> owner, Ptr32<unsigned short> count)
{
    int n = owner->records.end - owner->records.begin;
    *count = n;
    if ((unsigned short)n != 0)
        return owner->records.begin;
    return 0;
}

void w3d_record_owner_set_mode_800919cc(Ptr32<W3dRecordOwner> owner, unsigned char mode)
{
    owner->mode = mode;
}

void w3d_pose_owner_set_pose_8009278c(Ptr32<W3dPoseOwner> owner, Ptr32<const W3dPose> pose)
{
    owner->pose.scale = pose->scale;
    owner->pose.position = pose->position;
}

void w3d_empty_80093294(void)
{
}

void w3d_empty_80095644(void)
{
}

void w3d_empty_800959cc(void)
{
}

}



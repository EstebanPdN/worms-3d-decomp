#include "w3d_ptr.h"
#line 1 "a_ai_planner.cpp"
/* AI turn planner state (0x800063bc..0x80007ccc).
 *
 * Names are inferred from behavior; no original symbols survive. The planner
 * keeps its state in small globals: a state number (7 = idle, 2 = cleared,
 * 1 = running), a countdown timer, a tick counter, three plan vectors, the
 * command list and the command registry. Some tiny functions here are virtual
 * methods of the plan classes (their names appear as strings such as
 * "CAIPlanSkipTurn" and "CAIPlanSeed").
 */
extern "C" {

/* Unused BLKmode local: reproduces 8 bytes of frame the original reserves
 * (the original object is unknown; no surviving instruction uses it). */
typedef struct W3dAiFrameSlot {
    short unknown[3];
} W3dAiFrameSlot;

typedef struct W3dAiVector {
    Ptr32<Ptr32<void>> begin;
    Ptr32<Ptr32<void>> end;
    Ptr32<Ptr32<void>> capacity;
} W3dAiVector;

typedef struct W3dAiByteVector {
    Ptr32<unsigned char> begin;
    Ptr32<unsigned char> end;
    Ptr32<unsigned char> capacity;
} W3dAiByteVector;

typedef struct W3dAiPlan W3dAiPlan;

typedef struct W3dAiPlanVtable {
    unsigned char unknown_00[0x28];
    Ptr32<Ptr32<void> (Ptr32<W3dAiPlan>)> name;
} W3dAiPlanVtable;

struct W3dAiPlan {
    unsigned char unknown_00[4];
    float score;
    unsigned char unknown_08[4];
    Ptr32<W3dAiPlanVtable> vtable;
};

typedef struct W3dAiWeaponInfo {
    unsigned char unknown_00[0xcc];
    int shots;
} W3dAiWeaponInfo;

extern int w3d_ai_planner_state_804aa568;
extern int w3d_ai_planner_flag_804aa56c;
extern float w3d_ai_planner_timer_804aa570;
extern int w3d_ai_planner_ticks_804aa574;
extern int w3d_ai_planner_flag_804aa578;
extern int w3d_ai_planner_flag_804aa57c;
extern Ptr32<W3dAiVector> w3d_ai_plans_a_804aa558;
extern Ptr32<W3dAiVector> w3d_ai_plans_b_804aa55c;
extern Ptr32<W3dAiVector> w3d_ai_plans_c_804aa560;
extern Ptr32<W3dAiVector> w3d_command_list_804aa564;
extern Ptr32<void> w3d_command_registry_804aa5a4;
extern Ptr32<W3dAiVector> w3d_ai_named_list_804aa750;
extern Ptr32<W3dAiByteVector> w3d_ai_buffer_a_804aa754;
extern Ptr32<W3dAiByteVector> w3d_ai_buffer_b_804aa75c;
extern int w3d_ai_turn_team_804aa580;
extern int w3d_ai_weapon_804aa584;
extern int w3d_ai_weapon_shots_804aa588;
extern int w3d_ai_flag_804aa58c;
extern int w3d_ai_weapon_ready_804aa590;
extern int w3d_ai_teams_ready_804aa598;
extern Ptr32<int> w3d_ai_weapon_table_804aa5a8;
extern Ptr32<void> w3d_ai_plan_name_skip_turn_804aa5ac;
extern Ptr32<void> w3d_ai_plan_name_seed_804aa5b0;
extern int w3d_ai_team_804aa6c0;
extern int w3d_ai_team_804aa6c4;
extern int w3d_ai_team_804aa6c8;
extern int w3d_ai_limit_804aa6cc;
extern int w3d_ai_value_804aa6d0;
extern int w3d_ai_value_804aa6e0;
extern int w3d_ai_value_804aa6e4;
extern int w3d_ai_value_804aa6e8;
extern int w3d_ai_team_active_804a84d8[];
extern int w3d_ai_team_state_804a8518[];
extern Ptr32<void> w3d_ai_weapon_names_803eb63c[];
extern const float w3d_f32_100_803694d0[];
extern const float w3d_f32_200_803694d4[];
extern const float w3d_f32_0_803694e4[];
extern Ptr32<void> w3d_world_map_804b1758;

void w3d_ai_planner_step_800064d4(void);
void w3d_vector_destroy_virtual16(Ptr32<W3dAiVector> vector);
void w3d_vector_destroy_virtual12(Ptr32<W3dAiVector> vector);
void w3d_vector_destroy_named(Ptr32<W3dAiVector> vector);
void w3d_memcpy_802eee50(Ptr32<void> dest, Ptr32<const void> source, unsigned int size, ...);
Ptr32<void> w3d_handle_storage_allocate(unsigned int bytes);
void w3d_handle_storage_release(Ptr32<void> storage);
void w3d_string_assign(Ptr32<void> dest, Ptr32<void> source);
void w3d_ai_select_team_800152fc(int team);
int w3d_ai_team_exists_800153dc(int team);
int w3d_ai_team_alive_80015400(int team);
int w3d_ai_turn_active_800157cc(void);
void w3d_world_map_refresh_8001f2cc(Ptr32<void> map);
void w3d_world_map_update_8002013c(Ptr32<void> map);
Ptr32<void> w3d_weapon_lookup_800fc330(Ptr32<Ptr32<void>> name, Ptr32<Ptr32<W3dAiWeaponInfo>> info);
void w3d_command_create_19_80009404(void);
void w3d_command_create_1_80007d58(int value);
void w3d_command_create_6_80008d84(int count);
void w3d_command_create_21_8000953c(void);

extern "C++" {
template<class T> inline const T &w3d_ai_max(const T &first, const T &second)
{ return first < second ? second : first; }
template<class T> inline const T &w3d_ai_min(const T &first, const T &second)
{ return second < first ? second : first; }
}

int w3d_ai_plan_return_zero_800063bc(void)
{
    return 0;
}

void w3d_ai_plan_nop_800063c4(void)
{
}

int w3d_ai_plan_return_zero_800063c8(void)
{
    return 0;
}

void w3d_ai_planner_set_state(int state);
void w3d_ai_planner_reset(void);
void w3d_ai_planner_destroy(void);
void w3d_ai_select_team(int team);
void w3d_ai_set_registry(Ptr32<void> registry);

void w3d_ai_planner_stop(void)
{
    switch (w3d_ai_planner_state_804aa568) {
    case 0:
    case 1:
        break;
    case 7:
        w3d_ai_planner_set_state(1);
        break;
    default: {
        int team = w3d_ai_team_804aa6c0;
        Ptr32<void> registry = w3d_command_registry_804aa5a4;
        w3d_ai_planner_reset();
        w3d_ai_planner_destroy();
        w3d_ai_select_team(team);
        w3d_ai_set_registry(registry);
        break;
    }
    }
    w3d_ai_planner_ticks_804aa574 = 0;
}

void w3d_ai_planner_update(void)
{
    W3dAiFrameSlot unused;

    w3d_ai_planner_timer_804aa570 -= w3d_f32_100_803694d0[0];
    if (w3d_ai_planner_timer_804aa570 > w3d_f32_100_803694d0[0])
        w3d_ai_planner_timer_804aa570 = w3d_f32_200_803694d4[0];
    w3d_ai_planner_ticks_804aa574++;
    while (w3d_ai_planner_state_804aa568 != 7 && w3d_ai_planner_timer_804aa570 < w3d_f32_100_803694d0[0])
        w3d_ai_planner_step_800064d4();
}

void w3d_ai_planner_clear_800066e0(void);

void w3d_ai_planner_destroy(void)
{
    w3d_ai_planner_clear_800066e0();
    w3d_vector_destroy_virtual16(w3d_command_list_804aa564);
}

void w3d_ai_planner_reset(void)
{
    w3d_ai_planner_clear_800066e0();
    w3d_ai_limit_804aa6cc = 1000;
    w3d_ai_team_804aa6c0 = -1;
    w3d_ai_team_804aa6c4 = -1;
    w3d_ai_value_804aa6e8 = -1;
    w3d_ai_value_804aa6d0 = 0;
    w3d_command_registry_804aa5a4 = 0;
    w3d_ai_planner_set_state(7);
}

static inline void w3d_ai_bytes_erase(Ptr32<W3dAiByteVector> vector, Ptr32<unsigned char> first, Ptr32<unsigned char> last)
{
    int removed = last - first;
    w3d_memcpy_802eee50(first, last, vector->end - last);
    vector->end = vector->end - removed;
}

static inline void w3d_ai_bytes_clear(Ptr32<W3dAiByteVector> vector)
{
    w3d_ai_bytes_erase(vector, vector->begin, vector->end);
}


void w3d_ai_planner_set_state(int state)
{
    w3d_ai_planner_state_804aa568 = state;
}

void w3d_ai_swap_plan_lists(void)
{
    Ptr32<W3dAiVector> a = w3d_ai_plans_a_804aa558;
    w3d_ai_plans_a_804aa558 = w3d_ai_plans_b_804aa55c;
    w3d_ai_plans_b_804aa55c = a;
}

void w3d_ai_init_teams(void)
{
    int i;
    w3d_ai_teams_ready_804aa598 = 1;
    for (i = 0; i < 16; i++) {
        if (w3d_ai_team_exists_800153dc(i) && w3d_ai_team_alive_80015400(i))
            w3d_ai_team_active_804a84d8[i] = 1;
        else
            w3d_ai_team_active_804a84d8[i] = 0;
        w3d_ai_team_state_804a8518[i] = 0;
    }
}

void w3d_ai_vector_push(Ptr32<W3dAiVector> vector, Ptr32<void> item);

void w3d_ai_push_plan_b(Ptr32<void> plan)
{
    w3d_ai_vector_push(w3d_ai_plans_b_804aa55c, plan);
}

void w3d_ai_push_plan_a(Ptr32<void> plan)
{
    w3d_ai_vector_push(w3d_ai_plans_a_804aa558, plan);
    w3d_ai_planner_flag_804aa578 = 1;
}

void w3d_ai_plan_get_name(Ptr32<W3dAiPlan> plan, Ptr32<void> name)
{
    w3d_string_assign(name, plan->vtable->name(plan));
}

Ptr32<void> w3d_ai_vector_pop(Ptr32<W3dAiVector> vector)
{
    Ptr32<Ptr32<void>> end = vector->end;
    Ptr32<void> item = *--end;
    vector->end = end;
    return item;
}

static inline void w3d_ai_vector_push_ref(Ptr32<W3dAiVector> vector, Ptr32<void> const &item)
{
    if (vector->end == vector->capacity) {
        unsigned int used = (Ptr32<unsigned char>)vector->end - (Ptr32<unsigned char>)vector->begin;
        unsigned int bytes = 4 * w3d_ai_max((int)(used + 1), (int)(used + (used >> 1)));
        Ptr32<unsigned char> replacement = (Ptr32<unsigned char>)w3d_handle_storage_allocate(bytes);
        if (vector->begin) {
            w3d_memcpy_802eee50(replacement, vector->begin, w3d_ai_min(bytes, used));
            w3d_handle_storage_release(vector->begin);
        }
        vector->begin = (Ptr32<Ptr32<void>>)replacement;
        vector->end = (Ptr32<Ptr32<void>>)(replacement + used);
        vector->capacity = (Ptr32<Ptr32<void>>)(replacement + bytes);
    }
    *vector->end = item;
    vector->end++;
}

void w3d_ai_vector_push(Ptr32<W3dAiVector> vector, Ptr32<void> item)
{
    w3d_ai_vector_push_ref(vector, item);
}


Ptr32<void> w3d_ai_plan_skip_turn_name(void)
{
    return w3d_ai_plan_name_skip_turn_804aa5ac;
}

void w3d_ai_plan_nop_80007760(void)
{
}

int w3d_ai_plan_return_zero_80007764(void)
{
    return 0;
}

int w3d_ai_weapon_available(int weapon);

void w3d_ai_check_skip_weapon(void)
{
    w3d_ai_weapon_available(49);
}

void w3d_ai_plan_skip_turn(void)
{
    if (w3d_ai_weapon_available(49)) {
        w3d_command_create_19_80009404();
        w3d_command_create_1_80007d58(49);
        w3d_command_create_6_80008d84(1000);
        w3d_command_create_21_8000953c();
    } else {
        w3d_command_create_19_80009404();
        w3d_command_create_6_80008d84(100000);
    }
}

Ptr32<void> w3d_ai_plan_seed_name(void)
{
    return w3d_ai_plan_name_seed_804aa5b0;
}

void w3d_ai_plan_nop_800077f0(void)
{
}

void w3d_ai_select_team(int team)
{
    w3d_ai_select_team_800152fc(team);
}

void w3d_ai_begin_turn(int team)
{
    if (w3d_ai_turn_team_804aa580 != team) {
        w3d_ai_turn_team_804aa580 = -1;
        w3d_ai_weapon_804aa584 = 60;
        w3d_ai_weapon_shots_804aa588 = 0;
    } else if (w3d_ai_weapon_ready_804aa590 == 0) {
        w3d_ai_turn_team_804aa580 = -1;
        w3d_ai_weapon_804aa584 = 60;
        w3d_ai_weapon_shots_804aa588 = 0;
    }
    if (w3d_ai_team_804aa6c8 != team) {
        w3d_ai_flag_804aa58c = 0;
        w3d_ai_value_804aa6e0 = 0;
        w3d_ai_value_804aa6e4 = 0;
        w3d_ai_weapon_ready_804aa590 = 0;
    }
    w3d_world_map_refresh_8001f2cc(w3d_world_map_804b1758);
    w3d_world_map_update_8002013c(w3d_world_map_804b1758);
    w3d_ai_teams_ready_804aa598 = 0;
}

void w3d_ai_weapon_fired(void)
{
    w3d_ai_weapon_ready_804aa590 = 1;
    if (w3d_ai_weapon_804aa584 != 60)
        w3d_ai_weapon_shots_804aa588--;
}

void w3d_ai_select_weapon(int weapon)
{
    Ptr32<W3dAiWeaponInfo> info;
    if (w3d_ai_weapon_804aa584 == 60) {
        Ptr32<void> name;
        Ptr32<W3dAiWeaponInfo> found;
        name = w3d_ai_weapon_names_803eb63c[weapon];
        w3d_ai_turn_team_804aa580 = w3d_ai_team_804aa6c0;
        w3d_ai_weapon_804aa584 = weapon;
        w3d_weapon_lookup_800fc330(&name, &found);
        info = found;
    } else {
        Ptr32<void> name;
        Ptr32<W3dAiWeaponInfo> found;
        if (!w3d_ai_turn_active_800157cc())
            return;
        if (w3d_ai_weapon_shots_804aa588 != 0)
            return;
        name = w3d_ai_weapon_names_803eb63c[weapon];
        w3d_weapon_lookup_800fc330(&name, &found);
        info = found;
    }
    w3d_ai_weapon_shots_804aa588 = info->shots;
}

void w3d_ai_set_registry(Ptr32<void> registry)
{
    w3d_command_registry_804aa5a4 = registry;
}

int w3d_ai_weapon_available(int weapon)
{
    if (w3d_ai_weapon_804aa584 != 60) {
        if (weapon == w3d_ai_weapon_804aa584 && w3d_ai_weapon_shots_804aa588 > 0)
            return 1;
        return 0;
    }
    if (w3d_ai_weapon_ready_804aa590 != 0 && !w3d_ai_turn_active_800157cc())
        return 0;
    return w3d_ai_weapon_table_804aa5a8[weapon] != 0;
}


#if 0
/* 0x800066e0: one scheduling swap in the second buffer clear (argument move
 * versus length subtraction). */
void w3d_ai_planner_clear_800066e0(void)
{
    w3d_vector_destroy_virtual12(w3d_ai_plans_a_804aa558);
    w3d_vector_destroy_virtual12(w3d_ai_plans_b_804aa55c);
    w3d_vector_destroy_virtual12(w3d_ai_plans_c_804aa560);
    w3d_vector_destroy_named(w3d_ai_named_list_804aa750);
    w3d_ai_bytes_clear(w3d_ai_buffer_a_804aa754);
    w3d_ai_bytes_clear(w3d_ai_buffer_b_804aa75c);
    w3d_ai_planner_timer_804aa570 = w3d_f32_0_803694e4[0];
    w3d_ai_planner_flag_804aa56c = 0;
    w3d_ai_planner_flag_804aa578 = 0;
    w3d_ai_planner_flag_804aa57c = 0;
    w3d_ai_planner_set_state(2);
}

/* 0x800076c4: same instructions; index and start counters get swapped
 * registers. */
void w3d_ai_sort_plans(W3dAiVector *vector)
{
    int i = 0;
    int start = 0;
    int n = vector->end - vector->begin;
    if (n - 1 <= 0)
        return;
    do {
        W3dAiPlan *a = (W3dAiPlan *)vector->begin[i];
        W3dAiPlan *b = (W3dAiPlan *)vector->begin[i + 1];
        if (a->score > b->score) {
            vector->begin[i] = b;
            vector->begin[i + 1] = a;
            start = 0;
            i++;
        } else if (i == start) {
            start++;
            i = start;
        } else {
            i++;
        }
        if (i == n - 1)
            i = start;
    } while (start < n - 1);
}
#endif

}



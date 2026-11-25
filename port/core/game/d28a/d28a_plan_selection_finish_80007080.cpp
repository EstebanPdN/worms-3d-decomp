#include "w3d_ptr.h"
#line 1 "d28a_plan_selection_finish_80007080.cpp"
// GWMP8P rev0 0x80007080. Stores a worm's finished plan. When no other team
// member is still pending, picks the highest-scoring plan, destroys them all
// and commits the choice; otherwise switches to the next pending worm. Names
// are inferred from the original instructions.
struct Plan {
    int unknown0;
    float score;       /* +4 */
    int unknown8;
    Ptr32<Ptr32<void>> vtable;     /* +12; slot +12 is the deleting destructor */
    void Delete() { ((Ptr32<void (Ptr32<Plan>, int)>)vtable[3])(this, 3); }
};
extern int g_worm_804aa6c0, g_chooser_804aa6c4, g_busy_804aa598;
extern Ptr32<Plan> g_plans_804a8518[];
extern int g_pending_804a84d8[];
extern "C" void w3d_cx7p_planner_reset_800066e0();
extern "C" void w3d_ai_planner_set_state(int);
extern "C" int w3d_auto_800153dc(int);
extern "C" int s19_slot_matches_global_80015400(int);
extern "C" void w3d_ai_select_team(int);
extern "C" void w3d_command_create_19();
extern "C" void w3d_command_create_18(int);
extern "C" void w3d_d28a_plan_selection_finish_80007080(Ptr32<Plan> plan)
{
    g_pending_804a84d8[g_worm_804aa6c0] = 0;
    g_plans_804a8518[g_worm_804aa6c0] = plan;
    w3d_cx7p_planner_reset_800066e0();
    w3d_ai_planner_set_state(2);
    int i;
    for (i = 0; i <= 15; i++) {
        if (g_pending_804a84d8[i] != 0) {
            int r = w3d_auto_800153dc(i);
            if (r != 0 && (r = s19_slot_matches_global_80015400(i)) != 0) goto picked;
            g_pending_804a84d8[i] = r;
        }
    }
picked:
    if (i == 16) {
        float best = -1e20f;
        int chosen = -1;
        for (i = 0; i < 16; i++) {
            Ptr32<Plan> p = g_plans_804a8518[i];
            if (p && p->score > best) { best = p->score; chosen = i; }
        }
        if (chosen == -1) chosen = g_chooser_804aa6c4;
        for (i = 0; i < 16; i++) {
            if (g_plans_804a8518[i]) g_plans_804a8518[i]->Delete();
            g_plans_804a8518[i] = 0;
        }
        w3d_command_create_19();
        w3d_command_create_18(chosen);
        w3d_ai_select_team(chosen);
        g_busy_804aa598 = 0;
    } else {
        w3d_ai_select_team(i);
    }
}



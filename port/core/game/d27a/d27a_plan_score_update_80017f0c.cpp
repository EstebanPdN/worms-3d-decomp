#include "w3d_ptr.h"
#line 1 "d27a_plan_score_update_80017f0c.cpp"
// GWMP8P rev0 0x80017f0c. Computes a plan's score from the worm's state and
// rejects it near other worms. Names are inferred from the original
// instructions.
extern "C" float sqrt_802e82c0(float);
extern "C" float w3d_libm_forward_802e83cc(float);
extern "C" float w3d_fn_802e8094(float);
struct Vec { float x, y, z; };
struct Worm;
struct Query { char unknown00[136]; unsigned count; char unknown8c[64]; int active; };
struct Query2 { char unknown00[236]; float factor; };
struct Component { char unknown00[72]; int alive; };
struct List;
struct Settings {
    char unknown00[24]; float f24;
    char unknown1c[80]; float f108; char unknown70[4]; float f116, f120, f124, f128;
    char unknown84[52]; float f184;
};
extern Ptr32<Settings> w3d_settings_804aa6d8;
extern float g_scale_804aa74c;
extern int g_a_804aa748, g_b_804aa744;
extern Ptr32<List> g_players_804aab4c;
extern Vec g_center_8041d3a0;
extern "C" Ptr32<Vec> w3d_auto_80015588(Ptr32<Worm>);
extern "C" Ptr32<Query> s8_index_query_800fc6dc(int);
extern "C" int w3d_auto_800155ac(Ptr32<Worm>);
extern "C" int s19_check_pair_80015434(Ptr32<Worm>);
extern "C" Ptr32<Query2> s8_index_query_800fcb4c(int);
extern "C" bool w3d_auto_80015488(Ptr32<Worm>);
extern "C" int w3d_player_list_worm_count_8008c440(Ptr32<List>);
extern "C" Ptr32<Component> s19_lookup_slot_8008c454(Ptr32<List>, int);
extern "C" Ptr32<Vec> w3d_component_position_801256ec(Ptr32<Component>);
extern "C" Ptr32<float> w3d_component_radius_801256e4(Ptr32<Component>);
struct Plan { char unknown00[8]; Ptr32<Worm> worm; float score; };
inline float DistSq(const Vec &a, const Vec &b)
{
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return dx * dx + dy * dy + dz * dz;
}
extern "C" int w3d_d27a_plan_score_update_80017f0c(Ptr32<Plan> self)
{
    Ptr32<Worm> w = self->worm;
    float score = 1.0f;
    Ptr32<Vec> pos = w3d_auto_80015588(w);
    if (s8_index_query_800fc6dc((int)w3d::H(w))->active) score = w3d_settings_804aa6d8->f124;
    score *= (float)w3d_auto_800155ac(w) * w3d_settings_804aa6d8->f120 + 1.0f;
    float k = 1.0f - (float)s8_index_query_800fc6dc((int)w3d::H(w))->count * w3d_settings_804aa6d8->f116;
    if (k <= 0.1f) k = 0.1f;
    score += k;
    int flag;
    if (s19_check_pair_80015434(w)) {
        flag = g_a_804aa748;
        score /= g_scale_804aa74c;
    } else {
        flag = g_b_804aa744;
        score *= -g_scale_804aa74c;
    }
    if (flag == 1) score *= w3d_settings_804aa6d8->f108;
    float f = w3d_settings_804aa6d8->f128;
    if (f != 0.0f) {
        float d = sqrt_802e82c0(DistSq(g_center_8041d3a0, *pos));
        if (d < 200.0f) d = 200.0f;
        score *= w3d_fn_802e8094(f * w3d_libm_forward_802e83cc(200.0f / d));
    }
    float q = s8_index_query_800fcb4c((int)w3d::H(w))->factor;
    if (q != 1.0f) score *= q;
    f = w3d_settings_804aa6d8->f184;
    if (f != 1.0f) {
        bool r = !w3d_auto_80015488(w);
        if (score > 0.0f && r) score *= f;
    }
    if (w3d_settings_804aa6d8->f24 == 1.0f) {
        int n = w3d_player_list_worm_count_8008c440(g_players_804aab4c);
        if (n > 0) {
            for (int i = 0; i < n; i++) {
                Ptr32<Component> c = s19_lookup_slot_8008c454(g_players_804aab4c, i);
                if (c->alive) {
                    Ptr32<Vec> p = w3d_component_position_801256ec(c);
                    Ptr32<float> rad = w3d_component_radius_801256e4(c);
                    if (DistSq(*p, *pos) <= *rad * *rad) return 0;
                }
            }
        }
    }
    self->score = score;
    return 1;
}



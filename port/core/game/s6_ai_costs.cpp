#include "w3d_ptr.h"
#line 1 "s6_ai_costs.cpp"
extern "C" {
struct S6CostVec { float x,y,z; };
static inline float s6_squared(Ptr32<const S6CostVec> a,Ptr32<const S6CostVec> b) {
    float x=a->x-b->x; float y=a->y-b->y; float z=a->z-b->z;
    return (x*x+y*y)+z*z;
}
struct S6CostPlan { int kind; float cost; int active; Ptr32<void> vtable; int index; Ptr32<void> actor; S6CostVec origin; char unknown_24[28]; unsigned char flag, amount; };
struct S6CostEntry { char unknown[12]; float cost; S6CostVec position; int damage; float scale; };
struct S6CostList { Ptr32<Ptr32<S6CostEntry>> begin; Ptr32<Ptr32<S6CostEntry>> end; };
struct S6CostTuning { char unknown_0[64]; float exposure_scale; float unknown_44; float unknown_48; float range_scale; char unknown_50[4]; float minimum; float unknown_58; float unknown_5c; float cost_scale; };
extern Ptr32<S6CostList> w3d_ai_entries_804aa750;
extern Ptr32<S6CostTuning> w3d_ai_tuning_804aa6d8;
extern const float w3d_f32_80369c48[],w3d_f32_80369c4c[],w3d_f32_80369c50[],w3d_f32_80369c54[],w3d_f32_80369c5c[],w3d_f32_80369c60[],w3d_f32_80369c68[],w3d_f32_80369c6c[],w3d_f32_80369c98[];
float w3d_fn_802e82c0(float);
float w3d_fn_8021d100(Ptr32<S6CostTuning>,int);
float w3d_fn_800168b0(Ptr32<S6CostPlan>);
void w3d_auto_8000b2f8(Ptr32<S6CostPlan>,int);
void w3d_fn_8000a280(Ptr32<S6CostPlan>);
#if 0 /* Not exact: register allocation or instruction scheduling differs. */
float w3d_ai_damage_cost_8000b344(S6CostPlan *plan,int index,float chance,float damage) {
    S6CostEntry *entry = w3d_ai_entries_804aa750->begin[index];
    float maximum = (float)entry->damage;
    float adjusted = w3d_ai_tuning_804aa6d8->cost_scale;
    float scale = adjusted;
    int clamped = 0;
    if (damage >= maximum) {
        damage = maximum;
        clamped = 1;
        if (damage < w3d_ai_tuning_804aa6d8->minimum) damage = w3d_ai_tuning_804aa6d8->minimum;
    }
    if (chance != w3d_f32_80369c48[0] && !clamped && !plan->flag) {
        float slope = entry->scale;
        damage += (maximum-damage)*slope*chance;
        adjusted = scale*(slope*chance + w3d_f32_80369c4c[0]);
        if (damage > maximum) damage = maximum;
    }
    float cost = entry->cost;
    adjusted *= damage;
    return adjusted*cost;
}
#endif
#if 0 /* Not exact: register allocation or instruction scheduling differs. */
float w3d_ai_distance_weight_8000b418(S6CostPlan *plan,int index,float range) {
    float zero = w3d_f32_80369c50[0];
    if (range != zero) {
        S6CostEntry *entry = w3d_ai_entries_804aa750->begin[index];
        S6CostVec origin = plan->origin;
        float distance = w3d_fn_802e82c0(s6_squared(&origin,&entry->position));
        if (distance < range) return w3d_f32_80369c54[0]-distance/range;
    }
    return zero;
}
#endif
#if 0 /* Not exact: register allocation or instruction scheduling differs. */
float w3d_ai_distance_penalty_8000b5f4(S6CostPlan *plan,float range) {
    float zero = w3d_f32_80369c5c[0];
    if (range == zero) return zero;
    S6CostEntry *entry = w3d_ai_entries_804aa750->begin[plan->index];
    S6CostVec origin = plan->origin;
    float distance = w3d_fn_802e82c0(s6_squared(&origin,&entry->position));
    float factor = w3d_f32_80369c60[0];
    if (distance > zero) {
        factor = range/distance;
        if (factor < w3d_f32_80369c60[0]) factor = w3d_f32_80369c60[0];
    }
    return factor*w3d_ai_tuning_804aa6d8->range_scale;
}
#endif
void w3d_ai_scale_exposure_8000b7dc(Ptr32<S6CostPlan> plan) {
    float weight = w3d_fn_8021d100(w3d_ai_tuning_804aa6d8,(int)w3d::H(plan->actor));
    plan->cost *= weight;
    float exposure = w3d_fn_800168b0(plan);
    float zero = w3d_f32_80369c68[0];
    if (exposure > zero) {
        float factor = w3d_f32_80369c6c[0]-exposure*w3d_ai_tuning_804aa6d8->exposure_scale;
        if (factor < zero) factor = zero;
        plan->cost *= factor;
    }
}
void w3d_ai_add_amount_cost_8000b86c(Ptr32<S6CostPlan> plan) {
    w3d_auto_8000b2f8(plan,0);
    w3d_fn_8000a280(plan);
    plan->cost += (float)((3-plan->amount)/3)*w3d_f32_80369c98[0];
}
}



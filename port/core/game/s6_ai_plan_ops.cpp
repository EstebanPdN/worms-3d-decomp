#include "w3d_ptr.h"
#line 1 "s6_ai_plan_ops.cpp"
extern "C" {
struct S6Vec { float x,y,z; };
struct S6PlanOps {
    int unknown_0; float cost; int unknown_8; Ptr32<void> vtable;
    int index; Ptr32<void> actor; S6Vec origin; S6Vec result; S6Vec target;
    float result_cost; unsigned char flag; unsigned char amount;
    char unknown_42[10]; Ptr32<void> queue_a; int unknown_50; Ptr32<void> queue_b; S6Vec saved;
};
struct S6NamedCost { char unknown[12]; float cost; };
struct S6NamedCosts { unsigned int begin; };
struct S6AiTuning { char unknown[96]; float cost_scale; };
extern Ptr32<S6NamedCosts> w3d_ai_costs_804aa750;
extern Ptr32<S6AiTuning> w3d_ai_tuning_804aa6d8;
extern S6Vec w3d_ai_origin_8041d3a0[];
extern S6Vec w3d_ai_result_8041e850[];
extern float w3d_ai_result_cost_804b1768;
extern float w3d_ai_cost_804aa570;
extern const float w3d_f32_80369bac[], w3d_f32_80369bcc[], w3d_f32_80369bd0[], w3d_f32_80369bd4[], w3d_f32_80369bd8[];
extern const float w3d_f32_80369c0c[], w3d_f32_80369c10[];
extern const char w3d_str_80369bfc[];
extern char w3d_vtable_8040d7b8[];
int w3d_fn_80009b04(Ptr32<S6PlanOps>, Ptr32<void>, Ptr32<void>, float);
int w3d_fn_80009f08(Ptr32<S6PlanOps>, Ptr32<void>, Ptr32<void>, float);
void w3d_move_queue_release(Ptr32<void>);
void w3d_path_cost_destroy(Ptr32<S6PlanOps>, int);
void w3d_auto_80015264(Ptr32<void>);
void w3d_fn_8001a7f8(Ptr32<void>, Ptr32<S6Vec>, int);
int w3d_fn_8001aaf8(Ptr32<S6Vec>, float, float);
int w3d_fn_8001ae30(Ptr32<S6Vec>);
int w3d_fn_8001b0d4(Ptr32<S6Vec>);
void w3d_fn_800fc1f0(Ptr32<Ptr32<const char>>, Ptr32<int>);
#if 0 /* Four attempts: frame is eight bytes too small. */
int w3d_ai_try_attack_80009a94(S6PlanOps *plan, void *a, void *b, float cost) {
    if (w3d_fn_80009b04(plan,a,b,cost)) return 1;
    if (w3d_fn_80009f08(plan,a,b,cost)) return 1;
    return 0;
}
#endif
void w3d_ai_attack_plan_destroy_8000a20c(Ptr32<S6PlanOps> plan,int flags) {
    plan->vtable = w3d_vtable_8040d7b8;
    if (plan->queue_b) w3d_move_queue_release(plan->queue_b);
    if (plan->queue_a) w3d_move_queue_release(plan->queue_a);
    w3d_path_cost_destroy(plan,0);
    if (flags&1) w3d_auto_80015264(plan);
}
#if 0 /* Six attempts: one indexed-load operand order differs. */
void w3d_ai_add_named_cost_8000a280(S6PlanOps *plan) {
    unsigned int index = plan->index;
    if (index != -1) {
        S6NamedCost *entry = *(S6NamedCost **)((index << 2) + w3d_ai_costs_804aa750->begin);
        plan->cost = entry->cost * w3d_ai_tuning_804aa6d8->cost_scale + plan->cost;
    } else {
        plan->cost += w3d_f32_80369bac[0];
    }
}
#endif
void w3d_ai_set_query_origin_8000a62c(Ptr32<S6PlanOps> plan) {
    if (plan->queue_a) w3d_ai_origin_8041d3a0[0] = plan->saved;
    w3d_fn_8001a7f8(plan->actor,w3d_ai_origin_8041d3a0,1);
}
int w3d_ai_capture_query_8000a68c(Ptr32<S6PlanOps> plan,int result) {
    if (result) {
        S6Vec position;
        position.x = w3d_ai_result_8041e850[0].x;
        position.y = w3d_ai_result_8041e850[0].y;
        position.z = w3d_ai_result_8041e850[0].z;
        plan->result = position;
        plan->result_cost = w3d_ai_result_cost_804b1768;
    }
    return result;
}
#if 0 /* Four attempts: frame is eight bytes too small. */
int w3d_ai_query_range_8000a6ec(S6PlanOps *plan,float distance) {
    w3d_ai_cost_804aa570 += w3d_f32_80369bcc[0];
    w3d_ai_set_query_origin_8000a62c(plan);
    return w3d_ai_capture_query_8000a68c(plan,w3d_fn_8001aaf8(&plan->origin,distance,w3d_f32_80369bd0[0]));
}
#endif
int w3d_ai_query_a_8000a758(Ptr32<S6PlanOps> plan) {
    w3d_ai_cost_804aa570 += w3d_f32_80369bd4[0];
    w3d_ai_set_query_origin_8000a62c(plan);
    return w3d_ai_capture_query_8000a68c(plan,w3d_fn_8001ae30(&plan->origin));
}
int w3d_ai_query_b_8000a7ac(Ptr32<S6PlanOps> plan) {
    w3d_ai_cost_804aa570 += w3d_f32_80369bd8[0];
    w3d_ai_set_query_origin_8000a62c(plan);
    return w3d_ai_capture_query_8000a68c(plan,w3d_fn_8001b0d4(&plan->origin));
}
#if 0 /* Four attempts: frame is eight bytes too small. */
float w3d_ai_apply_double_damage_8000af90(float damage) {
    const char *name = w3d_str_80369bfc;
    int enabled;
    w3d_fn_800fc1f0(&name,&enabled);
    if (damage == w3d_f32_80369c0c[0]) damage = w3d_f32_80369c10[0];
    if (enabled == 1) damage += damage;
    return damage;
}
#endif
}



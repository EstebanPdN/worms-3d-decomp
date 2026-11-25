struct K7aVec { float x, y, z; };
struct K7aWeaponPlan { int kind; float cost; int active; void *vtable; int index; void *actor; K7aVec origin, result, target; float result_cost; unsigned char flag, amount; char unknown_42[34]; float weight; };
struct K7aWeaponTuning { float values[120]; };
extern "C" K7aWeaponTuning *w3d_ai_tuning_804aa6d8;
extern "C" const char w3d_str_80369f44[];
extern "C" const char w3d_str_80369f58[];
extern "C" const float w3d_f32_80369f70[];
extern "C" void w3d_auto_8000b2f8(K7aWeaponPlan *plan, int mode);
extern "C" float w3d_ai_bomber_damage_8000e058(K7aWeaponPlan *plan);
extern "C" float w3d_ai_bomber_radius_8000e094(K7aWeaponPlan *plan);
extern "C" float w3d_ai_bomber_range_8000e0bc(K7aWeaponPlan *plan);
extern "C" void w3d_fn_800fc270(const char **name, float *value);
extern "C" void w3d_fn_800fc230(const char **name, unsigned int *value);
extern "C" float w3d_fn_8000b4c4(K7aWeaponPlan *plan, float reach, float a, float b, float damage);
extern "C" float w3d_fn_8000b5f4(K7aWeaponPlan *plan, float range);
extern "C" void w3d_fn_8000b7dc(K7aWeaponPlan *plan);

extern "C" void w3d_k7a_bomber_score_8000e0ec(K7aWeaponPlan *plan)
{
    w3d_auto_8000b2f8(plan, 0);
    float damage = w3d_ai_bomber_damage_8000e058(plan);
    const char *speed_name = w3d_str_80369f44;
    float speed;
    w3d_fn_800fc270(&speed_name, &speed);
    const char *duration_name = w3d_str_80369f58;
    unsigned int duration;
    w3d_fn_800fc230(&duration_name, &duration);
    float radius = w3d_ai_bomber_radius_8000e094(plan);
    float reach = speed * (float)duration + (radius + radius);
    plan->cost += w3d_fn_8000b4c4(plan, reach, w3d_ai_tuning_804aa6d8->values[23], w3d_ai_tuning_804aa6d8->values[22], damage);
    plan->cost += w3d_fn_8000b5f4(plan, w3d_ai_bomber_range_8000e0bc(plan));
    w3d_fn_8000b7dc(plan);
    plan->cost = plan->cost * w3d_ai_tuning_804aa6d8->values[106] * plan->weight;
}

extern "C" {
struct S6CallbackVec { float x,y,z; };
struct S6CallbackPlan;
struct S6CallbackTable {
    void *unknown[9];
    S6CallbackPlan *(*clone)(S6CallbackPlan *);
    void *unknown_28;
    int (*available)(S6CallbackPlan *);
    float (*range)(S6CallbackPlan *);
    void (*execute)(S6CallbackPlan *);
};
struct S6CallbackPlan {
    int kind; float cost; int active; S6CallbackTable *vtable; int index; void *actor;
    S6CallbackVec origin,result,target; float result_cost;
    unsigned char flag,amount; char unknown_42[10]; void *queue_a; int unknown_50; void *queue_b;
    S6CallbackVec saved; float weight;
    bool special() const { return flag; }
};
struct S6CallbackTuning {
    float values[120];
};
struct S6CallbackEntry { char unknown[12]; float cost; };
struct S6CallbackEntries { S6CallbackEntry **begin; };
struct S6WeaponProperties {
    char unknown[200]; float damage_a; unsigned int count; char unknown_d0[20]; float damage_b;
    char unknown_e8[20]; float radius_a; float unknown_100; float radius_b;
    char unknown_108[28]; float damage_scale; float range; char unknown_128[20]; int special;
};
extern S6CallbackTuning *w3d_ai_tuning_804aa6d8;
extern S6CallbackEntries *w3d_ai_entries_804aa750;
extern int w3d_ai_mode_804aa588;
void w3d_auto_8000b2f8(S6CallbackPlan *,int);
void w3d_ai_push_plan_a(S6CallbackPlan *);
S6WeaponProperties *w3d_cached_name_lookup_80341694(S6CallbackPlan *,int);
S6WeaponProperties *w3d_cached_name_lookup_80341710(S6CallbackPlan *,int);
float w3d_fn_8000af90(S6CallbackPlan *,float);
float w3d_fn_8000b4c4(S6CallbackPlan *,float,float,float,float);
float w3d_fn_8000b5f4(S6CallbackPlan *,float);
void w3d_fn_8000b7dc(S6CallbackPlan *);
void w3d_fn_8000affc(S6CallbackPlan *,int,float);
float w3d_fn_8001b660(S6CallbackVec *);
float w3d_fn_8001b734(S6CallbackVec *);
int w3d_fn_8000a6ec(S6CallbackPlan *,float);
int w3d_fn_8000a758(S6CallbackPlan *);
int w3d_fn_8000b6bc(S6CallbackPlan *,int);
void w3d_move_queue_release(void *);
int w3d_fn_800157cc();
void w3d_command_create_7();
void w3d_ai_select_weapon(int);
extern const float w3d_f32_80369cc4[],w3d_f32_80369cc8[],w3d_f32_80369d10[],w3d_f32_80369d28[],w3d_f32_80369d44[],w3d_f32_80369dec[],w3d_f32_80369df0[],w3d_f32_80369e3c[],w3d_f32_80369eb8[];
int w3d_ai_clone_and_enqueue_8000c078(S6CallbackPlan *plan) {
    plan->amount=0; plan->active=1;
    w3d_ai_push_plan_a(plan->vtable->clone(plan));
    return 0;
}
float w3d_ai_weapon_damage_8000ce84(S6CallbackPlan *plan) {
    S6WeaponProperties *props=w3d_cached_name_lookup_80341694(plan,0);
    return w3d_fn_8000af90(plan,props->damage_a);
}
float w3d_ai_weapon_radius_8000cec0(S6CallbackPlan *plan) {
    return w3d_cached_name_lookup_80341694(plan,0)->radius_b;
}
float w3d_ai_weapon_range_8000cee8(S6CallbackPlan *plan) {
    return w3d_cached_name_lookup_80341694(plan,0)->radius_a;
}
#if 0 /* Not exact: register allocation or instruction scheduling differs. */
void w3d_ai_score_attack_8000cf18(S6CallbackPlan *plan) {
    w3d_auto_8000b2f8(plan,0);
    float damage=w3d_ai_weapon_damage_8000ce84(plan);
    float radius=plan->vtable->range(plan);
    plan->cost+=w3d_fn_8000b4c4(plan,radius,w3d_ai_tuning_804aa6d8->values[23],w3d_ai_tuning_804aa6d8->values[22],damage);
    float range=w3d_ai_weapon_range_8000cee8(plan);
    plan->cost+=w3d_fn_8000b5f4(plan,range);
    w3d_fn_8000b7dc(plan);
    plan->cost=plan->cost*w3d_ai_tuning_804aa6d8->values[108]*plan->weight;
}
#endif
#if 0 /* Not exact: register allocation or instruction scheduling differs. */
void w3d_ai_execute_result_8000d004(S6CallbackPlan *plan) {
    float duration=w3d_ai_tuning_804aa6d8->values[15];
    int type=(int)w3d_fn_8001b660(&plan->result);
    w3d_fn_8000affc(plan,type,duration);
}
#endif
int w3d_ai_test_range_a_8000d068(S6CallbackPlan *plan) {
    return w3d_fn_8000b6bc(plan,w3d_fn_8000a6ec(plan,w3d_f32_80369d10[0]));
}
int w3d_ai_test_range_b_8000d0b4(S6CallbackPlan *plan) {
    int result=w3d_fn_8000a6ec(plan,w3d_f32_80369d28[0]);
    if (w3d_fn_8001b734(&plan->result)>w3d_ai_tuning_804aa6d8->values[83]) result=0;
    return w3d_fn_8000b6bc(plan,result);
}
int w3d_ai_test_range_c_8000d120(S6CallbackPlan *plan) {
    return w3d_fn_8000a6ec(plan,w3d_f32_80369d44[0]);
}
int w3d_ai_test_raised_origin_8000d1dc(S6CallbackPlan *plan) {
    plan->origin.y+=w3d_ai_tuning_804aa6d8->values[8];
    return w3d_fn_8000b6bc(plan,w3d_fn_8000a758(plan));
}
void w3d_ai_test_range_d_8000d2c8(S6CallbackPlan *plan) {
    w3d_fn_8000b6bc(plan,w3d_fn_8000a6ec(plan,w3d_f32_80369dec[0]));
    plan->result_cost=w3d_f32_80369df0[0];
}
int w3d_ai_test_range_e_8000d328(S6CallbackPlan *plan) {
    return w3d_fn_8000b6bc(plan,w3d_fn_8000a6ec(plan,w3d_f32_80369e3c[0]));
}
#if 0 /* Not exact: register allocation or instruction scheduling differs. */
void w3d_ai_score_named_attack_8000d568(S6CallbackPlan *plan) {
    w3d_auto_8000b2f8(plan,0);
    w3d_cached_name_lookup_80341710(plan,1);
    S6CallbackEntry *entry=w3d_ai_entries_804aa750->begin[plan->index];
    plan->cost=entry->cost*w3d_ai_tuning_804aa6d8->values[24]+plan->cost;
    plan->cost=plan->cost*w3d_ai_tuning_804aa6d8->values[107]*plan->weight;
}
#endif
float w3d_ai_named_damage_8000d99c(S6CallbackPlan *plan) {
    S6WeaponProperties *props=w3d_cached_name_lookup_80341710(plan,0);
    float damage=props->damage_b;
    if (!props->special) damage*=(float)props->count;
    return w3d_fn_8000af90(plan,damage);
}
float w3d_ai_named_range_8000da0c(S6CallbackPlan *plan) {
    return w3d_cached_name_lookup_80341710(plan,0)->range;
}
float w3d_ai_named_scaled_count_8000da34(S6CallbackPlan *plan) {
    S6WeaponProperties *props=w3d_cached_name_lookup_80341710(plan,0);
    return props->damage_scale*(float)props->count;
}
#if 0 /* Not exact: register allocation or instruction scheduling differs. */
void w3d_ai_score_named_damage_8000da8c(S6CallbackPlan *plan) {
    w3d_auto_8000b2f8(plan,0);
    float damage=w3d_ai_named_damage_8000d99c(plan);
    float range=w3d_ai_named_range_8000da0c(plan);
    plan->cost+=w3d_fn_8000b4c4(plan,range,w3d_ai_tuning_804aa6d8->values[23],w3d_f32_80369eb8[0],damage);
    float count=w3d_ai_named_scaled_count_8000da34(plan);
    plan->cost+=w3d_fn_8000b5f4(plan,count);
    if (w3d_cached_name_lookup_80341710(plan,0)->special) {
        plan->cost*=w3d_ai_tuning_804aa6d8->values[20];
        if (plan->special()) plan->cost*=w3d_ai_tuning_804aa6d8->values[119];
    }
    w3d_fn_8000b7dc(plan);
    plan->cost=plan->cost*w3d_ai_tuning_804aa6d8->values[107]*plan->weight;
}
#endif
void w3d_ai_execute_named_attack_8000dbd4(S6CallbackPlan *plan) {
    int special=w3d_cached_name_lookup_80341710(plan,0)->special;
    if (special && w3d_ai_mode_804aa588!=1) {
        struct S6HeldQueue { int unknown; void *queue; };
        S6HeldQueue *held=(S6HeldQueue *)((char *)plan+80);
        if (held->queue) { w3d_move_queue_release(held->queue); held->queue=0; }
    }
    plan->vtable->execute(plan);
    if (special && w3d_ai_mode_804aa588!=1) {
        if (!w3d_fn_800157cc()) w3d_command_create_7();
        w3d_ai_select_weapon((int)plan->actor);
    }
}
void w3d_ai_execute_fixed_a_8000dc78(S6CallbackPlan *plan) {
    w3d_fn_8000affc(plan,1,w3d_ai_tuning_804aa6d8->values[14]);
}
void w3d_ai_execute_fixed_b_8000dcbc(S6CallbackPlan *plan) {
    w3d_fn_8000affc(plan,1,w3d_ai_tuning_804aa6d8->values[13]);
}
}

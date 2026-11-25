extern "C" {
struct S6WeaponVec { float x,y,z; };
struct S6WeaponPlan { int kind; float cost; int active; void *vtable; int index; void *actor; S6WeaponVec origin,result,target; float result_cost; unsigned char flag,amount; char unknown_42[34]; float weight; };
struct S6WeaponTuning { float values[120]; };
struct S6WeaponProps { char unknown[200]; float damage; int unknown_cc; float damage_208; char unknown_d4[40]; float range; int unknown_100; float radius; };
struct S6ScoreEntry { int unknown[2]; void *actor; };
struct S6ScoreEntries { S6ScoreEntry **begin; };
extern S6WeaponTuning *w3d_ai_tuning_804aa6d8;
extern S6ScoreEntries *w3d_ai_entries_804aa750;
extern S6WeaponVec w3d_vector_8045e788[];
extern const float w3d_f32_80369f14[],w3d_f32_80369f18[],w3d_f32_80369fcc[],w3d_f32_80369fd0[],w3d_f32_8036a054[],w3d_f32_8036a0c0[],w3d_f32_8036a0c4[],w3d_f32_8036a0c8[],w3d_f32_8036a120[],w3d_f32_8036a124[],w3d_f32_8036a128[],w3d_f32_8036a144[],w3d_f32_8036a174[];
extern const char w3d_str_80369f44[],w3d_str_80369f58[];
void w3d_auto_8000b2f8(S6WeaponPlan *,int);
S6WeaponProps *w3d_cached_name_lookup_80341694(S6WeaponPlan *,int);
S6WeaponProps *w3d_cached_name_lookup_8034178c(S6WeaponPlan *,int);
float w3d_fn_8000af90(S6WeaponPlan *,float);
float w3d_fn_8000b4c4(S6WeaponPlan *,float,float,float,float);
float w3d_fn_8000b5f4(S6WeaponPlan *,float);
float w3d_fn_8000b344(S6WeaponPlan *,int,float,float);
void w3d_fn_8000b7dc(S6WeaponPlan *);
void w3d_fn_8000a280(S6WeaponPlan *);
int w3d_fn_8000f804(S6WeaponPlan *,float);
int w3d_fn_8000b6bc(S6WeaponPlan *,int);
void w3d_fn_8000affc(S6WeaponPlan *,int,float);
void w3d_fn_800fc270(const char **,float *);
void w3d_fn_800fc230(const char **,unsigned int *);
void w3d_fn_80015910(S6WeaponVec *,float);
int w3d_auto_800155ac(void *);
void w3d_ai_score_area_attack_8000dd04(S6WeaponPlan *plan) {
    w3d_auto_8000b2f8(plan,0);
    plan->cost+=w3d_fn_8000b4c4(plan,w3d_f32_80369f14[0],w3d_ai_tuning_804aa6d8->values[23],w3d_ai_tuning_804aa6d8->values[22],w3d_f32_80369f18[0]);
    plan->cost=plan->cost*w3d_ai_tuning_804aa6d8->values[106]*plan->weight;
}
float w3d_ai_bomber_damage_8000e058(S6WeaponPlan *plan) {
    return w3d_fn_8000af90(plan,w3d_cached_name_lookup_80341694(plan,0)->damage);
}
float w3d_ai_bomber_radius_8000e094(S6WeaponPlan *plan) {
    return w3d_cached_name_lookup_80341694(plan,0)->radius;
}
float w3d_ai_bomber_range_8000e0bc(S6WeaponPlan *plan) {
    return w3d_cached_name_lookup_80341694(plan,0)->range;
}
#if 0 /* Not exact: register allocation or instruction scheduling differs. */
void w3d_ai_score_bomber_8000e0ec(S6WeaponPlan *plan) {
    w3d_auto_8000b2f8(plan,0);
    float damage=w3d_ai_bomber_damage_8000e058(plan);
    const char *speed_name=w3d_str_80369f44;
    float speed;
    w3d_fn_800fc270(&speed_name,&speed);
    const char *duration_name=w3d_str_80369f58;
    unsigned int duration;
    w3d_fn_800fc230(&duration_name,&duration);
    float radius=w3d_ai_bomber_radius_8000e094(plan);
    float reach=speed*(float)duration+(radius+radius);
    plan->cost+=w3d_fn_8000b4c4(plan,reach,w3d_ai_tuning_804aa6d8->values[23],w3d_ai_tuning_804aa6d8->values[22],damage);
    plan->cost+=w3d_fn_8000b5f4(plan,w3d_ai_bomber_range_8000e0bc(plan));
    w3d_fn_8000b7dc(plan);
    plan->cost=plan->cost*w3d_ai_tuning_804aa6d8->values[106]*plan->weight;
}
#endif
#if 0 /* Not exact: register allocation or instruction scheduling differs. */
void w3d_ai_execute_offset_8000e9bc(S6WeaponPlan *plan) {
    float zero=w3d_f32_80369fcc[0];
    S6WeaponVec direction; direction.x=zero; direction.y=zero; direction.z=zero;
    w3d_fn_80015910(&direction,zero);
    S6WeaponVec origin; origin.x=zero; origin.y=zero; origin.z=zero;
    direction.x-=origin.x; direction.y-=origin.y; direction.z-=origin.z;
    S6WeaponVec offset;
    float scale=w3d_ai_tuning_804aa6d8->values[39];
    offset.x=direction.x*scale; offset.y=direction.y*scale; offset.z=direction.z*scale;
    origin=offset;
    plan->origin.x+=origin.x; plan->origin.y+=origin.y; plan->origin.z+=origin.z;
    plan->result=w3d_vector_8045e788[0];
    w3d_fn_8000affc(plan,1,w3d_f32_80369fd0[0]);
}
#endif
void w3d_ai_score_weapon_base_8000eb64(S6WeaponPlan *plan) {
    w3d_cached_name_lookup_80341694(plan,1);
    w3d_cached_name_lookup_8034178c(plan,1);
    w3d_auto_8000b2f8(plan,1);
    w3d_fn_8000a280(plan);
    plan->cost*=w3d_ai_tuning_804aa6d8->values[105];
    if (plan->flag) plan->cost*=w3d_f32_8036a054[0];
}
float w3d_ai_projectile_damage_800102fc(S6WeaponPlan *plan) {
    return w3d_fn_8000af90(plan,w3d_cached_name_lookup_8034178c(plan,0)->damage_208);
}
void w3d_ai_score_projectile_80010338(S6WeaponPlan *plan) {
    w3d_auto_8000b2f8(plan,1);
    float damage=w3d_ai_projectile_damage_800102fc(plan);
    plan->cost+=w3d_fn_8000b344(plan,plan->index,w3d_ai_tuning_804aa6d8->values[22],damage);
    w3d_fn_8000b7dc(plan);
    plan->cost*=w3d_ai_tuning_804aa6d8->values[105];
    if (plan->flag) plan->cost*=w3d_f32_8036a0c0[0];
}
int w3d_ai_test_projectile_a_800103d4(S6WeaponPlan *plan) {
    return w3d_fn_8000b6bc(plan,w3d_fn_8000f804(plan,w3d_f32_8036a0c4[0]));
}
void w3d_ai_execute_projectile_80010414(S6WeaponPlan *plan) {
    w3d_fn_8000affc(plan,1,w3d_f32_8036a0c8[0]);
}
#if 0 /* Not exact: register allocation or instruction scheduling differs. */
void w3d_ai_score_half_health_80010464(S6WeaponPlan *plan) {
    w3d_auto_8000b2f8(plan,1);
    int index=plan->index;
    int health=w3d_auto_800155ac(w3d_ai_entries_804aa750->begin[index]->actor)/2;
    plan->cost+=w3d_fn_8000b344(plan,index,w3d_f32_8036a120[0],(float)health);
    w3d_fn_8000b7dc(plan);
    plan->cost*=w3d_ai_tuning_804aa6d8->values[105];
    if (plan->flag) plan->cost*=w3d_f32_8036a124[0];
}
#endif
int w3d_ai_test_projectile_b_80010538(S6WeaponPlan *plan) {
    return w3d_fn_8000b6bc(plan,w3d_fn_8000f804(plan,w3d_f32_8036a128[0]));
}
int w3d_ai_test_projectile_c_80010584(S6WeaponPlan *plan) {
    return w3d_fn_8000b6bc(plan,w3d_fn_8000f804(plan,w3d_f32_8036a144[0]));
}
float w3d_ai_splash_damage_800105cc(S6WeaponPlan *plan) {
    return w3d_fn_8000af90(plan,w3d_cached_name_lookup_80341694(plan,0)->damage);
}
float w3d_ai_splash_radius_80010608(S6WeaponPlan *plan) {
    return w3d_cached_name_lookup_80341694(plan,0)->radius;
}
#if 0 /* Not exact: register allocation or instruction scheduling differs. */
void w3d_ai_score_splash_80010630(S6WeaponPlan *plan) {
    w3d_auto_8000b2f8(plan,1);
    float damage=w3d_ai_splash_damage_800105cc(plan);
    float radius=w3d_ai_splash_radius_80010608(plan);
    plan->cost+=w3d_fn_8000b4c4(plan,radius,w3d_ai_tuning_804aa6d8->values[23],w3d_ai_tuning_804aa6d8->values[22],damage);
    w3d_fn_8000b7dc(plan);
    plan->cost*=w3d_ai_tuning_804aa6d8->values[105];
    if (plan->flag) plan->cost*=w3d_f32_8036a174[0];
}
#endif
}

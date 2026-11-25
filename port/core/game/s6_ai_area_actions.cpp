#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s6_ai_area_actions.c"
/* Area-effect AI scoring and execution callbacks. */
typedef struct { int kind; float score; int active; Ptr32<void> vtable; int index,weapon; } W3dS6AreaPlan;
typedef struct { unsigned char unknown00[200]; float damage; unsigned char unknowncc[52]; unsigned int count; } W3dS6AreaWeapon;
typedef struct { unsigned char unknown00[8]; int team; unsigned char unknown0c[16]; int damage; } W3dS6AreaActor;
typedef struct { Ptr32<Ptr32<W3dS6AreaActor>> begin; Ptr32<Ptr32<W3dS6AreaActor>> end; } W3dS6AreaActors;
extern Ptr32<W3dS6AreaActors> w3d_ai_entries_804aa750;
extern int w3d_s6_team_804aa6c0;
Ptr32<W3dS6AreaWeapon> w3d_cached_name_lookup_80341694(Ptr32<W3dS6AreaPlan>,int);
float w3d_ai_splash_damage_800105cc(Ptr32<W3dS6AreaPlan>);
float w3d_ai_splash_radius_80010608(Ptr32<W3dS6AreaPlan>);
void w3d_ai_score_death_damage_80011950(Ptr32<W3dS6AreaPlan>,float,float);
void w3d_auto_8000b2f8(Ptr32<W3dS6AreaPlan>,int);
int w3d_fn_8000b6bc(Ptr32<W3dS6AreaPlan>,int);
int w3d_fn_800106e0(Ptr32<W3dS6AreaPlan>,float);
void w3d_fn_8000affc(Ptr32<W3dS6AreaPlan>,int,float);
float w3d_fn_8000b344(Ptr32<W3dS6AreaPlan>,int,float,float);
extern const float w3d_f32_8036a3e0[],w3d_f32_8036a408[],w3d_f32_8036a40c[],w3d_f32_8036a410[];
extern const float w3d_f32_8036a430[],w3d_f32_8036a434[],w3d_f32_8036a438[],w3d_f32_8036a45c[],w3d_f32_8036a468[];
#if 0 /* Eight-byte stack-frame gap remains. */
void w3d_ai_score_cluster_bomb_80011a70(W3dS6AreaPlan *plan) {
    float damage,radius;
    W3dS6AreaWeapon *bomb=w3d_cached_name_lookup_80341694(plan,0),*cluster;
    plan->weapon=36;
    cluster=w3d_cached_name_lookup_80341694(plan,0);
    plan->weapon=2;
    damage=w3d_ai_splash_damage_800105cc(plan);
    damage=(float)bomb->count*cluster->damage+damage;
    radius=w3d_ai_splash_radius_80010608(plan);
    w3d_ai_score_death_damage_80011950(plan,damage,radius);
}
#endif
#if 0 /* Eight-byte stack-frame gap remains. */
void w3d_ai_score_cluster_alt_80011c58(W3dS6AreaPlan *plan) {
    float damage,radius;
    W3dS6AreaWeapon *bomb=w3d_cached_name_lookup_80341694(plan,0),*cluster;
    plan->weapon=37;
    cluster=w3d_cached_name_lookup_80341694(plan,0);
    plan->weapon=6;
    damage=w3d_ai_splash_damage_800105cc(plan);
    damage=(float)bomb->count*cluster->damage+damage;
    radius=w3d_ai_splash_radius_80010608(plan);
    w3d_ai_score_death_damage_80011950(plan,damage,radius);
}
#endif
void w3d_ai_push_area_trajectory_80011d00(Ptr32<W3dS6AreaPlan> plan) {
    w3d_fn_8000b6bc(plan,w3d_fn_800106e0(plan,*w3d_f32_8036a3e0));
}
#if 0 /* One indexed-load operand-order difference remains. */
void w3d_ai_score_all_actors_80011f30(W3dS6AreaPlan *plan) {
    int i=0,count;
    w3d_auto_8000b2f8(plan,0);
    count=w3d_ai_entries_804aa750->end-w3d_ai_entries_804aa750->begin;
    for(;i<count;i++) {
        if(w3d_ai_entries_804aa750->begin[i]->team!=-1)
            plan->score+=w3d_fn_8000b344(plan,i,*w3d_f32_8036a408,*w3d_f32_8036a40c);
    }
}
#endif
void w3d_ai_execute_all_actors_80011fd4(Ptr32<W3dS6AreaPlan> plan) {
    w3d_fn_8000affc(plan,1,*w3d_f32_8036a410);
}
#if 0 /* One indexed-load operand-order difference remains. */
void w3d_ai_score_other_teams_80012018(W3dS6AreaPlan *plan) {
    int i=0,count;
    w3d_auto_8000b2f8(plan,0);
    count=w3d_ai_entries_804aa750->end-w3d_ai_entries_804aa750->begin;
    for(;i<count;i++) {
        int team=w3d_ai_entries_804aa750->begin[i]->team;
        if(team!=-1 && team!=w3d_s6_team_804aa6c0)
            plan->score+=w3d_fn_8000b344(plan,i,*w3d_f32_8036a430,*w3d_f32_8036a434);
    }
}
#endif
void w3d_ai_execute_other_teams_800120c8(Ptr32<W3dS6AreaPlan> plan) {
    w3d_fn_8000affc(plan,1,*w3d_f32_8036a438);
}
#if 0 /* Stack layout, indexed loads and loop register allocation differ. */
void w3d_ai_score_average_damage_8001210c(W3dS6AreaPlan *plan) {
    int i,count,active=0,average;
    float sum;
    w3d_auto_8000b2f8(plan,0);
    count=w3d_ai_entries_804aa750->end-w3d_ai_entries_804aa750->begin;
    sum=*w3d_f32_8036a45c;
    for(i=0;i<count;i++) {
        W3dS6AreaActor *actor=w3d_ai_entries_804aa750->begin[i];
        if(actor->team!=-1) { active++;sum+=(float)actor->damage; }
    }
    average=(int)(sum/(float)active);
    for(i=0;i<count;i++) {
        W3dS6AreaActor *actor=w3d_ai_entries_804aa750->begin[i];
        if(actor->team!=-1) plan->score+=w3d_fn_8000b344(plan,i,*w3d_f32_8036a45c,(float)(actor->damage-average));
    }
}
#endif
void w3d_ai_execute_average_damage_80012278(Ptr32<W3dS6AreaPlan> plan) {
    w3d_fn_8000affc(plan,1,*w3d_f32_8036a468);
}

}

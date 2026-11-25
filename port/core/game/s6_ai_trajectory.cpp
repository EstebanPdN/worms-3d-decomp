#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s6_ai_trajectory.c"
/* AI trajectory callbacks. Names and field meanings are inferred. */
typedef struct { float x,y,z; } W3dS6Vector;
typedef struct {
    int unknown00; float score; unsigned char unknown08[28];
    W3dS6Vector direction; unsigned char unknown30[12]; float time;
    unsigned char unknown40[36]; float factor;
} W3dS6Plan;
typedef struct { unsigned char unknown00[184]; float range, radius; unsigned char unknownc0[8]; float damage; unsigned char unknowncc[48]; float distance; unsigned char unknown100[4]; float power; } W3dS6Weapon;
typedef struct { unsigned char unknown00[88]; float a,b; unsigned char unknown60[300]; float factor; } W3dS6Settings;
extern Ptr32<W3dS6Settings> w3d_s6_settings_804aa6d8;
extern const float w3d_f32_8036a178[],w3d_f32_8036a17c[],w3d_f32_8036a180[],w3d_f32_8036a184[];
extern const float w3d_f32_8036a188[],w3d_f32_8036a18c[],w3d_f32_8036a1dc[],w3d_f32_8036a284[],w3d_f32_8036a288[];
int w3d_fn_8000f804(Ptr32<W3dS6Plan>);
int w3d_fn_8000feb8(Ptr32<W3dS6Plan>,float);
float w3d_fn_802e82c0(float);
Ptr32<W3dS6Weapon> w3d_cached_name_lookup_80341694(Ptr32<W3dS6Plan>,int);
Ptr32<void> w3d_cached_name_lookup_80341808(Ptr32<W3dS6Plan>,int);
int w3d_fn_8000b6bc(Ptr32<W3dS6Plan>,int);
void w3d_fn_8000affc(Ptr32<W3dS6Plan>,int,float);
void w3d_auto_8000b2f8(Ptr32<W3dS6Plan>,int);
float w3d_fn_8000b4c4(Ptr32<W3dS6Plan>,float,float,float,float);

#if 0 /* Aggregate copies and scalar preservation differ from the original. */
int w3d_ai_scale_trajectory_800106e0(W3dS6Plan *plan,float time)
{
    W3dS6Vector scaled,copy;
    float radius,inv;
    W3dS6Weapon *weapon;
    W3dS6Vector *direction;
    int result=0;
    if(w3d_fn_8000f804(plan)) {
        weapon=w3d_cached_name_lookup_80341694(plan,0);
        radius=weapon->radius;
        if(radius==*w3d_f32_8036a178) radius=weapon->range * *w3d_f32_8036a17c;
        direction=&plan->direction;
        inv=*w3d_f32_8036a180/w3d_fn_802e82c0(direction->z*direction->z+(direction->x*direction->x+direction->y*direction->y));
        direction->x*=inv; direction->y*=inv; direction->z*=inv;
        scaled.x=direction->x*radius; scaled.y=direction->y*radius; scaled.z=direction->z*radius;
        copy=scaled;
        *direction=copy;
        result=w3d_fn_8000feb8(plan,time+*w3d_f32_8036a184);
    }
    return result;
}
#endif
int w3d_ai_scale_trajectory_800106e0(Ptr32<W3dS6Plan>,float);
void w3d_ai_push_scaled_trajectory_8001080c(Ptr32<W3dS6Plan> plan) {
    w3d_fn_8000b6bc(plan,w3d_ai_scale_trajectory_800106e0(plan,*w3d_f32_8036a188));
}
void w3d_ai_execute_trajectory_8001084c(Ptr32<W3dS6Plan> plan) {
    w3d_fn_8000affc(plan,1,*w3d_f32_8036a18c);
}
void w3d_ai_reset_trajectory_time_800108b8(Ptr32<W3dS6Plan> plan) {
    plan->time=*w3d_f32_8036a1dc;
    w3d_ai_execute_trajectory_8001084c(plan);
}
void w3d_ai_score_trajectory_80010920(Ptr32<W3dS6Plan> plan) {
    float score;
    w3d_cached_name_lookup_80341694(plan,1);
    w3d_cached_name_lookup_80341808(plan,1);
    w3d_auto_8000b2f8(plan,0);
    score=plan->score+w3d_fn_8000b4c4(plan,*w3d_f32_8036a284,w3d_s6_settings_804aa6d8->b,w3d_s6_settings_804aa6d8->a,*w3d_f32_8036a288);
    plan->score=score;
    plan->score=score*w3d_s6_settings_804aa6d8->factor*plan->factor;
}

extern const float w3d_f32_8036a2b0[],w3d_f32_8036a2c8[],w3d_f32_8036a2e4[],w3d_f32_8036a2fc[],w3d_f32_8036a328[];
float w3d_fn_8000af90(Ptr32<W3dS6Plan>,float);
float w3d_fn_8000b5f4(Ptr32<W3dS6Plan>,float);
void w3d_ai_scale_exposure_8000b7dc(Ptr32<W3dS6Plan>);
int w3d_fn_8000aa9c(Ptr32<W3dS6Plan>,int,float,float);
float w3d_ai_weapon_damage_80010f60(Ptr32<W3dS6Plan> plan);
float w3d_ai_weapon_power_80010f9c(Ptr32<W3dS6Plan> plan);
float w3d_ai_weapon_distance_80010fc4(Ptr32<W3dS6Plan> plan);
#if 0 /* All instructions match except an eight-byte stack-frame gap. */
void w3d_ai_score_weapon_80010e74(W3dS6Plan *plan) {
    struct {float damage,power;} values;
    w3d_auto_8000b2f8(plan,0);
    values.damage=w3d_ai_weapon_damage_80010f60(plan);
    values.power=w3d_ai_weapon_power_80010f9c(plan);
    plan->score+=w3d_fn_8000b4c4(plan,values.power,w3d_s6_settings_804aa6d8->b,w3d_s6_settings_804aa6d8->a,values.damage);
    plan->score+=w3d_fn_8000b5f4(plan,w3d_ai_weapon_distance_80010fc4(plan));
    w3d_ai_scale_exposure_8000b7dc(plan);
    plan->score=plan->score*w3d_s6_settings_804aa6d8->factor*plan->factor;
}
#endif
void w3d_ai_execute_weapon_80010f34(Ptr32<W3dS6Plan> plan) {
    w3d_fn_8000affc(plan,1,*w3d_f32_8036a2b0);
}
float w3d_ai_weapon_damage_80010f60(Ptr32<W3dS6Plan> plan) {
    return w3d_fn_8000af90(plan,w3d_cached_name_lookup_80341694(plan,0)->damage);
}
float w3d_ai_weapon_power_80010f9c(Ptr32<W3dS6Plan> plan) {
    return w3d_cached_name_lookup_80341694(plan,0)->power;
}
float w3d_ai_weapon_distance_80010fc4(Ptr32<W3dS6Plan> plan) {
    return w3d_cached_name_lookup_80341694(plan,0)->distance;
}
void w3d_ai_query_sheep_80010ff8(Ptr32<W3dS6Plan> plan) {
    typedef struct { unsigned char unknown00[560]; float speed; unsigned char unknown234[12]; float distance; } Sheep;
    Ptr32<Sheep> sheep=w3d_cached_name_lookup_80341808(plan,0);
    w3d_fn_8000aa9c(plan,0,sheep->speed * *w3d_f32_8036a2c8,sheep->distance);
}
void w3d_ai_query_radius_80011058(Ptr32<W3dS6Plan> plan) {
    Ptr32<W3dS6Weapon> weapon=w3d_cached_name_lookup_80341694(plan,0);
    w3d_fn_8000aa9c(plan,0,*w3d_f32_8036a2e4,weapon->radius);
}
void w3d_ai_query_radius_alt_800110ac(Ptr32<W3dS6Plan> plan) {
    Ptr32<W3dS6Weapon> weapon=w3d_cached_name_lookup_80341694(plan,0);
    w3d_fn_8000aa9c(plan,1,*w3d_f32_8036a2fc,weapon->radius);
}
Ptr32<void> w3d_auto_8001523c(unsigned);
Ptr32<void> w3d_move_queue_construct(Ptr32<void>);
void w3d_fn_80003558(Ptr32<void>,Ptr32<void>,int,Ptr32<void>);
void w3d_fn_80009984(Ptr32<Ptr32<void>>,int);
void w3d_ai_execute_sheep_80011344(Ptr32<W3dS6Plan> plan) {
    Ptr32<void> queue;
    w3d_fn_8000affc(plan,1,*w3d_f32_8036a328);
    queue=w3d_move_queue_construct(w3d_auto_8001523c(48));
    w3d_fn_80003558(queue,(Ptr32<char>)plan+24,11,(Ptr32<char>)plan+104);
    w3d_fn_80009984(&queue,0);
}

}

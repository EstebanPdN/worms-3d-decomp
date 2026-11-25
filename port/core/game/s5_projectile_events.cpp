#include "w3d_ptr.h"
#line 1 "s5_projectile_events.cpp"
/* Projectile ticking, ground placement, handle bounds and one-shot effects. */
extern "C" {
struct S5EventVec { float x,y,z; };
struct S5EventIface;
struct S5EventVtable { Ptr32<void (void)> reserved[4]; Ptr32<void (Ptr32<S5EventIface>)> release; };
struct S5EventIface { Ptr32<S5EventVtable> vtable; };
struct S5EventHandle { unsigned unknown[2]; };
struct S5EventActor { unsigned char reserved[28]; S5EventVec position; unsigned char reserved40[24]; S5EventHandle handle; unsigned char reserved72[16]; int phase,moving,bouncing,owner,slot; unsigned char reserved108[12]; int active,effect; unsigned started; Ptr32<S5EventIface> resource; };
extern S5EventVec w3d_zero_vector_8045e788[],w3d_trace_position_8043ae20[];
extern const float w3d_f32_80388e4c[],w3d_f32_80388e50[],w3d_f32_80388e54[],w3d_f32_80388f7c[];
extern const char w3d_str_80388f68[];
extern int w3d_trace_owner_804b17ac,w3d_trace_slot_804b17a8,w3d_event_state_804b17a0;
extern Ptr32<void> w3d_message_pool_804b1754;
int w3d_scene_timer_is_one_8006e71c(void);
void w3d_projectile_move_800d610c(Ptr32<S5EventActor>);
void w3d_projectile_bounce_800d6350(Ptr32<S5EventActor>);
void w3d_projectile_activate_800d65ec(Ptr32<S5EventActor>);
void w3d_projectile_effect_800d673c(Ptr32<S5EventActor>);
void w3d_auto_8015fd1c(Ptr32<void>);
void w3d_trace_800b0824(Ptr32<S5EventVec>,Ptr32<S5EventVec>,Ptr32<S5EventVec>,int,int);
void w3d_actor_handle_member_set_bounds(Ptr32<S5EventHandle>,Ptr32<S5EventVec>,float);
int w3d_effect_800e5ca4(Ptr32<S5EventVec>,Ptr32<const char>,float,int);
Ptr32<void> w3d_message_allocate_801613f0(Ptr32<void>,unsigned);
Ptr32<void> w3d_owner_slot_message_8003a264(Ptr32<void>,int,int);
int w3d_message_post_current(Ptr32<void>);
static inline void s5_event_set(Ptr32<S5EventVec> out,float x,float y,float z) { out->x=x;out->y=y;out->z=z; }
static inline void s5_event_copy(Ptr32<S5EventVec> out,Ptr32<const S5EventVec> source) { s5_event_set(out,source->x,source->y,source->z); }
int w3d_projectile_tick_800d5c68(Ptr32<S5EventActor> actor,unsigned now)
{
    if(!w3d_scene_timer_is_one_8006e71c()) {
        if(actor->moving) w3d_projectile_move_800d610c(actor);
        else if(actor->bouncing) w3d_projectile_bounce_800d6350(actor);
        if(actor->active && now>actor->started+50) {
            if(!actor->phase) w3d_projectile_activate_800d65ec(actor);
            else if(now>actor->started+100) {
                w3d_projectile_effect_800d673c(actor);
                if(actor->resource) actor->resource->vtable->release(actor->resource);
                actor->resource=0;
                w3d_auto_8015fd1c(actor);
            }
        }
    }
    return 20;
}
void w3d_projectile_update_bounds_800d60ac(Ptr32<S5EventActor> actor)
{
    S5EventVec point;
    s5_event_copy(&point,&actor->position);
    float radius=*w3d_f32_80388e54;
    point.y+=radius;
    w3d_actor_handle_member_set_bounds(&actor->handle,&point,radius);
}
void w3d_projectile_place_ground_800d5ff0(Ptr32<S5EventActor> actor)
{
    S5EventVec direction,hit;
    s5_event_set(&direction,*w3d_f32_80388e4c,*w3d_f32_80388e50,*w3d_f32_80388e4c);
    s5_event_copy(&hit,w3d_zero_vector_8045e788);
    w3d_trace_800b0824(&actor->position,&direction,&hit,1000,1);
    actor->position=*w3d_trace_position_8043ae20;
    actor->owner=w3d_trace_owner_804b17ac;
    actor->slot=w3d_trace_slot_804b17a8;
    w3d_projectile_update_bounds_800d60ac(actor);
}
void w3d_projectile_effect_800d673c(Ptr32<S5EventActor> actor)
{
    if(!actor->effect) {
        actor->effect=1;
        w3d_effect_800e5ca4(&actor->position,w3d_str_80388f68,0.0f,0);
    }
}
int w3d_projectile_post_owner_slot_800d6788(Ptr32<S5EventActor> actor)
{
    Ptr32<void> message=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_owner_slot_message_8003a264(message,actor->slot,actor->owner));
    return !w3d_event_state_804b17a0;
}
}



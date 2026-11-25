#include "w3d_ptr.h"
#line 1 "s5_projectile_state.cpp"
/* Projectile actor defaults and owned interface destruction. */
extern "C" {
struct S5ProjectileIface;
struct S5ProjectileVtable { Ptr32<void (void)> reserved[4]; Ptr32<void (Ptr32<S5ProjectileIface>)> release; };
struct S5ProjectileIface { Ptr32<S5ProjectileVtable> vtable; };
struct S5ProjectileVec { float x,y,z; };
struct S5ProjectileHandle { unsigned unknown[2]; };
struct S5Projectile { Ptr32<void> vtable; unsigned char reserved[24]; S5ProjectileVec bounds,velocity,acceleration; S5ProjectileHandle handle; Ptr32<S5ProjectileIface> held72; Ptr32<S5ProjectileIface> held76; Ptr32<S5ProjectileIface> held80; Ptr32<S5ProjectileIface> held84; int state88,state92,state96,state100,state104; Ptr32<S5ProjectileIface> held108; Ptr32<S5ProjectileIface> held112; Ptr32<S5ProjectileIface> held116; int state120,state124,state128; Ptr32<S5ProjectileIface> held132; float first,second; };
extern unsigned char w3d_projectile_vtable_8040fd08[];
extern S5ProjectileVec w3d_zero_vector_8045e788[];
extern const float w3d_f32_80388e18[],w3d_f32_80388e1c[];
int w3d_actor_base_initialize(Ptr32<void>);
void w3d_actor_base_destroy(Ptr32<void>,int);
Ptr32<void> w3d_actor_handle_member_initialize(Ptr32<S5ProjectileHandle>);
void w3d_actor_handle_member_destroy(Ptr32<S5ProjectileHandle>,int);
void w3d_actor_handle_member_set_word(Ptr32<S5ProjectileHandle>,int);
void w3d_actor_handle_member_set_slot_word(Ptr32<S5ProjectileHandle>,int);
void w3d_actor_handle_member_set_bounds(Ptr32<S5ProjectileHandle>,Ptr32<S5ProjectileVec>,float);
Ptr32<S5Projectile> w3d_projectile_init_800d58ec(Ptr32<S5Projectile> actor)
{
    w3d_actor_base_initialize(actor);
    actor->vtable=w3d_projectile_vtable_8040fd08;
    w3d_actor_handle_member_initialize(&actor->handle);
    actor->held72=0;actor->held76=0;actor->held80=0;actor->held84=0;
    actor->held108=0;actor->held112=0;actor->held116=0;actor->held132=0;
    w3d_actor_handle_member_set_word(&actor->handle,25);
    w3d_actor_handle_member_set_slot_word(&actor->handle,16);
    w3d_actor_handle_member_set_bounds(&actor->handle,&actor->bounds,*w3d_f32_80388e18);
    actor->state88=0;actor->state120=0;actor->state124=0;actor->state96=0;actor->state92=0;actor->state104=0;actor->state100=0;
    actor->velocity=*w3d_zero_vector_8045e788;
    actor->acceleration=*w3d_zero_vector_8045e788;
    actor->state128=0;
    if(actor->held132) actor->held132->vtable->release(actor->held132);
    actor->held132=0;
    actor->second=actor->first=0.0f;
    return actor;
}
static inline void s5_projectile_release(Ptr32<S5ProjectileIface> value) { if(value) value->vtable->release(value); }
void w3d_projectile_destroy_800d5a14(Ptr32<S5Projectile> actor,int flags)
{
    actor->vtable=w3d_projectile_vtable_8040fd08;
    s5_projectile_release(actor->held132);
    s5_projectile_release(actor->held116);
    s5_projectile_release(actor->held112);
    s5_projectile_release(actor->held108);
    s5_projectile_release(actor->held84);
    s5_projectile_release(actor->held80);
    s5_projectile_release(actor->held76);
    s5_projectile_release(actor->held72);
    w3d_actor_handle_member_destroy(&actor->handle,2);
    w3d_actor_base_destroy(actor,flags);
}
}



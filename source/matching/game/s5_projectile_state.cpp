/* Projectile actor defaults and owned interface destruction. */
extern "C" {
struct S5ProjectileIface;
struct S5ProjectileVtable { void (*reserved[4])(); void (*release)(S5ProjectileIface *); };
struct S5ProjectileIface { S5ProjectileVtable *vtable; };
struct S5ProjectileVec { float x,y,z; };
struct S5ProjectileHandle { unsigned unknown[2]; };
struct S5Projectile { void *vtable; unsigned char reserved[24]; S5ProjectileVec bounds,velocity,acceleration; S5ProjectileHandle handle; S5ProjectileIface *held72,*held76,*held80,*held84; int state88,state92,state96,state100,state104; S5ProjectileIface *held108,*held112,*held116; int state120,state124,state128; S5ProjectileIface *held132; float first,second; };
extern unsigned char w3d_projectile_vtable_8040fd08[];
extern S5ProjectileVec w3d_zero_vector_8045e788[];
extern const float w3d_f32_80388e18[],w3d_f32_80388e1c[];
int w3d_actor_base_initialize(void *);
void w3d_actor_base_destroy(void *,int);
void * w3d_actor_handle_member_initialize(S5ProjectileHandle *);
void w3d_actor_handle_member_destroy(S5ProjectileHandle *,int);
void w3d_actor_handle_member_set_word(S5ProjectileHandle *,int);
void w3d_actor_handle_member_set_slot_word(S5ProjectileHandle *,int);
void w3d_actor_handle_member_set_bounds(S5ProjectileHandle *,S5ProjectileVec *,float);
S5Projectile *w3d_projectile_init_800d58ec(S5Projectile *actor)
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
static inline void s5_projectile_release(S5ProjectileIface *value) { if(value) value->vtable->release(value); }
void w3d_projectile_destroy_800d5a14(S5Projectile *actor,int flags)
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

#include "w3d_ptr.h"
#line 1 "s5_nuclear_state.cpp"
/* Nuclear utility lifecycle, pending-handle release and activation timing. */
extern "C" {
struct S5NuclearIface;
struct S5NuclearVtable { Ptr32<void (void)> reserved[4]; Ptr32<void (Ptr32<S5NuclearIface>)> release; };
struct S5NuclearIface { Ptr32<S5NuclearVtable> vtable; };
struct S5NuclearUtility { Ptr32<void> vtable; unsigned char reserved[56]; int active; Ptr32<S5NuclearIface> resource; Ptr32<S5NuclearIface> effect; unsigned deadline; int slot,value,flag; };
struct S5NuclearName { unsigned id; Ptr32<const char> text; };
struct S5NuclearMessage { unsigned short id,reserved; Ptr32<void> vtable; };
struct S5NuclearKey { Ptr32<const char> text; };
struct S5NuclearHandle { Ptr32<S5NuclearIface> pointer; unsigned reserved; S5NuclearHandle() { pointer=0; } ~S5NuclearHandle() { if(pointer) pointer->vtable->release(pointer); } };
struct S5NuclearContext { unsigned char reserved[52]; unsigned time; };
struct S5NuclearResource { unsigned char reserved[56]; unsigned delay; };
extern unsigned char w3d_nuclear_vtable_8040fc48[],w3d_message_vtable_8040db38[];
extern const char w3d_str_803887bc[];
extern Ptr32<S5NuclearUtility> w3d_nuclear_utility_804aae44;
extern S5NuclearName w3d_nuclear_name_804ae9cc,w3d_nuclear_name_804ae9d4;
extern Ptr32<void> w3d_message_pool_804b1754;
void w3d_nuclear_base_destroy_8002a978(Ptr32<void>,int);
void w3d_nuclear_base_detach_8002ae70(Ptr32<void>);
void w3d_nuclear_base_step_8002ad9c(Ptr32<void>);
void w3d_timer_set_800fde64(int);
int w3d_pool_release_800c56b8(int);
Ptr32<void> w3d_message_allocate_801613f0(Ptr32<void>,unsigned);
unsigned w3d_cached_message_id(Ptr32<S5NuclearName>,int);
Ptr32<void> w3d_int_message_init_80125fdc(Ptr32<void>,unsigned short,int);
int w3d_message_post_current(Ptr32<void>);
Ptr32<void> w3d_constructor_lookup_name(Ptr32<S5NuclearKey>,Ptr32<Ptr32<S5NuclearIface>>);
Ptr32<S5NuclearIface> w3d_empty_80341584(Ptr32<S5NuclearIface>);
Ptr32<S5NuclearResource> w3d_auto_801797b4(Ptr32<S5NuclearIface>);
Ptr32<S5NuclearContext> w3d_engine_get_context(void);
void w3d_nuclear_destroy_800d24e0(Ptr32<S5NuclearUtility> utility,int flags)
{
    utility->vtable=w3d_nuclear_vtable_8040fc48;
    if(utility->effect) utility->effect->vtable->release(utility->effect);
    if(utility->resource) utility->resource->vtable->release(utility->resource);
    w3d_nuclear_base_destroy_8002a978(utility,flags);
}
void w3d_nuclear_detach_800d2790(Ptr32<S5NuclearUtility> utility)
{
    Ptr32<S5NuclearIface> replacement=0;
    w3d_nuclear_utility_804aae44=0;
    if(utility->effect) utility->effect->vtable->release(utility->effect);
    utility->effect=replacement;
    if(utility->flag) { w3d_timer_set_800fde64(2500); utility->flag=0; }
    if(utility->slot) {
        Ptr32<void> message=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
        w3d_message_post_current(w3d_int_message_init_80125fdc(message,w3d_cached_message_id(&w3d_nuclear_name_804ae9cc,1),utility->value));
        w3d_pool_release_800c56b8(utility->slot);
        utility->slot=0;
    }
    w3d_nuclear_base_detach_8002ae70(utility);
}
void w3d_nuclear_step_800d2848(Ptr32<S5NuclearUtility> utility)
{
    if(!utility->active) {
        S5NuclearHandle handle;
        S5NuclearKey key; key.text=w3d_str_803887bc;
        w3d_constructor_lookup_name(&key,&handle.pointer);
        Ptr32<S5NuclearResource> resource=w3d_auto_801797b4(w3d_empty_80341584(handle.pointer));
        Ptr32<S5NuclearContext> context=w3d_engine_get_context();
        utility->deadline=context->time+resource->delay;
        Ptr32<S5NuclearMessage> message=(Ptr32<S5NuclearMessage>)w3d_message_allocate_801613f0(w3d_message_pool_804b1754,8);
        message->id=w3d_cached_message_id(&w3d_nuclear_name_804ae9d4,1);
        message->vtable=w3d_message_vtable_8040db38;
        w3d_message_post_current(message);
        w3d_nuclear_base_step_8002ad9c(utility);
        utility->active=1;
    }
    w3d_nuclear_base_step_8002ad9c(utility);
}
}



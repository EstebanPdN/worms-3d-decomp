#include "w3d_ptr.h"
#line 1 "s4_frontend_service.cpp"
extern "C" {
struct S4Object { Ptr32<Ptr32<void (void)>> vtable; };
struct S4FrontendService { Ptr32<void> vtable; unsigned char pad[24]; Ptr32<S4Object> handles[10]; };
struct S4Value { unsigned char pad[20]; unsigned int a,b,c,d; };
int w3d_ctor_801628b0(Ptr32<void>);
void w3d_service_destroy_801628ec(Ptr32<void>,int);
Ptr32<void> w3d_lookup_value_800fc330(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<S4Value>>);
void w3d_apply_value_801ea4c8(Ptr32<void>,Ptr32<S4Value>);
extern unsigned char w3d_vtable_8041c1f0[];
extern Ptr32<S4FrontendService> w3d_frontend_instance_804abbfc;
Ptr32<S4FrontendService> w3d_s4_frontend_service_construct(Ptr32<S4FrontendService> self)
{
    w3d_ctor_801628b0(self);
    self->vtable=w3d_vtable_8041c1f0;
    self->handles[0]=0;
    self->handles[1]=0;
    self->handles[2]=0;
    self->handles[3]=0;
    self->handles[4]=0;
    self->handles[5]=0;
    self->handles[6]=0;
    self->handles[7]=0;
    self->handles[8]=0;
    self->handles[9]=0;
    w3d_frontend_instance_804abbfc=self;
    return self;
}
void w3d_s4_frontend_service_destroy(Ptr32<S4FrontendService> self,int flags)
{
    self->vtable=w3d_vtable_8041c1f0;
    if(self->handles[9]) ((Ptr32<void (Ptr32<S4Object>)>)self->handles[9]->vtable[4])(self->handles[9]);
    if(self->handles[8]) ((Ptr32<void (Ptr32<S4Object>)>)self->handles[8]->vtable[4])(self->handles[8]);
    if(self->handles[7]) ((Ptr32<void (Ptr32<S4Object>)>)self->handles[7]->vtable[4])(self->handles[7]);
    if(self->handles[6]) ((Ptr32<void (Ptr32<S4Object>)>)self->handles[6]->vtable[4])(self->handles[6]);
    if(self->handles[5]) ((Ptr32<void (Ptr32<S4Object>)>)self->handles[5]->vtable[4])(self->handles[5]);
    if(self->handles[4]) ((Ptr32<void (Ptr32<S4Object>)>)self->handles[4]->vtable[4])(self->handles[4]);
    if(self->handles[3]) ((Ptr32<void (Ptr32<S4Object>)>)self->handles[3]->vtable[4])(self->handles[3]);
    if(self->handles[2]) ((Ptr32<void (Ptr32<S4Object>)>)self->handles[2]->vtable[4])(self->handles[2]);
    if(self->handles[1]) ((Ptr32<void (Ptr32<S4Object>)>)self->handles[1]->vtable[4])(self->handles[1]);
    if(self->handles[0]) ((Ptr32<void (Ptr32<S4Object>)>)self->handles[0]->vtable[4])(self->handles[0]);
    w3d_service_destroy_801628ec(self,flags);
}
// Deferred: two argument-setup words differ after two checks.
#if 0
void w3d_s4_frontend_apply_named_value(void *,void *destination,const char *name)
{
    S4Value *value;
    if(destination) {
        w3d_lookup_value_800fc330(&name,&value);
        w3d_apply_value_801ea4c8(destination,value);
    }
}
#endif
int w3d_s4_frontend_named_value_differs(Ptr32<void>,Ptr32<const char> name,Ptr32<S4Value> other)
{
    Ptr32<S4Value> value;
    if(!other) return 0;
    w3d_lookup_value_800fc330(&name,&value);
    if(value->d==other->d && value->c==other->c && value->b==other->b) {
        if(value->a!=other->a) return 1;
        return 0;
    }
    return 1;
}
}



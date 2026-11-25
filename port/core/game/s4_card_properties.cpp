#include "w3d_ptr.h"
#line 1 "s4_card_properties.cpp"
extern "C" {
struct S4Object { Ptr32<Ptr32<void (void)>> vtable; };
struct S4Card { unsigned char pad[932]; Ptr32<S4Object> previous; Ptr32<S4Object> next; Ptr32<S4Object> confirm; unsigned char pad944[40]; Ptr32<S4Object> resource; int unknown988; Ptr32<void> handle; unsigned char pad996[20]; unsigned int flags; };
struct S4Cache { unsigned char data[8]; };
extern S4Cache w3d_cache_804b0c14,w3d_cache_804b0c1c,w3d_cache_804b0c24;
extern int w3d_resource_count_804abb60;
int w3d_cached_message_id(Ptr32<void>,int);
int w3d_subscribe_80162024(Ptr32<void>,Ptr32<unsigned short>,Ptr32<void>);
int w3d_auto_80162310(Ptr32<S4Object>);
void w3d_auto_8015fd1c(Ptr32<void>);
void w3d_s4_card_subscribe_navigation(Ptr32<S4Card> self)
{
    unsigned short a,b,c;
    if(!(self->flags&0x20000000)) {
        a=w3d_cached_message_id(&w3d_cache_804b0c14,1);
        w3d_subscribe_80162024(self,&a,&self->previous);
        b=w3d_cached_message_id(&w3d_cache_804b0c1c,1);
        w3d_subscribe_80162024(self,&b,&self->next);
        c=w3d_cached_message_id(&w3d_cache_804b0c24,1);
        w3d_subscribe_80162024(self,&c,&self->confirm);
        self->flags|=0x20000000;
    }
    self->flags&=0x7fffffff;
}
void w3d_s4_card_unsubscribe_navigation(Ptr32<S4Card> self)
{
    if(self->flags&0x20000000) {
        register int zero=0;
        w3d_auto_80162310(self->previous);
        w3d_auto_80162310(self->next);
        w3d_auto_80162310(self->confirm);
        if(self->previous) ((Ptr32<void (Ptr32<S4Object>)>)self->previous->vtable[4])(self->previous);
        self->previous=(Ptr32<S4Object>)w3d::G(zero);
        if(self->next) ((Ptr32<void (Ptr32<S4Object>)>)self->next->vtable[4])(self->next);
        self->next=(Ptr32<S4Object>)w3d::G(zero);
        if(self->confirm) ((Ptr32<void (Ptr32<S4Object>)>)self->confirm->vtable[4])(self->confirm);
        self->confirm=(Ptr32<S4Object>)w3d::G(zero);
        self->flags&=~0x20000000U;
    }
    self->flags&=0x7fffffff;
}
struct S4App { unsigned char pad[108]; Ptr32<S4Object> audio; unsigned char pad112[68]; int soundMode; };
extern Ptr32<S4App> w3d_app_804b1788;
extern const char w3d_str_803cfb44[];
void w3d_set_value_800fc43c(Ptr32<Ptr32<const char>>,int);
int w3d_read_int_800fc230(Ptr32<Ptr32<const char>>,Ptr32<int>);
// Deferred: argument setup and branch layout differ after one attempt.
#if 0
void w3d_s4_card_apply_sound(void *)
{
    struct { const char *first,*second; unsigned int value; } local;
    if(w3d_app_804b1788->soundMode==0) {
        local.first=w3d_str_803cfb44;
        w3d_set_value_800fc43c(&local.first,0);
    } else {
        local.second=w3d_str_803cfb44;
        register unsigned int zero=0;
        local.value=zero;
        w3d_read_int_800fc230(&local.second,(int *)&local.value);
        if(local.value>2) local.value=zero;
        int mode=local.value;
        if(mode) {
            S4Object *audio=w3d_app_804b1788->audio;
            ((void (*)(S4Object *,int))audio->vtable[31])(audio,mode);
            return;
        }
    }
    S4Object *audio=w3d_app_804b1788->audio;
    ((void (*)(S4Object *,int))audio->vtable[31])(audio,0);
}
#endif
void w3d_s4_card_clear_resource(Ptr32<S4Card> self)
{
    if(self->handle) {
        w3d_auto_8015fd1c(self->handle);
        register int zero=0;
        self->handle=(Ptr32<void>)w3d::G(zero);
        if(self->resource) ((Ptr32<void (Ptr32<S4Object>)>)self->resource->vtable[4])(self->resource);
        self->resource=(Ptr32<S4Object>)w3d::G(zero);
        w3d_resource_count_804abb60-=10;
    }
}
}



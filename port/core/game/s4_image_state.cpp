#include "w3d_ptr.h"
#line 1 "s4_image_state.cpp"
extern "C" {
struct S4Object { Ptr32<Ptr32<void (void)>> vtable; };
struct S4ImageConfig { unsigned char pad[116]; Ptr32<const char> name; };
struct S4Image {
    Ptr32<void> vtable; unsigned char pad4[24],base[12]; Ptr32<S4ImageConfig> config;
    unsigned char pad44[96]; int enabled; unsigned char pad144[64]; Ptr32<Ptr32<void (void)>> secondary;
    Ptr32<S4Object> resource; Ptr32<S4Object> children[2]; int state; unsigned int timer; int pending;
};
struct S4Context { unsigned char pad[52]; unsigned int time; };
struct S4String { Ptr32<char> text; int gap; };
struct S4Message { unsigned short id; };
extern unsigned char w3d_vtable_8041c120[],w3d_vtable_8041c170[];
extern const char w3d_str_803cffc0[];
int w3d_ctor_8015fef0(Ptr32<void>);
void w3d_base_destroy_8015ff2c(Ptr32<void>,int);
Ptr32<void> w3d_image_base_construct_802afb20(Ptr32<void>);
void w3d_image_base_destroy_802afc40(Ptr32<void>,int);
int w3d_auto_8015fb34(Ptr32<void>,Ptr32<S4Message>);
void w3d_auto_8028d1e4(Ptr32<void>);
void w3d_auto_8028d274(Ptr32<void>);
int w3d_image_base_active_802b264c(Ptr32<void>);
void w3d_image_base_message_802aff9c(Ptr32<void>,Ptr32<S4Message>);
void w3d_image_refresh_8028d3b8(Ptr32<void>);
Ptr32<S4Context> w3d_engine_get_context(void);
void w3d_string_base_init(Ptr32<void>);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
Ptr32<unsigned short> w3d_string_header(Ptr32<void>);
void w3d_string_uppercase_8020c2e8(Ptr32<void>);
unsigned int strlen(Ptr32<const char>);
int strcmp(Ptr32<const char>,Ptr32<const char>);
Ptr32<S4Image> w3d_s4_image_construct(Ptr32<S4Image> self)
{
    w3d_ctor_8015fef0(self);
    w3d_image_base_construct_802afb20(self->base);
    self->secondary=(Ptr32<Ptr32<void (...)>>)w3d_vtable_8041c120;
    self->vtable=w3d_vtable_8041c170;
    self->resource=0;
    Ptr32<Ptr32<S4Object>> child=self->children;
    int n=1;
    do { *child++=0; } while(n--);
    register int zero=0;
    self->state=zero;self->pending=zero;
    if(self->children[0]) ((Ptr32<void (Ptr32<S4Object>)>)self->children[0]->vtable[4])(self->children[0]);
    self->children[0]=(Ptr32<S4Object>)w3d::G(zero);
    if(self->children[1]) ((Ptr32<void (Ptr32<S4Object>)>)self->children[1]->vtable[4])(self->children[1]);
    self->children[1]=(Ptr32<S4Object>)w3d::G(zero);
    return self;
}
// Deferred: instruction allocation or loop layout differs after three attempts.
#if 0
void w3d_s4_image_destroy(S4Image *self,int flags)
{
    self->secondary=(void (**)(...))w3d_vtable_8041c120;
    self->vtable=w3d_vtable_8041c170;
    S4Object **begin=self->children;
    if(begin) {
        S4Object **end=begin+2;
        if(begin!=end) {
            register S4Object **first=begin;
            do {
                S4Object *child=*--end;
                if(child) ((void (*)(S4Object *))child->vtable[4])(child);
            } while(first!=end);
        }
    }
    if(self->resource) ((void (*)(S4Object *))self->resource->vtable[4])(self->resource);
    w3d_image_base_destroy_802afc40(self->base,0);
    w3d_base_destroy_8015ff2c(self,flags);
}
#endif
// Deferred: instruction allocation or loop layout differs after three attempts.
#if 0
int w3d_s4_image_message(register S4Image *self,S4Message *message)
{
    switch(message->id) {
    case 64:
        if(w3d_auto_8015fb34(self,message)>=0) {w3d_auto_8028d1e4(self);return 0;}
        return (int)0x80004005;
    case 66: w3d_auto_8028d274(self);break;
    default:
        { void *base=self->base;
          if(w3d_image_base_active_802b264c(base)) w3d_image_base_message_802aff9c(base,message); }
    }
    return w3d_auto_8015fb34(self,message);
}
#endif
void w3d_s4_image_visibility(Ptr32<S4Image> self)
{
    int enabled=self->enabled;
    if(self->children[0]) ((Ptr32<void (Ptr32<S4Object>, int)>)self->children[0]->vtable[22])(self->children[0],enabled);
    if(self->children[1]) ((Ptr32<void (Ptr32<S4Object>, int)>)self->children[1]->vtable[22])(self->children[1],enabled^1);
}
// Deferred: instruction allocation or loop layout differs after three attempts.
#if 0
int w3d_s4_image_changed(void *,S4Image *self)
{
    if(self->pending==1) {
        if(self->state==2 || self->state==5) {
            void (*call)(void *,const char *)=(void (*)(void *,const char *))self->secondary[6];
            call(self->base,self->config->name);
            self->state=3;
        }
        if(self->state==0) self->state=1;
        self->timer=w3d_engine_get_context()->time+500;
    } else {w3d_image_refresh_8028d3b8(self);w3d_s4_image_visibility(self);}
    return 0;
}
#endif
// Deferred: instruction allocation or loop layout differs after three attempts.
#if 0
int w3d_s4_image_has_tga_suffix(void *,S4String *input)
{
    S4String local;
    register S4String *text=&local;
    register S4String *cleanup=text;
    w3d_string_base_init(text);
    local.text=input->text;
    ++*w3d_string_header(text);
    w3d_string_uppercase_8020c2e8(text);
    const char *value=local.text;
    unsigned int length=strlen(value);
    int result;
    if(length>4 && strcmp(value+length-4,w3d_str_803cffc0)==0) {
        result=1;w3d_string_base_finish(cleanup);w3d_string_release(cleanup);
    } else {
        result=0;w3d_string_base_finish(cleanup);w3d_string_release(cleanup);
    }
    w3d_string_base_finish(input);w3d_string_release(input);
    return result;
}
#endif
}



#include "w3d_ptr.h"
#line 1 "s1_damage_popup.cpp"
/* Damage popup timing, position, text, and impulse-message initialization. */
extern "C" {
struct W3dS1DamageVec { float x,y,z; };
struct W3dS1DamageColor { signed char r,g,b,a; };
struct W3dS1DamageMsg { unsigned short id,pad;Ptr32<void> vtable;unsigned int source;int amount;W3dS1DamageVec position;float magnitude;unsigned int flags; };
extern Ptr32<unsigned int> w3d_context_804b1788;
extern unsigned int w3d_color_804af3b4,w3d_message_804ad460;
extern unsigned char w3d_vtable_8040db38[];
extern const char w3d_str_8037787c[],w3d_str_80377888[],w3d_str_8037788c[],w3d_str_803778a4[];
extern const float w3d_f32_80377880[],w3d_f32_80377884[],w3d_f32_80377898[];
unsigned int w3d_cached_message_id(Ptr32<void>,int);
Ptr32<void> w3d_fn_800fc1f0(Ptr32<Ptr32<const char>>,Ptr32<int>);
int w3d_auto_8011ab68(Ptr32<unsigned int>,Ptr32<unsigned short>);
int w3d_fn_8011ac1c(Ptr32<unsigned int>,unsigned int);
void w3d_auto_8015fd1c(Ptr32<unsigned int>);
void w3d_fn_8011adf8(Ptr32<unsigned int>,Ptr32<W3dS1DamageColor>,Ptr32<unsigned int>);
float w3d_fn_802e82c0(float);
int w3d_sprintf_802ec254(Ptr32<char>,Ptr32<const char>,...);
void w3d_fn_8004ea78(Ptr32<unsigned int>);
void w3d_fn_8004ec64(Ptr32<unsigned int>,unsigned int);
void w3d_fn_8004ed24(Ptr32<unsigned int>,unsigned int);
static inline void damage_copy(Ptr32<W3dS1DamageVec> out,Ptr32<W3dS1DamageVec> in) { float x=in->x,y=in->y,z=in->z;out->x=x;out->y=y;out->z=z; }
static inline void damage_position(Ptr32<unsigned int> self,Ptr32<W3dS1DamageVec> position) { ((Ptr32<void (Ptr32<unsigned int>, Ptr32<W3dS1DamageVec>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)self)[10])(self,position); }
static inline void damage_text(Ptr32<unsigned int> self,Ptr32<const char> text) { ((Ptr32<void (Ptr32<unsigned int>, Ptr32<const char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)self)[11])(self,text); }
int w3d_fn_8004e964(Ptr32<unsigned int> self,Ptr32<unsigned short> message)
{
    if(*message==64) {
        if(w3d_auto_8011ab68(self,message)>=0) {w3d_fn_8004ea78(self);return 0;}
        return 0x80004005;
    }
    return w3d_auto_8011ab68(self,message);
}
int w3d_fn_8004e9c8(Ptr32<unsigned int> self,unsigned int now)
{
    if(!self[23]) {self[23]=now;damage_position(self,(Ptr32<W3dS1DamageVec>)(self+24));return 0;}
    if(self[22]!=self[21])w3d_fn_8004ec64(self,now);
    w3d_fn_8004ed24(self,now);
    if(now>self[23]+2500) {w3d_auto_8015fd1c(self);return -1;}
    w3d_fn_8011ac1c(self,now);return 0;
}
void w3d_fn_8004ea78(Ptr32<unsigned int> self)
{
    struct { W3dS1DamageColor color;int gap; } local;
    local.color.r=-1;local.color.g=50;local.color.b=50;local.color.a=-1;
    w3d_fn_8011adf8(self,&local.color,&w3d_color_804af3b4);
    damage_text(self,w3d_str_8037787c);
}
#if 0 /* Remaining floating-point scheduling or time-conversion differences. */
void w3d_fn_8004eb34(unsigned int *self,W3dS1DamageVec *position)
{
    struct { W3dS1DamageVec camera;int gap0;W3dS1DamageVec delta;int gap1;W3dS1DamageVec copy;int gap2; } local;
    *(W3dS1DamageVec *)(self+24)=*position;
    unsigned int camera=w3d_context_804b1788[12];
    W3dS1DamageVec *eye=((W3dS1DamageVec *(*)(unsigned int))(*(void ***)camera)[14])(camera);
    damage_copy(&local.camera,eye);
    local.delta.x=local.camera.x-position->x;local.delta.y=local.camera.y-position->y;local.delta.z=local.camera.z-position->z;
    float length=w3d_fn_802e82c0(local.delta.x*local.delta.x+local.delta.y*local.delta.y+local.delta.z*local.delta.z);
    float scale=w3d_f32_80377880[0]/length;
    local.delta.x*=scale;local.delta.y*=scale;local.delta.z*=scale;
    W3dS1DamageVec *out=(W3dS1DamageVec *)(self+24);
    out->x+=local.delta.x;out->y+=local.delta.y;out->z+=local.delta.z;
    out->y+=w3d_f32_80377884[0];
}
#endif
void w3d_fn_8004ec64(Ptr32<unsigned int> self,unsigned int now)
{
    char text[16];
    int value=(int)((now-self[23])*self[21])/850;
    self[22]=value;
    if(value>(int)self[21])self[22]=self[21];
    if((int)self[21]>0)w3d_sprintf_802ec254(text,w3d_str_80377888,-(int)self[22]);
    else w3d_sprintf_802ec254(text,w3d_str_8037788c,-(int)self[22]);
    damage_text(self,text);
}
#if 0 /* Remaining floating-point scheduling or time-conversion differences. */
void w3d_fn_8004ed24(unsigned int *self,unsigned int now)
{
    struct { W3dS1DamageVec position;int gap; } local;
    damage_copy(&local.position,(W3dS1DamageVec *)(self+24));
    if(now>self[23]+1000)local.position.y+=(float)(now-1000-self[23])*w3d_f32_80377898[0];
    damage_position(self,&local.position);
}
#endif
Ptr32<W3dS1DamageMsg> w3d_fn_8004ee4c(Ptr32<W3dS1DamageMsg> self,unsigned int source,int amount,Ptr32<W3dS1DamageVec> position,float magnitude,unsigned int flags,int suppress_double)
{
    struct { Ptr32<const char> key;int doubled;int gap[2]; } local;
    self->id=w3d_cached_message_id(&w3d_message_804ad460,1);self->vtable=w3d_vtable_8040db38;
    self->source=source;self->amount=amount;self->position=*position;self->magnitude=magnitude;self->flags=flags;
    if(!suppress_double) {
        local.key=w3d_str_803778a4;w3d_fn_800fc1f0(&local.key,&local.doubled);
        if(local.doubled==1) { self->amount+=self->amount;self->magnitude+=self->magnitude; }
    }
    return self;
}
}



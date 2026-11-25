#include "w3d_ptr.h"
#line 1 "s1_crate_impacts.cpp"
/* Crate damage, splash, camera, and utility reward actions. */
extern "C" {
struct W3dS1PickupKey { Ptr32<const char> text; };
struct W3dS1PickupVec { float x,y,z; };
struct W3dS1PickupRef;
struct W3dS1PickupRefVtable { Ptr32<void (void)> unused[4]; Ptr32<void (Ptr32<W3dS1PickupRef>)> release; };
struct W3dS1PickupRef { Ptr32<W3dS1PickupRefVtable> vtable; };
struct W3dS1PickupSound;
struct W3dS1PickupSoundVtable { Ptr32<void (void)> unused[24]; Ptr32<void (Ptr32<W3dS1PickupSound>, Ptr32<const char>, Ptr32<W3dS1PickupVec>)> play; };
struct W3dS1PickupSound { Ptr32<W3dS1PickupSoundVtable> vtable; };
struct W3dS1PickupContext { unsigned char unknown[0x6c];Ptr32<W3dS1PickupSound> sound; };
struct W3dS1PickupActor { unsigned char unknown[0xd5];unsigned char team; };
struct W3dS1PickupTeam { unsigned char unknown[0x3c];unsigned char alliance; };
struct W3dS1PickupMessage { unsigned short id;unsigned short unused;Ptr32<void> vtable; };
struct W3dS1PickupHandle { unsigned int id,kind; };
extern Ptr32<void> w3d_queue_804b1754;
extern Ptr32<W3dS1PickupContext> w3d_context_804b1788;
extern unsigned char w3d_message_vtable_8040db38[];
extern unsigned int w3d_message_804ad3b0,w3d_message_804ad358,w3d_message_804ad380,w3d_message_804ad378,w3d_message_804ad3f0,w3d_message_804ad3c8,w3d_message_804ad3a0,w3d_message_804ad398,w3d_message_804ad350;
extern const char w3d_str_80377118[],w3d_str_80376ed4[],w3d_str_803772cc[],w3d_str_803772dc[],w3d_str_803772f0[],w3d_str_80377308[],w3d_str_80377318[],w3d_str_80377330[],w3d_str_8037734c[];
extern const float w3d_f32_803772ec[];
Ptr32<void> w3d_fn_801613f0(Ptr32<void>,unsigned int);
unsigned int w3d_cached_message_id(Ptr32<void>,int);
int w3d_message_post_current(Ptr32<void>);
Ptr32<void> w3d_message_int_init(Ptr32<void>,unsigned int,unsigned int);
Ptr32<W3dS1PickupActor> w3d_fn_800fc6dc(unsigned int);
Ptr32<W3dS1PickupTeam> w3d_fn_800fc7f8(unsigned int);
int w3d_fn_800fc3b0(Ptr32<Ptr32<const char>>,unsigned int);
void w3d_fn_800fc550(Ptr32<Ptr32<const char>>,unsigned int);
void w3d_fn_800fc230(Ptr32<Ptr32<const char>>,Ptr32<int>);
void w3d_fn_800fc43c(Ptr32<Ptr32<const char>>,int);
Ptr32<unsigned int> w3d_fn_800fc710(unsigned int,Ptr32<W3dS1PickupHandle>);
void w3d_fn_80178474(Ptr32<W3dS1PickupHandle>,int);
void w3d_auto_8015fd1c(Ptr32<void>);
void w3d_auto_8004c814(Ptr32<unsigned int>,unsigned int);
void w3d_fn_8004c598(Ptr32<unsigned int>,unsigned int);
void w3d_fn_8004c670(Ptr32<unsigned int>,unsigned int);
void w3d_fn_8004c51c(Ptr32<unsigned int>);
void w3d_fn_8004c7a0(Ptr32<unsigned int>,unsigned int);
void w3d_fn_8004cda4(Ptr32<unsigned int>,unsigned int);
void w3d_fn_8004d10c(Ptr32<unsigned int>);
int w3d_fn_800e5ca4(float,Ptr32<W3dS1PickupVec>,Ptr32<const char>,int);
static inline void post_pickup_message(Ptr32<unsigned int> id)
{
    Ptr32<W3dS1PickupMessage> message=(Ptr32<W3dS1PickupMessage>)w3d_fn_801613f0(w3d_queue_804b1754,8);
    message->id=w3d_cached_message_id(id,1);
    message->vtable=w3d_message_vtable_8040db38;
    w3d_message_post_current(message);
}
static inline void release_pickup_ref(unsigned int value)
{
    Ptr32<W3dS1PickupRef> ref=(Ptr32<W3dS1PickupRef>)w3d::G(value);
    if(ref)ref->vtable->release(ref);
}

extern const char w3d_str_803772bc[],w3d_str_80377360[],w3d_str_8037737c[],w3d_str_80377394[],w3d_str_803773ac[],w3d_str_803773c4[],w3d_str_803773d8[],w3d_str_803773f0[],w3d_str_80377404[],w3d_str_8037740c[],w3d_str_80377434[],w3d_str_80377440[],w3d_str_80377454[],w3d_str_8037746c[],w3d_str_80376eb0[],w3d_str_803774bc[],w3d_str_803774dc[];
extern const float w3d_f32_803773fc[],w3d_f32_8037741c[],w3d_f32_80377420[],w3d_f32_80377474[],w3d_f32_80377478[],w3d_f32_8037747c[],w3d_f32_803774fc[],w3d_f32_80377500[],w3d_f32_80377504[];
extern W3dS1PickupVec w3d_hit_8043ae20[];
extern unsigned int w3d_distance_804b1764,w3d_message_804ad3f8,w3d_camera_804aa8c8;
extern Ptr32<unsigned char> w3d_world_804b17e0;
Ptr32<void> w3d_fn_800fc1f0(const W3dS1PickupKey &,Ptr32<int>);
void w3d_fn_800fc270(const W3dS1PickupKey &,Ptr32<float>);
Ptr32<unsigned int> w3d_fn_800fc82c(unsigned int,Ptr32<W3dS1PickupHandle>);
Ptr32<void> w3d_fn_800fcdb8(unsigned int,Ptr32<W3dS1PickupHandle>);
int w3d_fn_8025cbe0(Ptr32<void>,unsigned int);
void w3d_fn_8025d020(Ptr32<void>,unsigned int,signed char);
Ptr32<void> w3d_fn_800666b4(float,float,float,float,float,Ptr32<void>,Ptr32<W3dS1PickupVec>,Ptr32<W3dS1PickupVec>);
void w3d_fn_800b0824(Ptr32<W3dS1PickupVec>,Ptr32<W3dS1PickupVec>,Ptr32<W3dS1PickupVec>,unsigned int,int);
void w3d_fn_80035714(float,unsigned int,Ptr32<const char>);
float w3d_auto_80178df0(Ptr32<void>);
float fn_80162BC8(void);
void w3d_fn_8004c850(Ptr32<unsigned int>);
void w3d_fn_8004cd08(Ptr32<unsigned int>);
void w3d_fn_8004d23c(Ptr32<unsigned int>);
static inline void scale_vec(Ptr32<W3dS1PickupVec> out,Ptr32<W3dS1PickupVec> v,float scale)
{
    out->x=v->x*scale;out->y=v->y*scale;out->z=v->z*scale;
}
static inline void copy_vec(Ptr32<W3dS1PickupVec> out,Ptr32<W3dS1PickupVec> in)
{
    float x=in->x,y=in->y,z=in->z;out->x=x;out->y=y;out->z=z;
}
static inline void add_vec(Ptr32<W3dS1PickupVec> v,Ptr32<W3dS1PickupVec> delta)
{
    v->x+=delta->x;v->y+=delta->y;v->z+=delta->z;
}
#if 0 /* Remaining scheduling, register allocation, or aggregate stack differences. */
void w3d_fn_8004c850(unsigned int *self)
{
    struct { W3dS1PickupVec position;int gap;const char *damage_key;float damage;const char *impulse_key;float impulse;const char *worm_key;float worm_radius;const char *land_key;float land_radius;const char *radius_key;float impulse_radius;const char *index_key; } local;
    if(!self[0x7c/4]) {
        self[0x7c/4]=1;
        copy_vec(&local.position,(W3dS1PickupVec *)(self+0x28/4));
        local.position.y-=*(float *)(self+0x40/4);
        local.damage_key=w3d_str_80377360;w3d_fn_800fc270(*(W3dS1PickupKey *)&local.damage_key,&local.damage);
        local.impulse_key=w3d_str_8037737c;w3d_fn_800fc270(*(W3dS1PickupKey *)&local.impulse_key,&local.impulse);
        local.worm_key=w3d_str_80377394;w3d_fn_800fc270(*(W3dS1PickupKey *)&local.worm_key,&local.worm_radius);
        local.land_key=w3d_str_803773ac;w3d_fn_800fc270(*(W3dS1PickupKey *)&local.land_key,&local.land_radius);
        local.radius_key=w3d_str_803773c4;w3d_fn_800fc270(*(W3dS1PickupKey *)&local.radius_key,&local.impulse_radius);
        void *message=w3d_fn_801613f0(w3d_queue_804b1754,52);
        W3dS1PickupVec *position=(W3dS1PickupVec *)(self+0x28/4);
        w3d_message_post_current(w3d_fn_800666b4(local.damage,local.impulse,local.worm_radius,local.land_radius,local.impulse_radius,message,position,&local.position));
        w3d_fn_800e5ca4(w3d_f32_803773fc[0],position,w3d_str_803773d8,0);
        W3dS1PickupSound *sound=w3d_context_804b1788->sound;
        if(sound)sound->vtable->play(sound,w3d_str_803773f0,position);
        local.index_key=w3d_str_80377118;w3d_fn_800fc3b0(&local.index_key,self[0x20/4]);
        post_pickup_message(&w3d_message_804ad350);
        w3d_auto_8015fd1c(self);
    }
}
#endif
#if 0 /* Remaining scheduling, register allocation, or aggregate stack differences. */
void w3d_fn_8004cbdc(float scale,unsigned int *self,W3dS1PickupVec *direction)
{
    if(self[0x74/4]) {
        struct { W3dS1PickupVec delta; int gap; W3dS1PickupVec copy; int gap2; } local;
        scale_vec(&local.delta,direction,scale);
        add_vec((W3dS1PickupVec *)(self+0x34/4),&local.delta);
        self[0x64/4]=0;
    }
}
#endif
#if 0 /* Remaining scheduling, register allocation, or aggregate stack differences. */
void w3d_fn_8004cc60(float damage,unsigned int *self)
{
    struct { const char *key; int active; int gap[2]; } local;
    if((int)self[0x8c/4]!=-1) {
        local.key=w3d_str_803772bc;w3d_fn_800fc1f0(*(W3dS1PickupKey *)&local.key,&local.active);
        if(w3d_fn_800fc6dc(local.active)->team!=self[0x8c/4])return;
    }
    int health=(int)self[0x48/4]-(int)damage;
    self[0x48/4]=health;
    if(health<=0&&!self[0x7c/4])w3d_fn_8004c850(self);
}
#endif
void w3d_fn_8004cd08(Ptr32<unsigned int> self)
{
    Ptr32<W3dS1PickupSound> sound=w3d_context_804b1788->sound;
    if(sound)sound->vtable->play(sound,w3d_str_80377404,(Ptr32<W3dS1PickupVec>)(self+0x28/4));
    W3dS1PickupVec position;copy_vec(&position,(Ptr32<W3dS1PickupVec>)(self+0x28/4));
    position.y=w3d_f32_8037741c[0];
    w3d_fn_800e5ca4(w3d_f32_80377420[0],&position,w3d_str_8037740c,0);
}
#if 0 /* Remaining scheduling, register allocation, or aggregate stack differences. */
void w3d_fn_8004cda4(unsigned int *self,unsigned int team)
{
    W3dS1PickupHandle local;W3dS1PickupHandle *handle=&local;handle->id=0;handle->kind=0xe3a8;
    void *inventory=w3d_fn_800fcdb8(w3d_fn_800fc7f8(team)->alliance,handle);
    unsigned int amount=w3d_fn_8025cbe0(inventory,self[0x24/4]);
    if(amount!=-1) { unsigned int increment=*((unsigned char *)self+0x47); increment+=amount; w3d_fn_8025d020(inventory,self[0x24/4],(signed char)increment); }
    self[0x44/4]=0;w3d_fn_80178474(handle,2);
}
#endif
#if 0 /* Remaining scheduling, register allocation, or aggregate stack differences. */
void w3d_fn_8004d044(unsigned int *self,unsigned int *message)
{
    const char *key;int active;
    if(!self[0x7c/4]) {
        if((int)self[0x8c/4]!=-1) {
            key=w3d_str_803772bc;w3d_fn_800fc1f0(*(W3dS1PickupKey *)&key,&active);
            if(w3d_fn_800fc6dc(active)->team!=self[0x8c/4])return;
        }
        if(message[2]==self[0x14/4]) {
            int health=(int)self[0x48/4]-message[3];self[0x48/4]=health;
            if(health<=0)w3d_fn_8004c850(self);
        }
        release_pickup_ref(self[0xf4/4]);self[0xf4/4]=0;
    }
}
#endif
void w3d_fn_8004d10c(Ptr32<unsigned int> self)
{
    struct { W3dS1PickupHandle handle;Ptr32<const char> key;int active; } local;
    local.key=w3d_str_803772bc;w3d_fn_800fc1f0(*(Ptr32<W3dS1PickupKey>)&local.key,&local.active);
    if(local.active!=-1) {
        Ptr32<W3dS1PickupHandle> handle=&local.handle;
        unsigned int team=w3d_fn_800fc6dc(local.active)->team;
        handle->id=0;handle->kind=0xe3a8;
        Ptr32<unsigned int> target=w3d_fn_800fc82c(team,handle);target[0x28/4]=1;
        w3d_fn_80178474(handle,2);post_pickup_message(&w3d_message_804ad3f8);
    }
}
#if 0 /* Remaining scheduling, register allocation, or aggregate stack differences. */
void w3d_fn_8004d1c4(unsigned int *self)
{
    const char *data,*entity;
    w3d_fn_8004d23c(self);
    w3d_fn_800fc550((data=w3d_str_80377434,&data),(unsigned int)w3d_str_80377440);
    entity=w3d_str_80377454;w3d_fn_800fc43c(&entity,self[0x14/4]);
    w3d_fn_80035714(w3d_f32_80377474[0],w3d_camera_804aa8c8,w3d_str_8037746c);
}
#endif
#if 0 /* Remaining scheduling, register allocation, or aggregate stack differences. */
void w3d_fn_8004d23c(unsigned int *self)
{
    struct { W3dS1PickupVec position;int gap0;W3dS1PickupVec direction;int gap1;W3dS1PickupVec zero;int gap2;W3dS1PickupVec hit;int gap3;const char *key;float level;union { float value;unsigned int bits; } magnitude; } local;
    copy_vec(&local.position,(W3dS1PickupVec *)(self+0x28/4));
    local.key=w3d_str_80376eb0;w3d_fn_800fc270(*(W3dS1PickupKey *)&local.key,&local.level);
    local.magnitude.value=local.position.y-*(float *)(w3d_world_804b17e0+0x3108);
    local.magnitude.bits&=0x7fffffff;
    local.direction.x=w3d_f32_8037747c[0];local.direction.y=-local.magnitude.value/w3d_f32_80377478[0];local.direction.z=w3d_f32_8037747c[0];
    local.zero.x=w3d_f32_8037747c[0];local.zero.z=w3d_f32_8037747c[0];local.zero.y=w3d_f32_8037747c[0];
    w3d_fn_800b0824(&local.position,&local.direction,&local.zero,1000,1);
    copy_vec(&local.hit,w3d_hit_8043ae20);
    *(float *)(self+0x104/4)=local.position.x;
    if(w3d_distance_804b1764<=1000)*(float *)(self+0x108/4)=local.hit.y;
    else *(float *)(self+0x108/4)=local.level;
    *(float *)(self+0x10c/4)=local.position.z;
}
#endif
void w3d_fn_8004d35c(Ptr32<unsigned int> self)
{
    Ptr32<const char> key;
    if(!self[0x7c/4]&&!self[0x84/4]) {
        self[0x7c/4]=1;self[0x84/4]=1;
        Ptr32<W3dS1PickupSound> sound=w3d_context_804b1788->sound;
        if(sound)sound->vtable->play(sound,w3d_str_803773f0,(Ptr32<W3dS1PickupVec>)(self+0x28/4));
        key=w3d_str_80377118;w3d_fn_800fc3b0(&key,self[0x20/4]);
        post_pickup_message(&w3d_message_804ad350);w3d_auto_8015fd1c(self);
    }
}
#if 0 /* Remaining scheduling, register allocation, or aggregate stack differences. */
void w3d_fn_8004d428(unsigned int *self)
{
    struct { W3dS1PickupVec random;int gap0;W3dS1PickupVec impulse;int gap1;W3dS1PickupVec copy;int gap2;const char *max_key,*min_key; } local;
    if(self[0x64/4]) {
        if(*(float *)(self+0x110/4)==w3d_f32_803774fc[0]) {
            local.max_key=w3d_str_803774bc;w3d_fn_800fc270(*(W3dS1PickupKey *)&local.max_key,(float *)(self+0x110/4));
            local.min_key=w3d_str_803774dc;w3d_fn_800fc270(*(W3dS1PickupKey *)&local.min_key,(float *)(self+0x114/4));
        }
        local.random.x=fn_80162BC8()*2-w3d_f32_80377500[0];local.random.y=w3d_f32_80377504[0];
        local.random.z=fn_80162BC8()*2-w3d_f32_80377500[0];
        float scale=fn_80162BC8()*(*(float *)(self+0x110/4)-*(float *)(self+0x114/4));
        scale_vec(&local.impulse,&local.random,scale);
        *(W3dS1PickupVec *)(self+0x34/4)=local.impulse;
        self[0x64/4]=0;
    }
}
#endif
void w3d_fn_8004d54c(Ptr32<unsigned int> self)
{
    float level=w3d_auto_80178df0((Ptr32<void>)w3d::G((self[0xb8/4])));
    if(!self[0x80/4]&&*(Ptr32<float>)(self+0x2c/4)<=level) {
        self[0x70/4]=0;self[0x80/4]=1;w3d_fn_8004cd08(self);
    }
}
}



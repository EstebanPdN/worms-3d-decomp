#include "w3d_ptr.h"
#line 1 "s1_sound_tests.cpp"
/* Observed sound test scheduling, spatial offsets, and debug sound resources. */
extern "C" {
struct W3dS1SoundVec {float x,y,z;};
struct W3dS1SoundRef;
struct W3dS1SoundVtable {Ptr32<void (void)> unused[4];Ptr32<void (Ptr32<W3dS1SoundRef>)> release;};
struct W3dS1SoundRef {Ptr32<W3dS1SoundVtable> vtable;};
struct W3dS1SoundText {Ptr32<char> text;};
extern unsigned char w3d_vtable_8040eb20[],w3d_vtable_8040eb60[];
extern Ptr32<unsigned int> w3d_context_804b1788; extern Ptr32<unsigned int> w3d_sound_debug_804aaa10;
extern unsigned int w3d_output_804aaa14,w3d_message_804ad478,w3d_message_804ad480;
extern Ptr32<const char> w3d_sound_names_803f40f4[];
extern const char w3d_str_803781c0[];
extern const float w3d_f32_80378178[],w3d_f32_80378188[],w3d_f32_8037818c[],w3d_f32_80378190[],w3d_f32_80378198[];
void w3d_base_destroy_8015ff2c(Ptr32<void>,int);
int w3d_ctor_801628b0(Ptr32<void>);
void w3d_service_destroy_801628ec(Ptr32<void>,int);
void w3d_auto_8015fd1c(Ptr32<void>);
Ptr32<unsigned int> w3d_engine_get_context(void);
unsigned int w3d_auto_8015ff5c(Ptr32<void>);
float w3d_auto_8015ff7c(Ptr32<void>);
void w3d_motion_get_position_80066894(Ptr32<W3dS1SoundVec>,Ptr32<void>);
float w3d_motion_get_28_800668e4(Ptr32<void>);
float w3d_fn_80051a18(float,Ptr32<void>);
float w3d_fn_802e86d4(float);
float w3d_fn_802e88ac(float);
unsigned int w3d_fn_802cc4f0(Ptr32<const char>);
void w3d_fn_802cc58c(unsigned int);
int w3d_auto_8016293c(Ptr32<void>,Ptr32<unsigned short>);
void w3d_auto_80051f94(Ptr32<void>);
void w3d_empty_80052004(Ptr32<void>);
int w3d_fn_8015f65c(unsigned int,Ptr32<void>);
Ptr32<W3dS1SoundVec> w3d_vec_message_value_80126034(Ptr32<void>);
Ptr32<const char> w3d_get_8010a8fc(Ptr32<void>);
void w3d_string_from_text(Ptr32<W3dS1SoundText>,Ptr32<const char>);
void w3d_string_base_finish(Ptr32<W3dS1SoundText>);
void w3d_string_release(Ptr32<W3dS1SoundText>);
void w3d_fn_80051930(Ptr32<unsigned int>,int,int);
Ptr32<W3dS1SoundVec> w3d_fn_80051a24(float,Ptr32<W3dS1SoundVec>,Ptr32<void>,Ptr32<W3dS1SoundVec>);
static inline void release_sound(unsigned int v) {Ptr32<W3dS1SoundRef> ref=(Ptr32<W3dS1SoundRef>)w3d::G(v);if(ref)ref->vtable->release(ref);}
static inline void sound_play(unsigned int sound) {((Ptr32<void (unsigned int)>)(*(Ptr32<Ptr32<Ptr32<void>>>)w3d::G(sound))[5])(sound);}
static inline void sound_position(unsigned int sound,Ptr32<W3dS1SoundVec> position) {((Ptr32<void (unsigned int, int, Ptr32<W3dS1SoundVec>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)w3d::G(sound))[14])(sound,3,position);}
static inline void sound_volume(float volume,unsigned int sound) {((Ptr32<void (unsigned int, int, float)>)(*(Ptr32<Ptr32<Ptr32<void>>>)w3d::G(sound))[13])(sound,1,volume);}
static inline void sound_lookup(unsigned int context,Ptr32<const char> name,Ptr32<unsigned int> out) {((Ptr32<void (unsigned int, Ptr32<const char>, Ptr32<unsigned int>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)w3d::G(context))[23])(context,name,out);}
#if 0 /* Remaining loop register allocation, scheduling, or message-dispatch copy differences. */
void w3d_fn_80051564(unsigned int *self,int flags)
{
    self[0]=(unsigned int)w3d_vtable_8040eb20;
    unsigned int *first=self+11;
    if(first) {unsigned int *last=self+15;while(last!=first)release_sound(*--last);}
    w3d_base_destroy_8015ff2c(self,flags);
}
#endif
#if 0 /* Remaining loop register allocation, scheduling, or message-dispatch copy differences. */
int w3d_fn_8005166c(unsigned int *self,int now)
{
    int finished=1;
    for(int i=0;i<4;++i) {
        unsigned int *sound=self+11+i;
        if(*sound) {
            if(!self[7+i]) {finished=0;if(now>(int)sound[4]) {sound_play(*sound);self[7+i]=1;}}
            else if(((int (*)(unsigned int))(*(void ***)*sound)[9])(*sound)) {finished=0;w3d_fn_80051930(self,i,now);}
        }
    }
    if(finished)w3d_auto_8015fd1c(self);
    return 0;
}
#endif
#if 0 /* Remaining loop register allocation, scheduling, or message-dispatch copy differences. */
void w3d_fn_800517a4(unsigned int *self,void *motion)
{
    struct {W3dS1SoundVec origin;int gap;W3dS1SoundVec position;int gap2;} local;
    if(!w3d_context_804b1788[27]) {w3d_auto_8015fd1c(self);return;}
    self[20]=w3d_engine_get_context()[13];
    int previous=4;
    for(int i=0;i<4;++i) {
        self[15+i]=self[20]+w3d_auto_8015ff5c(self)%870;self[7+i]=0;
        int selected=w3d_auto_8015ff5c(self)&3;
        if(selected==previous)selected=(selected+1)%4;
        previous=selected;
        sound_lookup(w3d_context_804b1788[27],w3d_sound_names_803f40f4[selected],self+11+i);
        w3d_motion_get_position_80066894(&local.origin,motion);
        unsigned int sound=self[11+i];
        float radius=w3d_motion_get_28_800668e4(motion);
        w3d_fn_80051a24(radius,&local.position,self,&local.origin);
        sound_position(sound,&local.position);
        sound_volume(w3d_f32_80378178[0],self[11+i]);
    }
    *(float *)(self+19)=w3d_fn_80051a18(w3d_motion_get_28_800668e4(motion),self);
}
#endif
void w3d_fn_80051930(Ptr32<unsigned int> self,int index,int now)
{
    int start=self[20];float volume;
    if(now<=start+750)volume=((float)(now-start)/w3d_f32_80378188[0])**(Ptr32<float>)(self+19);
    else if(now>=start+3250)volume=w3d_f32_8037818c[0];
    else volume=((float)(2500-(now-start))/w3d_f32_80378190[0])**(Ptr32<float>)(self+19);
    if(volume<w3d_f32_8037818c[0])volume=w3d_f32_8037818c[0];
    sound_volume(volume,self[11+index]);
}
Ptr32<W3dS1SoundVec> w3d_fn_80051a24(float radius,Ptr32<W3dS1SoundVec> out,Ptr32<void> self,Ptr32<W3dS1SoundVec> origin)
{
    struct {W3dS1SoundVec position;int gap;W3dS1SoundVec temporary;int gap2[3];} local;
    Ptr32<W3dS1SoundVec> position=&local.position;float x=origin->x,y=origin->y,z=origin->z;position->x=x;position->z=z;position->y=y;
    float angle=w3d_auto_8015ff7c(self)*w3d_f32_80378198[0];
    float distance=w3d_auto_8015ff7c(self)*radius;
    local.position.x+=w3d_fn_802e86d4(angle)*distance;
    local.position.z+=w3d_fn_802e88ac(angle)*distance;
    out->x=position->x;out->y=position->y;out->z=position->z;
    return out;
}
Ptr32<unsigned int> w3d_fn_80051c9c(Ptr32<unsigned int> self)
{
    w3d_ctor_801628b0(self);self[0]=(unsigned int)w3d::H(w3d_vtable_8040eb60);
    Ptr32<unsigned int> p=self+8;int count=5;do {*p++=0;}while(--count);
    self[18]=0;self[19]=0;self[20]=0;w3d_sound_debug_804aaa10=self;
    w3d_output_804aaa14=w3d_fn_802cc4f0(w3d_str_803781c0);return self;
}
#if 0 /* Remaining loop register allocation, scheduling, or message-dispatch copy differences. */
void w3d_fn_80051d18(unsigned int *self,int flags)
{
    self[0]=(unsigned int)w3d_vtable_8040eb60;w3d_fn_802cc58c(w3d_output_804aaa14);w3d_sound_debug_804aaa10=0;
    release_sound(self[20]);release_sound(self[19]);release_sound(self[18]);
    unsigned int *first=self+8;
    if(first) {unsigned int *last=self+13;while(last!=first)release_sound(*--last);}
    w3d_service_destroy_801628ec(self,flags);
}
#endif
#if 0 /* Remaining loop register allocation, scheduling, or message-dispatch copy differences. */
int w3d_fn_80051df8(unsigned int *self,unsigned short *message)
{
    struct {union {W3dS1SoundVec position;W3dS1SoundText text;} value;int gap;W3dS1SoundVec camera;int gap2;} local;
    unsigned int id=*message;
    switch((unsigned short)id) {
    case 64:if(w3d_auto_8016293c(self,message)>=0) {w3d_auto_80051f94(self);return 0;}return 0x80004005;
    case 66:w3d_empty_80052004(self);return w3d_auto_8016293c(self,message);
    }
    if(w3d_fn_8015f65c(id,&w3d_message_804ad478)) {
        W3dS1SoundVec *value=w3d_vec_message_value_80126034(message);
        local.value.position=*value;
    } else if(!w3d_fn_8015f65c(id,&w3d_message_804ad480))return w3d_auto_8016293c(self,message);
    else {
        w3d_string_from_text(&local.value.text,w3d_get_8010a8fc(message));
        sound_lookup(w3d_context_804b1788[27],local.value.text.text,self+20);
        unsigned int camera=w3d_context_804b1788[12];
        W3dS1SoundVec *position=((W3dS1SoundVec *(*)(unsigned int))(*(void ***)camera)[14])(camera);
        float x=position->x,y=position->y,z=position->z;local.camera.x=x;local.camera.y=y;local.camera.z=z;
        sound_position(self[20],&local.camera);sound_play(self[20]);
        w3d_string_base_finish(&local.value.text);w3d_string_release(&local.value.text);
    }
    return 0;
}
#endif
}



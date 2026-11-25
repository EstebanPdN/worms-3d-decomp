#include "w3d_ptr.h"
#line 1 "s2_wind_display_r3.cpp"
/* Wind display state, animation rate and numeric mesh digits. */
extern "C" {
struct Object {Ptr32<Ptr32<void>> vtable;};
struct Gap {int a,b;~Gap(){}};
double fabs(double);
struct Vec {float x,y,z;Vec(){}Vec(float a,float b,float c){x=a;y=b;z=c;}Vec(const Vec &v){x=v.x;y=v.y;z=v.z;}};
struct Wind {Ptr32<void> vtable;char unknown04[24];Ptr32<Object> mesh;int control;Ptr32<Object> other; Ptr32<Object> digits; Ptr32<Object> direction; Ptr32<Object> speed; Ptr32<Object> maximum; Ptr32<Object> rate;char unknown3c[12];Ptr32<Object> extra[2];float value,ratio;int timer,enabled,start;float fraction;Ptr32<Object> unknown68;float unknown6c;int sampleRate,channels,unknown78[9];};
struct Context {char unknown00[56];int paused;};
struct Message {unsigned short id,pad;Ptr32<void> vtable;int zero,time;Vec position,velocity;float value;int target;float amount;char member[8];};
void w3d_ctor_8015fef0(Ptr32<Wind>);
int w3d_auto_8015fb34(Ptr32<Wind>,Ptr32<unsigned short>);
int w3d_fn_8015f620(Ptr32<void>,unsigned short);
void w3d_fn_80130638(Ptr32<Wind>);
void w3d_wind_set_visible_801315a0(Ptr32<Wind>,int);
float w3d_wind_ratio_80130dd4(Ptr32<Wind>);
void w3d_wind_clear_animation_80130f78(Ptr32<Wind>);
void w3d_wind_animation_80130ed8(Ptr32<Wind>);
void w3d_wind_digits_80130e24(Ptr32<Wind>);
Ptr32<Object> w3d_empty_80342a74(Ptr32<Object>);
Ptr32<Object> w3d_empty_80343584(Ptr32<Object>);
Ptr32<Object> w3d_empty_8034380c(Ptr32<Object>);
float w3d_auto_80178df0(Ptr32<Object>);
Ptr32<unsigned char> w3d_fn_80189828(Ptr32<Object>);
Ptr32<Context> w3d_engine_get_context();
void w3d_fn_80181640(Ptr32<Object>,Ptr32<const char>,Ptr32<int>,int,float,float,float);
void w3d_mesh_instance_check_control(Ptr32<Object>,int,int);
int w3d_mesh_instance_control_3c(Ptr32<Object>,int);
float w3d_fn_802e86d4(float);
float w3d_fn_802e88ac(float);
int w3d_cached_message_id(Ptr32<void>,int);
Ptr32<void> w3d_actor_method_member_initialize(Ptr32<void>);
extern unsigned int w3d_obj_804af730,w3d_obj_804af738,w3d_obj_804af7a0;
extern char w3d_obj_80410e40[],w3d_obj_8040db38[];
extern const float w3d_f32_8039dfe4[],w3d_f32_8039dfe8[],w3d_f32_8039e15c[],w3d_f32_8039e160[],w3d_f32_8039e164[],w3d_f32_8039e174[],w3d_f32_8039e178[],w3d_f32_8039e1b0[],w3d_f32_8039e1b4[],w3d_f32_8039e1ec[],w3d_f32_8039e27c[];
extern const char w3d_str_8039e19c[];
#if 0 // Excluded after two attempts: constant setup and field initialization scheduling differ.
Wind *w3d_wind_construct_8012fff4(Wind *self) {
    w3d_ctor_8015fef0(self);
    self->vtable=w3d_obj_80410e40;self->control=-1;
    self->fraction=w3d_f32_8039dfe8[0];self->enabled=1;self->start=0;
    self->unknown6c=w3d_f32_8039dfe4[0];self->sampleRate=22050;self->channels=2;
    self->mesh=0;self->other=0;self->digits=0;self->direction=0;self->speed=0;self->maximum=0;self->rate=0;self->extra[0]=0;self->extra[1]=0;self->unknown68=0;
    self->unknown78[0]=0;self->unknown78[1]=0;self->unknown78[2]=0;self->unknown78[3]=0;self->unknown78[4]=0;self->unknown78[5]=0;self->unknown78[6]=0;self->unknown78[7]=0;self->unknown78[8]=0;
    self->value=w3d_f32_8039dfe4[0];self->timer=0;self->ratio=w3d_f32_8039dfe4[0];
    return self;
}
#endif
int w3d_wind_dispatch_80130320(Ptr32<Wind> self,Ptr32<unsigned short> message) {
    if(*message==64) {
        if(w3d_auto_8015fb34(self,message)>=0) w3d_fn_80130638(self);
        else return 0x80004005;
    } else if(w3d_fn_8015f620(&w3d_obj_804af730,*message)) w3d_wind_set_visible_801315a0(self,0);
    else if(!w3d_fn_8015f620(&w3d_obj_804af738,*message)) return w3d_auto_8015fb34(self,message);
    else w3d_wind_set_visible_801315a0(self,1);
    return 0;
}
void w3d_wind_update_ratio_80130d1c(Ptr32<Wind> self,int enabled) {
    Gap scratch;
    float previous=self->ratio;
    float ratio=w3d_wind_ratio_80130dd4(self);
    float difference=fabs(ratio-previous);
    self->ratio=ratio;
    if(difference>w3d_f32_8039e15c[0]) {
        w3d_wind_clear_animation_80130f78(self);w3d_wind_animation_80130ed8(self);w3d_wind_digits_80130e24(self);
    }
    if(self->enabled!=enabled) {
        self->enabled=enabled;
        self->start=self->timer-(int)(((w3d_f32_8039e160[0]-self->fraction)*w3d_f32_8039e164[0])/w3d_f32_8039e164[0]);
    }
}
float w3d_wind_ratio_80130dd4(Ptr32<Wind> self) {
    Gap scratch;
    float speed=w3d_auto_80178df0(w3d_empty_80342a74(self->speed));
    return speed/w3d_auto_80178df0(w3d_empty_80342a74(self->maximum));
}
void w3d_wind_digits_80130e24(Ptr32<Wind> self) {
    Gap scratch;
    float speed=w3d_auto_80178df0(w3d_empty_80342a74(self->speed));
    float maximum=w3d_auto_80178df0(w3d_empty_80342a74(self->maximum));
    int value=(int)((speed*w3d_f32_8039e174[0])/maximum+w3d_f32_8039e178[0]);
    Ptr32<Object> digits=w3d_empty_8034380c(self->digits);
    w3d_fn_80189828(digits)[0]=value/10;
    w3d_fn_80189828(digits)[1]=value%10;
}
#if 0 // Excluded after two attempts: two animation argument setup instructions differ.
void w3d_wind_animation_80130ed8(Wind *self) {
    if(!w3d_engine_get_context()->paused) {
        Object *mesh=w3d_empty_80343584(self->mesh);
        float rate=w3d_auto_80178df0(w3d_empty_80342a74(self->rate));
        float ratio=self->ratio;
        float zero=w3d_f32_8039e1b0[0];
        if(ratio>zero) {
            w3d_fn_80181640(mesh,w3d_str_8039e19c,&self->control,1,w3d_f32_8039e1b4[0]/(ratio*rate),zero,zero);
            w3d_mesh_instance_check_control(mesh,self->control,1);
        }
    }
}
#endif
void w3d_wind_clear_animation_80130f78(Ptr32<Wind> self) {
    w3d_mesh_instance_control_3c(w3d_empty_80343584(self->mesh),-1);
    self->control=-1;
}
inline Ptr32<Vec> copyVector(Ptr32<Vec> out,const Vec &value) {out->x=value.x;out->y=value.y;out->z=value.z;return out;}
Vec w3d_wind_direction_80131520(Ptr32<Wind> self) {
    float direction=w3d_auto_80178df0(w3d_empty_80342a74(self->direction));
    Vec value;Gap scratch;value.x=w3d_fn_802e86d4(direction);value.y=w3d_f32_8039e1ec[0];value.z=w3d_fn_802e88ac(direction);
    return value;
}
void w3d_wind_set_visible_801315a0(Ptr32<Wind> self,int visible) {
    ((Ptr32<void (Ptr32<Object>, int)>)self->mesh->vtable[22])(self->mesh,visible);
    ((Ptr32<void (Ptr32<Object>, int)>)self->digits->vtable[22])(self->digits,visible);
    ((Ptr32<void (Ptr32<Object>, int)>)self->other->vtable[22])(self->other,visible);
}
Ptr32<Message> w3d_motion_message_construct_80131a84(Ptr32<Message> self) {
    self->id=w3d_cached_message_id(&w3d_obj_804af7a0,1);self->vtable=w3d_obj_8040db38;
    w3d_actor_method_member_initialize(self->member);
    self->zero=0;
    float zero=w3d_f32_8039e27c[0];
    self->time=60;self->position=Vec(zero,zero,zero);
    self->velocity=Vec(zero,zero,zero);
    self->target=-1;self->value=zero;self->amount=zero;return self;
}
}



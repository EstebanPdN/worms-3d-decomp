#include "w3d_ptr.h"
#line 1 "s1_debris_motion.cpp"
/* Observed debris fading and collision normal selection. */
extern "C" {
struct W3dS1DebrisVec {float x,y,z;};
struct W3dS1Debris {char unknown[52];W3dS1DebrisVec scale;char unknown40[28];unsigned int stamp;};
struct W3dS1DebrisMessage {unsigned short id,reserved;Ptr32<void> vtable;};
extern Ptr32<void> w3d_queue_804b1754;
extern unsigned int w3d_message_804ad5d4;
extern int w3d_ready_804b1784;
extern unsigned char w3d_vtable_8040db38[];
extern W3dS1DebrisVec w3d_normal_8043ae38[];
extern const float w3d_f32_8037a090[],w3d_f32_8037a0ec[],w3d_f32_8037a0f0[];
void w3d_empty_800672c0(Ptr32<void>);
void w3d_fn_800672c4(Ptr32<void>);
void w3d_auto_8015fd1c(Ptr32<void>);
Ptr32<W3dS1DebrisMessage> w3d_fn_801613f0(Ptr32<void>,unsigned int);
unsigned int w3d_cached_message_id(Ptr32<void>,int);
void w3d_message_post_current(Ptr32<void>);
void w3d_fn_800bd920(void);
float w3d_fn_802e82c0(float);
int w3d_fn_8006704c(Ptr32<W3dS1Debris> self,unsigned int now)
{
    w3d_empty_800672c0(self);w3d_fn_800672c4(self);
    if(now>self->stamp+20000)w3d_auto_8015fd1c(self);
    else if(now>self->stamp+18000) {
        Ptr32<W3dS1DebrisVec> scale=&self->scale;
        scale->x*=w3d_f32_8037a090[0];scale->y*=w3d_f32_8037a090[0];scale->z*=w3d_f32_8037a090[0];
    }
    return 20;
}
#if 0 /* Excluded: local pointer and floating-point allocation differ after two attempts. */
W3dS1DebrisVec *w3d_fn_80067770(W3dS1DebrisVec *out,void *unused)
{
    W3dS1DebrisVec local;
    W3dS1DebrisMessage *message=w3d_fn_801613f0(w3d_queue_804b1754,8);
    message->id=w3d_cached_message_id(&w3d_message_804ad5d4,1);message->vtable=w3d_vtable_8040db38;
    w3d_message_post_current(message);
    if(!w3d_ready_804b1784)w3d_fn_800bd920();
    W3dS1DebrisVec *normal=&local;
    *normal=w3d_normal_8043ae38[0];
    float length=normal->x*normal->x+normal->y*normal->y+normal->z*normal->z;
    if(length>w3d_f32_8037a0ec[0]) {
        float reciprocal=w3d_f32_8037a0f0[0]/w3d_fn_802e82c0(length);
        float z=normal->z,x=local.x,y=normal->y;
        normal->z=z*reciprocal;local.x=x*reciprocal;normal->y=y*reciprocal;
    } else {normal->z=w3d_f32_8037a0ec[0];local.x=w3d_f32_8037a0ec[0];normal->y=w3d_f32_8037a0f0[0];}
    out->x=local.x;out->y=normal->y;out->z=normal->z;
    return out;
}
#endif
}



#include "w3d_ptr.h"
#line 1 "s1_camera_messages.cpp"
/* Observed falling-camera activation and input group changes. */
extern "C" {
struct W3dS1FallVec {float x,y,z;};
struct W3dS1FallFrame {unsigned int unknown;W3dS1FallVec position,target,up;};
struct W3dS1FallCamera {W3dS1FallFrame frame;char unknown28[36];unsigned int task;};
extern Ptr32<void> w3d_queue_804b1754;
extern unsigned int w3d_message_804ad5e0,w3d_message_804ad5e8;
extern const char w3d_str_8037a11c[],w3d_str_8037a134[],w3d_str_8037a144[],w3d_str_8037a14c[],w3d_str_8037a154[],w3d_str_8037a160[],w3d_str_8037a178[],w3d_str_8037a184[],w3d_str_8037a190[];
void w3d_service_mode_virtual_query(Ptr32<void>,Ptr32<void>);
void w3d_fn_800fc230(Ptr32<Ptr32<const char>>,Ptr32<unsigned int>);
Ptr32<void> w3d_fn_801613f0(Ptr32<void>,unsigned int);
unsigned int w3d_cached_message_id(Ptr32<void>,int);
Ptr32<void> w3d_message_string_init(Ptr32<void>,unsigned short,Ptr32<const char>);
int w3d_message_post_current(Ptr32<void>);
void w3d_fn_80067a04(Ptr32<W3dS1FallCamera> self,Ptr32<W3dS1FallFrame> frame)
{
    struct {Ptr32<const char> key;unsigned int pad;} local;
    w3d_service_mode_virtual_query(self,frame);
    local.key=w3d_str_8037a11c;w3d_fn_800fc230(&local.key,&self->task);
    self->frame.position=frame->position;self->frame.target=frame->target;self->frame.up=frame->up;
    Ptr32<void> message0=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id0=w3d_cached_message_id(&w3d_message_804ad5e8,1);
    w3d_message_post_current(w3d_message_string_init(message0,id0,w3d_str_8037a134));
    Ptr32<void> message1=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id1=w3d_cached_message_id(&w3d_message_804ad5e0,1);
    w3d_message_post_current(w3d_message_string_init(message1,id1,w3d_str_8037a144));
    Ptr32<void> message2=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id2=w3d_cached_message_id(&w3d_message_804ad5e0,1);
    w3d_message_post_current(w3d_message_string_init(message2,id2,w3d_str_8037a14c));
    Ptr32<void> message3=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id3=w3d_cached_message_id(&w3d_message_804ad5e0,1);
    w3d_message_post_current(w3d_message_string_init(message3,id3,w3d_str_8037a154));
    Ptr32<void> message4=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id4=w3d_cached_message_id(&w3d_message_804ad5e0,1);
    w3d_message_post_current(w3d_message_string_init(message4,id4,w3d_str_8037a160));
    Ptr32<void> message5=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id5=w3d_cached_message_id(&w3d_message_804ad5e0,1);
    w3d_message_post_current(w3d_message_string_init(message5,id5,w3d_str_8037a178));
    Ptr32<void> message6=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id6=w3d_cached_message_id(&w3d_message_804ad5e0,1);
    w3d_message_post_current(w3d_message_string_init(message6,id6,w3d_str_8037a184));
    Ptr32<void> message7=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id7=w3d_cached_message_id(&w3d_message_804ad5e0,1);
    w3d_message_post_current(w3d_message_string_init(message7,id7,w3d_str_8037a190));
}
}



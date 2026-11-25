#include "w3d_ptr.h"
#line 1 "cc37a_binder_activate_800eeadc.cpp"

// Partial turn/binder views. Config flags are byte-wide; message keys truncate
// to sixteen bits. Preserve immediate notification before delayed notification.
struct cc37a_State {unsigned char unknown[28];Ptr32<void> resource;};
struct cc37a_Config {unsigned char unknown[52];int delay;unsigned char gap56[96];unsigned char flag152,flag153;unsigned char gap154[346];int mode;};
struct cc37a_Context {unsigned char unknown[52];int time;};
struct cc37a_Worm {unsigned char unknown[80];unsigned char position[12];};
struct cc37a_Message {unsigned short key,reserved;Ptr32<void> type;};
extern const char cc37a_active_8038bd9c[];
extern unsigned cc37a_key_804af01c[2],cc37a_key_804aeff4[2];
extern unsigned char cc37a_type_8040db38[];
extern Ptr32<void> cc37a_pool_804b1754;
extern "C" Ptr32<void> cc37a_touch_80341584(Ptr32<void>);
extern "C" Ptr32<cc37a_Config> cc37a_config_801797b4(Ptr32<void>);
extern "C" Ptr32<cc37a_Context> cc37a_context_80165254();
extern "C" int cc37a_read_800fc1f0(Ptr32<Ptr32<const char>>,Ptr32<int>);
extern "C" Ptr32<cc37a_Worm> cc37a_worm_800fc6dc(int);
extern "C" int cc37a_notify_800fdc80(unsigned char,unsigned char,Ptr32<void>,int,int,int);
extern "C" void cc37a_first_800eedc8(Ptr32<cc37a_State>),cc37a_second_800ef568(Ptr32<cc37a_State>);
extern "C" Ptr32<void> cc37a_alloc_801613f0(Ptr32<void>,unsigned);
extern "C" unsigned cc37a_cached_8015f5a0(Ptr32<void>,int);
extern "C" int cc37a_post_8016239c(Ptr32<void>);
extern "C" int cc37a_delay_800c53a0(Ptr32<void>,int);
extern "C" void cc37a_binder_activate_800eeadc(Ptr32<cc37a_State> self){Ptr32<cc37a_Config> config=cc37a_config_801797b4((Ptr32<void>)cc37a_touch_80341584(self->resource));
 if(config->flag153)goto notify;
 if(!config->flag152)goto dispatch;
 notify:{
  Ptr32<const char> key=cc37a_active_8038bd9c;int index;cc37a_read_800fc1f0(&key,&index);
  Ptr32<cc37a_Worm> worm=cc37a_worm_800fc6dc(index);
  cc37a_notify_800fdc80(config->flag153,config->flag152,worm->position,500,-1,-1);
 }
 dispatch:if(config->mode)cc37a_second_800ef568(self);else cc37a_first_800eedc8(self);
 Ptr32<cc37a_Message> message=(Ptr32<cc37a_Message>)cc37a_alloc_801613f0(cc37a_pool_804b1754,8);
 message->key=cc37a_cached_8015f5a0(cc37a_key_804af01c,1);message->type=cc37a_type_8040db38;cc37a_post_8016239c(message);
 Ptr32<cc37a_Message> delayed=(Ptr32<cc37a_Message>)cc37a_alloc_801613f0(cc37a_pool_804b1754,8);
 delayed->key=cc37a_cached_8015f5a0(cc37a_key_804aeff4,1);delayed->type=cc37a_type_8040db38;
 cc37a_delay_800c53a0(delayed,cc37a_context_80165254()->time+config->delay);
}



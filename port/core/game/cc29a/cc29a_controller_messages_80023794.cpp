#include "w3d_ptr.h"
#line 1 "cc29a_controller_messages_80023794.cpp"
// Original cached message-id dispatch; preserve full-width status and property comparisons.
struct cc29a_Controller_80023794 {unsigned char unknown[48];Ptr32<void> property;};
struct cc29a_Message_80023794 {unsigned short id;};
extern unsigned cc29a_cache_804aca54,cc29a_cache_804aca5c,cc29a_cache_804aca64,cc29a_cache_804aca74,cc29a_cache_804aca6c,cc29a_cache_804aca84,cc29a_cache_804aca7c;
extern "C" {int cc29a_base_8015fb34(Ptr32<void>,Ptr32<void>);void cc29a_start_80023944(Ptr32<void>);void cc29a_stop_800243a4(Ptr32<void>);int cc29a_equals_8015f65c(unsigned short,Ptr32<unsigned int>);
void cc29a_set_80024844(Ptr32<void>,int,int);void cc29a_refresh_800248f8(Ptr32<void>);void cc29a_delay_80024990(Ptr32<void>,int,int);int cc29a_read_80178c48(Ptr32<void>);int cc29a_value_800a830c(Ptr32<void>);void cc29a_clear_80024448(Ptr32<void>);}
extern "C" int cc29a_controller_messages_80023794(Ptr32<cc29a_Controller_80023794> self,Ptr32<cc29a_Message_80023794> message){
 unsigned short id=message->id;
 switch(id){case 64:if(cc29a_base_8015fb34(self,message)>=0){cc29a_start_80023944(self);return 0;}return 0x80004005;case 66:cc29a_stop_800243a4(self);break;
 default:
 if(cc29a_equals_8015f65c(id,&cc29a_cache_804aca54))cc29a_set_80024844(self,0,0);
 else if(cc29a_equals_8015f65c(id,&cc29a_cache_804aca5c))cc29a_set_80024844(self,0,1);
 else if(cc29a_equals_8015f65c(id,&cc29a_cache_804aca64)||cc29a_equals_8015f65c(id,&cc29a_cache_804aca74))cc29a_refresh_800248f8(self);
 else if(cc29a_equals_8015f65c(id,&cc29a_cache_804aca6c))cc29a_set_80024844(self,1,0);
 else if(cc29a_equals_8015f65c(id,&cc29a_cache_804aca84)){cc29a_set_80024844(self,0,0);cc29a_delay_80024990(self,60,0);}
 else if(cc29a_equals_8015f65c(id,&cc29a_cache_804aca7c)){int value=cc29a_read_80178c48(self->property);if(value==cc29a_value_800a830c(message)){cc29a_clear_80024448(self);cc29a_set_80024844(self,0,0);}}
 }
 return cc29a_base_8015fb34(self,message);
}



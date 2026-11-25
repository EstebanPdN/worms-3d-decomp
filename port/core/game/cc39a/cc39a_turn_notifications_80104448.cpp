#include "w3d_ptr.h"
#line 1 "cc39a_turn_notifications_80104448.cpp"
// One-shot turn transition notifications; names inferred from original call order.
struct cc39a_Runtime{unsigned char unknown[64];int notified;};
struct cc39a_Message{unsigned short type;unsigned short unknown;Ptr32<const void> vtable;};
struct cc39a_Key{unsigned data[2];};struct cc39a_Allocator;
extern Ptr32<cc39a_Allocator> cc39a_allocator_804b1754;
extern cc39a_Key cc39a_worm_804af1c8,cc39a_first_804af1b0,cc39a_second_804af1c0,cc39a_third_804af1d0;
extern const char cc39a_active_803995e8[];
extern const unsigned char cc39a_vtable_8040db38[];
extern "C" {
int cc39a_property_800fc1f0(Ptr32<Ptr32<const char>>,Ptr32<int>);
Ptr32<cc39a_Message> cc39a_allocate_801613f0(Ptr32<cc39a_Allocator>,unsigned);
unsigned cc39a_id_8015f5a0(Ptr32<cc39a_Key>,int);
Ptr32<cc39a_Message> cc39a_initInt_800a82f0(Ptr32<cc39a_Message>,unsigned short,int);
int cc39a_post_8016239c(Ptr32<cc39a_Message>);
void cc39a_firstAction_8002addc(Ptr32<cc39a_Runtime>);void cc39a_secondAction_8002ae70(Ptr32<cc39a_Runtime>);
}
extern "C" void cc39a_turn_notifications_80104448(Ptr32<cc39a_Runtime> self){
 if(!self->notified){
  self->notified=1;Ptr32<const char> key=cc39a_active_803995e8;int index;
  cc39a_property_800fc1f0(&key,&index);
  {Ptr32<cc39a_Message> message=cc39a_allocate_801613f0(cc39a_allocator_804b1754,12);
  cc39a_post_8016239c(cc39a_initInt_800a82f0(message,(unsigned short)cc39a_id_8015f5a0(&cc39a_worm_804af1c8,1),index));}
  {Ptr32<cc39a_Message> message=cc39a_allocate_801613f0(cc39a_allocator_804b1754,8);
  message->type=cc39a_id_8015f5a0(&cc39a_first_804af1b0,1);message->vtable=cc39a_vtable_8040db38;cc39a_post_8016239c(message);}
  {Ptr32<cc39a_Message> message=cc39a_allocate_801613f0(cc39a_allocator_804b1754,8);
  message->type=cc39a_id_8015f5a0(&cc39a_second_804af1c0,1);message->vtable=cc39a_vtable_8040db38;cc39a_post_8016239c(message);}
  {Ptr32<cc39a_Message> message=cc39a_allocate_801613f0(cc39a_allocator_804b1754,8);
  message->type=cc39a_id_8015f5a0(&cc39a_third_804af1d0,1);message->vtable=cc39a_vtable_8040db38;cc39a_post_8016239c(message);}
  cc39a_firstAction_8002addc(self);cc39a_secondAction_8002ae70(self);
 }
}



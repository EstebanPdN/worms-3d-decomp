#include "w3d_ptr.h"
#line 1 "cc29a_controller_select_level_800252c8.cpp"
// Original selector messages and eight-byte notification ownership.
struct cc29a_Message_800252c8 {unsigned short id,unknown;Ptr32<void> table;};
extern unsigned cc29a_cache_804aca9c,cc29a_cache_804acaac,cc29a_cache_804acab4,cc29a_cache_804acabc,cc29a_cache_804acac4,cc29a_cache_804acacc,cc29a_cache_804acaa4;
extern char cc29a_table_8040db38[];extern Ptr32<void> cc29a_allocator_804b1754;
extern "C" {int cc29a_base_8015fb34(Ptr32<void>,Ptr32<void>);void cc29a_start_8002547c(Ptr32<void>);int cc29a_equals_8015f65c(unsigned short,Ptr32<unsigned int>);unsigned cc29a_current_800255e0(Ptr32<void>);void cc29a_set_8002557c(Ptr32<void>,unsigned);Ptr32<void> cc29a_alloc_801613f0(Ptr32<void>,unsigned);unsigned short cc29a_id_8015f5a0(Ptr32<unsigned int>,int);int cc29a_post_8016239c(Ptr32<void>);}
inline void cc29a_notify_800252c8(){Ptr32<cc29a_Message_800252c8> m=(Ptr32<cc29a_Message_800252c8>)cc29a_alloc_801613f0(cc29a_allocator_804b1754,8);m->id=cc29a_id_8015f5a0(&cc29a_cache_804acaa4,1);m->table=cc29a_table_8040db38;cc29a_post_8016239c(m);}
extern "C" int cc29a_controller_select_level_800252c8(Ptr32<void> self,Ptr32<cc29a_Message_800252c8> message){
 unsigned short id=message->id;if(id==64){if(cc29a_base_8015fb34(self,message)>=0){cc29a_start_8002547c(self);return 0;}return 0x80004005;}
 if(cc29a_equals_8015f65c(id,&cc29a_cache_804aca9c)){unsigned current=cc29a_current_800255e0(self);cc29a_set_8002557c(self,current<5?current+1:1);cc29a_notify_800252c8();}
 else if(cc29a_equals_8015f65c(id,&cc29a_cache_804acaac)){cc29a_set_8002557c(self,1);cc29a_notify_800252c8();}
 else if(cc29a_equals_8015f65c(id,&cc29a_cache_804acab4)){cc29a_set_8002557c(self,2);cc29a_notify_800252c8();}
 else if(cc29a_equals_8015f65c(id,&cc29a_cache_804acabc)){cc29a_set_8002557c(self,3);cc29a_notify_800252c8();}
 else if(cc29a_equals_8015f65c(id,&cc29a_cache_804acac4)){cc29a_set_8002557c(self,4);cc29a_notify_800252c8();}
 else if(cc29a_equals_8015f65c(id,&cc29a_cache_804acacc)){cc29a_set_8002557c(self,5);cc29a_notify_800252c8();}
 return cc29a_base_8015fb34(self,message);
}



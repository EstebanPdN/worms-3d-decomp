#include "w3d_ptr.h"
#line 1 "cc28a_planner_update_gates_80020b44.cpp"
// Observed planner update gates and message ownership; field meanings inferred.
struct cc28a_Planner_80020b44 {unsigned char unknown[20];Ptr32<void> target;unsigned int unknown24;Ptr32<void> team;unsigned int unknown32;int notified,started,enabled;unsigned char unknown48[64];Ptr32<void> count; Ptr32<void> registry;};
struct cc28a_Range_80020b44 {unsigned char unknown[72];Ptr32<void> begin; Ptr32<void> end;};
struct cc28a_Message_80020b44 {unsigned short id,pad;Ptr32<void> type;};
extern int cc28a_flag_804aa7a4,cc28a_flag_804aa7a8,cc28a_mode_804aa580,cc28a_state_804aa568,cc28a_wait_804ab3e4;
extern int cc28a_flag_804aa7ac,cc28a_flag_804aa7b0,cc28a_flag_804aa7b4;
extern Ptr32<cc28a_Range_80020b44> cc28a_queue_804b1758;
extern Ptr32<void> cc28a_messages_804b1754;
extern unsigned int cc28a_name_804ac9a0;
extern unsigned char cc28a_type_8040db38[];
extern "C" int cc28a_timer_8006e71c();
extern "C" int cc28a_active_80020834(Ptr32<cc28a_Planner_80020b44>);
extern "C" Ptr32<void> cc28a_property_803426b4(Ptr32<void>);
extern "C" int cc28a_int_80178c48(Ptr32<void>);
extern "C" void cc28a_registry_80007cc4(Ptr32<void>);
extern "C" void cc28a_team_80007b44(int);
extern "C" void cc28a_stop_800063d0();
extern "C" void cc28a_update_80006444();
extern "C" Ptr32<cc28a_Message_80020b44> cc28a_allocate_801613f0(Ptr32<void>,int);
extern "C" unsigned int cc28a_id_8015f5a0(Ptr32<unsigned int>,int);
extern "C" void cc28a_dispatch_8015fc38(Ptr32<cc28a_Message_80020b44>,Ptr32<void>,int);
inline bool cc28a_mode_present_80020b44(){if(cc28a_mode_804aa580==-1)return false;return true;}
extern "C" int cc28a_planner_update_gates_80020b44(Ptr32<cc28a_Planner_80020b44> self){
 if(!cc28a_timer_8006e71c() && !cc28a_flag_804aa7a4 && cc28a_active_80020834(self) && self->enabled && !cc28a_flag_804aa7a8){
 int count=cc28a_int_80178c48(cc28a_property_803426b4(self->count));
 int limit=1;if(cc28a_mode_present_80020b44())limit=2;
 if(count<=limit && cc28a_queue_804b1758->begin==cc28a_queue_804b1758->end && cc28a_wait_804ab3e4==0){
  int zero=cc28a_wait_804ab3e4;
  cc28a_flag_804aa7ac=zero;cc28a_flag_804aa7b0=zero;cc28a_flag_804aa7b4=zero;
  if(!self->started){
   int team=cc28a_int_80178c48(cc28a_property_803426b4(self->team));
   cc28a_registry_80007cc4(self->registry);cc28a_team_80007b44(team);cc28a_stop_800063d0();self->started=1;
  }else if(cc28a_state_804aa568==7){
   int old=self->notified;self->notified=1;
   if(!old){
    Ptr32<cc28a_Message_80020b44> msg=cc28a_allocate_801613f0(cc28a_messages_804b1754,8);
    msg->id=cc28a_id_8015f5a0(&cc28a_name_804ac9a0,1);msg->type=cc28a_type_8040db38;
    cc28a_dispatch_8015fc38(msg,self->target,0);
   }
  }else cc28a_update_80006444();
 }else{
  if(count>limit && !cc28a_flag_804aa7ac)cc28a_flag_804aa7ac=1;
  if(cc28a_wait_804ab3e4 && !cc28a_flag_804aa7b4)cc28a_flag_804aa7b4=1;
  if(cc28a_queue_804b1758->begin==cc28a_queue_804b1758->end && !cc28a_flag_804aa7b0)cc28a_flag_804aa7b0=1;
 }
 }
 return 20;
}



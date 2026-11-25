#include "w3d_ptr.h"
#line 1 "cc27a_planner_action_tick_80022850.cpp"
// Original active action queue tick, including immediate removal and next activation.
struct cc27a_Action2850;
struct cc27a_Dispatch2850 {char unknown[16];Ptr32<void (Ptr32<cc27a_Action2850>, Ptr32<void>)> tick;};
struct cc27a_Action2850 {unsigned int unknown;int complete,started;unsigned int unknown12;Ptr32<cc27a_Dispatch2850> dispatch;};
extern "C" Ptr32<void> cc27a_copy_802eee50(Ptr32<void>,Ptr32<const void>,unsigned int,...);
struct cc27a_Range2850 {Ptr32<Ptr32<cc27a_Action2850>> begin; Ptr32<Ptr32<cc27a_Action2850>> end; Ptr32<Ptr32<cc27a_Action2850>> limit;
 unsigned int size()const{return ((unsigned int)w3d::H(end)-(unsigned int)w3d::H(begin))>>2;}
 static void erase(Ptr32<Ptr32<cc27a_Action2850>> destination,Ptr32<Ptr32<cc27a_Action2850>> next,Ptr32<Ptr32<cc27a_Action2850>> end){cc27a_copy_802eee50(destination,next,(Ptr32<char>)end-(Ptr32<char>)destination);}
 void pop(){if(begin+1!=end)erase(begin,begin+1,end-1);--end;}
};
struct cc27a_Planner2850 {char unknown[28];cc27a_Range2850 actions;};
extern Ptr32<void> cc27a_owner_804b1760;
extern "C" int cc27a_timer_8006e71c();
extern "C" int cc27a_team_80020834(Ptr32<void>);
extern "C" void cc27a_reset_80022634(Ptr32<cc27a_Planner2850>);
extern "C" void cc27a_activate_80022704(Ptr32<cc27a_Planner2850>);
extern "C" int cc27a_planner_action_tick_80022850(Ptr32<cc27a_Planner2850> self,Ptr32<void> context){
 if(cc27a_timer_8006e71c())return 20;
 if(cc27a_owner_804b1760 && !cc27a_team_80020834(cc27a_owner_804b1760))cc27a_reset_80022634(self);
 if(self->actions.size()){
  if((*self->actions.begin)->complete==1){self->actions.pop();if(self->actions.size())cc27a_activate_80022704(self);}
  if(self->actions.size()){
   if(!(*self->actions.begin)->started)cc27a_activate_80022704(self);
   Ptr32<cc27a_Action2850> action=*self->actions.begin;action->dispatch->tick(action,context);
  }
 }
 return 20;
}


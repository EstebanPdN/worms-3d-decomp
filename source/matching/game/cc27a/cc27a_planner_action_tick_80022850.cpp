// Original active action queue tick, including immediate removal and next activation.
struct cc27a_Action2850;
struct cc27a_Dispatch2850 {char unknown[16];void (*tick)(cc27a_Action2850*,void*);};
struct cc27a_Action2850 {unsigned int unknown;int complete,started;unsigned int unknown12;cc27a_Dispatch2850 *dispatch;};
extern "C" void *cc27a_copy_802eee50(void*,const void*,unsigned int,...);
struct cc27a_Range2850 {cc27a_Action2850 **begin,**end,**limit;
 unsigned int size()const{return ((unsigned int)end-(unsigned int)begin)>>2;}
 static void erase(cc27a_Action2850 **destination,cc27a_Action2850 **next,cc27a_Action2850 **end){cc27a_copy_802eee50(destination,next,(char*)end-(char*)destination);}
 void pop(){if(begin+1!=end)erase(begin,begin+1,end-1);--end;}
};
struct cc27a_Planner2850 {char unknown[28];cc27a_Range2850 actions;};
extern void *cc27a_owner_804b1760;
extern "C" int cc27a_timer_8006e71c();
extern "C" int cc27a_team_80020834(void*);
extern "C" void cc27a_reset_80022634(cc27a_Planner2850*);
extern "C" void cc27a_activate_80022704(cc27a_Planner2850*);
extern "C" int cc27a_planner_action_tick_80022850(cc27a_Planner2850*self,void*context){
 if(cc27a_timer_8006e71c())return 20;
 if(cc27a_owner_804b1760 && !cc27a_team_80020834(cc27a_owner_804b1760))cc27a_reset_80022634(self);
 if(self->actions.size()){
  if((*self->actions.begin)->complete==1){self->actions.pop();if(self->actions.size())cc27a_activate_80022704(self);}
  if(self->actions.size()){
   if(!(*self->actions.begin)->started)cc27a_activate_80022704(self);
   cc27a_Action2850*action=*self->actions.begin;action->dispatch->tick(action,context);
  }
 }
 return 20;
}
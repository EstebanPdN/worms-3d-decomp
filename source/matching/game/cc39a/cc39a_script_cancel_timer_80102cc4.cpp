// CancelTimer binding; views cover only witnessed fields, not complete classes.
struct cc39a_Lua;
struct cc39a_Timer{unsigned char unknown[8];int id;unsigned char unknown12[16];int cancelled;};
struct cc39a_Timers{cc39a_Timer** begin;cc39a_Timer** end;cc39a_Timer** capacity;unsigned size()const{return end-begin;}cc39a_Timer* at(unsigned i)const{return *(cc39a_Timer**)((char*)begin+(i<<2));}};
struct cc39a_Runtime{unsigned char unknown[68];cc39a_Lua* state;unsigned char gap72[312];cc39a_Timers timers;};
extern const char cc39a_countError_80398fe8[],cc39a_typeError_80399020[];
extern "C" {
int cc39a_top_802cd7f4(cc39a_Lua*);int cc39a_isnumber_802cda9c(cc39a_Lua*,int);float cc39a_number_802cdc5c(cc39a_Lua*,int);
void cc39a_report_801022ec(cc39a_Runtime*,const char*);void cc39a_settop_802cd808(cc39a_Lua*,int);void cc39a_cancel_80060050(cc39a_Timer*,int);
}
extern "C" int cc39a_script_cancel_timer_80102cc4(cc39a_Runtime* self){
 int count=cc39a_top_802cd7f4(self->state);
 if(count!=1){cc39a_report_801022ec(self,cc39a_countError_80398fe8);cc39a_settop_802cd808(self->state,-count-1);return 0;}
 if(!cc39a_isnumber_802cda9c(self->state,-1)){cc39a_report_801022ec(self,cc39a_typeError_80399020);cc39a_settop_802cd808(self->state,-2);return 0;}
 int id=(int)cc39a_number_802cdc5c(self->state,-1);
 for(unsigned i=0;i<self->timers.size();++i){
  cc39a_Timer* timer=self->timers.at(i);
  if(!timer->cancelled && timer->id==id)cc39a_cancel_80060050(timer,id);
 }
 cc39a_settop_802cd808(self->state,-2);return 0;
}

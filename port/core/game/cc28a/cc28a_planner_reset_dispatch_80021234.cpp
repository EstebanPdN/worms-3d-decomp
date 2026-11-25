#include "w3d_ptr.h"
#line 1 "cc28a_planner_reset_dispatch_80021234.cpp"
// Registry reset and transient Default action dispatch; original object extent24 observed.
struct cc28a_Action_80021234;
struct cc28a_Table_80021234{unsigned int unknown[5];Ptr32<void (Ptr32<cc28a_Action_80021234>)> activate;};
extern cc28a_Table_80021234 cc28a_table_8040dbe8[];
extern char cc28a_default_8036bba8[];
extern "C" void cc28a_destroy_80021468(Ptr32<cc28a_Action_80021234>,int);
struct cc28a_Action_80021234 {
 unsigned int unknown,zero;int state,kind;Ptr32<cc28a_Table_80021234> table;Ptr32<char> name;
 cc28a_Action_80021234(int value){zero=0;name=cc28a_default_8036bba8;kind=15;state=value;table=cc28a_table_8040dbe8;table->activate(this);}
 ~cc28a_Action_80021234(){cc28a_destroy_80021468(this,0);}
};
struct cc28a_Team_80021234 {unsigned char unknown[48];int state;};
struct cc28a_Service_80021234 {unsigned char unknown[312];int index;Ptr32<Ptr32<cc28a_Team_80021234>> teams;};
struct cc28a_Planner_80021234 {unsigned char unknown[116];Ptr32<void> registry;};
extern Ptr32<cc28a_Service_80021234> cc28a_service_804aa8c8;
extern int cc28a_state_804aa568;
extern "C" void cc28a_clear_80022664(Ptr32<void>);
extern "C" void cc28a_reset_80006694();
inline bool cc28a_is_active_80021234(){if(cc28a_state_804aa568==0)return false;return true;}
extern "C" void cc28a_planner_reset_dispatch_80021234(Ptr32<cc28a_Planner_80021234> self){
 cc28a_clear_80022664(self->registry);
 if(cc28a_is_active_80021234()){
  Ptr32<cc28a_Service_80021234> service=cc28a_service_804aa8c8;
  int state=(*(Ptr32<Ptr32<cc28a_Team_80021234>>)((Ptr32<char>)service->teams+(service->index<<2)))->state;
  if(state==1){cc28a_Action_80021234 action(state);}
  cc28a_reset_80006694();
 }
}



#include "w3d_ptr.h"
#line 1 "cx8b_type_registration_8020ba04.cpp"

struct Cx8bRegistration {unsigned int unknown00;Ptr32<const char> name;int state;Ptr32<void (void)> callback;int priority;Ptr32<void> base;};
extern "C" Cx8bRegistration descriptor_80463330[];
extern "C" char name_803b3160[],base_80463308[];
extern "C" int fn_8020b9c0();
extern "C" void fn_80200af8(Ptr32<Cx8bRegistration>);
extern "C" int state_804b0698;
extern "C" void w3d_cx8b_type_registration_8020ba04(int initialize,int priority) {
 if(priority==0xffff && initialize) {
 Ptr32<Cx8bRegistration> descriptor=descriptor_80463330;
 descriptor->name=name_803b3160;state_804b0698=0;descriptor->state=0;descriptor->callback=(Ptr32<void (void)>)fn_8020b9c0;descriptor->priority=10;descriptor->base=base_80463308;
 fn_80200af8(descriptor);
 }
}





#include "w3d_ptr.h"
#line 1 "cc29b_update_text_8018c3a0.cpp"
// Original GameCube PAL body; semantic names inferred. Layouts are observed source views.
struct cc29b_Controller_8018c3a0 {Ptr32<Ptr32<void>> vtable;};
struct cc29b_Text_8018c3a0 {char unknown[224];int count;int unused;Ptr32<Ptr32<cc29b_Controller_8018c3a0>> controllers;int active;int pad;float time;};
struct cc29b_Result_8018c3a0 {float value;char unknown[12];};
struct cc29b_Manager_8018c3a0 {Ptr32<Ptr32<void>> vtable;};
extern "C" const float lbl_803a7e28[];
extern "C" Ptr32<cc29b_Manager_8018c3a0> lbl_804ab5fc;
extern "C" void fn_8018dc98(Ptr32<cc29b_Text_8018c3a0>);
extern "C" int w3d_cc29b_update_text_8018c3a0(Ptr32<cc29b_Text_8018c3a0> self,float dt){
 bool active=false;Ptr32<Ptr32<cc29b_Controller_8018c3a0>> p=self->controllers;Ptr32<Ptr32<cc29b_Controller_8018c3a0>> end=p+self->count;
 self->time+=dt;
 for(;p!=end;++p){
  ((Ptr32<void (Ptr32<cc29b_Controller_8018c3a0>, float)>)(*p)->vtable[10])(*p,self->time);
  ((Ptr32<void (Ptr32<cc29b_Controller_8018c3a0>)>)(*p)->vtable[9])(*p);
  cc29b_Result_8018c3a0 result;
  ((Ptr32<void (Ptr32<cc29b_Controller_8018c3a0>, Ptr32<cc29b_Result_8018c3a0>)>)(*p)->vtable[11])(*p,&result);
  if(result.value!=lbl_803a7e28[0])active=true;
 }
 if(!active){((Ptr32<void (Ptr32<cc29b_Manager_8018c3a0>, Ptr32<cc29b_Text_8018c3a0>)>)lbl_804ab5fc->vtable[31])(lbl_804ab5fc,self);self->active=0;}
 fn_8018dc98(self);return 0;
}



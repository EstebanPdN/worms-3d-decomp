#include "w3d_ptr.h"
#line 1 "cc39b_session_state_8028dc30.cpp"
// Partial state/controller views. Interface and owner roles inferred from
// observed offsets; all status comparisons use the original signed domain.
struct cc39b_StateContext { unsigned char opaque[116];unsigned int word74; };
struct cc39b_StateMethods { Ptr32<void (void)> opaque[6];Ptr32<void (Ptr32<void>, unsigned int)> activate; };
struct cc39b_StateOwner { unsigned char opaque0[40];Ptr32<cc39b_StateContext> context;unsigned char opaque2c[164];Ptr32<cc39b_StateMethods> methods;unsigned char opaqueD4[12];int phase,deadline,ready; };
struct cc39b_Clock { unsigned char opaque[52];int time; };
extern "C" Ptr32<cc39b_Clock> cc39b_clock_80165254();
extern "C" void cc39b_state_stop_8028d3b8(Ptr32<cc39b_StateOwner>);
extern "C" void cc39b_state_reset_8028d34c(Ptr32<cc39b_StateOwner>);
extern "C" int cc39b_session_state_8028dc30(Ptr32<void>,Ptr32<cc39b_StateOwner> self) {
 if(self->ready==1) {
  if(self->phase==2 || self->phase==5) {
   Ptr32<cc39b_StateContext> context=self->context;
   self->methods->activate((Ptr32<unsigned char>)self+28,context->word74);
   self->phase=3;
  }
  if(self->phase==0) self->phase=1;
  self->deadline=cc39b_clock_80165254()->time+500;
 } else {cc39b_state_stop_8028d3b8(self);cc39b_state_reset_8028d34c(self);}
 return 0;
}



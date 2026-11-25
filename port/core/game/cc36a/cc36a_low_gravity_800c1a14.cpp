#include "w3d_ptr.h"
#line 1 "cc36a_low_gravity_800c1a14.cpp"

// Original 800c1a14 activates low gravity once, posts notifications and emits
// its position effect. Partial views and inferred names; original externals
// remain unowned. Float constants independently decoded from original DOL.
struct cc36a_Gravity {unsigned char unknown[36];int active;};
struct cc36a_Vector {float x,y,z;};
struct cc36a_Message {unsigned short key,reserved;Ptr32<void> type;};
extern const float cc36a_default_8038308c[],cc36a_scale_80383090[];
extern const char cc36a_on_8038304c[],cc36a_multiplier_80383060[],cc36a_effect_80383078[];
extern unsigned char cc36a_type_8040db38[];
extern unsigned int cc36a_cache_804ae684[2],cc36a_cache_804ae694[2];
extern Ptr32<void> cc36a_pool_804b1754;
extern "C" {
int cc36a_read_800fc270(Ptr32<Ptr32<const char>>,Ptr32<float>);
int cc36a_assign_800fc4c8(Ptr32<Ptr32<const char>>,float);
Ptr32<void> cc36a_allocate_801613f0(Ptr32<void>,unsigned int);
unsigned int cc36a_key_8015f5a0(Ptr32<void>,int);
int cc36a_post_8016239c(Ptr32<void>);
Ptr32<void> cc36a_initialize_80125fdc(Ptr32<void>,unsigned short,unsigned int);
// w3d_low_gravity_position_800c1b20 devuelve tres floats triviales (W3dGPoint): en ARM van en s0-s2, no por un puntero
// de salida en r0 como en PowerPC. Con el puntero, la entidad llegaba como &position (basura de la pila) y el efecto
// de la baja gravedad salía en un sitio cualquiera.
cc36a_Vector cc36a_position_800c1b20(Ptr32<cc36a_Gravity>);
unsigned int cc36a_effect_call_800e5ca4(Ptr32<cc36a_Vector>,Ptr32<const char>,int,float);
void cc36a_finish_8015fd1c(Ptr32<cc36a_Gravity>);
void cc36a_low_gravity_800c1a14(Ptr32<cc36a_Gravity> self){
 if(!self->active){
  cc36a_Vector position;
  self->active=1;
  Ptr32<const char> on=cc36a_on_8038304c;
  float value=cc36a_default_8038308c[0];
  cc36a_read_800fc270(&on,&value);
  Ptr32<const char> multiplier=cc36a_multiplier_80383060;
  cc36a_assign_800fc4c8(&multiplier,value);
  Ptr32<cc36a_Message> message=(Ptr32<cc36a_Message>)cc36a_allocate_801613f0(cc36a_pool_804b1754,8);
  message->key=cc36a_key_8015f5a0(cc36a_cache_804ae684,1);message->type=cc36a_type_8040db38;
  cc36a_post_8016239c(message);
  Ptr32<void> next=cc36a_allocate_801613f0(cc36a_pool_804b1754,12);
  unsigned short key=cc36a_key_8015f5a0(cc36a_cache_804ae694,1);
  cc36a_post_8016239c(cc36a_initialize_80125fdc(next,key,44));
  position=cc36a_position_800c1b20(self);
  cc36a_effect_call_800e5ca4(&position,cc36a_effect_80383078,0,cc36a_scale_80383090[0]);
  cc36a_finish_8015fd1c(self);
 }
}
}



#include "w3d_ptr.h"
#line 1 "cc21b_field_manager_sinit_8020797c.cpp"
// Observed descriptor and two arena-handle static constructions.
extern "C" {
extern unsigned int cc21b_descriptor_8045ee24[];
extern char cc21b_name_803ea1f4[];
extern char cc21b_vtable_80419598[];
extern char cc21b_vtable_80411ad8[];
extern char cc21b_name_803b2c90[];
extern char cc21b_name_803b2ca8[];
extern unsigned int cc21b_arena_804b0644[2];
extern unsigned int cc21b_arena_804b064c[2];
void cc21b_factory_80206d54();
Ptr32<void> cc21b_descriptor_ctor_8020fbd0(Ptr32<void>,Ptr32<void>,Ptr32<void>,Ptr32<void (void)>,int,int);
Ptr32<void> cc21b_arena_ctor_802097ec(Ptr32<void>,Ptr32<const char>,int,int);
void w3d_cc21b_field_manager_sinit_8020797c(int init,int priority) {
 if(priority==0xffff && init) {
  Ptr32<unsigned int> p=cc21b_descriptor_8045ee24;
  cc21b_descriptor_ctor_8020fbd0(p,cc21b_name_803ea1f4,p,cc21b_factory_80206d54,7,0);
  p[3]=(unsigned int)w3d::H(cc21b_vtable_80419598);
  p[0]=(unsigned int)w3d::H(cc21b_vtable_80411ad8);
  cc21b_arena_ctor_802097ec(cc21b_arena_804b0644,cc21b_name_803b2c90,0,0);
  cc21b_arena_ctor_802097ec(cc21b_arena_804b064c,cc21b_name_803b2ca8,0,8);
 }
}
}



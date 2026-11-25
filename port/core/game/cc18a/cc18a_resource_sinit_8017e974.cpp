#include "w3d_ptr.h"
#line 1 "cc18a_resource_sinit_8017e974.cpp"
// The table count and descriptor offsets are observed; names are structural.
struct Cc18aDescriptor { Ptr32<void> vtable; unsigned int word4,word8; Ptr32<void> handlers; };
extern "C" unsigned int lbl_80456f14[];
extern "C" Cc18aDescriptor lbl_80457014;
extern "C" char lbl_803e8a1c[],lbl_80419598[],lbl_80411ad8[];
extern "C" void fn_8017b834();
extern "C" Ptr32<void> fn_8020fbd0(Ptr32<void>,Ptr32<void>,Ptr32<void>,Ptr32<void>,int,int);
static inline void initialize(Ptr32<Cc18aDescriptor> p) {
  fn_8020fbd0(p,lbl_803e8a1c,p,(Ptr32<void>)fn_8017b834,7,0);
  p->handlers=lbl_80419598;
  p->vtable=lbl_80411ad8;
}
extern "C" void w3d_cc18a_resource_sinit_8017e974(int init,int priority) {
 if(priority==0xffff && init) {
  Ptr32<unsigned int> p=lbl_80456f14;
  for(int i=64;i!=0;--i) *p++=0;
  initialize(&lbl_80457014);
 }
}



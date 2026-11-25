#include "w3d_ptr.h"
#line 1 "cxb3_transition_801241d0.cpp"
/* Observed transition-message dispatch. Cache objects and service methods remain external. */
extern "C" int fn_8016293c(Ptr32<void>,Ptr32<void>);
extern "C" void fn_801242e0(Ptr32<void>),fn_801243b0(Ptr32<void>),fn_80124424(Ptr32<void>),fn_801244d8(Ptr32<void>),fn_8015fd1c(Ptr32<void>);
extern "C" int fn_8015f620(Ptr32<void>,unsigned short);
struct Cache { unsigned a,b; };
extern struct Cache lbl_804af4f8,lbl_804af4f0,lbl_804af500;
struct Msg {unsigned short id; inline unsigned short get() {return id;} };
extern "C" int cxb3_transition_801241d0(Ptr32<void> self,Ptr32<void> message) {
 unsigned short id=((Ptr32<Msg>)message)->get();
 switch(((Ptr32<Msg>)message)->get()) {
 case 64:
  if(fn_8016293c(self,message)>=0) {
   fn_801242e0(self); return 0;
  } else return 0x80004005;
 case 66: fn_801243b0(self); break;
 default:
  if(fn_8015f620(&lbl_804af4f8,id)) fn_80124424(self);
  else if(fn_8015f620(&lbl_804af4f0,id)) fn_801244d8(self);
  else if(fn_8015f620(&lbl_804af500,id)) fn_8015fd1c(self);
 }
 return fn_8016293c(self,message);
}



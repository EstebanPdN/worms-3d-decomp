#include "w3d_ptr.h"
#line 1 "f5a_refresh_callback_8026fb88.cpp"
// Observed field view; semantic names inferred.
#define F(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char*)w3d::AG(p)+(o)))
extern const float initial_803cbf30[];
extern "C" int fn_802bc71c(Ptr32<void>);
extern "C" int fn_802bc6a8(Ptr32<void>,int);
extern "C" void fn_8015fd1c(Ptr32<void>);
extern "C" void fn_8026f528(Ptr32<void>);
extern "C" void fn_8026f948(Ptr32<void>,int,int);
extern "C" void fn_802bc790(Ptr32<void>,float);
extern "C" void fn_80296410(Ptr32<void>,float);
extern "C" void fn_802700a8(Ptr32<void>);
extern "C" int w3d_f5a_refresh_callback_8026fb88(Ptr32<void>,Ptr32<void> self){
 if(!F(self,int,268)){
 Ptr32<void> context=F(self,void*,40);float value=initial_803cbf30[0];int active=0;
 if(F(context,int,148)==1 && F(self,void*,288)){
 int count=fn_802bc71c(F(self,void*,288));Ptr32<void> box=F(self,void*,288);value=F(box,float,68);
 if(count>1 && fn_802bc6a8(box,count-2)!=-1)active=1;
 }
 fn_8015fd1c(F(self,void*,288));F(self,void*,288)=0;fn_8026f528(self);
 if(F(context,int,148)==1){
 if(active)fn_8026f948(self,fn_802bc71c(F(self,void*,288))-1,1);
 else{fn_802bc790(F(self,void*,288),value);F(self,float,308)=value;F(self,float,312)=value;if(F(self,void*,292))fn_80296410(F(self,void*,292),value);}
 }else fn_802700a8(self);
 }return 0;
}



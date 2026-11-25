// Observed field view; semantic names inferred.
#define F(p,T,o) (*(T*)((char*)(p)+(o)))
extern const float initial_803cbf30[];
extern "C" int fn_802bc71c(void*);
extern "C" int fn_802bc6a8(void*,int);
extern "C" void fn_8015fd1c(void*);
extern "C" void fn_8026f528(void*);
extern "C" void fn_8026f948(void*,int,int);
extern "C" void fn_802bc790(void*,float);
extern "C" void fn_80296410(void*,float);
extern "C" void fn_802700a8(void*);
extern "C" int w3d_f5a_refresh_callback_8026fb88(void*,void*self){
 if(!F(self,int,268)){
 void* context=F(self,void*,40);float value=initial_803cbf30[0];int active=0;
 if(F(context,int,148)==1 && F(self,void*,288)){
 int count=fn_802bc71c(F(self,void*,288));void* box=F(self,void*,288);value=F(box,float,68);
 if(count>1 && fn_802bc6a8(box,count-2)!=-1)active=1;
 }
 fn_8015fd1c(F(self,void*,288));F(self,void*,288)=0;fn_8026f528(self);
 if(F(context,int,148)==1){
 if(active)fn_8026f948(self,fn_802bc71c(F(self,void*,288))-1,1);
 else{fn_802bc790(F(self,void*,288),value);F(self,float,308)=value;F(self,float,312)=value;if(F(self,void*,292))fn_80296410(F(self,void*,292),value);}
 }else fn_802700a8(self);
 }return 0;
}

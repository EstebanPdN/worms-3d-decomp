#include "w3d_ptr.h"
#line 1 "f5a_setup_pointer_8026f6e0.cpp"
#define F(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char*)w3d::AG(p)+(o)))
struct Vec3{float x,y,z;Vec3(float a,float b,float c):x(a),y(b),z(c){} Vec3(const Vec3&v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}};
struct Handle{Ptr32<void> p;Handle(const Handle&h):p(h.p){if(p)(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)(p))[3](p);}template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((void *)w3d_p.get()) {}
 Handle(void*v):p(v){if(p)(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)(p))[3](p);}};
extern char factory_8041c220[];extern Ptr32<void> service_804b178c;
extern const float scale_803cbf1c[],zero_803cbf20[];
extern "C" Ptr32<void> fn_8020b680(Ptr32<void>);
extern "C" int fn_80164514(Ptr32<void>,Ptr32<void>,Ptr32<void>);
extern "C" void fn_80296774(Ptr32<void>,Ptr32<void>);
extern "C" void fn_8029550c(Ptr32<void>,float);
extern "C" void fn_80295468(Ptr32<void>,Vec3);
extern "C" void fn_80296298(Ptr32<void>,int);
extern "C" void fn_8029623c(Ptr32<void>,int);
extern "C" void fn_8029677c(Ptr32<void>,Ptr32<void>);
extern "C" void fn_80296518(Ptr32<void>,Ptr32<void>);
extern "C" void fn_80295268(Ptr32<void>,Handle);
extern "C" void fn_8026ed00(Ptr32<void>);
extern "C" void w3d_f5a_setup_pointer_8026f6e0(Ptr32<void> self){
 if(!F(self,void*,292)){
 Ptr32<void> context=F(self,void*,40);float value=F(self,float,252);
 F(self,void*,292)=fn_8020b680(factory_8041c220);
 fn_80164514(service_804b178c,F(self,void*,292),F(self,void*,20));
 fn_80296774(F(self,void*,292),F(self,void*,32));F(F(self,void*,292),int,216)=F(self,int,28);
 float delta=F(context,float,24)-value;fn_8029550c(F(self,void*,292),delta+delta);
 Vec3 position(F(context,float,20)-value*scale_803cbf1c[0],zero_803cbf20[0],zero_803cbf20[0]);
 fn_80295468(F(self,void*,292),position);
 fn_80296298(F(self,void*,292),F(context,int,156));fn_8029623c(F(self,void*,292),F(context,int,128));
 fn_8029677c(F(self,void*,292),F(self,void*,140));fn_80296518(F(self,void*,292),F(self,void*,176));
 fn_80295268(F(self,void*,292),Handle(F(self,void*,112)));fn_8026ed00(self);
 }
}



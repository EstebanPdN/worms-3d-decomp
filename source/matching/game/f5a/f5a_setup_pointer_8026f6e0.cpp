#define F(p,T,o) (*(T*)((char*)(p)+(o)))
struct Vec3{float x,y,z;Vec3(float a,float b,float c):x(a),y(b),z(c){} Vec3(const Vec3&v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}};
struct Handle{void*p;Handle(const Handle&h):p(h.p){if(p)(*(void(***)(void*))(p))[3](p);}Handle(void*v):p(v){if(p)(*(void(***)(void*))(p))[3](p);}};
extern char factory_8041c220[];extern void*service_804b178c;
extern const float scale_803cbf1c[],zero_803cbf20[];
extern "C" void*fn_8020b680(void*);
extern "C" int fn_80164514(void*,void*,void*);
extern "C" void fn_80296774(void*,void*);
extern "C" void fn_8029550c(void*,float);
extern "C" void fn_80295468(void*,Vec3);
extern "C" void fn_80296298(void*,int);
extern "C" void fn_8029623c(void*,int);
extern "C" void fn_8029677c(void*,void*);
extern "C" void fn_80296518(void*,void*);
extern "C" void fn_80295268(void*,Handle);
extern "C" void fn_8026ed00(void*);
extern "C" void w3d_f5a_setup_pointer_8026f6e0(void*self){
 if(!F(self,void*,292)){
 void*context=F(self,void*,40);float value=F(self,float,252);
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

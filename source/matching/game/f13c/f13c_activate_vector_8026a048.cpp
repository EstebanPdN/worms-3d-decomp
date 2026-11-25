// Callee consumes the retained handle; F13cActivationVec3 uses native by-value copy. Partial layouts inferred.
#define F(p,T,o) (*(T*)((char*)(p)+(o)))
struct F13cActivationVec3{float x,y,z;F13cActivationVec3(const F13cActivationVec3&v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}};
struct F13cActivationHandle{void*p;F13cActivationHandle(const F13cActivationHandle&h):p(h.p){if(p)(*(void(***)(void*))(p))[3](p);}F13cActivationHandle(void*v):p(v){if(p)(*(void(***)(void*))(p))[3](p);}};
extern void*instance_804abb7c;
extern "C" void fn_8026d9a0(void*,F13cActivationHandle);
extern "C" void fn_8026d488(void*,F13cActivationVec3);
extern "C" void fn_8026d5c0(void*,void*);
extern "C" void fn_8026d8e8(void*,int);
inline void invoke(void*p,int slot){(*(void(***)(void*))(p))[slot](p);}
inline void attach(void*p,void*q){(*(void(***)(void*,void*))(p))[24](p,q);}
inline void enable(void*p,int q){(*(void(***)(void*,int))(p))[22](p,q);}
extern "C" void w3d_f13c_activate_vector_8026a048(void*self){
 void*p=F(self,void*,112);if(p){
 if(F(self,void*,216)){attach(p,F(self,void*,216));p=F(self,void*,216);if(p)invoke(p,4);F(self,void*,216)=0;}
 if(F(F(self,void*,40),int,140))enable(F(self,void*,284),1);
 if(!F(self,int,432)){
 fn_8026d9a0(instance_804abb7c,F13cActivationHandle(F(self,void*,112)));
 fn_8026d488(instance_804abb7c,F(F(self,void*,40),F13cActivationVec3,20));F(self,int,432)=1;
 }
 fn_8026d5c0(instance_804abb7c,(char*)self+312);fn_8026d8e8(instance_804abb7c,1);
 }
}

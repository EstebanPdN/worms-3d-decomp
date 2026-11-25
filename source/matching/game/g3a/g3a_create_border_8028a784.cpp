// Only complete four-byte retained handles and twelve-byte vectors are local values.
#define F(p,T,o) (*(T*)((char*)(p)+(o)))
struct G3aHeld {void*p;G3aHeld():p(0){}G3aHeld(const G3aHeld&h):p(h.p){if(p)(*(void(***)(void*))(p))[3](p);}~G3aHeld(){if(p)(*(void(***)(void*))(p))[4](p);}};
struct G3aVec {float x,y,z;G3aVec(float a,float b,float c):x(a),y(b),z(c){}G3aVec(const G3aVec&v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}};
struct G3aKey {const char*p;G3aKey(const char*s):p(s){}};
extern "C" void fn_8028a900(void*),fn_80164514(void*,void*,int),fn_802b310c(void*,float),fn_802b3020(void*,G3aVec),fn_802b30c0(void*,float,float),fn_802b3d04(void*,int,int);
extern "C" G3aHeld fn_802b3c5c(void*,G3aHeld);
extern "C" int fn_800fc1b0(const G3aKey*,G3aHeld*);
extern "C" void*fn_8020b680(void*),*fn_80342a74(void*);
extern "C" float fn_80178df0(void*);
extern unsigned counter_804abb60;extern void*manager_804b178c;extern char class_8041c660[],border_803cfb54[];extern const float zero_803cfb68[];
extern "C" void w3d_g3a_create_border_8028a784(void*self){
 if(!F(self,void*,988))fn_8028a900(self);
 void*border=F(self,void*,992);
 if(!border){
 counter_804abb60+=10;void*created=fn_8020b680(class_8041c660);F(self,void*,992)=created;fn_80164514(manager_804b178c,created,F(self,int,20));
 G3aHeld property;G3aKey key(border_803cfb54);fn_800fc1b0(&key,&property);
 border=F(self,void*,992);fn_802b310c(border,fn_80178df0(fn_80342a74(property.p)));
 float zero=zero_803cfb68[0];G3aVec position(F(self,float,996),F(self,float,1000),zero);fn_802b3020(F(self,void*,992),position);
 fn_802b30c0(F(self,void*,992),zero,zero);fn_802b3d04(F(self,void*,992),1,0);
 fn_802b3c5c(F(self,void*,992),F(self,G3aHeld,988));
 F(self,int,704)=2;
 }
}

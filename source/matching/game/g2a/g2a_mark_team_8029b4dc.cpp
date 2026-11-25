// Only pointer handles and the observed two-word owned descriptor are constructed.
#define F(p,T,o) (*(T*)((char*)(p)+(o)))
struct G2aOwned_80178474 {void*p;unsigned tag;G2aOwned_80178474():p(0),tag(58280){}~G2aOwned_80178474();};
struct G2aHeld {void*p;G2aHeld():p(0){}G2aHeld(void*q):p(q){if(p)(*(void(***)(void*))(p))[3](p);}~G2aHeld(){if(p)(*(void(***)(void*))(p))[4](p);}void assign(void*q){if(q){(*(void(***)(void*))(q))[3](q);if(p)(*(void(***)(void*))(p))[4](p);p=q;}}};
struct G2aKey {const char*p;G2aKey(const char*s):p(s){}};
extern "C" int fn_800fc1b0(const G2aKey&,G2aHeld*),fn_802ef234(const char*,const char*);
extern "C" void*fn_80341584(void*),*fn_80179598(void*,G2aOwned_80178474*);
extern const char name_803d0bf0[];
extern "C" void w3d_g2a_mark_team_8029b4dc(void*,const char*name){
 G2aOwned_80178474 owned;G2aHeld resource;
 if(fn_800fc1b0(G2aKey(name_803d0bf0),&resource)<0)return;
 G2aHeld data;
 {G2aHeld acquired(fn_80179598(fn_80341584(resource.p),&owned));data.assign(acquired.p);}
 if(F(data.p,int,92)){
 if(fn_802ef234(F(data.p,const char*,64),name)==0)F(data.p,int,300)=1;
 else if(fn_802ef234(F(data.p,const char*,144),name)==0)F(data.p,int,312)=1;
 else if(fn_802ef234(F(data.p,const char*,216),name)==0)F(data.p,int,308)=1;
 else if(fn_802ef234(F(data.p,const char*,292),name)==0 || fn_802ef234(F(data.p,const char*,292),name)==0)F(data.p,int,304)=1;
 return;
 }
}

// Native text parameter is consumed; all engine and team-data objects are external views.
#define F(p,T,o) (*(T*)((char*)(p)+(o)))
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
struct G2aStartText {char*p;~G2aStartText(){fn_8020c5c4(this);fn_80341588(this);}unsigned length()const{return *(unsigned short*)(p-4);}};
struct G2aStartKey {const char*p;G2aStartKey(const char*s):p(s){}};
struct G2aStartHeld {void*p;G2aStartHeld():p(0){}~G2aStartHeld(){if(p)(*(void(***)(void*))(p))[4](p);}};
extern "C" int fn_800fc1b0(const G2aStartKey&,G2aStartHeld*),fn_800fc2b0(const G2aStartKey&,const char**),fn_800fc230(const G2aStartKey&,unsigned*),fn_800fc550(const G2aStartKey&,const char*),fn_800fc43c(const G2aStartKey&,int),fn_802ef234(const char*,const char*);
extern "C" void*fn_80341584(void*),*fn_801797b4(void*),*fn_802eefe0(...);
extern void*instance_804abb7c;
extern const char can_803d0ce0[],tip_803d0cf0[],local_803d0d04[],data_803d0bf0[],please_803d0d10[],finished_803d0d20[],generating_803d0d30[],text_803d0d44[],add_803d0d54[];
inline bool teamStatus(void*data,int off){return F(data,int,off)!=0;}
inline bool isGenerating(void*data){return F(data,int,3168)!=0;}
extern "C" void w3d_g2a_game_start_8029d0ec(void*,G2aStartText name){
 if(!name.length()){fn_800fc43c(G2aStartKey(can_803d0ce0),0);return;}
 const char*tip;fn_800fc2b0(G2aStartKey(tip_803d0cf0),&tip);
 int can=0;int add=0;
 if(fn_802ef234(local_803d0d04,name.p)==0){
 G2aStartHeld held;
 if(fn_800fc1b0(G2aStartKey(data_803d0bf0),&held)<0){fn_800fc43c(G2aStartKey(can_803d0ce0),0);return;}
 unsigned worms=0;void*data=fn_801797b4(fn_80341584(held.p));
 if(F(data,unsigned,92)>1){
 int teams[4];fn_802eefe0(teams,0,16);
 switch(F(data,unsigned,92)){
 case 4:add=1;teams[F(data,int,236)]=1;teamStatus(data,256);
 case 3:teams[F(data,int,228)]=1;worms=F(data,unsigned,208);teamStatus(data,180);
 case 2:teams[F(data,int,224)]=1;worms+=F(data,unsigned,136);teamStatus(data,108);
 case 1:teams[F(data,int,152)]=1;worms+=F(data,unsigned,56);teamStatus(data,28);
 }
 if((unsigned)(teams[0]+teams[1]+teams[2]+teams[3])>1)can=1;
 }
 if(!can){fn_800fc2b0(G2aStartKey(please_803d0d10),&tip);can=0;}
 else{
 can=0;
 if(instance_804abb7c && F(instance_804abb7c,void*,68) && !isGenerating(F(instance_804abb7c,void*,68)))can=1;
 unsigned finished=0;fn_800fc230(G2aStartKey(finished_803d0d20),&finished);if(!finished)can=0;
 if(!can)fn_800fc2b0(G2aStartKey(generating_803d0d30),&tip);
 }
 if(worms>15)add=1;
 }
 fn_800fc550(G2aStartKey(text_803d0d44),tip);
 fn_800fc43c(G2aStartKey(can_803d0ce0),can);
 fn_800fc43c(G2aStartKey(add_803d0d54),add);
}

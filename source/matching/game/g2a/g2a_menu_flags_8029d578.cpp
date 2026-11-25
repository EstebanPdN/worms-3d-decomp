#define F(p,T,o) (*(T*)((char*)(p)+(o)))
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
struct G2aMenuText {char*p;~G2aMenuText(){fn_8020c5c4(this);fn_80341588(this);}unsigned length()const{return *(unsigned short*)(p-4);}};
struct G2aMenuDefault_803426b8:G2aMenuText {G2aMenuDefault_803426b8();};
struct G2aMenuFrom_8020bb54:G2aMenuText {G2aMenuFrom_8020bb54(const char*);};
struct G2aMenuKey{const char*p;G2aMenuKey(const char*s):p(s){}};
extern "C" int fn_800fc230(const G2aMenuKey&,unsigned*),fn_800fc2b0(const G2aMenuKey&,const char**),fn_802997fc(void*),fn_80299a94(void*),fn_8029d7b4(void*),fn_8029d89c(void*);
extern "C" void fn_8020c510(G2aMenuText*,const char*,...),fn_8020bd38(G2aMenuText*,const char*),fn_80299b48(void*,G2aMenuFrom_8020bb54,int);
extern const char skill_803d0a54[],worm_803d0a0c[],menuSkill_803d0d7c[],menuAdd_803d0d88[],menuDelete_803d0d90[],menuAccept_803d0d9c[],menuTeam_803d0da8[],menuFlag_803d0db0[];
extern "C" void w3d_g2a_menu_flags_8029d578(void*self){
 unsigned skill=0;fn_800fc230(G2aMenuKey(skill_803d0a54),&skill);
 int team=0,del=0,accept=0;bool add=false;
 int selected=fn_802997fc(self);int exists=fn_80299a94(self);int full=fn_8029d7b4(self);int other=fn_8029d89c(self);if(other)selected=1;
 G2aMenuDefault_803426b8 name;bool five=true;unsigned i=0;
 while(true){++i;fn_8020c510(&name,worm_803d0a0c,i);const char*value;fn_800fc2b0(G2aMenuKey(name.p),&value);fn_8020bd38(&name,value);
 if(!name.length() || *value==' '){five=false;break;}if(i>5)break;}
 if(!selected){add=exists!=0;del=1;team=1;}else if(five)accept=1;
 fn_80299b48(self,G2aMenuFrom_8020bb54(menuSkill_803d0d7c),full!=0);
 fn_80299b48(self,G2aMenuFrom_8020bb54(menuAdd_803d0d88),add);
 fn_80299b48(self,G2aMenuFrom_8020bb54(menuDelete_803d0d90),del);
 fn_80299b48(self,G2aMenuFrom_8020bb54(menuAccept_803d0d9c),accept);
 fn_80299b48(self,G2aMenuFrom_8020bb54(menuTeam_803d0da8),team);
 fn_80299b48(self,G2aMenuFrom_8020bb54(menuFlag_803d0db0),skill);
}

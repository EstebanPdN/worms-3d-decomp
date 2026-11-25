// Partial owner and land settings views inferred from original instructions.
#define F(p,T,o) (*(T*)((char*)(p)+(o)))
typedef int (*F10aLandCount_8026d5c0)(void*);
typedef void*(*F10aLandGet_8026d5c0)(void*,int);
typedef void(*F10aLandRemove_8026d5c0)(void*,void*);
typedef void(*F10aLandRetain_8026d5c0)(void*);
extern "C" void fn_8020c5c0(void*),fn_8020c5c4(void*),fn_80341588(void*);
extern "C" unsigned short *fn_80341884(void*);
struct F10aLandCopy_8026d5c0 {char*p;F10aLandCopy_8026d5c0(const F10aLandCopy_8026d5c0&s){fn_8020c5c0(this);p=s.p;++*fn_80341884(this);}~F10aLandCopy_8026d5c0(){fn_8020c5c4(this);fn_80341588(this);}};
struct F10aLandHeld_8026d5c0{void*p;F10aLandHeld_8026d5c0(const F10aLandHeld_8026d5c0&s):p(s.p){if(p)F(p,F10aLandRetain_8026d5c0*,0)[3](p);}~F10aLandHeld_8026d5c0(){if(p)F(p,F10aLandRetain_8026d5c0*,0)[4](p);}};
extern "C" void fn_8026dbe8(void*),*fn_8020b680(void*);
extern "C" int fn_80164514(void*,void*,unsigned);
extern "C" unsigned fn_8026ce4c(void*);
extern "C" void fn_8020bd38(void*,const char*),fn_800f342c(void*),fn_800f339c(void*),fn_800f2f94(void*,F10aLandCopy_8026d5c0,int),fn_800f3524(void*,F10aLandHeld_8026d5c0,void*);
extern char factory_804103d8[];extern void *root_804b178c;
extern const char pirate_803cbd28[],war_803cbd38[],lunar_803cbcf0[],england_803cbd44[],horror_803cbd54[],arctic_803cbd64[];
extern "C" void w3d_f10a_rebuild_land_8026d5c0(void*self,void*settings){
 if(!F(self,void*,72))fn_8026dbe8(self);
 if(!F(self,void*,68)){void*p=fn_8020b680(factory_804103d8);F(self,void*,68)=p;fn_80164514(root_804b178c,p,F(self,unsigned,20));}
 bool themeChanged=false,changed=false;int category=-1;
 if(F(settings,int,4)!=F(self,int,60)||F(self,int,80)==1){
 F(self,int,60)=F(settings,int,4);F(self,unsigned,64)=fn_8026ce4c(settings);themeChanged=true;changed=true;
 switch(F(self,int,60)){
 case 0:fn_8020bd38((char*)self+56,pirate_803cbd28);category=20;break;
 case 1:fn_8020bd38((char*)self+56,war_803cbd38);category=22;break;
 case 2:fn_8020bd38((char*)self+56,lunar_803cbcf0);category=23;break;
 case 3:fn_8020bd38((char*)self+56,england_803cbd44);category=21;break;
 case 4:fn_8020bd38((char*)self+56,horror_803cbd54);category=19;break;
 case 5:fn_8020bd38((char*)self+56,arctic_803cbd64);category=24;break;
 }
 }else if(fn_8026ce4c(settings)!=F(self,unsigned,64)){changed=true;F(self,unsigned,64)=fn_8026ce4c(settings);}
 if(themeChanged){fn_800f342c(F(self,void*,68));fn_800f339c(F(self,void*,68));fn_800f2f94(F(self,void*,68),F(self,F10aLandCopy_8026d5c0,56),category);}
 if(changed||F(self,int,80)){
 F(self,int,80)=0;
 while(F(F(self,void*,72),F10aLandCount_8026d5c0*,0)[30](F(self,void*,72))){void *list=F(self,void*,72);void**table=F(list,void**,0);void*item=((F10aLandGet_8026d5c0)table[29])(list,0);((F10aLandRemove_8026d5c0)table[24])(list,item);}
 fn_800f342c(F(self,void*,68));fn_800f3524(F(self,void*,68),F(self,F10aLandHeld_8026d5c0,72),settings);
 }
}

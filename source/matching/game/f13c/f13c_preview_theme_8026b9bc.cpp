// Partial editor data-selection and shared-string ownership views.
#define F(p,T,o) (*(T*)((char*)(p)+(o)))
extern "C" void fn_8020c5c4(void*),fn_80341588(void*),fn_8020c5c0(void*),fn_8020bb2c(void*);
extern "C" unsigned short *fn_80341884(void*);
struct F13cSelectHeader {unsigned short refs,length,capacity;void release(){if(!--refs)fn_8020bb2c(this);}};
struct F13cSelectText {
 F13cSelectText(const F13cSelectText &); F13cSelectText() {}char*p;~F13cSelectText(){fn_8020c5c4(this);fn_80341588(this);}unsigned length()const{return *(unsigned short*)(p-4);}void assign(const F13cSelectText&s){++((F13cSelectHeader*)(s.p-6))->refs;((F13cSelectHeader*)(p-6))->release();p=s.p;}};
struct F13cSelectFrom_8020bb54:F13cSelectText{F13cSelectFrom_8020bb54(const char*);};
struct F13cSelectCopy:F13cSelectText{F13cSelectCopy(const F13cSelectText&s){fn_8020c5c0(this);p=s.p;++*fn_80341884(this);}};
struct F13cSelectHeld{void*p;F13cSelectHeld():p(0){}~F13cSelectHeld(){if(p)(*(void(***)(void*))(p))[4](p);}};
struct F13cSelectKey{const char*p;F13cSelectKey(const char*s):p(s){}};
extern "C" int fn_800fc1b0(const F13cSelectKey&,F13cSelectHeld*),fn_802ef234(const char*,const char*);
extern "C" void*fn_80343744(void*),*fn_80341584(void*),*fn_801797b4(void*);
extern "C" F13cSelectText*fn_80179170(void*);
extern "C" void fn_8020c510(void*,const char*,...),fn_8026c0d0(void*,int),fn_8026b9bc(void*),fn_8026a048(void*),fn_8026d8a0(void*),fn_8026b6cc(void*),fn_8026c4dc(void*,int);
extern const char empty_803cba1c[],random_803cba20[],error_803cb850[],type_803667a8[];
extern void*instance_804abb7c;
inline bool isType(void*p,const void*target){while(p!=target){void*next=F(p,void*,20);if(p==next)return false;p=next;}return true;}

struct F13cThemeDefault_803426b8:F13cSelectText{F13cThemeDefault_803426b8();};
struct F13cThemeOwned_80178474{void*p;unsigned tag;F13cThemeOwned_80178474():p(0),tag(58280){}~F13cThemeOwned_80178474();};
struct F13cThemeHeld{
 F13cThemeHeld(const F13cThemeHeld &);void*p;F13cThemeHeld():p(0){}F13cThemeHeld(void*next):p(next){if(p)(*(void(***)(void*))(p))[3](p);}~F13cThemeHeld(){if(p)(*(void(***)(void*))(p))[4](p);}void assign(void*next){if(next){(*(void(***)(void*))(next))[3](next);if(p)(*(void(***)(void*))(p))[4](p);p=next;}}};
extern const char pirate_803cbae0[],war_803cbae8[],lunar_803cbaec[],england_803cbaf4[],horror_803cbafc[],arctic_803cbb04[],day_803cbb0c[],evening_803cbb10[],night_803cbb18[],time_803cb980[];
extern "C" F13cSelectText*fn_8020bd38(F13cSelectText*,const char*);
extern "C" int fn_800fc230(const F13cSelectKey&,unsigned*);
extern "C" void*fn_80179598(void*,F13cThemeOwned_80178474*);
extern "C" void w3d_f13c_preview_theme_8026b9bc(void*self){
 void*context=F(self,void*,40);F13cThemeDefault_803426b8 theme,time;
 switch(F(self,int,316)){
 case 0:fn_8020bd38(&theme,pirate_803cbae0);break;
 case 1:fn_8020bd38(&theme,war_803cbae8);break;
 case 2:fn_8020bd38(&theme,lunar_803cbaec);break;
 case 3:fn_8020bd38(&theme,england_803cbaf4);break;
 case 4:fn_8020bd38(&theme,horror_803cbafc);break;
 case 5:default:fn_8020bd38(&theme,arctic_803cbb04);break;
 }
 unsigned value;fn_800fc230(F13cSelectKey(time_803cb980),&value);
 switch(value){case 0:fn_8020bd38(&time,day_803cbb0c);break;case 1:fn_8020bd38(&time,evening_803cbb10);break;case 2:default:fn_8020bd38(&time,night_803cbb18);break;}
 F13cSelectHeld held;F13cSelectFrom_8020bb54 name(empty_803cba1c);
 if(F(context,F13cSelectText,156).length()){fn_800fc1b0(F13cSelectKey(F(context,F13cSelectText,156).p),&held);name.assign(*fn_80179170(fn_80343744(held.p)));}
 if(name.length()){F13cSelectKey key(name.p);if(fn_800fc1b0(key,&held)>=0){
 int random=fn_802ef234(name.p,random_803cba20)==0;
 if((*(int(***)(void*))(held.p))[6](held.p)==5){void*data=fn_801797b4(fn_80341584(held.p));void*type=(*(void*(***)(void*))(data))[5](data);
 if(isType(type,type_803667a8)){
 F13cThemeOwned_80178474 descriptor;F13cThemeHeld current;
 {F13cThemeHeld acquired(fn_80179598(fn_80341584(held.p),&descriptor));current.assign(acquired.p);}
 if(random==1)F(current.p,F13cSelectText,64).assign(theme);
 F(current.p,F13cSelectText,52).assign(time);
 }
 }
 }}
}

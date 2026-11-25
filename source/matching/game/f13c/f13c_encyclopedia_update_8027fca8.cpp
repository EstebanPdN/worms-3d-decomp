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

extern const char pedcurrent_803cee10[],peddata_803cee1c[],pedprev_803cee30[],pednext_803cee3c[],pedtitle_803cee48[],peddesc_803cee54[],pedimage_803cee60[],pedmovie_803cee6c[],pedfile_803cee78[];
extern "C" int fn_800fc230(const F13cSelectKey&,unsigned*),fn_800fc43c(const F13cSelectKey&,unsigned),fn_800fc550(const F13cSelectKey&,const char*),fn_800fc2b0(const F13cSelectKey&,const char**);
extern "C" F13cSelectText*fn_8020bd38(F13cSelectText*,const char*);
extern "C" void fn_8027ffe0(void*);
extern "C" void w3d_f13c_encyclopedia_update_8027fca8(void*self){
 unsigned current;fn_800fc230(F13cSelectKey(pedcurrent_803cee10),&current);fn_8027ffe0(self);
 fn_800fc43c(F13cSelectKey(pedprev_803cee30),current!=F(self,unsigned,160));
 F13cSelectHeld held;if(fn_800fc1b0(F13cSelectKey(peddata_803cee1c),&held)<0)return;
 void*data=fn_801797b4(fn_80341584(held.p));fn_800fc43c(F13cSelectKey(pednext_803cee3c),current<F(self,unsigned,164));
 void**items=(void**)((char*)F(data,void*,20)+32);
 F13cSelectCopy text(F(items[current],F13cSelectText,40));const char*translated;
 if(text.length()){F13cSelectKey key(text.p);if(fn_800fc2b0(key,&translated)>=0)fn_8020bd38(&text,translated);}
 fn_800fc550(F13cSelectKey(pedtitle_803cee48),text.p);
 text.assign(F(items[current],F13cSelectText,36));
 if(text.length()){F13cSelectKey key(text.p);if(fn_800fc2b0(key,&translated)>=0)fn_8020bd38(&text,translated);}
 fn_800fc550(F13cSelectKey(peddesc_803cee54),text.p);
 text.assign(F(items[current],F13cSelectText,32));fn_800fc550(F13cSelectKey(pedimage_803cee60),text.p);
 text.assign(F(items[current],F13cSelectText,28));
 if(text.length())fn_800fc43c(F13cSelectKey(pedmovie_803cee6c),1);else fn_800fc43c(F13cSelectKey(pedmovie_803cee6c),0);
 fn_800fc550(F13cSelectKey(pedfile_803cee78),text.p);
}

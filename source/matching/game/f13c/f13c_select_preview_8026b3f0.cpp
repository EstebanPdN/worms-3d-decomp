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
extern "C" void w3d_f13c_select_preview_8026b3f0(void*self){
 void*context=F(self,void*,40);F13cSelectHeld held;F13cSelectFrom_8020bb54 name(empty_803cba1c);
 if(F(context,F13cSelectText,156).length()){
  fn_800fc1b0(F13cSelectKey(F(context,F13cSelectText,156).p),&held);
  name.assign(*fn_80179170(fn_80343744(held.p)));
 }
 int standard=1;
 if(name.length()){F13cSelectKey key(name.p);if(fn_800fc1b0(key,&held)>=0&&fn_802ef234(name.p,random_803cba20)&&(*(int(***)(void*))(held.p))[6](held.p)==5){
  void*data=fn_801797b4(fn_80341584(held.p));void*type=(*(void*(***)(void*))(data))[5](data);
  if(isType(type,type_803667a8))standard=0;
  else{{F13cSelectCopy observedCopy(F(context,F13cSelectText,156));}fn_8020c510((char*)self+108,error_803cb850,F(context,F13cSelectText,156).p);}
 }
 }
 if(standard==1){F(self,F13cSelectText,424).assign(name);fn_8026c0d0(self,1);fn_8026b9bc(self);fn_8026a048(self);F(self,int,500)=1;}
 else{void*data=fn_801797b4(fn_80341584(held.p));F(self,F13cSelectText,428).assign(F(data,F13cSelectText,36));fn_8026d8a0(instance_804abb7c);fn_8026b6cc(self);fn_8026b9bc(self);fn_8026c0d0(self,1);fn_8026c4dc(self,0);F(self,int,500)=0;}
}

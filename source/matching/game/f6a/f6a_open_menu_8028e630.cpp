// Partial observed cache, string, global and owner layouts; roles inferred.
struct String{char*text;int unknown;~String();};
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
extern "C" void fn_8020c5c0(void*);struct Header;extern "C" Header*fn_80341884(void*);
extern "C" void fn_8020bb2c(void*);
struct Header{unsigned short refs,length,unknown;};
struct CallerString{char*text;CallerString(const CallerString&o){fn_8020c5c0(this);text=o.text;Header*h=fn_80341884(this);++h->refs;}CallerString&operator=(const CallerString&o){++((Header*)(o.text-6))->refs;Header*h=(Header*)(text-6);if(!--h->refs)fn_8020bb2c(h);text=o.text;return *this;}~CallerString(){fn_8020c5c4(this);fn_80341588(this);}};
struct CacheBase{int prefix[2];~CacheBase();};
struct Cache_8015f704:CacheBase{String name;Cache_8015f704(const char*);};
extern "C" void fn_8015f558(void*,int);
inline String::~String(){fn_8020c5c4(this);fn_80341588(this);}
inline CacheBase::~CacheBase(){fn_8015f558(this,2);}
struct Message;struct Owner{char unknown[20];void*context;char unknown24[40];int state,value;char unknown72[40];CallerString name,base;};struct Global{char unknown[208];int mode;};
extern void*queue_804b1754,*app_804b1788;extern Global*global_804aaabc;extern int depth_804abb5c,count_804abb60;
extern char change_803cfff0[],menu_803d0000[];
extern "C" Message*fn_801613f0(void*,int),*fn_8010a8e0(Message*,unsigned short,const char*);
extern "C" unsigned fn_8015f5a0(Cache_8015f704*,int);
extern "C" void fn_8016239c(Message*),fn_80129878(void*),fn_800fde38(),fn_800a7e14(int,const char*);
inline void post(Cache_8015f704*cache,const CallerString&name){Message*m=fn_801613f0(queue_804b1754,12);fn_8016239c(fn_8010a8e0(m,fn_8015f5a0(cache,1),name.text));}
extern void*service_804b178c;extern char factory_8041c890[];
extern "C" void*fn_8020b680(void*);
extern "C" void fn_80164514(void*,void*,void*),fn_8020bd38(void*,const char*),fn_802c1bd8(void*,CallerString,int,int);
extern "C" void w3d_f6a_open_menu_8028e630(Owner*self,CallerString name,int value,const char*text){
 ++depth_804abb5c;count_804abb60+=6;self->base=name;fn_8020bd38(&self->name,text);self->value=value;
 if(global_804aaabc->mode==7)fn_80129878(app_804b1788);
 void*panel=fn_8020b680(factory_8041c890);fn_80164514(service_804b178c,panel,self->context);
 fn_802c1bd8(panel,name,depth_804abb5c,value);fn_800fde38();
 Cache_8015f704 cache(change_803cfff0);post(&cache,name);self->state=1;
 if(global_804aaabc->mode==7)fn_800a7e14(6,menu_803d0000);
}

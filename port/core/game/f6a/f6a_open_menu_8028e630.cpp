#include "w3d_ptr.h"
#line 1 "f6a_open_menu_8028e630.cpp"
// Partial observed cache, string, global and owner layouts; roles inferred.
struct String{Ptr32<char> text;int unknown;~String();};
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
extern "C" void fn_8020c5c0(Ptr32<void>);struct Header;extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
extern "C" void fn_8020bb2c(Ptr32<void>);
struct Header{unsigned short refs,length,unknown;};
struct CallerString{Ptr32<char> text;CallerString(const CallerString&o){fn_8020c5c0(this);text=o.text;Ptr32<Header> h=fn_80341884(this);++h->refs;}CallerString&operator=(const CallerString&o){++((Ptr32<Header>)(o.text-6))->refs;Ptr32<Header> h=(Ptr32<Header>)(text-6);if(!--h->refs)fn_8020bb2c(h);text=o.text;return *this;}~CallerString(){fn_8020c5c4(this);fn_80341588(this);}};
struct CacheBase{int prefix[2];~CacheBase();};
struct Cache_8015f704:CacheBase{String name __attribute__((aligned(__alignof__(CacheBase))));template <class W3dU> Cache_8015f704(Ptr32<W3dU> w3d_p) : Cache_8015f704((const char *)w3d_p.get()) {}
 Cache_8015f704(const char*);};
extern "C" void fn_8015f558(Ptr32<void>,int);
inline String::~String(){fn_8020c5c4(this);fn_80341588(this);}
inline CacheBase::~CacheBase(){fn_8015f558(this,2);}
struct Message;struct Owner{char unknown[20];Ptr32<void> context;char unknown24[40];int state,value;char unknown72[40];CallerString name,base;};struct Global{char unknown[208];int mode;};
extern Ptr32<void> queue_804b1754; extern Ptr32<void> app_804b1788;extern Ptr32<Global> global_804aaabc;extern int depth_804abb5c,count_804abb60;
extern char change_803cfff0[],menu_803d0000[];
extern "C" Ptr32<Message> fn_801613f0(Ptr32<void>,int); Ptr32<Message> fn_8010a8e0(Ptr32<Message>,unsigned short,Ptr32<const char>);
extern "C" unsigned fn_8015f5a0(Ptr32<Cache_8015f704>,int);
extern "C" void fn_8016239c(Ptr32<Message>),fn_80129878(Ptr32<void>),fn_800fde38(),fn_800a7e14(int,Ptr32<const char>);
inline void post(Ptr32<Cache_8015f704> cache,const CallerString&name){Ptr32<Message> m=fn_801613f0(queue_804b1754,12);fn_8016239c(fn_8010a8e0(m,fn_8015f5a0(cache,1),name.text));}
extern Ptr32<void> service_804b178c;extern char factory_8041c890[];
extern "C" Ptr32<void> fn_8020b680(Ptr32<void>);
extern "C" void fn_80164514(Ptr32<void>,Ptr32<void>,Ptr32<void>),fn_8020bd38(Ptr32<void>,Ptr32<const char>),fn_802c1bd8(Ptr32<void>,CallerString,int,int);
extern "C" void w3d_f6a_open_menu_8028e630(Ptr32<Owner> self,CallerString name,int value,Ptr32<const char> text){
 ++depth_804abb5c;count_804abb60+=6;self->base=name;fn_8020bd38(&self->name,text);self->value=value;
 if(global_804aaabc->mode==7)fn_80129878(app_804b1788);
 Ptr32<void> panel=fn_8020b680(factory_8041c890);fn_80164514(service_804b178c,panel,self->context);
 fn_802c1bd8(panel,name,depth_804abb5c,value);fn_800fde38();
 Cache_8015f704 cache(change_803cfff0);post(&cache,name);self->state=1;
 if(global_804aaabc->mode==7)fn_800a7e14(6,menu_803d0000);
}



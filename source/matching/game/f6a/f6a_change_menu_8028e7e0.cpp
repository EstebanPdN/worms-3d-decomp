// Partial observed cache, string, global and owner layouts; roles inferred.
struct String{char*text;int unknown;};
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
struct CallerString{char*text;~CallerString(){fn_8020c5c4(this);fn_80341588(this);}};
struct Cache_8015f704{int prefix[2];String name;Cache_8015f704(const char*);~Cache_8015f704();};
extern "C" void fn_8015f558(Cache_8015f704*,int);
inline Cache_8015f704::~Cache_8015f704(){fn_8020c5c4(&name);fn_80341588(&name);fn_8015f558(this,2);}
struct Message;struct Owner{char unknown[64];int state;};struct Global{char unknown[208];int mode;};
extern void*queue_804b1754,*app_804b1788;extern Global*global_804aaabc;extern int depth_804abb5c,count_804abb60;
extern char change_803cfff0[],menu_803d0000[];
extern "C" Message*fn_801613f0(void*,int),*fn_8010a8e0(Message*,unsigned short,const char*);
extern "C" unsigned fn_8015f5a0(Cache_8015f704*,int);
extern "C" void fn_8016239c(Message*),fn_80129878(void*),fn_800fde38(),fn_800a7e14(int,const char*);
inline void post(Cache_8015f704*cache,const CallerString&name){Message*m=fn_801613f0(queue_804b1754,12);fn_8016239c(fn_8010a8e0(m,fn_8015f5a0(cache,1),name.text));}
extern "C" void w3d_f6a_change_menu_8028e7e0(Owner*self,CallerString name){
 ++depth_804abb5c;count_804abb60+=6;if(global_804aaabc->mode==7)fn_80129878(app_804b1788);fn_800fde38();
 if(((unsigned short*)name.text)[-2]){Cache_8015f704 cache(change_803cfff0);post(&cache,name);}
 self->state=1;if(global_804aaabc->mode==7)fn_800a7e14(6,menu_803d0000);
}

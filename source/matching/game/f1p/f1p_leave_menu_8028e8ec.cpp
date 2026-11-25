// Partial cache and owner layouts inferred from observed offsets.
struct String {
 String(const String &); String() {}char *text;};
extern "C" void fn_8020c5c4(String*),fn_80341588(String*);
struct Cache_8015f704 {int prefix[2];String name;Cache_8015f704(const char*);~Cache_8015f704();};
extern "C" void fn_8015f558(Cache_8015f704*,int);
inline Cache_8015f704::~Cache_8015f704(){fn_8020c5c4(&name);fn_80341588(&name);fn_8015f558(this,2);}
struct Message{unsigned short id,pad;void *payload;};
struct Owner{char pad[64];int held;};struct Global{char pad[208];int mode;};
extern void *queue_804b1754,*app_804b1788;extern Global *global_804aaabc;extern int depth_804abb5c,count_804abb60;
extern const char name_803d0008[];extern char value_8040db38[];
extern "C" Message *fn_801613f0(void*,int);
extern "C" unsigned fn_8015f5a0(Cache_8015f704*,int);
extern "C" void fn_800a7e14(int,int),fn_801298cc(void*);
extern "C" int fn_8016239c(Message*);
inline void post(Cache_8015f704 *cache){Message*m=fn_801613f0(queue_804b1754,8);m->id=fn_8015f5a0(cache,1);m->payload=value_8040db38;fn_8016239c(m);}
extern "C" void w3d_leave_menu_8028e8ec(Owner*self){Cache_8015f704 cache(name_803d0008);post(&cache);--depth_804abb5c;count_804abb60-=6;self->held=0;if(global_804aaabc->mode==7){fn_800a7e14(6,0);fn_801298cc(app_804b1788);}}

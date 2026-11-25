// Inferred shared-string header and partial lookup result layout.
extern "C" void fn_8020c5c0(void*),fn_8020c5c4(void*),fn_80341588(void*),fn_8020bb2c(void*);
extern "C" unsigned short*fn_80341884(void*);
struct F1pBarrackHeader{unsigned short refs,length,capacity;};
struct F1pBarrackText{char*text;F1pBarrackText(const char*);F1pBarrackText(const F1pBarrackText&o){fn_8020c5c0(this);text=o.text;++*fn_80341884(this);}~F1pBarrackText(){fn_8020c5c4(this);fn_80341588(this);}F1pBarrackText&operator=(const F1pBarrackText&o){F1pBarrackHeader*h=(F1pBarrackHeader*)(o.text-6);++h->refs;h=(F1pBarrackHeader*)(text-6);if(--h->refs==0)fn_8020bb2c(h);text=o.text;return *this;}};
struct F1pBarrackIface{void**table;};struct F1pBarrackHandle{
 F1pBarrackHandle(const F1pBarrackHandle &);F1pBarrackIface*p;F1pBarrackHandle():p(0){}~F1pBarrackHandle(){if(p)((void(*)(F1pBarrackIface*))p->table[4])(p);}};
struct F1pBarrackKey{const char*text;F1pBarrackKey(const char*p):text(p){}};

struct F1pBarrackEntry{char gap[48];unsigned unlocked;void*missions;char gap2[4];const char*name;};
struct F1pBarrackArray{char gap[24];unsigned count;int unknown;F1pBarrackEntry*entries[1];};
struct F1pBarrackData{char gap[24];F1pBarrackArray*teams;};
struct F1pBarrackContext{char gap[188];unsigned flags;};extern F1pBarrackContext*context_804b1788;
extern char barracks_803ceaa0[],current_803cea5c[];
extern "C" void*fn_80341584(F1pBarrackIface*);
extern "C" F1pBarrackData*fn_801797b4(void*);
extern "C" int fn_800fc1b0(F1pBarrackKey*,F1pBarrackHandle*),fn_800fc2b0(F1pBarrackKey*,const char**),fn_802ef234(const char*,const char*),fn_8027be7c(void*,int);
extern "C" F1pBarrackText*fn_8020bd38(F1pBarrackText*,const char*);
extern "C" unsigned w3d_team_unlocked_8027dc5c(void*self,F1pBarrackText name){
 F1pBarrackHandle barracks;F1pBarrackKey lookup(barracks_803ceaa0);unsigned result=0;
 if(fn_800fc1b0(&lookup,&barracks)<0)return 0;
 F1pBarrackData*data=fn_801797b4(fn_80341584(barracks.p));
 if(!((F1pBarrackHeader*)(name.text-6))->length){F1pBarrackKey key(current_803cea5c);const char*text;fn_800fc2b0(&key,&text);fn_8020bd38(&name,text);}
 unsigned count=data->teams->count;F1pBarrackEntry**entries=data->teams->entries;
 unsigned i=0;if(result<count)do{if(fn_802ef234(name.text,entries[i]->name)==0){if(context_804b1788->flags&16)result=fn_8027be7c(self,3)-1;else result=entries[i]->unlocked;break;}++i;}while(i<count);
 return result;
}

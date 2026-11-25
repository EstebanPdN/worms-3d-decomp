// Inferred shared-string header and partial lookup result layout.
extern "C" void fn_8020c5c0(void*),fn_8020c5c4(void*),fn_80341588(void*),fn_8020bb2c(void*);
extern "C" unsigned short*fn_80341884(void*);
struct F7aHeader{unsigned short refs,length,capacity;};
struct F7aText{char*text;F7aText(const char*);F7aText(const F7aText&o){fn_8020c5c0(this);text=o.text;++*fn_80341884(this);}~F7aText(){fn_8020c5c4(this);fn_80341588(this);}F7aText&operator=(const F7aText&o){F7aHeader*h=(F7aHeader*)(o.text-6);++h->refs;h=(F7aHeader*)(text-6);if(--h->refs==0)fn_8020bb2c(h);text=o.text;return *this;}};
struct F7aIface{void**table;};struct F7aHandle{
 F7aHandle(const F7aHandle &);F7aIface*p;F7aHandle():p(0){}~F7aHandle(){if(p)((void(*)(F7aIface*))p->table[4])(p);}};
struct F7aKey{const char*text;F7aKey(const char*p):text(p){}};
struct F7aTeamData{char unknown[32];int skill;F7aText mission;};
extern char failed_803cea20[],temp_803cf080[];
extern "C" int fn_802ef234(const char*,const char*);
extern "C" void fn_8027befc(F7aText*,void*,int,int);
extern "C" int fn_800fc1b0(F7aKey*,F7aHandle*);
extern "C" F7aText*fn_8020bd38(F7aText*,const char*);
extern "C" void*fn_80341584(F7aIface*);
extern "C" F7aTeamData*fn_801797b4(void*);
inline void*operator new(unsigned int,void*p){return p;}
struct F7aSlot{int alignment[2];~F7aSlot(){((F7aHandle*)this)->~F7aHandle();}};
// The observed returned-name storage is reused for the later interface handle.
extern "C" F7aText w3d_f7a_lookup_team_mission_80281924(void*self,int category,int index){
 F7aText key(failed_803cea20);F7aSlot slot;F7aText*name=(F7aText*)&slot;
 fn_8027befc(name,self,category,index);key=*name;name->~F7aText();
 F7aHandle*value=new(&slot)F7aHandle;F7aKey lookup(key.text);
 if(fn_800fc1b0(&lookup,value)<0){fn_8020bd38(&key,failed_803cea20);return key;}
 key=fn_801797b4(fn_80341584(value->p))->mission;
 if(!((F7aHeader*)(key.text-6))->length||fn_802ef234(key.text,failed_803cea20)==0)fn_8020bd38(&key,temp_803cf080);
 return key;
}

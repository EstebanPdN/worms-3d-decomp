#include "w3d_ptr.h"
#line 1 "f7a_lookup_team_mission_80281924.cpp"
// Inferred shared-string header and partial lookup result layout.
extern "C" void fn_8020c5c0(Ptr32<void>),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>),fn_8020bb2c(Ptr32<void>);
extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<void>);
struct F7aHeader{unsigned short refs,length,capacity;};
struct F7aText{Ptr32<char> text;template <class W3dU> F7aText(Ptr32<W3dU> w3d_p) : F7aText((const char *)w3d_p.get()) {}
 F7aText(const char*);F7aText(const F7aText&o){fn_8020c5c0(this);text=o.text;++*fn_80341884(this);}~F7aText(){fn_8020c5c4(this);fn_80341588(this);}F7aText&operator=(const F7aText&o){Ptr32<F7aHeader> h=(Ptr32<F7aHeader>)(o.text-6);++h->refs;h=(Ptr32<F7aHeader>)(text-6);if(--h->refs==0)fn_8020bb2c(h);text=o.text;return *this;}};
struct F7aIface{Ptr32<Ptr32<void>> table;};struct F7aHandle{
 F7aHandle(const F7aHandle &);Ptr32<F7aIface> p;F7aHandle():p(0){}~F7aHandle(){if(p)((Ptr32<void (Ptr32<F7aIface>)>)p->table[4])(p);}};
struct F7aKey{Ptr32<const char> text;template <class W3dU> F7aKey(Ptr32<W3dU> w3d_p) : F7aKey((const char *)w3d_p.get()) {}
 F7aKey(const char*p):text(p){}};
struct F7aTeamData{char unknown[32];int skill;F7aText mission;};
extern char failed_803cea20[],temp_803cf080[];
extern "C" int fn_802ef234(Ptr32<const char>,Ptr32<const char>);
extern "C" void fn_8027befc(Ptr32<F7aText>,Ptr32<void>,int,int);
extern "C" int fn_800fc1b0(Ptr32<F7aKey>,Ptr32<F7aHandle>);
extern "C" Ptr32<F7aText> fn_8020bd38(Ptr32<F7aText>,Ptr32<const char>);
extern "C" Ptr32<void> fn_80341584(Ptr32<F7aIface>);
extern "C" Ptr32<F7aTeamData> fn_801797b4(Ptr32<void>);
inline void*operator new(__SIZE_TYPE__,void*p){return p;}
struct F7aSlot{int alignment[2];~F7aSlot(){((Ptr32<F7aHandle>)this)->~F7aHandle();}};
// The observed returned-name storage is reused for the later interface handle.
extern "C" F7aText w3d_f7a_lookup_team_mission_80281924(Ptr32<void> self,int category,int index){
 F7aText key(failed_803cea20);F7aSlot slot;Ptr32<F7aText> name=(Ptr32<F7aText>)&slot;
 fn_8027befc(name,self,category,index);key=*name;name->~F7aText();
 Ptr32<F7aHandle> value=new(&slot)F7aHandle;F7aKey lookup(key.text);
 if(fn_800fc1b0(&lookup,value)<0){fn_8020bd38(&key,failed_803cea20);return key;}
 key=fn_801797b4(fn_80341584(value->p))->mission;
 if(!((Ptr32<F7aHeader>)(key.text-6))->length||fn_802ef234(key.text,failed_803cea20)==0)fn_8020bd38(&key,temp_803cf080);
 return key;
}



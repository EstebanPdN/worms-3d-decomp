#include "w3d_ptr.h"
#line 1 "f1p_team_mission_count_8027dacc.cpp"
// Inferred shared-string header and partial lookup result layout.
extern "C" void fn_8020c5c0(Ptr32<void>),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>),fn_8020bb2c(Ptr32<void>);
extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<void>);
struct F1pMissionCountHeader{unsigned short refs,length,capacity;};
struct F1pMissionCountText{Ptr32<char> text;template <class W3dU> F1pMissionCountText(Ptr32<W3dU> w3d_p) : F1pMissionCountText((const char *)w3d_p.get()) {}
 F1pMissionCountText(const char*);F1pMissionCountText(const F1pMissionCountText&o){fn_8020c5c0(this);text=o.text;++*fn_80341884(this);}~F1pMissionCountText(){fn_8020c5c4(this);fn_80341588(this);}F1pMissionCountText&operator=(const F1pMissionCountText&o){Ptr32<F1pMissionCountHeader> h=(Ptr32<F1pMissionCountHeader>)(o.text-6);++h->refs;h=(Ptr32<F1pMissionCountHeader>)(text-6);if(--h->refs==0)fn_8020bb2c(h);text=o.text;return *this;}};
struct F1pMissionCountIface{Ptr32<Ptr32<void>> table;};struct F1pMissionCountHandle{
 F1pMissionCountHandle(const F1pMissionCountHandle &);Ptr32<F1pMissionCountIface> p;F1pMissionCountHandle():p(0){}~F1pMissionCountHandle(){if(p)((Ptr32<void (Ptr32<F1pMissionCountIface>)>)p->table[4])(p);}};
struct F1pMissionCountKey{Ptr32<const char> text;template <class W3dU> F1pMissionCountKey(Ptr32<W3dU> w3d_p) : F1pMissionCountKey((const char *)w3d_p.get()) {}
 F1pMissionCountKey(const char*p):text(p){}};

struct F1pMissionCountArray;
struct F1pMissionCountEntry{char gap[48];unsigned unlocked;Ptr32<F1pMissionCountArray> missions;char gap2[4];Ptr32<const char> name;};
struct F1pMissionCountArray{char gap[24];unsigned count;int unknown;Ptr32<F1pMissionCountEntry> entries[1];};
struct F1pMissionCountData{char gap[24];Ptr32<F1pMissionCountArray> teams;};
struct F1pMissionCountContext{char gap[188];unsigned flags;};extern Ptr32<F1pMissionCountContext> context_804b1788;
extern char barracks_803ceaa0[],current_803cea5c[],retry_803cea38[];
extern "C" int fn_800fc43c(Ptr32<F1pMissionCountKey>,int);
extern "C" Ptr32<void> fn_80341584(Ptr32<F1pMissionCountIface>);
extern "C" Ptr32<F1pMissionCountData> fn_801797b4(Ptr32<void>);
extern "C" int fn_800fc1b0(Ptr32<F1pMissionCountKey>,Ptr32<F1pMissionCountHandle>),fn_800fc2b0(Ptr32<F1pMissionCountKey>,Ptr32<Ptr32<const char>>),fn_802ef234(Ptr32<const char>,Ptr32<const char>),fn_8027be7c(Ptr32<void>,int);
extern "C" Ptr32<F1pMissionCountText> fn_8020bd38(Ptr32<F1pMissionCountText>,Ptr32<const char>);
extern "C" unsigned w3d_team_mission_count_8027dacc(Ptr32<void> self,F1pMissionCountText name){
 F1pMissionCountHandle barracks;F1pMissionCountKey lookup(barracks_803ceaa0);unsigned result=0;
 int status=fn_800fc1b0(&lookup,&barracks);F1pMissionCountKey retry(retry_803cea38);fn_800fc43c(&retry,0);if(status<0)return 0;
 Ptr32<F1pMissionCountData> data=fn_801797b4(fn_80341584(barracks.p));
 unsigned count=data->teams->count;
 if(!((Ptr32<F1pMissionCountHeader>)(name.text-6))->length){F1pMissionCountKey key(current_803cea5c);Ptr32<const char> text;fn_800fc2b0(&key,&text);fn_8020bd38(&name,text);}
 Ptr32<Ptr32<F1pMissionCountEntry>> entries=data->teams->entries;
 unsigned i=0;if(result<count)do{if(fn_802ef234(name.text,entries[i]->name)==0){if(context_804b1788->flags&16)result=fn_8027be7c(self,0)-1;else result=entries[i]->missions->count-1;break;}++i;}while(i<count);
 return result;
}



#include "w3d_ptr.h"
#line 1 "f1p_team_unlocked_8027dc5c.cpp"
// Inferred shared-string header and partial lookup result layout.
extern "C" void fn_8020c5c0(Ptr32<void>),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>),fn_8020bb2c(Ptr32<void>);
extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<void>);
struct F1pBarrackHeader{unsigned short refs,length,capacity;};
struct F1pBarrackText{Ptr32<char> text;template <class W3dU> F1pBarrackText(Ptr32<W3dU> w3d_p) : F1pBarrackText((const char *)w3d_p.get()) {}
 F1pBarrackText(const char*);F1pBarrackText(const F1pBarrackText&o){fn_8020c5c0(this);text=o.text;++*fn_80341884(this);}~F1pBarrackText(){fn_8020c5c4(this);fn_80341588(this);}F1pBarrackText&operator=(const F1pBarrackText&o){Ptr32<F1pBarrackHeader> h=(Ptr32<F1pBarrackHeader>)(o.text-6);++h->refs;h=(Ptr32<F1pBarrackHeader>)(text-6);if(--h->refs==0)fn_8020bb2c(h);text=o.text;return *this;}};
struct F1pBarrackIface{Ptr32<Ptr32<void>> table;};struct F1pBarrackHandle{
 F1pBarrackHandle(const F1pBarrackHandle &);Ptr32<F1pBarrackIface> p;F1pBarrackHandle():p(0){}~F1pBarrackHandle(){if(p)((Ptr32<void (Ptr32<F1pBarrackIface>)>)p->table[4])(p);}};
struct F1pBarrackKey{Ptr32<const char> text;template <class W3dU> F1pBarrackKey(Ptr32<W3dU> w3d_p) : F1pBarrackKey((const char *)w3d_p.get()) {}
 F1pBarrackKey(const char*p):text(p){}};

struct F1pBarrackEntry{char gap[48];unsigned unlocked;Ptr32<void> missions;char gap2[4];Ptr32<const char> name;};
struct F1pBarrackArray{char gap[24];unsigned count;int unknown;Ptr32<F1pBarrackEntry> entries[1];};
struct F1pBarrackData{char gap[24];Ptr32<F1pBarrackArray> teams;};
struct F1pBarrackContext{char gap[188];unsigned flags;};extern Ptr32<F1pBarrackContext> context_804b1788;
extern char barracks_803ceaa0[],current_803cea5c[];
extern "C" Ptr32<void> fn_80341584(Ptr32<F1pBarrackIface>);
extern "C" Ptr32<F1pBarrackData> fn_801797b4(Ptr32<void>);
extern "C" int fn_800fc1b0(Ptr32<F1pBarrackKey>,Ptr32<F1pBarrackHandle>),fn_800fc2b0(Ptr32<F1pBarrackKey>,Ptr32<Ptr32<const char>>),fn_802ef234(Ptr32<const char>,Ptr32<const char>),fn_8027be7c(Ptr32<void>,int);
extern "C" Ptr32<F1pBarrackText> fn_8020bd38(Ptr32<F1pBarrackText>,Ptr32<const char>);
extern "C" unsigned w3d_team_unlocked_8027dc5c(Ptr32<void> self,F1pBarrackText name){
 F1pBarrackHandle barracks;F1pBarrackKey lookup(barracks_803ceaa0);unsigned result=0;
 if(fn_800fc1b0(&lookup,&barracks)<0)return 0;
 Ptr32<F1pBarrackData> data=fn_801797b4(fn_80341584(barracks.p));
 if(!((Ptr32<F1pBarrackHeader>)(name.text-6))->length){F1pBarrackKey key(current_803cea5c);Ptr32<const char> text;fn_800fc2b0(&key,&text);fn_8020bd38(&name,text);}
 unsigned count=data->teams->count;Ptr32<Ptr32<F1pBarrackEntry>> entries=data->teams->entries;
 unsigned i=0;if(result<count)do{if(fn_802ef234(name.text,entries[i]->name)==0){if(context_804b1788->flags&16)result=fn_8027be7c(self,3)-1;else result=entries[i]->unlocked;break;}++i;}while(i<count);
 return result;
}



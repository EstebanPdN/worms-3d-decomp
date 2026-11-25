#include "w3d_ptr.h"
#line 1 "f1p_team_description_8027c018.cpp"
// Inferred shared-string header and partial lookup result layout.
extern "C" void fn_8020c5c0(Ptr32<void>),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>),fn_8020bb2c(Ptr32<void>);
extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<void>);
struct F1pDesc_8027c018_Header{unsigned short refs,length,capacity;};
struct F1pDesc_8027c018_Text{Ptr32<char> text;template <class W3dU> F1pDesc_8027c018_Text(Ptr32<W3dU> w3d_p) : F1pDesc_8027c018_Text((const char *)w3d_p.get()) {}
 F1pDesc_8027c018_Text(const char*);F1pDesc_8027c018_Text();F1pDesc_8027c018_Text(const F1pDesc_8027c018_Text&o){fn_8020c5c0(this);text=o.text;++*fn_80341884(this);}~F1pDesc_8027c018_Text(){fn_8020c5c4(this);fn_80341588(this);}F1pDesc_8027c018_Text&operator=(const F1pDesc_8027c018_Text&o){Ptr32<F1pDesc_8027c018_Header> h=(Ptr32<F1pDesc_8027c018_Header>)(o.text-6);++h->refs;h=(Ptr32<F1pDesc_8027c018_Header>)(text-6);if(--h->refs==0)fn_8020bb2c(h);text=o.text;return *this;}};
struct F1pDesc_8027c018_Iface{Ptr32<Ptr32<void>> table;};struct F1pDesc_8027c018_Handle{
 F1pDesc_8027c018_Handle(const F1pDesc_8027c018_Handle &);Ptr32<F1pDesc_8027c018_Iface> p;F1pDesc_8027c018_Handle():p(0){}~F1pDesc_8027c018_Handle(){if(p)((Ptr32<void (Ptr32<F1pDesc_8027c018_Iface>)>)p->table[4])(p);}};
struct F1pDesc_8027c018_Key{Ptr32<const char> text;template <class W3dU> F1pDesc_8027c018_Key(Ptr32<W3dU> w3d_p) : F1pDesc_8027c018_Key((const char *)w3d_p.get()) {}
 F1pDesc_8027c018_Key(const char*p):text(p){}};
struct F1pDesc_8027c018_TeamData{char unknown[72];F1pDesc_8027c018_Text description;};
extern char failed_803cea20[],temp_803cf080[];
extern "C" int fn_802ef234(Ptr32<const char>,Ptr32<const char>);
extern "C" void fn_8027befc(Ptr32<F1pDesc_8027c018_Text>,Ptr32<void>,int,int);
extern "C" int fn_800fc1b0(Ptr32<F1pDesc_8027c018_Key>,Ptr32<F1pDesc_8027c018_Handle>);
extern "C" Ptr32<F1pDesc_8027c018_Text> fn_8020bd38(Ptr32<F1pDesc_8027c018_Text>,Ptr32<const char>);
extern "C" Ptr32<void> fn_80341584(Ptr32<F1pDesc_8027c018_Iface>);
extern "C" Ptr32<F1pDesc_8027c018_TeamData> fn_801797b4(Ptr32<void>);
inline void*operator new(__SIZE_TYPE__,void*p){return p;}
struct F1pDesc_8027c018_Slot{int alignment[2];~F1pDesc_8027c018_Slot(){((Ptr32<F1pDesc_8027c018_Handle>)this)->~F1pDesc_8027c018_Handle();}};

extern char missing_803cea28[];
extern "C" int fn_800fc2b0(Ptr32<F1pDesc_8027c018_Key>,Ptr32<Ptr32<const char>>);
extern "C" void fn_8020c510(Ptr32<F1pDesc_8027c018_Text>,Ptr32<const char>,...);
extern "C" F1pDesc_8027c018_Text w3d_team_description_8027c018(Ptr32<void> self,int category,int index){
 F1pDesc_8027c018_Text key(failed_803cea20);F1pDesc_8027c018_Slot slot;Ptr32<F1pDesc_8027c018_Text> name=(Ptr32<F1pDesc_8027c018_Text>)&slot;
 fn_8027befc(name,self,category,index);key=*name;name->~F1pDesc_8027c018_Text();
 Ptr32<F1pDesc_8027c018_Handle> value=new(&slot)F1pDesc_8027c018_Handle;F1pDesc_8027c018_Key lookup(key.text);
 if(fn_800fc1b0(&lookup,value)<0){fn_8020bd38(&key,failed_803cea20);return key;}
 key=fn_801797b4(fn_80341584(value->p))->description;
 F1pDesc_8027c018_Text result;F1pDesc_8027c018_Key descriptionKey(key.text);Ptr32<const char> text;
 if(fn_800fc2b0(&descriptionKey,&text)<0)fn_8020c510(&result,missing_803cea28,w3d::VA(key.text));else fn_8020bd38(&result,text);
 return result;
}



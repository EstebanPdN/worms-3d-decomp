#include "w3d_ptr.h"
#line 1 "f6a_advance_menu_8028e9c0.cpp"
// Partial observed menu history and deque layout; semantic roles inferred.
extern "C" void fn_8020c5c0(Ptr32<void>),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
struct Header{unsigned short refs,length,unknown;};extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
struct Text_803426b8{Ptr32<char> text;int unknown;Text_803426b8();~Text_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
struct CallerString{Ptr32<char> text;int unknown;CallerString(const Text_803426b8&o){fn_8020c5c0(this);text=o.text;Ptr32<Header> h=fn_80341884(this);++h->refs;}~CallerString(){fn_8020c5c4(this);fn_80341588(this);}};
struct Key{Ptr32<const char> text;template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char*p):text(p){}};
struct Names{char unknown[20];};
struct Deque{Ptr32<int> current; Ptr32<int> first; Ptr32<int> last; Ptr32<Ptr32<int>> node;};
struct Owner{char unknown[68];int value;Names names,history;char unknown112[8];Deque deque;};
extern Ptr32<void> app_804b1788;extern char refcount_803d001c[],empty_803d0034[],briefing_803d0038[];
extern "C" int fn_8015ccbc(Ptr32<void>),fn_8006e71c(),fn_800fc1f0(Ptr32<Key>,Ptr32<int>),fn_800c4660(Ptr32<Names>),fn_802ef234(Ptr32<const char>,Ptr32<const char>),fn_800fc2b0(Ptr32<Key>,Ptr32<Ptr32<char>>),fn_800fc550(Ptr32<Key>,Ptr32<const char>);
extern "C" void fn_800c4a7c(Ptr32<Names>,Ptr32<Text_803426b8>),fn_8035eec4(Ptr32<Deque>),fn_8028e630(Ptr32<Owner>,CallerString,int,Ptr32<const char>);
inline int different(const Text_803426b8&self,Ptr32<const char> other){return fn_802ef234(self.text,other)!=0;}
inline void pop(Ptr32<Deque> p){if(p->current!=p->last-1)++p->current;else fn_8035eec4(p);}
extern "C" void w3d_f6a_advance_menu_8028e9c0(Ptr32<Owner> self){
 if(fn_8015ccbc(app_804b1788)==1)return;if(fn_8006e71c()==1)return;
 int refs=0;Key refKey(refcount_803d001c);fn_800fc1f0(&refKey,&refs);if(refs>0)return;
 Text_803426b8 menu;fn_800c4a7c(&self->names,&menu);Text_803426b8 history;
 if(fn_800c4660(&self->history)){fn_800c4a7c(&self->history,&history);int changed=different(history,empty_803d0034);if(changed){Key key(history.text);Ptr32<char> text;fn_800fc2b0(&key,&text);Key target(briefing_803d0038);fn_800fc550(&target,text);}}
 self->value=*self->deque.current;pop(&self->deque);fn_8028e630(self,CallerString(menu),self->value,history.text);
}



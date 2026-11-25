#include "w3d_ptr.h"
#line 1 "g2b_pair_callbacks_v1_801ad974.cpp"
// Partial external interfaces; complete local Held is exactly one pointer.
struct Interface {Ptr32<Ptr32<void>> table;};
inline void retain(Ptr32<Interface> p){if(p)((Ptr32<void (Ptr32<Interface>)>)p->table[3])(p);}
inline void release(Ptr32<Interface> p){if(p)((Ptr32<void (Ptr32<Interface>)>)p->table[4])(p);}
struct Held {
 Ptr32<Interface> p;template <class W3dU> Held(Ptr32<W3dU> w3d_p) : Held((Interface *)w3d_p.get()) {}
 Held(Interface*q):p(q){retain(p);} Held(const Held&q):p(q.p){retain(p);}~Held(){release(p);}
 void reset(Ptr32<Interface> q=0){retain(q);release(p);p=q;}
 void set(Ptr32<Interface> q){retain(q);release(p);p=q;}
 Held&operator=(const Held&q){Ptr32<Interface> old=p;p=q.p;retain(p);release(old);return *this;}
};
struct Callback {unsigned unknown;unsigned short unknown4,index;};
struct Item {Ptr32<Ptr32<void>> table;char unknown[44];Held first,second;};
struct Secondary {char unknown[24];Ptr32<Ptr32<void>> callbacks;};
struct Owner {char unknown[92];unsigned unknown92;Held next;};
extern "C" Ptr32<Item> fn_801ad108(Ptr32<Owner>,Ptr32<Item>);
inline int invoke(Ptr32<Owner> owner,Ptr32<Callback> callback){Ptr32<Secondary> secondary=(Ptr32<Secondary>)((Ptr32<char>)owner+4);return ((Ptr32<int (Ptr32<Secondary>, Ptr32<Callback>)>)secondary->callbacks[callback->index])(secondary,callback);}
extern "C" int g2b_pair_callbacks_801ad974(Ptr32<char> self,Ptr32<Item> item){
 Ptr32<Owner> owner=self?w3d::R((Ptr32<Owner>)(self-4)):0;
 owner->next.reset();
 Held second=Held(0);
 if(item->second.p){invoke(owner,(Ptr32<Callback>)item->second.p);second.set(owner->next.p);owner->next.reset();}
 Held first=Held(0);
 if(item->first.p){invoke(owner,(Ptr32<Callback>)item->first.p);first.set(owner->next.p);owner->next.reset();}
 if(second.p||first.p){
  Ptr32<Item> result=fn_801ad108(owner,item);
  if(second.p)result->second=second;
  if(first.p)result->first=first;
  owner->next.set((Ptr32<Interface>)result);
 }
 return 0;
}



#include "w3d_ptr.h"
#line 1 "g2b_dispatch_held_801ad644.cpp"
// External object prefixes, never locally constructed.
struct Interface {Ptr32<Ptr32<void>> table;};
inline void retain(Ptr32<Interface> p){if(p)((Ptr32<void (Ptr32<Interface>)>)p->table[3])(p);}
inline void release(Ptr32<Interface> p){if(p)((Ptr32<void (Ptr32<Interface>)>)p->table[4])(p);}
// Complete one-pointer held value; original stack slot and retain/release witness its footprint.
struct Held {Ptr32<Interface> p;template <class W3dU> Held(Ptr32<W3dU> w3d_p) : Held((Interface *)w3d_p.get()) {}
 Held(Interface*q):p(q){retain(p);}~Held(){release(p);}void clear(){Ptr32<Interface> old=p;p=0;release(old);}};
struct Callback {unsigned unknown;unsigned short unknown4,index;};
struct Item {Ptr32<Ptr32<void>> table;char unknown[44];Held callback;};
struct Secondary {char unknown[20];Ptr32<Item> current;Ptr32<Ptr32<void>> callbacks;};
struct Owner {char unknown[92];int clearPending;Held next;};
extern "C" void fn_801ace68(Ptr32<Owner>,Ptr32<Item>);
extern "C" void fn_801ad060(Ptr32<Owner>);
extern "C" int fn_801ad590(Ptr32<Secondary>,Ptr32<Item>);
extern "C" int g2b_dispatch_held_801ad644(Ptr32<char> self,Ptr32<Item> item){
 Ptr32<Owner> owner=self?w3d::R((Ptr32<Owner>)(self-4)):0;
 Ptr32<Callback> callback=(Ptr32<Callback>)item->callback.p;
 if(callback){
  Ptr32<Secondary> secondary=(Ptr32<Secondary>)((Ptr32<char>)owner+4);
  secondary->current=item;owner->clearPending=0;
  fn_801ace68(owner,item);
  int result=((Ptr32<int (Ptr32<Secondary>, Ptr32<Callback>)>)secondary->callbacks[callback->index])(secondary,callback);
  fn_801ad060(owner);
  Held saved(owner->next.p);
  if(owner->clearPending){
   if(saved.p)((Ptr32<Item>)saved.p)->callback.clear();
   else item->callback.clear();
   owner->clearPending=0;
  }
  return result;
 }
 return fn_801ad590(owner?w3d::R((Ptr32<Secondary>)((Ptr32<char>)owner+4)):0,item);
}



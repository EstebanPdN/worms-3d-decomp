// External object prefixes, never locally constructed.
struct Interface {void **table;};
inline void retain(Interface*p){if(p)((void(*)(Interface*))p->table[3])(p);}
inline void release(Interface*p){if(p)((void(*)(Interface*))p->table[4])(p);}
// Complete one-pointer held value; original stack slot and retain/release witness its footprint.
struct Held {Interface*p;Held(Interface*q):p(q){retain(p);}~Held(){release(p);}void clear(){Interface*old=p;p=0;release(old);}};
struct Callback {unsigned unknown;unsigned short unknown4,index;};
struct Item {void**table;char unknown[44];Held callback;};
struct Secondary {char unknown[20];Item*current;void**callbacks;};
struct Owner {char unknown[92];int clearPending;Held next;};
extern "C" void fn_801ace68(Owner*,Item*);
extern "C" void fn_801ad060(Owner*);
extern "C" int fn_801ad590(Secondary*,Item*);
extern "C" int g2b_dispatch_held_801ad644(char*self,Item*item){
 Owner*owner=self?(Owner*)(self-4):0;
 Callback*callback=(Callback*)item->callback.p;
 if(callback){
  Secondary*secondary=(Secondary*)((char*)owner+4);
  secondary->current=item;owner->clearPending=0;
  fn_801ace68(owner,item);
  int result=((int(*)(Secondary*,Callback*))secondary->callbacks[callback->index])(secondary,callback);
  fn_801ad060(owner);
  Held saved(owner->next.p);
  if(owner->clearPending){
   if(saved.p)((Item*)saved.p)->callback.clear();
   else item->callback.clear();
   owner->clearPending=0;
  }
  return result;
 }
 return fn_801ad590(owner?(Secondary*)((char*)owner+4):0,item);
}

// Partial external interfaces; complete local Held is exactly one pointer.
struct Interface {void **table;};
inline void retain(Interface*p){if(p)((void(*)(Interface*))p->table[3])(p);}
inline void release(Interface*p){if(p)((void(*)(Interface*))p->table[4])(p);}
struct Held {
 Interface*p;Held(Interface*q):p(q){retain(p);} Held(const Held&q):p(q.p){retain(p);}~Held(){release(p);}
 void reset(Interface*q=0){retain(q);release(p);p=q;}
 void set(Interface*q){retain(q);release(p);p=q;}
 Held&operator=(const Held&q){Interface*old=p;p=q.p;retain(p);release(old);return *this;}
};
struct Callback {unsigned unknown;unsigned short unknown4,index;};
struct Item {void**table;char unknown[44];Held first,second;};
struct Secondary {char unknown[24];void**callbacks;};
struct Owner {char unknown[92];unsigned unknown92;Held next;};
extern "C" Item*fn_801ad108(Owner*,Item*);
inline int invoke(Owner*owner,Callback*callback){Secondary*secondary=(Secondary*)((char*)owner+4);return ((int(*)(Secondary*,Callback*))secondary->callbacks[callback->index])(secondary,callback);}
extern "C" int g2b_pair_callbacks_801ad974(char*self,Item*item){
 Owner*owner=self?(Owner*)(self-4):0;
 owner->next.reset();
 Held second=Held(0);
 if(item->second.p){invoke(owner,(Callback*)item->second.p);second.set(owner->next.p);owner->next.reset();}
 Held first=Held(0);
 if(item->first.p){invoke(owner,(Callback*)item->first.p);first.set(owner->next.p);owner->next.reset();}
 if(second.p||first.p){
  Item*result=fn_801ad108(owner,item);
  if(second.p)result->second=second;
  if(first.p)result->first=first;
  owner->next.set((Interface*)result);
 }
 return 0;
}

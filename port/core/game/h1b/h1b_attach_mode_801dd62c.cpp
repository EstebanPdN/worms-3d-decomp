#include "w3d_ptr.h"
#line 1 "h1b_attach_mode_801dd62c.cpp"
// Partial external ABI views; the sole complete local object is a four-byte holder.
struct Interface {Ptr32<Ptr32<void>> table;};
inline void retain(Ptr32<Interface> p){if(p)((Ptr32<void (Ptr32<Interface>)>)p->table[3])(p);}
inline void release(Ptr32<Interface> p){if(p)((Ptr32<void (Ptr32<Interface>)>)p->table[4])(p);}
struct Held {Ptr32<Interface> p;Held():p(0){}~Held(){release(p);}void clear(){release(p);p=0;}};
struct Storage;
struct List {unsigned count,unknown;Ptr32<Storage> storage;void append(Ptr32<Interface>);};
extern "C" void fn_80210d54(Ptr32<List>,unsigned);
inline void List::append(Ptr32<Interface> p){fn_80210d54(this,count+1);unsigned offset=count<<2;Ptr32<Storage> items=storage;retain(p);Ptr32<Ptr32<Interface>> slot=(Ptr32<Ptr32<Interface>>)w3d::G((offset+(unsigned)w3d::H(items)));release(*slot);*slot=p;++count;}
struct Owner {Ptr32<Ptr32<void>> table;unsigned unknown[18];List pending;};
extern "C" int h1b_attach_mode_801dd62c(Ptr32<Owner> self,Ptr32<void> key,Ptr32<void> value){
 Held item;
 if(((Ptr32<int (Ptr32<Owner>, Ptr32<void>, Ptr32<Held>)>)self->table[23])(self,key,&item)!=0)return (int)0x80004005;
 if(((Ptr32<int (Ptr32<Interface>)>)item.p->table[10])(item.p)!=0){item.clear();return (int)0x80004005;}
 ((Ptr32<void (Ptr32<Interface>, int, Ptr32<void>)>)item.p->table[14])(item.p,3,value);
 ((Ptr32<void (Ptr32<Interface>)>)item.p->table[5])(item.p);
 self->pending.append(item.p);
 return 0;
}



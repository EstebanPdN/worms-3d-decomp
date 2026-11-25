#include "w3d_ptr.h"
#line 1 "g4b_remove_flagged_entry_v2_801dc530.cpp"
// Partial external ABI views. None of these objects are locally constructed.
struct Interface {Ptr32<Ptr32<void>> table;};
struct Held {Ptr32<Interface> p;};
struct Storage;
struct List {int count,unknown;Ptr32<Storage> storage;
 Ptr32<Interface> get(unsigned i){return ((Ptr32<Ptr32<Interface>>)storage)[i];}
 Ptr32<Held> begin(){return (Ptr32<Held>)storage;}
 Ptr32<Held> end(){return (Ptr32<Held>)storage+count;}
};
struct Entry {Ptr32<Ptr32<void>> table;unsigned unknown[4];int count;unsigned unknown24[3];int flags;
 int size()const{return count;}Ptr32<void> child(int);
};
struct Owner {unsigned unknown[9];List entries,services;unsigned unknown60[29];int enabled;};
extern "C" Ptr32<void> fn_801de10c(Ptr32<Interface>,int);
inline Ptr32<void> Entry::child(int i){return fn_801de10c((Ptr32<Interface>)this,i);}
extern "C" void fn_80210dd8(Ptr32<List>,Ptr32<Held>,Ptr32<Held>);
inline int kind(Ptr32<Interface> p,unsigned slot){return ((Ptr32<int (Ptr32<Interface>)>)p->table[slot])(p);}
inline void removeChild(Ptr32<Interface> service,Ptr32<Interface> child){((Ptr32<void (Ptr32<Interface>, Ptr32<Interface>)>)service->table[11])(service,child);}
extern "C" int g4b_remove_flagged_entry_801dc530(Ptr32<Owner> self,int flags){
 for(Ptr32<Held> cursor=self->entries.begin();cursor!=self->entries.end();++cursor){
  Ptr32<Entry> entry=(Ptr32<Entry>)cursor->p;
  if(entry && entry->flags==flags){
   for(int index=entry->size()-1;index>=0;--index){
    Ptr32<Interface> child=(Ptr32<Interface>)entry->child(index);
    for(unsigned i=0;i<self->services.count;++i){
     if(kind(child,8)==kind(self->services.get(i),7)){removeChild(self->services.get(i),child);break;}
     if(kind(child,8)==3 && kind(self->services.get(i),7)==4)removeChild(self->services.get(i),child);
    }
   }
   fn_80210dd8(&self->entries,cursor,cursor+1);return 0;
  }
 }
 return (int)0x80004005;
}



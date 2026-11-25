// Partial external ABI views. None of these objects are locally constructed.
struct Interface {void**table;};
struct Held {Interface*p;};
struct Storage;
struct List {int count,unknown;Storage*storage;
 Interface*get(unsigned i){return ((Interface**)storage)[i];}
 Held*begin(){return (Held*)storage;}
 Held*end(){return (Held*)storage+count;}
};
struct Entry {void**table;unsigned unknown[4];int count;unsigned unknown24[3];int flags;
 int size()const{return count;}void*child(int);
};
struct Owner {unsigned unknown[9];List entries,services;unsigned unknown60[29];int enabled;};
extern "C" void*fn_801de10c(Interface*,int);
inline void*Entry::child(int i){return fn_801de10c((Interface*)this,i);}
extern "C" void fn_80210dd8(List*,Held*,Held*);
inline int kind(Interface*p,unsigned slot){return ((int(*)(Interface*))p->table[slot])(p);}
inline void removeChild(Interface*service,Interface*child){((void(*)(Interface*,Interface*))service->table[11])(service,child);}
extern "C" int g4b_remove_flagged_entry_801dc530(Owner*self,int flags){
 for(Held*cursor=self->entries.begin();cursor!=self->entries.end();++cursor){
  Entry*entry=(Entry*)cursor->p;
  if(entry && entry->flags==flags){
   for(int index=entry->size()-1;index>=0;--index){
    Interface*child=(Interface*)entry->child(index);
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

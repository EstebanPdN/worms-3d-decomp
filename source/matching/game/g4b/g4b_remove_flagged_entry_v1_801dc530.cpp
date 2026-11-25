// Complete one-pointer output holder; all receiver and item views remain external.
struct Interface {void**table;};
inline void retain(Interface*p){if(p)((void(*)(Interface*))p->table[3])(p);}
inline void release(Interface*p){if(p)((void(*)(Interface*))p->table[4])(p);}
struct Entry;
struct Held {Interface*p;Held():p(0){}~Held(){release(p);}Entry*operator->()const{return (Entry*)p;}void set(Interface*q){retain(q);release(p);p=q;}};
struct Storage;
struct List {int count,unknown;Storage*storage;Interface*get(unsigned i){return ((Interface**)storage)[i];}Held&at(int i){return ((Held*)storage)[i];}Held*begin(){return (Held*)storage;}Held*end(){return (Held*)storage+count;}void append(Interface*);};
extern "C" void fn_80210d54(List*,int);
inline void List::append(Interface*p){fn_80210d54(this,count+1);int offset=count<<2;Storage*items=storage;retain(p);Interface**slot=(Interface**)(offset+(unsigned)items);release(*slot);*slot=p;++count;}
struct Entry {void**table;unsigned unknown[4];int count;unsigned unknown24[3];int flags;int size()const{return count;}void*child(int);};
struct Owner {unsigned unknown[9];List entries,services;unsigned unknown60[29];int enabled;};
extern "C" const char*fn_801de134(Interface*);
extern "C" int fn_802ef234(const char*,const char*);
extern "C" int fn_801de2dc(const char*,Held*,void*);
extern "C" void fn_801de13c(Interface*,const char*);
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

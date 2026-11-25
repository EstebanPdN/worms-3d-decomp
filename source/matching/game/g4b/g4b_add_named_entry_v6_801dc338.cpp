// Complete one-pointer output holder; all receiver and item views remain external.
struct Interface {void**table;};
inline void retain(Interface*p){if(p)((void(*)(Interface*))p->table[3])(p);}
inline void release(Interface*p){if(p)((void(*)(Interface*))p->table[4])(p);}
struct Entry;
struct Held {Interface*p;Held():p(0){}~Held(){release(p);}Entry*operator->()const{return (Entry*)p;}void set(Interface*q){retain(q);release(p);p=q;}};
struct Storage;
struct List {int count,unknown;Storage*storage;Interface*get(unsigned i){return ((Interface**)storage)[i];}Held&at(int i){return ((Held*)storage)[i];}void append(Interface*);};
extern "C" void fn_80210d54(List*,int);
inline void List::append(Interface*p){fn_80210d54(this,count+1);at(count).set(p);++count;}
struct Entry {void**table;unsigned unknown[4];int count;unsigned unknown24[3];int flags;int size()const{return count;}void*child(int);};
struct Owner {unsigned unknown[9];List entries,services;unsigned unknown60[29];int enabled;};
extern "C" const char*fn_801de134(Interface*);
extern "C" int fn_802ef234(const char*,const char*);
extern "C" int fn_801de2dc(const char*,Held*,void*);
extern "C" void fn_801de13c(Interface*,const char*);
extern "C" void*fn_801de10c(Interface*,int);
inline void*Entry::child(int i){return fn_801de10c((Interface*)this,i);}
extern "C" int g4b_add_named_entry_801dc338(Owner*self,const char*name,int flags,void*context){
 Held item;
 if(!self->enabled)return (int)0x80004005;
 unsigned service=0;
 for(;service<self->entries.count;++service)if(fn_802ef234(fn_801de134(self->entries.get(service)),name)==0)return 0;
 int result=fn_801de2dc(name,&item,context);
 if(result<0)return result;
 self->entries.append(item.p);
 service=0;fn_801de13c(item.p,name);item->flags=flags;
 for(;service<self->services.count;++service){
  for(int index=0;index<item->size();++index){
   Interface*target=self->services.get(service);
   void**table=target->table;
   void*value=item->child(index);
   ((void(*)(Interface*,void*))table[10])(target,value);
  }
 }
 return 0;
}

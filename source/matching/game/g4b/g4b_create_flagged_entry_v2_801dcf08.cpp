// Complete one-pointer output holder; all receiver and item views remain external.
struct Interface {void**table;};
inline void retain(Interface*p){if(p)((void(*)(Interface*))p->table[3])(p);}
inline void release(Interface*p){if(p)((void(*)(Interface*))p->table[4])(p);}
struct Entry;
struct Held {Interface*p;Held():p(0){}~Held(){release(p);}void clear(){release(p);p=0;}Entry*operator->()const{return (Entry*)p;}void set(Interface*q){retain(q);release(p);p=q;}};
struct Storage;
struct List {int count,unknown;Storage*storage;Interface*get(unsigned i){return ((Interface**)storage)[i];}Held&at(int i){return ((Held*)storage)[i];}void append(Interface*);};
extern "C" void fn_80210d54(List*,int);
inline void List::append(Interface*p){fn_80210d54(this,count+1);int offset=count<<2;Storage*items=storage;retain(p);Interface**slot=(Interface**)(offset+(char*)items);release(*slot);*slot=p;++count;}
struct Entry {void**table;unsigned unknown[4];int count;unsigned unknown24[3];int flags;int size()const{return count;}void*child(int);};
struct Owner {unsigned unknown[9];List entries,services;unsigned unknown60[29];int enabled;};
extern "C" const char*fn_801de134(Interface*);
extern "C" int fn_802ef234(const char*,const char*);
extern "C" int fn_801de2dc(const char*,Held*,void*);
extern "C" void fn_801de13c(Interface*,const char*);
extern "C" void*fn_801de10c(Interface*,int);
inline void*Entry::child(int i){return fn_801de10c((Interface*)this,i);}
extern char type_803655bc[];
extern "C" Interface*fn_8020fcb4(const void*);
extern "C" int g4b_create_flagged_entry_801dcf08(Owner*self,int flags){
 Held item;
 for(unsigned i=0;i<self->entries.count;++i){item.set(self->entries.get(i));if(item->flags==flags)return (int)0x80004005;}
 item.clear();item.set(fn_8020fcb4(type_803655bc));item->flags=flags;
 self->entries.append(item.p);return 0;
}

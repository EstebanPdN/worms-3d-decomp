#include "w3d_ptr.h"
#line 1 "g4b_create_flagged_entry_801dcf08.cpp"
// Complete one-pointer output holder; all receiver and item views remain external.
struct Interface {Ptr32<Ptr32<void>> table;};
inline void retain(Ptr32<Interface> p){if(p)((Ptr32<void (Ptr32<Interface>)>)p->table[3])(p);}
inline void release(Ptr32<Interface> p){if(p)((Ptr32<void (Ptr32<Interface>)>)p->table[4])(p);}
struct Entry;
struct Held {Ptr32<Interface> p;Held():p(0){}~Held(){release(p);}void clear(){release(p);p=0;}Ptr32<Entry> operator->()const{return (Ptr32<Entry>)p;}void set(Ptr32<Interface> q){retain(q);release(p);p=q;}};
struct Storage;
struct List {int count,unknown;Ptr32<Storage> storage;Ptr32<Interface> get(unsigned i){return ((Ptr32<Ptr32<Interface>>)storage)[i];}Held&at(int i){return ((Ptr32<Held>)storage)[i];}void append(Ptr32<Interface>);};
extern "C" void fn_80210d54(Ptr32<List>,int);
inline void List::append(Ptr32<Interface> p){fn_80210d54(this,count+1);int offset=count<<2;Ptr32<Storage> items=storage;retain(p);Ptr32<Ptr32<Interface>> slot=(Ptr32<Ptr32<Interface>>)w3d::G((offset+(unsigned)w3d::H(items)));release(*slot);*slot=p;++count;}
struct Entry {Ptr32<Ptr32<void>> table;unsigned unknown[4];int count;unsigned unknown24[3];int flags;int size()const{return count;}Ptr32<void> child(int);};
struct Owner {unsigned unknown[9];List entries,services;unsigned unknown60[29];int enabled;};
extern "C" Ptr32<const char> fn_801de134(Ptr32<Interface>);
extern "C" int fn_802ef234(Ptr32<const char>,Ptr32<const char>);
extern "C" int fn_801de2dc(Ptr32<const char>,Ptr32<Held>,Ptr32<void>);
extern "C" void fn_801de13c(Ptr32<Interface>,Ptr32<const char>);
extern "C" Ptr32<void> fn_801de10c(Ptr32<Interface>,int);
inline Ptr32<void> Entry::child(int i){return fn_801de10c((Ptr32<Interface>)this,i);}
extern char type_803655bc[];
extern "C" Ptr32<Interface> fn_8020fcb4(Ptr32<const void>);
extern "C" int g4b_create_flagged_entry_801dcf08(Ptr32<Owner> self,int flags){
 Held item;
 for(unsigned i=0;i<self->entries.count;++i){item.set(self->entries.get(i));if(item->flags==flags)return (int)0x80004005;}
 item.clear();item.set(fn_8020fcb4(type_803655bc));item->flags=flags;
 self->entries.append(item.p);return 0;
}



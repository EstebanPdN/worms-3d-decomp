// Partial external ABI views; the sole complete local object is a four-byte holder.
struct Interface {void **table;};
inline void retain(Interface*p){if(p)((void(*)(Interface*))p->table[3])(p);}
inline void release(Interface*p){if(p)((void(*)(Interface*))p->table[4])(p);}
struct Held {Interface*p;Held():p(0){}~Held(){release(p);}void clear(){release(p);p=0;}};
struct Storage;
struct List {unsigned count,unknown;Storage*storage;void append(Interface*);};
extern "C" void fn_80210d54(List*,unsigned);
inline void List::append(Interface*p){fn_80210d54(this,count+1);unsigned offset=count<<2;Storage*items=storage;retain(p);Interface**slot=(Interface**)(offset+(char*)items);release(*slot);*slot=p;++count;}
struct Owner {void**table;unsigned unknown[18];List pending;};
extern "C" int h1b_attach_mode_bytes_801dd62c(Owner*self,void*key,void*value){
 Held item;
 if(((int(*)(Owner*,void*,Held*))self->table[23])(self,key,&item)!=0)return (int)0x80004005;
 if(((int(*)(Interface*))item.p->table[10])(item.p)!=0){item.clear();return (int)0x80004005;}
 ((void(*)(Interface*,int,void*))item.p->table[14])(item.p,3,value);
 ((void(*)(Interface*))item.p->table[5])(item.p);
 self->pending.append(item.p);
 return 0;
}

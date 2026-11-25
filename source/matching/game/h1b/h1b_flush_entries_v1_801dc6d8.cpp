// External prefix views only; this routine constructs no external objects.
struct Interface {void **table;};
struct Entry {unsigned unknown[9];int flags;};
struct Storage;
struct List {unsigned count,unknown;Storage*storage;Interface*get(unsigned i){return ((Interface**)storage)[i];}};
struct Owner {void**table;unsigned unknown[8];List entries,services;};
extern "C" void fn_80210b90(List*,unsigned);
extern "C" int h1b_flush_entries_v1_801dc6d8(Owner*self){
 int result=0;
 for(unsigned i=0;i<self->services.count;++i){
  Interface*p=self->services.get(i);
  if(p && ((int(*)(Interface*))p->table[7])(p)==1){
   p=self->services.get(i);((void(*)(Interface*))p->table[15])(p);
  }
 }
 unsigned i=self->entries.count;
 while(i--){Entry*entry=(Entry*)self->entries.get(i);
  if(entry){int status=((int(*)(Owner*,int))self->table[21])(self,entry->flags);if(status)result=status;}
 }
 fn_80210b90(&self->entries,0);
 return result;
}

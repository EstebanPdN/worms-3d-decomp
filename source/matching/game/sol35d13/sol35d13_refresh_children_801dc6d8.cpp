// Partial GC32 owner/child views from original operands. Names are inferred.
namespace Sol35d13Children {
struct Child;
struct ChildTable {
 void (*earlier[7])();
 int (*is_active)(Child *);
 void (*middle[7])();
 void (*refresh)(Child *);
};
struct Child { ChildTable *table; unsigned unknown[8]; unsigned key; };
struct Children { unsigned count; unsigned short capacity,growth; Child **slots; };
struct Owner;
struct OwnerTable { void (*earlier[21])(); int (*apply)(Owner *,unsigned); };
struct Owner { OwnerTable *table; unsigned unknown[8]; Children pending,active; };
extern "C" void sol35d13_resize_refs_80210b90(Children *,unsigned);
typedef char ChildKeyOffset[((unsigned)&((Child *)0)->key)==36?1:-1];
typedef char PendingOffset[((unsigned)&((Owner *)0)->pending)==36?1:-1];
}
extern "C" int sol35d13_refresh_children_801dc6d8(Sol35d13Children::Owner *self) {
 using namespace Sol35d13Children;
 int result=0;
 for(unsigned i=0;i<self->active.count;++i) {
  Children &active=self->active;
  if(active.slots[i] && active.slots[i]->table->is_active(active.slots[i])==1)
   active.slots[i]->table->refresh(active.slots[i]);
 }
 Children &pending=self->pending;
 for(unsigned i=pending.count;i;) {
  --i;
  Child *child=pending.slots[i];
  if(child) {
   int value=self->table->apply(self,child->key);
   if(value) result=value;
  }
 }
 sol35d13_resize_refs_80210b90(&pending,0);
 return result;
}

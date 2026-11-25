// GWMP8P rev0 GC32 reconstruction. Names describe observed roles.
// Descriptor parent links are at byte20; entry tables expose descriptor at slot5.
// Container records and all descriptor objects remain external original data.
struct Sol32cTypeDescriptor { unsigned words[5]; Sol32cTypeDescriptor *parent; };
struct Sol32cEntry;
struct Sol32cEntryTable { void (*slots[5])(); Sol32cTypeDescriptor *(*type)(Sol32cEntry *); };
struct Sol32cCountedItems { unsigned words[6]; int count; };
struct Sol32cEntry { Sol32cEntryTable *table; unsigned words[5]; Sol32cCountedItems *items; };
struct Sol32cEntryCollection { unsigned words[6]; int size; unsigned word28; Sol32cEntry *entries[1]; };
struct Sol32cEntryOwner { unsigned words[8]; Sol32cEntryCollection *collection; };
struct Sol32cDispatchState { int selected; unsigned words4[4]; int active; unsigned words24[7]; float extent,position; unsigned words60[11]; void *resource; };
extern "C" void sol32c_clear_entries_802bf658(Sol32cDispatchState *);
extern "C" void *sol32c_resource_identity_80341584(void *);
extern "C" Sol32cEntryOwner *sol32c_resource_owner_801797b4(void *);
extern "C" void sol32c_dispatch_first_802bdf10(Sol32cDispatchState *,int,Sol32cEntryOwner *);
extern "C" void sol32c_dispatch_second_802be9e4(Sol32cDispatchState *,int,Sol32cEntryOwner *);
extern "C" void sol32c_dispatch_third_802c00dc(Sol32cDispatchState *,int,Sol32cEntryOwner *);
extern "C" void sol32c_refresh_entries_802bf81c(Sol32cDispatchState *);
extern Sol32cTypeDescriptor sol32c_first_type_80366258[];
extern Sol32cTypeDescriptor sol32c_second_type_803662f8[];
extern Sol32cTypeDescriptor sol32c_third_type_803662a8[];
extern const float sol32c_position_bias_803d83a8[];
inline bool sol32c_is_type(Sol32cTypeDescriptor *type,Sol32cTypeDescriptor *base) {
 while(type!=base) { Sol32cTypeDescriptor *parent=type->parent; if(type==parent) return false; type=parent; }
 return true;
}
typedef char Sol32cPointerWidth[(sizeof(void *)==4)?1:-1];
typedef char Sol32cDescriptorSize[(sizeof(Sol32cTypeDescriptor)==24)?1:-1];
typedef char Sol32cDispatchSize[(sizeof(Sol32cDispatchState)==108)?1:-1];
extern "C" void sol32c_dispatch_typed_entries_802bdd24(Sol32cDispatchState *self) {
 if(self->active) {
  sol32c_clear_entries_802bf658(self);
  if(self->resource && self->selected>=0) {
   Sol32cEntryOwner *owner=sol32c_resource_owner_801797b4(sol32c_resource_identity_80341584(self->resource));
   Sol32cEntryCollection *collection=owner->collection;
   int size=collection->size;
   Sol32cEntry **entries=collection->entries;
   if(size && entries[0]->items->count>self->selected) {
    self->position=self->extent+self->extent-sol32c_position_bias_803d83a8[0];
    int index=0;
    do {
     int next=index+1;
     Sol32cEntry *entry=entries[index];
     if(sol32c_is_type(entry->table->type(entry),sol32c_first_type_80366258))
      sol32c_dispatch_first_802bdf10(self,index,owner);
     else {
      entry=entries[index];
      if(sol32c_is_type(entry->table->type(entry),sol32c_second_type_803662f8))
       sol32c_dispatch_second_802be9e4(self,index,owner);
      else {
       entry=entries[index];
       if(sol32c_is_type(entry->table->type(entry),sol32c_third_type_803662a8))
        sol32c_dispatch_third_802c00dc(self,index,owner);
      }
     }
     index=next;
    } while(size!=index);
    sol32c_refresh_entries_802bf81c(self);
   }
  }
 }
}

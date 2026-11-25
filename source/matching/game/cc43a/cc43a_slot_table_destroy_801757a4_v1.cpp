// Partial inferred object and interface views. Unknown bytes describe observed
// offsets only, not a recovered complete class or its original sizeof.
struct cc43a_Held;
struct cc43a_HeldVtable { void* unknown00[4]; void (*release)(cc43a_Held*); };
struct cc43a_Held { cc43a_HeldVtable* vtable; };
struct cc43a_HeldSlot { cc43a_Held* p; ~cc43a_HeldSlot() { if(p) p->vtable->release(p); } };
struct cc43a_SlotTable { void* vtable; unsigned char unknown04[20]; cc43a_HeldSlot* slots; void* storage; unsigned char unknown20[2064]; void* array; unsigned int unknown834; void* tailStorage; };
extern "C" void* cc43a_tableVtable_80412250[];
extern "C" void* cc43a_baseVtable_80412318[];
extern "C" cc43a_SlotTable* cc43a_globalTable_804ab5c4;
extern "C" void cc43a_release_all_801758e8(cc43a_SlotTable*);
extern "C" void cc43a_array_free_801fe240(void*);
extern "C" void cc43a_storage_free_802134fc(void*);
extern "C" void cc43a_base_destroy_80210990(void*,unsigned int);
extern "C" void cc43a_delete_801fe1f8(void*);
extern "C" void cc43a_slot_table_destroy_801757a4(cc43a_SlotTable* self,unsigned int flags) {
 self->vtable=cc43a_tableVtable_80412250;
 cc43a_release_all_801758e8(self);
 cc43a_globalTable_804ab5c4=0;
 if(self->array) cc43a_array_free_801fe240(self->array);
 void* base=(unsigned char*)self+4;
 delete [] self->slots;
 if(self->tailStorage) cc43a_storage_free_802134fc(self->tailStorage);
 if(self->storage) cc43a_storage_free_802134fc(self->storage);
 self->vtable=cc43a_baseVtable_80412318;
 cc43a_base_destroy_80210990(base,0);
 if(flags&1) cc43a_delete_801fe1f8(self);
}

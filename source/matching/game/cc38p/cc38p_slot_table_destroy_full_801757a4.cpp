// Release-all integer result witnessed in original801758e8 and admitted source; ignored here.
// Partial inferred object and interface views. Unknown bytes describe observed
// offsets only, not a recovered complete class or its original sizeof.
struct cc38p_Held;
struct cc38p_HeldVtable { void* unknown00[4]; void (*release)(cc38p_Held*); };
struct cc38p_Held { cc38p_HeldVtable* vtable; };
struct cc38p_HeldSlot { cc38p_Held* p; ~cc38p_HeldSlot() { if(p) p->vtable->release(p); } };
struct cc38p_SlotTable { void* vtable; unsigned char unknown04[20]; cc38p_HeldSlot* slots; void* storage; unsigned char unknown20[2064]; void* array; unsigned int unknown834; void* tailStorage; };
extern "C" void* cc38p_tableVtable_80412250[];
extern "C" void* cc38p_baseVtable_80412318[];
extern "C" cc38p_SlotTable* cc38p_globalTable_804ab5c4;
extern "C" int cc38p_release_all_801758e8(cc38p_SlotTable*);
extern "C" void cc38p_array_free_801fe240(void*);
extern "C" void cc38p_storage_free_802134fc(void*);
extern "C" void cc38p_base_destroy_80210990(void*,unsigned int);
extern "C" void cc38p_delete_801fe1f8(void*);
extern "C" void cc38p_slot_table_destroy_full_801757a4(cc38p_SlotTable* self,unsigned int flags) {
 self->vtable=cc38p_tableVtable_80412250;
 cc38p_release_all_801758e8(self);
 cc38p_globalTable_804ab5c4=0;
 if(self->array) cc38p_array_free_801fe240(self->array);
 void* base=(unsigned char*)self+4;
 delete [] self->slots;
 if(self->tailStorage) cc38p_storage_free_802134fc(self->tailStorage);
 if(self->storage) cc38p_storage_free_802134fc(self->storage);
 self->vtable=cc38p_baseVtable_80412318;
 cc38p_base_destroy_80210990(base,0);
 if(flags&1) cc38p_delete_801fe1f8(self);
}

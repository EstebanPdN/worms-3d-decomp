#include "w3d_ptr.h"
#line 1 "cc38p_slot_table_destroy_full_801757a4.cpp"
// Release-all integer result witnessed in original801758e8 and admitted source; ignored here.
// Partial inferred object and interface views. Unknown bytes describe observed
// offsets only, not a recovered complete class or its original sizeof.
struct cc38p_Held;
struct cc38p_HeldVtable { Ptr32<void> unknown00[4]; Ptr32<void (Ptr32<cc38p_Held>)> release; };
struct cc38p_Held { Ptr32<cc38p_HeldVtable> vtable; };
struct cc38p_HeldSlot { Ptr32<cc38p_Held> p; ~cc38p_HeldSlot() { if(p) p->vtable->release(p); } };
struct cc38p_SlotTable { Ptr32<void> vtable; unsigned char unknown04[20]; Ptr32<cc38p_HeldSlot> slots; Ptr32<void> storage; unsigned char unknown20[2064]; Ptr32<void> array; unsigned int unknown834; Ptr32<void> tailStorage; };
extern "C" Ptr32<void> cc38p_tableVtable_80412250[];
extern "C" Ptr32<void> cc38p_baseVtable_80412318[];
extern "C" Ptr32<cc38p_SlotTable> cc38p_globalTable_804ab5c4;
extern "C" int cc38p_release_all_801758e8(Ptr32<cc38p_SlotTable>);
extern "C" void cc38p_array_free_801fe240(Ptr32<void>);
extern "C" void cc38p_storage_free_802134fc(Ptr32<void>);
extern "C" void cc38p_base_destroy_80210990(Ptr32<void>,unsigned int);
extern "C" void cc38p_delete_801fe1f8(Ptr32<void>);
extern "C" void cc38p_slot_table_destroy_full_801757a4(Ptr32<cc38p_SlotTable> self,unsigned int flags) {
 self->vtable=cc38p_tableVtable_80412250;
 cc38p_release_all_801758e8(self);
 cc38p_globalTable_804ab5c4=0;
 if(self->array) cc38p_array_free_801fe240(self->array);
 Ptr32<void> base=(Ptr32<unsigned char>)self+4;
 w3d::delete_array(self->slots);
 if(self->tailStorage) cc38p_storage_free_802134fc(self->tailStorage);
 if(self->storage) cc38p_storage_free_802134fc(self->storage);
 self->vtable=cc38p_baseVtable_80412318;
 cc38p_base_destroy_80210990(base,0);
 if(flags&1) cc38p_delete_801fe1f8(self);
}



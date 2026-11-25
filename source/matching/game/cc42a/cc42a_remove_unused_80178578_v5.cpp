// Inferred partial views: interface callbacks at 12/16, table at 24, free-bit
// array at 28. Lookup fills a 16-bit index; its full output contract is unknown.
struct cc42a_Entry;
struct cc42a_EntryVtable {void* unknown00[3];int (*retain)(cc42a_Entry*);int (*release)(cc42a_Entry*);};
struct cc42a_Entry {cc42a_EntryVtable* vtable;};
struct cc42a_TableOwner {unsigned char unknown00[24];cc42a_Entry** entries;unsigned int* freeBits;};
extern "C" int cc42a_find_80177eb0(cc42a_TableOwner*,void*,unsigned short*);
extern "C" void cc42a_refresh_801787ec(cc42a_TableOwner*);
inline cc42a_Entry*& cc42a_slot(cc42a_TableOwner* self,unsigned short index) {
 return *(cc42a_Entry**)((char*)self->entries+(index*4));
}
inline void cc42a_clearSlot(cc42a_TableOwner* self,unsigned short index) {
 cc42a_Entry*& slot=cc42a_slot(self,index);
 if(slot)slot->vtable->release(slot);
 slot=0;
}
extern "C" int cc42a_remove_unused_80178578(cc42a_TableOwner* self,void* key) {
 unsigned short index;
 int status=cc42a_find_80177eb0(self,key,&index);
 if(status<0)return status;
 cc42a_Entry* entry=*(cc42a_Entry**)((index*4)+(char*)self->entries);
 int count=entry->vtable->retain(entry);
 entry=*(cc42a_Entry**)((index*4)+(char*)self->entries);
 entry->vtable->release(entry);
 if(count!=2)return (int)0x80004005;
 cc42a_Entry** base=self->entries;
 int offset=index*4;
 cc42a_Entry** slot=(cc42a_Entry**)(offset+(char*)base);
 if(*slot)(*slot)->vtable->release(*slot);
 *slot=0;
 *(unsigned int*)((char*)self->freeBits+((index>>5)<<2)) |= 1u<<(index&31);
 cc42a_refresh_801787ec(self);
 return 0;
}

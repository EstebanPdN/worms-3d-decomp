// Inferred partial views: interface callbacks at 12/16, table at 24, free-bit
// array at 28. Lookup fills a 16-bit index; its full output contract is unknown.
struct cc42a_Entry;
struct cc42a_EntryVtable {void* unknown00[3];int (*retain)(cc42a_Entry*);int (*release)(cc42a_Entry*);void* unknown14[6]; int (*rename)(cc42a_Entry*,void*);};
struct cc42a_Entry {cc42a_EntryVtable* vtable;};
struct cc42a_TableOwner {unsigned char unknown00[24];cc42a_Entry** entries;unsigned int* freeBits;};
extern "C" int cc42a_find_80177eb0(cc42a_TableOwner*,void*,unsigned short*);
extern "C" void cc42a_refresh_801787ec(cc42a_TableOwner*);
extern "C" int cc42a_move_unused_80178668(cc42a_TableOwner* self,void* oldKey,void* newKey) {
 unsigned short oldIndex,newIndex;
 int status=cc42a_find_80177eb0(self,oldKey,&oldIndex);
 if(status<0)return status;
 cc42a_Entry* entry=*(cc42a_Entry**)((oldIndex*4)+(char*)self->entries);
 int count=entry->vtable->retain(entry);
 entry=*(cc42a_Entry**)((oldIndex*4)+(char*)self->entries);
 entry->vtable->release(entry);
 if(count!=2 || cc42a_find_80177eb0(self,newKey,&newIndex)>=0)return (int)0x80004005;
 unsigned int from=oldIndex;
 cc42a_Entry** base=self->entries;
 unsigned int to=newIndex;
 cc42a_Entry* incoming=(*(cc42a_Entry**)(from*4+(char*)base));
 if(incoming)incoming->vtable->retain(incoming);
 cc42a_Entry* outgoing=(*(cc42a_Entry**)(to*4+(char*)base));
 if(outgoing)outgoing->vtable->release(outgoing);
 (*(cc42a_Entry**)(to*4+(char*)base))=(*(cc42a_Entry**)(from*4+(char*)base));
 unsigned int savedIndex=oldIndex;
 base=self->entries;
 if((*(cc42a_Entry**)(savedIndex*4+(char*)base)))(*(cc42a_Entry**)(savedIndex*4+(char*)base))->vtable->release((*(cc42a_Entry**)(savedIndex*4+(char*)base)));
 (*(cc42a_Entry**)(savedIndex*4+(char*)base))=0;
 entry=*(cc42a_Entry**)((newIndex*4)+(char*)self->entries);
 entry->vtable->rename(entry,newKey);
 *(unsigned int*)((char*)self->freeBits+((oldIndex>>5)<<2)) |= 1u<<(oldIndex&31);
 cc42a_refresh_801787ec(self);
 return 0;
}

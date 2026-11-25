#include "w3d_ptr.h"
#line 1 "cc42a_remove_unused_80178578_v10.cpp"
// Inferred partial views: interface callbacks at 12/16, table at 24, free-bit
// array at 28. Lookup fills a 16-bit index; its full output contract is unknown.
struct cc42a_Entry;
struct cc42a_EntryVtable {Ptr32<void> unknown00[3];Ptr32<int (Ptr32<cc42a_Entry>)> retain;Ptr32<int (Ptr32<cc42a_Entry>)> release;};
struct cc42a_Entry {Ptr32<cc42a_EntryVtable> vtable;};
struct cc42a_TableOwner {unsigned char unknown00[24];Ptr32<Ptr32<cc42a_Entry>> entries;Ptr32<unsigned int> freeBits;};
extern "C" int cc42a_find_80177eb0(Ptr32<cc42a_TableOwner>,Ptr32<void>,Ptr32<unsigned short>);
extern "C" void cc42a_refresh_801787ec(Ptr32<cc42a_TableOwner>);
extern "C" int cc42a_remove_unused_80178578(Ptr32<cc42a_TableOwner> self,Ptr32<void> key) {
 unsigned short index;
 int status=cc42a_find_80177eb0(self,key,&index);
 if(status<0)return status;
 Ptr32<cc42a_Entry> entry=*(Ptr32<Ptr32<cc42a_Entry>>)((index*4)+(Ptr32<char>)self->entries);
 int count=entry->vtable->retain(entry);
 entry=*(Ptr32<Ptr32<cc42a_Entry>>)((index*4)+(Ptr32<char>)self->entries);
 entry->vtable->release(entry);
 if(count!=2)return (int)0x80004005;
 unsigned int savedIndex=index;
 Ptr32<Ptr32<cc42a_Entry>> base=self->entries;
 if((*(Ptr32<Ptr32<cc42a_Entry>>)(savedIndex*4+(Ptr32<char>)base)))(*(Ptr32<Ptr32<cc42a_Entry>>)(savedIndex*4+(Ptr32<char>)base))->vtable->release((*(Ptr32<Ptr32<cc42a_Entry>>)(savedIndex*4+(Ptr32<char>)base)));
 (*(Ptr32<Ptr32<cc42a_Entry>>)(savedIndex*4+(Ptr32<char>)base))=0;
 *(Ptr32<unsigned int>)((Ptr32<char>)self->freeBits+((index>>5)<<2)) |= 1u<<(index&31);
 cc42a_refresh_801787ec(self);
 return 0;
}



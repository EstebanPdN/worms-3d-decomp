#include "w3d_ptr.h"
#line 1 "cc39b_read_refs_801e7044.cpp"
// Partial interfaces: only the observed virtual release/read slots are typed.
// The leading argument is unused in the original; errors exit before replacement.
typedef unsigned int cc39b_u32;
struct cc39b_Ref;
struct cc39b_RefTable { Ptr32<void (void)> slots[4];Ptr32<void (Ptr32<cc39b_Ref>)> release; };
struct cc39b_Ref { Ptr32<cc39b_RefTable> vtable; };
struct cc39b_Reader;
struct cc39b_ReaderTable { Ptr32<void (void)> slots[8];Ptr32<int (Ptr32<cc39b_Reader>, Ptr32<Ptr32<cc39b_Ref>>, cc39b_u32)> read; };
struct cc39b_Reader { Ptr32<cc39b_ReaderTable> vtable; };
extern "C" int cc39b_read_refs_801e7044(Ptr32<void>,Ptr32<cc39b_Reader> reader,Ptr32<Ptr32<cc39b_Ref>> items,cc39b_u32 mode,cc39b_u32 count) {
 for(cc39b_u32 i=0;i<count;++i) {
  Ptr32<cc39b_Ref> incoming=0;
  int result=reader->vtable->read(reader,&incoming,mode);
  if(result<0) return result;
  if(items[i]) items[i]->vtable->release(items[i]);
  items[i]=incoming;
 }
 return 0;
}



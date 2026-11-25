#include "w3d_ptr.h"
#line 1 "cc40a_pattern_table_8017c12c.cpp"
// Partial interface views inferred from the original vtable slots and field offsets.
// These views do not establish complete class declarations or object sizes.
struct cc40a_Pattern;
struct cc40a_Table;
struct cc40a_PatternVtable { Ptr32<void> reserved[8]; Ptr32<int (Ptr32<cc40a_Pattern>)> refresh; };
struct cc40a_Pattern { Ptr32<cc40a_PatternVtable> vtable; unsigned char unknown04[16]; unsigned int flags; };
struct cc40a_TableVtable {
 Ptr32<void> reserved00[19]; Ptr32<int (Ptr32<cc40a_Table>, unsigned int)> resize;
 Ptr32<void> reserved50; Ptr32<int (Ptr32<cc40a_Table>, unsigned int, unsigned int)> setIndex;
 Ptr32<void> reserved58; Ptr32<int (Ptr32<cc40a_Table>, unsigned int, unsigned int)> setValue;
};
struct cc40a_Table { Ptr32<cc40a_TableVtable> vtable; };
extern "C" int cc40a_pattern_table_8017c12c(Ptr32<cc40a_Pattern> self,Ptr32<cc40a_Table> table) {
 if((int)self->flags<0) { int result=self->vtable->refresh(self); if(result<0)return result; }
 self->flags |= 0x80000000u;
 table->vtable->resize(table,129);
 table->vtable->setValue(table,0,0);
 table->vtable->setValue(table,1,1);
 for(unsigned int index=0;index<64;++index) {
  if(index&1)table->vtable->setIndex(table,index,1);
  else table->vtable->setIndex(table,index,0);
 }
 table->vtable->setIndex(table,128,3);
 return 0;
}



#include "w3d_ptr.h"
#line 1 "cx10b_descriptor_visit_array_80200620.cpp"
// Observed PPC32 field records: identifier +0, byte displacement +6, handler +8, stride twelve.
struct Stream;struct Field;
struct StreamVtable {Ptr32<void> reserved[6];Ptr32<int (Ptr32<Stream>, unsigned int, int)> begin;Ptr32<int (Ptr32<Stream>, unsigned int)> end;};
struct Stream {Ptr32<StreamVtable> vtable;};
struct FieldVtable {Ptr32<void> reserved[15];Ptr32<int (Ptr32<Field>, Ptr32<Stream>, Ptr32<unsigned char>, unsigned int, int, Ptr32<void>)> visit;};
struct Field {Ptr32<FieldVtable> vtable;};
struct FieldRecord {unsigned int identifier;unsigned short unknown,offset;Ptr32<Field> handler;};
struct Descriptor {unsigned char opaque[6];unsigned short stride;unsigned char middle[9];unsigned char count;unsigned char tail[10];Ptr32<FieldRecord> fields;};
extern "C" Ptr32<Descriptor> descriptor_80200460(Ptr32<void>);
extern "C" int w3d_cx10b_descriptor_visit_array_80200620(Ptr32<void> self,Ptr32<Stream> stream,Ptr32<unsigned char> data,unsigned int tag,unsigned int count,Ptr32<void> context) {
 unsigned int item=0;
 Ptr32<Descriptor> descriptor=descriptor_80200460(self);
 unsigned int fieldCount=descriptor->count;
 for(;item<count;++item) {
  stream->vtable->begin(stream,tag,0);
  for(unsigned int field=0;field<fieldCount;++field) {
   FieldRecord &record=descriptor->fields[field];
   record.handler->vtable->visit(record.handler,stream,data+record.offset,record.identifier,1,context);
  }
  stream->vtable->end(stream,tag);
  data+=descriptor->stride;
 }
 return 0;
}




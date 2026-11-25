#include "w3d_ptr.h"
#line 1 "cx11b_descriptor_write_array_80200714.cpp"
// Observed PPC32 field records: identifier +0, byte displacement +6, handler +8, stride twelve.
struct Stream;struct Field;
struct StreamVtable {Ptr32<void> reserved[6];Ptr32<int (Ptr32<Stream>, unsigned int, int)> begin;Ptr32<int (Ptr32<Stream>, unsigned int)> end;Ptr32<void> extra[37];Ptr32<int (Ptr32<Stream>)> isSpecial;};
struct Stream {Ptr32<StreamVtable> vtable;};
struct FieldVtable {Ptr32<void> reserved[16];Ptr32<int (Ptr32<Field>, Ptr32<Stream>, Ptr32<unsigned char>, unsigned int, int, Ptr32<void>)> visit;};
struct Field {Ptr32<FieldVtable> vtable;};
struct FieldRecord {unsigned int identifier;unsigned short unknown,offset;Ptr32<Field> handler;};
struct Descriptor {unsigned char opaque[6];unsigned short stride;unsigned char middle[9];unsigned char count;unsigned char tail[10];Ptr32<FieldRecord> fields;};
extern "C" Ptr32<Descriptor> descriptor_80200460(Ptr32<void>);
struct Owner {unsigned char opaque[20];unsigned int flags;};
extern "C" void prepare_80200884(Ptr32<void>);
extern "C" int w3d_cx11b_descriptor_write_array_80200714(Ptr32<void> self,Ptr32<Stream> stream,Ptr32<unsigned char> data,unsigned int tag,unsigned int count,Ptr32<void> context) {
 Ptr32<Descriptor> descriptor=descriptor_80200460(self);
 unsigned int fieldCount=descriptor->count;
 prepare_80200884(self);
 if(stream->vtable->isSpecial(stream)==0 && (((Ptr32<Owner>)self)->flags&3)==3){FieldRecord &record=descriptor->fields[0];return record.handler->vtable->visit(record.handler,stream,data+record.offset,record.identifier,fieldCount*count,context);}
 for(unsigned int item=0;item<count;++item) {
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





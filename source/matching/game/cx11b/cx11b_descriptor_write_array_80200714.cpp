// Observed PPC32 field records: identifier +0, byte displacement +6, handler +8, stride twelve.
struct Stream;struct Field;
struct StreamVtable {void *reserved[6];int (*begin)(Stream *,unsigned int,int);int (*end)(Stream *,unsigned int);void *extra[37];int (*isSpecial)(Stream *);};
struct Stream {StreamVtable *vtable;};
struct FieldVtable {void *reserved[16];int (*visit)(Field *,Stream *,unsigned char *,unsigned int,int,void *);};
struct Field {FieldVtable *vtable;};
struct FieldRecord {unsigned int identifier;unsigned short unknown,offset;Field *handler;};
struct Descriptor {unsigned char opaque[6];unsigned short stride;unsigned char middle[9];unsigned char count;unsigned char tail[10];FieldRecord *fields;};
extern "C" Descriptor *descriptor_80200460(void *);
struct Owner {unsigned char opaque[20];unsigned int flags;};
extern "C" void prepare_80200884(void *);
extern "C" int w3d_cx11b_descriptor_write_array_80200714(void *self,Stream *stream,unsigned char *data,unsigned int tag,unsigned int count,void *context) {
 Descriptor *descriptor=descriptor_80200460(self);
 unsigned int fieldCount=descriptor->count;
 prepare_80200884(self);
 if(stream->vtable->isSpecial(stream)==0 && (((Owner *)self)->flags&3)==3){FieldRecord &record=descriptor->fields[0];return record.handler->vtable->visit(record.handler,stream,data+record.offset,record.identifier,fieldCount*count,context);}
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



// Observed PPC32 field records: identifier +0, byte displacement +6, handler +8, stride twelve.
struct Stream;struct Field;
struct StreamVtable {void *reserved[6];int (*begin)(Stream *,unsigned int,int);int (*end)(Stream *,unsigned int);};
struct Stream {StreamVtable *vtable;};
struct FieldVtable {void *reserved[15];int (*visit)(Field *,Stream *,unsigned char *,unsigned int,int,void *);};
struct Field {FieldVtable *vtable;};
struct FieldRecord {unsigned int identifier;unsigned short unknown,offset;Field *handler;};
struct Descriptor {unsigned char opaque[6];unsigned short stride;unsigned char middle[9];unsigned char count;unsigned char tail[10];FieldRecord *fields;};
extern "C" Descriptor *descriptor_80200460(void *);
extern "C" int w3d_cx10b_descriptor_visit_array_80200620(void *self,Stream *stream,unsigned char *data,unsigned int tag,unsigned int count,void *context) {
 unsigned int item=0;
 Descriptor *descriptor=descriptor_80200460(self);
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


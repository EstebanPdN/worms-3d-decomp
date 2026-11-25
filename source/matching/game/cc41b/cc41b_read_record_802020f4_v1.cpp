// Original 0x802020f4. Each iteration reads sixteen bytes into the same destination.
// Only the first word and two halfwords are byte-swapped. The final eight bytes remain opaque.
struct cc41b_RecordStream;
struct cc41b_RecordStreamVtable { void *unknown[5]; int (*read)(cc41b_RecordStream *,void *,unsigned,int); void *unknown18; int (*seek)(cc41b_RecordStream *,unsigned,int,int); };
struct cc41b_RecordStream { cc41b_RecordStreamVtable *vtable; };
struct cc41b_RecordReader { unsigned char unknown[20]; cc41b_RecordStream *stream; };
struct cc41b_Record { unsigned word; unsigned short first,second; unsigned char opaque[8]; };
inline void cc41b_recordSwap32(unsigned &word){word= (word<<24)|((word&0xff00)<<8)|((word>>8)&0xff00)|(word>>24);}
inline void cc41b_recordSwap16(unsigned short &value){value= (value<<8)|(value>>8);}
extern "C" int cc41b_read_record_802020f4(cc41b_RecordReader *self,cc41b_Record *output,unsigned count) {
 if(!output)return self->stream->vtable->seek(self->stream,count*16,1,0);
 for(unsigned i=0;i<count;++i) {
  int status=self->stream->vtable->read(self->stream,output,16,0);
  if(status<0)return status;
  cc41b_recordSwap32(output->word);
  cc41b_recordSwap16(output->first);
  cc41b_recordSwap16(output->second);
 }
 return 0;
}

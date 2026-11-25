// Original 0x80201ea4. Inferred partial stream facade and virtual ABI; no data ownership.
// Unsigned count is converted to bytes; null output delegates relative skip.
struct cc41b_Stream;
struct cc41b_StreamVtable { void *unknown[5]; int (*read)(cc41b_Stream *,void *,unsigned,int); void *unknown18; int (*seek)(cc41b_Stream *,unsigned,int,int); };
struct cc41b_Stream { cc41b_StreamVtable *vtable; };
struct cc41b_Reader { unsigned char unknown[20]; cc41b_Stream *stream; };
inline void cc41b_swap32(unsigned &word){word=(word<<24)|((word&0xff00)<<8)|((word>>8)&0xff00)|(word>>24);}
inline void cc41b_swapWords(unsigned *output,unsigned count) {for(unsigned i=0;i<count;++i)cc41b_swap32(*output++);}
extern "C" void cc41b_read_words_80201ea4(cc41b_Reader *self,unsigned *output,unsigned count) {
 if(!output) self->stream->vtable->seek(self->stream,count*4,1,0);
 else {
  self->stream->vtable->read(self->stream,output,count*4,0);
  cc41b_swapWords(output,count);
 }
}

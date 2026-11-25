
struct Sink;
struct SinkVtable { void *reserved[6]; int (*write)(Sink *,const void *,unsigned int,int); };
struct Sink { SinkVtable *vtable; };
struct Writer { Sink *sink; };
extern "C" void *fill_802eefe0(void *,int,unsigned int);
static inline const unsigned int &minimum(const unsigned int &a,const unsigned int &b) { return b<a?b:a; }
extern "C" void w3d_cx9b_text_repeat_byte_8020d600(Writer *self,unsigned int count,int byte) {
 unsigned char block[64];
 unsigned int chunk=minimum((unsigned int)64,count);
 fill_802eefe0(block,byte,chunk);
 while(count) {
  unsigned int amount=minimum(count,chunk);
  self->sink->vtable->write(self->sink,block,amount,0);
  count-=amount;
 }
}


#include "w3d_ptr.h"
#line 1 "cx9b_text_repeat_byte_8020d600.cpp"

struct Sink;
struct SinkVtable { Ptr32<void> reserved[6]; Ptr32<int (Ptr32<Sink>, Ptr32<const void>, unsigned int, int)> write; };
struct Sink { Ptr32<SinkVtable> vtable; };
struct Writer { Ptr32<Sink> sink; };
extern "C" Ptr32<void> fill_802eefe0(Ptr32<void>,int,unsigned int);
static inline const unsigned int &minimum(const unsigned int &a,const unsigned int &b) { return b<a?b:a; }
extern "C" void w3d_cx9b_text_repeat_byte_8020d600(Ptr32<Writer> self,unsigned int count,int byte) {
 unsigned char block[64];
 unsigned int chunk=minimum((unsigned int)64,count);
 fill_802eefe0(block,byte,chunk);
 while(count) {
  unsigned int amount=minimum(count,chunk);
  self->sink->vtable->write(self->sink,block,amount,0);
  count-=amount;
 }
}




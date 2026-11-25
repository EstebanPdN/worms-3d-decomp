#include "w3d_ptr.h"
#line 1 "cx10b_buffered_stream_read_80219610.cpp"
// Inferred buffered stream; observed PPC32 fields at offsets twenty through forty.
struct Stream;
struct StreamVtable {Ptr32<void> reserved[5];Ptr32<int (Ptr32<Stream>, Ptr32<void>, unsigned int, Ptr32<unsigned int>)> read;Ptr32<void> write;Ptr32<int (Ptr32<Stream>, unsigned int, int, Ptr32<unsigned int>)> seek;};
struct Stream {Ptr32<StreamVtable> vtable;};
struct Buffered {unsigned char opaque[20];Ptr32<Stream> stream;unsigned int capacity;Ptr32<unsigned char> buffer;unsigned int base,valid,position;};

extern "C" int refill_802198bc(Ptr32<Buffered>,unsigned int);
extern "C" Ptr32<void> copy_802eee50(Ptr32<void>,Ptr32<const void>,unsigned int);
static inline const unsigned int &minimum(const unsigned int &a,const unsigned int &b){return b<a?b:a;}
extern "C" int w3d_cx10b_buffered_stream_read_80219610(Ptr32<Buffered> self,Ptr32<unsigned char> out,unsigned int requested,Ptr32<unsigned int> transferred) {
 if(transferred)*transferred=0;
 while(requested) {
  int status=refill_802198bc(self,self->position & -self->capacity);
  if(status<0 && status!=(int)0x90000001) return status;
  unsigned int count=minimum((unsigned int)(self->valid-(self->position-self->base)),requested);
  copy_802eee50(out,self->buffer+self->position-self->base,count);
  out+=count;requested-=count;self->position+=count;
  if(transferred)*transferred+=count;
  if(!count)break;
 }
 return 0;
}





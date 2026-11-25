#include "w3d_ptr.h"
#line 1 "cx10b_buffer_refill_802198bc.cpp"
// Inferred buffered stream; observed PPC32 fields at offsets twenty through forty.
struct Stream;
struct StreamVtable {Ptr32<void> reserved[5];Ptr32<int (Ptr32<Stream>, Ptr32<void>, unsigned int, Ptr32<unsigned int>)> read;Ptr32<void> write;Ptr32<int (Ptr32<Stream>, unsigned int, int, Ptr32<unsigned int>)> seek;};
struct Stream {Ptr32<StreamVtable> vtable;};
struct Buffered {unsigned char opaque[20];Ptr32<Stream> stream;unsigned int capacity;Ptr32<unsigned char> buffer;unsigned int base,valid,position;};

extern "C" Ptr32<void> allocate_801fe2a8(unsigned int,unsigned int);
extern "C" int w3d_cx10b_buffer_refill_802198bc(Ptr32<Buffered> self,unsigned int offset) {
 if(!self->buffer) {self->buffer=(Ptr32<unsigned char>)allocate_801fe2a8(self->capacity,32);self->valid=0;}
 if(self->base==offset && self->valid) return 0;
 unsigned int position=0;
 int status=self->stream->vtable->seek(self->stream,0,1,&position);
 if(status<0) return status;
 if(position!=offset) {status=self->stream->vtable->seek(self->stream,offset,0,0);if(status<0)return status;}
 unsigned int count;
 status=self->stream->vtable->read(self->stream,self->buffer,self->capacity,&count);
 self->base=offset;self->valid=count;
 return status;
}




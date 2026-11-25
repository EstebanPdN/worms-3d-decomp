#include "w3d_ptr.h"
#line 1 "cx9b_pending_header_write_802086dc.cpp"

struct Sink;
struct SinkVtable { Ptr32<void> reserved[6]; Ptr32<int (Ptr32<Sink>, Ptr32<const void>, unsigned int, int)> write; };
struct Sink { Ptr32<SinkVtable> vtable; };
// Inferred PPC32: sink +28, header bytes +32, pending +36; length is u16 at header-4.
struct Writer { unsigned char reserved[28]; Ptr32<Sink> sink; Ptr32<const unsigned char> header; int pending; };
extern "C" int w3d_cx9b_pending_header_write_802086dc(Ptr32<Writer> self,Ptr32<const void> data,unsigned int bytes) {
 if(self->pending) {
  int status=self->sink->vtable->write(self->sink,self->header,((Ptr32<const unsigned short>)self->header)[-2],0);
  if(status<0) return status;
  self->pending=0;
 }
 return self->sink->vtable->write(self->sink,data,bytes,0);
}




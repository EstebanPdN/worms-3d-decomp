#include "w3d_ptr.h"
#line 1 "cx16c_stream_mode_write_802047e0.cpp"

// Observed selected stream +20, mode +24. Other modes return failure.
struct Cx16cWriterStream { Ptr32<Ptr32<void>> methods; };
struct Cx16cWriter { char reserved[20]; Ptr32<Cx16cWriterStream> stream; int mode; };
extern "C" unsigned w3d_cx16c_stream_mode_write_802047e0(Ptr32<Cx16cWriter> self,Ptr32<void> buffer,int length) {
 switch(self->mode) {
 case 1: return 0;
 case 2: {
  Ptr32<Cx16cWriterStream> stream=self->stream;
  return ((Ptr32<unsigned int (Ptr32<Cx16cWriterStream>, Ptr32<void>, int, int)>)stream->methods[6])(stream,buffer,length,0);
 }
 case 0: return 0x80004005U;
 case 3: return 0x80004005U;
 }
 return 0x80004005U;
}




// Observed selected stream +20, mode +24. Other modes return failure.
struct Cx16cWriterStream { void **methods; };
struct Cx16cWriter { char reserved[20]; Cx16cWriterStream *stream; int mode; };
extern "C" unsigned w3d_cx16c_stream_mode_write_802047e0(Cx16cWriter *self,void *buffer,int length) {
 switch(self->mode) {
 case 1: return 0;
 case 2: {
  Cx16cWriterStream *stream=self->stream;
  return ((unsigned(*)(Cx16cWriterStream*,void*,int,int))stream->methods[6])(stream,buffer,length,0);
 }
 case 0: return 0x80004005U;
 case 3: return 0x80004005U;
 }
 return 0x80004005U;
}

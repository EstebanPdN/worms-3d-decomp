
struct Sink;
struct SinkVtable { void *reserved[6]; int (*write)(Sink *,const void *,unsigned int,int); };
struct Sink { SinkVtable *vtable; };
// Inferred PPC32: sink +28, header bytes +32, pending +36; length is u16 at header-4.
struct Writer { unsigned char reserved[28]; Sink *sink; const unsigned char *header; int pending; };
extern "C" int w3d_cx9b_pending_header_write_802086dc(Writer *self,const void *data,unsigned int bytes) {
 if(self->pending) {
  int status=self->sink->vtable->write(self->sink,self->header,((const unsigned short *)self->header)[-2],0);
  if(status<0) return status;
  self->pending=0;
 }
 return self->sink->vtable->write(self->sink,data,bytes,0);
}


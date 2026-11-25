// Inferred buffered stream; observed PPC32 fields at offsets twenty through forty.
struct Stream;
struct StreamVtable {void *reserved[5];int (*read)(Stream *,void *,unsigned int,unsigned int *);void *write;int (*seek)(Stream *,unsigned int,int,unsigned int *);};
struct Stream {StreamVtable *vtable;};
struct Buffered {unsigned char opaque[20];Stream *stream;unsigned int capacity;unsigned char *buffer;unsigned int base,valid,position;};

extern "C" void *allocate_801fe2a8(unsigned int,unsigned int);
extern "C" int w3d_cx10b_buffer_refill_802198bc(Buffered *self,unsigned int offset) {
 if(!self->buffer) {self->buffer=(unsigned char *)allocate_801fe2a8(self->capacity,32);self->valid=0;}
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


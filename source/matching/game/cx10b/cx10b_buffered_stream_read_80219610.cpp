// Inferred buffered stream; observed PPC32 fields at offsets twenty through forty.
struct Stream;
struct StreamVtable {void *reserved[5];int (*read)(Stream *,void *,unsigned int,unsigned int *);void *write;int (*seek)(Stream *,unsigned int,int,unsigned int *);};
struct Stream {StreamVtable *vtable;};
struct Buffered {unsigned char opaque[20];Stream *stream;unsigned int capacity;unsigned char *buffer;unsigned int base,valid,position;};

extern "C" int refill_802198bc(Buffered *,unsigned int);
extern "C" void *copy_802eee50(void *,const void *,unsigned int);
static inline const unsigned int &minimum(const unsigned int &a,const unsigned int &b){return b<a?b:a;}
extern "C" int w3d_cx10b_buffered_stream_read_80219610(Buffered *self,unsigned char *out,unsigned int requested,unsigned int *transferred) {
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



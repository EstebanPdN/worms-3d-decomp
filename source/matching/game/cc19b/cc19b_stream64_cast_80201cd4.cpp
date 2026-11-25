// Observed 64-bit transfer and word-swap helper call; helper semantics stay address-named.
struct Cc19bStream;
struct Cc19bStreamTable { void *unknown[5]; int (*transfer)(Cc19bStream *,void *,int,int); void *unknown24; int (*skip)(Cc19bStream *,int,int,int); };
struct Cc19bStream { Cc19bStreamTable *vt; };
struct Cc19bStreamOwner { unsigned char unknown[20]; Cc19bStream *stream; };
extern "C" unsigned long long fn_8035b260(unsigned long long);
static inline unsigned int cc19bSwap32(unsigned int v) {
 return (v<<24) | ((v&0xff00)<<8) | ((v>>8)&0xff00) | (v>>24);
}
static inline unsigned long long cc19bSwap64(unsigned long long v) {
 return fn_8035b260((unsigned long long)(unsigned int)v<<32) | cc19bSwap32((unsigned int)(v>>32));
}
extern "C" int w3d_cc19b_stream64_cast_80201cd4(Cc19bStreamOwner *self,unsigned long long *buffer,unsigned int count) {
 if (!buffer) { Cc19bStream *stream=self->stream; return stream->vt->skip(stream,count<<3,1,0); }
 Cc19bStream *stream=self->stream;
 int result=stream->vt->transfer(stream,buffer,count<<3,0);
 for(unsigned int i=0;i<count;i++) { unsigned long long *p=buffer++; *p=cc19bSwap64(*p); }
 return result;
}

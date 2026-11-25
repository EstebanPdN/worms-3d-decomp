#include "w3d_ptr.h"
#line 1 "cc19b_stream64_cast_80201dbc.cpp"
// Observed 64-bit transfer and word-swap helper call; helper semantics stay address-named.
struct Cc19bStream;
struct Cc19bStreamTable { Ptr32<void> unknown[5]; Ptr32<int (Ptr32<Cc19bStream>, Ptr32<void>, int, int)> transfer; Ptr32<void> unknown24; Ptr32<int (Ptr32<Cc19bStream>, int, int, int)> skip; };
struct Cc19bStream { Ptr32<Cc19bStreamTable> vt; };
struct Cc19bStreamOwner { unsigned char unknown[20]; Ptr32<Cc19bStream> stream; };
extern "C" unsigned long long fn_8035b260(unsigned long long);
static inline unsigned int cc19bSwap32(unsigned int v) {
 return (v<<24) | ((v&0xff00)<<8) | ((v>>8)&0xff00) | (v>>24);
}
static inline unsigned long long cc19bSwap64(unsigned long long v) {
 return fn_8035b260((unsigned long long)(unsigned int)v<<32) | cc19bSwap32((unsigned int)(v>>32));
}
extern "C" int w3d_cc19b_stream64_cast_80201dbc(Ptr32<Cc19bStreamOwner> self,Ptr32<unsigned long long> buffer,unsigned int count) {
 if (!buffer) { Ptr32<Cc19bStream> stream=self->stream; return stream->vt->skip(stream,count<<3,1,0); }
 Ptr32<Cc19bStream> stream=self->stream;
 int result=stream->vt->transfer(stream,buffer,count<<3,0);
 for(unsigned int i=0;i<count;i++) { Ptr32<unsigned long long> p=buffer++; *p=cc19bSwap64(*p); }
 return result;
}



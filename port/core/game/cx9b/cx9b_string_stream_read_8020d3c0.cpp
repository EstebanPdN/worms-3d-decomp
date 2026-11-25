#include "w3d_ptr.h"
#line 1 "cx9b_string_stream_read_8020d3c0.cpp"

struct SharedString { Ptr32<unsigned char> bytes; };
struct Reader { unsigned char reserved[20]; Ptr32<SharedString> string; unsigned int position; };
extern "C" Ptr32<void> copy_802eee50(Ptr32<void>,Ptr32<const void>,unsigned int);
static inline const unsigned int &minimum(const unsigned int &a,const unsigned int &b) { return b<a?b:a; }
extern "C" int w3d_cx9b_string_stream_read_8020d3c0(Ptr32<Reader> self,Ptr32<void> destination,unsigned int requested,Ptr32<unsigned int> read) {
 unsigned int count=minimum((unsigned int)(((Ptr32<unsigned short>)self->string->bytes)[-2]-self->position),requested);
 copy_802eee50(destination,self->string->bytes+self->position,count);
 if(read) *read=count;
 self->position+=count;
 return 0;
}




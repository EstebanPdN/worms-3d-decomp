#include "w3d_ptr.h"
#line 1 "cx9b_buffered_stream_seek_80219790.cpp"

struct Stream;
struct StreamVtable { Ptr32<void> reserved[9]; Ptr32<int (Ptr32<Stream>, Ptr32<unsigned int>)> size; };
struct Stream { Ptr32<StreamVtable> vtable; };
struct BufferedStream { unsigned char reserved[20]; Ptr32<Stream> backing; unsigned char gap[16]; unsigned int position; };
extern "C" int w3d_cx9b_buffered_stream_seek_80219790(Ptr32<BufferedStream> self,unsigned int offset,int origin,Ptr32<unsigned int> previous) {
 if(previous) *previous=self->position;
 switch(origin) {
 case 1: self->position+=offset;break;
 case 2: { unsigned int end[4]; int status=self->backing->vtable->size(self->backing,end);if(status<0)return status;self->position=end[0]+offset;break; }
 case 0:self->position=offset;break;
 default:return (int)0x80070057;
 }
 return 0;
}




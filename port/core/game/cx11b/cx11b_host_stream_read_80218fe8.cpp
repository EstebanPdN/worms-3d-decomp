#include "w3d_ptr.h"
#line 1 "cx11b_host_stream_read_80218fe8.cpp"
// PPC32 host handle +24; data/count are forwarded even though Ghidra drops unchanged r4/r5 in its prototype.
struct Stream {unsigned char opaque[24];int handle;};extern "C" int read_802e4cf4(int,Ptr32<void>,unsigned int);extern "C" void trace_80347324(Ptr32<void>,Ptr32<const char>,...);extern unsigned int trace_context_804b0640;extern const char format_803b393c[];
extern "C" int w3d_cx11b_host_stream_read_80218fe8(Ptr32<Stream> self,Ptr32<void> bytes,unsigned int count,Ptr32<int> out){int transferred=read_802e4cf4(self->handle,bytes,count);trace_80347324(&trace_context_804b0640,format_803b393c,self->handle,w3d::VA(bytes),count,transferred);if(out)*out=transferred;if(transferred!=0){int status=(int)0x80004005;if(transferred>=0)status=0;return status;}else return (int)0x90000001;}





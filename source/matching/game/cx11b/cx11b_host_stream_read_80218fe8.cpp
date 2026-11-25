// PPC32 host handle +24; data/count are forwarded even though Ghidra drops unchanged r4/r5 in its prototype.
struct Stream {unsigned char opaque[24];int handle;};extern "C" int read_802e4cf4(int,void *,unsigned int);extern "C" void trace_80347324(void *,const char *,...);extern unsigned int trace_context_804b0640;extern const char format_803b393c[];
extern "C" int w3d_cx11b_host_stream_read_80218fe8(Stream *self,void *bytes,unsigned int count,int *out){int transferred=read_802e4cf4(self->handle,bytes,count);trace_80347324(&trace_context_804b0640,format_803b393c,self->handle,bytes,count,transferred);if(out)*out=transferred;if(transferred!=0){int status=(int)0x80004005;if(transferred>=0)status=0;return status;}else return (int)0x90000001;}



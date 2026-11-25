// PPC32 stream member +20; virtual read +20. Original heap buffer stays allocated on read failure.
struct Stream;struct Vtable {void *unused[5];int (*read)(Stream *,void *,unsigned int,void *);};struct Stream {Vtable *vtable;};struct Reader {unsigned char opaque[20];Stream *stream;};
extern "C" void *allocate_80209060(unsigned int);
extern "C" void release_801fe288(void *);
extern "C" int compare_802eedc0(const void *,const void *,unsigned int);
extern "C" int w3d_cx11b_stream_compare_bytes_802022f4(Reader *self,const void *expected,unsigned int size){int status;char local[64];if(size<64){status=self->stream->vtable->read(self->stream,local,size,0);if(status<0)return status;int same=compare_802eedc0(local,expected,size);if(!same)return 0;return (int)0x80004005;}
 else {void *buffer=allocate_80209060(size);status=self->stream->vtable->read(self->stream,buffer,size,0);if(status<0)return status;int same=compare_802eedc0(buffer,expected,size);status=(int)0x80004005;if(!same)status=0;release_801fe288(buffer);return status;}return status;}




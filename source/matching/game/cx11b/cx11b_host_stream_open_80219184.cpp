// PPC32 host handle +24. Original mode values one/two/three map to zero/one/three.
struct Stream {unsigned char opaque[24];int handle;};extern "C" int close_80219264(Stream *);extern "C" int open_802e4ce4(const char *,int,int);extern "C" void trace_80347324(void *,const char *,...);extern unsigned int trace_context_804b0640;extern const char format_803b395c[],fail_803b3910[],success_803b390c[];
extern "C" int w3d_cx11b_host_stream_open_80219184(Stream *self,const char *path,unsigned int flags){close_80219264(self);int mode;switch(flags&3){case 2:mode=1;break;case 1:mode=0;break;case 3:mode=3;break;default:return (int)0x80070057;}int handle=open_802e4ce4(path,mode,0);self->handle=handle;const char *message;if(handle>=0)message=success_803b390c;else message=fail_803b3910;trace_80347324(&trace_context_804b0640,format_803b395c,path,message);int status=(int)0x90000004;if(self->handle>=0)status=0;return status;}



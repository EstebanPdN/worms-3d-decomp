#include "w3d_ptr.h"
#line 1 "cx11b_request_storage_return_8020f660.cpp"
// PPC32 storage contains eight-byte free spans at +16, count at +2064; request fields have observed offsets.
struct Span {unsigned int begin,size;};struct Store {unsigned char opaque[16];Span spans[256];unsigned int count;};struct Request {unsigned int a,b,c,begin,index,size;};

extern "C" Ptr32<Span> append_8020f850(Ptr32<Store>);
extern "C" int w3d_cx11b_request_storage_return_8020f660(Ptr32<Store> self,Ptr32<Request> request){bool merged=false;if(request->size){unsigned int i=0;for(;i<self->count;++i){Ptr32<Span> span=&self->spans[i];if(span->begin+span->size==request->begin){span->size+=request->size;merged=true;break;}if(request->begin+request->size==span->begin){span->begin=request->begin;span->size+=request->size;merged=true;break;}}if(!merged){Ptr32<Span> span=append_8020f850(self);span->begin=request->begin;span->size=request->size;}}
 request->a=0;request->b=0;request->c=0;request->begin=0;request->index=(unsigned int)-1;request->size=0;return 1;}





#include "w3d_ptr.h"
#line 1 "cx9b_service_try_chain_8020a158.cpp"

struct Service;
struct ServiceVtable { Ptr32<void> reserved[5]; Ptr32<int (Ptr32<Service>, Ptr32<void>, unsigned int, Ptr32<void>)> perform; };
struct Service { Ptr32<ServiceVtable> vtable; };
// Inferred PPC32: vector begin/end +20/+24; preferred service +32.
struct Chain { unsigned char reserved[20]; Ptr32<Ptr32<Service>> begin; Ptr32<Ptr32<Service>> end; unsigned int unknown; Ptr32<Service> preferred; };
extern "C" int w3d_cx9b_service_try_chain_8020a158(Ptr32<Chain> self,Ptr32<void> request,unsigned int flags,Ptr32<void> context) {
 int status=(int)0x80004005;
 Ptr32<Service> preferred=self->preferred;
 if(preferred && (flags&10)) { status=preferred->vtable->perform(preferred,request,flags,context); if(status>=0) return status; }
 for(Ptr32<Service> *cursor=self->begin,*end=self->end;cursor!=end;++cursor) {
  Ptr32<Service> service=*cursor;
  status=service->vtable->perform(service,request,flags,context);
  if(status>=0) return status;
 }
 return status;
}




#include "w3d_ptr.h"
#line 1 "cx9b_service_query_status_802081f8.cpp"

struct Interface;
struct Vtable { Ptr32<void> reserved0[2]; Ptr32<int (Ptr32<Interface>, Ptr32<const void>, Ptr32<Ptr32<Interface>>)> query; Ptr32<void> reserved1; Ptr32<int (Ptr32<Interface>)> release; Ptr32<void> reserved2[5]; Ptr32<int (Ptr32<Interface>)> status; };
struct Interface { Ptr32<Vtable> vtable; };
struct Owner { unsigned char reserved[20]; Ptr32<Interface> service; };
extern unsigned char interface_id_8040ca10[];
static inline void query(Ptr32<Interface> service,Ptr32<Ptr32<Interface>> out) { if(service) service->vtable->query(service,interface_id_8040ca10,out); }
extern "C" int w3d_cx9b_service_query_status_802081f8(Ptr32<Owner> self) {
 Ptr32<Interface> result=0;
 query(self->service,&result);
 if(result) {
  int status=result->vtable->status(result);
  if(result) result->vtable->release(result);
  return status;
 }
 return (int)0x80004001;
}





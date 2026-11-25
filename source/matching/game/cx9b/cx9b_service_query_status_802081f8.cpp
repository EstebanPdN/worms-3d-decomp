
struct Interface;
struct Vtable { void *reserved0[2]; int (*query)(Interface *,const void *,Interface **); void *reserved1; int (*release)(Interface *); void *reserved2[5]; int (*status)(Interface *); };
struct Interface { Vtable *vtable; };
struct Owner { unsigned char reserved[20]; Interface *service; };
extern unsigned char interface_id_8040ca10[];
static inline void query(Interface *service,Interface **out) { if(service) service->vtable->query(service,interface_id_8040ca10,out); }
extern "C" int w3d_cx9b_service_query_status_802081f8(Owner *self) {
 Interface *result=0;
 query(self->service,&result);
 if(result) {
  int status=result->vtable->status(result);
  if(result) result->vtable->release(result);
  return status;
 }
 return (int)0x80004001;
}



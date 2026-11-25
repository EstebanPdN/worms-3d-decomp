
struct Service;
struct ServiceVtable { void *reserved[5]; int (*perform)(Service *,void *,unsigned int,void *); };
struct Service { ServiceVtable *vtable; };
// Inferred PPC32: vector begin/end +20/+24; preferred service +32.
struct Chain { unsigned char reserved[20]; Service **begin; Service **end; unsigned int unknown; Service *preferred; };
extern "C" int w3d_cx9b_service_try_chain_8020a158(Chain *self,void *request,unsigned int flags,void *context) {
 int status=(int)0x80004005;
 Service *preferred=self->preferred;
 if(preferred && (flags&10)) { status=preferred->vtable->perform(preferred,request,flags,context); if(status>=0) return status; }
 for(Service **cursor=self->begin,* *end=self->end;cursor!=end;++cursor) {
  Service *service=*cursor;
  status=service->vtable->perform(service,request,flags,context);
  if(status>=0) return status;
 }
 return status;
}


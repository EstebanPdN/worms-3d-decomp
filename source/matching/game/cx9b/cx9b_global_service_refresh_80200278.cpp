
struct Interface;
struct Vtable { void *reserved[3]; int (*retain)(Interface *); int (*release)(Interface *); void *middle[18]; Interface *(*resolve)(Interface *,const char *); };
struct Interface { Vtable *vtable; };
extern "C" Interface *service_8020b648();
extern char service_name_80419500[];
extern Interface *held_service_804b063c;
extern "C" int w3d_cx9b_global_service_refresh_80200278() {
 const char *name=service_name_80419500;
 Interface *service=service_8020b648();
 Interface *replacement=service->vtable->resolve(service,name);
 if(replacement) replacement->vtable->retain(replacement);
 if(held_service_804b063c) held_service_804b063c->vtable->release(held_service_804b063c);
 held_service_804b063c=replacement;
 return 0;
}


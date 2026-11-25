#include "w3d_ptr.h"
#line 1 "cx9b_global_service_refresh_80200278.cpp"

struct Interface;
struct Vtable { Ptr32<void> reserved[3]; Ptr32<int (Ptr32<Interface>)> retain; Ptr32<int (Ptr32<Interface>)> release; Ptr32<void> middle[18]; Ptr32<Ptr32<Interface> (Ptr32<Interface>, Ptr32<const char>)> resolve; };
struct Interface { Ptr32<Vtable> vtable; };
extern "C" Ptr32<Interface> service_8020b648();
extern char service_name_80419500[];
extern Ptr32<Interface> held_service_804b063c;
extern "C" int w3d_cx9b_global_service_refresh_80200278() {
 Ptr32<const char> name=service_name_80419500;
 Ptr32<Interface> service=service_8020b648();
 Ptr32<Interface> replacement=service->vtable->resolve(service,name);
 if(replacement) replacement->vtable->retain(replacement);
 if(held_service_804b063c) held_service_804b063c->vtable->release(held_service_804b063c);
 held_service_804b063c=replacement;
 return 0;
}




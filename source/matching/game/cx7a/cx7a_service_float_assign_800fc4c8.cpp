
// Resolve a held interface from service +0x64 / vtable +0x7c, assign a
// float through its converted value interface, release the held result.
struct Cx7aInterface;
struct Cx7aIfaceTable {void *unknown[4];void (*release)(Cx7aInterface *);};
struct Cx7aInterface {Cx7aIfaceTable *vtable;};
struct Cx7aService;
struct Cx7aServiceTable {void *unknown[31];int (*lookup)(Cx7aService *,const void *,Cx7aInterface **);};
struct Cx7aService {Cx7aServiceTable *vtable;};
struct Cx7aContext {unsigned char unknown[100];Cx7aService *service;};
extern Cx7aContext *context_804b1788;
extern "C" Cx7aInterface *convert_80342a74(Cx7aInterface *);
extern "C" int assign_80178dfc(Cx7aInterface *,const float *);
struct Cx7aHeld {Cx7aInterface *value;unsigned int spare;Cx7aHeld():value(0){}~Cx7aHeld(){if(value)value->vtable->release(value);}};
extern "C" int w3d_cx7a_service_float_assign_800fc4c8(float input,const void *key) {Cx7aHeld held;float value=input;Cx7aService *service=context_804b1788->service;int result=service->vtable->lookup(service,key,&held.value);if(result>=0)assign_80178dfc(convert_80342a74(held.value),&value);return result;}

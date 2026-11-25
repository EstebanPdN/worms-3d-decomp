#include "w3d_ptr.h"
#line 1 "cx7a_service_float_assign_800fc4c8.cpp"

// Resolve a held interface from service +0x64 / vtable +0x7c, assign a
// float through its converted value interface, release the held result.
struct Cx7aInterface;
struct Cx7aIfaceTable {Ptr32<void> unknown[4];Ptr32<void (Ptr32<Cx7aInterface>)> release;};
struct Cx7aInterface {Ptr32<Cx7aIfaceTable> vtable;};
struct Cx7aService;
struct Cx7aServiceTable {Ptr32<void> unknown[31];Ptr32<int (Ptr32<Cx7aService>, Ptr32<const void>, Ptr32<Ptr32<Cx7aInterface>>)> lookup;};
struct Cx7aService {Ptr32<Cx7aServiceTable> vtable;};
struct Cx7aContext {unsigned char unknown[100];Ptr32<Cx7aService> service;};
extern Ptr32<Cx7aContext> context_804b1788;
extern "C" Ptr32<Cx7aInterface> convert_80342a74(Ptr32<Cx7aInterface>);
extern "C" int assign_80178dfc(Ptr32<Cx7aInterface>,Ptr32<const float>);
struct Cx7aHeld {Ptr32<Cx7aInterface> value;unsigned int spare;Cx7aHeld():value(0){}~Cx7aHeld(){if(value)value->vtable->release(value);}};
extern "C" int w3d_cx7a_service_float_assign_800fc4c8(float input,Ptr32<const void> key) {Cx7aHeld held;float value=input;Ptr32<Cx7aService> service=context_804b1788->service;int result=service->vtable->lookup(service,key,&held.value);if(result>=0)assign_80178dfc(convert_80342a74(held.value),&value);return result;}



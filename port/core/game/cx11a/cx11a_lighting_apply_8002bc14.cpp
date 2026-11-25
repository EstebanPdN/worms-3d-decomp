#include "w3d_ptr.h"
#line 1 "cx11a_lighting_apply_8002bc14.cpp"
// Observed service vtable slots +0x24 read a seven-word value and +0x28 apply it. Owner float fields at +0x5c/+0x64/+0x80.
struct Cx11aColor {float x,y,z,w;};
struct Cx11aLighting {Cx11aColor color;unsigned int other[3];};
struct Cx11aService;struct Cx11aVTable {Ptr32<void> unknown[9];Ptr32<Ptr32<const Cx11aLighting> (Ptr32<Cx11aService>)> get;Ptr32<int (Ptr32<Cx11aService>, Ptr32<const Cx11aLighting>)> set;};
struct Cx11aService {Ptr32<Cx11aVTable> vtable;};
struct Cx11aContext {unsigned char unknown00[0x30];Ptr32<Cx11aService> first;unsigned char unknown34[0x58];Ptr32<Cx11aService> second;};
extern Ptr32<Cx11aContext> context_804b1788;
struct Cx11aOwner {unsigned char unknown00[0x5c];float scale;unsigned char unknown60[4];Cx11aColor first;unsigned char unknown74[12];Cx11aColor second;};
extern "C" void w3d_cx11a_lighting_apply_8002bc14(Ptr32<const Cx11aOwner> self){
Ptr32<Cx11aService> service=context_804b1788->first;
Cx11aLighting value=*service->vtable->get(service);
value.color.x=self->first.x*self->scale;value.color.y=self->first.y*self->scale;value.color.z=self->first.z*self->scale;value.color.w=self->first.w*self->scale;
service->vtable->set(service,&value);
Ptr32<Cx11aService> second=context_804b1788->second;
value=*second->vtable->get(second);
value.color.x=self->second.x*self->scale;value.color.y=self->second.y*self->scale;value.color.z=self->second.z*self->scale;value.color.w=self->second.w*self->scale;
second->vtable->set(second,&value);
}



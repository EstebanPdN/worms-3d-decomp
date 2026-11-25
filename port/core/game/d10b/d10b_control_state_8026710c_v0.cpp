#include "w3d_ptr.h"
#line 1 "d10b_control_state_8026710c_v0.cpp"
// Partial owner/vtable views: only accessed fields are established; original full sizes and callback result type are unknown.
// Native hypothesis: independent state accessors and branch-local coupled state updates preserve the original branch tree.
// PPC32 observed owner fields; roles are inferred. Virtual visibility/enabled update is slot +88.
struct d10b_Control;struct d10b_Vtable {Ptr32<void> unused[22];Ptr32<void (Ptr32<d10b_Control>, unsigned int)> set;};struct d10b_Control {Ptr32<d10b_Vtable> vtable;};
struct d10b_Owner {unsigned char p0[140];unsigned int active;unsigned char p1[32];unsigned int mode;unsigned char p2[8];unsigned int toggle;unsigned char p3[248];Ptr32<d10b_Control> c440; Ptr32<d10b_Control> c444; Ptr32<d10b_Control> c448; Ptr32<d10b_Control> c452; Ptr32<d10b_Control> c456; Ptr32<d10b_Control> c460; Ptr32<d10b_Control> c464; Ptr32<d10b_Control> c468; Ptr32<d10b_Control> c472; Ptr32<d10b_Control> c476; Ptr32<d10b_Control> c480; Ptr32<d10b_Control> c484;};
extern "C" void d10b_control_state_8026710c(Ptr32<d10b_Owner> self){unsigned int inverse=self->mode^1U;unsigned int mode=self->mode;unsigned int inactive=self->active^1U;unsigned int toggle=self->toggle;if(!self->active){toggle=0;if(self->c448){inverse=0;mode=0;}else{inverse=1;mode=0;}}
 if(self->c440)self->c440->vtable->set(self->c440,inverse);
 if(self->c444)self->c444->vtable->set(self->c444,mode);
 if(self->c448)self->c448->vtable->set(self->c448,inactive);
 if(self->c456)self->c456->vtable->set(self->c456,toggle^1);
 if(self->c464)self->c464->vtable->set(self->c464,toggle^1);
 if(self->c472)self->c472->vtable->set(self->c472,toggle^1);
 if(self->c480)self->c480->vtable->set(self->c480,toggle^1);
 if(self->c460)self->c460->vtable->set(self->c460,toggle);
 if(self->c468)self->c468->vtable->set(self->c468,toggle);
 if(self->c476)self->c476->vtable->set(self->c476,toggle);
 if(self->c484)self->c484->vtable->set(self->c484,toggle);
}





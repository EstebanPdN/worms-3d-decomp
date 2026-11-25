// Partial owner/vtable views: only accessed fields are established; original full sizes and callback result type are unknown.
// Native hypothesis: independent state accessors and branch-local coupled state updates preserve the original branch tree.
// PPC32 observed owner fields; roles are inferred. Virtual visibility/enabled update is slot +88.
struct d10b_Control;struct d10b_Vtable {void *unused[22];void (*set)(d10b_Control *,unsigned int);};struct d10b_Control {d10b_Vtable *vtable;};
struct d10b_Owner {unsigned char p0[140];unsigned int active;unsigned char p1[32];unsigned int mode;unsigned char p2[8];unsigned int toggle;unsigned char p3[248];d10b_Control *c440,*c444,*c448,*c452,*c456,*c460,*c464,*c468,*c472,*c476,*c480,*c484;};
extern "C" void d10b_control_state_8026710c(d10b_Owner *self){unsigned int inverse=self->mode^1U;unsigned int mode=self->mode;unsigned int inactive=self->active^1U;unsigned int toggle=self->toggle;if(!self->active){toggle=0;if(self->c448){inverse=0;mode=0;}else{inverse=1;mode=0;}}
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



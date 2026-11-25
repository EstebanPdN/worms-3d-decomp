
struct Interface; struct Vtable { void (*slot[7])(Interface*); }; struct Interface { Vtable *vtable; };
struct ManagerVtable { void (*unused[25])(); void (*detach)(Interface*,void*,int); };
struct Manager { ManagerVtable *vtable; };
struct Context { unsigned char opaque[108]; Manager *manager; };
extern "C" Context *context_804b1788;
struct Resource { unsigned char opaque[200]; unsigned int handle; Interface *held; int state; };
inline void detach(unsigned int *handle,Resource *self) {
 if(*handle) { Manager *m=context_804b1788->manager; m->vtable->detach((Interface*)m,handle,200); self->state=3; }
}
inline void release(Interface *p){if(p)p->vtable->slot[4](p);}
extern "C" void w3d_cx12b_resource_stop_802629bc(Resource *self) {
 detach(&self->handle,self);
 if(self->held) self->held->vtable->slot[6](self->held);
 release(self->held);
 self->held=0;
}



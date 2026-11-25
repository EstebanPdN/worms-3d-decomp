
struct Cx8bActiveInterface;
struct Cx8bActiveVtable {void *unknown00[4];void (*release)(Cx8bActiveInterface *);void *unknown14;void (*stop)(Cx8bActiveInterface *);};
struct Cx8bActiveInterface {Cx8bActiveVtable *vtable;};
struct Cx8bActiveResource {char unknown00[104];int state,active;char unknown70[4];int pending;char unknown78[12];Cx8bActiveInterface *held;};
static inline void clear(Cx8bActiveResource *self,int zero) {
 self->active=zero;self->state=zero;self->pending=zero;
 if(self->held) self->held->vtable->release(self->held);
 self->held=(Cx8bActiveInterface *)zero;
}
extern "C" void w3d_cx8b_active_resource_clear_802b24bc(Cx8bActiveResource *self) {
 if(self->active) {if(self->held) self->held->vtable->stop(self->held);clear(self,0);}
}


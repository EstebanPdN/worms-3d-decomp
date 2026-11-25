
struct Cx8bModeTransition;
struct Cx8bTransitionVtable { void *unknown00[5];void (*reset)(Cx8bModeTransition *); };
struct Cx8bModeTransition { char unknown00[148];int mode,pending,requested;char unknowna0[4];int blocker;char unknowna8[12];Cx8bTransitionVtable *vtable; };
extern "C" void w3d_cx8b_mode_transition_request_802b11d8(Cx8bModeTransition *self,int mode) {
 if(mode==self->mode) self->pending=0;
 else if(mode==1) {self->pending=mode;self->requested=mode;}
 else { int blocker=self->blocker; if(blocker==0) {self->vtable->reset(self);self->pending=blocker;} }
}



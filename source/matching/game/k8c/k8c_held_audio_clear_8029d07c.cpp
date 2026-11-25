struct K8cAudioResource;
struct K8cAudioVtable { void *unknown00[4]; void (*release)(K8cAudioResource *); void *unknown14; void (*stop)(K8cAudioResource *); };
struct K8cAudioResource { K8cAudioVtable *vtable; };
struct K8cAudioOwner { char unknown00[124]; K8cAudioResource *held; };
static inline void k8c_release(K8cAudioResource *r) { if (r) r->vtable->release(r); }
static inline void k8c_stop(K8cAudioResource *r) { if (r) r->vtable->stop(r); }
extern "C" void *service_804b1788;
extern "C" void fn_80129738(void *);
extern "C" void w3d_k8c_held_audio_clear_8029d07c(K8cAudioOwner *self) {
 k8c_stop(self->held);
 k8c_release(self->held);
 self->held=0; fn_80129738(service_804b1788);
}


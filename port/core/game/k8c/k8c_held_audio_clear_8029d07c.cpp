#include "w3d_ptr.h"
#line 1 "k8c_held_audio_clear_8029d07c.cpp"
struct K8cAudioResource;
struct K8cAudioVtable { Ptr32<void> unknown00[4]; Ptr32<void (Ptr32<K8cAudioResource>)> release; Ptr32<void> unknown14; Ptr32<void (Ptr32<K8cAudioResource>)> stop; };
struct K8cAudioResource { Ptr32<K8cAudioVtable> vtable; };
struct K8cAudioOwner { char unknown00[124]; Ptr32<K8cAudioResource> held; };
static inline void k8c_release(Ptr32<K8cAudioResource> r) { if (r) r->vtable->release(r); }
static inline void k8c_stop(Ptr32<K8cAudioResource> r) { if (r) r->vtable->stop(r); }
extern "C" Ptr32<void> service_804b1788;
extern "C" void fn_80129738(Ptr32<void>);
extern "C" void w3d_k8c_held_audio_clear_8029d07c(Ptr32<K8cAudioOwner> self) {
 k8c_stop(self->held);
 k8c_release(self->held);
 self->held=0; fn_80129738(service_804b1788);
}




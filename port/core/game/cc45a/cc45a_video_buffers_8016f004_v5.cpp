#include "w3d_ptr.h"
#line 1 "cc45a_video_buffers_8016f004_v5.cpp"
// Original callee and downstream witnesses are retained in build/cc45a/video-*-witness.txt.
// Unsigned allocation sizes and alignment stay full-width. SDK setters and wait
// have side effects only; no observed return is consumed here. No local padding.
// Partial render-mode and video-state views; unknown spans are observed offsets only.
struct cc45a_RenderMode { unsigned int flags; unsigned short width, unknown06, height; };
struct cc45a_VideoState { unsigned char unknown00[40]; Ptr32<cc45a_RenderMode> mode; unsigned char unknown2c[484]; Ptr32<void> buffers[2]; unsigned int active, copy_gamma; };
extern "C" {
void cc45a_release_801fe2e0(Ptr32<void>);
Ptr32<void> cc45a_allocate_801fe2a8(unsigned int,unsigned int);
void cc45a_configure_80303e2c(Ptr32<cc45a_RenderMode>);
void cc45a_set_framebuffer_80304b18(Ptr32<void>);
void cc45a_flush_803049e8();
void cc45a_retrace_80303964();
void cc45a_copy_gamma_80309240(unsigned int);
void cc45a_video_buffers_8016f004_v5(Ptr32<cc45a_VideoState> self) {
 unsigned int i=0;
 Ptr32<void> empty=0;
 Ptr32<Ptr32<void>> slot=self->buffers;
 for(;i<2;++i,++slot) {
  if(*slot) { cc45a_release_801fe2e0(*slot); *slot=empty; }
 }
 unsigned int bytes=((self->mode->width+15)&0xfff0U)*self->mode->height*2;
 self->buffers[0]=cc45a_allocate_801fe2a8(bytes,32);
 self->buffers[1]=cc45a_allocate_801fe2a8(bytes,32);
 self->active=0;
 cc45a_configure_80303e2c(self->mode);
 cc45a_set_framebuffer_80304b18(self->buffers[1]);
 cc45a_flush_803049e8();
 cc45a_retrace_80303964();
 unsigned int interlaced=self->mode->flags&1;
 cc45a_copy_gamma_80309240(self->copy_gamma);
 if(interlaced) cc45a_retrace_80303964();
}
}



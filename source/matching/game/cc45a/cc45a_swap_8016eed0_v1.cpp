// Original scale helper reads float input and writes scale/filter state.
// The callback result is tested as a full word; other possible dynamic targets
// are unknown. Original table 80411c10 slot 0x70 is 801680b4 (DOL word
// 801680b4 at 80411c80). All tables/globals remain external and unowned.
// SDK black-screen flag is stored as a full word. Empty begin hook has only
// a call-site signature; sizeof of the complete original classes is unknown.
// Partial display/context views recovered from observed load/store offsets.
struct cc45a_SwapMode { unsigned char unknown00[25]; unsigned char antialias; unsigned char sample_pattern[24]; unsigned char filter[7]; };
struct cc45a_SwapDisplay { unsigned char unknown00[40]; cc45a_SwapMode *mode; unsigned char unknown2c[484]; void *buffers[2]; unsigned int active, unknown21c; float scale; unsigned char filter[7]; };
struct cc45a_SwapGraphics;
struct cc45a_SwapVtable { void *unknown00[28]; int (*copy_complete)(cc45a_SwapGraphics*); };
struct cc45a_SwapGraphics { cc45a_SwapVtable *vtable; unsigned char unknown04[256]; unsigned int flags; };
extern "C" {
extern cc45a_SwapGraphics *cc45a_graphics_804b1884;
extern unsigned int cc45a_startup_frames_804ab55c;
void cc45a_scale_8016ee4c(cc45a_SwapDisplay*,float);
void cc45a_done_803085a0();
void cc45a_begin_8016ee48(cc45a_SwapDisplay*);
void cc45a_alpha_8030ba0c(unsigned char);
void cc45a_filter_80309038(unsigned char,const unsigned char*,unsigned char,const unsigned char*);
void cc45a_copy_80309254(void*,unsigned char);
void cc45a_framebuffer_80304b18(void*);
void cc45a_black_80304b84(int);
void cc45a_flush_803049e8();
void cc45a_retrace_80303964();
void cc45a_swap_8016eed0(cc45a_SwapDisplay *self) {
 cc45a_scale_8016ee4c(self,self->scale);
 cc45a_SwapGraphics *graphics=cc45a_graphics_804b1884;
 if(graphics->vtable->copy_complete(graphics)==0) {
  cc45a_done_803085a0();
  cc45a_begin_8016ee48(self);
  if(cc45a_graphics_804b1884->flags&1) cc45a_alpha_8030ba0c(1); else cc45a_alpha_8030ba0c(0);
  cc45a_filter_80309038(self->mode->antialias,self->mode->sample_pattern,1,self->filter);
  cc45a_copy_80309254(self->buffers[self->active],1);
  cc45a_SwapMode *mode=self->mode;
  cc45a_filter_80309038(mode->antialias,mode->sample_pattern,1,mode->filter);
  cc45a_done_803085a0();
  cc45a_alpha_8030ba0c(1);
 }
 cc45a_framebuffer_80304b18(self->buffers[self->active]);
 if(cc45a_startup_frames_804ab55c==0) {cc45a_startup_frames_804ab55c=1;cc45a_black_80304b84(1);}
 else if(cc45a_startup_frames_804ab55c==1) {cc45a_black_80304b84(0);++cc45a_startup_frames_804ab55c;}
 cc45a_flush_803049e8();
 cc45a_retrace_80303964();
 self->active^=1;
}
}

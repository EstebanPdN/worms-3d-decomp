// Inferred presentation/completion-token flow. Retains the timeout abort path
// and a final token read after abort, as shown by the original branch order.
// SDK input masks verify byte booleans and halfword token; OSReport original
// prologue saves the variadic register area. No initialized data is owned.
// Empty begin hook has unknown original signature; only this call-site context
// is represented. A matched frame does not establish any original sizeof.
// Partial byte layout observed in DOL, not the original complete type sizes.
struct cc45a_Mode { unsigned char unknown00[25]; unsigned char antialias; unsigned char sample_pattern[24]; unsigned char filter[7]; };
struct cc45a_Display { unsigned char unknown00[40]; cc45a_Mode *mode; unsigned char unknown2c[484]; void *buffers[2]; unsigned int active; unsigned char unknown21c[8]; unsigned char filter[7]; };
struct cc45a_Graphics { unsigned char unknown00[260]; unsigned int flags; };
extern "C" {
extern cc45a_Display *cc45a_display_804b1888;
extern cc45a_Graphics *cc45a_graphics_804b1884;
extern unsigned int cc45a_elapsed_804b00e4,cc45a_deadline_804b00e8;
extern const char cc45a_warning_803a4e7c[];
void cc45a_begin_8016ee48(cc45a_Display*); // empty original; passed context, discarded result
void cc45a_alpha_8030ba0c(unsigned char);
void cc45a_filter_80309038(unsigned char,const unsigned char*,unsigned char,const unsigned char*);
void cc45a_copy_80309254(void*,unsigned char);
void cc45a_draw_token_803084e0(unsigned short);
unsigned short cc45a_read_token_80308594();
void cc45a_report_802fb7ac(const char*,...);
void cc45a_abort_801683c4();
void cc45a_reset_8016830c(unsigned int);
void cc45a_present_80168200() {
 cc45a_Display *self=cc45a_display_804b1888;
 bool aborted=false;
 cc45a_begin_8016ee48(self);
 if(cc45a_graphics_804b1884->flags&1) cc45a_alpha_8030ba0c(1); else cc45a_alpha_8030ba0c(0);
 cc45a_filter_80309038(self->mode->antialias,self->mode->sample_pattern,1,self->filter);
 cc45a_copy_80309254(self->buffers[self->active],1);
 cc45a_Mode *mode=self->mode;
 cc45a_filter_80309038(mode->antialias,mode->sample_pattern,1,mode->filter);
 cc45a_draw_token_803084e0(0xb00b);
 cc45a_elapsed_804b00e4=0;
 while(cc45a_read_token_80308594()!=0xb00b && !aborted) {
  if(cc45a_elapsed_804b00e4>=cc45a_deadline_804b00e8) {
   aborted=true;
   cc45a_report_802fb7ac(cc45a_warning_803a4e7c);
   cc45a_abort_801683c4();
   cc45a_reset_8016830c(1);
  }
 }
 cc45a_alpha_8030ba0c(1);
}
}

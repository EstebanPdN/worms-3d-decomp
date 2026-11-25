// GWMP8P rev0, observed GC32 partial layout. Built with -mps-float (paired-single
// FP frame). Its .rodata pool starts at 0x803d7ffc, 4 bytes past an 8-byte
// boundary (0x803d7ff8 is the 0.0f of the function at 0x802b633c), so the
// leading 10.0f step minimum is a borrowed extern; the unit owns the
// 8-aligned tail 0x803d8000..0x803d800b (unsigned->double conversion
// constant, 0.0f), decoded from the DOL.
// Mode, panel and duration names
// describe use and do not establish the original class identity.
struct D19fModeText { const char *data; unsigned short length() const { return *(const unsigned short *)(data-4); } };
struct D19fModeData { unsigned words0[30]; D19fModeText leave,enter; unsigned words128[2]; float step,duration; };
struct D19fModePanel { unsigned words0[7]; unsigned base28[3]; D19fModeData *data; unsigned words44[23]; int suppress; unsigned words140[12]; int mode; unsigned words192[4]; void **table; unsigned words212[17]; void *resource,*list; unsigned words288[6]; float extent; unsigned words316[22]; void *property; int locks; float duration,elapsed; };
extern "C" void d19f_mode_base_802b16c4(void *,int);
extern "C" void d19f_mode_build_802b8430(D19fModePanel *);
extern "C" unsigned d19f_mode_list_size_802bc71c(void *);
extern "C" void d19f_mode_list_active_802bcc40(void *,int);
extern "C" void d19f_mode_release_8015fd1c(void *);
extern "C" void d19f_mode_update_802b8754(D19fModePanel *);
extern "C" void d19f_mode_reset_802b929c(D19fModePanel *);
extern "C" void d19f_mode_property_802bfba4(void *,int);
extern int d19f_mode_lock_804abb4c;
extern const float d19f_mode_min_step_803d7ffc[]; // {10.0f}; an array keeps it out of small data
typedef char D19fModePanelSize[(sizeof(D19fModePanel)==420)?1:-1];
extern "C" void d19f_set_panel_mode_802b68f4(D19fModePanel *self,int mode) {
 if(mode!=self->mode && (mode!=1 || d19f_mode_lock_804abb4c!=1)) {
  d19f_mode_base_802b16c4(self->base28,mode);
  D19fModeData *data=self->data;
  if(mode==1 && self->resource) {
   self->duration=data->duration;
   if(!self->list) d19f_mode_build_802b8430(self);
   float step=data->step;
   if(step<d19f_mode_min_step_803d7ffc[0]) step=d19f_mode_min_step_803d7ffc[0];
   float duration=(float)d19f_mode_list_size_802bc71c(self->list)*step;
   if(duration<self->duration) self->duration=duration;
   self->extent=self->duration;
   d19f_mode_list_active_802bcc40(self->list,1);
   if(self->duration==0.0f) {
    if(self->list) { d19f_mode_release_8015fd1c(self->list); self->list=0; }
    if(self->locks==1) { d19f_mode_lock_804abb4c=0; self->locks=0; }
    d19f_mode_update_802b8754(self);
   } else if(data->enter.length()) {
    ((void(*)(void *,const char *))self->table[7])(self->base28,data->enter.data);
   }
  } else {
   self->duration=0.0f;
   if(self->elapsed==0.0f) d19f_mode_reset_802b929c(self);
   if(self->list) d19f_mode_list_active_802bcc40(self->list,0);
   if(data->leave.length() && !self->suppress) {
    ((void(*)(void *,const char *))self->table[7])(self->base28,data->leave.data);
   }
  }
  if(self->property) d19f_mode_property_802bfba4(self->property,mode);
 }
}

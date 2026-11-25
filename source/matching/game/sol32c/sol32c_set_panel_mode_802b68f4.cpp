// GWMP8P rev0, observed GC32 partial layout. Mode, panel and duration names
// describe use and do not establish the original class identity.
struct Sol32cModeText { const char *data; unsigned short length() const { return *(const unsigned short *)(data-4); } };
struct Sol32cModeData { unsigned words0[30]; Sol32cModeText leave,enter; unsigned words128[2]; float step,duration; };
struct Sol32cModePanel { unsigned words0[7]; unsigned base28[3]; Sol32cModeData *data; unsigned words44[23]; int suppress; unsigned words140[12]; int mode; unsigned words192[4]; void **table; unsigned words212[17]; void *resource,*list; unsigned words288[6]; float extent; unsigned words316[22]; void *property; int locks; float duration,elapsed; };
extern "C" void sol32c_mode_base_802b16c4(void *,int);
extern "C" void sol32c_mode_build_802b8430(Sol32cModePanel *);
extern "C" unsigned sol32c_mode_list_size_802bc71c(void *);
extern "C" void sol32c_mode_list_active_802bcc40(void *,int);
extern "C" void sol32c_mode_release_8015fd1c(void *);
extern "C" void sol32c_mode_update_802b8754(Sol32cModePanel *);
extern "C" void sol32c_mode_reset_802b929c(Sol32cModePanel *);
extern "C" void sol32c_mode_property_802bfba4(void *,int);
extern int sol32c_mode_lock_804abb4c;
extern const float sol32c_mode_min_step_803d7ffc[],sol32c_mode_zero_803d8008[];
typedef char Sol32cModePanelSize[(sizeof(Sol32cModePanel)==420)?1:-1];
extern "C" void sol32c_set_panel_mode_802b68f4(Sol32cModePanel *self,int mode) {
 if(mode!=self->mode && (mode!=1 || sol32c_mode_lock_804abb4c!=1)) {
  void *base=self->base28;
  sol32c_mode_base_802b16c4(base,mode);
  Sol32cModeData *data=self->data;
  if(mode==1 && self->resource) {
   self->duration=data->duration;
   if(!self->list) sol32c_mode_build_802b8430(self);
   float step=data->step;
   if(step<sol32c_mode_min_step_803d7ffc[0]) step=sol32c_mode_min_step_803d7ffc[0];
   float duration=(float)sol32c_mode_list_size_802bc71c(self->list)*step;
   if(duration<self->duration) self->duration=duration;
   self->extent=self->duration;
   sol32c_mode_list_active_802bcc40(self->list,1);
   if(self->duration==sol32c_mode_zero_803d8008[0]) {
    if(self->list) { sol32c_mode_release_8015fd1c(self->list); self->list=0; }
    if(self->locks==1) { sol32c_mode_lock_804abb4c=0; self->locks=0; }
    sol32c_mode_update_802b8754(self);
   } else if(data->enter.length()) {
    ((void(*)(void *,const char *))self->table[7])(base,data->enter.data);
   }
  } else {
   self->duration=sol32c_mode_zero_803d8008[0];
   if(self->elapsed==sol32c_mode_zero_803d8008[0]) sol32c_mode_reset_802b929c(self);
   if(self->list) sol32c_mode_list_active_802bcc40(self->list,0);
   if(data->leave.length() && !self->suppress) {
    ((void(*)(void *,const char *))self->table[7])(base,data->leave.data);
   }
  }
  if(self->property) sol32c_mode_property_802bfba4(self->property,mode);
 }
}

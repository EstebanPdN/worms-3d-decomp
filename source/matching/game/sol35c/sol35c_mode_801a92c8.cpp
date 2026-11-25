// Reference interface-prefix view; slots and offsets observed in original code.
struct Sol35cInterface { void **vtable; };
struct Sol35cOwner { unsigned char unknown[160]; int mode; unsigned char unknown164[12]; Sol35cInterface *held; };
extern "C" Sol35cInterface *fn_8020fcb4(void *);
extern unsigned char lbl_80363b54[],lbl_80363ba4[];
extern "C" int sol35c_mode_801a92c8(Sol35cOwner *self,int mode) {
 if(mode!=self->mode) {
  void *which;
  if(mode==0)which=lbl_80363b54;else which=lbl_80363ba4;
  Sol35cInterface *fresh=fn_8020fcb4(which);
  if(fresh)((unsigned (*)(Sol35cInterface *))fresh->vtable[3])(fresh);
  Sol35cInterface *old=self->held;
  if(old)((unsigned (*)(Sol35cInterface *))old->vtable[4])(old);
  self->held=fresh;
 }
 self->mode=mode;
 return 0;
}

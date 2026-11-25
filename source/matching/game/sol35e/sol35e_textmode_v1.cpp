struct sol35e_TextCarrier { unsigned char unknown00[11]; unsigned char flags; unsigned char unknown0c[120]; char *payload; };
struct sol35e_TextOwner { unsigned char unknown00[28]; unsigned char subobject[12]; sol35e_TextCarrier *carrier; unsigned char unknown2c[96]; int guard; unsigned char unknown90[32]; int mode; unsigned char unknownb4[28]; void **vtable; unsigned char unknownd4[32]; void *mesh; int unknownf8; int kind; };
struct sol35e_Colour { unsigned char r,g,b,a; sol35e_Colour(unsigned char x,unsigned char y,unsigned char z,unsigned char w):r(x),g(y),b(z),a(w) {} };
extern "C" void sol35e_dispatch_payload_802b1258(const char *);
extern "C" void *sol35e_mesh_identity_80343580(void *);
extern "C" void sol35e_fill_colour_8018d35c(void *,const sol35e_Colour *);
extern "C" void sol35e_base_mode_802b0990(void *,int);
extern "C" void sol35e_update_controls_80260144(sol35e_TextOwner *);
extern "C" void sol35e_text_mode_8025fa88(sol35e_TextOwner *self,int mode) {
 if(self->mode!=mode) {
 if(mode) {
  sol35e_TextCarrier *carrier=self->carrier;
  char *payload=carrier->payload;
  if(((unsigned short *)payload)[-2] && ((carrier->flags^4)&4) && self->guard) sol35e_dispatch_payload_802b1258(payload);
  if(self->kind==1) {
   void *mesh=sol35e_mesh_identity_80343580(self->mesh);
   sol35e_Colour colour(251,227,105,255);
   sol35e_fill_colour_8018d35c(mesh,&colour);
  }
 } else {
  if(self->kind==1) {
   void *mesh=sol35e_mesh_identity_80343580(self->mesh);
   sol35e_Colour colour(255,255,255,255);
   sol35e_fill_colour_8018d35c(mesh,&colour);
  }
 }
 } else if(mode) ((void (*)(void *))self->vtable[14])(self->subobject);
 sol35e_base_mode_802b0990(self->subobject,mode);
 sol35e_update_controls_80260144(self);
}

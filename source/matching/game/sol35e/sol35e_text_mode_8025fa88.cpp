// Partial GameCube ABI views inferred from original 0x8025fa88.
// The primary carrier supplies a shared-string payload at +132. The second
// interface starts at owner+28 and uses the vtable pointer at owner+208.
// Colour byte values and both local lifetimes follow the original stores.
struct sol35e_TextCarrier { unsigned char unknown00[11]; unsigned char flags; unsigned char unknown0c[120]; char *payload; };
struct sol35e_TextOwner { unsigned char unknown00[28]; unsigned char subobject[12]; sol35e_TextCarrier *carrier; unsigned char unknown2c[96]; int guard; unsigned char unknown90[32]; int mode; unsigned char unknownb4[28]; void **vtable; unsigned char unknownd4[32]; void *mesh; int unknownf8; int kind; };
struct sol35e_Colour { unsigned char r,g,b,a; sol35e_Colour(unsigned char x,unsigned char y,unsigned char z,unsigned char w):r(x),g(y),b(z),a(w) {} };
extern "C" void sol35e_dispatch_payload_802b1258(const char *);
extern "C" void *sol35e_mesh_identity_80343580(void *);
extern "C" int sol35e_fill_colour_8018d35c(void *,const sol35e_Colour *);
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

#define SOL35E_OFFSET(T,M,N) typedef char sol35e_offset_##M[((unsigned)&((T *)0)->M)==N?1:-1]
SOL35E_OFFSET(sol35e_TextOwner,carrier,40);
SOL35E_OFFSET(sol35e_TextOwner,guard,140);
SOL35E_OFFSET(sol35e_TextOwner,mode,176);
SOL35E_OFFSET(sol35e_TextOwner,vtable,208);
SOL35E_OFFSET(sol35e_TextOwner,mesh,244);
SOL35E_OFFSET(sol35e_TextOwner,kind,252);
SOL35E_OFFSET(sol35e_TextCarrier,payload,132);
#undef SOL35E_OFFSET

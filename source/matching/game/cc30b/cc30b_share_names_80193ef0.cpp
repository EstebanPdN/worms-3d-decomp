// Inferred shared-name canonicalization. Minimal string view; original class size is unknown.
typedef unsigned int cc30b_u32;
extern "C" void fn_803426b8(void *);
extern "C" void fn_8020c5c4(void *);
extern "C" void fn_80341588(void *);
extern "C" void fn_8020bb2c(void *);
extern "C" int fn_802ef234(const char *,const char *);
struct cc30b_String_803426b8 {
 char *text;
 cc30b_String_803426b8();
 ~cc30b_String_803426b8() {fn_8020c5c4(this);fn_80341588(this);}
 void assign(const cc30b_String_803426b8 &other) {
  ++*(unsigned short *)(other.text-6);
  char *old=text-6; if(--*(unsigned short *)old==0) fn_8020bb2c(old);
  text=other.text;
 }
};
struct cc30b_NameSlot_80193ef0 {char *text;cc30b_u32 other;
 void assign(const cc30b_String_803426b8 &s) {++*(unsigned short *)(s.text-6);char *old=text-6;if(--*(unsigned short *)old==0)fn_8020bb2c(old);text=s.text;}
};
struct cc30b_Names_80193ef0;
struct cc30b_NamesVtable_80193ef0 {void *unknown[17];int (*prepare)(cc30b_Names_80193ef0 *);int (*update)(cc30b_Names_80193ef0 *);};
struct cc30b_Names_80193ef0 {cc30b_NamesVtable_80193ef0 *vtable;char unknown04[16];cc30b_NameSlot_80193ef0 *names;char unknown18[52];cc30b_u32 count;};
extern "C" void w3d_cc30b_share_names_80193ef0(cc30b_Names_80193ef0 *self) {
 cc30b_u32 i=0;
 self->vtable->prepare(self);self->vtable->update(self);
 cc30b_String_803426b8 previous;
 for(;i<self->count;++i) {
  if(fn_802ef234(*(char **)((char *)self->names+(i<<3)),previous.text)==0) ((cc30b_NameSlot_80193ef0 *)((char *)self->names+(i<<3)))->assign(previous);
  else {cc30b_NameSlot_80193ef0 &slot=self->names[i];++*(unsigned short *)(slot.text-6);char *old=previous.text-6;if(--*(unsigned short *)old==0)fn_8020bb2c(old);previous.text=slot.text;}
 }
}

typedef unsigned int cc35b_u32;
typedef unsigned char cc35b_u8;
struct cc35b_VideoInfo { cc35b_u32 width,height,format; };
struct cc35b_AudioInfo { cc35b_u32 words[4]; };
// Partial byte-exact view; inferred component and header names only.
struct cc35b_HeaderState { cc35b_u8 unknown0[108];cc35b_u32 component_count;cc35b_u8 components[16];cc35b_VideoInfo video;cc35b_AudioInfo audio;cc35b_u8 unknown156[16];int audio_present; };
struct cc35b_HeaderPlayer { int unknown0;cc35b_HeaderState *state;cc35b_u8 unknown8[76];int mode; };
extern "C" void *fn_80343994();
extern "C" int fn_801fdcac(void *,cc35b_HeaderState *,void *,int,cc35b_u32);
extern "C" void fn_802fb7ac(const char *,...);
extern "C" int fn_802f5320(cc35b_HeaderState *);
extern char lbl_803db228[],lbl_803db25c[];
extern "C" int w3d_cc35b_movie_headers_802e09c4(cc35b_HeaderPlayer *self,void *scratch,cc35b_u32 *offset) {
 cc35b_u32 i=0;
 cc35b_HeaderState *view=self->state;
 if(i<view->component_count) do {
  cc35b_u32 kind=view->components[i];
  switch(kind) {
  case 0:
   if(fn_801fdcac(fn_80343994(),self->state,scratch,32,*offset)) {
 fn_802fb7ac(lbl_803db228); fn_802f5320(self->state);self->mode=7;return 0;
 }
   self->state->video=*(cc35b_VideoInfo *)scratch;
   *offset+=12;
   break;
  case 1:
   if(fn_801fdcac(fn_80343994(),self->state,scratch,32,*offset)) {
 fn_802fb7ac(lbl_803db228); fn_802f5320(self->state);self->mode=7;return 0;
 }
   self->state->audio=*(cc35b_AudioInfo *)scratch;
   self->state->audio_present=kind;
   *offset+=16;
   break;
  default:
   fn_802fb7ac(lbl_803db25c);return 0;
  }
  view=self->state;
  ++i;
 } while(i<view->component_count);
 return 1;
}

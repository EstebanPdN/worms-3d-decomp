// Partial reference ABI view of the wormpot outro owner. Names are inferred.
// Original control traversal is exactly eleven 72-byte entries beginning at
// +316. The two IEEE binary32 literals at 0x803d69ac/0x803d69b0 decode to 1/0.
struct sol35e_OutroEntry {unsigned control;unsigned char unknown04[68];};
struct sol35e_OutroOwner {unsigned char unknown00[244];void *mesh;unsigned char unknownf8[12];unsigned outro,control;unsigned char unknown10c[48];sol35e_OutroEntry entries[11];unsigned char unknown454[232];unsigned flags;};
struct sol35e_OutroVector {float x,y,z;sol35e_OutroVector(float a,float b,float c):x(a),y(b),z(c){}};
struct sol35e_OutroAudio {void **vtable;};
struct sol35e_OutroContext {unsigned char unknown00[108];sol35e_OutroAudio *audio;};
extern sol35e_OutroContext *sol35e_outro_context_804b1788;
extern const char sol35e_machine_outro_803d698c[],sol35e_audio_outro_803d699c[];
extern "C" int sol35e_check_control_8018179c(void *,unsigned,int);
extern "C" void sol35e_release_owner_8015fd1c(void *);
extern "C" void sol35e_dispatch_labels_802ab24c(sol35e_OutroOwner *);
extern "C" int sol35e_play_clip_80181640(void *,const char *,unsigned *,int,float,float,float);
extern "C" void sol35e_panel_outro_802b1f98(void *);
extern "C" void sol35e_stop_wormpot_802aa11c(sol35e_OutroOwner *self,int release) {
 sol35e_OutroEntry *entry=self->entries;
 int remaining=11;
 do { sol35e_check_control_8018179c(self->mesh,entry->control,0);++entry;}while(--remaining);
 self->flags=32768;
 if(release==1) sol35e_release_owner_8015fd1c(self);
 else {
  sol35e_dispatch_labels_802ab24c(self);
  sol35e_check_control_8018179c(self->mesh,self->control,0);
  sol35e_play_clip_80181640(self->mesh,sol35e_machine_outro_803d698c,&self->outro,0,1.0f,0.0f,0.0f);
  sol35e_OutroVector vector(0.0f,0.0f,1.0f);
  sol35e_OutroAudio *audio=sol35e_outro_context_804b1788->audio;
  ((void (*)(sol35e_OutroAudio *,const char *,const sol35e_OutroVector *))audio->vtable[24])(audio,sol35e_audio_outro_803d699c,&vector);
  sol35e_panel_outro_802b1f98((char *)self+28);
 }
}

#define SOL35E_OFFSET(T,M,N) typedef char sol35e_offset_##M[((unsigned)&((T *)0)->M)==N?1:-1]
SOL35E_OFFSET(sol35e_OutroOwner,mesh,244);
SOL35E_OFFSET(sol35e_OutroOwner,outro,260);
SOL35E_OFFSET(sol35e_OutroOwner,control,264);
SOL35E_OFFSET(sol35e_OutroOwner,entries,316);
SOL35E_OFFSET(sol35e_OutroOwner,flags,1340);
SOL35E_OFFSET(sol35e_OutroContext,audio,108);
typedef char sol35e_entry_stride[sizeof(sol35e_OutroEntry)==72?1:-1];
#undef SOL35E_OFFSET

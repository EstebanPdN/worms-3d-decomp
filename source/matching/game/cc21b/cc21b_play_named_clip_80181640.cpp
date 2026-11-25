// GWMP8P rev0, original 0x80181640 (144 bytes).
// Lookup writes only the first word (verified in 0x80181598). This caller's
// observed stack reservation gives the local a 28-byte extent; the remaining
// 24 bytes have no established meaning and are never initialized or read here.
// Scalar playback names and float-versus-double source spelling remain inferred.
struct Cc21bClipLookup { int index; unsigned int unknown[6]; };
extern "C" int cc21b_find_clip_80181598(void *,const void *,Cc21bClipLookup *);
extern "C" int cc21b_play_clip_801816d0(void *,int,int *,float,float,int,float);
extern "C" int w3d_cc21b_play_named_clip_80181640(void *self,const void *name,int *result,float a,float b,int flags,float c)
{
 Cc21bClipLookup found;
 int status=cc21b_find_clip_80181598(self,name,&found);
 if(status>=0)
  status=cc21b_play_clip_801816d0(self,found.index,result,a,b,flags,c);
 else { *result=-1; }
 return status;
}

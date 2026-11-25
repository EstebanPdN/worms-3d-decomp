typedef unsigned int cc35b_u32;
typedef unsigned char cc35b_u8;
// Partial movie state: only observed offsets; names are inferred, no sizeof claim.
struct cc35b_Buffer { cc35b_u8 *data; cc35b_u8 *cursor; cc35b_u32 ready; };
struct cc35b_MovieState {
 cc35b_u8 unknown0[68]; cc35b_u32 video_block_bytes, audio_samples;
 cc35b_u8 unknown76[52]; cc35b_u32 width,height;
 cc35b_u8 unknown136[20]; cc35b_u8 *arena_end;
 int opened,playing,busy,audio_present;
 cc35b_u8 unknown176[168]; cc35b_u8 *planes[3];
 inline cc35b_Buffer *buffer_at(cc35b_u32 offset) { return (cc35b_Buffer *)((cc35b_u8 *)this+offset); }
};
struct cc35b_Player { int unknown0; cc35b_MovieState *state; };
extern "C" void fn_802fa95c(void *, cc35b_u32);
inline void cc35b_layout(cc35b_u8 *arena,cc35b_Player *self) {

  cc35b_u32 size=self->state->width*self->state->height;
  self->state->planes[0]=arena;
  cc35b_u32 y=(size+31)&~31u, uv=((size>>2)+31)&~31u;
  fn_802fa95c(arena,y);
  arena+=y;

  self->state->planes[1]=arena;
  fn_802fa95c(arena,uv); arena+=uv;
  self->state->planes[2]=arena;
  fn_802fa95c(arena,uv); arena+=uv;
  cc35b_u32 offset=224;
  for(int count=10;count;--count) {
   cc35b_Buffer *b=self->state->buffer_at(offset);
   b->ready=0;
   b->data=arena;
   offset+=12;
   arena+=(self->state->video_block_bytes+31)&~31u;
  }
  if(self->state->audio_present) {
   for(cc35b_u32 i=0;i<4;++i) {
    cc35b_Buffer *b=self->state->buffer_at(360+i*12);
    b->data=arena;
    b->cursor=arena;
    b->ready=0;
    arena+=(self->state->audio_samples*4+31)&~31u;
   }
  }
  self->state->arena_end=arena;
}

extern "C" int w3d_cc35b_movie_buffers_802e1134(cc35b_Player *self,cc35b_u8 *arena) { if(self->state->opened && !self->state->playing) { if(self->state->busy) return 0; cc35b_layout(arena,self); } return 1; }

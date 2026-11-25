#include "w3d_ptr.h"
#line 1 "cc34b_movie_read_done_802e1478.cpp"
typedef unsigned int cc34b_u32;
struct cc34b_ReadBlock_802e1478 { Ptr32<cc34b_u32> data; cc34b_u32 frame; int ready; };
struct cc34b_MovieState_802e1478 {
 char before_frames[80]; cc34b_u32 frame_count, first_size; char before_start[12]; cc34b_u32 start_offset;
 char before_flags[56]; int active, prepared, audio, unknown, error, looping; cc34b_u32 offset; char before_index[8]; int block_index; cc34b_u32 read_size, frame; float volume,target,step; int duration; cc34b_ReadBlock_802e1478 blocks[10];
};
struct cc34b_Player_802e1478 { int unknown; Ptr32<cc34b_MovieState_802e1478> movie; char before_pending[60]; int pending; char before_mode[12]; int mode; };
inline Ptr32<void> cc34b_read_buffer_802e1478(Ptr32<void> base,int offset) {return *(Ptr32<Ptr32<void>>)((Ptr32<char>)base+offset);}
extern "C" {
extern Ptr32<cc34b_Player_802e1478> lbl_804b190c;
extern const char lbl_803db318[];
int fn_802f5568(Ptr32<cc34b_MovieState_802e1478>,Ptr32<void>,cc34b_u32,cc34b_u32,Ptr32<void (int)>,int);
int fn_802fb7ac(Ptr32<const char>,...);
Ptr32<void> fn_80343994(); int fn_801fdbec(Ptr32<void>,int);
void w3d_cc34b_movie_read_done_802e1478(int result) {
 Ptr32<cc34b_Player_802e1478> self=lbl_804b190c;
 if(result==-1) {self->movie->error=1;self->mode=7;}
 else if(result!=-3) {
  Ptr32<cc34b_MovieState_802e1478> movie=self->movie;
  movie->offset+=movie->read_size;
  Ptr32<cc34b_ReadBlock_802e1478> block=movie->blocks+movie->block_index;
  self->movie->read_size=*self->movie->blocks[self->movie->block_index].data;
  block->ready=1;
  block->frame=self->movie->frame;
  int next=self->movie->block_index+1;
  int wrapped=0; if(next<10) wrapped=next; self->movie->block_index=wrapped;
  ++self->movie->frame;
  if(self->movie->frame > self->movie->frame_count-1 && self->movie->looping==1) {
   self->movie->frame=0;
   self->movie->offset=self->movie->start_offset;
   self->movie->read_size=self->movie->first_size;
  }
  if(--self->pending!=0) {
   Ptr32<cc34b_MovieState_802e1478> read=self->movie;
   if(fn_802f5568(read,cc34b_read_buffer_802e1478(read,read->block_index*12+224),read->read_size,read->offset,w3d_cc34b_movie_read_done_802e1478,2)!=1) {fn_802fb7ac(lbl_803db318);self->movie->error=1;}
   fn_801fdbec(fn_80343994(),1);
  } else {self->mode=4;self->movie->prepared=1;}
 }
}
}



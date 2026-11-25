// GWMP8P rev0 0x802e1854. Movie player: decodes the components of the frame
// in the read slot. Player, Stream, Slot and Segment are partial views
// shared in layout with g7b_copy_stereo_802e1d7c. Field names and the slot
// count are inference.
struct Segment{char*base;char*cursor;unsigned frames;};
struct Slot{char*data;int u;int valid;};
struct Stream{char u0[108];unsigned count;unsigned char types[40];unsigned frames;char u156[16];int f172;char u176[16];int rd;char u196[28];Slot slots[11];char u356[4];Segment ring[4];int wr;};
struct Player{void*table;Stream*stream;};
extern char msg_803db344[];
extern "C" int fn_802e1a98(Player*,char*);
extern "C" int fn_802fb7ac(const char*,...);
extern "C" unsigned fn_80322308(char*,char*,int);
extern "C" int fn_802fdb6c();
extern "C" int fn_802fdb94(int);
extern "C" void fn_802e2248(Player*);
extern "C" int d26l_movie_frame_decode_802e1854(Player*self,int frame){
 int ok=1;
 if(self->stream->slots[self->stream->rd].valid==0)ok=0;
 if(ok){
  char*data=self->stream->slots[self->stream->rd].data;
  int*sizes=(int*)(data+8);
  char*comp=data+self->stream->count*4+8;
  if(self->stream->f172){
   if(frame<0||(unsigned)frame>=self->stream->frames){
    fn_802fb7ac(msg_803db344);
    return 4;
   }
   if(self->stream->ring[self->stream->wr].frames==0){
    for(unsigned i=0;i<self->stream->count;i++){
     switch(self->stream->types[i]){
     case 0:
      if(!fn_802e1a98(self,comp))return 1;
      break;
     case 1:{
      Segment*r=&self->stream->ring[self->stream->wr];
      unsigned n=fn_80322308(r->base,comp+sizes[0]*frame,0);
      int lock=fn_802fdb6c();
      r->frames=n;
      r->cursor=r->base;
      fn_802fdb94(lock);
      ++self->stream->wr;
      if(self->stream->wr>3)self->stream->wr=0;
      break;}
     }
     comp+=*sizes;
     ++sizes;
    }
   }else return 3;
  }else{
   for(unsigned i=0;i<self->stream->count;i++){
    if(self->stream->types[i]==0&&!fn_802e1a98(self,comp))return 1;
    comp+=*sizes;
    ++sizes;
   }
  }
  self->stream->slots[self->stream->rd].valid=0;
  int next=self->stream->rd+1;
  int v=0;
  if(next<=9)v=next;
  self->stream->rd=v;
  fn_802e2248(self);
  return 0;
 }
 return 2;
}

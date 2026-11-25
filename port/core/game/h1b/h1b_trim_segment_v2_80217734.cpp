#include "w3d_ptr.h"
#line 1 "h1b_trim_segment_v2_80217734.cpp"
// All layout types are external observed prefixes, never local complete objects.
struct Heap;struct Backend;
struct Segment {unsigned unknown;Ptr32<Segment> next;Ptr32<void> base;unsigned extent;Ptr32<char> end;unsigned available;};
struct State {unsigned flags,granularity,unknown;Ptr32<Segment> segments;};
typedef Ptr32<Ptr32<void> (Ptr32<Heap>, Ptr32<void>, unsigned int, unsigned int, Ptr32<Backend>)> Resize;
struct Backend {Resize resize;unsigned unknown,quantum;};
struct Heap {unsigned unknown[11];Ptr32<Backend> backend;Ptr32<State> state;};
extern unsigned lbl_80400770[];
extern "C" int h1b_trim_segment_v2_80217734(Ptr32<Heap> self,Ptr32<Segment> segment,unsigned request,int mode){
 Ptr32<State> state=self->state;Resize resize=self->backend->resize;Ptr32<void> base=segment->base;
 if(request<segment->available){
  unsigned size=self->backend->quantum;if(!size)size=lbl_80400770[0];
  size*=request/size;size&=~7u;
  if(!mode)size=(size/state->granularity)*state->granularity;
  if(size){
   if(request>size && request-size<24)size-=state->granularity;
   if(size && resize(self,base,segment->extent,segment->extent-size,self->backend)==base){
    segment->extent-=size;segment->available-=size;segment->end-=size;*(Ptr32<unsigned int>)(segment->end-4)=1;return 0;
   }
  }
 }else{
  Ptr32<Segment> head=state->segments;Ptr32<Segment> previous;
  if(segment==head){previous=0;state->segments=segment->next;}
  else{previous=head;Ptr32<Segment> next=segment->next;while(previous->next!=segment)previous=previous->next;previous->next=next;}
  if(resize(self,base,segment->extent,0,self->backend)==base)return 0;
  if(previous){segment->next=previous->next;previous->next=segment;}
  else{segment->next=state->segments;state->segments=segment;}
 }
 return -1;
}



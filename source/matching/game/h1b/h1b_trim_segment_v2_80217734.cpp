// All layout types are external observed prefixes, never local complete objects.
struct Heap;struct Backend;
struct Segment {unsigned unknown;Segment*next;void*base;unsigned extent;char*end;unsigned available;};
struct State {unsigned flags,granularity,unknown;Segment*segments;};
typedef void*(*Resize)(Heap*,void*,unsigned,unsigned,Backend*);
struct Backend {Resize resize;unsigned unknown,quantum;};
struct Heap {unsigned unknown[11];Backend*backend;State*state;};
extern unsigned lbl_80400770[];
extern "C" int h1b_trim_segment_v2_80217734(Heap*self,Segment*segment,unsigned request,int mode){
 State*state=self->state;Resize resize=self->backend->resize;void*base=segment->base;
 if(request<segment->available){
  unsigned size=self->backend->quantum;if(!size)size=lbl_80400770[0];
  size*=request/size;size&=~7u;
  if(!mode)size=(size/state->granularity)*state->granularity;
  if(size){
   if(request>size && request-size<24)size-=state->granularity;
   if(size && resize(self,base,segment->extent,segment->extent-size,self->backend)==base){
    segment->extent-=size;segment->available-=size;segment->end-=size;*(unsigned*)(segment->end-4)=1;return 0;
   }
  }
 }else{
  Segment*head=state->segments;Segment*previous;
  if(segment==head){previous=0;state->segments=segment->next;}
  else{previous=head;Segment*next=segment->next;while(previous->next!=segment)previous=previous->next;previous->next=next;}
  if(resize(self,base,segment->extent,0,self->backend)==base)return 0;
  if(previous){segment->next=previous->next;previous->next=segment;}
  else{segment->next=state->segments;state->segments=segment;}
 }
 return -1;
}

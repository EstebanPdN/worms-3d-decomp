// Inferred external movie/audio views; never constructed as local complete objects.
// Four 12-byte ring records and index wrap 0..3 are observed in the original.
// The union preserves the original big-endian low-half access to a saturated word.
struct Segment{void*base;short*cursor;unsigned frames;};
struct Stream{char unknown0[160];int active;char unknown164[4];void*source;void*decoded;char unknown176[32];float volume;char unknown212[148];Segment ring[4];char unknown408[4];int index;};
struct Player{void*table;Stream*stream;};
extern unsigned short volume_804040ec[];
extern "C" void fn_802e220c(Player*);
extern "C" void*fn_802eefe0(void*,int,unsigned);
union SampleWord{int value;unsigned short halves[2];};
inline void clamp(SampleWord&sample){if(sample.value < -32768)sample.value=-32768;if(sample.value>32767)sample.value=32767;}
extern "C" void g7b_copy_stereo_802e1d7c(Player*self,short*output,unsigned requested){
 Stream*state=self->stream;
 if(state){if(state->active&&state->source&&state->decoded){
 short*destination=output;unsigned pending=requested;

 Segment*segment=&self->stream->ring[self->stream->index];
 for(;;){
  unsigned available=segment->frames;
  if(!available)goto silence;
  unsigned count;if(available<pending)count=available;else count=pending;
  unsigned left=pending-count;
  short*input=segment->cursor;
  SampleWord sample;
  for(unsigned i=0;i<count;++i){
   fn_802e220c(self);
   int gain=volume_804040ec[(int)self->stream->volume];
   sample.value=(gain * (int)*input)>>15;clamp(sample);*destination++=sample.halves[1];
   sample.value=(gain * (int)*++input)>>15;clamp(sample);*destination++=sample.halves[1];
   ++input;
  }
  pending=left;
  segment->cursor=input;
  int remaining=segment->frames-count;segment->frames=remaining;
  if(!remaining){
   ++self->stream->index;
   if(self->stream->index>3)self->stream->index=remaining;
   segment=&self->stream->ring[self->stream->index];
  }
 if(!left)goto finished;
 }

silence:
 fn_802eefe0(destination,0,pending*4);
 }else fn_802eefe0(output,0,requested*4);}
finished:;
}

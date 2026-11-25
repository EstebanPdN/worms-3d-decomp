#include "w3d_ptr.h"
#line 1 "cx13b_movie_update_802e0c8c.cpp"
// PPC32 observed decoder/movie offsets; field and method names are inferred.
struct Movie;struct Vtable{Ptr32<void> unused[6];Ptr32<void (Ptr32<Movie>)> close;Ptr32<void> gap;Ptr32<void (Ptr32<Movie>)> stop;};
struct Frame{Ptr32<void> buffer;unsigned int ordinal,ready;};
struct Decoder{unsigned char opaque[68];unsigned int videoBytes,audioSamples;unsigned char gap76[4];unsigned int frames,first;unsigned char gap88[12];unsigned int base;unsigned char gap104[56];unsigned int opened,busy,counter,flag172,error,loop,offset,pending,unused192,index,bytes,ordinal;float volume,pitch,rate;int audio;Frame queue[10];Ptr32<void> y; Ptr32<void> u; Ptr32<void> v;int slot356;Frame audioQueue[4];int slot408,slot412;};
struct Movie{Ptr32<Vtable> vtable;Ptr32<Decoder> decoder;Ptr32<void> textures;int initialized;Ptr32<void> audio[2];unsigned int selected;Ptr32<void> callback;int s32,s36,mode;unsigned char pad[12];Ptr32<void> buffer;unsigned int time,interval,preloads;unsigned char pad72[8];int active,state;};

extern "C" int poll_802f76e0();extern "C" Ptr32<void> instance_80343994();extern "C" void notify_801fdbec(Ptr32<void>,int);extern "C" unsigned int ticks_80304c00();extern "C" int decode_802e1854(Ptr32<Movie>,int);extern "C" char file_803db1f8[],message_803db294[];extern "C" void report_802fb82c(Ptr32<const char>,int,Ptr32<const char>,...);extern "C" int frame_802e1b08(Ptr32<Movie>);extern "C" void advance_802e1710(Ptr32<Movie>);
extern "C" int w3d_cx13b_movie_update_802e0c8c(Ptr32<Movie> self){if(self->state==4){int state=poll_802f76e0();int error=0;switch(state){case -1:error=1;break;case 4:error=1;break;case 5:error=1;break;case 6:error=1;break;case 11:error=1;break;}notify_801fdbec(instance_80343994(),1);if(!error&&self->active){if(ticks_80304c00()>self->time+self->interval){if(decode_802e1854(self,*(Ptr32<int>)((Ptr32<unsigned char>)self+52))!=1){}else report_802fb82c(file_803db1f8,609,message_803db294);self->time=ticks_80304c00();}int frame=frame_802e1b08(self);if(frame==(int)self->interval)advance_802e1710(self);Ptr32<Decoder> d=self->decoder;if(frame==(int)d->frames-1&&!d->loop)self->state=6;}}return self->state;}





#include "w3d_ptr.h"
#line 1 "cx12b_movie_play_802e0db8.cpp"
// Original PPC32 layouts; movie field names are inferred from diagnostics and calls.
struct Movie;struct Vtable{Ptr32<void> unused[6];Ptr32<void (Ptr32<Movie>)> close;Ptr32<void> gap[1];Ptr32<void (Ptr32<Movie>)> stop;};
struct Frame{Ptr32<void> buffer;unsigned int a,b;};
struct Decoder{unsigned char opaque[80];unsigned int frames,first;unsigned char middle[12];unsigned int base;unsigned char tail[56];unsigned int opened,busy,counter,flag172,error,loop,offset,pending,unused192,index,bytes,ordinal;float volume,pitch,rate;int audio;Frame queue[16];};
struct Movie{Ptr32<Vtable> vtable;Ptr32<Decoder> decoder;Ptr32<void> textures;int initialized;Ptr32<void> audio[2];unsigned int selected;Ptr32<void> callback;int s32,s36,mode;unsigned char pad[12];Ptr32<void> buffer;unsigned char pad60[8];unsigned int preloads;unsigned char pad72[8];int active,state;};

extern "C" char uninitialized_803db2b0[],play_803db2e4[],file_803db1f8[],failure_803db2f0[];extern "C" int print_802ebfbc(Ptr32<const char>,...);extern "C" void trace_802fb7ac(Ptr32<const char>,...);extern "C" Ptr32<void> monitor_800c8120();extern "C" void flag_800c7fe4(Ptr32<void>,int);extern "C" int preload_802e1618(Ptr32<Movie>,int);extern "C" void report_802fb82c(Ptr32<const char>,int,Ptr32<const char>,...);
extern "C" int w3d_cx12b_movie_play_802e0db8(Ptr32<Movie> self,int loop){if(!self->initialized){print_802ebfbc(uninitialized_803db2b0);return 0;}trace_802fb7ac(play_803db2e4);flag_800c7fe4(monitor_800c8120(),1);self->active=1;int s=self->state;if(s==1||s==5||s==6){if(!preload_802e1618(self,loop)){report_802fb82c(file_803db1f8,665,failure_803db2f0);return 0;}}return 1;}




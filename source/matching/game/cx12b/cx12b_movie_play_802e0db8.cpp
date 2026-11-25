// Original PPC32 layouts; movie field names are inferred from diagnostics and calls.
struct Movie;struct Vtable{void*unused[6];void(*close)(Movie*);void*gap[1];void(*stop)(Movie*);};
struct Frame{void*buffer;unsigned int a,b;};
struct Decoder{unsigned char opaque[80];unsigned int frames,first;unsigned char middle[12];unsigned int base;unsigned char tail[56];unsigned int opened,busy,counter,flag172,error,loop,offset,pending,unused192,index,bytes,ordinal;float volume,pitch,rate;int audio;Frame queue[16];};
struct Movie{Vtable*vtable;Decoder*decoder;void*textures;int initialized;void*audio[2];unsigned int selected;void*callback;int s32,s36,mode;unsigned char pad[12];void*buffer;unsigned char pad60[8];unsigned int preloads;unsigned char pad72[8];int active,state;};

extern "C" char uninitialized_803db2b0[],play_803db2e4[],file_803db1f8[],failure_803db2f0[];extern "C" int print_802ebfbc(const char*,...);extern "C" void trace_802fb7ac(const char*,...);extern "C" void*monitor_800c8120();extern "C" void flag_800c7fe4(void*,int);extern "C" int preload_802e1618(Movie*,int);extern "C" void report_802fb82c(const char*,int,const char*,...);
extern "C" int w3d_cx12b_movie_play_802e0db8(Movie*self,int loop){if(!self->initialized){print_802ebfbc(uninitialized_803db2b0);return 0;}trace_802fb7ac(play_803db2e4);flag_800c7fe4(monitor_800c8120(),1);self->active=1;int s=self->state;if(s==1||s==5||s==6){if(!preload_802e1618(self,loop)){report_802fb82c(file_803db1f8,665,failure_803db2f0);return 0;}}return 1;}


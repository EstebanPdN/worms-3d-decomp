// PPC32 observed decoder/movie offsets; field and method names are inferred.
struct Movie;struct Vtable{void*unused[6];void(*close)(Movie*);void*gap;void(*stop)(Movie*);};
struct Frame{void*buffer;unsigned int ordinal,ready;};
struct Decoder{unsigned char opaque[68];unsigned int videoBytes,audioSamples;unsigned char gap76[4];unsigned int frames,first;unsigned char gap88[12];unsigned int base;unsigned char gap104[56];unsigned int opened,busy,counter,flag172,error,loop,offset,pending,unused192,index,bytes,ordinal;float volume,pitch,rate;int audio;Frame queue[10];void*y,*u,*v;int slot356;Frame audioQueue[4];int slot408,slot412;};
struct Movie{Vtable*vtable;Decoder*decoder;void*textures;int initialized;void*audio[2];unsigned int selected;void*callback;int s32,s36,mode;unsigned char pad[12];void*buffer;unsigned int time,interval,preloads;unsigned char pad72[8];int active,state;};

extern "C" int poll_802f76e0();extern "C" void*instance_80343994();extern "C" void notify_801fdbec(void*,int);extern "C" unsigned int ticks_80304c00();extern "C" int decode_802e1854(Movie*,int);extern "C" char file_803db1f8[],message_803db294[];extern "C" void report_802fb82c(const char*,int,const char*,...);extern "C" int frame_802e1b08(Movie*);extern "C" void advance_802e1710(Movie*);
extern "C" int w3d_cx13b_movie_update_802e0c8c(Movie*self){if(self->state==4){int state=poll_802f76e0();int error=0;switch(state){case -1:error=1;break;case 4:error=1;break;case 5:error=1;break;case 6:error=1;break;case 11:error=1;break;}notify_801fdbec(instance_80343994(),1);if(!error&&self->active){if(ticks_80304c00()>self->time+self->interval){if(decode_802e1854(self,*(int*)((unsigned char*)self+52))!=1){}else report_802fb82c(file_803db1f8,609,message_803db294);self->time=ticks_80304c00();}int frame=frame_802e1b08(self);if(frame==(int)self->interval)advance_802e1710(self);Decoder*d=self->decoder;if(frame==(int)d->frames-1&&!d->loop)self->state=6;}}return self->state;}



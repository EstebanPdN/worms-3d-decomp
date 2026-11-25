// Original PPC32 layouts; movie field names are inferred from diagnostics and calls.
struct Movie;struct Vtable{void*unused[6];void(*close)(Movie*);void*gap[1];void(*stop)(Movie*);};
struct Frame{void*buffer;unsigned int a,b;};
struct Decoder{unsigned char opaque[80];unsigned int frames,first;unsigned char middle[12];unsigned int base;unsigned char tail[56];unsigned int opened,busy,counter,flag172,error,loop,offset,pending,unused192,index,bytes,ordinal;float volume,pitch,rate;int audio;Frame queue[16];};
struct Movie{Vtable*vtable;Decoder*decoder;void*textures;int initialized;void*audio[2];unsigned int selected;void*callback;int s32,s36,mode;unsigned char pad[12];void*buffer;unsigned char pad60[8];unsigned int preloads;unsigned char pad72[8];int active,state;};

static inline unsigned k8c_slot_offset(unsigned i){return i*12+224;}
extern "C" void done_802e1478(int,void*);extern "C" int read_802f5568(void*,void*,unsigned int,unsigned int,void(*)(int,void*),int);extern "C" char failure_803db318[];extern "C" void trace_802fb7ac(const char*,...);extern "C" void*instance_80343994();extern "C" void notify_801fdbec(void*,int);
extern "C" int w3d_k8c_movie_preload_802e1618(Movie*self,int loop){if(self->decoder->opened&&!self->decoder->busy){self->preloads=10;if(!loop){unsigned int frames=self->decoder->frames;if(frames<=9)self->preloads=frames;}self->state=3;Decoder*d=self->decoder;if(read_802f5568(d,*(void**)((unsigned char*)d+k8c_slot_offset(d->index)),d->bytes,d->offset,done_802e1478,2)!=1){trace_802fb7ac(failure_803db318);notify_801fdbec(instance_80343994(),0);self->decoder->error=1;return 0;}self->decoder->loop=loop;notify_801fdbec(instance_80343994(),0);return 1;}return 0;}




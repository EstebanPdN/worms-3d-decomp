#include "w3d_ptr.h"
#line 1 "k8c_movie_preload_802e1618.cpp"
// Original PPC32 layouts; movie field names are inferred from diagnostics and calls.
struct Movie;struct Vtable{Ptr32<void> unused[6];Ptr32<void (Ptr32<Movie>)> close;Ptr32<void> gap[1];Ptr32<void (Ptr32<Movie>)> stop;};
struct Frame{Ptr32<void> buffer;unsigned int a,b;};
struct Decoder{unsigned char opaque[80];unsigned int frames,first;unsigned char middle[12];unsigned int base;unsigned char tail[56];unsigned int opened,busy,counter,flag172,error,loop,offset,pending,unused192,index,bytes,ordinal;float volume,pitch,rate;int audio;Frame queue[16];};
struct Movie{Ptr32<Vtable> vtable;Ptr32<Decoder> decoder;Ptr32<void> textures;int initialized;Ptr32<void> audio[2];unsigned int selected;Ptr32<void> callback;int s32,s36,mode;unsigned char pad[12];Ptr32<void> buffer;unsigned char pad60[8];unsigned int preloads;unsigned char pad72[8];int active,state;};

static inline unsigned k8c_slot_offset(unsigned i){return i*12+224;}
extern "C" void done_802e1478(int,Ptr32<void>);extern "C" int read_802f5568(Ptr32<void>,Ptr32<void>,unsigned int,unsigned int,Ptr32<void (int, Ptr32<void>)>,int);extern "C" char failure_803db318[];extern "C" void trace_802fb7ac(Ptr32<const char>,...);extern "C" Ptr32<void> instance_80343994();extern "C" void notify_801fdbec(Ptr32<void>,int);
extern "C" int w3d_k8c_movie_preload_802e1618(Ptr32<Movie> self,int loop){if(self->decoder->opened&&!self->decoder->busy){self->preloads=10;if(!loop){unsigned int frames=self->decoder->frames;if(frames<=9)self->preloads=frames;}self->state=3;Ptr32<Decoder> d=self->decoder;if(read_802f5568(d,*(Ptr32<Ptr32<void>>)((Ptr32<unsigned char>)d+k8c_slot_offset(d->index)),d->bytes,d->offset,done_802e1478,2)!=1){trace_802fb7ac(failure_803db318);notify_801fdbec(instance_80343994(),0);self->decoder->error=1;return 0;}self->decoder->loop=loop;notify_801fdbec(instance_80343994(),0);return 1;}return 0;}






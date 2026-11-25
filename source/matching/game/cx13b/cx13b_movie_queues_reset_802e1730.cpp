// PPC32 observed decoder/movie offsets; field and method names are inferred.
struct Movie;struct Vtable{void*unused[6];void(*close)(Movie*);void*gap;void(*stop)(Movie*);};
struct Frame{void*buffer;unsigned int ordinal,ready;};
struct Decoder{unsigned char opaque[68];unsigned int videoBytes,audioSamples;unsigned char gap76[4];unsigned int frames,first;unsigned char gap88[12];unsigned int base;unsigned char gap104[56];unsigned int opened,busy,counter,flag172,error,loop,offset,pending,unused192,index,bytes,ordinal;float volume,pitch,rate;int audio;Frame queue[10];void*y,*u,*v;int slot356;Frame audioQueue[4];int slot408,slot412;};
struct Movie{Vtable*vtable;Decoder*decoder;void*textures;int initialized;void*audio[2];unsigned int selected;void*callback;int s32,s36,mode;unsigned char pad[12];void*buffer;unsigned int time,interval,preloads;unsigned char pad72[8];int active,state;};

extern "C" int cancel_802f7a68(Decoder*);
extern "C" int w3d_cx13b_movie_queues_reset_802e1730(Movie*self){Decoder*d=self->decoder;if(d->opened&&!d->counter){unsigned int zero=d->counter;d->busy=zero;if(self->decoder->pending){cancel_802f7a68(self->decoder);self->decoder->pending=zero;}for(int i=0;i<10;++i)self->decoder->queue[i].ready=0;for(int i=0;i<4;++i)self->decoder->audioQueue[i].ready=0;self->decoder->slot356=-1;self->decoder->offset=self->decoder->base;self->decoder->bytes=self->decoder->first;self->decoder->index=0;self->decoder->ordinal=0;self->decoder->error=0;self->decoder->unused192=0;self->decoder->slot408=0;self->decoder->slot412=0;self->decoder->volume=self->decoder->pitch;self->decoder->audio=0;return 1;}return 0;}


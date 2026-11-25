// PPC32 observed decoder/movie offsets; field and method names are inferred.
struct Movie;struct Vtable{void*unused[6];void(*close)(Movie*);void*gap;void(*stop)(Movie*);};
struct Frame{void*buffer;unsigned int ordinal,ready;};
struct Decoder{unsigned char opaque[68];unsigned int videoBytes,audioSamples;unsigned char gap76[4];unsigned int frames,first;unsigned char gap88[12];unsigned int base;unsigned char gap104[56];unsigned int opened,busy,counter,flag172,error,loop,offset,pending,unused192,index,bytes,ordinal;float volume,pitch,rate;int audio;Frame queue[10];void*y,*u,*v;int slot356;Frame audioQueue[4];int slot408,slot412;};
struct Movie{Vtable*vtable;Decoder*decoder;void*textures;int initialized;void*audio[2];unsigned int selected;void*callback;int s32,s36,mode;unsigned char pad[12];void*buffer;unsigned int time,interval,preloads;unsigned char pad72[8];int active,state;};

extern "C" char message_803db278[];extern "C" int print_802ebfbc(const char*,...);extern "C" int close_802f5320(Decoder*);extern "C" void*heap_804ab8b4;extern "C" void free_80209920(void*,void*);extern "C" void reset_80209968(void*);
extern "C" int w3d_cx13b_movie_close_request_802e0b2c(Movie*self){if(!self->initialized){print_802ebfbc(message_803db278);return 0;}self->vtable->stop(self);self->state=2;Decoder*d=self->decoder;if(d->opened&&!d->busy){if(d->flag172){if(d->counter==1)return 0;}else d->counter=0;if(!self->decoder->pending){self->decoder->opened=0;close_802f5320(self->decoder);return 1;}}if(self->buffer)free_80209920(heap_804ab8b4,self->buffer);self->buffer=0;reset_80209968(heap_804ab8b4);return 0;}


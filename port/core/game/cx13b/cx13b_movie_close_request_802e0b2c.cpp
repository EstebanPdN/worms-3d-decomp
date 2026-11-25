#include "w3d_ptr.h"
#line 1 "cx13b_movie_close_request_802e0b2c.cpp"
// PPC32 observed decoder/movie offsets; field and method names are inferred.
struct Movie;struct Vtable{Ptr32<void> unused[6];Ptr32<void (Ptr32<Movie>)> close;Ptr32<void> gap;Ptr32<void (Ptr32<Movie>)> stop;};
struct Frame{Ptr32<void> buffer;unsigned int ordinal,ready;};
struct Decoder{unsigned char opaque[68];unsigned int videoBytes,audioSamples;unsigned char gap76[4];unsigned int frames,first;unsigned char gap88[12];unsigned int base;unsigned char gap104[56];unsigned int opened,busy,counter,flag172,error,loop,offset,pending,unused192,index,bytes,ordinal;float volume,pitch,rate;int audio;Frame queue[10];Ptr32<void> y; Ptr32<void> u; Ptr32<void> v;int slot356;Frame audioQueue[4];int slot408,slot412;};
struct Movie{Ptr32<Vtable> vtable;Ptr32<Decoder> decoder;Ptr32<void> textures;int initialized;Ptr32<void> audio[2];unsigned int selected;Ptr32<void> callback;int s32,s36,mode;unsigned char pad[12];Ptr32<void> buffer;unsigned int time,interval,preloads;unsigned char pad72[8];int active,state;};

extern "C" char message_803db278[];extern "C" int print_802ebfbc(Ptr32<const char>,...);extern "C" int close_802f5320(Ptr32<Decoder>);extern "C" Ptr32<void> heap_804ab8b4;extern "C" void free_80209920(Ptr32<void>,Ptr32<void>);extern "C" void reset_80209968(Ptr32<void>);
extern "C" int w3d_cx13b_movie_close_request_802e0b2c(Ptr32<Movie> self){if(!self->initialized){print_802ebfbc(message_803db278);return 0;}self->vtable->stop(self);self->state=2;Ptr32<Decoder> d=self->decoder;if(d->opened&&!d->busy){if(d->flag172){if(d->counter==1)return 0;}else d->counter=0;if(!self->decoder->pending){self->decoder->opened=0;close_802f5320(self->decoder);return 1;}}if(self->buffer)free_80209920(heap_804ab8b4,self->buffer);self->buffer=0;reset_80209968(heap_804ab8b4);return 0;}




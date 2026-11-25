#include "w3d_ptr.h"
#line 1 "cx13b_movie_async_read_complete_802e1360.cpp"
// PPC32 observed decoder/movie offsets; field and method names are inferred.
struct Movie;struct Vtable{Ptr32<void> unused[6];Ptr32<void (Ptr32<Movie>)> close;Ptr32<void> gap;Ptr32<void (Ptr32<Movie>)> stop;};
struct Frame{Ptr32<void> buffer;unsigned int ordinal,ready;};
struct Decoder{unsigned char opaque[68];unsigned int videoBytes,audioSamples;unsigned char gap76[4];unsigned int frames,first;unsigned char gap88[12];unsigned int base;unsigned char gap104[56];unsigned int opened,busy,counter,flag172,error,loop,offset,pending,unused192,index,bytes,ordinal;float volume,pitch,rate;int audio;Frame queue[10];Ptr32<void> y; Ptr32<void> u; Ptr32<void> v;int slot356;Frame audioQueue[4];int slot408,slot412;};
struct Movie{Ptr32<Vtable> vtable;Ptr32<Decoder> decoder;Ptr32<void> textures;int initialized;Ptr32<void> audio[2];unsigned int selected;Ptr32<void> callback;int s32,s36,mode;unsigned char pad[12];Ptr32<void> buffer;unsigned int time,interval,preloads;unsigned char pad72[8];int active,state;};

extern "C" Ptr32<Movie> current_804b190c;extern "C" void read_802e128c(Ptr32<Movie>);
extern "C" void w3d_cx13b_movie_async_read_complete_802e1360(int status,Ptr32<void>){Ptr32<Movie> self=current_804b190c;if(status==-1){self->decoder->error=1;self->state=7;}else if(status!=-3){self->decoder->pending=0;self->decoder->queue[self->decoder->index].ordinal=self->decoder->ordinal;self->decoder->ordinal++;self->decoder->queue[self->decoder->index].ready=1;self->decoder->offset+=self->decoder->bytes;Ptr32<Decoder> d=self->decoder;d->bytes=*(Ptr32<unsigned int>)d->queue[d->index].buffer;unsigned int next=self->decoder->index+1;int wrapped=0;if((int)next<=9)wrapped=next;self->decoder->index=wrapped;int ready=1;if(!self->decoder->queue[self->decoder->index].ready)ready=0;if(!ready)read_802e128c(self);}}





#include "w3d_ptr.h"
#line 1 "cx12b_movie_frame_read_async_802e128c.cpp"
// Original PPC32 layouts; movie field names are inferred from diagnostics and calls.
struct Movie;struct Vtable{Ptr32<void> unused[6];Ptr32<void (Ptr32<Movie>)> close;Ptr32<void> gap[1];Ptr32<void (Ptr32<Movie>)> stop;};
struct Frame{Ptr32<void> buffer;unsigned int a,b;};
struct Decoder{unsigned char opaque[80];unsigned int frames,first;unsigned char middle[12];unsigned int base;unsigned char tail[56];unsigned int opened,busy,counter,flag172,error,loop,offset,pending,unused192,index,bytes,ordinal;float volume,pitch,rate;int audio;Frame queue[16];};
struct Movie{Ptr32<Vtable> vtable;Ptr32<Decoder> decoder;Ptr32<void> textures;int initialized;Ptr32<void> audio[2];unsigned int selected;Ptr32<void> callback;int s32,s36,mode;unsigned char pad[12];Ptr32<void> buffer;unsigned char pad60[8];unsigned int preloads;unsigned char pad72[8];int active,state;};

extern "C" void done_802e1360(int,Ptr32<void>);extern "C" int read_802f5568(Ptr32<void>,Ptr32<void>,unsigned int,unsigned int,Ptr32<void (int, Ptr32<void>)>,int);
extern "C" void w3d_cx12b_movie_frame_read_async_802e128c(Ptr32<Movie> self){Ptr32<Decoder> d=self->decoder;int error=d->error;if(!error&&d->busy){if(d->ordinal>d->frames-1){if(d->loop!=1)return;d->ordinal=error;self->decoder->offset=self->decoder->base;self->decoder->bytes=self->decoder->first;}self->decoder->pending=1;Ptr32<Decoder> current=self->decoder;if(read_802f5568(current,current->queue[current->index].buffer,current->bytes,current->offset,done_802e1360,2)!=1){self->decoder->pending=error;self->decoder->error=1;}}}





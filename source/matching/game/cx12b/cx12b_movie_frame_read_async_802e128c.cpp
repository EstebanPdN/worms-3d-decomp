// Original PPC32 layouts; movie field names are inferred from diagnostics and calls.
struct Movie;struct Vtable{void*unused[6];void(*close)(Movie*);void*gap[1];void(*stop)(Movie*);};
struct Frame{void*buffer;unsigned int a,b;};
struct Decoder{unsigned char opaque[80];unsigned int frames,first;unsigned char middle[12];unsigned int base;unsigned char tail[56];unsigned int opened,busy,counter,flag172,error,loop,offset,pending,unused192,index,bytes,ordinal;float volume,pitch,rate;int audio;Frame queue[16];};
struct Movie{Vtable*vtable;Decoder*decoder;void*textures;int initialized;void*audio[2];unsigned int selected;void*callback;int s32,s36,mode;unsigned char pad[12];void*buffer;unsigned char pad60[8];unsigned int preloads;unsigned char pad72[8];int active,state;};

extern "C" void done_802e1360(int,void*);extern "C" int read_802f5568(void*,void*,unsigned int,unsigned int,void(*)(int,void*),int);
extern "C" void w3d_cx12b_movie_frame_read_async_802e128c(Movie*self){Decoder*d=self->decoder;int error=d->error;if(!error&&d->busy){if(d->ordinal>d->frames-1){if(d->loop!=1)return;d->ordinal=error;self->decoder->offset=self->decoder->base;self->decoder->bytes=self->decoder->first;}self->decoder->pending=1;Decoder *current=self->decoder;if(read_802f5568(current,current->queue[current->index].buffer,current->bytes,current->offset,done_802e1360,2)!=1){self->decoder->pending=error;self->decoder->error=1;}}}



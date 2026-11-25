// PPC32 observed decoder/movie offsets; field and method names are inferred.
struct Movie;struct Vtable{void*unused[6];void(*close)(Movie*);void*gap;void(*stop)(Movie*);};
struct Frame{void*buffer;unsigned int ordinal,ready;};
struct Decoder{unsigned char opaque[68];unsigned int videoBytes,audioSamples;unsigned char gap76[4];unsigned int frames,first;unsigned char gap88[12];unsigned int base;unsigned char gap104[56];unsigned int opened,busy,counter,flag172,error,loop,offset,pending,unused192,index,bytes,ordinal;float volume,pitch,rate;int audio;Frame queue[10];void*y,*u,*v;int slot356;Frame audioQueue[4];int slot408,slot412;};
struct Movie{Vtable*vtable;Decoder*decoder;void*textures;int initialized;void*audio[2];unsigned int selected;void*callback;int s32,s36,mode;unsigned char pad[12];void*buffer;unsigned int time,interval,preloads;unsigned char pad72[8];int active,state;};

extern "C" Movie*current_804b190c;extern "C" void read_802e128c(Movie*);
extern "C" void w3d_cx13b_movie_async_read_complete_802e1360(int status,void*){Movie*self=current_804b190c;if(status==-1){self->decoder->error=1;self->state=7;}else if(status!=-3){self->decoder->pending=0;self->decoder->queue[self->decoder->index].ordinal=self->decoder->ordinal;self->decoder->ordinal++;self->decoder->queue[self->decoder->index].ready=1;self->decoder->offset+=self->decoder->bytes;Decoder*d=self->decoder;d->bytes=*(unsigned int*)d->queue[d->index].buffer;unsigned int next=self->decoder->index+1;int wrapped=0;if((int)next<=9)wrapped=next;self->decoder->index=wrapped;int ready=1;if(!self->decoder->queue[self->decoder->index].ready)ready=0;if(!ready)read_802e128c(self);}}



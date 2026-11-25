// Original PPC32 layouts; movie field names are inferred from diagnostics and calls.
struct Movie;struct Vtable{void*unused[6];void(*close)(Movie*);void*gap[1];void(*stop)(Movie*);};
struct Frame{void*buffer;unsigned int a,b;};
struct Decoder{unsigned char opaque[80];unsigned int frames,first;unsigned char middle[12];unsigned int base;unsigned char tail[56];unsigned int opened,busy,counter,flag172,error,loop,offset,pending,unused192,index,bytes,ordinal;float volume,pitch,rate;int audio;Frame queue[16];};
struct Movie{Vtable*vtable;Decoder*decoder;void*textures;int initialized;void*audio[2];unsigned int selected;void*callback;int s32,s36,mode;unsigned char pad[12];void*buffer;unsigned char pad60[8];unsigned int preloads;unsigned char pad72[8];int active,state;};

extern "C" char message_803db058[];extern "C" int print_802ebfbc(const char*,...);extern "C" void quit_802fabc8();extern "C" unsigned int lock_802fdb6c();extern "C" int unlock_802fdb94(unsigned int);extern "C" void*callback_80311210(void*);extern "C" void*heap_804ab8b4;extern "C" void release_80209920(void*,void*);extern "C" void collect_80209968(void*);extern "C" void destroy_801fe1f8(void*);
inline void shutdown(Movie*self,int zero){self->initialized=zero;if(self->buffer)release_80209920(heap_804ab8b4,self->buffer);self->buffer=0;if(self->audio[0])release_80209920(heap_804ab8b4,self->audio[0]);self->audio[0]=0;if(self->audio[1])release_80209920(heap_804ab8b4,self->audio[1]);self->audio[1]=0;collect_80209968(heap_804ab8b4);if(self->decoder)destroy_801fe1f8(self->decoder);self->decoder=0;if(self->textures)destroy_801fe1f8(self->textures);self->textures=0;}
extern "C" void w3d_cx12b_movie_shutdown_802e03e0(Movie*self){if(!self->initialized){print_802ebfbc(message_803db058);}else{self->vtable->close(self);quit_802fabc8();unsigned int state=lock_802fdb6c();if(self->callback)callback_80311210(self->callback);unlock_802fdb94(state);shutdown(self,0);}}


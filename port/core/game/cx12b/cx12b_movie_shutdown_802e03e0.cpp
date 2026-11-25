#include "w3d_ptr.h"
#line 1 "cx12b_movie_shutdown_802e03e0.cpp"
// Original PPC32 layouts; movie field names are inferred from diagnostics and calls.
struct Movie;struct Vtable{Ptr32<void> unused[6];Ptr32<void (Ptr32<Movie>)> close;Ptr32<void> gap[1];Ptr32<void (Ptr32<Movie>)> stop;};
struct Frame{Ptr32<void> buffer;unsigned int a,b;};
struct Decoder{unsigned char opaque[80];unsigned int frames,first;unsigned char middle[12];unsigned int base;unsigned char tail[56];unsigned int opened,busy,counter,flag172,error,loop,offset,pending,unused192,index,bytes,ordinal;float volume,pitch,rate;int audio;Frame queue[16];};
struct Movie{Ptr32<Vtable> vtable;Ptr32<Decoder> decoder;Ptr32<void> textures;int initialized;Ptr32<void> audio[2];unsigned int selected;Ptr32<void> callback;int s32,s36,mode;unsigned char pad[12];Ptr32<void> buffer;unsigned char pad60[8];unsigned int preloads;unsigned char pad72[8];int active,state;};

extern "C" char message_803db058[];extern "C" int print_802ebfbc(Ptr32<const char>,...);extern "C" void quit_802fabc8();extern "C" unsigned int lock_802fdb6c();extern "C" int unlock_802fdb94(unsigned int);extern "C" Ptr32<void> callback_80311210(Ptr32<void>);extern "C" Ptr32<void> heap_804ab8b4;extern "C" void release_80209920(Ptr32<void>,Ptr32<void>);extern "C" void collect_80209968(Ptr32<void>);extern "C" void destroy_801fe1f8(Ptr32<void>);
inline void shutdown(Ptr32<Movie> self,int zero){self->initialized=zero;if(self->buffer)release_80209920(heap_804ab8b4,self->buffer);self->buffer=0;if(self->audio[0])release_80209920(heap_804ab8b4,self->audio[0]);self->audio[0]=0;if(self->audio[1])release_80209920(heap_804ab8b4,self->audio[1]);self->audio[1]=0;collect_80209968(heap_804ab8b4);if(self->decoder)destroy_801fe1f8(self->decoder);self->decoder=0;if(self->textures)destroy_801fe1f8(self->textures);self->textures=0;}
extern "C" void w3d_cx12b_movie_shutdown_802e03e0(Ptr32<Movie> self){if(!self->initialized){print_802ebfbc(message_803db058);}else{self->vtable->close(self);quit_802fabc8();unsigned int state=lock_802fdb6c();if(self->callback)callback_80311210(self->callback);unlock_802fdb94(state);shutdown(self,0);}}




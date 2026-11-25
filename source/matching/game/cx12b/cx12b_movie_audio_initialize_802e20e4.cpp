// Original PPC32 layouts; movie field names are inferred from diagnostics and calls.
struct Movie;struct Vtable{void*unused[6];void(*close)(Movie*);void*gap[1];void(*stop)(Movie*);};
struct Frame{void*buffer;unsigned int a,b;};
struct Decoder{unsigned char opaque[80];unsigned int frames,first;unsigned char middle[12];unsigned int base;unsigned char tail[56];unsigned int opened,busy,counter,flag172,error,loop,offset,pending,unused192,index,bytes,ordinal;float volume,pitch,rate;int audio;Frame queue[16];};
struct Movie{Vtable*vtable;Decoder*decoder;void*textures;int initialized;void*audio[2];unsigned int selected;void*callback;int s32,s36,mode;unsigned char pad[12];void*buffer;unsigned char pad60[8];unsigned int preloads;unsigned char pad72[8];int active,state;};


extern "C" unsigned int lock_802fdb6c();extern "C" int unlock_802fdb94(unsigned int);extern "C" void*heap_804ab8b4;extern "C" void*allocate_802098fc(void*,unsigned int,unsigned int);extern "C" void callback_802e1f88();extern "C" void*install_80311210(void(*)());extern "C" void trace_802fb7ac(const char*,...);extern "C" char message_803db370[];extern "C" void*clear_802eefe0(void*,int,unsigned int);extern "C" void cache_802fa988(void*,unsigned int);extern "C" void submit_80311254(void*,unsigned int);extern "C" void start_803112dc();
extern "C" int w3d_cx12b_movie_audio_initialize_802e20e4(Movie*self,int mode){unsigned int state=lock_802fdb6c();self->mode=mode;self->selected=0;self->s32=0;self->s36=0;self->audio[0]=allocate_802098fc(heap_804ab8b4,640,32);self->audio[1]=allocate_802098fc(heap_804ab8b4,640,32);self->callback=install_80311210(callback_802e1f88);if(!self->callback&&self->mode){install_80311210(0);unlock_802fdb94(state);trace_802fb7ac(message_803db370);return 0;}unlock_802fdb94(state);if(!self->mode){clear_802eefe0(self->audio[0],0,640);clear_802eefe0(self->audio[1],0,640);cache_802fa988(self->audio[0],640);cache_802fa988(self->audio[1],640);submit_80311254(self->audio[self->selected],640);start_803112dc();}return 1;}



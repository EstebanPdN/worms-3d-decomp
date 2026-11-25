// Original 8002d3e4. Names inferred; state vectors copied by their observed words.
struct cc31a_Vector_8002d3e4 {unsigned x,y,z;};
struct cc31a_Owner_8002d3e4 {unsigned unknown;cc31a_Vector_8002d3e4 position,target,up;char gap[36];int state;};
extern void* cc31a_arena_804b1754;
extern unsigned cc31a_cache_804accdc,cc31a_cache_804accd4;
extern char cc31a_text_8037296c[];
extern char cc31a_text_80372974[];
extern char cc31a_text_80372984[];
extern char cc31a_text_8037298c[];
extern char cc31a_text_803729a4[];
extern char cc31a_text_803729b0[];
extern char cc31a_text_803729bc[];
extern char cc31a_text_803729c8[];
extern char cc31a_text_803729d8[];
extern "C" {void cc31a_call_8015a6b8(cc31a_Owner_8002d3e4*,cc31a_Owner_8002d3e4*);void*cc31a_call_801613f0(void*,unsigned);unsigned cc31a_call_8015f5a0(unsigned*,int);void*cc31a_call_8010a8e0(void*,unsigned short,const char*);int cc31a_call_8016239c(void*);
void cc31a_camera_restore_modes_8002d3e4(cc31a_Owner_8002d3e4*self,cc31a_Owner_8002d3e4*src) {
 self->state=0;self->position=src->position;self->target=src->target;self->up=src->up;
 cc31a_call_8015a6b8(self,src);
{void*message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accdc,1),cc31a_text_8037296c));}
{void*message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accdc,1),cc31a_text_80372974));}
{void*message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accdc,1),cc31a_text_80372984));}
{void*message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accd4,1),cc31a_text_8037298c));}
{void*message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accd4,1),cc31a_text_803729a4));}
{void*message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accd4,1),cc31a_text_803729b0));}
{void*message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accd4,1),cc31a_text_803729bc));}
{void*message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accd4,1),cc31a_text_803729c8));}
{void*message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accd4,1),cc31a_text_803729d8));}
}}

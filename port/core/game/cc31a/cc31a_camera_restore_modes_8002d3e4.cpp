#include "w3d_ptr.h"
#line 1 "cc31a_camera_restore_modes_8002d3e4.cpp"
// Original 8002d3e4. Names inferred; state vectors copied by their observed words.
struct cc31a_Vector_8002d3e4 {unsigned x,y,z;};
struct cc31a_Owner_8002d3e4 {unsigned unknown;cc31a_Vector_8002d3e4 position,target,up;char gap[36];int state;};
extern Ptr32<void> cc31a_arena_804b1754;
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
extern "C" {void cc31a_call_8015a6b8(Ptr32<cc31a_Owner_8002d3e4>,Ptr32<cc31a_Owner_8002d3e4>);Ptr32<void> cc31a_call_801613f0(Ptr32<void>,unsigned);unsigned cc31a_call_8015f5a0(Ptr32<unsigned int>,int);Ptr32<void> cc31a_call_8010a8e0(Ptr32<void>,unsigned short,Ptr32<const char>);int cc31a_call_8016239c(Ptr32<void>);
void cc31a_camera_restore_modes_8002d3e4(Ptr32<cc31a_Owner_8002d3e4> self,Ptr32<cc31a_Owner_8002d3e4> src) {
 self->state=0;self->position=src->position;self->target=src->target;self->up=src->up;
 cc31a_call_8015a6b8(self,src);
{Ptr32<void> message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accdc,1),cc31a_text_8037296c));}
{Ptr32<void> message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accdc,1),cc31a_text_80372974));}
{Ptr32<void> message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accdc,1),cc31a_text_80372984));}
{Ptr32<void> message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accd4,1),cc31a_text_8037298c));}
{Ptr32<void> message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accd4,1),cc31a_text_803729a4));}
{Ptr32<void> message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accd4,1),cc31a_text_803729b0));}
{Ptr32<void> message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accd4,1),cc31a_text_803729bc));}
{Ptr32<void> message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accd4,1),cc31a_text_803729c8));}
{Ptr32<void> message=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_8010a8e0(message,cc31a_call_8015f5a0(&cc31a_cache_804accd4,1),cc31a_text_803729d8));}
}}



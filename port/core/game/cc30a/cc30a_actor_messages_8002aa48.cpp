#include "w3d_ptr.h"
#line 1 "cc30a_actor_messages_8002aa48.cpp"
// Original 8002aa48; eight-byte arena message and virtual event routes.
struct cc30a_Owner_8002aa48;
struct cc30a_VTable_8002aa48 {char gap[40];Ptr32<void (Ptr32<cc30a_Owner_8002aa48>)> start;Ptr32<void (Ptr32<cc30a_Owner_8002aa48>)> conditional;Ptr32<void (Ptr32<cc30a_Owner_8002aa48>)> stop;};
struct cc30a_Owner_8002aa48 {Ptr32<cc30a_VTable_8002aa48> vt;char gap[56];unsigned pending;};
struct cc30a_Message_8002aa48 {unsigned short id,unknown;Ptr32<void> type;};
extern unsigned cc30a_cache_804acc44,cc30a_cache_804acc34,cc30a_cache_804acc4c,cc30a_cache_804acc5c;
extern char cc30a_type_8040db38[];extern Ptr32<void> cc30a_arena_804b1754;
extern "C" {int cc30a_call_8015fb34(Ptr32<void>,Ptr32<void>);void cc30a_call_8002aba4(Ptr32<void>);void cc30a_call_8002acd0(Ptr32<void>);int cc30a_call_8002b0a0(Ptr32<void>);int cc30a_call_8015f65c(unsigned short,Ptr32<unsigned int>);unsigned short cc30a_call_8015f5a0(Ptr32<unsigned int>,int);Ptr32<void> cc30a_call_801613f0(Ptr32<void>,unsigned);int cc30a_call_8016239c(Ptr32<void>);
int cc30a_actor_messages_8002aa48(Ptr32<cc30a_Owner_8002aa48> self,Ptr32<unsigned short> msg){unsigned short id=*msg;
 switch(id){case 64:if(cc30a_call_8015fb34(self,msg)>=0){cc30a_call_8002aba4(self);return 0;}return 0x80004005;
 case 66:if(self->pending){Ptr32<cc30a_Message_8002aa48> m=(Ptr32<cc30a_Message_8002aa48>)cc30a_call_801613f0(cc30a_arena_804b1754,8);m->id=cc30a_call_8015f5a0(&cc30a_cache_804acc44,1);m->type=cc30a_type_8040db38;cc30a_call_8016239c(m);}cc30a_call_8002acd0(self);break;
 default:if(cc30a_call_8015f65c(id,&cc30a_cache_804acc34))self->vt->start(self);
 else if(cc30a_call_8015f65c(id,&cc30a_cache_804acc4c)){if(cc30a_call_8002b0a0(self))self->vt->conditional(self);}
 else if(cc30a_call_8015f65c(id,&cc30a_cache_804acc5c))self->vt->stop(self);
 }return cc30a_call_8015fb34(self,msg);
}}



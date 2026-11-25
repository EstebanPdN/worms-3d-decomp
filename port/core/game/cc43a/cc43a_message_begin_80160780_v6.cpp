#include "w3d_ptr.h"
#line 1 "cc43a_message_begin_80160780_v6.cpp"
// Original DOL 803a4660 contains big-endian 00000000 (float +0.0).
// Inferred message fields and sender prefix. The allocator request witnesses
// 36 bytes for this message view; unrelated classes remain incomplete.
struct cc43a_Arena;
struct cc43a_Sender { unsigned char unknown00[32]; float x,y; };
extern "C" Ptr32<cc43a_Arena> cc43a_arena_804b1754;
extern "C" Ptr32<void> cc43a_allocate_801613f0(Ptr32<cc43a_Arena>,unsigned int);
extern "C" unsigned int cc43a_messageIds_803fe234[];
extern "C" Ptr32<void> cc43a_messageVtable_8040db38[];
struct cc43a_Message {
 unsigned short tag,unknown02;
 Ptr32<void> vtable;
 unsigned int kind,id;
 unsigned short a,b;
 unsigned char active,unknown15[3];
 float x,y,z;
 static void* operator new(__SIZE_TYPE__ size) {return cc43a_allocate_801613f0(cc43a_arena_804b1754,size);}
 cc43a_Message(unsigned int mode,unsigned int event,unsigned short bits,unsigned char enabled,float px,float py,float pz):tag(0x1004),vtable(cc43a_messageVtable_8040db38),kind(mode),id(event),a(bits),b(bits),active(enabled),x(px),y(py),z(pz) {}
};
extern "C" int cc43a_dispatch_8015fc84(Ptr32<cc43a_Sender>,Ptr32<cc43a_Message>);
extern "C" void cc43a_message_begin_80160780(Ptr32<cc43a_Sender> self,unsigned int unused,unsigned int index) {
 Ptr32<cc43a_Message> message=new cc43a_Message(2,cc43a_messageIds_803fe234[index],0,0,self->x,self->y,0.0f);
 cc43a_dispatch_8015fc84(self,message);
}



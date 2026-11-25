// Inferred message fields and sender prefix. The allocator request witnesses
// 36 bytes for this message view; unrelated classes remain incomplete.
struct cc43a_Arena;
struct cc43a_Sender { unsigned char unknown00[32]; float x,y; };
extern "C" cc43a_Arena* cc43a_arena_804b1754;
extern "C" void* cc43a_allocate_801613f0(cc43a_Arena*,unsigned int);
extern "C" unsigned int cc43a_messageIds_803fe234[];
extern "C" void* cc43a_messageVtable_8040db38[];
extern "C" const float cc43a_zero_803a4660[];
struct cc43a_Message {
 unsigned short tag,unknown02;
 void* vtable;
 unsigned int kind,id;
 unsigned short a,b;
 unsigned char active,unknown15[3];
 float x,y,z;
 static void* operator new(unsigned int size) {return cc43a_allocate_801613f0(cc43a_arena_804b1754,size);}
 cc43a_Message(unsigned int mode,unsigned int event,unsigned short bits,unsigned char enabled,float pz,float px,float py):tag(0x1004),vtable(cc43a_messageVtable_8040db38),kind(mode),id(event),a(bits),b(bits),active(enabled),x(px),y(py),z(pz) {}
};
extern "C" int cc43a_dispatch_8015fc84(cc43a_Sender*,cc43a_Message*);
extern "C" void cc43a_message_begin_80160780(cc43a_Sender* self,unsigned int unused,unsigned int index) {
 cc43a_Message* message=new cc43a_Message(2,cc43a_messageIds_803fe234[index],0,0,cc43a_zero_803a4660[0],self->x,self->y);
 cc43a_dispatch_8015fc84(self,message);
}

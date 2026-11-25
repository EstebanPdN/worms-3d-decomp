#include "w3d_ptr.h"
#line 1 "cxa_motion_messages.cpp"
// Original instruction layout verified at 0x80021c60 and 0x80021d8c.
// Names describe observed operations; no original class identity is asserted.
struct CxaVector {
 float x,y,z;
 CxaVector(const CxaVector &v) {float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}
};
// Only the observed message prefix is described; the arena reserves 236 bytes.
struct CxaMessage {unsigned char header[8];int kind;unsigned char gap[4];CxaVector position; void setPosition(CxaVector value) {position=value;} };
struct CxaOwner {unsigned char unknown[20];CxaVector position;};
extern "C" Ptr32<void> arena_804b1754;
extern "C" Ptr32<void> reserve_801613f0(Ptr32<void>,unsigned int);
extern "C" Ptr32<CxaMessage> construct_80131a84(Ptr32<void>);
extern "C" int post_8016239c(Ptr32<CxaMessage>);
extern "C" int cxa_motion_message_80021c60(Ptr32<CxaOwner> self) {
 Ptr32<CxaMessage> message=construct_80131a84(reserve_801613f0(arena_804b1754,236));
 message->kind=5;
 message->setPosition(self->position);
 post_8016239c(message);
 return 0;
}
extern "C" int cxa_motion_message_80021d8c(Ptr32<CxaOwner> self) {
 Ptr32<CxaMessage> message=construct_80131a84(reserve_801613f0(arena_804b1754,236));
 message->kind=15;
 message->setPosition(self->position);
 post_8016239c(message);
 return 0;
}

struct CxaTimedOwner {unsigned char unknown[20];unsigned int time;CxaVector position;};
struct CxaContext {unsigned char unknown[52];unsigned int time;};
typedef char CxaVectorSize[(sizeof(CxaVector)==12)?1:-1];
extern "C" Ptr32<CxaContext> context_80165254();
extern "C" int cxa_motion_message_8002165c(Ptr32<CxaTimedOwner> self) {
 self->time+=context_80165254()->time;
 Ptr32<CxaMessage> message=construct_80131a84(reserve_801613f0(arena_804b1754,236));
 message->kind=4;
 message->setPosition(self->position);
 post_8016239c(message);
 return 0;
}



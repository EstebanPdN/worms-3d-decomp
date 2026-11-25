// Original instruction layout verified at 0x80021c60 and 0x80021d8c.
// Names describe observed operations; no original class identity is asserted.
struct CxaVector {
 float x,y,z;
 CxaVector(const CxaVector &v) {float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}
};
// Only the observed message prefix is described; the arena reserves 236 bytes.
struct CxaMessage {unsigned char header[8];int kind;unsigned char gap[4];CxaVector position; void setPosition(CxaVector value) {position=value;} };
struct CxaOwner {unsigned char unknown[20];CxaVector position;};
extern "C" void *arena_804b1754;
extern "C" void *reserve_801613f0(void*,unsigned int);
extern "C" CxaMessage *construct_80131a84(void*);
extern "C" int post_8016239c(CxaMessage*);
extern "C" int cxa_motion_message_80021c60(CxaOwner *self) {
 CxaMessage *message=construct_80131a84(reserve_801613f0(arena_804b1754,236));
 message->kind=5;
 message->setPosition(self->position);
 post_8016239c(message);
 return 0;
}
extern "C" int cxa_motion_message_80021d8c(CxaOwner *self) {
 CxaMessage *message=construct_80131a84(reserve_801613f0(arena_804b1754,236));
 message->kind=15;
 message->setPosition(self->position);
 post_8016239c(message);
 return 0;
}

struct CxaTimedOwner {unsigned char unknown[20];unsigned int time;CxaVector position;};
struct CxaContext {unsigned char unknown[52];unsigned int time;};
typedef char CxaVectorSize[(sizeof(CxaVector)==12)?1:-1];
extern "C" CxaContext *context_80165254();
extern "C" int cxa_motion_message_8002165c(CxaTimedOwner *self) {
 self->time+=context_80165254()->time;
 CxaMessage *message=construct_80131a84(reserve_801613f0(arena_804b1754,236));
 message->kind=4;
 message->setPosition(self->position);
 post_8016239c(message);
 return 0;
}

// Partial observed callback and range layouts; names reflect inferred roles. Snapshot copies isolate traversal from mutation by dispatch.
struct Callback {int unknown;void*receiver;char pad[8];int ready;};
struct Range {Callback **begin,**end;unsigned size()const{return end-begin;}};
extern "C" void* allocate_801fe0b8(unsigned);
extern "C" void copy_802eee50(void*,...);
extern "C" void dispatch_8015fc38(void*,void*,int);
extern "C" void release_801fe160(void*);
extern "C" void f2b_dispatch_snapshot_801623dc(Range*s,void*message){Callback**copy=(Callback**)allocate_801fe0b8(s->size()*4);unsigned size=s->size()*4;Callback**p=copy;Callback**end=(Callback**)((char*)copy+size);copy_802eee50(copy,s->begin,size);while(p!=end){if((*p)->ready)dispatch_8015fc38(message,(*p)->receiver,0);++p;}release_801fe160(copy);}

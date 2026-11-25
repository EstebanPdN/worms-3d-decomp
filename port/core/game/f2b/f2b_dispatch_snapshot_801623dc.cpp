#include "w3d_ptr.h"
#line 1 "f2b_dispatch_snapshot_801623dc.cpp"
// Partial observed callback and range layouts; names reflect inferred roles. Snapshot copies isolate traversal from mutation by dispatch.
struct Callback {int unknown;Ptr32<void> receiver;char pad[8];int ready;};
struct Range {Ptr32<Ptr32<Callback>> begin; Ptr32<Ptr32<Callback>> end;unsigned size()const{return end-begin;}};
extern "C" Ptr32<void> allocate_801fe0b8(unsigned);
extern "C" void copy_802eee50(Ptr32<void>,...);
extern "C" void dispatch_8015fc38(Ptr32<void>,Ptr32<void>,int);
extern "C" void release_801fe160(Ptr32<void>);
extern "C" void f2b_dispatch_snapshot_801623dc(Ptr32<Range> s,Ptr32<void> message){Ptr32<Ptr32<Callback>> copy=(Ptr32<Ptr32<Callback>>)allocate_801fe0b8(s->size()*4);unsigned size=s->size()*4;Ptr32<Ptr32<Callback>> p=copy;Ptr32<Ptr32<Callback>> end=(Ptr32<Ptr32<Callback>>)((Ptr32<char>)copy+size);copy_802eee50(copy,w3d::VA(s->begin),size);while(p!=end){if((*p)->ready)dispatch_8015fc38(message,(*p)->receiver,0);++p;}release_801fe160(copy);}



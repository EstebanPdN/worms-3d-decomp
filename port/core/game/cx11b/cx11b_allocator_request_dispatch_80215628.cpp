#include "w3d_ptr.h"
#line 1 "cx11b_allocator_request_dispatch_80215628.cpp"
// Observed global points directly to a three-function operations table, passed as its own context.
struct Allocator {Ptr32<Ptr32<void> (Ptr32<Allocator>, unsigned int)> allocate;Ptr32<Ptr32<void> (Ptr32<Allocator>, Ptr32<void>, unsigned int, int)> resize;Ptr32<int (Ptr32<Allocator>, Ptr32<void>)> release;};extern Ptr32<Allocator> allocator_804aba6c;
extern "C" Ptr32<void> w3d_cx11b_allocator_request_dispatch_80215628(Ptr32<void>,Ptr32<void> pointer,int existing,unsigned int size){if(!existing)return allocator_804aba6c->allocate(allocator_804aba6c,size);else if(!size){int status=allocator_804aba6c->release(allocator_804aba6c,pointer);Ptr32<void> result=0;if(status>=0)result=pointer;return result;}return allocator_804aba6c->resize(allocator_804aba6c,pointer,size,0);}




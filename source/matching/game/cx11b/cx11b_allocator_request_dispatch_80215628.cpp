// Observed global points directly to a three-function operations table, passed as its own context.
struct Allocator {void *(*allocate)(Allocator *,unsigned int);void *(*resize)(Allocator *,void *,unsigned int,int);int (*release)(Allocator *,void *);};extern Allocator *allocator_804aba6c;
extern "C" void *w3d_cx11b_allocator_request_dispatch_80215628(void *,void *pointer,int existing,unsigned int size){if(!existing)return allocator_804aba6c->allocate(allocator_804aba6c,size);else if(!size){int status=allocator_804aba6c->release(allocator_804aba6c,pointer);void *result=0;if(status>=0)result=pointer;return result;}return allocator_804aba6c->resize(allocator_804aba6c,pointer,size,0);}


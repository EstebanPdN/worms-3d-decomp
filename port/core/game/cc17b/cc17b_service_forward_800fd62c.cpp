#include "w3d_ptr.h"
#line 1 "cc17b_service_forward_800fd62c.cpp"
/* Observed singleton service pointer +100, virtual slot +128 and one-word
   stack copy of the incoming name handle. */
struct Cc17bForwardService { Ptr32<Ptr32<int (void)>> vtable; };
struct Cc17bForwardRoot { char pad[100]; Ptr32<Cc17bForwardService> service; };
extern "C" {
extern Ptr32<Cc17bForwardRoot> root_804b1788;
int w3d_cc17b_service_forward_800fd62c(Ptr32<const unsigned int> name,unsigned a,unsigned b,unsigned c) {
 unsigned local=*name;
 Ptr32<Cc17bForwardService> service=root_804b1788->service;
 return ((Ptr32<int (Ptr32<Cc17bForwardService>, Ptr32<unsigned int>, unsigned int, unsigned int, unsigned int)>)service->vtable[32])(service,&local,a,b,c);
}
}



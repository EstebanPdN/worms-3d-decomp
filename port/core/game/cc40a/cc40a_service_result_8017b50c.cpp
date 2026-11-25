#include "w3d_ptr.h"
#line 1 "cc40a_service_result_8017b50c.cpp"
// Partial service interface view inferred from virtual slots. The local retained
// reference survives the result call and is released on both success and failure.
struct cc40a_ResultService;
struct cc40a_ResultVtable {
 Ptr32<void> unknown00[3]; Ptr32<int (Ptr32<cc40a_ResultService>)> retain; Ptr32<int (Ptr32<cc40a_ResultService>)> release;
 Ptr32<void> unknown14; Ptr32<int (Ptr32<cc40a_ResultService>, Ptr32<const void>)> evaluate;
 Ptr32<void> unknown1c[5]; Ptr32<int (Ptr32<cc40a_ResultService>, Ptr32<const void>)> setInput;
 Ptr32<unsigned int (Ptr32<cc40a_ResultService>)> result;
};
struct cc40a_ResultService {Ptr32<cc40a_ResultVtable> vtable;};
struct cc40a_ResultOwner {unsigned char unknown00[120];Ptr32<const void> context;};
extern "C" Ptr32<cc40a_ResultService> cc40a_lookupService_8020b680(Ptr32<const void>);
extern "C" const unsigned char cc40a_serviceKey_804164c0[];
struct cc40a_ResultHandle {
 Ptr32<cc40a_ResultService> pointer;
 template <class W3dU> cc40a_ResultHandle(Ptr32<W3dU> w3d_p) : cc40a_ResultHandle((cc40a_ResultService *)w3d_p.get()) {}
 cc40a_ResultHandle(cc40a_ResultService* p):pointer(p){if(pointer)pointer->vtable->retain(pointer);}
 ~cc40a_ResultHandle(){if(pointer)pointer->vtable->release(pointer);}
};
extern "C" unsigned int cc40a_service_result_8017b50c(Ptr32<cc40a_ResultOwner> self,Ptr32<const void> input){
 cc40a_ResultHandle service(cc40a_lookupService_8020b680(cc40a_serviceKey_804164c0));
 service.pointer->vtable->setInput(service.pointer,input);
 if(service.pointer->vtable->evaluate(service.pointer,self->context)<0)return 0;
 return service.pointer->vtable->result(service.pointer);
}



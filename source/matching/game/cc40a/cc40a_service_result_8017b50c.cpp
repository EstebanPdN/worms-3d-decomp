// Partial service interface view inferred from virtual slots. The local retained
// reference survives the result call and is released on both success and failure.
struct cc40a_ResultService;
struct cc40a_ResultVtable {
 void* unknown00[3]; int (*retain)(cc40a_ResultService*); int (*release)(cc40a_ResultService*);
 void* unknown14; int (*evaluate)(cc40a_ResultService*,const void*);
 void* unknown1c[5]; int (*setInput)(cc40a_ResultService*,const void*);
 unsigned int (*result)(cc40a_ResultService*);
};
struct cc40a_ResultService {cc40a_ResultVtable* vtable;};
struct cc40a_ResultOwner {unsigned char unknown00[120];const void* context;};
extern "C" cc40a_ResultService* cc40a_lookupService_8020b680(const void*);
extern "C" const unsigned char cc40a_serviceKey_804164c0[];
struct cc40a_ResultHandle {
 cc40a_ResultService* pointer;
 cc40a_ResultHandle(cc40a_ResultService* p):pointer(p){if(pointer)pointer->vtable->retain(pointer);}
 ~cc40a_ResultHandle(){if(pointer)pointer->vtable->release(pointer);}
};
extern "C" unsigned int cc40a_service_result_8017b50c(cc40a_ResultOwner* self,const void* input){
 cc40a_ResultHandle service(cc40a_lookupService_8020b680(cc40a_serviceKey_804164c0));
 service.pointer->vtable->setInput(service.pointer,input);
 if(service.pointer->vtable->evaluate(service.pointer,self->context)<0)return 0;
 return service.pointer->vtable->result(service.pointer);
}

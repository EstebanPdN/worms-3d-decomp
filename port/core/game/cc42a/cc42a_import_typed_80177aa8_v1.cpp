#include "w3d_ptr.h"
#line 1 "cc42a_import_typed_80177aa8_v1.cpp"
// Partial inferred runtime interface views; names describe observed operations.
struct cc42a_Type { unsigned char unknown00[20]; Ptr32<const cc42a_Type> parent; };
struct cc42a_Interface;
struct cc42a_Vtable {Ptr32<void> unknown00[3]; Ptr32<int (Ptr32<cc42a_Interface>)> retain; Ptr32<int (Ptr32<cc42a_Interface>)> release; Ptr32<Ptr32<const cc42a_Type> (Ptr32<cc42a_Interface>)> type; Ptr32<void> unknown18[2]; Ptr32<int (Ptr32<cc42a_Interface>, Ptr32<Ptr32<cc42a_Interface>>, int)> query;};
struct cc42a_Interface {Ptr32<cc42a_Vtable> vtable;};
struct cc42a_Hold {
 Ptr32<cc42a_Interface> value;
 cc42a_Hold(const cc42a_Hold& p):value(p.value){if(value)value->vtable->retain(value);}
 template <class W3dU> cc42a_Hold(Ptr32<W3dU> w3d_p) : cc42a_Hold((cc42a_Interface *)w3d_p.get()) {}
 cc42a_Hold(cc42a_Interface* p):value(p){if(value)value->vtable->retain(value);}
 ~cc42a_Hold(){if(value)value->vtable->release(value);}
};
extern "C" const cc42a_Type cc42a_requiredType_80361f08[];
extern "C" int cc42a_insert_80178108(Ptr32<void>,Ptr32<cc42a_Interface>,unsigned char);
inline bool cc42a_hasType(Ptr32<const cc42a_Type> type) {
 while(type!=cc42a_requiredType_80361f08) {if(type==type->parent)return false;type=type->parent;}return true;
}
extern "C" int cc42a_import_typed_80177aa8(Ptr32<void> self,Ptr32<cc42a_Interface> input) {
 cc42a_Hold result(0);
 int status=input->vtable->query(input,&result.value,0);
 if(status<0)return status;
 {
  if(!cc42a_hasType(result.value->vtable->type(result.value)))return (int)0x80004005;
  cc42a_Hold typed(result);
  return cc42a_insert_80178108(self,typed.value,255);
 }
}



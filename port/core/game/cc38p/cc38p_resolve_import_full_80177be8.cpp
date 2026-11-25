#include "w3d_ptr.h"
#line 1 "cc38p_resolve_import_full_80177be8.cpp"
// Full-width group argument witnessed in 80178108; replaces held narrow draft.
// Partial inferred runtime interface views; names describe observed operations.
struct cc38p_Type { unsigned char unknown00[20]; Ptr32<const cc38p_Type> parent; };
struct cc38p_Interface;
struct cc38p_Vtable {Ptr32<void> unknown00[3]; Ptr32<int (Ptr32<cc38p_Interface>)> retain; Ptr32<int (Ptr32<cc38p_Interface>)> release; Ptr32<Ptr32<const cc38p_Type> (Ptr32<cc38p_Interface>)> type; Ptr32<void> unknown18[2]; Ptr32<int (Ptr32<cc38p_Interface>, Ptr32<Ptr32<cc38p_Interface>>, int)> query;};
struct cc38p_Interface {Ptr32<cc38p_Vtable> vtable;};
struct cc38p_Hold {
 Ptr32<cc38p_Interface> value;
 cc38p_Hold(const cc38p_Hold& p):value(p.value){if(value)value->vtable->retain(value);}
 template <class W3dU> cc38p_Hold(Ptr32<W3dU> w3d_p) : cc38p_Hold((cc38p_Interface *)w3d_p.get()) {}
 cc38p_Hold(cc38p_Interface* p):value(p){if(value)value->vtable->retain(value);}
 ~cc38p_Hold(){if(value)value->vtable->release(value);}
};
extern "C" const cc38p_Type cc38p_requiredType_80361f08[];
extern "C" int cc38p_insert_80178108(Ptr32<void>,Ptr32<cc38p_Interface>,unsigned int);
inline bool cc38p_hasType(Ptr32<const cc38p_Type> type) {
 while(type!=cc38p_requiredType_80361f08) {if(type==type->parent)return false;type=type->parent;}return true;
}
extern "C" int cc38p_resolve_8020b6e8(Ptr32<void>,Ptr32<Ptr32<cc38p_Interface>>);
// Fresh hypothesis: early error returns plus nested reference copy lifetime,
// established by the exact neighboring import reconstruction.
extern "C" int cc38p_resolve_import_full_80177be8(Ptr32<void> self,Ptr32<void> input,unsigned int group) {
 cc38p_Hold result(0);
 int status=cc38p_resolve_8020b6e8(input,&result.value);
 if(status<0)return status;
 {
  if(!cc38p_hasType(result.value->vtable->type(result.value)))return (int)0x80004005;
  cc38p_Hold typed(result);
  return cc38p_insert_80178108(self,typed.value,group);
 }
}



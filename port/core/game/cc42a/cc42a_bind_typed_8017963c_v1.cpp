#include "w3d_ptr.h"
#line 1 "cc42a_bind_typed_8017963c_v1.cpp"
// Partial inferred runtime interface views; names describe observed operations.
struct cc42a_Type { unsigned char unknown00[20]; Ptr32<const cc42a_Type> parent; };
struct cc42a_Interface;
struct cc42a_Vtable {Ptr32<void> unknown00[3]; Ptr32<int (Ptr32<cc42a_Interface>)> retain; Ptr32<int (Ptr32<cc42a_Interface>)> release; Ptr32<Ptr32<const cc42a_Type> (Ptr32<cc42a_Interface>)> type;};
struct cc42a_Interface {Ptr32<cc42a_Vtable> vtable;};
struct cc42a_Hold {
 Ptr32<cc42a_Interface> value;
 template <class W3dU> cc42a_Hold(Ptr32<W3dU> w3d_p) : cc42a_Hold((cc42a_Interface *)w3d_p.get()) {}
 cc42a_Hold(cc42a_Interface* p):value(p){if(value)value->vtable->retain(value);}
 ~cc42a_Hold(){if(value)value->vtable->release(value);}
};
struct cc42a_Binding {unsigned char unknown00[28];Ptr32<cc42a_Interface> bound;};
struct cc42a_BindOwner {unsigned char unknown00[4];Ptr32<cc42a_Binding> binding;};
extern "C" Ptr32<cc42a_Interface> cc42a_resolve_8020b680(Ptr32<void>);
extern "C" const cc42a_Type cc42a_requiredType_80365788[];
inline bool cc42a_hasType(Ptr32<const cc42a_Type> type) {
 while(type!=cc42a_requiredType_80365788) {if(type==type->parent)return false;type=type->parent;}return true;
}
inline void cc42a_assign(Ptr32<cc42a_Interface> &slot,Ptr32<cc42a_Interface> value) {
 Ptr32<cc42a_Interface> old=slot;slot=value;
 if(value)value->vtable->retain(value);
 if(old)old->vtable->release(old);
}
extern "C" int cc42a_bind_typed_8017963c(Ptr32<cc42a_BindOwner> self,Ptr32<void> input) {
 cc42a_Hold held(cc42a_resolve_8020b680(input));
 if(!held.value)return (int)0x80004005;
 if(!cc42a_hasType(held.value->vtable->type(held.value)))return (int)0x80004005;
 cc42a_assign(self->binding->bound,held.value);
 return 0;
}



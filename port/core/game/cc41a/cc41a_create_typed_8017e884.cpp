#include "w3d_ptr.h"
#line 1 "cc41a_create_typed_8017e884.cpp"
// Partial inferred interface and type-descriptor views, not complete class layouts.
struct cc41a_Type {unsigned char unknown00[20]; Ptr32<const cc41a_Type> parent;};
struct cc41a_Result;
struct cc41a_ResultVtable {Ptr32<void> unknown00[5]; Ptr32<Ptr32<const cc41a_Type> (Ptr32<cc41a_Result>)> type;};
struct cc41a_Result {Ptr32<cc41a_ResultVtable> vtable;};
struct cc41a_Definition {unsigned char unknown00[20]; unsigned int value;};
struct cc41a_Factory;
struct cc41a_FactoryVtable {Ptr32<void> unknown00[6]; Ptr32<int (Ptr32<cc41a_Factory>, unsigned int)> value; Ptr32<void> unknown1c[5]; Ptr32<int (Ptr32<cc41a_Factory>, unsigned int)> input; Ptr32<Ptr32<cc41a_Result> (Ptr32<cc41a_Factory>)> create;};
struct cc41a_Factory {Ptr32<cc41a_FactoryVtable> vtable;};
struct cc41a_Owner;
struct cc41a_OwnerVtable {Ptr32<void> unknown00[29]; Ptr32<Ptr32<cc41a_Definition> (Ptr32<cc41a_Owner>, Ptr32<const unsigned char>)> lookup;};
struct cc41a_Owner {Ptr32<cc41a_OwnerVtable> vtable;unsigned char unknown04[9812]; Ptr32<cc41a_Factory> factory;};
extern "C" const cc41a_Type cc41a_resultType_80363f64[];
inline bool cc41a_isResult(Ptr32<const cc41a_Type> t){while(t!=cc41a_resultType_80363f64){if(t==t->parent)return false;t=t->parent;}return true;}
extern "C" Ptr32<cc41a_Result> cc41a_create_typed_8017e884(Ptr32<cc41a_Owner> self,unsigned int input,unsigned char group){
 unsigned char key=group;
 unsigned int value=self->vtable->lookup(self,&key)->value;
 self->factory->vtable->input(self->factory,input);
 self->factory->vtable->value(self->factory,value);
 Ptr32<cc41a_Result> result=self->factory->vtable->create(self->factory);
 if(result && cc41a_isResult(result->vtable->type(result)))return result;
 return 0;
}



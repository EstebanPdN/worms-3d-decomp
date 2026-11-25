// Partial inferred interface and type-descriptor views, not complete class layouts.
struct cc41a_Type {unsigned char unknown00[20]; const cc41a_Type* parent;};
struct cc41a_Result;
struct cc41a_ResultVtable {void* unknown00[5]; const cc41a_Type* (*type)(cc41a_Result*);};
struct cc41a_Result {cc41a_ResultVtable* vtable;};
struct cc41a_Definition {unsigned char unknown00[20]; unsigned int value;};
struct cc41a_Factory;
struct cc41a_FactoryVtable {void* unknown00[6]; int (*value)(cc41a_Factory*,unsigned int); void* unknown1c[5]; int (*input)(cc41a_Factory*,unsigned int); cc41a_Result* (*create)(cc41a_Factory*);};
struct cc41a_Factory {cc41a_FactoryVtable* vtable;};
struct cc41a_Owner;
struct cc41a_OwnerVtable {void* unknown00[29]; cc41a_Definition* (*lookup)(cc41a_Owner*,const unsigned char*);};
struct cc41a_Owner {cc41a_OwnerVtable* vtable;unsigned char unknown04[9812]; cc41a_Factory* factory;};
extern "C" const cc41a_Type cc41a_resultType_80363f64[];
inline bool cc41a_isResult(const cc41a_Type* t){while(t!=cc41a_resultType_80363f64){if(t==t->parent)return false;t=t->parent;}return true;}
extern "C" cc41a_Result* cc41a_create_typed_8017e884(cc41a_Owner* self,unsigned int input,unsigned char group){
 unsigned char key=group;
 unsigned int value=self->vtable->lookup(self,&key)->value;
 self->factory->vtable->input(self->factory,input);
 self->factory->vtable->value(self->factory,value);
 cc41a_Result* result=self->factory->vtable->create(self->factory);
 if(result && cc41a_isResult(result->vtable->type(result)))return result;
 return 0;
}

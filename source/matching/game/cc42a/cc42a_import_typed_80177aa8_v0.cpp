// Partial inferred runtime interface views; names describe observed operations.
struct cc42a_Type { unsigned char unknown00[20]; const cc42a_Type* parent; };
struct cc42a_Interface;
struct cc42a_Vtable {void* unknown00[3]; int (*retain)(cc42a_Interface*); int (*release)(cc42a_Interface*); const cc42a_Type* (*type)(cc42a_Interface*); void* unknown18[2]; int (*query)(cc42a_Interface*,cc42a_Interface**,int);};
struct cc42a_Interface {cc42a_Vtable* vtable;};
struct cc42a_Hold {
 cc42a_Interface* value;
 cc42a_Hold(const cc42a_Hold& p):value(p.value){if(value)value->vtable->retain(value);}
 cc42a_Hold(cc42a_Interface* p):value(p){if(value)value->vtable->retain(value);}
 ~cc42a_Hold(){if(value)value->vtable->release(value);}
};
extern "C" const cc42a_Type cc42a_requiredType_80361f08[];
extern "C" int cc42a_insert_80178108(void*,cc42a_Interface*,unsigned char);
inline bool cc42a_hasType(const cc42a_Type* type) {
 while(type!=cc42a_requiredType_80361f08) {if(type==type->parent)return false;type=type->parent;}return true;
}
extern "C" int cc42a_import_typed_80177aa8(void* self,cc42a_Interface* input) {
 cc42a_Hold result(0);
 int status=input->vtable->query(input,&result.value,0);
 if(status>=0) {
  if(!cc42a_hasType(result.value->vtable->type(result.value)))return (int)0x80004005;
  cc42a_Hold typed(result);
  status=cc42a_insert_80178108(self,typed.value,255);
 }
 return status;
}

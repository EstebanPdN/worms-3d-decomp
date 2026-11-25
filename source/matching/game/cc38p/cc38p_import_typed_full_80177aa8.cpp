// Corrected external group prototype. Already-admitted body, zero new coverage.
// Partial inferred runtime interface views; names describe observed operations.
struct cc38p_Type { unsigned char unknown00[20]; const cc38p_Type* parent; };
struct cc38p_Interface;
struct cc38p_Vtable {void* unknown00[3]; int (*retain)(cc38p_Interface*); int (*release)(cc38p_Interface*); const cc38p_Type* (*type)(cc38p_Interface*); void* unknown18[2]; int (*query)(cc38p_Interface*,cc38p_Interface**,int);};
struct cc38p_Interface {cc38p_Vtable* vtable;};
struct cc38p_Hold {
 cc38p_Interface* value;
 cc38p_Hold(const cc38p_Hold& p):value(p.value){if(value)value->vtable->retain(value);}
 cc38p_Hold(cc38p_Interface* p):value(p){if(value)value->vtable->retain(value);}
 ~cc38p_Hold(){if(value)value->vtable->release(value);}
};
extern "C" const cc38p_Type cc38p_requiredType_80361f08[];
extern "C" int cc38p_insert_80178108(void*,cc38p_Interface*,unsigned int);
inline bool cc38p_hasType(const cc38p_Type* type) {
 while(type!=cc38p_requiredType_80361f08) {if(type==type->parent)return false;type=type->parent;}return true;
}
extern "C" int cc38p_import_typed_full_80177aa8(void* self,cc38p_Interface* input) {
 cc38p_Hold result(0);
 int status=input->vtable->query(input,&result.value,0);
 if(status<0)return status;
 {
  if(!cc38p_hasType(result.value->vtable->type(result.value)))return (int)0x80004005;
  cc38p_Hold typed(result);
  return cc38p_insert_80178108(self,typed.value,255);
 }
}

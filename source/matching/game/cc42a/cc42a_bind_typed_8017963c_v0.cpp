// Partial inferred runtime interface views; names describe observed operations.
struct cc42a_Type { unsigned char unknown00[20]; const cc42a_Type* parent; };
struct cc42a_Interface;
struct cc42a_Vtable {void* unknown00[3]; int (*retain)(cc42a_Interface*); int (*release)(cc42a_Interface*); const cc42a_Type* (*type)(cc42a_Interface*);};
struct cc42a_Interface {cc42a_Vtable* vtable;};
struct cc42a_Hold {
 cc42a_Interface* value;
 cc42a_Hold(cc42a_Interface* p):value(p){if(value)value->vtable->retain(value);}
 ~cc42a_Hold(){if(value)value->vtable->release(value);}
};
struct cc42a_Binding {unsigned char unknown00[28];cc42a_Interface* bound;};
struct cc42a_BindOwner {unsigned char unknown00[4];cc42a_Binding* binding;};
extern "C" cc42a_Interface* cc42a_resolve_8020b680(void*);
extern "C" const cc42a_Type cc42a_requiredType_80365788[];
inline bool cc42a_hasType(const cc42a_Type* type) {
 while(type!=cc42a_requiredType_80365788) {if(type==type->parent)return false;type=type->parent;}return true;
}
extern "C" int cc42a_bind_typed_8017963c(cc42a_BindOwner* self,void* input) {
 cc42a_Hold held(cc42a_resolve_8020b680(input));
 if(!held.value)return (int)0x80004005;
 if(!cc42a_hasType(held.value->vtable->type(held.value)))return (int)0x80004005;
 cc42a_Interface* old=self->binding->bound;
 self->binding->bound=held.value;
 if(held.value)held.value->vtable->retain(held.value);
 if(old)old->vtable->release(old);
 return 0;
}

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
inline void cc42a_assign(cc42a_Interface*& slot,cc42a_Interface* value) {
 cc42a_Interface* old=slot;slot=value;
 if(value)value->vtable->retain(value);
 if(old)old->vtable->release(old);
}
struct cc42a_Service;
struct cc42a_ServiceVtable {void* unknown00[6];int (*permits)(cc42a_Service*,cc42a_Interface*);void* unknown1c[5];int (*prepare)(cc42a_Service*,cc42a_Interface*);};
struct cc42a_Service {cc42a_ServiceVtable* vtable;};
extern "C" cc42a_Service* cc42a_service_804b015c;
extern "C" cc42a_Interface* cc42a_fetch_801ea470(cc42a_Interface*);
extern "C" int cc42a_notify_80178b5c(cc42a_BindOwner*);
extern "C" int cc42a_replace_binding_801792a4(cc42a_BindOwner* self,cc42a_Interface** input) {
 cc42a_Hold held(self->binding->bound);
 cc42a_Interface* incoming=*input;
 if(held.value==incoming)return 1;
 cc42a_Binding* binding;
 if(!held.value){binding=self->binding;goto replace;}
 if(!incoming) {
  cc42a_assign(self->binding->bound,0);
 } else {
  cc42a_service_804b015c->vtable->prepare(cc42a_service_804b015c,incoming);
  if(!cc42a_service_804b015c->vtable->permits(cc42a_service_804b015c,held.value))return 1;
  incoming=*input;
  binding=self->binding;
 replace:
  cc42a_assign(binding->bound,cc42a_fetch_801ea470(incoming));
 }
 return cc42a_notify_80178b5c(self);
}

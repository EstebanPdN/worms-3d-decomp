// Inferred interface roles; observed PPC32 virtual slots are preserved.
struct Product;
struct ProductVtable {void *unused[2]; int (*initialize)(Product *,void *,unsigned int *); int (*close)(Product *); int (*release)(Product *);};
struct Product {ProductVtable *vtable;};
struct Factory;
struct FactoryVtable {void *unused[21]; Product *(*create)(Factory *,void *);};
struct Factory {FactoryVtable *vtable;};
extern "C" int w3d_cx10b_service_create_initialize_80211f80(Factory *self,void *key,void *settings,unsigned int *out) {
 Product *product=self->vtable->create(self,key);
 if(product) {
  int status=product->vtable->initialize(product,settings,out);
  if(status>=0) return status;
  product->vtable->close(product);
  product->vtable->release(product);
  return status;
 }
 *out=0;
 return (int)0x80004005;
}


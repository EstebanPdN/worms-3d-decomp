#include "w3d_ptr.h"
#line 1 "cx10b_service_create_initialize_80211f80.cpp"
// Inferred interface roles; observed PPC32 virtual slots are preserved.
struct Product;
struct ProductVtable {Ptr32<void> unused[2]; Ptr32<int (Ptr32<Product>, Ptr32<void>, Ptr32<unsigned int>)> initialize; Ptr32<int (Ptr32<Product>)> close; Ptr32<int (Ptr32<Product>)> release;};
struct Product {Ptr32<ProductVtable> vtable;};
struct Factory;
struct FactoryVtable {Ptr32<void> unused[21]; Ptr32<Ptr32<Product> (Ptr32<Factory>, Ptr32<void>)> create;};
struct Factory {Ptr32<FactoryVtable> vtable;};
extern "C" int w3d_cx10b_service_create_initialize_80211f80(Ptr32<Factory> self,Ptr32<void> key,Ptr32<void> settings,Ptr32<unsigned int> out) {
 Ptr32<Product> product=self->vtable->create(self,key);
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




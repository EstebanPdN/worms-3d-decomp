#include "w3d_ptr.h"
#line 1 "cc21b_converter_sinit_8020eda8.cpp"
// Observed converter type descriptor and callback registration.
// The first registration word remains untouched; callback semantics are inferred.
extern "C" {
extern unsigned int cc21b_descriptor_80463360[];
extern char cc21b_name_803ea280[];
extern char cc21b_vtable_80419598[];
extern char cc21b_vtable_80411ad8[];
struct Cc21bConverterRegistration { unsigned int unknown0; Ptr32<const char> name; Ptr32<void (void)> forward; Ptr32<void (void)> reverse; unsigned int unknown16; Ptr32<void> table; };
extern Cc21bConverterRegistration cc21b_registration_80463390;
extern char cc21b_name_803b32f8[];
extern char cc21b_table_80463308[];
int cc21b_forward_8020ea2c();
int cc21b_reverse_8020ed40();
Ptr32<void> cc21b_insert_80200af8(Ptr32<Cc21bConverterRegistration>);
void cc21b_factory_8020de48();
Ptr32<void> cc21b_descriptor_ctor_8020fbd0(Ptr32<void>,Ptr32<void>,Ptr32<void>,Ptr32<void (void)>,int,int);
void w3d_cc21b_converter_sinit_8020eda8(int init,int priority) {
 if(priority==0xffff && init) {
  Ptr32<unsigned int> p=cc21b_descriptor_80463360;
  cc21b_descriptor_ctor_8020fbd0(p,cc21b_name_803ea280,p,cc21b_factory_8020de48,7,0);
  p[3]=(unsigned int)w3d::H(cc21b_vtable_80419598);
  p[0]=(unsigned int)w3d::H(cc21b_vtable_80411ad8);
  Ptr32<Cc21bConverterRegistration> entry=&cc21b_registration_80463390;
  entry->name=cc21b_name_803b32f8;
  entry->forward=(Ptr32<void (void)>)cc21b_forward_8020ea2c;
  entry->reverse=(Ptr32<void (void)>)cc21b_reverse_8020ed40;
  entry->unknown16=0;
  entry->table=cc21b_table_80463308;
  cc21b_insert_80200af8(entry);
 }
}
}



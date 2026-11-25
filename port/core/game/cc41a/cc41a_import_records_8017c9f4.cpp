#include "w3d_ptr.h"
#line 1 "cc41a_import_records_8017c9f4.cpp"
// Partial inferred views; input records have an observed 24-byte stride.
struct cc41a_Interface;
struct cc41a_InterfaceVtable {Ptr32<void> unknown00[3];Ptr32<int (Ptr32<cc41a_Interface>)> retain;Ptr32<int (Ptr32<cc41a_Interface>)> release;};
struct cc41a_Interface {Ptr32<cc41a_InterfaceVtable> vtable;};
struct cc41a_Local {Ptr32<cc41a_Interface> pointer;template <class W3dU> cc41a_Local(Ptr32<W3dU> w3d_p) : cc41a_Local((cc41a_Interface *)w3d_p.get()) {}
 cc41a_Local(cc41a_Interface* p):pointer(p){if(pointer)pointer->vtable->retain(pointer);}~cc41a_Local(){if(pointer)pointer->vtable->release(pointer);}};
struct cc41a_Record {unsigned int name;unsigned char category,type;unsigned char unknown06[18];};
struct cc41a_Definition {unsigned char unknown00[20];Ptr32<void> value;};
struct cc41a_Owner {unsigned char unknown00[9752];unsigned int count;};
extern "C" const unsigned char cc41a_key_80412110[];
extern "C" Ptr32<cc41a_Definition> cc41a_definitions_80456f14[];
extern "C" unsigned int cc41a_peak_804ab5e8;
extern "C" Ptr32<cc41a_Interface> cc41a_service_8020b680(Ptr32<const void>);
extern "C" int cc41a_copy_80174274(Ptr32<cc41a_Interface>,Ptr32<void>,Ptr32<const cc41a_Record>);
extern "C" int cc41a_insert_8017c464(Ptr32<cc41a_Owner>,Ptr32<cc41a_Interface>);
inline const unsigned int& cc41a_max(const unsigned int& a,const unsigned int& b){return a<b?b:a;}
extern "C" int cc41a_import_records_8017c9f4(Ptr32<cc41a_Owner> self,Ptr32<const cc41a_Record> records,unsigned int count){
 bool failed=false;
 for(unsigned int i=0;i<count;++i){
  Ptr32<const cc41a_Record> current=&records[i];
  cc41a_Local local(cc41a_service_8020b680(cc41a_key_80412110));
  cc41a_copy_80174274(local.pointer,cc41a_definitions_80456f14[current->type]->value,current);
  if(!cc41a_insert_8017c464(self,local.pointer))failed=true;
 }
 cc41a_peak_804ab5e8=cc41a_max(cc41a_peak_804ab5e8,self->count);
 int result=(int)0x80004005u;
 if(!failed)result=0;
 return result;
}



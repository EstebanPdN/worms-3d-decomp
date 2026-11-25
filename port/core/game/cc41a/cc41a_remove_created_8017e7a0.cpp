#include "w3d_ptr.h"
#line 1 "cc41a_remove_created_8017e7a0.cpp"
// Inferred partial views and role names. Callback order and repeated result query are intentional.
// The table search status is deliberately ignored, as in the original. No fallback index is added.
// The observed 801ef380 body removes/releases one indexed interface and has no result value.
struct cc41a_Table;
struct cc41a_Record {unsigned char unknown00[44]; Ptr32<cc41a_Table> table;};
struct cc41a_Definition {unsigned char unknown00[20]; Ptr32<cc41a_Record> record;};
struct cc41a_Factory;
struct cc41a_FactoryVtable {Ptr32<void> unknown00[6]; Ptr32<int (Ptr32<cc41a_Factory>, Ptr32<cc41a_Record>)> record;Ptr32<void> unknown1c[5];Ptr32<int (Ptr32<cc41a_Factory>, unsigned int)> input;Ptr32<Ptr32<void> (Ptr32<cc41a_Factory>)> create;};
struct cc41a_Factory {Ptr32<cc41a_FactoryVtable> vtable;};
struct cc41a_Owner;
struct cc41a_OwnerVtable {Ptr32<void> unknown00[29]; Ptr32<Ptr32<cc41a_Definition> (Ptr32<cc41a_Owner>, Ptr32<const unsigned char>)> lookup;};
struct cc41a_Owner {Ptr32<cc41a_OwnerVtable> vtable;unsigned char unknown04[9812];Ptr32<cc41a_Factory> factory;};
extern "C" int cc41a_find_801ee0e0(Ptr32<cc41a_Table>,Ptr32<void>,Ptr32<unsigned int>);
extern "C" void cc41a_update_801ef380(Ptr32<cc41a_Record>,unsigned int,unsigned int,unsigned int,unsigned int);
extern "C" int cc41a_remove_created_8017e7a0(Ptr32<cc41a_Owner> self,unsigned int input,unsigned char group){
 unsigned char key=group;
 Ptr32<cc41a_Record> record=self->vtable->lookup(self,&key)->record;
 self->factory->vtable->input(self->factory,input);
 self->factory->vtable->record(self->factory,record);
 int status;
 if(self->factory->vtable->create(self->factory)){
  Ptr32<cc41a_Table> table=record->table;
  Ptr32<void> result=self->factory->vtable->create(self->factory);
  unsigned int index;
  cc41a_find_801ee0e0(table,result,&index);
  cc41a_update_801ef380(record,44,3,index,1);
  status=0;
 }else status=(int)0x80004005u;
 return status;
}



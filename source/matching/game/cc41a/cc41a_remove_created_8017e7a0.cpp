// Inferred partial views and role names. Callback order and repeated result query are intentional.
// The table search status is deliberately ignored, as in the original. No fallback index is added.
// The observed 801ef380 body removes/releases one indexed interface and has no result value.
struct cc41a_Table;
struct cc41a_Record {unsigned char unknown00[44]; cc41a_Table* table;};
struct cc41a_Definition {unsigned char unknown00[20]; cc41a_Record* record;};
struct cc41a_Factory;
struct cc41a_FactoryVtable {void* unknown00[6]; int (*record)(cc41a_Factory*,cc41a_Record*);void* unknown1c[5];int (*input)(cc41a_Factory*,unsigned int);void* (*create)(cc41a_Factory*);};
struct cc41a_Factory {cc41a_FactoryVtable* vtable;};
struct cc41a_Owner;
struct cc41a_OwnerVtable {void* unknown00[29]; cc41a_Definition* (*lookup)(cc41a_Owner*,const unsigned char*);};
struct cc41a_Owner {cc41a_OwnerVtable* vtable;unsigned char unknown04[9812];cc41a_Factory* factory;};
extern "C" int cc41a_find_801ee0e0(cc41a_Table*,void*,unsigned int*);
extern "C" void cc41a_update_801ef380(cc41a_Record*,unsigned int,unsigned int,unsigned int,unsigned int);
extern "C" int cc41a_remove_created_8017e7a0(cc41a_Owner* self,unsigned int input,unsigned char group){
 unsigned char key=group;
 cc41a_Record* record=self->vtable->lookup(self,&key)->record;
 self->factory->vtable->input(self->factory,input);
 self->factory->vtable->record(self->factory,record);
 int status;
 if(self->factory->vtable->create(self->factory)){
  cc41a_Table* table=record->table;
  void* result=self->factory->vtable->create(self->factory);
  unsigned int index;
  cc41a_find_801ee0e0(table,result,&index);
  cc41a_update_801ef380(record,44,3,index,1);
  status=0;
 }else status=(int)0x80004005u;
 return status;
}

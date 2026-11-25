// PPC32 field offset halfword +10 and store pointer +16; interfaces retain +12 and release +16.
struct Service;struct Vtable {void *unused[3];int (*retain)(Service *);int (*release)(Service *);};struct Service {Vtable *vtable;};
struct Field {unsigned char opaque[10];unsigned short offset;unsigned int pad;void *store;};
extern "C" unsigned char *acquire_802078b4(void *,void *,unsigned int);
extern "C" void w3d_cx11b_record_interface_assign_8021a2ac(Field *self,void *record,Service *value){unsigned char *data=acquire_802078b4(self->store,record,self->offset+4);unsigned int offset=self->offset;Service **slot=(Service **)(data+offset);if(*slot)(*slot)->vtable->release(*slot);*slot=value;if(value)value->vtable->retain(value);}


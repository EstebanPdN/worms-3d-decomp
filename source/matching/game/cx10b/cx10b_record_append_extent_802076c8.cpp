// Observed PPC32 slots vector: count +0, capacity +4, data +8.
struct Interface;struct Vtable {void *reserved[3];int (*retain)(Interface *);int (*release)(Interface *);void *middle[5];unsigned int (*extent)(Interface *);};
struct Interface {Vtable *vtable;};
struct Slots;
extern "C" void reserve_80210d54(Slots *,unsigned int);
struct Slots {unsigned int count,capacity;Interface **data;
 void append(Interface *value) {
  reserve_80210d54(this,count+1);
  unsigned int offset=count<<2;
  Interface **base=data;
  if(value)value->vtable->retain(value);
  Interface **slot=(Interface **)(offset+(unsigned int)base);
  if(*slot)(*slot)->vtable->release(*slot);
  *slot=value;++count;
 }
};

struct Owner {unsigned char opaque[20];Slots slots;unsigned int total;};
extern "C" void w3d_cx10b_record_append_extent_802076c8(Owner *self,Interface *value){self->slots.append(value);self->total+=value->vtable->extent(value);}


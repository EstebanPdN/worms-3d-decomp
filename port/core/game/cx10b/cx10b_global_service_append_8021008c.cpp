#include "w3d_ptr.h"
#line 1 "cx10b_global_service_append_8021008c.cpp"
// Observed PPC32 slots vector: count +0, capacity +4, data +8.
struct Interface;struct Vtable {Ptr32<void> reserved[3];Ptr32<int (Ptr32<Interface>)> retain;Ptr32<int (Ptr32<Interface>)> release;Ptr32<void> middle[5];Ptr32<unsigned int (Ptr32<Interface>)> extent;};
struct Interface {Ptr32<Vtable> vtable;};
struct Slots;
extern "C" void reserve_80210d54(Ptr32<Slots>,unsigned int);
struct Slots {unsigned int count,capacity;Ptr32<Ptr32<Interface>> data;
 void append(Ptr32<Interface> value) {
  reserve_80210d54(this,count+1);
  unsigned int offset=count<<2;
  Ptr32<Ptr32<Interface>> base=data;
  if(value)value->vtable->retain(value);
  Ptr32<Ptr32<Interface>> slot=(Ptr32<Ptr32<Interface>>)w3d::G((offset+(unsigned int)w3d::H(base)));
  if(*slot)(*slot)->vtable->release(*slot);
  *slot=value;++count;
 }
};

extern Slots global_slots_80463be0[];
extern "C" void w3d_cx10b_global_service_append_8021008c(Ptr32<Interface> value){global_slots_80463be0[0].append(value);}




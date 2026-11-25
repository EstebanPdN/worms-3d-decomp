#include "w3d_ptr.h"
#line 1 "sol35d9_insert_interfaces_801ef200_v2.cpp"
// Inferred GC32 array header and native interface ownership; no local headers.
namespace sol35d9_insert_interfaces_v2 {
struct Interface;
typedef Ptr32<void (Ptr32<Interface>)> VirtualCall;
struct Interface { Ptr32<VirtualCall> vtable; };
struct Header {
 Ptr32<VirtualCall> vtable;
 unsigned short references, tag;
 unsigned unknown8, unknown12, unknown16, capacity, count;
 unsigned short locks, unknown30;
};
extern "C" Ptr32<Ptr32<Interface>> fn_801ef048(Ptr32<Ptr32<Header>>,unsigned,unsigned,unsigned);
inline Ptr32<Ptr32<Header>> field(Ptr32<void> owner,unsigned offset) {
 return reinterpret_cast<Header **>(w3d::R(w3d::sc<char *>(owner)+offset));
}
inline Ptr32<Ptr32<Interface>> lock(Ptr32<void> owner,unsigned offset,unsigned count) {
 Ptr32<Ptr32<Header>> ref=field(owner,offset);
 Ptr32<Header> h=*ref;
 if(h->references==1 && count==h->count) {
  ++h->locks;
  return reinterpret_cast<Interface **>(w3d::R(h+1));
 }
 return fn_801ef048(ref,count,4,2);
}
typedef char HeaderSize[(sizeof(Header)==32)?1:-1];
}
extern "C" void sol35d9_insert_interfaces_801ef200_v2(Ptr32<void> owner,unsigned offset,unsigned unused,
 Ptr32<Ptr32<sol35d9_insert_interfaces_v2::Interface>> input,unsigned index,unsigned count) {
 using namespace sol35d9_insert_interfaces_v2;
 Ptr32<Ptr32<Interface>> data=lock(owner,offset,(*field(owner,offset))->count+count);
 Ptr32<Ptr32<Interface>> limit=data+index+count;
 input+=count;
 Ptr32<Ptr32<Interface>> end=data+(*field(owner,offset))->count;
 Ptr32<Ptr32<Interface>> source=end-count;
 while(end!=limit) *--end=*--source;
 for(;count;) {
  Ptr32<Interface> value=*--input;
  --count;
  *--end=value;
  value->vtable[3](value);
 }
}



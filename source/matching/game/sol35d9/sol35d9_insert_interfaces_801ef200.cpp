// Inferred GC32 array header and native interface ownership; no local headers.
namespace sol35d9_insert_interfaces {
struct Interface;
typedef void (*VirtualCall)(Interface *);
struct Interface { VirtualCall *vtable; };
struct Header {
 VirtualCall *vtable;
 unsigned short references, tag;
 unsigned unknown8, unknown12, unknown16, capacity, count;
 unsigned short locks, unknown30;
};
extern "C" Interface **fn_801ef048(Header **,unsigned,unsigned,unsigned);
inline Interface **lock(Header **ref,unsigned count) {
 Header *h=*ref;
 if(h->references==1 && count==h->count) {
  ++h->locks;
  return reinterpret_cast<Interface **>(h+1);
 }
 return fn_801ef048(ref,count,4,2);
}
typedef char HeaderSize[(sizeof(Header)==32)?1:-1];
}
extern "C" void sol35d9_insert_interfaces_801ef200(void *owner,unsigned offset,unsigned unused,
 sol35d9_insert_interfaces::Interface **input,unsigned index,unsigned count) {
 using namespace sol35d9_insert_interfaces;
 Header **ref=reinterpret_cast<Header **>(static_cast<char *>(owner)+offset);
 Interface **data=lock(ref,(*ref)->count+count);
 Interface **limit=data+index+count;
 input+=count;
 Interface **end=data+(*ref)->count;
 Interface **source=end-count;
 while(end!=limit) *--end=*--source;
 for(;count;--count) {
  Interface *value=*--input;
  *--end=value;
  value->vtable[3](value);
 }
}

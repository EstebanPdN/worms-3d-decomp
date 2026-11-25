// Inferred GC32 array header and native interface ownership; no local headers.
namespace sol35d9_insert_interfaces_v2 {
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
inline Header **field(void *owner,unsigned offset) {
 return reinterpret_cast<Header **>(static_cast<char *>(owner)+offset);
}
inline Interface **lock(void *owner,unsigned offset,unsigned count) {
 Header **ref=field(owner,offset);
 Header *h=*ref;
 if(h->references==1 && count==h->count) {
  ++h->locks;
  return reinterpret_cast<Interface **>(h+1);
 }
 return fn_801ef048(ref,count,4,2);
}
typedef char HeaderSize[(sizeof(Header)==32)?1:-1];
}
extern "C" void sol35d9_insert_interfaces_801ef200_v2(void *owner,unsigned offset,unsigned unused,
 sol35d9_insert_interfaces_v2::Interface **input,unsigned index,unsigned count) {
 using namespace sol35d9_insert_interfaces_v2;
 Interface **data=lock(owner,offset,(*field(owner,offset))->count+count);
 Interface **limit=data+index+count;
 input+=count;
 Interface **end=data+(*field(owner,offset))->count;
 Interface **source=end-count;
 while(end!=limit) *--end=*--source;
 for(;count;) {
  Interface *value=*--input;
  --count;
  *--end=value;
  value->vtable[3](value);
 }
}

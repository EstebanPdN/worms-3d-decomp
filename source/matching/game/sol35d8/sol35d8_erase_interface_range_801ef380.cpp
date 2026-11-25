// Native array-header and interface slots are partial inferred GC32 views.
namespace sol35d8_erase_interface_range {
struct Interface;
typedef void (*VirtualCall)(Interface *);
struct Interface {VirtualCall *vtable;};
struct Header {
 void *vtable;
 unsigned short references,unknown06;
 unsigned unknown08[4];
 unsigned count;
 unsigned short locks,unknown1e;
};
extern "C" void *fn_801ef048(Header **,unsigned,unsigned,unsigned);
inline Header **field(void *owner,unsigned offset) {
 return reinterpret_cast<Header **>(static_cast<char *>(owner)+offset);
}
typedef char HeaderSize[(sizeof(Header)==32)?1:-1];
}
extern "C" void sol35d8_erase_interface_range_801ef380(void *owner,unsigned offset,unsigned kind,unsigned position,unsigned removed) {
 using namespace sol35d8_erase_interface_range;
 if(removed) {
  Header *header=*field(owner,offset);
  if(header->references!=1) {
   fn_801ef048(field(owner,offset),header->count,4,2);
   header=*field(owner,offset);
  }
  unsigned oldcount=header->count;
  Interface **data=reinterpret_cast<Interface **>(header+1);
  header->count=oldcount-removed;
  Interface **source=data+(position+removed);
  Interface **destination=data+position;
  for(;removed;--removed) {
   Interface *entry=*destination++;
   entry->vtable[4](entry);
  }
  destination=data+position;
  for(;source!=data+oldcount;++source) {*destination=*source;++destination;}
 }
}

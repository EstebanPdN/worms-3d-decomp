#include "w3d_ptr.h"
#line 1 "cx9a_service_result_append_8008bffc.cpp"
// Inferred raw byte-storage vector: begin +0, end +4, capacity +8.
extern "C" Ptr32<unsigned char> storage_allocate_80212fd4(unsigned int);
extern "C" void storage_release_802134fc(Ptr32<void>);
extern "C" Ptr32<void> storage_copy_802eee50(Ptr32<void>,Ptr32<const void>,...);
static inline const int &larger(const int &a,const int &b){return a<b?b:a;}
static inline const unsigned int &smaller(const unsigned int &a,const unsigned int &b){return b<a?b:a;}
struct Cx9aStorage {Ptr32<unsigned char> begin; Ptr32<unsigned char> end; Ptr32<unsigned char> capacity;
 void push(const unsigned int &value){
  if(end==capacity){unsigned int used=end-begin;int next=used+1;int grown=used+(used>>1);unsigned int allocated=larger(next,grown)*4;
   Ptr32<unsigned char> fresh=storage_allocate_80212fd4(allocated);
   if(begin){storage_copy_802eee50(fresh,begin,smaller(allocated,used));storage_release_802134fc(begin);}
   begin=fresh;end=fresh+used;capacity=fresh+allocated;
  }
  *(Ptr32<unsigned int>)end=value;end+=4;
 }
};
// PPC32 retained interface: table +0, retain slot +0xc, release slot +0x10.
struct Cx9aInterface;
struct Cx9aInterfaceTable {Ptr32<void> unknown[3];Ptr32<void (Ptr32<Cx9aInterface>)> retain;Ptr32<void (Ptr32<Cx9aInterface>)> release;};
struct Cx9aInterface {Ptr32<Cx9aInterfaceTable> table;unsigned char unknown04[0x18];unsigned int position[3];};
struct Cx9aHeld {Ptr32<Cx9aInterface> value;unsigned int spare;template <class W3dU> Cx9aHeld(Ptr32<W3dU> w3d_p) : Cx9aHeld((Cx9aInterface *)w3d_p.get()) {}
 Cx9aHeld(Cx9aInterface *v):value(v){if(value)value->table->retain(value);}~Cx9aHeld(){if(value)value->table->release(value);}};
extern "C" Ptr32<Cx9aInterface> interface_lookup_8020b680(Ptr32<const void>);
extern "C" unsigned int service_create_80164514(Ptr32<void>,Ptr32<Cx9aInterface>,unsigned int);
extern Ptr32<void> service_804b178c;
// Owner creation argument +0x14, output storage +0x134.
struct Cx9aOwner {unsigned char unknown00[0x14];unsigned int argument;unsigned char unknown18[284];Cx9aStorage storage;};
extern unsigned char interface_key_80410bc8[];
extern "C" void w3d_cx9a_service_result_append_8008bffc(Ptr32<Cx9aOwner> self){Cx9aHeld held(interface_lookup_8020b680(interface_key_80410bc8));self->storage.push(service_create_80164514(service_804b178c,held.value,self->argument));}



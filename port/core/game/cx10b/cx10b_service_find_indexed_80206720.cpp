#include "w3d_ptr.h"
#line 1 "cx10b_service_find_indexed_80206720.cpp"
// Inferred interface names; observed PPC32 vtable byte offsets are explicit.
struct Interface;
struct Vtable { Ptr32<void> unused[3]; Ptr32<int (Ptr32<Interface>)> retain; Ptr32<int (Ptr32<Interface>)> release; };
struct Interface { Ptr32<Vtable> vtable; };

struct KeyVector {Ptr32<unsigned int> begin; Ptr32<unsigned int> end; Ptr32<unsigned int> capacity;};
struct Registry {unsigned char opaque[44]; Ptr32<Ptr32<Interface>> services;KeyVector keys;};
extern "C" Ptr32<unsigned int> find_8035c220(Ptr32<unsigned int>,Ptr32<unsigned int>,Ptr32<const unsigned int>);
extern "C" int w3d_cx10b_service_find_indexed_80206720(Ptr32<Registry> self,unsigned int key,Ptr32<Ptr32<Interface>> out) {
 KeyVector &keys=self->keys;
 Ptr32<unsigned int> p=find_8035c220(keys.begin,keys.end,&key);
 if(p==keys.end) { *out=0;return (int)0x80004005; }
 else {
  unsigned int offset=((unsigned int)w3d::H(p)-(unsigned int)w3d::H(self->keys.begin))&~3u;
  Ptr32<Ptr32<Interface>> slot=(Ptr32<Ptr32<Interface>>)w3d::G((offset+(unsigned int)w3d::H(self->services)));
  Ptr32<Interface> value=*slot;
  *out=value;value->vtable->retain(value);return 0;
 }
}





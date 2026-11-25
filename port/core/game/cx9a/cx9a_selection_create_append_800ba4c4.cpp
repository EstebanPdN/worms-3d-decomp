#include "w3d_ptr.h"
#line 1 "cx9a_selection_create_append_800ba4c4.cpp"
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
// Inferred pool allocation creates a 0x14-byte selection; owner storage +0x34.
struct Cx9aOwner {unsigned char unknown00[0x34];Cx9aStorage storage;};
struct Cx9aPool {unsigned int head;};
extern Cx9aPool selection_pool_804adde4;
extern "C" Ptr32<void> pool_allocate_802098d8(Ptr32<void>,unsigned int);
extern "C" Ptr32<void> selection_construct_800b912c(Ptr32<void>);
extern "C" void selection_initialize_800b923c(Ptr32<void>);
extern "C" Ptr32<void> selection_key_800b4d98(Ptr32<void>);
extern "C" void selection_set_key_800b9240(Ptr32<void>,Ptr32<void>);
extern "C" int w3d_cx9a_selection_create_append_800ba4c4(Ptr32<Cx9aOwner> self,Ptr32<void> key){unsigned int entry=(unsigned int)w3d::H(selection_construct_800b912c(pool_allocate_802098d8(&selection_pool_804adde4,0x14)));selection_initialize_800b923c((Ptr32<void>)w3d::G(entry));selection_set_key_800b9240((Ptr32<void>)w3d::G(entry),selection_key_800b4d98(key));self->storage.push(entry);return 0;}



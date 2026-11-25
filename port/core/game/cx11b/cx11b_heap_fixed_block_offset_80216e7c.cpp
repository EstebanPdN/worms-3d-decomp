#include "w3d_ptr.h"
#line 1 "cx11b_heap_fixed_block_offset_80216e7c.cpp"
// Observed PPC32 heap state +48; region link +4 and end address +16. Integer addresses preserve original unsigned ordering.
struct Region {unsigned int unknown;Ptr32<Region> next;unsigned int words[2];unsigned int end;};
struct Chunk {unsigned int owner,size;};struct Heap {unsigned int flags,unknown,quantum;Ptr32<Region> regions;Ptr32<Chunk> free;};struct Owner {unsigned char opaque[48];Ptr32<Heap> heap;};

extern "C" int w3d_cx11b_heap_fixed_block_offset_80216e7c(Ptr32<Owner> self,unsigned int address){Ptr32<Heap> heap=self->heap;unsigned int flags=heap->flags;unsigned int mode=flags&1;if(!mode){mode=flags&0x4000;heap->flags=flags&~0x4000U;if(!mode){if(flags&0x2000)return -1;heap->flags=(flags&~0x4000U)|0x2000;}}
 int result=-1;for(Ptr32<Region> region=heap->regions;region;region=region->next){unsigned int end=region->end-8;unsigned int begin=(unsigned int)w3d::H(region)+32;if(address>=begin&&address<end){unsigned int stride=(heap->quantum+7)&~7U;Ptr32<Chunk> block=(Ptr32<Chunk>)w3d::G((begin+((address-begin)/stride)*stride));if(block->size==0x55555555){Ptr32<Chunk> free=heap->free;while(free){if(free==block)goto done;free=(Ptr32<Chunk>)w3d::G(free->owner);}}result=address-(unsigned int)w3d::H(block);break;}}
 done:if(!mode)heap->flags&=~0x2000U;return result;}





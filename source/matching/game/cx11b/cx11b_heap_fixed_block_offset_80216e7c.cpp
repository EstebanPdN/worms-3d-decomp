// Observed PPC32 heap state +48; region link +4 and end address +16. Integer addresses preserve original unsigned ordering.
struct Region {unsigned int unknown;Region *next;unsigned int words[2];unsigned int end;};
struct Chunk {unsigned int owner,size;};struct Heap {unsigned int flags,unknown,quantum;Region *regions;Chunk *free;};struct Owner {unsigned char opaque[48];Heap *heap;};

extern "C" int w3d_cx11b_heap_fixed_block_offset_80216e7c(Owner *self,unsigned int address){Heap *heap=self->heap;unsigned int flags=heap->flags;unsigned int mode=flags&1;if(!mode){mode=flags&0x4000;heap->flags=flags&~0x4000U;if(!mode){if(flags&0x2000)return -1;heap->flags=(flags&~0x4000U)|0x2000;}}
 int result=-1;for(Region *region=heap->regions;region;region=region->next){unsigned int end=region->end-8;unsigned int begin=(unsigned int)region+32;if(address>=begin&&address<end){unsigned int stride=(heap->quantum+7)&~7U;Chunk *block=(Chunk *)(begin+((address-begin)/stride)*stride);if(block->size==0x55555555){Chunk *free=heap->free;while(free){if(free==block)goto done;free=(Chunk *)free->owner;}}result=address-(unsigned int)block;break;}}
 done:if(!mode)heap->flags&=~0x2000U;return result;}



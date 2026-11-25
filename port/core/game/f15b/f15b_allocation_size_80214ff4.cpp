#include "w3d_ptr.h"
#line 1 "f15b_allocation_size_80214ff4.cpp"
// Inferred heap state and linked region/block views; all pointer ordering uses the original unsigned address comparisons.
struct F15bRegion{unsigned unknown;Ptr32<F15bRegion> next;unsigned gap[2];Ptr32<char> end;unsigned tail[3];};
struct F15bBlock{unsigned unknown,flags;};struct F15bHeapState{unsigned flags,unknown[2];Ptr32<F15bRegion> head;};struct F15bHeapOwner{char unknown[48];Ptr32<F15bHeapState> state;};
extern "C" unsigned f15b_allocation_size_80214ff4(Ptr32<F15bHeapOwner> self,unsigned address){Ptr32<F15bHeapState> h=self->state;unsigned flags=h->flags;if(flags&1){}else{if(flags&8192)return ~0u;h->flags=flags|8192;}Ptr32<F15bRegion> r=h->head;unsigned result=~0u;while(r){Ptr32<F15bBlock> b=(Ptr32<F15bBlock>)((Ptr32<char>)r+32);Ptr32<char> end=r->end-8;if(address>(unsigned)w3d::H(b)&&address<(unsigned)w3d::H(end)){for(;b<(Ptr32<F15bBlock>)end;b=(Ptr32<F15bBlock>)((Ptr32<char>)b+((b->flags&~7u)+8))){if(address==(unsigned)w3d::H(((Ptr32<char>)b+8))){unsigned v=b->flags;result=v&~7u;if((v&5)!=1)result=~0u;goto done;}if(address<=(unsigned)w3d::H(b))break;}}r=r->next;}done:h->flags=h->flags&~8192u;return result;}



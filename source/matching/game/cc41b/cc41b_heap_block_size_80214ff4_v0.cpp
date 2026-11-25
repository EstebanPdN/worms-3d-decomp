// Original 0x80214ff4. Partial arena/chunk metadata views, names inferred.
// Address ordering is explicitly unsigned as in the original PowerPC comparisons.
struct cc41b_HeapRegion { unsigned unknown0; cc41b_HeapRegion *next; unsigned unknown8[2]; unsigned limit; unsigned unknown14[3]; };
struct cc41b_HeapState { unsigned flags; unsigned unknown[2]; cc41b_HeapRegion *regions; };
struct cc41b_HeapOwner { unsigned char unknown[48]; cc41b_HeapState *state; };
struct cc41b_HeapChunk { unsigned owner,size_flags; };
extern "C" unsigned cc41b_heap_block_size_80214ff4(cc41b_HeapOwner *self,unsigned user) {
 cc41b_HeapState *state=self->state;
 if(!(state->flags&1)) {
  if(state->flags&0x2000)return ~0u;
  state->flags|=0x2000;
 }
 unsigned result=~0u;
 for(cc41b_HeapRegion *region=state->regions;region;region=region->next) {
  unsigned cursor=(unsigned)region+32;
  unsigned end=region->limit-8;
  if(cursor<user && user<end) {
   for(;cursor<end;cursor+=(((cc41b_HeapChunk *)cursor)->size_flags&~7u)+8) {
    if(user==cursor+8) {
     unsigned flags=((cc41b_HeapChunk *)cursor)->size_flags;
     result=flags&~7u;
     if((flags&5)!=1) result=~0u;
     goto done;
    }
    if(user<=cursor)break;
   }
  }
 }
 done:state->flags&=~0x2000u;
 return result;
}

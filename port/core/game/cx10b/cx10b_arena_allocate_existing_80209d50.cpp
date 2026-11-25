#include "w3d_ptr.h"
#line 1 "cx10b_arena_allocate_existing_80209d50.cpp"
// Observed PPC32 block links and byte-pointer fields at offsets zero, eight and twelve.
struct Block {Ptr32<Block> next;unsigned int opaque;Ptr32<unsigned char> end; Ptr32<unsigned char> cursor;};
struct Arena {unsigned int minimum;Ptr32<Block> head;};
extern "C" void grow_80209e08(Ptr32<Arena>,unsigned int);
extern "C" Ptr32<void> w3d_cx10b_arena_allocate_existing_80209d50(Ptr32<Arena> self,unsigned int size) {
 Ptr32<Block> block=self->head;
 while(block) {
  Ptr32<unsigned char> end=block->end;
  Ptr32<unsigned char> cursor=block->cursor;
  if((unsigned int)(end-cursor)>size) {block->cursor=cursor+size;return cursor;}
  block=block->next;
 }
 if(size>self->minimum) grow_80209e08(self,size);
 else grow_80209e08(self,self->minimum);
 block=self->head;
 Ptr32<unsigned char> cursor=block->cursor;
 block->cursor=cursor+size;
 return cursor;
}





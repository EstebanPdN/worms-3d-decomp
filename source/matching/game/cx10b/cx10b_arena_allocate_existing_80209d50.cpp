// Observed PPC32 block links and byte-pointer fields at offsets zero, eight and twelve.
struct Block {Block *next;unsigned int opaque;unsigned char *end,*cursor;};
struct Arena {unsigned int minimum;Block *head;};
extern "C" void grow_80209e08(Arena *,unsigned int);
extern "C" void *w3d_cx10b_arena_allocate_existing_80209d50(Arena *self,unsigned int size) {
 Block *block=self->head;
 while(block) {
  unsigned char *end=block->end;
  unsigned char *cursor=block->cursor;
  if((unsigned int)(end-cursor)>size) {block->cursor=cursor+size;return cursor;}
  block=block->next;
 }
 if(size>self->minimum) grow_80209e08(self,size);
 else grow_80209e08(self,self->minimum);
 block=self->head;
 unsigned char *cursor=block->cursor;
 block->cursor=cursor+size;
 return cursor;
}



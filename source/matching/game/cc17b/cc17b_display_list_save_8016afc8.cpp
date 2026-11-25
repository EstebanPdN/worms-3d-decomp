/* Original display-list byte count at +4 and storage pointer at +12.
   The allocator receives the emitted count in r4; it is not an unused move. */
struct Cc17bDisplayList { unsigned word,size; void *unknown,*bytes; };
extern "C" {
unsigned fn_8030bd80();
extern void *allocator_804b1884;
void *fn_80166fd0(void *,unsigned);
void *fn_802eee50(void *,const void *,unsigned);
void fn_802fa988(void *,unsigned);
void w3d_cc17b_display_list_save_8016afc8(Cc17bDisplayList *self) {
 unsigned capacity=self->size;
 if(!capacity)fn_8030bd80();
 else {
  unsigned size=fn_8030bd80();self->size=size;
  if(size<=capacity) {
   void *destination=fn_80166fd0(allocator_804b1884,size);
   fn_802eee50(destination,self->bytes,self->size);
   unsigned count=self->size;self->bytes=destination;
   fn_802fa988(destination,count);
  }
 }
}
}

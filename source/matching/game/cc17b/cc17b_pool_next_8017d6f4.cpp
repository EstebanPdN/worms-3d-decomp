/* Observed fixed table: six header words and 1920 four-byte entries.
   The index is advanced in the caller's storage; negative indices are unsigned. */
struct Cc17bSlotPool { unsigned header[6]; unsigned slots[1920]; };
extern "C" int w3d_cc17b_pool_next_8017d6f4(Cc17bSlotPool *self,unsigned *index,unsigned *output) {
 for(;*index<1920;++*index) if(((Cc17bSlotPool *)((*index<<2)+(unsigned)self))->slots[0]) break;
 if(*index==1920) return 0;
 else { *output=((Cc17bSlotPool *)((*index<<2)+(unsigned)self))->slots[0]; ++*index; return 1; }
}

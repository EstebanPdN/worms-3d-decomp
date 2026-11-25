// Partial native views for the slot-return path. Full class sizes are unknown.
struct d11a_Resource;
struct d11a_Slot;
struct d11a_SlotTable {
 unsigned unknown[12];
 unsigned char (*kind)(d11a_Slot *);
 unsigned unknown52;
 unsigned short (*index)(d11a_Slot *);
 unsigned char (*group)(d11a_Slot *);
};
struct d11a_Slot { d11a_SlotTable *table; };
struct d11a_Flags { unsigned char unknown[7], value; void mark_available() { value |= 4; } };
struct d11a_Selected { unsigned unknown; d11a_Flags flags; };
inline unsigned d11a_first_bit(unsigned bits) {
 unsigned bit=0;
 while ((bits&1)==0) { bits >>= 1; ++bit; }
 return bit;
}
struct d11a_BitSet {
 unsigned *begin, *end, *capacity;
 unsigned bit_count;
 unsigned first(unsigned *result) {
   for (unsigned i=0; i<(unsigned)(end-begin); ++i) {
     unsigned bits=*(unsigned *)((char *)begin + (i << 2));
     if (bits) {
       *result=i*32+d11a_first_bit(bits);
       if (*result >= bit_count) { *result=(unsigned)-1; return false; }
       return true;
     }
   }
   *result=(unsigned)-1;
   return false;
 }
};
extern unsigned short d11a_free_count_804b18a6;
extern unsigned short *d11a_free_indices_804b18a0;
extern unsigned d11a_kind_counts_804a89d8[];
// Full-word status and pointer results are witnessed in the direct callees.
extern "C" int d11a_release_count_80190458(d11a_Resource *, d11a_Slot *);
extern "C" d11a_BitSet *d11a_bitset_801720c0(d11a_Resource *, unsigned);
extern "C" d11a_Selected *d11a_select_80172088(d11a_Resource *, unsigned);
// Inferred inline counter-table operation: the original keeps its address
// live across the kind callback. It does not introduce an external wrapper.
inline void d11a_decrement_kind(unsigned *counts, d11a_Slot *slot) {
 unsigned kind=slot->table->kind(slot);
 --counts[kind];
}
extern "C" int d11a_release_slot_8017192c(d11a_Resource *self, d11a_Slot *slot)
{
 d11a_release_count_80190458(self,slot);
 d11a_BitSet *bits=d11a_bitset_801720c0(self,slot->table->group(slot));
 unsigned first;
 if (bits->first(&first) != 1)
   d11a_select_80172088(self,slot->table->group(slot))->flags.mark_available();
 d11a_decrement_kind(d11a_kind_counts_804a89d8, slot);
 unsigned index=slot->table->index(slot);
 d11a_free_indices_804b18a0[d11a_free_count_804b18a6++]=index;
 return 0;
}

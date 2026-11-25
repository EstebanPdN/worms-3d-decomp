#include "w3d_ptr.h"
#line 1 "e12b_release_slot_8017192c_v0.cpp"
// Partially observed views of the resource slot table. Only the members the
// recovered body touches are declared; the remaining words are padding.
struct e12b_Resource;
struct e12b_Slot;
struct e12b_SlotTable {
 unsigned unknown[12];
 Ptr32<unsigned char (Ptr32<e12b_Slot>)> kind;
 unsigned unknown52;
 Ptr32<unsigned short (Ptr32<e12b_Slot>)> index;
 Ptr32<unsigned char (Ptr32<e12b_Slot>)> group;
};
struct e12b_Slot { Ptr32<e12b_SlotTable> table; };
struct e12b_Flags { unsigned char unknown[4], value, w3d_tag_rest[3]; void mark_available() { value |= 4; } };
struct e12b_Selected { unsigned unknown; e12b_Flags flags; };
inline unsigned e12b_first_bit(unsigned bits) {
 unsigned bit=0;
 while ((bits&1)==0) { bits >>= 1; ++bit; }
 return bit;
}
// A bitset of slot indices. first() finds the lowest index whose bit is set
// and reports it as a value below bit_count; a set bit past bit_count is
// reported as -1, and an empty set as -1.
struct e12b_BitSet {
 Ptr32<unsigned int> begin; Ptr32<unsigned int> end; Ptr32<unsigned int> capacity;
 unsigned bit_count;
 unsigned first(Ptr32<unsigned int> result) {
   for (unsigned i=0; i<(unsigned)(end-begin); ++i) {
     unsigned bits=*(Ptr32<unsigned int>)((Ptr32<char>)begin + (i << 2));
     if (bits) {
       *result=i*32+e12b_first_bit(bits);
       if (*result >= bit_count) { *result=(unsigned)-1; return false; }
       return true;
     }
   }
   *result=(unsigned)-1;
   return false;
 }
};
extern unsigned short e12b_free_count_804b18a6;
extern Ptr32<unsigned short> e12b_free_indices_804b18a0;
extern unsigned e12b_kind_counts_804a89d8[];
// Full-word status and pointer results are witnessed in the direct callees.
extern "C" int e12b_release_count_80190458(Ptr32<e12b_Resource>, Ptr32<e12b_Slot>);
extern "C" Ptr32<e12b_BitSet> e12b_bitset_801720c0(Ptr32<e12b_Resource>, unsigned);
extern "C" Ptr32<e12b_Selected> e12b_select_80172088(Ptr32<e12b_Resource>, unsigned);
// Inferred inline counter-table operation: the original keeps the table base
// live across the kind callback and scales the returned kind by four.
inline void e12b_decrement_kind(Ptr32<unsigned int> counts, Ptr32<e12b_Slot> slot) {
 unsigned kind=slot->table->kind(slot);
 counts += kind;
 --*counts;
}
// Return one slot to the free list: release the slot's resource handle, mark
// the slot's group available unless a free index already exists, decrement the
// per-kind counter, and push the slot's group index onto the free-index ring.
extern "C" int e12b_release_slot_8017192c(Ptr32<e12b_Resource> self, Ptr32<e12b_Slot> slot)
{
 e12b_release_count_80190458(self,slot);
 Ptr32<e12b_BitSet> bits=e12b_bitset_801720c0(self,slot->table->group(slot));
 unsigned first;
 if (bits->first(&first) != 1)
   e12b_select_80172088(self,slot->table->group(slot))->flags.mark_available();
 e12b_decrement_kind(e12b_kind_counts_804a89d8, slot);
 unsigned index=slot->table->index(slot);
 e12b_free_indices_804b18a0[e12b_free_count_804b18a6++]=index;
 return 0;
}



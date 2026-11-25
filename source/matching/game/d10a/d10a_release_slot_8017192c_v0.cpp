// Partial native views for the slot-return path. Full class sizes are unknown.
struct d10a_Resource;
struct d10a_Slot;
struct d10a_SlotTable {
 unsigned unknown[12];
 unsigned (*kind)(d10a_Slot *);
 unsigned unknown52;
 unsigned (*index)(d10a_Slot *);
 unsigned (*group)(d10a_Slot *);
};
struct d10a_Slot { d10a_SlotTable *table; };
struct d10a_Flags { unsigned char unknown[7], value; void mark_available() { value |= 4; } };
struct d10a_Selected { unsigned unknown; d10a_Flags flags; };
struct d10a_BitSet {
 unsigned *begin, *end, *capacity;
 unsigned bit_count;
 bool first(unsigned *result) {
   for (unsigned i=0; i<(unsigned)(end-begin); ++i) {
     unsigned bits=begin[i];
     if (bits) {
       unsigned bit=0;
       while (!(bits&1)) { bits >>= 1; ++bit; }
       *result=i*32+bit;
       if (*result >= bit_count) { *result=(unsigned)-1; return false; }
       return true;
     }
   }
   *result=(unsigned)-1;
   return false;
 }
};
extern unsigned short d10a_free_count_804b18a6;
extern unsigned short *d10a_free_indices_804b18a0;
extern unsigned d10a_kind_counts_804a89d8[];
// Full-word status and pointer results are witnessed in the direct callees.
extern "C" int d10a_release_count_80190458(d10a_Resource *, d10a_Slot *);
extern "C" d10a_BitSet *d10a_bitset_801720c0(d10a_Resource *, unsigned);
extern "C" d10a_Selected *d10a_select_80172088(d10a_Resource *, unsigned);
extern "C" int d10a_release_slot_8017192c(d10a_Resource *self, d10a_Slot *slot)
{
 d10a_release_count_80190458(self,slot);
 d10a_BitSet *bits=d10a_bitset_801720c0(self,slot->table->group(slot));
 unsigned first;
 if (!bits->first(&first))
   d10a_select_80172088(self,slot->table->group(slot))->flags.mark_available();
 --d10a_kind_counts_804a89d8[slot->table->kind(slot)];
 unsigned index=slot->table->index(slot);
 unsigned count=d10a_free_count_804b18a6;
 d10a_free_count_804b18a6=count+1;
 d10a_free_indices_804b18a0[count]=index;
 return 0;
}

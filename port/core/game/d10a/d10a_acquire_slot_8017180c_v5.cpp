#include "w3d_ptr.h"
#line 1 "d10a_acquire_slot_8017180c_v5.cpp"
// Inferred resource-slot acquisition. Views describe only accessed fields;
// the pool's 136-byte stride is witnessed by the original multiplication.
struct d10a_Resource;
struct d10a_Slot;
struct d10a_SlotTable {
    unsigned unknown0[3];
    Ptr32<unsigned int (Ptr32<d10a_Slot>)> retain;
    Ptr32<unsigned int (Ptr32<d10a_Slot>)> release;
    unsigned unknown20[5];
    Ptr32<int (Ptr32<d10a_Slot>, Ptr32<d10a_Resource>, unsigned int)> bind;
};
struct d10a_Slot { Ptr32<d10a_SlotTable> table; };
struct d10a_Resource { unsigned char unknown[26]; unsigned char default_group, kind; };
struct d10a_Flags { unsigned char unknown[4]; unsigned char value; char w3d_tag_rest[3]; void clear_available() { value &= 251; } };
struct d10a_Selected { unsigned unknown; d10a_Flags flags; };
extern unsigned short d10a_free_count_804b18a6;
extern Ptr32<unsigned short> d10a_free_indices_804b18a0;
extern Ptr32<d10a_Slot> d10a_slots_804b189c;
extern unsigned d10a_kind_counts_804a89d8[];
// Original add_count returns zero; output/group are call-site-observed unused
// parameters. Reference callbacks return full-word counts, confirmed through the pool constructor
// and original vtable targets 80185970/80185990; their results are discarded.
extern "C" int d10a_add_count_80190438(Ptr32<d10a_Resource>, Ptr32<Ptr32<d10a_Slot>>, unsigned);
extern "C" Ptr32<d10a_Selected> d10a_select_80172088(Ptr32<d10a_Resource>, unsigned);
extern "C" int d10a_acquire_slot_8017180c(Ptr32<d10a_Resource> self, Ptr32<Ptr32<d10a_Slot>> out, unsigned group)
{
    unsigned count = d10a_free_count_804b18a6;
    if (count == 0) return (int)0x80004005u;
    if (group == 255) group = self->default_group;
    unsigned next = count - 1;
    unsigned offset = d10a_free_indices_804b18a0[(unsigned short)next] * 136u;
    Ptr32<d10a_Slot> base = d10a_slots_804b189c;
    d10a_free_count_804b18a6 = next;
    Ptr32<d10a_Slot> slot = (Ptr32<d10a_Slot>)w3d::G((offset + (unsigned)w3d::H(base)));
    if (slot) slot->table->retain(slot);
    if (*out) (*out)->table->release(*out);
    *out = slot;
    int result = slot->table->bind(slot, self, group);
    if (result >= 0) {
        ++d10a_kind_counts_804a89d8[self->kind];
        result = d10a_add_count_80190438(self, out, 255);
    }
    Ptr32<d10a_Selected> selected = d10a_select_80172088(self, group);
    selected->flags.clear_available();
    return result;
}



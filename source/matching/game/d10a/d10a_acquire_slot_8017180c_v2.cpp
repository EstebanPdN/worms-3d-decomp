// Inferred resource-slot acquisition. Views describe only accessed fields;
// the pool's 136-byte stride is witnessed by the original multiplication.
struct d10a_Resource;
struct d10a_Slot;
struct d10a_SlotTable {
    unsigned unknown0[3];
    void (*retain)(d10a_Slot *);
    void (*release)(d10a_Slot *);
    unsigned unknown20[5];
    int (*bind)(d10a_Slot *, d10a_Resource *, unsigned);
};
struct d10a_Slot { d10a_SlotTable *table; };
struct d10a_Resource { unsigned char unknown[24]; unsigned char kind, default_group; };
struct d10a_Flags { unsigned char unknown[7]; unsigned char value; void clear(unsigned char mask) { value &= (unsigned char)~mask; } };
struct d10a_Selected { unsigned unknown; d10a_Flags flags; };
extern unsigned short d10a_free_count_804b18a6;
extern unsigned short *d10a_free_indices_804b18a0;
extern d10a_Slot *d10a_slots_804b189c;
extern unsigned d10a_kind_counts_804a89d8[];
// Original add_count returns zero; output/group are call-site-observed unused
// parameters. Reference callback results are discarded, their types remain partial.
extern "C" int d10a_add_count_80190438(d10a_Resource *, d10a_Slot **, unsigned);
extern "C" d10a_Selected *d10a_select_80172088(d10a_Resource *, unsigned);
extern "C" int d10a_acquire_slot_8017180c(d10a_Resource *self, d10a_Slot **out, unsigned group)
{
    unsigned count = d10a_free_count_804b18a6;
    if (count == 0) return (int)0x80004005u;
    if (group == 255) group = self->default_group;
    unsigned next = count - 1;
    unsigned offset = d10a_free_indices_804b18a0[(unsigned short)next] * 136u;
    d10a_Slot *base = d10a_slots_804b189c;
    d10a_free_count_804b18a6 = next;
    d10a_Slot *slot = (d10a_Slot *)(offset + (unsigned)base);
    if (slot) slot->table->retain(slot);
    if (*out) (*out)->table->release(*out);
    *out = slot;
    int result = slot->table->bind(slot, self, group);
    if (result >= 0) {
        ++d10a_kind_counts_804a89d8[self->kind];
        result = d10a_add_count_80190438(self, out, 255);
    }
    d10a_Selected *selected = d10a_select_80172088(self, group);
    selected->flags.clear(4);
    return result;
}

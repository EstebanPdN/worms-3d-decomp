#include "w3d_ptr.h"
#line 1 "d24j_acquire_slot_8017f6ec.cpp"
// Inferred resource-slot acquisition, 204-byte pool (Worms 3D GameCube PAL, 0x8017f6ec).
//
// Same shape as d10a_acquire_slot_8017180c: pops a free index, retains the
// slot, replaces the caller's handle, binds the slot and on success counts the
// kind. Lazily prepares the resource first (0x8017ffbc when state bit 5 is set
// and +48 is empty) and counts every bind attempt at +112.

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
struct d10a_Resource { unsigned char unknown[26]; unsigned char default_group, kind; unsigned char u26[8]; unsigned short state; unsigned char u38[10]; int value48; unsigned char u52[60]; int count112; };
struct d10a_Flags { unsigned char unknown[4]; unsigned char value; char w3d_tag_rest[3]; void clear_available() { value &= 251; } };
struct d10a_Selected { unsigned unknown; d10a_Flags flags; };
extern unsigned short lbl_804ab61c;
extern Ptr32<unsigned short> lbl_804ab618;
extern Ptr32<d10a_Slot> lbl_804ab60c;
extern unsigned d10a_kind_counts_804a89d8[];
extern "C" int d10a_add_count_80190438(Ptr32<d10a_Resource>, Ptr32<Ptr32<d10a_Slot>>, unsigned);
extern "C" int fn_8017ffbc(Ptr32<d10a_Resource>);
extern "C" int d24j_acquire_slot_8017f6ec(Ptr32<d10a_Resource> self, Ptr32<Ptr32<d10a_Slot>> out, unsigned group)
{
    if (lbl_804ab61c == 0) return (int)0x80004005u;
    if (group == 255) group = self->default_group;
    if ((self->state & 32) && self->value48 == 0) fn_8017ffbc(self);
    unsigned short next = --lbl_804ab61c;
    unsigned offset = lbl_804ab618[next] * 204u;
    Ptr32<d10a_Slot> base = lbl_804ab60c;
    Ptr32<d10a_Slot> slot = (Ptr32<d10a_Slot>)w3d::G((offset + (unsigned)w3d::H(base)));
    if (slot) slot->table->retain(slot);
    if (*out) (*out)->table->release(*out);
    *out = slot;
    int result = slot->table->bind(slot, self, group);
    if (result >= 0) {
        ++d10a_kind_counts_804a89d8[self->kind];
        result = d10a_add_count_80190438(self, out, 255);
    }
    self->count112++;
    return result;
}



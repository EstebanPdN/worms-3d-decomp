#include "w3d_ptr.h"
#line 1 "d24j_rename_slot_80178668.cpp"
// Rename a table slot (Worms 3D GameCube PAL, 0x80178668).
//
// Looks up the old name and returns a negative lookup status. Returns
// 0x80004005 unless the slot's retain count probe gives 2 and the new name is
// free. Moves the item to the new slot, releases and clears the old slot, sets
// the new name (virtual slot 11), marks the old slot deleted in the bit set at
// +28, runs the table's follow-up 0x801787ec and returns 0.

struct String { Ptr32<char> data; };
struct Item { Ptr32<Ptr32<void>> vtable;
    int retain() { return ((Ptr32<int (Ptr32<Item>)>)vtable[3])(this); }
    int release() { return ((Ptr32<int (Ptr32<Item>)>)vtable[4])(this); }
    int kind() { return ((Ptr32<int (Ptr32<Item>)>)vtable[6])(this); }
    void set_name(Ptr32<Ptr32<const char> const> n) { ((Ptr32<void (Ptr32<Item>, Ptr32<Ptr32<const char> const>)>)vtable[11])(this, n); }
 Ptr32<const char> name() { return ((Ptr32<Ptr32<const char> (Ptr32<Item>)>)vtable[8])(this); } };
struct Cache { Ptr32<const char> key; unsigned short index; };
struct Table { char u[24]; Ptr32<Ptr32<Item>> entries; Ptr32<unsigned int> deleted; char u32[12]; Cache cache[256]; char pad[24]; unsigned capacity;
    Ptr32<Item> get(unsigned i) { return entries[i]; }
};
extern "C" int fn_80177eb0(Ptr32<Table>, Ptr32<Ptr32<const char> const>, Ptr32<unsigned short>);
extern "C" void fn_801787ec(Ptr32<Table>);
extern "C" int d24j_rename_slot_80178668(Ptr32<Table> self, Ptr32<Ptr32<const char> const> from, Ptr32<Ptr32<const char> const> to)
{
    unsigned short a, b;
    int status = fn_80177eb0(self, from, &a);
    if (status < 0) return status;
    int count = self->entries[a]->retain();
    self->entries[a]->release();
    unsigned slot_a;
    if (count != 2 || fn_80177eb0(self, to, &b) >= 0) return 0x80004005;
    {
        Ptr32<Ptr32<Item>> e = self->entries;
        unsigned oa = (unsigned)a << 2;
        unsigned ob = (unsigned)b << 2;
        Ptr32<Item> p = *(Ptr32<Ptr32<Item>>)w3d::G((oa + (unsigned)w3d::H(e)));
        if (p) p->retain();
        Ptr32<Item> q = *(Ptr32<Ptr32<Item>>)w3d::G((ob + (unsigned)w3d::H(e)));
        if (q) q->release();
        Ptr32<Item> moved = *(Ptr32<Ptr32<Item>>)w3d::G((oa + (unsigned)w3d::H(e)));
        slot_a = a;
        *(Ptr32<Ptr32<Item>>)w3d::G((ob + (unsigned)w3d::H(e))) = moved;
    }
    {
        unsigned oa = slot_a << 2;
        Ptr32<Ptr32<Item>> e = self->entries;
        Ptr32<Item> p = *(Ptr32<Ptr32<Item>>)w3d::G((oa + (unsigned)w3d::H(e)));
        if (p) p->release();
        *(Ptr32<Ptr32<Item>>)w3d::G((oa + (unsigned)w3d::H(e))) = 0;
    }
    self->entries[b]->set_name(to);
    *(Ptr32<unsigned int>)((Ptr32<char>)self->deleted + (a >> 5 << 2)) |= 1 << (a & 31);
    fn_801787ec(self);
    return 0;
}



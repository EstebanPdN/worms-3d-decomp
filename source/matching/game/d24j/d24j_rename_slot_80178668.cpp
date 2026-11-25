// Rename a table slot (Worms 3D GameCube PAL, 0x80178668).
//
// Looks up the old name and returns a negative lookup status. Returns
// 0x80004005 unless the slot's retain count probe gives 2 and the new name is
// free. Moves the item to the new slot, releases and clears the old slot, sets
// the new name (virtual slot 11), marks the old slot deleted in the bit set at
// +28, runs the table's follow-up 0x801787ec and returns 0.

struct String { char *data; };
struct Item { void **vtable;
    int retain() { return ((int (*)(Item *))vtable[3])(this); }
    int release() { return ((int (*)(Item *))vtable[4])(this); }
    int kind() { return ((int (*)(Item *))vtable[6])(this); }
    void set_name(const char *const *n) { ((void (*)(Item *, const char *const *))vtable[11])(this, n); }
 const char *name() { return ((const char *(*)(Item *))vtable[8])(this); } };
struct Cache { const char *key; unsigned short index; };
struct Table { char u[24]; Item **entries; unsigned *deleted; char u32[12]; Cache cache[256]; char pad[24]; unsigned capacity;
    Item *get(unsigned i) { return entries[i]; }
};
extern "C" int fn_80177eb0(Table *, const char *const *, unsigned short *);
extern "C" void fn_801787ec(Table *);
extern "C" int d24j_rename_slot_80178668(Table *self, const char *const *from, const char *const *to)
{
    unsigned short a, b;
    int status = fn_80177eb0(self, from, &a);
    if (status < 0) return status;
    int count = self->entries[a]->retain();
    self->entries[a]->release();
    unsigned slot_a;
    if (count != 2 || fn_80177eb0(self, to, &b) >= 0) return 0x80004005;
    {
        Item **e = self->entries;
        unsigned oa = (unsigned)a << 2;
        unsigned ob = (unsigned)b << 2;
        Item *p = *(Item **)(oa + (unsigned)e);
        if (p) p->retain();
        Item *q = *(Item **)(ob + (unsigned)e);
        if (q) q->release();
        Item *moved = *(Item **)(oa + (unsigned)e);
        slot_a = a;
        *(Item **)(ob + (unsigned)e) = moved;
    }
    {
        unsigned oa = slot_a << 2;
        Item **e = self->entries;
        Item *p = *(Item **)(oa + (unsigned)e);
        if (p) p->release();
        *(Item **)(oa + (unsigned)e) = 0;
    }
    self->entries[b]->set_name(to);
    *(unsigned *)((char *)self->deleted + (a >> 5 << 2)) |= 1 << (a & 31);
    fn_801787ec(self);
    return 0;
}

// Create or update a kind-4 (string) property of a table (Worms 3D GameCube PAL, 0x80175a34).
//
// Looks the name up (0x80177eb0). When it exists and flag 1 allows updating, a
// slot of kind 4 is updated; flag 4 skips the mode handling, flag 8 replaces
// the mode, otherwise a different mode is an error. Any other existing case
// returns 0x80004005. A missing name creates a 20-byte property
// (0x80179038), stores it in the slot with retain/release, sets value, name,
// mode and the flags without 1, 4 and 8, then updates the free count and the
// global created counter.
//
// The two update returns are separate statements in the source: late
// cross-jumping merges them, and the extra references give the value parameter
// its register priority. Built with -fvtable-thunks (real virtual calls).

struct Name;
struct String;

struct Property {
    virtual int query_interface();
    virtual void retain();
    virtual void release();
    virtual void slot_20();
    virtual int kind();
    virtual int wrong_kind();
    virtual void slot_32();
    virtual int mode();
    virtual void slot_40();
    virtual void set_name(const Name *name);
    virtual void set_mode(int mode);
    virtual void set_flags(unsigned flags);
};

// Observed layout: slot array at +24, free-slot count at +2092.
struct Table {
    char pad_00[24];
    Property **slots;
    char pad_1c[2064];
    int free_count;
};

extern "C" int fn_80177eb0(Table *table, const Name *name, unsigned short *index);
extern "C" void *fn_801fe1d8(unsigned size);
extern unsigned var_804ab5b0;
extern "C" Property *fn_80179038(void *memory);
extern "C" Property *fn_80343744(Property *property);
extern "C" int fn_801790bc(Property *property, const String *value);

extern "C" int d25j_set_string_property_80175a34(Table *table, const Name *name, const String *value, int mode, unsigned flags)
{
    unsigned short index;
    if (fn_80177eb0(table, name, &index) >= 0) {
        if (flags & 1) {
            if (table->slots[index]->kind() == 4) {
                if (flags & 4)
                    return fn_801790bc(fn_80343744(table->slots[index]), value);
                if (flags & 8) {
                    table->slots[index]->set_mode(mode);
                } else if (table->slots[index]->mode() != mode) {
                    table->slots[index]->mode();
                    return (int)0x80004005;
                }
                return fn_801790bc(fn_80343744(table->slots[index]), value);
            }
        }
        return (int)0x80004005;
    }
    Property *created = fn_80179038(fn_801fe1d8(20));
    Property **slots = table->slots;
    unsigned offset = (unsigned)index << 2;
    if (created)
        created->retain();
    Property *old = *(Property **)(offset + (int)slots);
    if (old)
        old->release();
    *(Property **)(offset + (int)slots) = created;
    fn_801790bc(created, value);
    created->set_name(name);
    created->set_mode(mode);
    created->set_flags(flags & ~13u);
    table->free_count--;
    var_804ab5b0++;
    return 0;
}

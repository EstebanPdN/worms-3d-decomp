#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10param_802073e8.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10EntryFactory S10EntryFactory;
typedef Ptr32<int (Ptr32<S10EntryFactory>)> S10FactoryMethod;
struct S10EntryFactory {
    Ptr32<S10FactoryMethod> vtable;
    char reserved[16];
    unsigned int flags;
    char reserved24[8];
    unsigned int count;
};
typedef struct S10PoolEntry {
    Ptr32<void> vtable;
    Ptr32<void> name;
    unsigned short flags;
    unsigned short count;
    Ptr32<void> registry;
    Ptr32<S10EntryFactory> owner;
    char reserved[16];
} S10PoolEntry;
extern Ptr32<void> fn_801fe1d8(int);
extern Ptr32<S10PoolEntry> fn_8021a184(Ptr32<void>);
extern char lbl_8045edb8[];
extern int fn_80200074(Ptr32<void>);
extern void fn_802076ac(Ptr32<S10EntryFactory>, int);
extern void fn_8020bd38(Ptr32<void>, Ptr32<const void>);
extern void fn_802076c8(Ptr32<S10EntryFactory>, Ptr32<S10PoolEntry>);

Ptr32<S10PoolEntry> w3d_s10_create_named_entry_802073e8(Ptr32<S10EntryFactory> object, Ptr32<const void> name)
{
    Ptr32<S10PoolEntry> entry;
    unsigned int count, flags;
    if (object->vtable[5](object) != 0)
        return 0;
    entry = fn_8021a184(fn_801fe1d8(36));
    fn_802076ac(object, fn_80200074(lbl_8045edb8));
    count = object->count;
    flags = object->flags;
    entry->owner = object;
    entry->flags = flags;
    entry->registry = lbl_8045edb8;
    fn_8020bd38(&entry->name, name);
    entry->count = count;
    fn_802076c8(object, entry);
    return entry;
}

}

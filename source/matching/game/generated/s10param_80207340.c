/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10EntryFactory S10EntryFactory;
typedef int (*S10FactoryMethod)(S10EntryFactory *);
struct S10EntryFactory {
    S10FactoryMethod *vtable;
    char reserved[16];
    unsigned int flags;
    char reserved24[8];
    unsigned int count;
};
typedef struct S10PoolEntry {
    void *vtable;
    void *name;
    unsigned short flags;
    unsigned short count;
    void *registry;
    S10EntryFactory *owner;
    char reserved[16];
} S10PoolEntry;
extern void *fn_801fe1d8(int);
extern S10PoolEntry *fn_8021a030(void *);
extern char lbl_8045ed4c[];
extern int fn_80200074(void *);
extern void fn_802076ac(S10EntryFactory *, int);
extern void fn_8020bd38(void *, const void *);
extern void fn_802076c8(S10EntryFactory *, S10PoolEntry *);

S10PoolEntry *w3d_s10_create_named_entry_80207340(S10EntryFactory *object, const void *name)
{
    S10PoolEntry *entry;
    unsigned int count, flags;
    if (object->vtable[5](object) != 0)
        return 0;
    entry = fn_8021a030(fn_801fe1d8(36));
    fn_802076ac(object, fn_80200074(lbl_8045ed4c));
    count = object->count;
    flags = object->flags;
    entry->owner = object;
    entry->flags = flags;
    entry->registry = lbl_8045ed4c;
    fn_8020bd38(&entry->name, name);
    entry->count = count;
    fn_802076c8(object, entry);
    return entry;
}

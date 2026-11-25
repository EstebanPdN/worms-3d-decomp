struct K4bIface { void **vtable; };
struct K4bLookup { void **vtable; };
struct K4bScanner {
    char pad0[52];
    unsigned int count;
    char pad38[4];
    struct K4bIface **items;
    char pad40[12];
    struct K4bLookup *lookup;
};
typedef void (*K4bLookupBegin)(struct K4bLookup *);
typedef int (*K4bLookupFind)(struct K4bLookup *, struct K4bIface *);
int w3d_k4b_scanner_has_missing_801b1e48(struct K4bScanner *self)
{
    struct K4bIface **it = self->items;
    struct K4bIface **end = it + self->count;
    ((K4bLookupBegin)self->lookup->vtable[12])(self->lookup);
    for (; it != end; it++) {
        if (((K4bLookupFind)self->lookup->vtable[6])(self->lookup, *it) == 0)
            return 1;
    }
    return 0;
}
// desc: w3d_k4b_scanner_has_missing_801b1e48: Appears to prepare a lookup object, then return one if any item of the list is not found by its sixth-slot query, otherwise zero.

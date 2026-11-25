// desc: Appears to synchronize a four-entry table with a source table: it records a source object when its virtual slot 13 reports one and the slot is empty, and clears the slot otherwise, returning zero.
struct S21Item;
struct S21ItemMethods { void (*reserved[13])(void); int (*active)(struct S21Item *); };
struct S21Item { struct S21ItemMethods *methods; };
struct S21Object { char pad[36]; struct S21Item **sources; char pad1[12]; struct S21Item **slots; };
int w3d_s21_sync_slots_801fb768(struct S21Object *self)
{
    struct S21Item **source = self->sources;
    unsigned i = 0;
    struct S21Item **slot = self->slots;
    struct S21Item *none = 0;
    do {
        if ((*source)->methods->active(*source) == 1) {
            if (*slot == 0)
                *slot = *source;
        } else if (*slot != 0)
            *slot = none;
        i++;
        source++;
        slot++;
    } while (i <= 3);
    return 0;
}

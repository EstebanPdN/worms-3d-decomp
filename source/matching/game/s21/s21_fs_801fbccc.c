// desc: Appears to look up an entry index in the vector at offset 36, fetch the entry's value through virtual slot 11 into the output and return zero, or 0x80004005 when not found.
struct S21Entry;
struct S21EntryMethods { void (*reserved[11])(void); int (*value)(struct S21Entry *); };
struct S21Entry { struct S21EntryMethods *methods; };
struct S21Vector { struct S21Entry **items; };
struct S21Object { char pad[36]; struct S21Entry **items; };
extern int fn_801f9fbc(void *, int, int);
int w3d_s21_get_entry_value_801fbccc(struct S21Object *self, int a, int b, int *out)
{
    int index = fn_801f9fbc((char *)self + 36, a, b);
    struct S21Entry *entry;
    if (index < 0)
        return 0x80004005;
    entry = *(struct S21Entry **)((unsigned)self->items + (index << 2));
    *out = entry->methods->value(entry);
    return 0;
}

// desc: Appears to look up an entry index in the vector at offset 36 and forward one argument to the entry's virtual slot 15, or return 0x80004005 when not found.
struct S21Entry;
struct S21EntryMethods { void (*reserved[15])(void); int (*apply)(struct S21Entry *, int); };
struct S21Entry { struct S21EntryMethods *methods; };
struct S21Object { char pad[36]; struct S21Entry **items; };
extern int fn_801f9fbc(void *, int, int);
int w3d_s21_apply_entry_one_801fbdb0(struct S21Object *self, int a, int b, int c)
{
    int index = fn_801f9fbc((char *)self + 36, a, b);
    struct S21Entry *entry;
    if (index < 0)
        return 0x80004005;
    entry = *(struct S21Entry **)((unsigned)self->items + (index << 2));
    return entry->methods->apply(entry, c);
}

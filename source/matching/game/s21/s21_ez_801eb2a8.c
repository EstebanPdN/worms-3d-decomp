// desc: Appears to look up an entry by name in the null-terminated table returned by a helper, comparing the name with each eight-byte entry's leading string, returning the entry or zero.
// desc: Appears to look up an entry by name in the null-terminated table returned by a helper, comparing the name with each eight-byte entry's leading string, returning the entry or zero.
struct S21Entry { const char *name; int value; };
extern struct S21Entry *fn_801eb29c(void *);
extern int fn_802ef234(const char *, const char *);
struct S21Entry *w3d_s21_find_entry_801eb2a8(void *self, const char *name)
{
    struct S21Entry *entry = fn_801eb29c(self);
    if (entry == 0)
        return 0;
    for (; entry->name != 0; entry++) {
        if (fn_802ef234(name, entry->name) == 0)
            return entry;
    }
    return 0;
}

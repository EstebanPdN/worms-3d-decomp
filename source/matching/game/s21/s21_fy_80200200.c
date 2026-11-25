// desc: Appears to look up an entry by name in the table at offset 4: entries are eight bytes, the lookup skips ones without a second field and returns the entry whose second field equals the name.
struct S21Entry { const char *id; const char *name; };
struct S21Table { char pad[4]; struct S21Entry *entries; };
extern int fn_802ef234(const char *, const char *);
struct S21Entry *w3d_s21_find_by_name_80200200(struct S21Table *table, const char *name)
{
    struct S21Entry *entry = table->entries;
    if (entry == 0)
        return 0;
    for (; entry->id != 0; entry++) {
        if (entry->name != 0 && fn_802ef234(name, entry->name) == 0)
            return entry;
    }
    return 0;
}

// desc: Appears to find an entry by name in the object's array of 64-byte records, comparing the name with the record's leading text, and return the record or zero.
struct S21Record { char name[64]; };
struct S21Table { char pad[32]; int count; struct S21Record *records; };
extern int fn_802ef074(const char *, const char *);
struct S21Record *w3d_s21_find_by_name_801f8d6c(struct S21Table *table, const char *name)
{
    int i = 0;
    struct S21Record *record = table->records;
    for (; i < table->count; i++, record++) {
        if (fn_802ef074(name, record->name) == 0)
            return record;
    }
    return 0;
}

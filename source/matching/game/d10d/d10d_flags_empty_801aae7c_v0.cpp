// Flag-table emptiness test (0x801aae7c). The first argument is unused.
// If the owner record (+100) has a zero count at +24 the result is 1; a
// table (+96) whose length at +24 is zero gives 0; otherwise the result is 1
// only when every byte of the table's flags (+32) is zero.
// Partial observed views; full types and sizeof are unknown.
struct d10d_FlagOwner { unsigned char unknown00[24]; unsigned int count; };
struct d10d_FlagTable { unsigned char unknown00[24]; unsigned int length; unsigned char unknown1c[4]; unsigned char flags[1]; };
struct d10d_FlagQuery { unsigned char unknown00[96]; d10d_FlagTable *table; d10d_FlagOwner *owner; };

extern "C" int d10d_a(void *unused, d10d_FlagQuery *query) {
    d10d_FlagTable *table = query->table;
    if (query->owner->count == 0) return 1;
    unsigned int length = table->length;
    if (length == 0) return 0;
    unsigned int set = 0;
    for (unsigned int i = 0; i < length; i++)
        if (table->flags[i]) set++;
    return set == 0;
}

extern "C" int d10d_b(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    unsigned char *flags = table->flags;
    unsigned int length = table->length;
    if (owner->count == 0) return 1;
    if (length == 0) return 0;
    unsigned int set = 0;
    for (unsigned int i = 0; i < length; i++)
        if (flags[i] != 0) set++;
    return set == 0;
}

extern "C" bool d10d_c(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    unsigned char *flags = table->flags;
    unsigned int length = table->length;
    if (owner->count == 0) return true;
    if (length == 0) return false;
    unsigned int set = 0;
    for (unsigned int i = 0; i < length; i++)
        if (flags[i] != 0) set++;
    return set == 0;
}

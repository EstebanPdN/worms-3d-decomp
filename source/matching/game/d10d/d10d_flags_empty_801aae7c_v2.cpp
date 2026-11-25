// Flag-table emptiness test (0x801aae7c): loop bound re-read from the table
// (loop-invariant motion copies it), trials.
struct d10d_FlagOwner { unsigned char unknown00[24]; unsigned int count; };
struct d10d_FlagTable { unsigned char unknown00[24]; unsigned int length; unsigned char unknown1c[4]; unsigned char flags[1]; };
struct d10d_FlagQuery { unsigned char unknown00[96]; d10d_FlagTable *table; d10d_FlagOwner *owner; };

extern "C" int d10d_h(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    if (owner->count == 0) return 1;
    if (table->length == 0) return 0;
    unsigned int set = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (table->flags[i]) set++;
    return set == 0;
}

extern "C" int d10d_i(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    unsigned char *flags = table->flags;
    unsigned int length = table->length;
    if (owner->count == 0) return 1;
    if (length == 0) return 0;
    unsigned int set = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (flags[i]) set++;
    return set == 0;
}

extern "C" int d10d_j(void *unused, d10d_FlagQuery *query) {
    d10d_FlagTable *table = query->table;
    if (query->owner->count == 0) return 1;
    if (table->length == 0) return 0;
    unsigned int set = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (table->flags[i] != 0) set++;
    return set == 0;
}

extern "C" int d10d_k(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    unsigned char *flags = table->flags;
    if (owner->count == 0) return 1;
    if (table->length == 0) return 0;
    unsigned int set = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (flags[i]) set++;
    return set == 0;
}

// Flag-table emptiness test (0x801aae7c): one counter reused for the owner
// count and the set-flag count, trials.
struct d10d_FlagOwner { unsigned char unknown00[24]; unsigned int count; };
struct d10d_FlagTable { unsigned char unknown00[24]; unsigned int length; unsigned char unknown1c[4]; unsigned char flags[1]; };
struct d10d_FlagQuery { unsigned char unknown00[96]; d10d_FlagTable *table; d10d_FlagOwner *owner; };

extern "C" int d10d_l(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    unsigned char *flags = table->flags;
    unsigned int n = owner->count;
    if (n == 0) return 1;
    if (table->length == 0) return 0;
    n = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (flags[i]) n++;
    return n == 0;
}

extern "C" int d10d_m(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    unsigned char *flags = table->flags;
    unsigned int length = table->length;
    if (owner->count == 0) return 1;
    if (length == 0) return 0;
    unsigned int set = 0;
    for (unsigned int i = 0; i < length; i++)
        if (flags[i]) set++;
    if (table->length) {}
    return set == 0;
}

extern "C" int d10d_n(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    unsigned char *flags = table->flags;
    unsigned int length = table->length;
    unsigned int n = owner->count;
    if (n == 0) return 1;
    if (length == 0) return 0;
    n = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (flags[i]) n++;
    return n == 0;
}

extern "C" int d10d_o(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    unsigned char *flags = table->flags;
    int result = 1;
    if (owner->count != 0) {
        if (table->length == 0) return 0;
        unsigned int set = 0;
        for (unsigned int i = 0; i < table->length; i++)
            if (flags[i]) set++;
        result = set == 0;
    }
    return result;
}

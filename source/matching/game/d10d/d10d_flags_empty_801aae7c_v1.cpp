// Flag-table emptiness test (0x801aae7c), inline counting helper trials.
struct d10d_FlagOwner { unsigned char unknown00[24]; unsigned int count; };
struct d10d_FlagTable { unsigned char unknown00[24]; unsigned int length; unsigned char unknown1c[4]; unsigned char flags[1]; };
struct d10d_FlagQuery { unsigned char unknown00[96]; d10d_FlagTable *table; d10d_FlagOwner *owner; };

static inline unsigned int d10d_count_set(const unsigned char *flags, unsigned int length) {
    unsigned int set = 0;
    for (unsigned int i = 0; i < length; i++)
        if (flags[i]) set++;
    return set;
}

extern "C" int d10d_d(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    unsigned char *flags = table->flags;
    unsigned int length = table->length;
    if (owner->count == 0) return 1;
    if (length == 0) return 0;
    return d10d_count_set(flags, length) == 0;
}

extern "C" int d10d_e(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    if (owner->count == 0) return 1;
    if (table->length == 0) return 0;
    return d10d_count_set(table->flags, table->length) == 0;
}

static inline int d10d_all_clear(const unsigned char *flags, unsigned int length) {
    if (length == 0) return 0;
    unsigned int set = 0;
    for (unsigned int i = 0; i < length; i++)
        if (flags[i]) set++;
    return set == 0;
}

extern "C" int d10d_f(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    if (owner->count == 0) return 1;
    return d10d_all_clear(table->flags, table->length);
}

extern "C" int d10d_g(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    unsigned char *flags = table->flags;
    unsigned int length = table->length;
    if (owner->count == 0) return 1;
    return d10d_all_clear(flags, length);
}

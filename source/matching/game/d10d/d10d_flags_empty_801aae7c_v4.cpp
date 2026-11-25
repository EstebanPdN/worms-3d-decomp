// Flag-table emptiness test (0x801aae7c): declaration-order trials of the
// counter-reuse form (owner count, table length, flag pointer).
struct d10d_FlagOwner { unsigned char unknown00[24]; unsigned int count; };
struct d10d_FlagTable { unsigned char unknown00[24]; unsigned int length; unsigned char unknown1c[4]; unsigned char flags[1]; };
struct d10d_FlagQuery { unsigned char unknown00[96]; d10d_FlagTable *table; d10d_FlagOwner *owner; };

extern "C" int d10d_pfln_ot(void *unused, d10d_FlagQuery *query) {
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

extern "C" int d10d_pfln_to(void *unused, d10d_FlagQuery *query) {
    d10d_FlagTable *table = query->table;
    d10d_FlagOwner *owner = query->owner;
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

extern "C" int d10d_pfnl_ot(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    unsigned char *flags = table->flags;
    unsigned int n = owner->count;
    unsigned int length = table->length;
    if (n == 0) return 1;
    if (length == 0) return 0;
    n = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (flags[i]) n++;
    return n == 0;
}

extern "C" int d10d_pfnl_to(void *unused, d10d_FlagQuery *query) {
    d10d_FlagTable *table = query->table;
    d10d_FlagOwner *owner = query->owner;
    unsigned char *flags = table->flags;
    unsigned int n = owner->count;
    unsigned int length = table->length;
    if (n == 0) return 1;
    if (length == 0) return 0;
    n = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (flags[i]) n++;
    return n == 0;
}

extern "C" int d10d_plfn_ot(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    unsigned int length = table->length;
    unsigned char *flags = table->flags;
    unsigned int n = owner->count;
    if (n == 0) return 1;
    if (length == 0) return 0;
    n = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (flags[i]) n++;
    return n == 0;
}

extern "C" int d10d_plfn_to(void *unused, d10d_FlagQuery *query) {
    d10d_FlagTable *table = query->table;
    d10d_FlagOwner *owner = query->owner;
    unsigned int length = table->length;
    unsigned char *flags = table->flags;
    unsigned int n = owner->count;
    if (n == 0) return 1;
    if (length == 0) return 0;
    n = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (flags[i]) n++;
    return n == 0;
}

extern "C" int d10d_plnf_ot(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    unsigned int length = table->length;
    unsigned int n = owner->count;
    unsigned char *flags = table->flags;
    if (n == 0) return 1;
    if (length == 0) return 0;
    n = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (flags[i]) n++;
    return n == 0;
}

extern "C" int d10d_plnf_to(void *unused, d10d_FlagQuery *query) {
    d10d_FlagTable *table = query->table;
    d10d_FlagOwner *owner = query->owner;
    unsigned int length = table->length;
    unsigned int n = owner->count;
    unsigned char *flags = table->flags;
    if (n == 0) return 1;
    if (length == 0) return 0;
    n = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (flags[i]) n++;
    return n == 0;
}

extern "C" int d10d_pnfl_ot(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    unsigned int n = owner->count;
    unsigned char *flags = table->flags;
    unsigned int length = table->length;
    if (n == 0) return 1;
    if (length == 0) return 0;
    n = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (flags[i]) n++;
    return n == 0;
}

extern "C" int d10d_pnfl_to(void *unused, d10d_FlagQuery *query) {
    d10d_FlagTable *table = query->table;
    d10d_FlagOwner *owner = query->owner;
    unsigned int n = owner->count;
    unsigned char *flags = table->flags;
    unsigned int length = table->length;
    if (n == 0) return 1;
    if (length == 0) return 0;
    n = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (flags[i]) n++;
    return n == 0;
}

extern "C" int d10d_pnlf_ot(void *unused, d10d_FlagQuery *query) {
    d10d_FlagOwner *owner = query->owner;
    d10d_FlagTable *table = query->table;
    unsigned int n = owner->count;
    unsigned int length = table->length;
    unsigned char *flags = table->flags;
    if (n == 0) return 1;
    if (length == 0) return 0;
    n = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (flags[i]) n++;
    return n == 0;
}

extern "C" int d10d_pnlf_to(void *unused, d10d_FlagQuery *query) {
    d10d_FlagTable *table = query->table;
    d10d_FlagOwner *owner = query->owner;
    unsigned int n = owner->count;
    unsigned int length = table->length;
    unsigned char *flags = table->flags;
    if (n == 0) return 1;
    if (length == 0) return 0;
    n = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (flags[i]) n++;
    return n == 0;
}

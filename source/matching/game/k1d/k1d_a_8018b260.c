struct K1dTable { char pad[68]; void *entries; int count; };
extern int bsearch(const void *key, const void *base, int n, int size, int (*cmp)(const void *, const void *));
extern int fn_8018b628(const void *, const void *);
unsigned short w3d_k1d_lookup_entry_8018b260(struct K1dTable *t, unsigned short key)
{
    unsigned short k = key;
    char *r = (char *)bsearch(&k, t->entries, t->count, 6, fn_8018b628);
    if (r) return *(unsigned short *)(r + 4);
    return 0;
}
// k1d: w3d_k1d_lookup_entry_8018b260|0x8018b260|Appears to binary-search a table of six-byte entries by a 16-bit key and return the entry value or zero.

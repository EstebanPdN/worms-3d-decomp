extern void fn_802ef9c0(char *);
unsigned short w3d_s20_hash_name_80177e28(char *self, char *name) {
    unsigned int high;
    unsigned int hash;
    fn_802ef9c0(name);
    hash = 0;
    while (*name != 0) {
        hash = (hash << 4) + *name;
        name++;
        high = hash & 0xf0000000;
        if (high != 0) {
            hash ^= high >> 24;
            hash ^= high;
        }
    }
    return hash % *(unsigned int *)(self + 2116);
}

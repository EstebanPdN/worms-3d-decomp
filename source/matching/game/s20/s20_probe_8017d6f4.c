int w3d_s20_next_slot_8017d6f4(char *self, int *index, int *out) {
    int *table = (int *)(self + 24);
    while ((unsigned int)*index < 1920 && table[*index] == 0)
        ++*index;
    if (*index == 1920)
        return 0;
    *out = table[*index];
    *index += 1;
    return 1;
}

unsigned short w3d_s20_hash_name_8017e1c4(void *self, char *name) {
    unsigned int high = 0;
    unsigned int hash = 0;
    while (*name != 0) {
        hash = (hash << 4) + *name++;
        high = hash & 0xf0000000;
        if (high != 0) {
            hash ^= high >> 24;
            hash ^= high;
        }
    }
    return hash % 1920;
}

/* Alpha-byte classification and an ordered-tree value lookup. */
typedef struct S20Entry { char pad[3]; unsigned char alpha; } S20Entry;
int w3d_s20_classify_item_bytes_801d5844(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    char *record;
    S20Entry *entries;
    unsigned int count;
    unsigned int i;
    int kind;
    if (*(int *)(base + 48) != 0) {
        *(int *)(base + 44) = 1;
        return 0;
    }
    record = *(char **)(item + 20);
    kind = 0;
    count = *(unsigned int *)(record + 24);
    entries = (S20Entry *)(record + 32);
    for (i = 0; i < count; i++) {
        S20Entry *e = &entries[i];
        if (e->alpha != 255) {
            kind = 2;
            if (e->alpha != 0) {
                kind = 1;
                break;
            }
        }
    }
    *(int *)(base + 44) = kind;
    return 0;
}
int w3d_s20_find_value_801a688c(char *self, unsigned int key) {
    unsigned int wanted = key;
    unsigned int *wanted_ref = &wanted;
    char *header = self + 76;
    char *best = *(char **)(header + 4);
    char *node = *(char **)(best + 4);
    char *end;
    while (node != 0) {
        if (*(unsigned int *)(node + 16) >= key) {
            best = node;
            node = *(char **)(node + 8);
        } else {
            node = *(char **)(node + 12);
        }
    }
    end = *(char **)(header + 4);
    if (best == end || *wanted_ref < *(unsigned int *)(best + 16))
        best = end;
    if (best == *(char **)(self + 80))
        return 0;
    return *(int *)(best + 20);
}

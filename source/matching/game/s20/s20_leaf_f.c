/* Fixed-capacity entry stack with 20-byte entries starting at offset 32. */
typedef struct S20Entry { int words[5]; } S20Entry;

void w3d_s20_remove_entry_800f287c(char *self, int index) {
    if (*(int *)(self + 1032) == 0)
        return;
    *(S20Entry *)(self + index * 20 + 32) = *(S20Entry *)(self + *(int *)(self + 1032) * 20 + 12);
    *(int *)(self + 1032) -= 1;
}

/* Loop over a pointer vector with no per-item work. */
int w3d_s20_touch_items_800f6760(char *self, char *vector) {
    unsigned int count = (*(int *)(vector + 20) - *(int *)(vector + 16)) >> 2;
    unsigned int i;
    volatile char pad[32];
    for (i = 0; i < count; i++) {
    }
    return 1;
}

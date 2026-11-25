extern int r27a_entries_80431c80[];
extern "C" int r27a_sum_8008da24() {
    int sum = 0;
    unsigned i = 0;
    do {
        sum += *(int *)((unsigned)r27a_entries_80431c80 + (i << 3));
        i += 2;
    } while (i < 40);
    return sum;
}

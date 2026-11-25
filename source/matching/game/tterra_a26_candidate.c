/* Experimental candidate: relocation-masked differences remain; no linked proof. */
extern int tterra_a26_table_80431c80[];
extern void *tterra_a26_lookup_80164fc8(int);
extern void tterra_a26_flag_80122af8(void *);
int tterra_a26_sum_8008da24(void) {
    int sum = 0, i;
    for (i = 0; i < 20; i++)
        sum += *(int *)((char *)tterra_a26_table_80431c80 + ((i * 2) << 3));
    return sum;
}
static inline void tterra_a26_clear_impl(char *self, int invalid) {
    int value = *(int *)(self + 32);
    if (value != invalid) {
        void *object = tterra_a26_lookup_80164fc8(value);
        if (object) tterra_a26_flag_80122af8(object);
        *(int *)(self + 32) = invalid;
    }
}

void tterra_a26_clear_800cd990(char *self) { tterra_a26_clear_impl(self, -1); }
extern char *tterra_a26_global_804aaabc;
extern int tterra_a26_match_8006e10c(char *);
extern int tterra_a26_test_8006ae58(char *);
int tterra_a26_gate_8006ee18(void) {
    if ((*(unsigned *)(tterra_a26_global_804aaabc + 240) & 0x04000000) == 0) {
        if (tterra_a26_match_8006e10c(tterra_a26_global_804aaabc) == 0) {
            if (*(unsigned *)(tterra_a26_global_804aaabc + 240) & 0x01000000)
                return tterra_a26_test_8006ae58(tterra_a26_global_804aaabc) != 0;
        }
    }
    return 0;
}

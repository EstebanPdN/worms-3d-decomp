/* Triple push and index remap helpers. */
extern void fn_8016e608(char *);
void w3d_s20_push_triple_8016e57c(char *self, int a, int b, int c) {
    char *first;
    char *second;
    char *third;
    int *slot;
    if (*(int *)(self + 556) == 0)
        fn_8016e608(self);
    first = self + 4;
    second = self + 8;
    third = self + 12;
    slot = (int *)(first + *(int *)(self + 552) * 12);
    *slot = a;
    slot = (int *)(second + *(int *)(self + 552) * 12);
    *slot = b;
    slot = (int *)(third + *(int *)(self + 552) * 12);
    *slot = c;
    *(int *)(self + 552) = *(int *)(self + 552) + 1;
}

int w3d_s20_remap_item_indices_801ab98c(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    if (*(int *)(base + 88) != 0) {
        int *slot;
        int *table32 = (int *)(base + 264);
        int *table28 = (int *)(base + 248);
        int *table24 = (int *)(base + 280);
        int *item32 = (int *)(item + 32);
        int *item28 = (int *)(item + 28);
        int *item24 = (int *)(item + 24);
        *item32 = table32[*item32];
        slot = (int *)((char *)table28 + *item28 * 4);
        *item28 = *slot;
        slot = (int *)((char *)table24 + *item24 * 4);
        *item24 = *slot;
    }
    if (*(int *)(base + 112) != 0)
        *(float *)(item + 44) = *(float *)(base + 116);
    return 0;
}


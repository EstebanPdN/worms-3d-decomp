/* near miss: two lwzx operand-order words differ */
int w3d_s20_remap_item_indices_801ab98c(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    if (*(int *)(base + 88) != 0) {
        int *table32 = (int *)(base + 264);
        int *table28 = (int *)(base + 248);
        int *table24 = (int *)(base + 280);
        int *item32 = (int *)(item + 32);
        int *item28 = (int *)(item + 28);
        int *item24 = (int *)(item + 24);
        *item32 = table32[*item32];
        *item28 = table28[*item28];
        *item24 = table24[*item24];
    }
    if (*(int *)(base + 112) != 0)
        *(float *)(item + 44) = *(float *)(base + 116);
    return 0;
}


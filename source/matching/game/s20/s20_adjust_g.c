/* Method on the secondary base subobject (this - 4, null-checked). */
int w3d_s20_remap_item_indices_801ab98c(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    if (*(int *)(base + 88) != 0) {
        char *t32 = base + 264;
        char *t28 = base + 248;
        char *t24 = base + 280;
        int o32 = *(int *)(item + 32) * 4;
        int o28 = *(int *)(item + 28) * 4;
        int o24 = *(int *)(item + 24) * 4;
        *(int *)(item + 32) = *(int *)(t32 + o32);
        *(int *)(item + 28) = *(int *)(t28 + o28);
        *(int *)(item + 24) = *(int *)(t24 + o24);
    }
    if (*(int *)(base + 112) != 0)
        *(float *)(item + 44) = *(float *)(base + 116);
    return 0;
}

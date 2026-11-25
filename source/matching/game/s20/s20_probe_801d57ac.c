/* Method on the secondary base subobject (this - 4, null-checked). */
extern float lbl_803af230[];
extern float lbl_803af22c[];

int w3d_s20_classify_item_values_801d57ac(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    char *record;
    int mode;
    float *values;
    unsigned int i;
    unsigned int count;
    float low;
    float high;
    if (*(int *)(base + 48) != 0) {
        *(int *)(base + 44) = 1;
        return 0;
    }
    record = *(char **)(item + 20);
    mode = 0;
    values = (float *)(record + 44);
    count = *(unsigned int *)(record + 24);
    low = lbl_803af22c[0];
    high = lbl_803af230[0];
    for (i = 0; i < count; i++, values += 4) {
        if (*values != low) {
            mode = 2;
            if (*values != high) {
                mode = 1;
                break;
            }
        }
    }
    *(int *)(base + 44) = mode;
    return 0;
}

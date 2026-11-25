extern float lbl_803a7e2c[];
float w3d_s20_sum_weighted_8018c8bc(char *self) {
    int off = 28;
    char *group = *(char **)(*(char **)(self + 168) + off);
    char *table = group + 32;
    float divisor = *(float *)(*(char **)(*(char **)(group + 32) + off) + 36);
    float sum = lbl_803a7e2c[0];
    unsigned char *p = *(unsigned char **)(self + 180);
    unsigned char *end = *(unsigned char **)(self + 184);
    while (p != end) {
        unsigned short pair = *(unsigned short *)p;
        char *entry = *(char **)(table + (pair >> 8) * 4);
        sum += *(float *)(*(char **)(entry + off) + 32 + p[1] * 8);
        p += 2;
    }
    return sum * *(float *)(self + 36) / divisor;
}

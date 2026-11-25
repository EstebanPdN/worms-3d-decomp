/* Small leaf accessors and predicates. */
extern float lbl_803af62c[];
extern float lbl_803af630[];
extern float lbl_803af634[];
extern float lbl_803af638[];

unsigned char w3d_s20_get_byte_slot_801a9b04(char *self, int index) {
    char *table = self + 304;
    return *(unsigned char *)(table + index);
}

int w3d_s20_set_byte_slot_801a9af4(char *self, int index, int value) {
    char *table = self + 304;
    *(char *)(table + index) = value;
    return 0;
}

int w3d_s20_clear_word_slot_801a314c(char *self, int index) {
    int *table = *(int **)(self + 72);
    int offset = index * 4;
    *(int *)((char *)table + offset) = 0;
    return 0;
}

unsigned char w3d_s20_sum_bytes_80177e04(void *self, unsigned int value) {
    unsigned char a = value, b = value >> 8, c = value >> 16, d = value >> 24;
    return a + b + c + d;
}

unsigned char w3d_s20_sum_bytes_8017e1a0(void *self, unsigned int value) {
    unsigned char a = value, b = value >> 8, c = value >> 16, d = value >> 24;
    return a + b + c + d;
}

int w3d_s20_has_record_key_80199f68(char *self, int key) {
    char *record;
    for (record = *(char **)(self + 32); record != *(char **)(self + 36); record += 24) {
        if (*(unsigned short *)(record + 18) == key)
            return 1;
    }
    return 0;
}

float w3d_s20_evaluate_polynomial_80197244(float *coefficients, int degree, float x) {
    float result = coefficients[degree];
    degree--;
    for (; degree >= 0; degree--)
        result = x * result + coefficients[degree];
    return result;
}

float w3d_s20_select_band_801d69dc(void *self, float x) {
    if (x > lbl_803af62c[0] && x <= lbl_803af630[0])
        return lbl_803af634[0];
    return lbl_803af638[0];
}

int w3d_s20_any_handle_set_8013f844(char *self) {
    if (*(int *)(self + 144) != -1)
        return 1;
    if (*(int *)(self + 140) != -1)
        return 1;
    if (*(int *)(self + 148) != -1)
        return 1;
    return 0;
}

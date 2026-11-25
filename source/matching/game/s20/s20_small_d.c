/* Small helpers: empty loop, handler dispatch, struct copy, forward differences. */
typedef void (*S20Handler2)(char *, char *);
typedef struct S20Block24 { int words[6]; } S20Block24;

int w3d_s20_dispatch_item_801a4a58(char *self, char *item) {
    char *record = *(char **)(item + 20);
    return ((int (*)(char *, char *))(*(void ***)(self + 24))[*(unsigned short *)(record + 6)])(self, record);
}

void w3d_s20_set_block_801c7e34(char *self, S20Block24 *value) {
    *(S20Block24 *)(self + 20) = *value;
}

void w3d_s20_forward_differences_80197208(void *self, float a, float b, float c, float d, float *out_third, float *out_c, float *out_b, float *out_a) {
    d = d - c;
    c = c - b;
    b = b - a;
    d = d - c;
    c = c - b;
    d = d - c;
    *out_third = d;
    *out_c = c + c + c;
    *out_b = b + b + b;
    *out_a = a;
}

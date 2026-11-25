/* Matrix copies, slot scanning and a string hash. */
typedef struct S20Mat4 { float m[12]; } S20Mat4;

int w3d_s20_set_inner_matrix_8017b0b8(char *self, S20Mat4 *value) {
    char *inner = *(char **)(*(char **)(self + 120) + 48);
    *(S20Mat4 *)(inner + 20) = *value;
    {
        char *flags = inner + 4;
        *(unsigned char *)(flags + 7) &= 0xfd;
    }
    return 0;
}

int w3d_s20_get_inner_matrix_8017b5f4(char *self, S20Mat4 *out) {
    char *inner = *(char **)(*(char **)(self + 120) + 48);
    *out = *(S20Mat4 *)(inner + 20);
    return 0;
}


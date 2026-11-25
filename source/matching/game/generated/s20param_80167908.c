/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Struct copies and entry allocation. */
typedef struct S20Mat4 { float m[16]; } S20Mat4;
typedef struct S20Quad { int a; int b; int c; int d; } S20Quad;

S20Mat4 *w3d_s20_get_matrix_80167908(char *self, S20Mat4 *out) {
    *out = *(S20Mat4 *)(self + 112);
    return out;
}

int w3d_s20_set_matrix_801a0890(char *self, S20Mat4 *value) {
    *(S20Mat4 *)(self + 20) = *value;
    return 0;
}

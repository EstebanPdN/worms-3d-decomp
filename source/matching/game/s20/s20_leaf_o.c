/* Small struct copies and a counter stamp. */
typedef struct S20Pair { int first; int second; } S20Pair;
typedef struct S20Quad { int a; int b; int c; int d; } S20Quad;
extern unsigned short lbl_804ab788;

void w3d_s20_stamp_sequence_801afaa4(char *self) {
    unsigned short next = ++lbl_804ab788;
    *(unsigned short *)(self + 56) = next;
    *(int *)(self + 52) = 0;
}

S20Pair *w3d_s20_get_pair_801c83fc(S20Pair *out, char *source) {
    *out = *(S20Pair *)(source + 24);
    return out;
}

void w3d_s20_set_quad_and_flag_801c8488(char *self, S20Quad *value) {
    *(S20Quad *)(self + 72) = *value;
    *(int *)(self + 88) = 1;
}

int w3d_s20_set_quad_801ab934(char *self, S20Quad *value) {
    *(S20Quad *)(self + 96) = *value;
    return 0;
}

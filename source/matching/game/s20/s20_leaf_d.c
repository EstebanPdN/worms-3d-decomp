/* Small leaf predicates and numeric helpers. */
extern float lbl_804a91d8[];
extern float lbl_804b18d0;
extern float lbl_803a84b8[];

int w3d_s20_vector_all_ge_800f5894(float *a, float *b) {
    if (a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2])
        return 1;
    return 0;
}

typedef struct S20Rect { int left; int top; int right; int bottom; } S20Rect;
extern S20Rect lbl_80399f28[];

int w3d_s20_point_in_rect_8010b594(int x, int y, int index) {
    if (x >= lbl_80399f28[index].left && x <= lbl_80399f28[index].right && y >= lbl_80399f28[index].top && y <= lbl_80399f28[index].bottom)
        return 1;
    return 0;
}

int w3d_s20_scan_high_nibbles_801b0b10(unsigned char *bytes, unsigned int count, int groups) {
    while (groups-- != 0) {
        unsigned int i;
        for (i = 0; i < count; i++) {
            int value = *bytes++;
            if (value & 0xf0)
                return 7;
        }
    }
    return 8;
}

float w3d_s20_evaluate_cubic_8019661c(int *self, float x) {
    float t;
    if (*self == 0)
        return lbl_803a84b8[0];
    t = x - lbl_804b18d0;
    return t * (t * (t * lbl_804a91d8[0] + lbl_804a91d8[1]) + lbl_804a91d8[2]) + lbl_804a91d8[3];
}

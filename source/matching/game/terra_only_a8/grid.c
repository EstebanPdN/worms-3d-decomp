typedef unsigned int u32;
extern u32 lbl_80372724[];
extern u32 lbl_804accc0, lbl_804accc4, lbl_804accc8, lbl_804acccc;
int terra_only_a8_grid_8002c73c(u32 *p, u32 x, u32 bit, u32 y, int level) {
    if (x >= p[5] || y >= p[10]) return 0;
    if (level) {
        do {
            u32 width = p[level+5];
            u32 index = p[level];
            lbl_804accc0 = x >> level;
            lbl_804accc8 = bit & lbl_80372724[level];
            lbl_804accc4 = y >> level;
            lbl_804acccc = p[index + lbl_804accc0 + lbl_804accc4 * width] >> lbl_804accc8;
            if (lbl_804acccc & 2) return 1;
            if (!(lbl_804acccc & 1)) return 0;
        } while (--level);
    }
    lbl_804acccc = p[p[0] + x + y * p[5]];
    return (lbl_804acccc & (1u << bit)) != 0;
}

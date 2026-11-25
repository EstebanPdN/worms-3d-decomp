// (Worms 3D GameCube PAL, 0x801d8cd4).
//
// Reads a 32-bit image rectangle from the emulated GS memory buffer
// 0x804b0554 using GS PSMCT32 addressing: for each pixel derives page
// (64x32), block via table 0x803ff1d4, column and word via 0x803ff254, and
// stores one word to the destination.

extern unsigned *lbl_804b0554;
extern int lbl_803ff1d4[];
extern int lbl_803ff254[];
extern "C" void w3d_d25e_read_tex_psmct32_801d8cd4(int dbp, int dbw, int dsax, int dsay, int rrw, int rrh, void *data) {
    unsigned *dst = (unsigned *)data;
    int startBlockPos = dbp * 64;
    for (int y = dsay; y < dsay + rrh; y++) {
        for (int x = dsax; x < dsax + rrw; x++) {
            int pageX = x / 64;
            int pageY = y / 32;
            int page = pageX + pageY * dbw;
            int px = x - (pageX * 64);
            int py = y - (pageY * 32);
            int blockX = px / 8;
            int blockY = py / 8;
            int block = lbl_803ff1d4[blockX + blockY * 8];
            int bx = px - blockX * 8;
            int by = py - blockY * 8;
            int column = by / 2;
            int cx = bx;
            int cy = by - column * 2;
            int cw = lbl_803ff254[cx + cy * 8];
            unsigned *mem = &lbl_804b0554[column * 16 + (block * 64 + (page * 2048 + startBlockPos)) + cw];
            *dst = *mem;
            dst++;
        }
    }
}

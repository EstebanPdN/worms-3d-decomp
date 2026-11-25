// (Worms 3D GameCube PAL, 0x801d8e20).
//
// Writes an 8-bit image rectangle into the emulated GS memory buffer
// 0x804b0554 using GS PSMT8 addressing: for each pixel derives page
// (128x64), block via table 0x803ff414, column, word via 0x803ff494[column &
// 1] and byte via 0x803ff694, and stores one source byte there.

extern unsigned *lbl_804b0554;
extern int lbl_803ff414[];
extern int lbl_803ff494[2][64];
extern int lbl_803ff694[];
extern "C" void w3d_d25e_write_tex_psmt8_801d8e20(int dbp, int dbw, int dsax, int dsay, int rrw, int rrh, void *data) {
    dbw >>= 1;
    unsigned char *src = (unsigned char *)data;
    int startBlockPos = dbp * 64;
    for (int y = dsay; y < dsay + rrh; y++) {
        for (int x = dsax; x < dsax + rrw; x++) {
            int pageX = x / 128;
            int pageY = y / 64;
            int page = pageX + pageY * dbw;
            int px = x - (pageX * 128);
            int py = y - (pageY * 64);
            int blockX = px / 16;
            int blockY = py / 16;
            int block = lbl_803ff414[blockX + blockY * 8];
            int bx = px - blockX * 16;
            int by = py - blockY * 16;
            int column = by / 4;
            int cx = bx;
            int cy = by - column * 4;
            int cw = lbl_803ff494[column & 1][cx + cy * 16];
            int cb = lbl_803ff694[cx + cy * 16];
            unsigned char *dst = (unsigned char *)&lbl_804b0554[((column * 16 + (block * 64 + (page * 2048 + startBlockPos))) + cw)];
            dst[cb] = *src;
            src++;
        }
    }
}

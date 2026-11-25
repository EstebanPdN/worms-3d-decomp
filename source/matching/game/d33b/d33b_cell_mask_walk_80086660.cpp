// GWMP8P rev0 0x80086660. Cell mask walk: copies the 3x3 row masks and the
// four edge masks, packs corner bytes, then for eight columns emits the
// bytes and shifts the masks.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Rows { unsigned m[9]; };
struct Edges { unsigned e[4]; };
struct Cells {
    char unknown00[564];
    int cell;
    Rows source;
    Rows rows;
    Edges edge;
    Edges edgeWork;
};
extern unsigned lbl_804addec, lbl_804addf0, lbl_804addf4, lbl_804addf8;
extern unsigned lbl_804addfc, lbl_804ade00, lbl_804ade04, lbl_804ade08;
extern float kFloatOne[];
extern "C" void w3d_auto_80086514(Cells *, Vec, unsigned char);
extern "C" void w3d_auto_8008659c(Cells *, Vec, unsigned char);
static inline unsigned Corners(const unsigned *p) {
    return (p[0] & 1) << 7 | (p[0] & 2) << 2 | (p[3] & 1) << 6 | (p[3] & 2) << 1
         | (p[1] & 1) << 5 | (p[1] & 2) | (p[4] & 1) << 4 | (p[4] >> 1 & 1);
}
static inline unsigned Next(unsigned old, const unsigned *p) {
    return (old & 15) << 4 | ((p[0] & 2) << 2 | (p[3] & 2) << 1 | (p[1] & 2) | (p[4] >> 1 & 1));
}
extern "C" void d33b_cell_mask_walk_80086660(Cells *self, int cell, Vec *pos, int mode, unsigned char *out, unsigned char tag) {
    self->cell = cell;
    self->rows = self->source;
    self->edgeWork = self->edge;
    lbl_804addec = Corners(&self->rows.m[0]);
    lbl_804addf0 = Corners(&self->rows.m[3]);
    lbl_804addf4 = Corners(&self->rows.m[1]);
    lbl_804addf8 = Corners(&self->rows.m[4]);
    for (unsigned i = 1; i <= 7; i++) {
        lbl_804addfc = lbl_804addec;
        lbl_804ade00 = lbl_804addf0;
        lbl_804ade04 = lbl_804addf4;
        lbl_804ade08 = lbl_804addf8;
        out[9] = lbl_804addf0;
        out[81] = lbl_804addf4;
        out[90] = lbl_804addf8;
        out[0] = lbl_804addec;
        out++;
        self->rows.m[0] >>= 1;
        self->rows.m[1] >>= 1;
        self->rows.m[2] >>= 1;
        self->rows.m[3] >>= 1;
        self->rows.m[4] >>= 1;
        self->rows.m[5] >>= 1;
        self->rows.m[6] >>= 1;
        self->rows.m[7] >>= 1;
        self->rows.m[8] >>= 1;
        lbl_804addec = Next(lbl_804addec, &self->rows.m[0]);
        lbl_804addf0 = Next(lbl_804addf0, &self->rows.m[3]);
        lbl_804addf4 = Next(lbl_804addf4, &self->rows.m[1]);
        lbl_804addf8 = Next(lbl_804addf8, &self->rows.m[4]);
        if (self->rows.m[4] & 1) {
            if (mode == 0) w3d_auto_80086514(self, *pos, tag);
            else w3d_auto_8008659c(self, *pos, tag);
        }
        self->edgeWork.e[0] >>= 1;
        self->edgeWork.e[1] >>= 1;
        self->edgeWork.e[2] >>= 1;
        self->edgeWork.e[3] >>= 1;
        tag -= 4;
        { float k = kFloatOne[0]; pos->y = pos->y + k; }
        self->cell++;
    }
    out[9] = lbl_804addf0;
    out[81] = lbl_804addf4;
    out[90] = lbl_804addf8;
    out[0] = lbl_804addec;
}

/* Terrain row walk (0x80086b08): reads the corner heights of the row from the float grid (bounded by +488,
 * row stride in byte +492) and the height and material samples of the 2-by-3 image neighbourhoods at +8 and
 * +4 (0x8037d0b8 default; each sample bounds-checks x and y, the +4 image doubles it, all shift right by
 * +504), then for 7 cells shifts the windows one column, reads the next column, derives the edge and centre
 * midpoints at +2552..+2568 and draws the cell (0x80086660) with a copy of the position, advancing the output
 * by 18 bytes, the flags by 9, position x by 1.0 and the tag byte. Field names are inferred from the original
 * instructions; layouts are partial views. Owns the literals 0.0, 0.5, 1.0 at 0x8037d0b8. */
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Image {
    unsigned base; char unknown04[16]; unsigned width; char unknown24[16]; unsigned height;
    unsigned Get(unsigned x, unsigned y) const {
        if (x < width && y < height) return ((const unsigned *)this)[base + x + y * width];
        return 0;
    }
    unsigned Get2(unsigned x, unsigned y) const {
        if (x < width && y < height) return ((const unsigned *)this)[base + x + y * width] << 1;
        return 0;
    }
};
struct Terrain {
    char unknown00[4]; Image *low; Image *high; char unknown12[476]; float *end; unsigned char stride; char unknown493[7]; unsigned column; unsigned shift;
    char unknown508[60]; unsigned l568, l572, l576, l580, l584, l588, l592, l596, l600; char unknown604[36]; unsigned h640, h644, h648, h652;
    char unknown656[1880]; float a2536, a2540, a2544, a2548, m2552, m2556, m2560, m2564, m2568;
    unsigned Hi(unsigned x, unsigned y) const { return high->Get(x, y) >> shift; }
    unsigned Lo(unsigned x, unsigned y) const { return low->Get2(x, y) >> shift; }
};
extern "C" void w3d_draw_80086660(Terrain *, short *, Vec *, void *, char *, unsigned char);
extern "C" void w3d_d29b_row_80086b08(Terrain *self, unsigned row, short *out, float *p, Vec *pos, void *ctx, char *flags, unsigned char tag) {
    self->a2540 = p < self->end ? *p : 0.0f;
    self->a2548 = (float *)((self->stride << 2) + (unsigned)p) < self->end ? *(float *)((self->stride << 2) + (unsigned)p) : 0.0f;
    self->h648 = self->Hi(self->column, row);
    self->h652 = self->Hi(self->column, row + 1);
    self->l580 = self->Lo(self->column - 1, row - 1);
    self->l584 = self->Lo(self->column - 1, row);
    self->l588 = self->Lo(self->column - 1, row + 1);
    self->l592 = self->Lo(self->column, row - 1);
    self->l596 = self->Lo(self->column, row);
    self->l600 = self->Lo(self->column, row + 1);
    for (unsigned i = 1; i <= 7; i++) {
        self->l568 = self->l580; self->l572 = self->l584; self->l576 = self->l588;
        self->l580 = self->l592; self->l584 = self->l596; self->l588 = self->l600;
        self->l592 = self->Lo(self->column + i, row - 1);
        self->l596 = self->Lo(self->column + i, row);
        self->l600 = self->Lo(self->column + i, row + 1);
        self->h640 = self->h648; self->h644 = self->h652;
        self->h648 = self->Hi(self->column + i, row);
        self->h652 = self->Hi(self->column + i, row + 1);
        self->a2536 = self->a2540;
        self->a2540 = p + 1 < self->end ? p[1] : 0.0f;
        self->a2544 = self->a2548;
        float *q = p + 1;
        float *r = (float *)((self->stride << 2) + (unsigned)p);
        r = r + 1;
        self->a2548 = r < self->end ? *r : 0.0f;
        self->m2552 = (self->a2536 + self->a2540) * 0.5f;
        self->m2556 = (self->a2536 + self->a2544) * 0.5f;
        self->m2560 = (self->a2548 + self->a2540) * 0.5f;
        self->m2564 = (self->a2544 + self->a2548) * 0.5f;
        self->m2568 = (self->m2552 + self->m2564) * 0.5f;
        Vec t = *pos;
        w3d_draw_80086660(self, out, &t, ctx, flags, tag);
        out += 9; flags += 9;
        pos->x += 1.0f;
        p = q;
        tag++;
    }
}

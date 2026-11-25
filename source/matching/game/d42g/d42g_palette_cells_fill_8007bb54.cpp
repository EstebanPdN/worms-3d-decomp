// GWMP8P rev0 0x8007bb54. Fills the 2916 byte cell map from a tile palette:
// a flat fill when the palette is empty, else the average of all but the
// last value, then paints each tile. Field names inferred; Lt keeps the
// bound in a preheader copy (const reference inline, as in 0x80078f48).
extern "C" void *memset(void *, int, unsigned);
// Tile palette: one byte value and the cell index it paints.
struct Tile { unsigned char value; unsigned char pad; unsigned short index; };
struct Palette { char u0[24]; unsigned count; char u28[4]; Tile tiles[1]; };
struct Source { char u0[76]; Palette *palette; };
struct Self { char u0[696]; unsigned char *cells; int ready; };
inline bool Lt(unsigned a, const unsigned &b) { return a < b; }
extern "C" void d42g_palette_cells_fill_8007bb54(Self *self, Source *src) {
    Palette *p = src->palette;
    unsigned count = p->count;
    Tile *t = p->tiles;
    Tile *tiles = t;
    if (count == 0) {
        memset(self->cells, 150, 2916);
        self->ready = 0;
        return;
    }
    count--;
    unsigned sum = 0;
    unsigned i;
    for (i = 0; i < count; i++) {
        sum += t->value;
        t++;
    }
    self->ready = 1;
    memset(self->cells, (unsigned char)(sum / count), 2916);
    t = tiles;
    for (i = 0; Lt(i, count); i++) {
        self->cells[t->index] = t->value;
        t++;
    }
}

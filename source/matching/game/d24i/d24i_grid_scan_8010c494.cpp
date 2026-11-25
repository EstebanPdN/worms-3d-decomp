// d24i: 0x8010c494 (408 bytes). Scan a 7 by 7 cell grid. For each cell whose edge
// test 0x8010bd74 passes, seek the run-length cursor at +28 to the key
// (layer << 10) + row + (column << 5), read the run's value and draw the cell's
// two triangles (0x8010b318) from the corner heights: stride 72 bytes per row and
// 1296 per column, flag 1 for the first triangle and 0 for the second.
struct d24i_Run {
    unsigned short value;
    unsigned short length;
};
struct d24i_RunCursor {
    d24i_Run *runs;                      // +0
    int index;                           // +4
    int position;                        // +8
    int key;                             // +12
    void seek(int target) {
        int delta = target - key;
        position += delta;
        key += delta;
        if (position < 0) {
            do {
                --index;
                position += runs[index].length;
            } while (position < 0);
        } else {
            while (position >= runs[index].length) {
                position -= runs[index].length;
                ++index;
            }
        }
    }
    unsigned short value() const { return runs[index].value; }
};
struct d24i_Corner { short unknown00; short height; };
struct d24i_GridRenderer {
    unsigned char unknown00[28];
    d24i_RunCursor cursor;               // +28
};
extern "C" int d24i_edge_8010bd74(void *, int, int);
extern "C" void d24i_triangle_8010b318(d24i_GridRenderer *, unsigned, int, int, int, int);

extern "C" void d24i_grid_scan_8010c494(d24i_GridRenderer *self, char *heights, void *grid, int layer) {
    int row = 0;
    int column = 0;
    do {
        int next = column + 1;
        if (d24i_edge_8010bd74(grid, row, column)) {
            int key = row + (layer << 10);
            key += column << 5;
            self->cursor.seek(key);
            unsigned value = self->cursor.value();
            short *corner = (short *)(heights + row * 72 + column * 1296 + 4);
            d24i_triangle_8010b318(self, value, corner[1], corner[37], corner[649], 1);
            d24i_triangle_8010b318(self, value, corner[37], corner[649], corner[685], 0);
        }
        column = next;
        if (column > 6) {
            column = 0;
            ++row;
        }
    } while (row <= 6);
}

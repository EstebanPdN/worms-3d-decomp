// d24i: 0x8010ca34 (408 bytes). Variant of d24i_grid_scan_8010c494: edge test 0x8010bd74,
// triangles 0x8010b318, descending rows, corners (+1370, +74, +1298) with flag 0 then (+74, +1298, +2) with flag 1.
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

extern "C" void d24i_grid_scan_reverse_8010ca34(d24i_GridRenderer *self, char *heights, void *grid, int layer) {
    int row = 6;
    int column = 0;
    do {
        int next = row - 1;
        if (d24i_edge_8010bd74(grid, row, column)) {
            short *corner = (short *)(heights + row * 72 + column * 1296 + 4);
            int key = row + (layer << 10);
            key += column << 5;
            self->cursor.seek(key);
            unsigned value = self->cursor.value();
            d24i_triangle_8010b318(self, value, corner[685], corner[37], corner[649], 0);
            d24i_triangle_8010b318(self, value, corner[37], corner[649], corner[1], 1);
        }
        row = next;
        if (row < 0) {
            row = 6;
            ++column;
        }
    } while (column <= 6);
}

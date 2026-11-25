// d24i: 0x8010c62c (1032 bytes). Two-pass scan of subdivided grid cells walking
// rows downward. Each cell seeks the run-length cursor at +28 and reads its flags
// (grid byte 1 + column * 81 + row * 9). Flag value 16 draws the cell's fan from
// its corners, 17 draws the corner triangles whose neighbour cell type
// (0x8010b560) matches; a corner height of 0xffff is absent. The first pass draws
// the near half and the second the far half.
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
extern "C" int d24i_cell_low_8010b560(const unsigned char *, int, int);
extern "C" void d24i_triangle_8010b318(d24i_GridRenderer *, unsigned, int, int, int, int);

extern "C" void d24i_grid_fans_8010c62c(d24i_GridRenderer *self, char *heights, const unsigned char *grid, int layer) {
    int row = 6;
    int column = 0;
    int pass = 0;
    int none = 0xffff;
    do {
        short *corner = (short *)(heights + row * 72 + column * 1296 + 4);
        int key = row + (layer << 10);
        key += column << 5;
        self->cursor.seek(key);
        unsigned value = self->cursor.value();
        int type = grid[column * 81 + (row * 9 + 1)] & 17;
        if (type == 16) {
            if (pass == 0) {
                unsigned short near = corner[37];
                if (near != none) {
                    d24i_triangle_8010b318(self, value, corner[361], (short)near, corner[343], 0);
                    d24i_triangle_8010b318(self, value, corner[37], corner[343], corner[19], 1);
                } else {
                    d24i_triangle_8010b318(self, value, corner[361], corner[343], corner[19], 1);
                }
                d24i_triangle_8010b318(self, value, corner[343], corner[19], corner[325], 0);
                unsigned short last = corner[1];
                if (last != none)
                    d24i_triangle_8010b318(self, value, corner[19], corner[325], (short)last, 1);
            } else {
                unsigned short far = corner[685];
                if (far != none) {
                    d24i_triangle_8010b318(self, value, corner[361], (short)far, corner[343], 1);
                    d24i_triangle_8010b318(self, value, corner[685], corner[343], corner[667], 0);
                } else {
                    d24i_triangle_8010b318(self, value, corner[361], corner[343], corner[667], 0);
                }
                d24i_triangle_8010b318(self, value, corner[343], corner[667], corner[325], 1);
                unsigned short last = corner[649];
                if (last != none)
                    d24i_triangle_8010b318(self, value, corner[667], corner[325], (short)last, 0);
            }
        } else if (type == 17) {
            if (pass == 0) {
                if ((unsigned short)corner[37] != none && (d24i_cell_low_8010b560(grid + 1, row + 1, column) & 15) == 2)
                    d24i_triangle_8010b318(self, value, corner[361], corner[37], corner[19], 0);
                if ((unsigned short)corner[1] != none && (d24i_cell_low_8010b560(grid + 1, row, column) & 15) == 1)
                    d24i_triangle_8010b318(self, value, corner[19], corner[325], corner[1], 1);
            } else {
                if ((unsigned short)corner[685] != none && (d24i_cell_low_8010b560(grid + 1, row + 1, column + 1) & 15) == 8)
                    d24i_triangle_8010b318(self, value, corner[361], corner[685], corner[667], 1);
                if ((unsigned short)corner[649] != none && (d24i_cell_low_8010b560(grid + 1, row, column + 1) & 15) == 4)
                    d24i_triangle_8010b318(self, value, corner[667], corner[325], corner[649], 0);
            }
        }
        row = row - 1;
        if (row < 0) {
            row = 6;
            if (column++ == 6 && pass == 0) {
                pass = 1;
                column = 0;
            }
        }
    } while (column <= 6 || pass == 0);
}

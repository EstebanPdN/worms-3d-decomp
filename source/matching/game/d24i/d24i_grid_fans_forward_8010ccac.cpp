// d24i: 0x8010ccac (1012 bytes). Forward two-pass variant of
// d24i_grid_fans_alt_8010d230: rows and columns ascend and the fan starts from
// the corners nearest the origin.
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
extern "C" int d24i_cell_high_8010b57c(const unsigned char *, int, int);
extern "C" void d24i_triangle_8010b43c(d24i_GridRenderer *, unsigned, int, int, int, int);

extern "C" void d24i_grid_fans_forward_8010ccac(d24i_GridRenderer *self, char *heights, const unsigned char *grid, int layer) {
    int row = 0;
    int column = 0;
    int pass = 0;
    int none = 0xffff;
    do {
        short *corner = (short *)(heights + row * 72 + column * 1296);
        int key = row + (layer << 10);
        key += column << 5;
        self->cursor.seek(key);
        unsigned value = self->cursor.value();
        int type = grid[row * 9 + column * 81] & 17;
        if (type == 1) {
            if (pass == 0) {
                unsigned short first = corner[1];
                int absent = 0xffff;
                if (first != absent)
                    d24i_triangle_8010b43c(self, value, (short)first, corner[19], corner[325], 0);
                d24i_triangle_8010b43c(self, value, corner[19], corner[325], corner[343], 1);
                unsigned short last = corner[649];
                if (last != absent) {
                    d24i_triangle_8010b43c(self, value, corner[325], corner[343], (short)last, 0);
                    d24i_triangle_8010b43c(self, value, corner[343], corner[649], corner[667], 1);
                } else {
                    d24i_triangle_8010b43c(self, value, corner[325], corner[343], corner[667], 0);
                }
            } else {
                unsigned short first = corner[37];
                int absent = 0xffff;
                if (first != absent)
                    d24i_triangle_8010b43c(self, value, (short)first, corner[19], corner[361], 1);
                d24i_triangle_8010b43c(self, value, corner[19], corner[361], corner[343], 0);
                unsigned short last = corner[685];
                if (last != absent) {
                    d24i_triangle_8010b43c(self, value, corner[361], corner[343], (short)last, 1);
                    d24i_triangle_8010b43c(self, value, corner[343], corner[685], corner[667], 0);
                } else {
                    d24i_triangle_8010b43c(self, value, corner[361], corner[343], corner[667], 1);
                }
            }
        } else if (type == 17) {
            if (pass == 0) {
                if ((unsigned short)corner[1] != none && (d24i_cell_high_8010b57c(grid, row, column) & 240) == 16)
                    d24i_triangle_8010b43c(self, value, corner[1], corner[19], corner[325], 0);
                if ((unsigned short)corner[649] != none && (d24i_cell_high_8010b57c(grid, row, column + 1) & 240) == 64)
                    d24i_triangle_8010b43c(self, value, corner[325], corner[649], corner[667], 1);
            } else {
                if ((unsigned short)corner[37] != none && (d24i_cell_high_8010b57c(grid, row + 1, column) & 240) == 32)
                    d24i_triangle_8010b43c(self, value, corner[37], corner[19], corner[361], 1);
                if ((unsigned short)corner[685] != none && (d24i_cell_high_8010b57c(grid, row + 1, column + 1) & 240) == 128)
                    d24i_triangle_8010b43c(self, value, corner[361], corner[685], corner[667], 0);
            }
        }
        column = column + 1;
        if (column > 6) {
            column = 0;
            if (row++ == 6 && pass == 0) {
                pass = 1;
                row = 0;
            }
        }
    } while (row <= 6 || pass == 0);
}

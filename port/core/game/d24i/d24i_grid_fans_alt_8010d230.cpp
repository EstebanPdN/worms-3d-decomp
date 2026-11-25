#include "w3d_ptr.h"
#line 1 "d24i_grid_fans_alt_8010d230.cpp"
// d24i: 0x8010d230 (1024 bytes). Variant of d24i_grid_fans_8010c62c: triangles
// 0x8010b43c with inverted flags, corners without a header offset, cell type 1
// draws the fan and neighbour types come from the high nibble (0x8010b57c).
struct d24i_Run {
    unsigned short value;
    unsigned short length;
};
struct d24i_RunCursor {
    Ptr32<d24i_Run> runs;                      // +0
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
extern "C" int d24i_cell_high_8010b57c(Ptr32<const unsigned char>, int, int);
extern "C" void d24i_triangle_8010b43c(Ptr32<d24i_GridRenderer>, unsigned, int, int, int, int);

extern "C" void d24i_grid_fans_alt_8010d230(Ptr32<d24i_GridRenderer> self, Ptr32<char> heights, Ptr32<const unsigned char> grid, int layer) {
    int row = 6;
    int column = 0;
    int pass = 0;
    int none = 0xffff;
    do {
        Ptr32<short> corner = (Ptr32<short>)(heights + row * 72 + column * 1296);
        int key = row + (layer << 10);
        key += column << 5;
        self->cursor.seek(key);
        unsigned value = self->cursor.value();
        int type = grid[row * 9 + column * 81] & 17;
        if (type == 1) {
            if (pass == 0) {
                unsigned short near = corner[36];
                if (near != none) {
                    d24i_triangle_8010b43c(self, value, corner[360], (short)near, corner[342], 1);
                    d24i_triangle_8010b43c(self, value, corner[36], corner[342], corner[18], 0);
                } else {
                    d24i_triangle_8010b43c(self, value, corner[360], corner[342], corner[18], 0);
                }
                d24i_triangle_8010b43c(self, value, corner[342], corner[18], corner[324], 1);
                unsigned short last = corner[0];
                if (last != none)
                    d24i_triangle_8010b43c(self, value, corner[18], corner[324], (short)last, 0);
            } else {
                unsigned short far = corner[684];
                if (far != none) {
                    d24i_triangle_8010b43c(self, value, corner[360], (short)far, corner[342], 0);
                    d24i_triangle_8010b43c(self, value, corner[684], corner[342], corner[666], 1);
                } else {
                    d24i_triangle_8010b43c(self, value, corner[360], corner[342], corner[666], 1);
                }
                d24i_triangle_8010b43c(self, value, corner[342], corner[666], corner[324], 0);
                unsigned short last = corner[648];
                if (last != none)
                    d24i_triangle_8010b43c(self, value, corner[666], corner[324], (short)last, 1);
            }
        } else if (type == 17) {
            if (pass == 0) {
                if ((unsigned short)corner[36] != none && (d24i_cell_high_8010b57c(grid, row + 1, column) & 240) == 32)
                    d24i_triangle_8010b43c(self, value, corner[360], corner[36], corner[18], 1);
                if ((unsigned short)corner[0] != none && (d24i_cell_high_8010b57c(grid, row, column) & 240) == 16)
                    d24i_triangle_8010b43c(self, value, corner[18], corner[324], corner[0], 0);
            } else {
                if ((unsigned short)corner[684] != none && (d24i_cell_high_8010b57c(grid, row + 1, column + 1) & 240) == 128)
                    d24i_triangle_8010b43c(self, value, corner[360], corner[684], corner[666], 0);
                if ((unsigned short)corner[648] != none && (d24i_cell_high_8010b57c(grid, row, column + 1) & 240) == 64)
                    d24i_triangle_8010b43c(self, value, corner[666], corner[324], corner[648], 1);
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



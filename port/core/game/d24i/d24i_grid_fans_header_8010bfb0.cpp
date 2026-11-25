#include "w3d_ptr.h"
#line 1 "d24i_grid_fans_header_8010bfb0.cpp"
// d24i: 0x8010bfb0 (1252 bytes). Forward two-pass grid fan scan with the header
// offset and low-nibble neighbour types, using triangles 0x8010b318. Seeks the
// run-length cursor to the layer start before the walk.
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
extern "C" int d24i_cell_8010b57c(Ptr32<const unsigned char>, int, int);
extern "C" void d24i_triangle_8010b318(Ptr32<d24i_GridRenderer>, unsigned, int, int, int, int);

extern "C" void d24i_grid_fans_header_8010bfb0(Ptr32<d24i_GridRenderer> self, Ptr32<char> heights, Ptr32<const unsigned char> grid, int layer) {
    int row = 0;
    int column = 0;
    int pass = 0;
    self->cursor.seek(layer << 10);
    while (row <= 6 || pass == 0) {
        Ptr32<short> corner = (Ptr32<short>)(heights + row * 72 + column * 1296 + 4);
        int key = row + (layer << 10);
        key += column << 5;
        self->cursor.seek(key);
        unsigned value = self->cursor.value();
        int type = grid[column * 81 + (row * 9 + 1)] & 17;
        if (type == 16) {
            if (pass == 0) {
                unsigned short first = corner[0];
                int absent = 0xffff;
                if (first != absent)
                    d24i_triangle_8010b318(self, value, (short)first, corner[18], corner[324], 1);
                d24i_triangle_8010b318(self, value, corner[18], corner[324], corner[342], 0);
                unsigned short last = corner[648];
                if (last != absent) {
                    d24i_triangle_8010b318(self, value, corner[324], corner[342], (short)last, 1);
                    d24i_triangle_8010b318(self, value, corner[342], corner[648], corner[666], 0);
                } else {
                    d24i_triangle_8010b318(self, value, corner[324], corner[342], corner[666], 1);
                }
            } else {
                unsigned short first = corner[36];
                int absent = 0xffff;
                if (first != absent)
                    d24i_triangle_8010b318(self, value, (short)first, corner[18], corner[360], 0);
                d24i_triangle_8010b318(self, value, corner[18], corner[360], corner[342], 1);
                unsigned short last = corner[684];
                if (last != absent) {
                    d24i_triangle_8010b318(self, value, corner[360], corner[342], (short)last, 0);
                    d24i_triangle_8010b318(self, value, corner[342], corner[684], corner[666], 1);
                } else {
                    d24i_triangle_8010b318(self, value, corner[360], corner[342], corner[666], 0);
                }
            }
        } else if (type == 17) {
            if (pass == 0) {
                if ((unsigned short)corner[0] != 0xffff && (d24i_cell_8010b57c(grid + 1, row, column) & 15) == 1)
                    d24i_triangle_8010b318(self, value, corner[0], corner[18], corner[324], 1);
                if ((unsigned short)corner[648] != 0xffff && (d24i_cell_8010b57c(grid + 1, row, column + 1) & 15) == 4)
                    d24i_triangle_8010b318(self, value, corner[324], corner[648], corner[666], 0);
            } else {
                if ((unsigned short)corner[36] != 0xffff && (d24i_cell_8010b57c(grid + 1, row + 1, column) & 15) == 2)
                    d24i_triangle_8010b318(self, value, corner[36], corner[18], corner[360], 0);
                if ((unsigned short)corner[684] != 0xffff && (d24i_cell_8010b57c(grid + 1, row + 1, column + 1) & 15) == 8)
                    d24i_triangle_8010b318(self, value, corner[360], corner[684], corner[666], 1);
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
    }
}



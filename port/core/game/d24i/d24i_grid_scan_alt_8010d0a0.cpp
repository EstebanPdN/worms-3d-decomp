#include "w3d_ptr.h"
#line 1 "d24i_grid_scan_alt_8010d0a0.cpp"
// d24i: 0x8010d0a0 (400 bytes). Variant of d24i_grid_scan_8010c494: edge test 0x8010bda0,
// triangles 0x8010b43c, ascending columns, corners (+2, +74, +1298) with flag 0 then (+74, +1298, +1370) with flag 1.
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
extern "C" int d24i_edge_8010bda0(Ptr32<void>, int, int);
extern "C" void d24i_triangle_8010b43c(Ptr32<d24i_GridRenderer>, unsigned, int, int, int, int);

extern "C" void d24i_grid_scan_alt_8010d0a0(Ptr32<d24i_GridRenderer> self, Ptr32<char> heights, Ptr32<void> grid, int layer) {
    int row = 0;
    int column = 0;
    do {
        int next = column + 1;
        if (d24i_edge_8010bda0(grid, row, column)) {
            Ptr32<short> corner = (Ptr32<short>)(heights + row * 72 + column * 1296);
            int key = row + (layer << 10);
            key += column << 5;
            self->cursor.seek(key);
            unsigned value = self->cursor.value();
            d24i_triangle_8010b43c(self, value, corner[0], corner[36], corner[648], 0);
            d24i_triangle_8010b43c(self, value, corner[36], corner[648], corner[684], 1);
        }
        column = next;
        if (column > 6) {
            column = 0;
            ++row;
        }
    } while (row <= 6);
}



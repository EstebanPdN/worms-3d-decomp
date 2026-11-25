#include "w3d_ptr.h"
#line 1 "d32i_contour_walk_pieces_8010b894.cpp"
// d32i: 0x8010b894. Marching squares walk that emits a start piece, a middle
// piece per cell and an end piece for each contour of the mark grid.
// Marching squares contour walk over the 9 by 9 cell marks.
struct Segment { char data[40]; };
struct MiddleSegment { char data[72]; };
extern "C" void memset_802eefe0(Ptr32<void>, int, unsigned);
extern "C" int next_start_8010b75c(Ptr32<void>, Ptr32<int>, Ptr32<int>, Ptr32<unsigned int>);
extern "C" int cell_case_8010b560(Ptr32<void>, int, int);
extern "C" int can_step_8010b594(int, int, unsigned);
extern "C" void emit_segment_8010aeb0(Ptr32<void>, Ptr32<void>, int, Ptr32<const void>, int, int);
extern unsigned char marks_8044c9ec[];
extern int scan_column_804af2b4, scan_row_804af2b0;
extern const int case_turn_80399e88[];
extern const int step_x_80399ec8[];
extern const int step_y_80399ed8[];
extern const unsigned char case_bit_80399f68[];
extern Segment start_803fcea0[][3];
extern MiddleSegment middle_803fd0a0[][3];
extern Segment end_803fd3e0[][3];
inline Ptr32<const Segment> Seg(Ptr32<Segment [3]> table, unsigned d, int t) { Ptr32<const Segment> row = table[d]; return row + t; }
inline Ptr32<const MiddleSegment> Mid(unsigned d, int t) { Ptr32<const MiddleSegment> row = middle_803fd0a0[d]; return row + t; }
inline int RowOf(int x) { return (x + 1) * 9 + 1; }
extern "C" void d32i_contour_walk_pieces_8010b894(Ptr32<void> a, Ptr32<void> b, Ptr32<void> grid, Ptr32<void> out) {
    memset_802eefe0(marks_8044c9ec, 4, 81);
    scan_row_804af2b0 = 0;
    scan_column_804af2b4 = 0;
    int sx, sy;
    unsigned sdir;
    while (next_start_8010b75c(grid, &sx, &sy, &sdir)) {
        int kind = cell_case_8010b560(grid, sx, sy);
        int turn = case_turn_80399e88[kind];
        emit_segment_8010aeb0(a, b, (int)w3d::H(out), Seg(start_803fcea0, sdir, turn), sx, sy);
        unsigned dir = (sdir + turn) & 3;
        Ptr32<unsigned char> m = marks_8044c9ec;
        int idx = sy + RowOf(sx);
        m[idx] -= case_bit_80399f68[kind];
        int x = sx + step_x_80399ec8[dir];
        int y = sy + step_y_80399ed8[dir];
        kind = cell_case_8010b560(grid, x, y);
        turn = case_turn_80399e88[kind];
        for (;;) {
            if (x == sx && y == sy && dir == sdir) break;
            unsigned next = (dir + turn) & 3;
            if (!can_step_8010b594(x, y, next)) break;
            marks_8044c9ec[y + RowOf(x)] -= case_bit_80399f68[kind];
            emit_segment_8010aeb0(a, b, (int)w3d::H(out), Mid(dir, turn), x, y);
            dir = next;
            x += step_x_80399ec8[dir];
            y += step_y_80399ed8[dir];
            kind = cell_case_8010b560(grid, x, y);
            turn = case_turn_80399e88[kind];
        }
        emit_segment_8010aeb0(a, b, (int)w3d::H(out), Seg(end_803fd3e0, dir, turn), x, y);
    }
}



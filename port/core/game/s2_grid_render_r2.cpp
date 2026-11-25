#include "w3d_ptr.h"
#line 1 "s2_grid_render_r2.cpp"
/* Grid edge rendering using the observed run-length cursor. */
extern "C" {
struct S2Run { unsigned short group, length; };
struct S2Cursor {
    Ptr32<S2Run> runs; int index, offset, position;
    Ptr32<S2Cursor> seek(int next) {
        int delta = next - position;
        offset += delta;
        position += delta;
        if (offset < 0) {
            do { --index; offset += runs[index].length; } while (offset < 0);
        } else {
            while (offset >= runs[index].length) { offset -= runs[index].length; ++index; }
        }
        return this;
    }
};
struct S2GridRenderer { unsigned char pad00[28]; S2Cursor cursor; unsigned char pad2c[720-44]; Ptr32<unsigned char> grid; unsigned char pad2d4[2492-724]; Ptr32<unsigned char> vertices; };
Ptr32<void> memset(Ptr32<void>, int, unsigned int);
extern unsigned char w3d_obj_8044c6ec[];
extern unsigned char w3d_obj_8044c86c[];
extern unsigned char w3d_obj_804af2ac;
void w3d_grid_contour_8010bb1c(Ptr32<S2GridRenderer>, Ptr32<const unsigned char>, Ptr32<const unsigned char>, int);
void w3d_auto_8010cc3c(Ptr32<S2GridRenderer>, Ptr32<const unsigned char>, Ptr32<const unsigned char>, int);
void w3d_auto_8010d834(Ptr32<S2GridRenderer>, Ptr32<const unsigned char>, Ptr32<const unsigned char>, int);
void w3d_grid_contour_8010b894(Ptr32<S2GridRenderer>, Ptr32<const unsigned char>, Ptr32<const unsigned char>, int);
void w3d_auto_8010cbcc(Ptr32<S2GridRenderer>, Ptr32<const unsigned char>, Ptr32<const unsigned char>, int);
void w3d_auto_8010d7c4(Ptr32<S2GridRenderer>, Ptr32<const unsigned char>, Ptr32<const unsigned char>, int);
int w3d_grid_edge_8010bd74(Ptr32<const unsigned char>, int, int);
int w3d_grid_edge_8010bda0(Ptr32<const unsigned char>, int, int);
void w3d_strip_dispatch_8010b318(Ptr32<S2GridRenderer>, unsigned short, int, int, int, int);
void w3d_strip_dispatch_8010b43c(Ptr32<S2GridRenderer>, unsigned short, int, int, int, int);


#if 0 /* 2 attempts; inline cursor addressing and scheduling differ */
void w3d_grid_render_edges_8010c494(S2GridRenderer *self, const unsigned char *vertices, const unsigned char *grid, int layer)
{
    int x = 0, y = 0;
    do {
        int nextY = y + 1;
        if (w3d_grid_edge_8010bd74(grid, x, y)) {
            S2Cursor *cursor = &self->cursor;
            int position = layer * 1024;
            position = x + position;
            position += y * 32;
            cursor = cursor->seek(position);
            const short *v = (const short *)(vertices + x * 72 + y * 1296 + 4);
            unsigned short group = self->cursor.runs[cursor->index].group;
            w3d_strip_dispatch_8010b318(self, group, v[1], v[37], v[649], 1);
            w3d_strip_dispatch_8010b318(self, group, v[37], v[649], v[685], 0);
        }
        y = nextY;
        if (y > 6) { y = 0; ++x; }
    } while (x <= 6);
}
#endif


void w3d_grid_render_layers_8010d8a4(Ptr32<S2GridRenderer> self, int unused, int mode)
{
    memset(w3d_obj_8044c6ec, 0, 384);
    memset(w3d_obj_8044c86c, 0, 384);
    w3d_obj_804af2ac = 0;
    Ptr32<const unsigned char> vertices = self->vertices + 1372;
    Ptr32<const unsigned char> grid = self->grid;
    grid += 91;
    for (int layer = 0; layer <= 6; ++layer, ++grid, vertices += 4) {
        if (mode == 1) {
            w3d_grid_contour_8010bb1c(self, vertices, grid, layer);
            w3d_auto_8010cc3c(self, vertices, grid, layer);
            w3d_auto_8010d834(self, vertices, grid, layer);
        } else {
            w3d_grid_contour_8010b894(self, vertices, grid, layer);
            w3d_auto_8010cbcc(self, vertices, grid, layer);
            w3d_auto_8010d7c4(self, vertices, grid, layer);
        }
    }
}

}



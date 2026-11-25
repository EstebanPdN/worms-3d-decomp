#include "w3d_ptr.h"
#line 1 "d41a_best_stand_80019b34.cpp"
// GWMP8P rev0 0x80019b34. Searches the 11 by 11 AI walk table on both layers
// for the open cell with the best combined score: for each open cell finds
// the best open neighbour within two cells, stores it in the cell, and adds
// 0.001 of the cell's own score. Writes both positions and the neighbour
// score; returns whether anything beat the start cell. Names are inferred.
struct Vec3 { float x, y, z; };
struct Grid;
struct Pos {
    short unknown00; short x; short z; unsigned char layer;
    Pos() {}
    Pos(short a, short b, unsigned char l) { x = a; z = b; layer = l; }
};
struct Cell { char unknown00[4]; float a; float b; short x; short z; unsigned char layer; char unknown11[3]; };
extern "C" void grid_probe_8001f1d8(Ptr32<Grid>, int);
extern "C" void grid_finish_8001f25c(Ptr32<Grid>, int);
extern "C" int cc26a_grid_select_layer_8001e328(Ptr32<Grid>, Ptr32<const Vec3>, Ptr32<short>, Ptr32<short>, Ptr32<int>);
extern "C" Ptr32<unsigned char> cc26a_grid_byte_cell_8001dff8(Ptr32<Grid>, int, int, int);
extern Ptr32<Grid> w3d_grid_804b1758;
extern int g_team_804aa6c0;
extern Ptr32<Cell> g_cells_804aa758;
extern Vec3 w3d_center_8041d3a0[];
inline bool Free(int a, int b, int l) { return *cc26a_grid_byte_cell_8001dff8(w3d_grid_804b1758, a, b, l) == 0; }
extern "C" bool w3d_d41a_best_stand_80019b34(Ptr32<Pos> outA, Ptr32<Pos> outB, Ptr32<float> outScore)
{
    short cx, cz;
    int layer0;
    Ptr32<const Vec3> p = w3d_center_8041d3a0; cc26a_grid_select_layer_8001e328(w3d_grid_804b1758, p, &cx, &cz, &layer0);
    grid_probe_8001f1d8(w3d_grid_804b1758, g_team_804aa6c0);
    Ptr32<Cell> c0 = &g_cells_804aa758[layer0 * 121];
    float a0 = c0->a; float b0 = c0->b;
    *outScore = a0;
    float start = b0 * 0.001f + a0;
    float top = start;
    for (int x = -5; x <= 5; x++) {
        for (int z = -5; z <= 5; z++) {
            for (int layer = 0; layer <= 1; layer++) {
                int ix = x + 5;
                int iz = z + 5;
                int px = cx + x * 2;
                int pz = cz + z * 2;
                Ptr32<Cell> c = &g_cells_804aa758[(layer * 11 + ix) * 11 + iz];
                if (c->b != -1000000.0f && Free(px, pz, layer)) {
                    float best = -1000000.0f;
                    Pos bestPos;
                    for (int dx = -2; dx <= 2; dx++) {
                        for (int dz = -2; dz <= 2; dz++) {
                            for (int l = 0; l <= 1; l++) {
                                int nx = x + dx;
                                int nz = z + dz;
                                if (nx < -5 || nx > 5 || nz < -5 || nz > 5) continue;
                                Ptr32<Cell> n = &g_cells_804aa758[(l * 11 + (nx + 5)) * 11 + (nz + 5)];
                                int qx = cx + nx * 2;
                                int qz = cz + nz * 2;
                                if (n->a > best && Free(qx, qz, l)) {
                                    best = n->a;
                                    bestPos = Pos(qx, qz, l);
                                }
                            }
                        }
                    }
                    c->x = bestPos.x;
                    c->z = bestPos.z;
                    c->layer = bestPos.layer;
                    float total = best + c->b * 0.001f;
                    if (total > top) {
                        top = total;
                        *outA = Pos(px, pz, layer);
                        *outB = Pos(c->x, c->z, c->layer);
                        *outScore = best;
                    }
                }
            }
        }
    }
    grid_finish_8001f25c(w3d_grid_804b1758, g_team_804aa6c0);
    return top > start;
}



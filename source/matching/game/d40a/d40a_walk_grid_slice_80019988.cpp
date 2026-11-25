// GWMP8P rev0 0x80019988. Computes one slice of the AI walk score table
// around the map centre: on the first slice refreshes the grid regions and
// probes for the team, then scores an 11 by 11 block of cells on both layers
// with two weightings (0x8001a02c), marks blocked cells with a large
// negative score, and on the last slice finishes the grid and returns 1.
// Names are inferred.
struct Vec3 { float x, y, z; };
struct Grid;
struct Cell { char unknown00[4]; float a; float b; char unknown0c[8]; };
extern "C" void w3d_grid_refresh_8001ef50(Grid *);
extern "C" void grid_probe_8001f1d8(Grid *, int);
extern "C" void grid_finish_8001f25c(Grid *, int);
extern "C" int cc26a_grid_select_layer_8001e328(Grid *, const Vec3 *, short *, short *, int *);
extern "C" unsigned char *cc26a_grid_byte_cell_8001dff8(Grid *, int, int, int);
extern "C" float w3d_d31a_walk_cell_score_8001a02c(int x, int z, int layer, int team, float w1, float w2);
extern Grid *w3d_grid_804b1758;
extern int g_slice_804aa768;
extern int g_team_804aa6c0;
extern Cell *g_cells_804aa758;
extern Vec3 w3d_center_8041d3a0[];
extern "C" int w3d_d40a_walk_grid_slice_80019988()
{
    short cx, cz;
    int layer0;
    if (g_slice_804aa768 == 0) {
        w3d_grid_refresh_8001ef50(w3d_grid_804b1758);
        grid_probe_8001f1d8(w3d_grid_804b1758, g_team_804aa6c0);
    }
    const Vec3 *p = w3d_center_8041d3a0; cc26a_grid_select_layer_8001e328(w3d_grid_804b1758, p, &cx, &cz, &layer0);
    int x = g_slice_804aa768 - 5;
    int end = x;
    if (x > 5) end = 5;
    for (; x <= end; x++) {
        for (int z = -5; z <= 5; z++) {
            for (int layer = 0; layer < 2; layer++) {
                int px = cx + x * 2;
                int pz = cz + z * 2;
                Cell *c = &g_cells_804aa758[layer * 121 + (x + 5) * 11 + (z + 5)];
                bool open = false;
                if (*cc26a_grid_byte_cell_8001dff8(w3d_grid_804b1758, px, pz, layer) == 0) {
                    open = true;
                    c->a = w3d_d31a_walk_cell_score_8001a02c(px, pz, layer, g_team_804aa6c0, 1.0f, 0.0f);
                    c->b = w3d_d31a_walk_cell_score_8001a02c(px, pz, layer, g_team_804aa6c0, 0.0f, 1.0f);
                }
                if (!open) {
                    c->a = -1000000.0f;
                    c->b = -1000000.0f;
                }
            }
        }
    }
    g_slice_804aa768++;
    if (x == 6) {
        g_slice_804aa768 = 0;
        grid_finish_8001f25c(w3d_grid_804b1758, g_team_804aa6c0);
        return 1;
    }
    return 0;
}

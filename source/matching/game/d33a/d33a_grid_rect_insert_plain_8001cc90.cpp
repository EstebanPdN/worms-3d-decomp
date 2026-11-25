// GWMP8P rev0 0x8001cc90. Builds a grid rectangle from a point, the global
// grid and a radius, and inserts it at the front of the grid's rectangle
// vector, using real STLport 4.5.3 vector insert. Names are inferred.
#include "compat/stlport_sn_oom.h"
#include <vector>
struct GridRect { int words[8]; };
struct Grid { char pad[72]; std::vector<GridRect> rects; };
extern Grid *w3d_grid_804b1758;
extern "C" GridRect cc25a_grid_rectangle_init_8001ee00(void *, Grid *, float);
extern "C" void w3d_d33a_grid_rect_insert_plain_8001cc90(void *a, float radius)
{
    GridRect r = cc25a_grid_rectangle_init_8001ee00(a, w3d_grid_804b1758, radius);
    Grid *g = w3d_grid_804b1758;
    g->rects.insert(g->rects.begin(), r);
}

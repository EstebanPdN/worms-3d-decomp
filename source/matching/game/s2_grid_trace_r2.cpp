/* Grid contour traversal and scan cursor state. */
extern "C" {
int w3d_grid_cell_low_8010b560(const unsigned char *, int, int);
int w3d_grid_inside_8010b594(int, int, int);
extern signed char w3d_grid_visits_8044c9ec[];
extern int w3d_grid_start_80399ee8[];
extern int w3d_grid_turn_80399e88[];
extern int w3d_grid_dx_80399ec8[];
extern int w3d_grid_dy_80399ed8[];
extern int w3d_grid_scan_x_804af2b0;
extern int w3d_grid_scan_y_804af2b4;


#if 0 /* 3 attempts; coordinate and direction register allocation differs */
void w3d_grid_trace_start_8010b5e8(const unsigned char *grid, int startX, int startY, int *outX, int *outY, int *outDirection)
{
    int x = startX, y = startY;
    int index = (x + 1) * 9;
    index += 1;
    y += index;
    index = y;
    y = startY;
    int direction = w3d_grid_visits_8044c9ec[index];
    int cell = w3d_grid_cell_low_8010b560(grid, x, y);
    int startDirection = (w3d_grid_start_80399ee8[cell] + direction) & 3;
    direction = (startDirection - w3d_grid_turn_80399e88[cell]) & 3;
    y -= w3d_grid_dy_80399ed8[direction];
    x -= w3d_grid_dx_80399ec8[direction];
    while ((x != startX || y != startY || direction != startDirection) && w3d_grid_inside_8010b594(x, y, direction)) {
        cell = w3d_grid_cell_low_8010b560(grid, x, y);
        direction = (direction - w3d_grid_turn_80399e88[cell]) & 3;
        y -= w3d_grid_dy_80399ed8[direction];
        x -= w3d_grid_dx_80399ec8[direction];
    }
    int dx = w3d_grid_dx_80399ec8[direction];
    int dy = w3d_grid_dy_80399ed8[direction];
    *outX = x + dx;
    *outY = y + dy;
    *outDirection = direction;
}
#endif


#if 0 /* 3 attempts; one addition operand order differs in best candidate */
int w3d_grid_scan_next_8010b75c(const unsigned char *grid, int *outX, int *outY, int *outDirection)
{
    while (w3d_grid_scan_x_804af2b0 <= 7) {
        int index = (w3d_grid_scan_x_804af2b0 + 1) * 9;
        index += 1;
        int y = w3d_grid_scan_y_804af2b4;
        y += index;
        index = y;
        int visits = w3d_grid_visits_8044c9ec[index];
        if (visits > 0) {
            int cell = w3d_grid_cell_low_8010b560(grid, w3d_grid_scan_x_804af2b0, w3d_grid_scan_y_804af2b4);
            if (cell && cell != 15 && w3d_grid_inside_8010b594(w3d_grid_scan_x_804af2b0, w3d_grid_scan_y_804af2b4, (w3d_grid_start_80399ee8[cell] + visits) & 3)) {
                w3d_grid_trace_start_8010b5e8(grid, w3d_grid_scan_x_804af2b0, w3d_grid_scan_y_804af2b4, outX, outY, outDirection);
                if (++w3d_grid_scan_y_804af2b4 > 7) {
                    w3d_grid_scan_y_804af2b4 = 0;
                    ++w3d_grid_scan_x_804af2b0;
                }
                return 1;
            }
        }
        if (++w3d_grid_scan_y_804af2b4 > 7) {
            w3d_grid_scan_y_804af2b4 = 0;
            ++w3d_grid_scan_x_804af2b0;
        }
    }
    return 0;
}
#endif


int w3d_grid_edge_8010bd74(const unsigned char *grid, int x, int y)
{
    y *= 81;
    y += x * 9;
    return (grid[y + 1] & 17) == 16;
}


int w3d_grid_edge_8010bda0(const unsigned char *grid, int x, int y)
{
    y *= 81;
    y += x * 9;
    return (grid[y + 0] & 17) == 1;
}


int w3d_grid_prefer_columns_8010bdc8(const unsigned char *grid)
{
    unsigned int columns = 0, rows = 0;
    int x = 0, y = 0, active = 0;
    do {
        if (w3d_grid_edge_8010bd74(grid, x, y)) {
            if (!active) { active = 1; ++columns; }
        } else active = 0;
        if (++y > 6) { y = 0; ++x; active = 0; }
    } while (x <= 6);
    x = 0; y = 0; active = 0;
    do {
        if (w3d_grid_edge_8010bd74(grid, x, y)) {
            if (!active) { active = 1; ++rows; }
        } else active = 0;
        if (++x > 6) { x = 0; ++y; active = 0; }
    } while (y <= 6);
    return columns < rows;
}


int w3d_grid_prefer_columns_8010bebc(const unsigned char *grid)
{
    unsigned int columns = 0, rows = 0;
    int x = 0, y = 0, active = 0;
    do {
        if (w3d_grid_edge_8010bda0(grid, x, y)) {
            if (!active) { active = 1; ++columns; }
        } else active = 0;
        if (++y > 6) { y = 0; ++x; active = 0; }
    } while (x <= 6);
    x = 0; y = 0; active = 0;
    do {
        if (w3d_grid_edge_8010bda0(grid, x, y)) {
            if (!active) { active = 1; ++rows; }
        } else active = 0;
        if (++x > 6) { x = 0; ++y; active = 0; }
    } while (y <= 6);
    return columns < rows;
}

}

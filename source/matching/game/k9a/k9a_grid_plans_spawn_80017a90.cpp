// Appears to try up to thirty times to pick a free grid cell from the global grid
// and, for each one found, queue a new path plan positioned at that cell's coordinates.
inline void *operator new(unsigned int, void *place) { return place; }
struct K9aPoint { float x, y, z; };
struct K9aGrid;
extern "C" void *w3d_auto_8001523c(unsigned int size);
extern "C" int w3d_grid_pick_8001dd28(K9aGrid *grid, short *column, short *row, int *layer);
extern "C" K9aPoint w3d_cx12a_sample_grid_8001e224(K9aGrid *grid, int column, int row, int layer);
extern "C" void w3d_path_cost_construct(void *plan);
extern char w3d_vtable_8040d850[];
struct K9aPlan
{
    char pad0[12];
    void *vtable;     // +12
    K9aPoint position; // +16
    K9aPlan(const K9aPoint &p)
    {
        w3d_path_cost_construct(this);
        vtable = w3d_vtable_8040d850;
        position = p;
    }
};
extern "C" void w3d_ai_push_plan_b(K9aPlan *plan);
extern K9aGrid *w3d_grid_804b1758;
extern int w3d_flag_804aa594;
extern "C" int w3d_k9a_grid_plans_spawn_80017a90(void)
{
    K9aGrid *grid = w3d_grid_804b1758;
    int found = 0;
    for (int i = 0; i < 30; i++)
    {
        short column;
        short row;
        int layer;
        if (w3d_grid_pick_8001dd28(grid, &column, &row, &layer))
        {
            K9aPlan *plan = (K9aPlan *)w3d_auto_8001523c(28);
            found = 1;
            new (plan) K9aPlan(w3d_cx12a_sample_grid_8001e224(grid, column, row, layer));
            w3d_ai_push_plan_b(plan);
        }
    }
    w3d_flag_804aa594 = 1;
    return found;
}

#include "w3d_ptr.h"
#line 1 "d28a_path_queue_build_near_800097e4.cpp"
// GWMP8P rev0 0x800097e4. Builds a move queue between two points on the grid
// and discards it when empty, single-step or when its first step is closer
// than 50 units; then advances the turn clock by the search cost. Names are
// inferred from the original instructions.
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
struct Vec { float x, y, z; };
struct Grid;
struct Queue {
    char unknown00[16];
    Ptr32<Ptr32<void>> vtable;   /* +16; slot +8 is the deleting destructor */
    Ptr32<Ptr32<void>> start; Ptr32<Ptr32<void>> finish;
    Queue();
    void Delete() { ((Ptr32<void (Ptr32<Queue>, int)>)vtable[2])(this, 3); }
};
extern float g_clock_804aa570;
extern Ptr32<Grid> w3d_grid_804b1758;
extern "C" Ptr32<void> w3d_auto_8001523c(unsigned int);
extern "C" void cc26a_grid_build_path_8001ebe0(Ptr32<Grid>, Ptr32<const Vec>, Ptr32<const Vec>, Ptr32<Queue>, int);
extern "C" int w3d_auto_8001ece8(Ptr32<Grid>);
extern int g_mode_804aa794;
extern "C" Ptr32<const Vec> w3d_move_queue_current_step(Ptr32<Queue>);
extern "C" float sqrt_802e82c0(float);
extern "C" int w3d_d28a_path_queue_build_near_800097e4(Ptr32<Ptr32<Queue>> out, Ptr32<const Vec> from, Ptr32<const Vec> to, int limit)
{
    *out = new (w3d_auto_8001523c(48)) Queue;
    g_clock_804aa570 += 100.0f;
    g_mode_804aa794 = 1;
    if (limit == -1) cc26a_grid_build_path_8001ebe0(w3d_grid_804b1758, from, to, *out, 150);
    else cc26a_grid_build_path_8001ebe0(w3d_grid_804b1758, from, to, *out, limit);
    int n = w3d_auto_8001ece8(w3d_grid_804b1758);
    Ptr32<Queue> q = *out;
    if (q) {
        if (q->start == q->finish || q->finish - q->start == 1) goto discard;
        {
            Ptr32<const Vec> s = w3d_move_queue_current_step(q);
            float dx = s->x - from->x, dy = s->y - from->y, dz = s->z - from->z;
            if (!(sqrt_802e82c0(dx * dx + dy * dy + dz * dz) < 50.0f)) goto done;
        }
        q = *out;
        if (q) {
discard:
            q->Delete();
        }
    }
    *out = 0;
done:
    g_clock_804aa570 += (float)n * 400.0f / 150.0f;
    return *out != 0;
}


